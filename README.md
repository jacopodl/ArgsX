ArgsX
=====

ArgsX is a simple c/c++ options parser with simple syntax, ArgsX supports long and short options.

ArgsX function
--------------
```c++
    int ArgsX(
	int Argc, // argc parameter
	char **Argv, // argv parameter
	int *arg_ptr, // index to argv pointer
	char *Opt, // pointer to short options string
	struct _ArgsX_LongOpt *Lopt, // pointer to long options struct
	char tr // Option trigger Eg: -
	);
```

Usage with short options
------------------------
```c++
    int index=1,Rchar=-1;
    while((Rchar=ArgsX(argc,argv,&index,(char *)"ab+c++",null,'-'))!=-1)
    {
      switch(returnchar)
      {
        case 'a':
        ...
        break;
        case 'b':
        ...
        break;
        case 'c':
        ...
        break;
        case _ARGSX_BadArg:
        ...
        break;
        case _ARGSX_LowArg:
        ...
        break;
        default:
        ...
        break;
      }
      index++;
    }
```
    a -> No arg required
    b -> Arg required
    c -> More args required (2 or plus) Eg: -c arg1 arg2 arg3 ...

Usage with long options
-----------------------
```c++
    _ArgsX_LongOpt MyOpt[]={{"repeat",_ARGSX_OPT_NO_ARGUMENTS,0},
                            {"invert",_ARGSX_OPT_REQUIRED_ARGUMENT,0},
                            {"make",_ARGSX_OPT_REQUIRES_MORE_ARGUMENTS,0}};
    int index=1,Rchar=-1;
    while((Rchar=ArgsX(argc,argv,&index,(char *)"a",MyOpt,'-'))!=-1)
    {
      switch(returnchar)
      {
        case _ARGSX_LongOption:
            if(ArgsX_LOpt_ptr==0)
            {
                ...
            }
            else if(ArgsX_LOpt_ptr==1)
                ...
            else
                ...
        break;
        case 'a':
        ...
        break;
        case _ARGSX_BadArg:
        ...
        break;
        case _ARGSX_LowArg:
        ...
        break;
        default:
        ...
        break;
      }
      index++;
    }
```
Usage with long options (alias)
-------------------------------
```c++
    _ArgsX_LongOpt MyOpt[]={{"repeat",_ARGSX_OPT_NO_ARGUMENTS,0},
                            {"invert",_ARGSX_OPT_REQUIRED_ARGUMENT,0},
                            {"make",_ARGSX_OPT_REQUIRES_MORE_ARGUMENTS,'m'}};
    int index=1,Rchar=-1;
    while((Rchar=ArgsX(argc,argv,&index,(char *)"m++",MyOpt,'-'))!=-1)
    {
      switch(returnchar)
      {
        case _ARGSX_LongOption:
            if(ArgsX_LOpt_ptr==0)
            {
                ...
            }
            else if(ArgsX_LOpt_ptr==1)
                ...
        break;
        case 'm':
        // -m or --make
        break;
        case _ARGSX_BadArg:
        ...
        break;
        case _ARGSX_LowArg:
        ...
        break;
        default:
        ...
        break;
      }
      index++;
    }
```
Change option trigger
---------------------
```c++
    ArgsX(argc,argv,&index,(char *)"m",null,'-')
                                             ^ Option trigger
```
                                             
Example
-------
See example in example/ directory


