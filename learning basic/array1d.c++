#include <iostream>
#include <string>
using namespace std;

// định nghĩa số phần tử mảng
#define MAX 3

int main()
{
	int arr[MAX];

	// nhập mảng
	cout << "Array input:" << endl;
	for (int i = 0; i < MAX; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	// xuất mảng
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
