#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec(10);
    for (auto &i : vec)
    {
        i = rand() % 10 + 1;
    }
    vector<int>::iterator it = find(vec.begin(), vec.end(), 5);
    int distance_element = distance(vec.begin(), it);
    cout << "The first occurrence of 5 is at position: " << distance_element << endl;
    return 0;
}