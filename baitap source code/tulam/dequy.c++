#include <iostream>
#include <algorithm>
#include <String>
#include <bits/stdc++.h>
using namespace std;

#if 0
// tính giai thừa của 1 số nguyên dương n
int giaithua(int n){
    if(n==0 || n==1) return 1; else{
        return n*giaithua(n-1);
    }
}
int main(){
    int n=5;
    cout << "Giai thua cua so nguyen duong "<<n<<" la: " << giaithua(n);

}
#endif
#if 0
int tong(int n){
    if(n==0) return 0;
    if(n==1) return 1; else return n+ tong(n-1);
}
int main(){
    int n = 100;
    cout << "tổng cấc số từ 1 đến " <<n <<"l à: " <<  tong(n);
}
#endif
#if 0
int tong(int a[],int n){
    if(n == 1) return a[n-1];
    if(n == 0) cout << "rỗng"; else return a[n-1] + tong(a, n-1) ;
}
int main(){
    srand(time(0));
    int n = 10;
    int a[n];
    // khởi tạo ngẫu nhiên cho mảng a[]
    for(int i=0; i<n;i++){
        a[i] =  rand() % 100 +1;
        cout << a[i] << "\t";
    }
    cout<< endl << "tổng tất cả các phần tử của mảng a là: " << tong(a,n) << endl;
}
#endif
#if 0
// fibornachhi thứ n
int fibor(int n){
    if(n==0) return 0; else if(n==1) return 1; else return fibor(n-1) + fibor(n-2);
}
int main(){
    int n = 10;
    cout << "số fibornacchi thứ" << n <<"là: " << fibor(n);
}
#endif
#if 0
int tongn(int n){
    if(n>=0 && n<= 9) return n; else return (n%10) + tongn(n/10);
}
int main(){
    int n= 12345;
    cout << "tổng các chữ số của n là: " << tongn(n);
}
#endif
#if 0
    int max(int a[], int n,int start,int end){
        if(start == end) return a[start];
        int mid = (start + end)/2;
        int max1 = max(a, n, start, mid);
        int max2 = max(a, n, mid+1, end);
        return (max1>max2)? max1 : max2;
    }
    int min(int a[], int n,int start,int end){
        if(start == end) return a[start];
        int mid = (start + end)/2;
        int min1 = min(a, n, start, mid);
        int min2 = min(a, n, mid+1, end);
        return (min1<min2)? min1 : min2;
    }
    int main(){
        srand(time(0));
        int n = 10, a[n];
        for(int i=0; i < n; i++ ){ a[i] =  rand()% 10 +1; cout << a[i] << "\t";}
        cout << endl;
        cout <<  "max trong a là: " << max(a,n, 0, n-1); cout << endl;
        cout << "min trong a là: " << min(a,n,0,n-1);
    }
#endif
#if 0
int ucln(int a, int b){
    if(b == 0) return a; else return ucln(b, a%b);
}
int main(){
    int n,k;
    cin >> n >> k;
    cout << ucln(n,k);
}
#endif
#if 0
auto daochuoi(string s, int start, int end){
    if(start == end){
        return s;
    }else if(start ==  end-1){
        swap(s[start], s[end]);
        return s;
    } else{
        swap(s[start] , s[end]);
        return daochuoi(s,start+1, end-1);
    }
}
int main(){
    string k;
    getline(cin, k);
    int mid =  (k.length()-1)/2;
    int start =  -1;
    int end = k.length();
    cout << daochuoi(k, start, end);
}
#endif
// tam giác pascal
int giaithua(int n){
    if(n==0 || n==1) return 1; else{
        return n*giaithua(n-1);
    }
}
auto pascal(int n, int i, int dem){
    if(n==i){
        cout << 1;
        return;
    }else{
        if(i==dem){
            if(dem ==0) cout << setw((n - dem - 1)/2 + 7) << ' ';
            cout << giaithua(dem)/(giaithua(i) * (giaithua(dem-i)));
            cout << endl;
            pascal(n, 0, ++dem);
        } else if(i!= dem) {
            if(i==0) cout << setw((n - dem - 1)/2 + 7) << ' ';
            cout << giaithua(dem)/(giaithua(i) * (giaithua(dem-i)));
            cout << "\t";
            pascal(n, ++i, dem);
        }
    }
}
int main(){
    int n, i=0, dem = 0;
    cin >> n;
    pascal(n,i,dem);
}