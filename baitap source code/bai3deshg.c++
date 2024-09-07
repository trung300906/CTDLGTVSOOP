//bài 3
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int xulytrunglap(int l[], int a[]){
    int cloudnum = 0, cloudip = 0;
    for(int i = 0 ; i < 10 ; i++){
        if(cloudnum != a[i]){
            cloudnum = a[i];
            l[cloudip] = cloudnum;
            cloudip = i;
        } 
    }
    return l[10];
}
int main(){
    srand(time(0));
    int a[10];
    int l[10];
    for (int i = 0 ;i<10;i++){
        a[i]=rand()%10+1;
        l[i] = 0;
        cout << a[i] << "\t" ;
    } 
    cout << endl;
    sort(a,a +10);
    xulytrunglap(l,a);
    for(int &item: l ){
        cout << item << "\t";
    }
    int *minn =  max_element(a, a+10);
    for(int &item:l){
        if(item == 0){
            continue;
        }
        if(*minn > item) *minn = item;
    }
    cout << endl << "giá trị cần tìm là: " << *minn <<  endl;
}