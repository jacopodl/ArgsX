![](https://img.shields.io/badge/version-1.5-green.svg)
[![GPLv3 License](https://img.shields.io/badge/license-GPL3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0.html)


ArgsX
=====

ArgsX is a simple C/C++ options parser with simple syntax, ArgsX supports long and short options.

ArgsX function
--------------
```c++
    int ArgsX(
	int argc,			// argc parameter
	char **argv,			// argv parameter
	char *opt,			// pointer to short options string
	ax_lopt *lopt,			// pointer to long options struct
	unsigned short lopt_size,	// size of long options struct
	char tr				// Option trigger Eg: -
	);
```
Usage:
------
```c++
    ax_lopt MyOpt[]={{"repeat",ARGSX_NOARG,0},
                     {"invert",ARGSX_REQ_ARG,0},
                     {"make",ARGSX_REQ_ARG,'m'}};
    int Rchar=-1;
    while((Rchar=ArgsX(argc,argv,(char *)"m!",MyOpt,sizeof(MyOpt),'-'))!=-1)
    {
      switch(Rchar)
      {
        case ARGSX_LOPT:
            if(ax_loptidx==0)
            {
                ...
            }
            else if(ax_loptidx==1)
                ...
        break;
        case 'm':
        // -m or --make
        break;
        case ARGSX_BAD_OPT:
        ...
        break;
        case ARGSX_FEW_ARGS:
        ...
        break;
        case ARGSX_NONOPT:
        ...
        break;
      }
    }
