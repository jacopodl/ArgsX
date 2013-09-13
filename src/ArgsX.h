/*
    <ArgsX is a simple c/c++ options parser>
    Copyright (C) <2013>  <Jacopo De Luca>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>

// Constant
#define _ARGSX_BadArg 0xBED
#define _ARGSX_LowArg 0x10A
#define _ARGSX_OtherData 0xCDA
#define _ARGSX_LongOption 0x10D
#define _ARGSX_FINISH -1
// -------------------------------------------
#define _ARGSX_OPT_NO_ARGUMENTS 0x0
#define _ARGSX_OPT_REQUIRED_ARGUMENT 0x1
#define _ARGSX_OPT_REQUIRES_MORE_ARGUMENTS 0x2

struct _ArgsX_LongOpt
{
    char *name;
    int Args;
    char opt;
};

int ArgsX_ArgPtr=-1,
    ArgsX_LOpt_ptr=-1;

int ArgsX(int Argc,char **Argv,int *arg_ptr,char *Opt,struct _ArgsX_LongOpt *Lopt,unsigned Lopt_size,char tr)
{
    if(*arg_ptr>=Argc)
        return _ARGSX_FINISH;

    if(*Argv[*arg_ptr]==tr)
    {
        if(*++Argv[*arg_ptr]==tr&&Lopt!=0)
        {
            Argv[*arg_ptr]++;
            for(unsigned i=0;i<(Lopt_size/sizeof(_ArgsX_LongOpt));i++)
            {
                if(strcmp(Lopt[i].name,Argv[*arg_ptr])==0)
                {
                    int ret = ((int)Lopt[i].opt==0)?_ARGSX_LongOption:((int)Lopt[i].opt);
                    ArgsX_LOpt_ptr=i;
                    if(Lopt[i].Args==_ARGSX_OPT_NO_ARGUMENTS)
                    {
                        return ret;
                    }
                    else if(++*arg_ptr<Argc&&*Argv[*arg_ptr]!=tr)
                    {
                        if(Lopt[i].Args==_ARGSX_OPT_REQUIRED_ARGUMENT)
                        {
                            ArgsX_ArgPtr=*arg_ptr;
                            return ret;
                        }
                        else if(Lopt[i].Args==_ARGSX_OPT_REQUIRES_MORE_ARGUMENTS)
                        {
                            for(int j=*arg_ptr;j<Argc;j++)
                            {
                                if(*Argv[j]!=tr)
                                    ArgsX_ArgPtr=j;
                                else
                                    break;
                            }
                            return ret;
                        }
                    }
                    else
                        return _ARGSX_LowArg;
                }
            }
            return _ARGSX_BadArg;
        }
        else
        {
            char *subarg,
                  RetChar=*Argv[*arg_ptr];

            if((subarg=strstr(Opt,Argv[*arg_ptr]))!=0)
            {
                if(*++subarg=='+')
                {
                    if(++*arg_ptr<Argc&&*Argv[*arg_ptr]!=tr)
                    {
                        if(*++subarg=='+')
                        {
                            for(int i=*arg_ptr;i<Argc;i++)
                            {
                                if(*Argv[i]!=tr)
                                    ArgsX_ArgPtr=i;
                                else
                                    break;
                            }
                        }
                        else
                            ArgsX_ArgPtr=*arg_ptr;
                    }
                    else
                        return _ARGSX_LowArg;
                }
            }
            else
                return _ARGSX_BadArg;

            return (int)RetChar;
        }
    }
    ArgsX_ArgPtr=*arg_ptr;
    return _ARGSX_OtherData;
}


