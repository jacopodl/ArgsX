#include <iostream>
#include <stdlib.h>
#include "../../src/ArgsX.h"

using namespace std;

int main(int argc,char **argv)
{
    if(argc<2)
    {
        cout<<"Usage:\n"
            <<"example2 <text>\n"
            <<"example2 --repeat <n> <text>"
	    <<"example2 -i|--invert"<<endl;
    }

    _ArgsX_LongOpt MyOpt[]={{"repeat",_ARGSX_OPT_REQUIRED_ARGUMENT,0},
                            {"invert",_ARGSX_OPT_NO_ARGUMENTS,'i'}};
    char *cstring=NULL;
    bool i=false;
    int Nn=1;

    int index=1,
        returnchar=-1;

    while((returnchar=ArgsX(argc,argv,&index,(char *)"i",MyOpt,sizeof(MyOpt),'-'))!=-1)
    {
        switch(returnchar)
        {
        case _ARGSX_LongOption:
            if(ArgsX_LOpt_ptr==0)
            {
                Nn=atoi(argv[ArgsX_ArgPtr]);
            }
            break;
        case 'i':
            i=true;
            break;
        case _ARGSX_BadArg:
            cout<<"Bad Arg "<<endl;
            return -1;
            break;
        case _ARGSX_LowArg:
            cout<<"Low Args"<<endl;
            return -1;
            break;
        default:
            cstring=argv[ArgsX_ArgPtr];
            break;
        }
        index++;
    }

    if(cstring!=NULL)
    {
        if(!i)
        {
            for(int i=0;i<Nn;i++)
            {
                cout<<cstring<<endl;
            }
        }
        else
        {
            for(int i=0;i<Nn;i++)
            {
                for(int j=strlen(cstring);j>=0;j--)
                {
                    cout<<cstring[j];
                }
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"No string :/"<<endl;
    }
}

