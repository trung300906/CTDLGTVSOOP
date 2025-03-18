#include <bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    int x, y, z;
    Fraction()
    {
        cin >> x >> y >> z;
    }
    Fraction(int x, int y, int z) // Tránh mẫu số = 0
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator>(const Fraction &op) const
    {
        if (this->x != op.x)
        {
            return this->x > op.x;
        }
        else if (this->y != op.y)
        {
            return this->y < op.y;
        }
        return this->z > op.z;
    }
};

priority_queue<Fraction, vector<Fraction>, greater<Fraction>> pq;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Fraction temp;
        pq.push(temp);
    }
    while (!pq.empty())
    {
        cout << pq.top().x << " " << pq.top().y << " " << pq.top().z << "\n";
        pq.pop();
    }
}