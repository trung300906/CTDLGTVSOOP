#include <bits/stdc++.h>
using namespace std;

string normalize(string &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (i == 0)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
            {
                input[i] = toupper(input[i]);
            }
        }
        else
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                input[i] = tolower(input[i]);
            }
        }
    }
    return input;
}

int main()
{
    int n = 10;
    int *ptr = &n;
    cout << ptr << endl;
}
