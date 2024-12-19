#include <bits/stdc++.h>
using namespace std;

struct pair_element
{
    pair<int, int> element1;
    pair<int, bool> element2;
};
int main()
{
    vector<pair<pair_element, pair_element>> elements(10);
    for (auto &i : elements)
    {
        i.first.element1 = make_pair(rand() % 10 + 1, rand() % 10 + 1);
        i.first.element2 = make_pair(i.first.element1.first + i.first.element1.second, rand() % 2 == 0);
        i.second.element1 = make_pair(rand() % 10 + 1, rand() % 10 + 1);
        i.second.element2 = make_pair(i.second.element1.first + i.second.element1.second, rand() % 2 == 0);
    }
}