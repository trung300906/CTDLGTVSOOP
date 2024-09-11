#include <iostream>
using namespace std;

int main()
{
	int array[4] = { 5, 8, 2, 7 };

	// in giá trị của biến array
	cout << "The array has value: " << array << '\n';

	// in địa chỉ của biến array
	cout << "The array has address: " << &array << '\n';

	// in địa chỉ của phần tử array[0]
	cout << "Element 0 has address: " << &array[0] << '\n';
    // toán tử trỏ (*) trả về giá trị phần tử đầu tiên: array[0]
	cout << *array << '\n'; // 5
    // khai báo con trỏ ptr trỏ vào mảng array
	int *ptr = array;
	cout << *(ptr) << '\n'; // 5

	char name[] = "Kteam"; // C-style string (mảng char)
	cout << *name << '\n'; // K
    /* pointer just a pointer, that's mean when you cout  typeid of a pointer, that's will be int * or Pi...
    meanwhile array just a array, for ex that's int arr[sizeof(array)] */
	system("pause");
	return 0;
}
