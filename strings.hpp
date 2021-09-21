#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int length(string s)
{
   int i=0;
   while ( s[i] != '\0' )
   {
      i++;
   }
   return i;
}

int charCount(string s,char c)
{
   int i = 0;
   int cont = 0;
   while ( s[i] != '\0' )
   {
      if ( s[i]== c )
      {
         cont++;
      }
      i++;
   }
   return cont;
}

string substring(string s,int d,int h)
{
   int i=0;
   string res;
   while ( s[i]!='\0')
   {
      if (i>=d)
      {
         if (i<h)
         {
            res=res+s[i];
         }
      }
      i++;
   }
   return res;
}

string substring(string s,int d) // ok
{
   int i=0;
      string res;
      while ( s[i]!='\0')
      {
         if (i>=d)
         {
            res = res+s[i];
         }
         i++;
      }
      return res;
}

int indexOf(string s,char c) // ok
{
   int i=0, q=-1;
   while (s[i]!='\0' and q==-1)
   {
      if (s[i]==c)
      {
         q=i;
      }
      i++;
   }
   return q;
}

int indexOf(string s,char c,int offSet) // ok
{
   int i=0, q=-1;
   while( s[offSet]!='\0' and q==-1 )
   {
      if( s[offSet]==c )
      {
         q = i;
      }
      offSet++;
      i++;
   }
   return q;
}

int indexOf(string s,string toSearch) // ok
{
   int i=0, k=0, pos=-1;
   string substring;
   for (i=0; i<length(s); i++)
   {
      if (s[i] == toSearch[k])
      {
         k++;
         substring = substring + s[i];
         if( substring==toSearch )
            {
               pos = i-k+1;
               i = length(s);
            }
         else
            k=0;
      }
   }
   return pos;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int i=0, k=0, pos=-1;
      string substring;
      for (i=0; i<=length(s); i++)
      {
         if (s[i] == toSearch[k])
         {
            k++;
            substring = substring + s[i];
            if( substring==toSearch )
               {
                  pos = (length(s)-length(toSearch)+1)+offset;
                  i = length(s);
               }
            else
               k=0;
         }
      }
      return pos;
}

int lastIndexOf(string s,char c)
{
   int i = 0,q = -1;
   while( s[i]!='\0' )
   {
      if( s[i]==c )
      {
         q = i;
      }
      i++;
   }
   return q;
}

int indexOfN(string s,char c,int n)
{
   int i = 0,q = -1, cn=1;
      while( s[i]!='\0' and cn<=n)
      {
         if( s[i]==c )
         {
            q = i;
            cn++;
         }
         i++;
      }
      if (n>cn) {
         q = length (s) - 1;
      }
    return q;
}

int charToInt(char c)
{
   int n;
   n = c - 48;
   return n;
}

char intToChar(int i)
{
   char n;
   n = i + 48;
   return n;
}

int getDigit(int n,int i)
{
   int res, x = 0;
   if( i>0 )
   {
      while( x<i )
      {
         n = n/10;
         x++;
      }
      res = n%10;
   }
   else
   {
      res = n%10;
   }
   return res;
}

int digitCount(int n)
{
   int cd=0, dn=0;
   while (n>9)
   {
      n=n/10;
      cd++;
   }
   dn=cd+1;
   return dn;
}

string intToString(int i)
{
   int d=0, y;
   char t;
   string res;
   while (d < digitCount(i))
   {
      y = getDigit(i,d);
      t = intToChar(y);
      res = t + res;
      d++;
   }
   return res;
}

int stringToInt(string s,int b) // ok
{
   int i=0, x=0;
   char y;
   while (s[i]!='\0')
   {
      y=s[i];
      x = x *(10) + charToInt(y);
      i++;
   }
   return x;
}

int stringToInt(string s) // ok
{
   int i = 0,x = 0;
   char y;
   while( s[i]!='\0' )
   {
      y = s[i];
      x = x*(10)+charToInt(y);
      i++;
   }
   return x;
}

string charToString(char c)
{
   string s;
   s = s + c;
   return s;
}

char stringToChar(string s)
{
   int i=0;
   char c;
   c = s[i];
   return c;
}

