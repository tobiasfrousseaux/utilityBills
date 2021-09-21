#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Consorcio
{
   int idCons;
   char chrDireccion[50];
   int cantPisos;
   int cantDptosxPiso;
};

struct RConsorcio
{
   Consorcio cons;
   double dblGasto;
};

struct RDepartamento
{
   int idCons;
   int idDpto;
   double mtsPorcentuales;
   double importePagar;
};

struct Gasto
{
   int idCons;
   int fecha;
   double importe;
   char categoria[20];
};

string consorcioToString(Consorcio x)
{
   char sep = 1;
   string sIdCons=to_string(x.idCons);
   string sChrDireccion=x.chrDireccion;
   string sCantPisos=to_string(x.cantPisos);
   string sCantDptosxPiso=to_string(x.cantDptosxPiso);
   return sIdCons+sep+sChrDireccion+sep+sCantPisos+sep+sCantDptosxPiso;
}

Consorcio consorcioFromString(string s)
{
   char sep = 1;
   Consorcio x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.chrDireccion,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.cantPisos=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.cantDptosxPiso=stoi(t3);
   return x;
}

string consorcioToDebug(Consorcio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.chrDireccion;
   sout << ",";
   sout << x.cantPisos;
   sout << ",";
   sout << x.cantDptosxPiso;
   sout<< "]";
   return sout.str();
}

Consorcio consorcio(int idCons,string chrDireccion,int cantPisos,int cantDptosxPiso)
{
   Consorcio a;
   a.idCons = idCons;
   strcpy(a.chrDireccion,chrDireccion.c_str());
   a.cantPisos = cantPisos;
   a.cantDptosxPiso = cantDptosxPiso;
   return a;
}

bool consorcioEquals(Consorcio a,Consorcio b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.cantPisos!=b.cantPisos) return false;
   if(a.cantDptosxPiso!=b.cantDptosxPiso) return false;
   return true;
}

string rConsorcioToString(RConsorcio x)
{
   char sep = 2;
   string sCons=consorcioToString(x.cons);
   string sDblGasto=to_string(x.dblGasto);
   return sCons+sep+sDblGasto;
}

RConsorcio rConsorcioFromString(string s)
{
   char sep = 2;
   RConsorcio x;
   string t0 = getTokenAt(s,sep,0);
   x.cons=consorcioFromString(t0);
   string t1 = getTokenAt(s,sep,1);
   x.dblGasto=stod(t1);
   return x;
}

string rConsorcioToDebug(RConsorcio x)
{
   stringstream sout;
   sout<< "[";
   sout << consorcioToDebug(x.cons);
   sout << ",";
   sout << x.dblGasto;
   sout<< "]";
   return sout.str();
}

RConsorcio rConsorcio(Consorcio cons,double dblGasto)
{
   RConsorcio a;
   a.cons = cons;
   a.dblGasto = dblGasto;
   return a;
}

bool rConsorcioEquals(RConsorcio a,RConsorcio b)
{
   if(!consorcioEquals(a.cons,b.cons)) return false;
   if(a.dblGasto!=b.dblGasto) return false;
   return true;
}

string rDepartamentoToString(RDepartamento x)
{
   char sep = 3;
   string sIdCons=to_string(x.idCons);
   string sIdDpto=to_string(x.idDpto);
   string sMtsPorcentuales=to_string(x.mtsPorcentuales);
   string sImportePagar=to_string(x.importePagar);
   return sIdCons+sep+sIdDpto+sep+sMtsPorcentuales+sep+sImportePagar;
}

RDepartamento rDepartamentoFromString(string s)
{
   char sep = 3;
   RDepartamento x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.idDpto=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.mtsPorcentuales=stod(t2);
   string t3 = getTokenAt(s,sep,3);
   x.importePagar=stod(t3);
   return x;
}

string rDepartamentoToDebug(RDepartamento x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.idDpto;
   sout << ",";
   sout << x.mtsPorcentuales;
   sout << ",";
   sout << x.importePagar;
   sout<< "]";
   return sout.str();
}

RDepartamento rDepartamento(int idCons,int idDpto,double mtsPorcentuales,double importePagar)
{
   RDepartamento a;
   a.idCons = idCons;
   a.idDpto = idDpto;
   a.mtsPorcentuales = mtsPorcentuales;
   a.importePagar = importePagar;
   return a;
}

bool rDepartamentoEquals(RDepartamento a,RDepartamento b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.idDpto!=b.idDpto) return false;
   if(a.mtsPorcentuales!=b.mtsPorcentuales) return false;
   if(a.importePagar!=b.importePagar) return false;
   return true;
}

string gastoToString(Gasto x)
{
   char sep = 4;
   string sidCons=to_string(x.idCons);
   string sFecha=to_string(x.fecha);
   string sImporte=to_string(x.importe);
   string sCategoria=x.categoria;
   return sidCons+sep+sFecha+sep+sImporte+sep+sCategoria;
}

Gasto gastoFromString(string s)
{
   char sep = 4;
   Gasto x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.fecha=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.importe=stod(t2);
   string t3 = getTokenAt(s,sep,3);
   strcpy(x.categoria,t3.c_str());
   return x;
}

string gastoToDebug(Gasto x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.importe;
   sout << ",";
   sout << x.categoria;
   sout<< "]";
   return sout.str();
}

Gasto gasto(int idCons,int fecha,double importe,string categoria)
{
   Gasto a;
   a.idCons = idCons;
   a.fecha = fecha;
   a.importe = importe;
   strcpy(a.categoria,categoria.c_str());
   return a;
}

bool gastoEquals(Gasto a,Gasto b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.fecha!=b.fecha) return false;
   if(a.importe!=b.importe) return false;
   return true;
}

#endif
