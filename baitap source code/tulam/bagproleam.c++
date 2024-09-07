#include <bits/stdc++.h>
using namespace std;
#define DONG 100
#define SOPT 100
int locso(int input[][DONG], int n, int &dem1, int ar[DONG], int maxkg){
    dem1 = 0;
    for (int i = 0; i < n; i++){
        if (input[0][i] <= maxkg){
            ar[dem1] = i;
            dem1++;
        }
    }
    return ar[DONG];
}
int main(){
    srand(time(0));
    int n, maxkg = 100, dem1 = 0, dem2 = 0;
    cout << " nhập số đồ vật muốn đưa vào túi: ";
    n=4;
    int input[DONG][SOPT];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            cin >> input[i][j];
            if (i == 0 && dem1 == 0){
                cout << "sk: "<< "\t";
                dem1++;
            }
            if (i == 1 && dem2 == 0){
                cout << "gt: "<< "\t";
                dem2++;
            }
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }
    int ar[DONG], max = 0, S = 0, Sgt = 0;
    int L[DONG], Llast[DONG], dem3 = 0;
    dem2 = 0;
    cout << "-------------------" << endl;
    locso(input, n, dem1, ar, maxkg);
    for (int i = 0; i < dem1; i++){
        cout << ar[i] << endl;
    }
    cout << "-------------------" << endl;
    for (int k = 0; k < dem1; k++){
        for (int i = k; i < dem1; i++){
            S += input[0][(ar[i])];
            Sgt += input[1][(ar[i])];
            L[dem2] = ar[i];
            dem2++;
            if (S > 50){
                S -= input[0][(ar[i])];
                Sgt -= input[1][(ar[i])];
                dem2--;
                L[dem2] = 0;
            }
            if (i == dem1 - 1){ // xét biên max xem có to nhất chưa
                if (max <= Sgt){
                    max = Sgt;
                    for (int j = 0; j < dem2; j++)
                    {
                        Llast[j] = L[j];
                    }
                    dem3 = dem2;
                }
                S = 0;
                Sgt = 0;
                for (int j = 0; j < dem2; j++){
                    L[j] = 0;
                }
                dem2 = 0;
            }
        }
    }
    for(int i=0 ; i< dem3; i++){
        cout << Llast[i] << " ";
    }
}
#if 0 
    #include <iostream>
    #include <algorithm>
    using namespace std;

    const int N = 100;
    int values[N], weights[N];
    int dp[N+1][N+1];

    int knapsack(int n, int W) {
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (weights[i-1] <= w)
                    dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
                else
                    dp[i][w] = dp[i-1][w];
            }
        }
        return dp[n][W];
    }

    int main() {
        int n, W;
        cin >> n >> W;
        for (int i = 0; i < n; i++)
            cin >> values[i] >> weights[i];
        cout << knapsack(n, W) << endl;
        return 0;
    }
#endif