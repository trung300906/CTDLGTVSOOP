#include <iostream>
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
    while (s[k + length] != '\0')
    {
        length++;
    }
    return length;
}

int myStrcmp(char s1[], char s2[])
{
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);
    int min_len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < min_len; i++)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] > s2[i]) ? 1 : -1;
        }
    }
    return (len1 == len2) ? 0 : (len1 > len2) ? 1 : -1;
}

void myStrcpy(char s[], int vt, char s1[], int k)
{
    for (int i = 0; i < k; i++)
    {
        s[vt + i] = s1[i];
    }
    s[vt + k] = '\0';
}

void mySubstr(char s[], int b, int count, char ss[])
{
    for (int i = 0; i < count && s[b + i] != '\0'; i++)
    {
        ss[i] = s[b + i];
    }
    ss[count] = '\0';
}

bool myStrcat(char s1[], char s2[])
{
    int len1 = myStrlen(s1, 0);
    int len2 = myStrlen(s2, 0);
    for (int i = 0; i <= len2; i++)
    {
        s1[len1 + i] = s2[i];
    }
    return true;
}

void StringReverse(char st[])
{
    int len = myStrlen(st, 0);
    char result[len];
    int count = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (st[i] == ' ' || i == 0)
        {
            if (i == 0 && st[i] != ' ')
            {
                for (int j = i; st[j] != ' ' && j < len; j++)
                {
                    result[count++] = st[j];
                }
                result[count++] = ' ';
                continue;
            }
            for (int j = i + 1; st[j] != ' ' && j < len; j++)
            {
                result[count++] = st[j];
            }
            result[count++] = ' ';
        }
    }
    result[count] = '\0';
    for (int i = 0; i < len; i++)
    {
        st[i] = result[i];
    }
}
