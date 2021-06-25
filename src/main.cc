#include <iostream>
#include "conv_layer.h"
int main()
{
  std::cout << "hello UAM!\n";
  Tensor<3> t1(16, 16, 3);
  Tensor<3> t2(16, 16, 6);
  Convolution conv1 = Convolution(3, 6, 3);
  conv1.forward(t1, t2);
  t2.print();
  return 0;
}
