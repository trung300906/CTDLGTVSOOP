#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int count;
    node *next[26];
    node()
    {
        count = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *cur = root;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            int idx = s[i] - 'a';
            if (cur->next[idx] == NULL)
                cur->next[idx] = new node();
            cur->next[idx]->count++;
            cur = cur->next[idx];
        }
    }
};

int main()
{
    cout << "hello world";
}