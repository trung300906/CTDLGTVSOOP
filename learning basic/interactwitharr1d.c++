#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime>   // for time()
#include <string>
using namespace std;

// định nghĩa số phần tử mảng
#define MAX 1000

// khai báo prototype
void nhapMang(int arr[], int &n);
void xuatMang(int arr[], int n);
void hoanVi(int &a, int &b);
void sapXepTang(int arr[], int n);
void themMotPhanTuVaoMang(int a[], int &n, int idx, int x);
void xoaMotPhanTuTrongMang(int a[], int &n, int idx);
int main()
{
	int myArray[MAX]; // mảng myArray có MAX phần tử
	int nSize;		  // nSize là số phần tử được sử dụng, do user nhập

	// nhập mảng myArray tự động
	nhapMang(myArray, nSize);

	// xuất mảng myArray
	cout << "myArray: " << endl;
	xuatMang(myArray, nSize);

	// sắp xếp mảng tăng
	sapXepTang(myArray, nSize);
	// thêm 1 phần tử vào mảng
	int idx;
	cout << "Nhap vi tri can them: ";
	cin >> idx;

	int x;
	cout << "Nhap gia tri can them: ";
	cin >> x;
	themMotPhanTuVaoMang(myArray, nSize, idx, x);

	// xuất mảng sau khi thêm
	cout << "myArray: " << endl;
	xuatMang(myArray, nSize);
	// xóa 1 phần tử trong mảng
	cout << "Nhap vi tri can xoa: ";
	cin >> idx;

	xoaMotPhanTuTrongMang(myArray, nSize, idx);

	// xuất mảng sau khi xóa
	cout << "myArray: " << endl;
	xuatMang(myArray, nSize);

	return 0;
}

// hàm nhập mảng
void nhapMang(int arr[], int &n)
{
	// khởi tạo số ngẫu nhiên
	srand(time(NULL));

	cout << "Nhap so luong phan tu n : ";
	cin >> n;

	// khởi tạo ngẫu nhiên từng phần tử từ chỉ số 0 đến n – 1
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

// hàm xuất mảng
void xuatMang(int arr[], int n)
{
	// xuất từng phần tử cho mảng từ chỉ số 0 đến n – 1
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << i << "] = " << arr[i] << endl;
	}
}

// hoán vị giá trị 2 biến số
void hoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// sắp xếp mảng tăng dần bằng thuật toán interchange sort
void sapXepTang(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
				hoanVi(arr[i], arr[j]);
		}
	}
}
void themMotPhanTuVaoMang(int a[], int &n, int idx, int x)
{
	if (idx >= 0 && idx <= n)
	{
		for (int i = n; i > idx; i--)
			a[i] = a[i - 1];
		a[idx] = x;
		n++;
	}
}
void xoaMotPhanTuTrongMang(int a[], int &n, int idx)
{
	if (idx >= 0 && idx < n)
	{
		for (int i = idx; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
	}
}