#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 14, 3, 6, 27, 12 };
	for (auto item: arr) // compiler tự dộng xác định kiểu cho item
	{
		cout << item << " ";
	}
	cout << endl;

	return 0;
}
