// bài 4
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    srand(time(NULL));
    int a[10], tich = 1;
    for(int i=0 ;i<10; i++){
        a[i] =  rand() % 5 + 1;
        cout << a[i] << "\t";
        tich *= a[i];
    }
    cout << endl << "tích: " << tich << endl;
    cout << "các ước số là:";
    int dem = 0;
    for(int i=1; i<=sqrt(tich); i++){
        if(tich % i ==0){
            cout << i << "\t";
            dem++;
            if(i != sqrt(tich)){
                cout << tich/i << "\t";
                dem++;
            }
        }
    }
    cout<< endl << "số ước là: " << dem << endl;
}