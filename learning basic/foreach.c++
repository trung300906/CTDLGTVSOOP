#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10];
    for (int &i : arr)
    {
        cin >> i;
    }
    for (const int &i : arr)
        cout << i << endl;
    /* Sử dụng tham chiếu (reference) hoặc tham chiếu hằng (const reference) cho biến khai báo trong vòng lặp for-each vì lý do hiệu suất. */
}