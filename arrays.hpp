#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len] = e;
   len++;
   return len;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   len++;
   for(int i=p; i<len; i++)
   {
      arr[i+1] = arr[i];
   }
   arr[p] = e;
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret = arr[p];
   for(int i=p; i<len; i++)
   {
      arr[i] = arr[i+1];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   T variableT;
   for(int i; i<=len; i++)
   {
      variableT = arr[i];
      if(cmpTK(variableT, arr[i]) == 0)
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   return 0;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   T varT;
   T segVarT;
   T almacenadaVarT;
   for(int i; i<=len; i++)
   {
      almacenadaVarT = arr[i];
      for(int j = i+1; j<=len; j++)
      {
         segVarT = arr[j];
         if(cmpTT(segVarT,almacenadaVarT) < 0)
         {
            arr[j] = almacenadaVarT;
            almacenadaVarT = segVarT;
            arr[i] = segVarT;
         }
      }

   }
}

#endif
