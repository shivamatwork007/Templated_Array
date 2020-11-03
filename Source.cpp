#include <iostream>

template<typename T,size_t size> 
class Array {
public:
	Array() 
	{
		memset(m_array, 0, size);
	}
	~Array() {

	}
	constexpr size_t GetSize() const {
		return size;
	}
	T& operator[](size_t idx) {
		return m_array[idx];
	}
	
	const T& operator[](size_t && idx) const {  ///std::cout << ref[i];
		if(!(idx<size))
		{
			__debugbreak(); ///debugModeonly::
		}
		return m_array[idx];
	}
	const T& operator[](const size_t & idx) const {///std::cout<<ref[5];
		return m_array[idx];
	}
private:
	T m_array[size];
};
int main() {
	Array<int,2> A;
	static_assert(A.GetSize()<10,"Too large");

	/// <summary>
	/// make Another Array with same size as above (A) array
	/// </summary>
	/// <returns></returns>
	Array<float, A.GetSize()>Arr_f;

	std::cout << A.GetSize()<<" " <<A[0] << std::endl;
	const auto& ref = A;
	std::cout<<ref[5];
	int i = 0;
	std::cout << ref[i];
}