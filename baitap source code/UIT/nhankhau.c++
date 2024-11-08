#include <iostream>
using namespace std;

int main()
{
    int t;
    char gen;
    do
    {
        cin >> t;
    } while (t > 100 || t < 0);
    cin >> gen;
    if (t >= 21)
    {
        if (gen == 'm' || gen == 'M')
        {
            cout << 1;
        }
        else if (gen == 'f' || gen == 'F')
        {
            cout << 2;
        }
        else
            cout << "I do not know why";
    }
    if (t < 21)
    {
        if (gen == 'm' || gen == 'M')
        {
            cout << 3;
        }
        else if (gen == 'f' || gen == 'F')
        {
            cout << 4;
        }
        else
            cout << "I do not know why";
    }
}