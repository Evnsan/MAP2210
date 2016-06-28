
#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "hessenberg.h"


/*****************************************************************************/
/* toHessenberg:                                                             */
/* Assumi-se que receberá uma matriz A real simetrica => forma de Hessenberg */
/* é tridiagonal                                                             */
/*****************************************************************************/
Tridiagonal* toHessenberg(Matrix* A){
  int i;
  Tridiagonal *H;
  Vector *x;
  
  x = createVector(A->row);
  x->data[0] = 0;
  H = createTridiagonal(A->row);
  for (i = 0; i < A->row; i++){
    H->princ->data[i] = A->data[i][i];
  }
  return H;
}

/*****************************************************************************/
/* findW:                                                                    */
/* Devolve vetor w utilizado no processo de reflexão de Householder          */
/*  w = x - (||x||/||y||)*y                                                  */
/*  y = e_{x->len}                                                           */
/*  lambda = ||x|| / ||y||                                                   */
/*****************************************************************************/
Vector* findW(Vector* x){
  int i;
  Vector *w;
  float lambda;

  w = createVector(x->len);

  lambda = dotProduct(x,x);
  lambda = (float)((double)lambda);
  w->data[0] = x->data[0] - lambda;
  for(i = 1; i < x->len; i++){
    w->data[i] = x->data[i];
  }

  return w;
}

/*****************************************************************************/
/* createTridiagonal:                                                        */
/*****************************************************************************/
Tridiagonal* createTridiagonal(int len){
  Tridiagonal* aux = malloc(sizeof *aux);
  aux->len_princ = len;
  aux->princ = createVector(len);
  aux->sub = createVector(len - 1);
  aux->sup = createVector(len - 1);
  return aux;
}

/*****************************************************************************/
/* freeTridiagonal:                                                          */
/*****************************************************************************/
void freeTridiagonal(Tridiagonal* H){
  freeVector(H->princ);
  freeVector(H->sub);
  freeVector(H->sup);
  free(H);
}
