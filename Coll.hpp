#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "strings.hpp"
#include "tokens.hpp"
using namespace std;

template<typename T>
struct Coll
{
   string s;
   char separador;
   int i;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.separador = sep;
   c.i=0;
   return c;
}

template<typename T>
Coll<T> coll()// Crea una colección vacía, preparada para contener elementos tipo T;
              //definiendo un separador por defecto para usar en la cadena tokenizada sobre la
              //cual se implementa la colección.
{
   Coll<T> c;
   c.s = "";
   c.separador = '|';
   c.i=0;
   return c;
}

template<typename T>
int collSize(Coll<T> c)//Retorna la cantidad de elementos que contiene la colección c.
{
   return tokenCount(c.s,c.separador);
}

template<typename T>
void collRemoveAll(Coll<T>& c)//Remueve de la colección c todos sus elementos, dejándola vacía.
{
  c.s = "";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)//: Remueve de la colección c el elemento ubicado en la posición p.

{
   c.i=p;
   removeTokenAt(c.s,c.sep,c.i);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))// Agrega el elemento t al final de la colección c.
{
   addToken(c.s,c.separador,tToString(t));
   return collSize<T>(c)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))//Reemplaza por t al elemento que se ubica en la posición p.
{
   setTokenAt(c.s,c.separador,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))//Retorna el elemento que se ubica en la posición p de la colección c.
{
   return tFromString(getTokenAt(c.s,c.separador,p));
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))//Determina si la colección c contiene al elemento k,
{
   T variableT;
   for(int i=0;  i< collSize<T>(c);i++)
   {
      variableT = tFromString(getTokenAt(c.s,c.separador,i));//lo guardo en la variable tipo T
      if(cmpTK(variableT,k) == 0 )// si es 0 quiere decir que la variable t y k son iguales
         return i;//Retorna: int - La posición que ocupa la primera ocurrencia de k dentro de c o un valor negativo si c no contiene a k.
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   T variableT;
   T segundaVariableT;
   T variableAlmacenadaT;
   string substring;
   for(int i=0; i < collSize<T>(c);i++)//extraigo la primera palabra del string y la comparo con las que le siguen
   {
      variableAlmacenadaT = tFromString(getTokenAt(c.s,c.separador,i));
      for(int j = i+1 ; j < collSize<T>(c); j++)//recorro el string desde el ultimo mas chico hasta el final del string
      {
         segundaVariableT = tFromString(getTokenAt(c.s,c.separador,j));

         if(cmpTT(segundaVariableT,variableAlmacenadaT) < 0 )
         {
            collSetAt<T>(c,variableAlmacenadaT,j,tToString);//Pongo la mas grande donde esta la mas chica.
            variableAlmacenadaT = segundaVariableT;
            collSetAt<T>(c,variableAlmacenadaT,i,tToString);//Pongo la mas chica donde esta la mas grande.
         }         
      }     
   }
}

template<typename T>
bool collHasNext(Coll<T> c)//Retorna true o false según queden, en la colección c, más elementos para continuar iterando
{
  return (c.i+1 < collSize<T>(c));//mientras el largo de la coll sea mayor que el indice retorna true
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))//: Retorna el próximo elemento de la colección c.
{
   c.i++;
   T t =tFromString(getTokenAt(c.s,c.separador,c.i));
   return t;
}

template<typename T>
void collReset(Coll<T>& c)//Reinicia la colección c para que la podamos volver a iterar.
{
   c.i=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll <T> collFromString(string s)
{
   Coll <T> x;
   x.sep = s[0];
   x.s = substring (s,1);
   return x;
}

#endif
