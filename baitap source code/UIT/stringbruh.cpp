#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    // delete after . point
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            size_t j = i + 1;
            while (j < s.size() && s[j] == ' ')
            {
                j++;
            }
            if (j - i > 1)
            {
                s.erase(s.begin() + i + 1, s.begin() + j - 1);
            }
        }
    }
    // delete before . point
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '.')
        {
            size_t j = i - 1;
            while (j < s.size() && s[j - 1] == ' ' && j >= 0)
            {
                j--;
            }
            if (i - j > 0)
            {
                s.erase(s.begin() + j, s.begin() + (i - 1));
            }
        }
    }
    cout << s << endl;
    return 0;
}