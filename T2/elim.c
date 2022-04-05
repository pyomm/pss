#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h = s;
  char *g = h+1;
  char *f;
  while(h!=0){
    if (*h == ' '){
      g = h+1;
      f = g;
      if (h == s){
        g = h;
      }
      if (*g == ' '){
        while (*f == ' '){
          f++;
        }
        while (*f != ' ' && *g != 0){
          *g = *f;
          *f = ' ';
          if (*g != 0){
            g++;
          }
          f++;
        }
      }
    }
    h++;
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a = (char *) s;
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
  char *p = malloc(l);
  char *r = p;
  char *b = (char *) s;
  e = 1;  //el valor de e inicia en 1, para que asi, si s parte con un espacio, este tambien se considere incorrecto
  while (*b !=0){
    if (e==1){
      //if (*b == ' ') no se necesita especificar porque no hace nada, solo revisa el siguiente caracter en s, o sea b++
      if(*b != ' '){
        *r = *s;
        r++;
      }
    }
    if (e==0){
      if (*b == ' '){
        *r = *s;
        e=1;
        r++;
      }
    }
    b++;
  }
  return p;
}