#include "layer.h"

class Convolution: public ILayer
{
	private:
		int _kernel_size;
		int _M;
		float* _weight_arr;
	public:
		void Convolution(int ks, int M){
			_kernel_size = ks;
			_M = M;
			_weight_arr = new float*[ks*ks*M]
		}

		void forward(float* src_tensor , float* dst_tensor);

		int get_weight_size(){
			return _kernel_size*_kernel_size*M;	
		}	
}
