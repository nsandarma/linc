#include "linear.h"

int main(void){
  int rows,cols;
  rows = 100;
  cols = 3;
  Dataset *data = make_regression(rows, cols);
  Parameter *params = parameter(data,0.0);

  print_single(params->weight, data->cols);
  printf("intercept : %f\n",params->intercept);
  // double pred[data->rows];
  // ddot(params->weight,data->x,data->rows,data->cols,pred,1.0);
  // print_single(pred,rows);
  // // double mape = get_mape(data->y, pred,  rows);
  // // printf("%f\n",mape);
  // 
  write_matrix("x.csv", rows, cols, data->x);
  write_matrix("y.csv", rows, 0,  data->y);

  free_dataset(data);
  free_params(params);


  return 0;

}



