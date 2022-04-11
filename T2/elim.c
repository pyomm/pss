#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h=s;  //puntero escritor sin modificar s original hacia el primer caracter
  char *g=s;  //puntero lector
  while(*h!=0){
    if(*h==' '){
      h++;
      while (*g==' '){
        g++;
      }
    }
    else if(*h!=0){
      h++;
      g++;
    }
    while(*g!=' ' && h!=g){
      *h=*g;
      *g=' ';
      if(*h!=0){
        h++;
        g++;
      }
    }
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char m[strlen(s)+1];  //string auxiliar, de largo s
  strcpy(m, s); //string auxiliar=s
  eliminar_espacios(m); //aplicacion funcion que muta str en el auxiliar
  char* r= malloc(strlen(m)+1);
  strcpy(r, m);
  return r;
}