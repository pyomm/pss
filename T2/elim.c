#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h = s + strlen(s)-1;  //puntero hacia caracter evaluado, parte del fin del string hacia s
  char *g = h-1;
  char *f = g;
  while(s <= h){
    if (*h == ' '){
      if (h == s+strlen(s)-1){
        g = h;
      }
      while (*f == ' '){
        f--;
        if (f<= s){
        s = g;
        }
      }
      while (*f != ' '){
        *g = *f;
        *f = ' ';
        g--;
        f--;
      }
    }
    h--;
  }
  s = f;
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a = s;
  int l = strlen(s);
  int e = 1;  //e=1 si el puntero esta en un espacio, e=0 si esta en un caracter != ' '
  while (*a !=0){
    if (e==1){
      if (*a == ' '){
        l--;
      }
      if(*a != ' '){
        e=0;
      }
    }
    if (e==0){
      if (*a == ' '){
        e=1;
      }
    }
    a++;
  }
  char *p = (char*) malloc(l);
  char *r = p;
  char *b = s;
  e = 1;  //el valor de e inicia en 1, para que asi, si s parte con un espacio, este tambien se considere incorrecto
  while (*b !=0){
    if (e==1){
      //if (*b == ' ') no se necesita especificar porque no hace nada, solo revisa el siguiente caracter en s, o sea b++
      if(*b != ' '){
        *p = *s;
      }
    }
    if (e==0){
      if (*b == ' '){
        *p = *s;
        e=1;
      }
    }
    b++;
  }
  return p;
}