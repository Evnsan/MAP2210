#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

#include "matrix.h"
#include "hessenberg.h"

int main(int argc, char** argv){
  int i = 0;  
  int j = 0;
  Matrix* A;
  Tridiagonal* H;
  /*testando*/
  Vector *x, *w;

  printf("Entrados %2d argumentos:\n", argc - 1);
  for(i = 1; i < argc; i++){
    printf("%s\n", argv[i]);
  }
  printf("------------\n");

  A = createMatrix(3, 3);

  A->data[0][0] = 1;
  A->data[0][1] = 3.0/5;
  A->data[0][2] = 4.0/5;
  A->data[1][0] = 3.0/5;
  A->data[1][1] = 2;
  A->data[1][2] = 1;
  A->data[2][0] = 4.0/5;
  A->data[2][1] = 1;
  A->data[2][2] = 2;

  printf("Matriz A:\n");
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      printf("%.2f ", A->data[i][j]);
    }
    printf("\n");
  }

  H = toHessenberg(A);
  printf("Matriz H:\n");
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if(i == j) printf("%.2f ", H->princ->data[i]);
      else printf("0.00 ");
    }
    printf("\n");
  }

  x = createVector(3);
  x->data[0] = 3.0/5;
  x->data[1] = 0;
  x->data[2] = 4.0/5;
  printf("Vetor x:\n");
  for(i = 0; i < 3; i++){
    printf("%.2f ", x->data[i]);
  }
  printf("\n");

  w = findW(x);
  printf("Vetor w:\n");
  for(i = 0; i < 3; i++){
    printf("%.2f ", w->data[i]);
  }
  printf("\n");


  
  /*
  PGMData* pgm = malloc(sizeof *pgm);

  pgm = readPGM("img/lena.pgm",pgm);
  for(i = 0; i < 512; i++){
    for(j = 0; j < 512; j++){
      if(pgm->matrix[i][j] > 127)
	pgm->matrix[i][j] = 255;
      else pgm->matrix[i][j] = 0;
    }
  }
  writePGM("img/bla.pgm",pgm);
  */
  
  return 0;
}
