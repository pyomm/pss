#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h=s;
  char *g=h;  //puntero lector
  int e=0;  //e=1 si el puntero lector quedo en un espacio, e=0 si quedo en un caracter != ' '
  while(*g!=0){
    if(e==0){
      *h=*g;
      h++;
      if(*g == ' '){
        e=1;
      }
    }
    else if (e==1){
      if(*g!=' '){
        *h=*g;
        h++;
        e=0;
      }
    }
    g++;
    if(*g==0){
      *h=0;
    }
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a=(char *) s; //puntero lector
  int l=strlen(s)+1;
  int e=0;  //e=1 si el puntero lector quedo en un espacio, e=0 si quedo en un caracter != ' '
  while (*a !=0){
    if (e==1){
      if (*a == ' '){
        l--;
      }
      else{
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
  char *p=malloc(l+1);
  char *r=p;
  e=0;  //e=1 si el puntero lector (s) quedo en un espacio, e=0 si quedo en un caracter != ' '
  while (*s !=0){
    if (e==1 && *s != ' '){
      //if (*b == ' ') no se necesita especificar porque no hace nada, solo revisa el siguiente caracter en s, o sea s++
      *r=*s;
      r++;
      e=0;
    }
    else if (e==0){
      *r=*s;
      r++;
      if (*s == ' '){
        e=1;
      }
    }
    s++;
  }
  r++;
  *r=0;
  return p;
}