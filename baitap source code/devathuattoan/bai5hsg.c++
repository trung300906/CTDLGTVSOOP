// bài 5 hoặc bài 1 an giang
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
using namespace std;
string erasing(string &S1, string &S2){
    S1.erase(remove_if(S1.begin(), S1.end(), [](char c){return !isdigit(c);}), S1.end());
    S2.erase(remove_if(S2.begin(), S2.end(), [](char c){return !isdigit(c);}), S2.end());
    return S1, S2;
}
int convert_string_int(string S1, string S2, int l1[], int l2[]){
    for(int i=0; i<S1.length(); i++){
        l1[i] = S1[i] - '0';
    }
    for(int j=0; j<S2.length(); j++){
        l2[j] = S2[j] - '0';
    }
    return l1[S1.length()], l2[S2.length()];
}
void ngandainhat(int arr[], int n, int result[]) {
    int dp[n];
    int prev[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    int index = maxIndex;
    int count = 0;
    while (index != -1) {
        result[count++] = arr[index];
        index = prev[index];
    }
}
int main(){
    string S1, S2;
    cout << "sâu S1: ";
    getline(cin,S1); cout << endl;
    int l1[S1.length()];
    int a1[S1.length()];
    cout << "Sâu S2: ";
    getline(cin,S2); cout << endl;
    int l2[S2.length()];
    int a2[S2.length()];
    erasing(S1,S2);
    cout << "sâu s1 sau khi xử lý " << S1 << endl;
    cout << "sâu s2 sau khi xử lý " << S2 << endl; 
    convert_string_int(S1,S2,l1,l2);
    ngandainhat(l1,S1.length(), a1);
    reverse(a1, a1 + S1.length()); // đảo mảng do bị ngược
    ngandainhat(l2,S2.length(), a2);
    reverse(a2, a2 + S2.length());
    int result1 = 0;
    int result2 = 0;
    for(int &num : a1){
        result1 = result1*10 + num;
    }
    for(int &num1 : a2){
        result2 = result2*10 + num1;
    }
    cout <<"tích là: " << result1 * result2 << endl;
}
#if 0
string erasing(string &S1, string &S2){
    for(int i=S1.length()-1; i>=0; i--){
        int convert = static_cast<int>(S1[i]);
        if((convert < 48) || (convert > 57)){
            S1.erase(S1.begin() + i);
        }
    }
    for(int i=S2.length()-1; i>=0; i--){
        int convert = static_cast<int>(S2[i]);
        if((convert < 48) || (convert > 57)){
            S2.erase(S2.begin() + i);
        }
    }
    return S1, S2;
}
#endif
/* các thứ cần đọc:
stoi: dùng để chuyển từ string -> int
to_string: dùng để chuyển từ int -> string
*/