#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "../../src/ArgsX.h"

using namespace std;

int main(int argc,char **argv)
{
    if(argc<2)
    {
        cout<<"Usage:\n"
            <<"example3 _s || __sum number1, number2, number3\n"
            <<"example3 _p || __pow base exponent\n"
            <<"example3 __inv number \n"<<endl;
    }

    _ArgsX_LongOpt MyOpt[]={{"pow",_ARGSX_OPT_REQUIRES_MORE_ARGUMENTS,'p'},
                            {"sum",_ARGSX_OPT_REQUIRES_MORE_ARGUMENTS,'s'},
                            {"inv",_ARGSX_OPT_REQUIRED_ARGUMENT,0}};

    int index=1,
        returnchar=-1;

    while((returnchar=ArgsX(argc,argv,&index,(char *)"s++p++",MyOpt,sizeof(MyOpt),'_'))!=-1)
    {
        int base=-1,exp=-1;
        switch(returnchar)
        {
        case _ARGSX_LongOption:
            if(ArgsX_LOpt_ptr==2)
            {
                cout<<atoi(argv[ArgsX_ArgPtr])*-1<<endl;
            }
            break;
        case 's':
            base=exp=0;
            for (int i=index;i<=ArgsX_ArgPtr;i++)
            {
                base+=atoi(argv[i]);
            }
            cout<<base<<endl;
            break;
        case 'p':
            for (int i=index;i<=ArgsX_ArgPtr;i++)
            {
                if(base==-1)
                    base=atoi(argv[i]);
                else if(exp==-1)
                     exp=atoi(argv[i]);
                else break;
            }
            cout<<pow(base,exp)<<endl;
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
            break;
        }
        index++;
    }
}

