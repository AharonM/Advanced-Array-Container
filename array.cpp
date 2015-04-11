#include <iostream>

#include "array.h"
#include "array_exception.h"

using namespace std;

#define DEBUG true

ostream &operator <<(ostream &os, const Array &array) {
	os << "{";
	for (int i = 0; i < array.size; i++)
		os << array.arr[i] << (i < array.size-1 ? ", " : "");
	os << "}";
	return os;
}


Array &Array::operator+=(const Array &obj){
	int j = size;
	size += obj.size;
	checkCapacity();
	for (int i=0; i < obj.size; i++)
    arr[j+i] = obj.arr[i];
	return *this;
}

Array operator+(const Array &array, int i){
	Array result;
	result.size = array.size;
	result.checkCapacity();
	for (int x = 0; x < result.size; x++) 
		result.arr[x] = array.arr[x];
	result.arr[result.size] = i;
	result.size++;
	return result;
}

Array operator+(const Array &array1, const Array &array2){
	Array result = array1;
	return result += array2;
}


Array::Array(const Array &other) : arr(new int[other.capacity]), capacity(other.capacity), size(other.size) {
	for (int i = 0; i < size; i++) 
		arr[i] = other.arr[i];
}

Array &Array::operator =(const Array &rhs) {
	if (this == &rhs) return *this;
	delete [] arr;
	size = rhs.size;
	capacity = rhs.capacity;
	arr = new int[capacity]; 
	for (int i = 0; i < size; i++) 
		arr[i] = rhs.arr[i];
	return *this;
}

int &Array::operator [](int index) {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}

const int &Array::operator [](int index) const {
	if (index < 0 || index >= size) throw ArrayException("Index out of bounds");
	return arr[index];
}

Array &Array::operator +=(int val) {
	checkCapacity();
	arr[size] = val;
	size++;
	return *this;
}

void Array::checkCapacity() {
	if (size < capacity) return;

	capacity *= 2;
	int *newArr = new int[capacity];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete [] arr;
	arr = newArr;
	if (DEBUG) cerr << "Increased array capacity to " << capacity << endl;
}

bool Array::isEmpty(){
	if (size == 0)
	return true;
	else
	return false;
}

bool Array::contains(int val) const{
	for (int i=0; i < this->size; i++){
		if(this->arr[i] == val)
			return true;}
	return false;
}

int Array::find(int val) const{
	for(int i=0; i < this->size; i++){
	if(this->arr[i] == val)
	return i;}
	return -1;
}


