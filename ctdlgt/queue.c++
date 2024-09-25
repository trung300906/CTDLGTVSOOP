#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    for(int i = 0 ; i < 10; i++) q.push(i);
    q.pop();
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop(); // pop the last element of the queue
    }
    cout << q.empty() << endl;
    cout << "size: " << q.size() << endl;
    cout << "sizeof: " << sizeof(q) << endl;
}