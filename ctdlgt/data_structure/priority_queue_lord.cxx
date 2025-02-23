#include <bits/stdc++.h>
using namespace std;

class Fraction
{
public:
    int x, y;
    Fraction(int x = 0, int y = 1) // Tránh mẫu số = 0
    {
        this->x = x;
        this->y = y;
    }

    bool operator<(const Fraction &op) const
    {
        return (this->x * op.y < this->y * op.x);
    }
};

priority_queue<Fraction, vector<Fraction>, less<Fraction>> pq;
int main()
{
    pq.push(Fraction(2, 4));
    pq.push(Fraction(4, 2));
    pq.push(Fraction(0, 2));
    cout << (pq.top().x) << "/" << pq.top().y;
}