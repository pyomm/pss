#include <string.h>

void sort(char **noms, int n) {
  char **ult= &noms[n-1];   //ultimo string del arreglo
  char **p= noms;   //primer string del arreglo, varia
  while (p<ult) {   //mientras no se llegue al ultimo string

    ////////////////////////////////////////////
    // Comienza el codigo que Ud. debe modificar
    ////////////////////////////////////////////

    char *s1=p[0];
    char *s2=p[1];
    int rc=0;
    while (rc==0){
        if (*s1==' '){
            while (*s2!=' ') {
                s2++;
                if (*s2 == 0) { //se terminó de leer p[1] habiendo espacios no igualados en p[0] aun
                    rc=1;
                }
            }
            if(*s2==' '){
                s2++;
            }
        }
        s1++;
        if(*s1==0){   //se terminó de leer p[0] sin encontrarse mas espacios que en p[1]
            rc=-1;
        }
    }

    ////////////////////////////////////////////
    // Fin del codigo que Ud. debe modificar
    ////////////////////////////////////////////
    if (rc<=0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= noms;
    }
  }
}