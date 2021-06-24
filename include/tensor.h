#include <array>
#incldue <initializer_list>

template<int N>
class Tensor
{
	private:
		int[N] _shape;
		float* _data_arr
		int dim = N;
	public:
		Tensor(std::initializer_list<int> shape){
			_shape { shape }
		}

}
