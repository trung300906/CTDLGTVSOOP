#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int x =2, y=3; long long int dem = 0;
    long long int N = pow(10, 9);
    for(long long int i = y ; i <= N; i++) if( i%x == 0 && i%y == 0 ) dem++;
    cout << dem << endl;
    //cout <<  endl << sizeof(LONG_LONG_MAX) << endl;
}