#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>

/**
 * A subconjunto de B:
 * A archivo regular -> B archivo regular de mismo tamaño y contenido
 * A directorio -> B directorio tq para toda entrada A/x hay B/x, y A/x subconjunto B/x
 */

void cmpdir(char *nom1, char *nom2) {
    struct stat st_nom1;
    struct stat st_nom2;
    int rc1;
    int rc2;
    rc1= stat(nom1, &st_nom1);
    rc2= stat(nom2, &st_nom2);

    if (rc1!=0) {
        printf("%s no existe\n", nom1);
        exit(0);
    }
    if (rc2!=0) {
        printf("%s si existe, %s no existe\n", nom1, nom2);
        exit(0);
    }
    if (S_ISREG(st_nom1.st_mode) && S_ISREG(st_nom2.st_mode)) {
        if (st_nom1.st_size != st_nom2.st_size) {
            printf("%s y %s son de distinto tamanno\n", nom1, nom2);
            exit(0);
        }
        char buf1[st_nom1.st_size + 1];
        char buf2[st_nom2.st_size + 1];
        int a = open(nom1, O_RDONLY);
        int b = open(nom2, O_RDONLY);
        if (a ==-1) {
            perror(nom1);
            exit(1);
        }
        if (b == -1) {
            perror(nom2);
            exit(1);
        }
        read(a, buf1, st_nom1.st_size);
        read(b, buf2, st_nom2.st_size);
        if (memcmp(buf1, buf2, st_nom1.st_size) != 0) {
            printf("Contenidos de %s y %s difieren\n", nom1, nom2);
            exit(0);
        }
        close(a);
        close(b);
    }
    else if (S_ISDIR(st_nom1.st_mode)) {
        if (S_ISDIR(st_nom2.st_mode)) {
            DIR *dir1 = opendir(nom1);
            DIR *dir2 = opendir(nom2);
            if (dir1 == NULL) {
                perror(nom1);
                exit(1);
            }
            if (dir2 == NULL) {
                perror(nom2);
                exit(1);
            }
            for (struct dirent *entry = readdir(dir1);
                 entry != NULL;
                 entry = readdir(dir1)) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                char *nom_arch1 = malloc(strlen(nom1) + strlen(entry->d_name) + 2);
                char *nom_arch2 = malloc(strlen(nom2) + strlen(entry->d_name) + 2);
                strcpy(nom_arch1, nom1);
                strcat(nom_arch1, "/");
                strcat(nom_arch1, entry->d_name);
                strcpy(nom_arch2, nom2);
                strcat(nom_arch2, "/");
                strcat(nom_arch2, entry->d_name);
                cmpdir(nom_arch1, nom_arch2);
                free(nom_arch1);
                free(nom_arch2);
            }
            closedir(dir1);
            closedir(dir2);
        }
        else{
            fprintf(stderr, "%s es directorio, %s no es directorio\n", nom1, nom2);
            exit(0);
        }
    }
    else {
        fprintf(stderr, "%s no es directorio, %s si es directorio\n", nom1, nom2);
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc!=3) {
        fprintf(stderr, "uso: %s <arch|dir> <arch|dir>\n", argv[0]);
        exit(2);
    }
    cmpdir(argv[1],argv[2]);
    printf("Es subconjunto\n");
    return 0;
}