/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
do
while
###End banned keyword*/
#include <iostream>
using namespace std;
int input(int &n)
{
    cin >> n;
    return n;
}

int sum(int n, int &s)
{
    if (n <= 0)
        return s;
    s += n % 10;
    return sum(n / 10, s);
}
int main()
{
    int n, s = 0;
    input(n);
    sum(n, s);
    cout << s;
}
