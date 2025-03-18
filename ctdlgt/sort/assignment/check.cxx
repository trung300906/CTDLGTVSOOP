// ID: 001
#include <iostream>
#include <vector>
using namespace std;
struct Mp
{
    string id;
    int x;
    Mp() {};
    Mp(string id, int x)
    {
        this->id = id;
        this->x = x;
    }
};
void tensor(vector<string> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void tensor_1(vector<string> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        tensor_1(arr, left, mid);
        tensor_1(arr, mid + 1, right);

        tensor(arr, left, mid, right);
    }
}
/*---------------------------------------------*/
void tensor_2_c(vector<Mp> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Mp> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].x > rightArr[j].x)
        {
            arr[k] = leftArr[i];
            i++;
        }
        else if (leftArr[i].x < rightArr[j].x)
        {
            arr[k] = rightArr[j];
            j++;
        }
        else
        {
            if (leftArr[i].id.size() != rightArr[j].id.size())
                arr[k] = (leftArr[i].id.size() < rightArr[j].id.size()) ? leftArr[i] : rightArr[j];
            else
                arr[k] = (leftArr[i].id < rightArr[j].id) ? leftArr[i] : rightArr[j];
            (arr[k].id == leftArr[i].id) ? i++ : j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void tensor_2(vector<Mp> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        tensor_2(arr, left, mid);
        tensor_2(arr, mid + 1, right);
        tensor_2_c(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (a.size() == 1)
    {
        cout << a[0] << " " << 1;
        return 0;
    }
    tensor_1(a, 0, n - 1);
    vector<Mp> b;
    int d = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            Mp tk(a[i - 1], d);
            b.push_back(tk);
            d = 1;
        }
        else
            ++d;
        if (i == a.size() - 1)
        {
            Mp tk(a[i], d);
            b.push_back(tk);
        }
    }
    tensor_2(b, 0, b.size() - 1);
    for (auto &i : b)
        cout << i.id << " " << i.x << "\n";
}