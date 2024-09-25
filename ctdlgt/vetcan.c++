#include <iostream>
using namespace std;

int main(){
    int a=1,b=2,c=3;
    cout << "min of a b and c: " << min(a,min(b,c)) << endl;
}