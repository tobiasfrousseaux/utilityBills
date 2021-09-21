#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
}

template<typename T> T read(FILE* f)
{
   T t;
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
}

template<typename T> int fileSize(FILE* f)
{
   return 0;
}

template<typename T> int filePos(FILE* f)
{
   return 0;
}

#endif
