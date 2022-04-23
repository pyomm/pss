#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "seleccion.h"

int selprim(Nodo **pa, int k) {
    Nodo *a=*pa;
    if (a== NULL){      //si el hijo del nodo no existe (caso base)
        return 0;       //no se cuenta como nodo
    }
    int c_izq= selprim(&a->izq, k);     //recursion para subarbol izquierdo
    int c_der;
    if (c_izq==k){
        *pa= a->izq;
        c_der = selprim(&a->der, 0);
        free(a);    //libera nodos >k
        return k;
    }
    c_der= selprim(&a->der, k-c_izq-1);     //recursion para subarbol derecho, k - (nodos ya visitados izquierdos)
    return c_izq+1+c_der;   //para el nodo, retorna cantidad nodos a su izquierda + 1 (el nodo mismo) + cantidad nodos a su derecha
}

Nodo *ultimos(Nodo *a, int *pk){
    if (a==NULL){
        *pk=0;
        return (NULL);
    }
    int k = *pk;
    int k_der=*pk;
    Nodo *n_der= ultimos(a->der, &k_der);
    if (k_der==k){
        return n_der;
    }
    int k_izq=k-k_der-1;
    Nodo * n_izq= ultimos(a->izq, &k_izq);  //revisa subarbol izquierdo para pk-(valores ya agregados)
    Nodo * f=malloc(sizeof(Nodo));  //malloc para retornar
    f->x=a->x;  //el valor del nodo en f se reemplaza
    f->izq=n_izq;   //se agrega la izquierda de f
    f->der=n_der;   //se agrega la derecha de f
    *pk=k_der+k_izq+1;  //actualiza pk nodos agregados
    return f;
}
