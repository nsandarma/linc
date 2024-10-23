#ifndef LINEAR_H
#define LINEAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#define R 2.0


typedef struct {
  double *x;
  double *y;
  int rows;
  int cols;
}Dataset;

typedef struct{
  double *weight;
  double intercept;
}Parameter;


Dataset *make_regression(int rows,int cols);

// Parameter *params(Dataset *data);

// utils.c
void printMatrix(double *matrix, int rows, int cols);
void free_dataset(Dataset *data);
void free_params(Parameter *params);
void print_dataset(Dataset *data,int n);
void print_single(double *arr,int n);
void print_matrix(double *matrix, int rows, int cols);
void fillArr(double arr[],int rows, int cols);
void transpose(double arr[],double arrT[],int rows,int cols);
void write_matrix(const char *filename,int rows, int cols,double *matrix);
void concatenate(double *A, double *B, double *C, int rows, int cols);


// ddot.c
void ddot(double *weight,double *x,int rows, int cols,double *result,double intercept);
void dot(double a[],double b[],double c[],int rowsA,int rowsB, int colsA, int colsB);

// linear.c
double get_mape(double y_true[],double y_pred[],int row);
int linalg_inv(double *matrix, double *inverse, int size);
void swap_rows(double *matrix, double *identity, int row1, int row2, int size);
Parameter *parameter(Dataset *data,double intercept);

#endif 

