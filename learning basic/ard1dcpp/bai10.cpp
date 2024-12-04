#include <bits/stdc++.h>
using namespace std;

int insertion_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0; // Returning the number of comparisons made during the sorting process.
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    a.insert(a.begin(), b.begin(), b.end());
    insertion_sort(a);
}