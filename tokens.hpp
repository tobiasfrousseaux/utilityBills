#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int i = 0, t = 0;
   while (s[i]!='\0')
   {
      t = charCount(s,sep);
      i++;
   }
   return t+1;
}

void addToken(string& s,char sep,string t)
{
   if (s!="\0")
   {
      s = s + ' ' + sep + ' ' + t;
   }
   else
      s = t;
}

string getTokenAt(string s,char sep, int i)
{
   string t;
   int tc = tokenCount(s,sep);      // tc es token count, cantidad de tokens
   int ps, us;    // ps primer separador , us ultimo separador
   if (i==0)
   {
      ps = indexOf(s,sep);    // no tiene separador al inicio por lo tanto el ps es el del final
      t = substring(s, i, ps);
   }
   if (i==(tc-1))
   {
      ps = indexOfN(s,sep,(tc-1));
      t = substring(s, ps+1);    // no tiene separador al final por lo tano no tiene us
   }
   if( i!=0 and i!=(tc-1) )
   {
      ps = indexOfN(s,sep,i);
      us = indexOfN(s,sep,(i+1));
      t = substring(s, (ps+1), (us-1));
   }
   return t;
}

void removeTokenAt(string& s,char sep, int i)
{
   int t = tokenCount(s, sep), c = 0;
   string g;
   while (c<=t)
   {
      if (c!=i)
      {
         g = g + getTokenAt(s,sep,c) + ' ' + sep + ' ';
      }
      c++;
      if (c==t)
      {
         s = g;
      }
   }
}

void setTokenAt(string& s,char sep, string t,int i)
{
   int x = tokenCount(s,sep),c = 0;
   string g;
   while (c<=x)
   {
      if( c!=i )
      {
         g = g+getTokenAt(s,sep,c)+ ' ' + sep;
      }
      if ( c==i )
      {
         addToken(g, sep, t);
         removeTokenAt(g,sep, i);
      }
      c++;
      if (c==x)
      {
         s = g;
      }
   }
}

int findToken(string s,char sep, string t)
{
   int x = tokenCount(s,sep), c = 0, u=-1;
   string p;
   while ( c<x and u==-1)
   {
      p = getTokenAt(s, sep, c);
      if ( p==t ){
         u=c;
      }
      c++;
   }
   return u;
}

#endif
