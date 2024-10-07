#include "linear.h"

void print_dataset(Dataset *data){
  for(int i = 0; i < data->rows; i++){
    for(int j = 0; j < data->cols; j++){
      printf("%f ",data->x[i * data->cols + j]);
    }
    printf("\t-> %d\n",data->y[i]);
  }
}

Dataset *create_data(int rows,int cols){
  Dataset *data = (Dataset *)malloc(sizeof(Dataset));
  if (data == NULL){
    printf("Memory Allocation failed\n");
    return NULL;
  }

  data->rows = rows;
  data->cols = cols;
  
  double *X = (double *)malloc(rows * cols * sizeof(double));
  u8 *y = (u8 *)malloc(rows * sizeof(u8));

  double r;

  for (int i = 0 ; i < rows; i++){
    double t = 0.0;
    for(int j = 0 ; j < cols; j++){
      r = ((double)rand()/(double)(RAND_MAX)) * 2.0;
      t += r;
      X[i * cols + j] = r;
    }
    if (t >= cols){
      y[i] = 1;
    }else {
      y[i] = 0;
    }
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

