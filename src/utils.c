#include "linear.h"

void print_dataset(Dataset *data,int n){
  if (n == 0){
    n = data->rows;
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < data->cols; j++){
      printf("%f ",data->x[i * data->cols + j]);
    }
    printf("\t-> %f\n",data->y[i]);
  }
}


void print_single(double *arr,int n){
  for (int i = 0; i < n; i++){
    printf("%f ",arr[i]);
  }
  printf("\n");
}

void print_matrix(double *matrix, int rows, int cols) {
    // Menampilkan matriks
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.4f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}


void transpose(double arr[],double arrT[],int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      arrT[j * rows + i] = arr[i * cols + j];
    }
  }
}


void fillArr(double arr[],int rows, int cols){
  for(int i = 0; i < rows; i ++){
    for (int j = 0; j < cols; j++){
      arr[i * cols + j] = ((double)rand()/(double)(RAND_MAX)) * 2.0;
    }
  }
}

Dataset *make_regression(int rows,int cols){
  Dataset *data = (Dataset *)malloc(sizeof(Dataset));
  if (data == NULL){
    printf("Memory Allocation failed\n");
    return NULL;
  }

  data->rows = rows;
  data->cols = cols;
  
  double *X = (double *)calloc(rows * cols ,sizeof(double));
  double *y = (double *)calloc(rows , sizeof(double));

  double r;

  for (int i = 0 ; i < rows; i++){
    double t = 0.0;
    for(int j = 0 ; j < cols; j++){
      r = ((double)rand()/(double)(RAND_MAX)) * 2.0;
      t += r;
      X[i * cols + j] = r;
    }
    y[i] = t * t + 0.5;
  }
  data->x = X;
  data->y = y;
  
  return data;
}


void free_dataset(Dataset *data){
  if (data != NULL){
    free(data->x);
    free(data->y);
    free(data);
  }
}

void free_params(Parameter *params){
  if (params != NULL){
    free(params->weight);
    free(params);
  }
}
