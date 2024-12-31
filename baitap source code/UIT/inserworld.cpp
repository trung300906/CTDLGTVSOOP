#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
    char s[MAX], s1[MAX];
    fgets(s, MAX, stdin);
    fgets(s1, MAX, stdin);
    int k;
    cin >> k;
    if (k < 0 || k > myStrlen(s, 0))
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
    else
    {
        ChenChuoiTaiVitriK(s, s1, k);
        cout << s;
    }
    return 0;
}

int myStrlen(char s[], int k)
{
    int length = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (s[i] == '\0')
            break;
        length++;
    }
    return length;
}

void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
    int len = myStrlen(s, 0);
    int len1 = myStrlen(s1, 0);

    if (s1[len1 - 1] == '\n')
        s1[len1 - 1] = '\0';
    /*if (s[len - 1] == '\n')
        s[len - 1] = '\0';*/

    len1 = myStrlen(s1, 0);
    len = myStrlen(s, 0);
    
    for (int i = len; i >= k; i--)
    {
        s[i + len1] = s[i];
    }

    for (int i = 0; i < len1; i++)
    {
        s[k + i] = s1[i];
    }

    s[len + len1] = '\0';
}
