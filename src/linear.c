#include "linear.h"

// len coef/weight = len(features)
// len intercept/bias = 1 if class == binary_class else len(class)

double sum(double *x, int n){
  double t=0.0;
  for(int i = 0; i < n;i++){
    t += x[i];
  }
  return t;
}

double get_mape(double y_true[],double y_pred[],int row){
  double mape = 0.0;

  for (int i = 0; i < row; i++){
    if (y_true[i] != 0) {
      mape += fabs((y_true[i] - y_pred[i]) / y_true[i]);
    }
  }
  mape = (mape / row) * 100.0;
  return mape;
}

void swap_rows(double *matrix, double *identity, int row1, int row2, int size) {
  for (int i = 0; i < size; i++) {
    // Swap matrix rows
    double temp = matrix[row1 * size + i];
    matrix[row1 * size + i] = matrix[row2 * size + i];
    matrix[row2 * size + i] = temp;

    // Swap identity rows
    temp = identity[row1 * size + i];
    identity[row1 * size + i] = identity[row2 * size + i];
    identity[row2 * size + i] = temp;
  }
}

// Fungsi untuk menghitung invers matriks menggunakan eliminasi Gauss-Jordan
int linalg_inv(double *matrix, double *inverse, int size) {
  // Membuat matriks identitas
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      inverse[i * size + j] = (i == j) ? 1.0 : 0.0;
    }
  }

  // Proses eliminasi Gauss-Jordan
  for (int i = 0; i < size; i++) {
    if (matrix[i * size + i] == 0) {
      // Pastikan elemen diagonal utama tidak nol
      int swapped = 0;
      // Cari baris lain yang tidak nol pada kolom i untuk ditukar
      for (int j = i + 1; j < size; j++) {
        if (matrix[j * size + i] != 0) {
          swap_rows(matrix, inverse, i, j, size);
          swapped = 1;
          break;
        }
      }
      if (!swapped) {
        return 0; // Matriks singular, tidak dapat dihitung inversnya
      }
    }

    // Bagi seluruh baris dengan elemen diagonal untuk membuatnya 1
    double diag_element = matrix[i * size + i];
    for (int j = 0; j < size; j++) {
      matrix[i * size + j] /= diag_element;
      inverse[i * size + j] /= diag_element;
    }

    // Eliminasi elemen selain diagonal di kolom i
    for (int j = 0; j < size; j++) {
      if (j != i) {
        double factor = matrix[j * size + i];
        for (int k = 0; k < size; k++) {
          matrix[j * size + k] -= factor * matrix[i * size + k];
          inverse[j * size + k] -= factor * inverse[i * size + k];
        }
      }
    }
  }
  return 1; // Matriks berhasil dihitung inversnya
}

Parameter *parameter(Dataset *data,double intercept){
  Parameter *params = (Parameter *)malloc(sizeof(Parameter)) ;
  int cols;
  double *theta = (double *)malloc(data->cols * sizeof(double));
  for (int i = 0 ; i < data->cols; i++){
    theta[i] = 0;
  }

  if (intercept != 0.0){
    cols = data->cols +1;

    double x_intercept[data->rows * cols];
    double x_transpose[data->rows * cols];
    double xt_dot_x[cols * cols];
    double linalg[cols * cols];
    double linalg_xt[cols * data->rows];
    double theta_temp[cols];

    for(int i = 0; i < data->rows; i++){
      for(int j = 0 ; j < cols;j++){
        double tmp;
        if (j != data->cols){
          tmp = data->x[i * data->cols + j];
        }else{
          tmp = intercept;
        }
        x_intercept[i * cols + j] = tmp;

      }
    }

    // transpose X
    transpose(x_intercept, x_transpose, data->rows, cols);

    // Xt dot X
    dot(x_transpose,x_intercept,xt_dot_x,cols,data->rows,data->rows,cols);

    // linalg_inv
    linalg_inv(xt_dot_x,linalg, cols);

    // linalg dot xt
    dot(linalg,x_transpose,linalg_xt,cols,cols,cols,data->rows);

    // theta
    ddot(data->y,linalg_xt,cols,data->rows,theta_temp,0.0);

    for (int i = 0 ; i < data->cols; i ++){
      theta[i] = theta_temp[i];
    }

    params->weight = theta ;
    params->intercept = theta_temp[cols];
    return params;


  }else{

    double x_transpose[data->rows * data->cols];
    double xt_dot_x[data->cols * data->cols];
    double linalg[data->cols * data->cols];
    double linalg_xt[data->cols * data->rows];

    // transpose X
    transpose(data->x, x_transpose, data->rows, data->cols);

    // Xt dot X
    dot(x_transpose,data->x,xt_dot_x,data->cols,data->rows,data->rows,data->cols);

    // linalg_inv
    linalg_inv(xt_dot_x,linalg, data->cols);

    // linalg dot xt
    dot(linalg,x_transpose,linalg_xt,data->cols,data->cols,data->cols,data->rows);

    // theta
    ddot(data->y,linalg_xt,data->cols,data->rows,theta,0.0);

    params->weight = theta ;
    params->intercept = intercept;
    return params;
  }


}

