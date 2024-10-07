#include "linear.h"


int main(void){
  int rows,cols;
  rows = 100;
  cols = 4;

  Dataset *data = create_data(rows, cols);
  print_dataset(data);
  free_dataset(data);

}



