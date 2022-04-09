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
      g=h+1;
      while (*g==' '){
        g++;
        while (*g!=' '){
          h++;
          *h=*g;
          *g=' ';
          g++;
        }
      }
      if(*g==0){
        *h=0;
      }
    }
    while(*h!=' ' &&h!=0){
      g++;
      h++;
    }
  }
  h++;
}

//genera nuevo string modificado -> malloc
char *eliminacion_espacios(const char *s) {
  char *a=(char*)s;
  char *b=(char*)s;
  int l=strlen(s);
  while(*a!=0){
    if(*a==' '){
      while(*b==' '){
        l--;
      }
    }
    a++;
  }
  char *p=malloc(l+1);
  char *r=p;
  //char *y=(char*)s+1;
  while(*s!=0){
    if(*s==' '){
      while(*s==' '){
        s++;
      }
    }
    while(*s!=' '){
      *r=*s;
      s++;
      r++;
    }
  }
  *r=0;
  return p;
}






    /*if(e==0){
      *h=*g;
      h++;
      if(*g == ' '){
        e=1;
      }
    }
    else{ //if e==1
      if(*g!=' '){
        *h=*g;
        h++;
        e=0;
      }
    }
    g++;
    if(*g==0){
      *h=0;
    }*/


  /*char *a=(char *) s; //puntero lector
  int l=strlen(s);
  int e=0;  //e=1 si el puntero lector quedo en un espacio, e=0 si quedo en un caracter != ' '
  while (*a!=0){
    if (e==0){
      if (*a==' '){
        e=1;
      }
    }
    else{ //if e==1
      if (*a==' '){
        l--;
      }
      else{
        e=0;
      }
    }

    a++;
  }

  e=0;  //e=1 si el puntero lector (s) quedo en un espacio, e=0 si quedo en un caracter != ' '
  while (*s!=0){
    if (e==1){
      if (*s!=' '){
        *r=*s;
        r++;
        e=0;
      }
    } //si e==1 y s== ' ' no se hace nada, solo revisa el siguiente caracter en s, o sea s++
    else{ //if e==0
      *r=*s;
      r++;
      if (*s==' '){
        e=1;
      }
    }
    s++;
  }
  *r=0;
  return p;*/