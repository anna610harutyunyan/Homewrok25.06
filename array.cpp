#include <iostream>
#include <exception>
class Array
{
	int* ptr = nullptr;
	int size;
public:
	Array(int size)
	{
		this->size = size;
		ptr = new int[size];
		std::cout << "Constructor  " << std::endl;
	}

	Array(const Array& other)
	{
		this->size = other.size;
		this->ptr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << "Copy constructor " << std::endl;

	}
	Array& operator=(const Array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		this->size = other.size;
		delete[] this->ptr;
		this->ptr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			ptr[i] = other.ptr[i];
		}
		std::cout << "Operator =  " << std::endl;

		return *this;

	}

	int& operator [] (int index)
	{
		std::cout << __func__ << std::endl;
		return ptr[index];

	}
	~Array()
	{
		delete[] ptr;
		ptr = nullptr;
		std::cout << " Destructor " << std::endl;

	}

	int get_element(int index)
	{
		if (index >= size || index < 0)
		{
			std::cerr << "Error!! Index is out of size boundaries \n";
			throw std::runtime_error("Check the size ");
		}

		return  ptr[index];
	}
};

int main(int argc, char** argv)
{
	Array array1(7);
	std::cout << "5th element in array is " << array1.get_element(5);
	Array array2(array1);
	Array array3(4);
	array3 = array1;
	int value = array1.operator[](5);





	return 0;
}