#include <bits/stdc++.h>

int main()
{
    srand(time(0));
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000 + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }*/
}