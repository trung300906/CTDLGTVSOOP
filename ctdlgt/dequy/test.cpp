#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[] = "chao cac ban";
    char b[20];
    for (int i = 0; i < strlen(a); i++)
    {
        b[i] = a[strlen(a) - i];
    }
    cout << b << endl;
    return 0;
}