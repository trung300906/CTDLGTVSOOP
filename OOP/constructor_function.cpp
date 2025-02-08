#include <bits/stdc++.h>
using namespace std;

typedef class myclass
{

public:
    int value1;
    int value2;
    int value3;
    myclass()
    {
        cout << "this is constructor of myclass \n";
    }
    myclass(int value1, int value2, int value3)
    {
        cout << "this is class with para_constructor \n";
    }
    void output(int);
} mc;

void mc::output(int value1)
{
    cout << "method output of: " << value1;
}
int main()
{
    mc test;
    mc tets(1, 2, 3);
    tets.output(2);
}