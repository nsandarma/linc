#ifndef LINEAR_H
#define LINEAR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define R 2.0
#define u8 unsigned char

typedef struct {
  double *x;
  u8 *y;
  int rows;
  int cols;
}Dataset;

typedef struct{
  double *weight;
  double intercept;
}Parameter;


Dataset *create_data(int rows,int cols);
void free_dataset(Dataset *data);
void print_dataset(Dataset *data);


#endif 




