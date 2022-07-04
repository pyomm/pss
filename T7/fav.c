#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fav.h"

int favorables_par(int n, int sum, int rep, int p) {
    int pid[p];
    int fd[p][2];
    int q= rep/p;   //cantidad lanzamientos en cada proceso hijo
    for (int i=0; i<p; i++){
       pipe(fd[i]);
    }
    for (int i=0; i<p; i++) {
        init_rand_seed();
        pid_t child = fork();
        if (child == 0) {   //estamos en hijo
            close(fd[i][0]);    //deshabilitamos lectura
            int res = favorables(n, sum, q);    //resultado de este hijo
            write(fd[i][1], &res, sizeof(int)); //escribimos el resultado
            exit(0);    //para salir del hijo
        }
        else {
            close(fd[i][1]);    //deshabilitamos escritura
            pid[i] = child;
        }
    }
    int f_res=0;    //resultado final
    for (int i=0; i<p; i++){
        waitpid(pid[i], NULL, 0);
        int c_res;  //resultado obtenido desde hijo
        leer(fd[i][0], &c_res, sizeof(int));
        f_res+=c_res;   //resultado final += resultado leido desde hijo
    }
    return f_res;
}