#include <iostream>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
    char s1[MAX], s2[MAX];
    cin.getline(s1, MAX);
    cin.getline(s2, MAX);
    bool kt = myStrcat(s1, s2);
    if (myStrlen(s1) + myStrlen(s2) >= MAX)
    {
        cout << "Khong noi duoc. Khong du bo nho.";
        return 0;
    }
    if (!kt)
    {
        cout << "Khong noi duoc. Khong du bo nho.";
        return 0;
    }
    cout << s1 << endl;
    return 0;
}

int myStrlen(char s[])
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

bool myStrcat(char s1[], char s2[])
{
    int len1 = myStrlen(s1);
    int len2 = myStrlen(s2);
    if (len1 + len2 >= MAX)
        return false;

    for (int i = 0; i <= len2; i++)
    {
        s1[len1 + i] = s2[i];
    }
    return true;
}
