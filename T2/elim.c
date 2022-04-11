#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

//un espacio solo esta posicionado correctamente si es que lo rodean caracteres => *(f-1)!= '' && *(f+1)!= ''

//modifica string original
void eliminar_espacios(char *s) {
  char *h=s;  //puntero escritor sin modificar s original hacia el primer caracter
  char *g=h+1;  //puntero lector
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
    if (*g!=' ' && *g!=0){
      g++;
    }
  }
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a=(char*)s;
  int l=strlen(s);
  while(*a!=0){
    if(*a==' '){
      a++;
      while(*a==' '){
        l--;
        a++;
      }
    }
    else{
      a++;
    }
  }
  char *r=malloc(l+1);  //+1 para el espacio ocupado por 0
  char *p=r;  //puntero al inicio de r para retornarlo
  while(*s!=0){
    if(*s==' '){  //un primer espacio en s (no es superfluo)
      *r=*s;  //se agrega a p
      s++;
      r++;
      if(*s==0){
        *r=*s;
      }
      while(*s==' '){ //espacios superfluos
        s++;  //se recorre sin agregar
        if(*s==0){
          *r=*s;
        }
      }
    }
    else{
      while(*s!=' ' && *s!=0){
        *r=*s;
        r++;
        s++;
        if(*s==0){
          *r=*s;
        }
      }
    }
  }
  return p;
}