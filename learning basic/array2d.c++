#include <iostream>
using namespace std;

#define ROW 2 // Max row
#define COL 3 // Max column

int main()
{
    // khởi tạo mảng 2 dòng 3 cột
    int arr[ROW][COL]{
        {6, 4, 3}, // row 1
        {7, 2, 8}  // row 2
    };

    // xuất giá trị các phần tử mảng
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << "a[" << i << "][" << j << "] = " << arr[i][j] << endl;
        }
    }
    return 0;
}
