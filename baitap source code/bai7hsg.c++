#if 0
#include <iostream>
using namespace std;

int main(){   
    
    int a[] = {1,-1,1,-1,1,-1,1,-1};
    int n = sizeof(a)/sizeof(int);
    int count = 0 ;
    for(int i=0 ; i < n; i++){
        if(a[i] == 0) count++;
        for(int j = i+1; j < n; j++){
            if( (a[i]+ a[j]) == 0){
                count++;
            }
        }
    }
    cout << count << endl;
}
#endif
// cách 2 dùng prefix sum(tức mảng tiền tố á)
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], s[N], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    map<int, int> cnt;
    for (int i = 0; i <= n; ++i) {
        ans += cnt[s[i]];
        ++cnt[s[i]];
    }
    cout << ans << endl;
    return 0;
}
