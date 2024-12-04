#include <iostream>
using namespace std;

void printIncreasingSubarrays(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool increasing = true;
            for (int k = i; k < j - 1; k++)
            {
                if (a[k] >= a[k + 1])
                {
                    increasing = false;
                    break;
                }
            }
            if (increasing && j > i + 1)
            {
                for (int k = i; k < j; k++)
                {
                    cout << a[k] << " ";
                }
                cout << endl;
            }
        }
    }
}
// O(n^4)
int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    printIncreasingSubarrays(a, n);
    return 0;
}
