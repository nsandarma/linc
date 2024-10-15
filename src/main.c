#include "linear.h"


int main(void){
  int rows,cols;
  rows = 10;
  cols = 3;
  Dataset *data = make_regression(rows, cols);
  Parameter *params = parameter(data);


  print_single(params->weight, data->cols);
  double pred[data->rows];
  ddot(params->weight,data->x,data->rows,data->cols,pred,0.0);
  print_single(pred, rows);


  free_dataset(data);
  free_params(params);


  return 0;

}



