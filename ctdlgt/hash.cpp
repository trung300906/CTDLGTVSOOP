#include <bits/stdc++.h>
using namespace std;
#if 0
typedef long long ll;

const int MOD = 1e9 + 7, BASE = 256, MaxN = 1 + 1e5;

ll hashS1[MaxN], power[MaxN];

ll getHash(int i, int j)
{
    return (hashS1[j] - hashS1[i - 1] * power[j - i + 1] + 1ll * MOD * MOD) % MOD;
}

int main()
{
    string s1 = "ababbab", s2 = "bab";
    int n = s1.length(), m = s2.length();
    vector<ll> powerdb;
    vector<ll> hashS1db;
    // Việc này biến chỉ số xâu từ [0, n - 1] và [0, m - 1] thành [1, n] và [1, m]
    s1 = " " + s1;
    s2 = " " + s2;
    ll hashS2 = 0;
    for (int i = 1; i <= m; ++i)
        hashS2 = (hashS2 * BASE + (s2[i] - 'a' + 1)) % MOD;
    // power[i] là BASE^i
    power[0] = 1;
    powerdb.push_back(power[0]);
    for (int i = 1; i <= n; ++i)
    {
        power[i] = (power[i - 1] * BASE) % MOD;
        powerdb.push_back(power[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        hashS1[i] = (hashS1[i - 1] * BASE + (s1[i] - 'a' + 1)) % MOD;
        hashS1db.push_back(hashS1[i]);
    }
    for (int i = 1; i <= n - m + 1; ++i)
        if (getHash(i, i + m - 1) == hashS2)
            cout << i << " ";
    return 0;
}
#endif
struct Vectorhash
{
    size_t operator()(const vector<int> &v) const
    {
        size_t hashvalue = 0;
        hash<int> hash_int;
        int memoryfact;
        int *itr_memoryfact = &memoryfact;
        for (auto &i : v)
        {
            hashvalue ^= hash_int(i) + 0x9e786780a9 + (hashvalue << 9) + (hashvalue >> 0);
        }
        return hashvalue;
    }
};
// method 2 using hash function
int main()
{
    string s = "geeksforgeeks";
    hash<string> hashinh;
    cout << hashinh(s) << endl;
    // hash for vector
    vector<int> vec = {1, 2, 100, 4, 54};
    Vectorhash hashing;
    cout << hashing(vec) << endl;
}
