
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrlen(char *s);
char *myStrcat(char *s1, char *s2);

int main()
{
    char *s1 = NULL, *s2 = NULL;
    s1 = new char[MAX];
    s2 = new char[MAX];
    // gets(s1);
    // gets(s2);
    cin.getline(s1, MAX - 1);
    cin.getline(s2, MAX - 1);
    char *s = myStrcat(s1, s2);
    puts(s);
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
char *myStrcat(char *s1, char *s2)
{
    int len1 = myStrlen(s1);
    int len2 = myStrlen(s2);

    for (int i = 0; i <= len2; i++)
    {
        s1[len1 + i] = s2[i];
    }
    return s1;
}