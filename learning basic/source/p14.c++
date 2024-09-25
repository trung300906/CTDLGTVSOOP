#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    double x;
    cin >> x;
    if(x >= 0){
        double chuvi = x*4, dientich = x*x;
        cout << fixed << showpoint;
        cout << "Chu vi: " << setprecision(2) << chuvi << endl;
        cout << "Dien tich: " << setprecision(2) << dientich << endl;
    }
}