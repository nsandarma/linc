#include "linear.h"

void dot(double a[],double b[], double c[],int rowsA,int rowsB, int colsA, int colsB){
  assert(colsA == rowsB);
  for(int i = 0; i < rowsA; i ++){
    for(int j = 0; j < colsB; j++){
      c[i * colsB + j] = 0;
      for(int k = 0;  k < colsA; k++){
        c[i * colsB + j] += a[i * colsA + k] * b[k * colsB + j];
      }
    }
  }
}

void ddot(double *weight,double *x,int rows, int cols, double *result,double intercept){
  for (int i = 0; i < rows; i++){
    double temp =  0.0;
    for (int j = 0; j < cols; j++){
      temp +=  weight[j] * x[i * cols + j];
    }
    result[i] = temp + intercept;
  }
}

void ddot2(double *x, int rows,int cols){
  int middle = rows / cols; // Menghitung jumlah elemen dalam satu kolom
  for (int i = 0 ; i < middle; i++){
    printf("[%f, %f, %f]\n", x[i], x[i + middle], x[rows - 1 - i]);
  }
}

