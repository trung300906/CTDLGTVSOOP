
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
    char s[MAX];
    cin.getline(s, MAX);
    if (myStrcmp(s, "") == 0)
        cout << "Chuoi rong." << endl;
    else
    {
        StringReverse(s);
        cout << s << endl;
    }
    return 0;
}

int myStrlen(char s[], int k)
{
    int length = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '\0')
            break;
        length++;
    }
    return length;
}

int myStrcmp(char s1[MAX], char s2[MAX])
{
    int len1 = myStrlen(s1, MAX);
    int len2 = myStrlen(s2, MAX);
    int min_len = min(len1, len2);
    for (int i = 0; i < min_len; i++)
    {
        if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    if (len1 < len2)
    {
        return -1;
    }
    else if (len1 > len2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void StringReverse(char st[])
{
    int len = myStrlen(st, MAX);
    st[len] = '\0';
    char result[len];
    int count = 0;
    for (int i = 0; i <= len; i++)
    {
        if (st[i] == '\0' || st[i] == ' ' || i == len)
        {
            for (int j = i - 1; st[j] != ' ' && j >= 0; j--)
            {
                result[count++] = st[j];
            }
            result[count++] = ' ';
        }
    }
    for (int i = 0; i < len; i++)
    {
        st[i] = result[i];
    }
}