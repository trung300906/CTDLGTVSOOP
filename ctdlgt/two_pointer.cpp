#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(NULL));
#if 0
    set<int> a;
    for (int i = 0; i < 10; i++)
    {
        a.insert(i);
    }
    set<int> b;
    for (int i = 11; i < 100; i++)
    {
        b.insert(rand() % 100 + 1);
    }
    set<int> c;
    for (auto &i : a)
    {
        c.insert(i);
    }
    for (auto &i : b)
    {
        c.insert(i);
    }
    for (auto &i : c)
    {
        cout << i << " ";
    }
#endif
#if 1
    set<int> a;
    set<int> b;
    vector<int> c;
    for (int i = 0; i < 10; i++)
    {
        a.insert(rand() % 100 + 3);
        b.insert(rand() % 100 + 1);
    }
    set<int>::iterator ait = a.begin(), bit = b.begin();
    while (ait != a.end() && bit != b.end())
    {
        if (ait == a.end())
        {
            c.push_back(*bit);
            bit++;
            continue;
        }
        if (bit == b.end())
        {
            c.push_back(*ait);
            ait++;
            continue;
        }
        if (*ait <= *bit)
        {
            c.push_back(*ait);
            ait++;
        }
        else
        {
            c.push_back(*bit);
            bit++;
        }
    }
    for (auto &i : c)
    {
        cout << i << " ";
    }
#endif
}