#ifndef HESSEMBERG_H
#define HESSEMBERG_H 1

#include "vector.h"


typedef struct tridiagonal_str{
  /*len_sub = len_sup = len_princ - 1*/
  int len_princ;
  Vector *princ, *sub, *sup;
}Tridiagonal;


Tridiagonal* toHessenberg(Matrix*);
Tridiagonal* createTridiagonal(int);
void freeTridiagonal(Tridiagonal*);
Vector* findW(Vector*);






#endif
