#pragma once
#include <iterator>


template <typename T>
class Vector {
public:
	T* arr;
	size_t size = 0;
	size_t capacity = 1;
	
	Vector() {
		arr = new T[size];
		capacity = size * 2;
	}

	T* begin() {
		return arr;
	}

	T* end() {
		return arr + size;
	}

	void reserve(size_t n) {
		if (n <= capacity) return;
		T* newArr = new T[n];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity = n;
	}

	void resize(size_t n) {
		T* newArr = new T[n];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;

		if (n > size) {
			for (int i = size; i < n; i++) {
				arr[i] = 0;
			}
		}

		size = n;
	}

	void resize(size_t n, const T& value) {
		T* newArr = new T[n];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;

		if (n > size) {
			for (int i = size; i < n; i++) {
				arr[i] = value;
			}
		}

		size = n;
	}

	void pushBack(const T& value) {
		if (capacity <= size+1){
			reserve(2 * (size + 1));
		}
		arr[size] = value;
		size++;
	}

	void pushFront(const T& value) {
		insert(0, value);
	}

	void insert(size_t n, const T& val) {
		if (capacity <= size+1) {
			reserve(2 * (size+1));
		}
		if (n > size) {
			throw std::invalid_argument("n is greater than size");
		}
		else {
			for (int i = size + 1; i > n; i--) {
				arr[i] = arr[i - 1];
			}
			arr[n] = val;
			size++;
		}

	}

	void erase(T* ptr) {
		size_t n = ptr - begin();
		for (size_t i = n; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}

	size_t sizeVector() {
		return size;
	}

	size_t capacityVector() {
		return capacity;
	}

	T& operator[](int index)
	{
		return arr[index];
	}

};
//begin end push_back insert erase at? 
