#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h=s;    //puntero hacia caracter por cambiar
  char *g=s;    //puntero hacia caracter a copiar en h
  while(*h!=0) {
      if (*g != ' ' && h != g) {    //si g es a copiar en h
          *h = *g;
          *g = ' ';     //g=' ' para no repetir el caracter ya pegado en h
                        // (se obtiene una modificacion equivalente a cambio de sitio del caracter *g en vez de una copia de este)
          if (*h != 0) {    //condicion para no salirse de s con el puntero g
              h++;
              g++;
          }
      }
      else if (*h == ' ') {
          h++;    //se avanza h para dejar el espacio no superfluo
          while (*g == ' ') {    //se obvian los espacios superfluos para el string resultante
              g++;
          }
      }
      else if (*h != 0) {    //avanzar en los caracteres=letras si h==g (no ha habido espacios superfluos)
          h++;
          g++;
      }
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char m[strlen(s)+1];    //string auxiliar, de largo s igual a original
  strcpy(m, s);    //string auxiliar=s
  eliminar_espacios(m);    //aplicacion funcion eliminar_espacios a str auxiliar
  char* r= malloc(strlen(m)+1);    //malloc de string obtenido tras eliminar_espacios +1(para el 0 al final de cada str)
  strcpy(r, m);    //copiar string modificado al espacio de malloc
  return r;
}