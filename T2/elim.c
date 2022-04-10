#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h=s;
  char *g=h+1;  //puntero lector
  //int e=0;  e=1 si el puntero lector quedo en un espacio, e=0 si quedo en un caracter != ' '
  while(*h!=0){
    if (*h==' '){
      while (*g==' ' && *h==' '){
        g++;
        while (*g!=' ' && *g!=0){
          h++;
          *h=*g;
          *g=' ';
          g++;
        }
        if (*g==0){
          h++;
          *h=0;
          h--;
        }
      }
    }
    h++;
    if (*g!=' '){
      g++;
    }
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a=(char*)s;
  int l=strlen(s);
  while(*a!=0 && l>0){
    if(*a==' '){
      a++;
      while(*a==' '){
        l--;
        a++;
      }
    }
    if (*a!=0){
      a++;
    }
  }
  char *r=malloc(l+1);
  char *p=r;
  while(*s!=0){
    if(s==0){
      *r=0;
    }
    if(*s==' '){  //un primer espacio en s (no es superfluo)
      *r=*s;  //se agrega a p
      s++;
      r++;
      while(*s==' '){ //espacios superfluos
        s++;  //se recorre sin agregar
      }
    }
    else{ //s es caracter y r no esta terminado
      *r=*s;
      s++;
      r++;
    }
  }
  return p;
}