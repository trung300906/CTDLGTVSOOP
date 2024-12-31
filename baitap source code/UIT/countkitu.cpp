#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	fgets(s, MAX, stdin); // Nhap chuoi s
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);

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
	if (s1[len1 - 1] = '\n')
		s1[len1 - 1] = '\0';
	len1 = myStrlen(s1, MAX);
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
void DemKyTu(char s[])
{
	int count[MAX] = {0};
	int len = myStrlen(s, MAX);
	for (int i = 0; s[i] != '\0'; i++)
	{
		count[s[i]]++;
	}
	for (int i = 0; i < len && (s[i] != '\n' || s[i] != '\0'); i++)
	{
		if (count[static_cast<int>(s[i])] > 0)
		{
			cout << s[i] << ": " << count[static_cast<int>(s[i])] << endl;
			count[static_cast<int>(s[i])] = 0; // Xoa ky tu da xuat hien
		}
	}
}