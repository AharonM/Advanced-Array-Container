#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
	friend std::ostream &operator <<(std::ostream &os, const Array &array);
	friend Array operator+(const Array &array, int i);
    friend Array operator+(const Array &array1, const Array &array2);
    
public:
	Array(int capacity=100) : arr(new int[capacity]), capacity(capacity), size(0) {}
	Array(const Array &other);
	~Array() {delete [] arr;}
	Array & operator =(const Array &rhs);
	int &operator [](int index);
	const int &operator [](int index) const;
	Array &operator+=(int val);
	Array &operator+=(const Array &arr);
	int getSize() const {return size;}
	bool isEmpty();
    bool contains(int val) const;
    int find(int val) const;
    
private:
	void checkCapacity();
	int *arr;
	int capacity;
	int size;
};

#endif
