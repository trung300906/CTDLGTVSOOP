#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int main()
{
    char s[MAX];
    // cout << "Nhap chuoi ky tu: ";
    fgets(s, MAX, stdin);
    // s[strcspn(s, "\000")] = '\n';
    //  cout << s << endl;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            cout << "CHUOI KHONG HOP LE.";
            return 0;
        }
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        cout << s[i];
    }
    return 0;
}