string stringToString(string s)
{
   string g = s;
   return g;
}

string doubleToString(double d)
{
   return to_string(d);
}

double stringToDouble(string s)
{

   return 1.1;
}

bool isEmpty(string s)
{
   int i=0;
   while (s[i] != '\0')
   {
      i++;
   }
   if ( i>0 )
   {
      return false;
   }
   else
      return true;
}

bool startsWith(string s,string x)
{
   if (substring(s,0,length(x))==x)
   {
      return true;
   }
   else
      return false;
}

bool endsWith(string s,string x)
{
   int y = length(s)-length(x);
   if (substring(s,y)==x)
   {
      return true;
   }
   else
      return false;
}

bool contains(string s,char c)
{
   if (indexOf(s,c) != -1)
   {
      return true;
   }
   else
      return false;
}

string replace(string s,char oldChar,char newChar)
{
   string t;
   int i=0;
   while (s[i]!='\0')
   {
      if (s[i]==oldChar)
      {
         t=t+newChar;
      }
      else
         t=t+s[i];
      i++;
   }
   return t;
}

string insertAt(string s,int pos,char c)
{
   int i=0;
   string t;
   while(s[i]!='\0')
   {
      if (i==pos)
      {
         t=t+c;
      }
      else
         t=t+s[i];
      i++;
   }
   return t;
}

string removeAt(string s,int pos)
{
   int i = 0;
   string t;
   while( s[i]!='\0' )
   {
      if( i != pos)
      {
         t = t+s[i];
      }
      i++;
   }
   return t;
}

string ltrim(string s)
{
   string t;
   int i=0, q=0, g=0;
   while ( s[i]!='\0' )
   {
      if (s[i]==' ' and q==0)
      {
         g++;
      }
      if (s[i]!=' ')
      {
         q++;
      }
      i++;
   }
   t = substring(s,g);
   return t;
}

string rtrim(string s)
{
   string t;
   int q = length(s);
   while (s[(q-1)]==' ')
   {
      q--;
   }
   t = substring (s,0,q);
   return t;
}

string trim(string s)
{
   string t;
   t = rtrim(s);
   t = ltrim(t);
   return t;
}

string replicate(char c,int n)
{
   string t;
   int i = 0;
   while (i<n)
   {
      t = t + c;
      i++;
   }
   return t;
}

string spaces(int n)
{
   string t;
   int i = 0;
   while (i<n)
   {
      t = t + ' ';
   }
   return t;
}

string lpad(string s,int n,char c)
{
   string t;
   int q = n - length(s);
   if (length(s)<n)
   {
      t = replicate(c,(q+1)) + s;
   }
   return t;
}

string rpad(string s,int n,char c)
{
   string t;
   int q = n-length(s);
   if( length(s)<n )
   {
      t = s + replicate(c,(q+1));
   }
   return t;
}

string cpad(string s,int n,char c)
{
   string t;
   int q = n-length(s);
   if( length(s)<n )
   {
      t = replicate(c,((q+1)/2))+ s + replicate(c,((q+1)/2));
   }
   return t;
}

bool isDigit(char c)
{
   if (48 <= c and c <= 57)
   {
      return true;
   }
   else
      return false;
}

bool isLetter(char c)
{
   if( (65<= c and c <=90) or (97<= c and c <=122) )
   {
      return true;
   }
   else
      return false;
}

bool isUpperCase(char c)
{
   if( 65<=c and c<=90 )
   {
      return true;
   }
   else
      return false;
}

bool isLowerCase(char c)
{
   if( 97<=c and c<=122 )
   {
      return true;
   }
   else
      return false;
}

char toUpperCase(char c)
{
   char u;
   u = c - 32;
   return u;
}

char toLowerCase(char c)
{
   char u;
   u = c+32;
   return u;
}

string toUpperCases(string s)
{
   int i=0;
   string t;
   while (s[i]!='\0')
   {
      char c = s[i];
      t = t + toUpperCase(c);;
      i++;
   }
   return t;
}

string toLowerCases(string s)
{
   int i=0;
   string t;
   while (s[i]!='\0')
   {
      char c = s[i];
      t = t + toLowerCase(c);;
      i++;
   }
   return t;
}

#endif
