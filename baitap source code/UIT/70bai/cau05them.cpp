#include <bits/stdc++.h>

int main()
{
    int n;
    std::cin >> n;
    int a[n];
    for (auto &i : a)
        cin >> i;
    for (const auto &i : a)
    {
        if (i < 20 && i % 2 == 0)
            std::cout << i << std::endl;
    }
}