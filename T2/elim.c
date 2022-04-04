#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h = s + strlen (s);  //puntero hacia caracter evaluado, parte del fin del string hacia s
  char *g = h-1;
  char *f = g-1;
  while(s < h){
    if (*h==''){
      if (h == s+strlen(s)){
        g = h;
      }
      while (*f == ''){
        f--;
      }
      if(f<s){
        s = h+1;
      }
      if (f >= s && f!=(h-1)){
        *g = *f;
        *f = '';
      }
    }
    h--;
    g = h-1;
    f = h-1;
  }
}


//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  ...
}
