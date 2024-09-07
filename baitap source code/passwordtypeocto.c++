#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
	cin >> n >> s;
	int z = n * 9;
	if (z < s){
		cout << -1;
	}
	else if (s <= 9){
		cout << s;
		for (int i = 2; i<= n;i++){
			cout << 0;
		}
	}
	else {
		for (int i = 1; i<= n;i++){
			if (s >= 10){
				cout << 9;
				s-= 9;
			}
		    else if (s < 10 && s != 0){
		        cout << s;
		        s = 0;
		    }
		    else{
		        cout << 0;
		    }
		}
	}
}