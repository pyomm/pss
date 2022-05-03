#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIZELIN 10

int main(int argc, char *argv[]) {
  if (argc<=2) {
    fprintf(stderr, "Uso: %s <archivo> <l1> <l2> <l3> ...\n", argv[0]);
    exit(1);
  }
  char *nom= argv[1];  // El nombre del archivo
  FILE *f = fopen(nom, "r+");   //abre el archivo a modificar en r+, para leer y sobreescribir
  char buf[SIZELIN];    //buf largo 10
  char buf1[SIZELIN];   //buf largo 10
  int a=2;  //a recorre las n lineas a intercambiar, parte en 2 ya que ahi comienzan los valores
  fseek(f, SIZELIN*atoi(argv[a]), SEEK_SET);
  fread(buf1, SIZELIN, 1, f);   //en buf1 queda el contenido de la linea argv[2]
  while(a<(argc-1)){
      strncpy(buf, buf1, SIZELIN);  //se copia en buf la linea guardada en el ciclo anterior
      fseek(f, SIZELIN*atoi(argv[a+1]), SEEK_SET);
      fread(buf1, SIZELIN, 1, f);   //se copia en buf1 la linea que sera sobreescrita
      fseek(f, SIZELIN*atoi(argv[a+1]), SEEK_SET);
      fwrite(buf,SIZELIN, 1, f);    //se reescribe la linea a+1
      a++;
  }
  fseek(f, SIZELIN*atoi(argv[2]), SEEK_SET);    //fuera del while ya que no se requiere guardar su texto (ya fue escrito en otra linea)
  fwrite(buf1, SIZELIN, 1, f);
  return 0;
}
