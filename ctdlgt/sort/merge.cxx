#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int left, int right)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == left)
            cout << "[ ";
        cout << arr[i] << " ";
        if (i == right)
            cout << "] ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }

    // Print the merged segment
    printArray(arr, left, right);
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    mergeSort(arr, 0, n - 1);

    return 0;
}
