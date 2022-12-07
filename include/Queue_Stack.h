#pragma once

template <class T>

class Vector {

private:

	T* data = 0;
	int size = 0;
	int capacity = 0;

public:

	Vector() {};
	Vector(int n) {
	
		data = new T[2 * n];
		for (int i = 0; i < n; i++) {

			data[i] = 0;
		}
		size = n;
		capacity = 2 * n;
	};

	~Vector() {
	
		delete[] data;
	};

	Vector(const Vector& v) {
	
		resize(v.size);
		for (int i = 0; i < size; i++) {

			data[i] = v.data[i];
		}
	};

	Vector& operator=(const Vector& v) {
	
		if (this == &v) {

			return *this;
		}
		delete[] data;
		capacity = v.capacity;
		size = v.size;
		data = new T[capacity];
		for (int i = 0; i < size; i++) {

			data[i] = v.data[i];
		}
	};

	T return_data(int i) {

		return data[i];
	}
	
	int size_1() {
	
		return size;
	};

	void resize(int newSize) {
	
		int res = newSize > size ? size : newSize;
		if (newSize < capacity) {

			size = newSize;
		}
		else {

			T* data_copy = new T[2 * newSize];
			for (int i = 0; i < res; i++) {

				data_copy[i] = data[i];
			}
			delete[] data;
			data = data_copy;
			capacity = 2 * newSize;
			size = newSize;
		}
	};

	void push_back(T k) {
	
		if (size == capacity) {

			resize(size + 1);
			data[size-1] = k;
		}
		else {

			data[size] = k;
			size++;
		}
	};

	T pop_back() {
	
		T tmp = data[size-1];
		size--;
		return tmp;
	};

	void pop_stack(T k) {

		for (int i = k; i < size; i++) {

			data[i] = data[i + 1];
		}
		size--;
	}

	void print() {
	
		for (int i = 0; i < this->size; ++i) {

			std::cout << this->data[i] << " ";
		}
		std::cout << std::endl;
	};

	
};


template <class T>

class Stack {

private:

	Vector<T> v;

public:

	Stack() {};

	int size() {

		return v.size_1();
	};

	bool empty() {

		return v.size_1() == 0;
	};

	void push(T k) {

		v.push_back(k);
	};

	void pop() {

		if (v.size_1() == 0) {
	
			throw "error";
		}
		v.pop_stack((v.size_1()) - 1);
	};

	T top() {

		if (v.size_1() == 0) {

			throw "error";
		}
		else {

			return v.return_data((v.size_1()) - 1);
		}
	}
};


template <class T>

class Queue {

private:

	T* data;
	int size;
	int capacity;
	int first;
	int last;

public:

	Queue() {

		size = 0;
		capacity = 1;
		data = new T[capacity];
		first = 0;
		last = 0;
	}

	~Queue() {

		delete[] data;
	}

	void resize(int newSize) {

		
		T* data_tmp = new T[2 * newSize];

		for (int i = 0; i < newSize; i++) {

			data_tmp[i] = data[i];
		}

		int tmp_first = 0;
		int tmp_last = last;

		delete[] data;
		data = data_tmp;
		capacity = 2 * newSize;
		size = newSize;
		first = tmp_first;
		last = tmp_last;
	};

	int size_q() {

		return size;
	}

	bool empty() {
	
		return size == 0;
	}

	void push(T k) {

		data[first] = k;
		first++;
		size++;
		if ((first == last) && (size != 0)) {

			resize(size);
		}
	}

	void pop() {

		if (size == 0) {

			throw "error";
		}
		else {

			data[first % capacity] = 0;
			first++;
			size--;
		}
	}

	T top_q() {

		if (size < 1) {

			throw "error";
		}
		return data[first % size];
	}
};





