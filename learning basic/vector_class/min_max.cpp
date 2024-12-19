#include <bits/stdc++.h>
using namespace std;

struct design
{
    int value1;
    int value2;
    int value3;
};

int main()
{
    int n = 10;
    vector<int> a(n);
    generate(a.begin(), a.end(), rand);

    // Find max using max_element
    vector<int>::iterator max_position = max_element(a.begin(), a.end());
    int max = *max_position;
    cout << "Max: " << max << endl;

    // Find min using min_element
    vector<int>::iterator min_position = min_element(a.begin(), a.end());
    // Using *min_position to get the value at the min_position iterator in vector a
    int min = *min_element(a.begin(), a.end());
    cout << "Min: " << min << endl;

    // Find both min and max at the same time using minmax_element
    pair<vector<int>::iterator, vector<int>::iterator> minmax = minmax_element(a.begin(), a.end());
    pair<int, int> minmax_e(*minmax.first, *minmax.second);
    cout << "Min: " << *minmax.first << ", Max: " << *minmax.second << endl;

    // Initialize vector b with random values for struct design
    vector<design> b(n);
    for (auto &i : b)
    {
        i.value1 = rand() % (*minmax.second - *minmax.first + 1) + *minmax.first;
        i.value2 = rand() % (*minmax.second - *minmax.first + 1) + *minmax.first;
        i.value3 = rand() % (*minmax.second - *minmax.first + 1) + *minmax.first;
    }

    // Find min and max in struct based on value1
    auto minmax2 = minmax_element(b.begin(), b.end(), [](const design &lhs, const design &rhs)
                                  { return lhs.value1 < rhs.value1; });

    cout << "Min value1 in struct: " << minmax2.first->value1 << endl;
    cout << "Max value1 in struct: " << minmax2.second->value1 << endl;

    return 0;
}
