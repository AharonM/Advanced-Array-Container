#include <iostream>

#include "array.h"
#include "array_exception.h"

using namespace std;

int main() {
	Array arr(10);
	int n;
	try {
		cout << arr[arr.getSize()];
		throw "Out of bounds exception not thrown";
	} catch (ArrayException e) {
		cout << "Caught expected ArrayException: " << e << endl;
	}

	for (int i = 0; i < 7; i++)
		arr += i;

	cout << "arr:\n" << arr << endl;
	
	Array arrI = arr;
	cout << "arrI:\n" << arrI << endl;
	
	arr += 9;
	cout << "arrI:\n" << arrI << endl;
	
	arrI += 2;
	cout << "arr:\n" << arr << endl;
	
	Array arrG(10);
	for (int i = 0; i < 6; i++)
		arrG += i;
	cout << "arrG:\n" << arrG << endl;
		
	arrI = arrG;
	cout << "arrI:\n" << arrI << endl;
	arrG += 14;
	cout << "arrI:\n" << arrI << endl;	
	
	Array arrK(10);	
	for (int i = 19; i < 25; i++)
		arrK += i;
	
	cout << "arrG:\n" << arrG << endl;
	cout << "arrK:\n" << arrK << endl;
	arr = arrK + arrG;
	cout << "arr:\n" << arr << endl;
	
	arrI = arrI+7;
	cout << "arrI + 7 :\n" << arrI << endl;

	cout << "arrI + arrG:\n" << arrI + arrG << endl;
	Array arrO;
	if(arrO.isEmpty())
	cout << "Array is empty\n";
	else
	cout << "Array is Not empty\n";
	
	cout << "Enter an int to look up in the array: ";
	cin >> n;
	if(arrK.contains(n)==true)
	cout << "Array contains " << n << endl;
	else
	cout << "Array does not contain " << n << endl; 
	
	cout << "Enter an int to look up it's location in the array: ";
	cin >> n;
	if(arrK.find(n) >= 0)
	cout << "The int is located at position: " << arrK.find(n)  << " in the array" << endl;
	else
	cout << "Array does not contain " << n << endl; 
	
	return 0;
}


