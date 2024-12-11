#include<bits/stdc++.h>
using namespace std;
 
const int MaxN = 1 + 1e6;
 
int n, a[MaxN];
stack<int> st;
 
int main(){
    freopen("CTDL.inp","r",stdin);
    freopen("CTDL.out","w",stdout);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i){
        /* // Các bạn chú ý phương thức kiểm tra empty() luôn phải được đặt 
        trước khi gọi top() hoặc pop() */
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(!st.empty()) cout << st.top() + 1 << " ";
        else cout << "-1" << " ";
        st.push(i);
    }
    return 0;
}
