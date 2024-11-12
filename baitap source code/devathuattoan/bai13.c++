#include <bits/stdc++.h>
using namespace std;

int logic(int a[], int n, int b[], int n1){ // lớn trước nhỏ sau
    int dem = 0;
    int j=0;
    for(int i=0;i<n && j<n1 ; i++){ // lưu ý khi dùng các toán tử, với toán tử , thì sẽ trả về giá trị bên trái(toán tử cuối là j <n1) khi đó i có thể vươn lên n và lỗi mảng
        if(a[i] == b[j]){
            j++;
            if(j==n1){
                dem++;
                j=0;
            }
            if (i==(n-1) && j<n1 ){
                break;
            }
        }
    }
    return dem;
}
int main(){
    srand(time(NULL));
    int n, n1;
    int ld=0, ldd=0, tam=0;
    cin  >> n >> n1;
    int a[n];
    int b[n1];
    while(ld<n && ldd < n1){
        a[ld]=rand() % 100 +1;
        cout <<"mảng a: " << a[ld] << endl;
        ld++;
        b[ldd]=rand() % 100 +1;    
        cout <<"mảng a1:" <<  b[ldd] << endl;
        ldd++;
    }
    if(n>n1){
        cout << "mảng a lớn hơn mảng b " << endl;
        cout << logic(a,n,b,n1);
    } else if(n<n1) {
        cout << "mảng b lớn hơn mảng a " << endl;
        cout << logic(b,n1,a,n);
    }
}