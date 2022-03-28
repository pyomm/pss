#include <stdio.h>
#include <stdlib.h>

#include "borrar-bits.h"

uint borrar_bits(uint x, uint pat, int len) {
  uint r = 0;  //variable auxiliar cualquiera
  int lo = len;  //variable auxiliar = len
  uint a = sizeof(uint)<<3; //largo de un uint definido como a, para ahorrar escritura adelante
  while (lo <= a){  //while para recorrer todos los bits de x
    uint r2 = (((x^pat)<<(a-lo))>>(a-lo));  //x^pat ve si pat esta en cierto grupo de bits de x y con <<, >> se ignoran bits no evaluados en este ciclo
    if (r2 == 0){  //si la seccion evaluada resulta compuesta solo de 0
      r = r|(x&pat); //r entrega 1 en las posiciones donde hay 1s del patron a cambiar por 0
      pat <<= (len-1); //len-1 porque se omite <<1 que se hace fuera del if
      lo += (len-1);
    }
    pat <<= 1;  //mueve pat a la izquierda para poder comparar todas las partes de x
    lo++; //avanza los bits de x revisados
  }
  return x&(~r); //~r2 tiene 0 unicamente en los sitios con 1s a borrar en x
}