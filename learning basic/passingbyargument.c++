#include<bits/stdc++.h>
using namespace std;

void foo(int *value){
    *value = 20;
    /* because variables throught into function is address , so variables contain have to pointer */
}
void printarray(const int *array, int size){
    if(!array) return ;
    for(int i = 0 ; i < size ; ++i){
        cout << array[i] << ' ';
    }
}
int main(){
    int value = 10;
    cout << "cost of value: " << value << endl;
    foo(&value);
    cout << "cost of value after foo: " << value << endl;

    int array[10];
    for(auto &i:array) i = 0;
    printarray(array,10);
    system("pause");
}