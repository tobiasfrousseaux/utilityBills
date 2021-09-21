#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "consorcios.hpp"
using namespace std;

Coll<RConsorcio> subirConsorcios()
{
   Coll<RConsorcio> ccon = coll<RConsorcio>();
   FILE* f = fopen("CONSORCIOS.dat","r+b");

   // leemos el primer registro
   Consorcio reg = read<Consorcio>(f);
   while( !feof(f) )
   {
      RConsorcio rc = rConsorcio(reg,0);
      collAdd<RConsorcio>(ccon,rc,rConsorcioToString);
      reg = read<Consorcio>(f);
   }
   fclose(f);
   return ccon;
}

int cmpIdCons(RConsorcio rc, int a)
{
   return rc.cons.idCons-a;
}
void procesarGastos (Gasto g, Coll<RConsorcio>& ccon)
{
   // Buscamos la posicoin del consorcio
   int posCons = collFind<RConsorcio, int>(ccon,g.idCons,cmpIdCons,rConsorcioFromString);

   // Obtenemos los datos del consorcio y le sumamos el importe del gasto
   RConsorcio rc = collGetAt<RConsorcio>(ccon, posCons, rConsorcioFromString);
   rc.dblGasto = rc.dblGasto + g.importe;
}

double mtsPorcentuales(int idCons, int idDpto)
{
   return 0;
}

int cmpMtsRdep(RDepartamento a, RDepartamento b)
{
   return a>b?-1:a<b?1:0;
}

void mostrarResultados(Coll<RConsorcio> ccon)
{
   collReset<RConsorcio>(ccon);
   while ( collHasNext<RConsorcio>(ccon))
   {
      RConsorcio rc = collNext<RConsorcio>(ccon,rConsorcioFromString);
      cout << "Consorcio calle: " << rc.cons.chrDireccion << ", Gastos totales: " << rc.dblGasto;

      Coll<RDepartamento> cd = Coll<RDepartamento();

      for (int i=1; i<=( rc.cons.cantPisos * rc.cons.cantDptosxPiso ); i++)
      {
         double metrosPorcentuales = mtsPorcentuales(rc.cons.idCons, i);
         double totalAPagar = ( rc.dblGasto / rc.cons.cantPisos ) * metrosPorcentuales;
         RDepartamento rd = rDepartamento(rc.cons.idCons, i, metrosPorcentuales, totalAPagar);
         collAdd<RDepartamento>(cd,rd,rDepartamentoToString);
      }

      collSort<RDepartamento>(cd, cmpMtsRdep, rDepartamentoFromString, rDepartamentoToString);

      collReset<RDepartamento>(cd);
      while ( collHasNext<RDepartamento>(cd) )
      {
         RDepartamento rd = collNext<RDepartamento>(cd,rDepartamentoFromString);
         cout << "Dpto: " << rd.idDpto << ", Mtos porcentuales: " << rd.mtsPorcentuales << ", Importe a pagar: " << rd.importePagar << endl;
      }
   }
}

int main() {
   Coll<RConsorcio> ccon = subirConsorcios();

   FILE* f = fopen("GASTOS.dat","r+b");

   Gasto reg = read<Gasto>(f);
   while ( !feof(f) )
   {
      procesarGastos(reg,ccon);
      reg = read<Gasto>(f);
   }

   mostrarResultados(crcon);
 return 0;
}
