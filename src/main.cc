#include <stdio.h>
#include "conv_layer.h"
int main(){
  printf("hello UAM!\n");
  Tensor<3> t1 = Tensor<3>(224,224,3);
  Convolution conv1 = Convolution(32,64,3);
  Tensor<3> t2 = conv1.forward(t1);
	//T.print();
  return 0;
}
