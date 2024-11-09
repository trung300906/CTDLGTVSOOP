#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

bool check(vector<pair<vector<int>, bool>> store, int hang)
{
    auto it = find(store[hang].first.begin(), store[hang].first.end(), 1);
    if (it != store[hang].first.end())
        return true;
    return false;
}
auto tim(vector<pair<vector<int>, bool>> store, vector<int> &loc, int hang)
{
    for (int run = 0; run < store.size(); run++)
        if (store[hang].first[run] == 1)
            loc.push_back(run);
    return loc;
}
auto tim_loc_2(vector<pair<vector<int>, bool>> store, vector<int> &loc, int hang, int &loccur, int &dem)
{
    if (store[hang].second == false)
    {
        for (int i = loccur; i < store[hang].first.size(); i++)
            if (store[hang].first[i] == 1)
                loc.push_back(i);
        if (!loc.empty())
        {
            dem += loc.back() - loccur;
            loccur = loc.back();
        }
        return loccur;
    }
    if (store[hang].second == true)
    {
        for (int i = loccur; i >= 0; i--)
            if (store[hang].first[i] == 1)
                loc.push_back(i);
        if (!loc.empty())
        {
            dem += loccur - loc.back();
            loccur = loc.back();
        }
        return loccur;
    }
    return loccur;
}
// r&1 == true => số lẽ
auto find_bool(pair<vector<int>, bool> &newpair, int R, int i)
{
    if ((R - 1) & 1)
    {
        if ((i & 1) == false)
            newpair.second = false;
        else
            newpair.second = true;
    }
    else
    {
        if ((i & 1) == true)
            newpair.second = false;
        else
            newpair.second = true;
    }
    return newpair;
}
int main()
{
    srand(time(0));
    int R, S, val;
    cin >> R >> S;
    vector<pair<vector<int>, bool>> store;
    for (int i = R - 1; i >= 0; i--)
    {
        pair<vector<int>, bool> newpair;
        find_bool(newpair, R, i);
        for (int j = 0; j < S; j++)
            if (i == R - 1 && j == 0)
                newpair.first.push_back(2);
            else
                newpair.first.push_back(rand() % 2);
        store.push_back(newpair);
        newpair.first.clear();
    }
    vector<int> loc;
    int dem = 0, loccur = 0;
    for (int i = 0; i < ceil(R / 2); i++)
        swap(store[i], store[R - i - 1]);
    for (int hang = store.size() - 1; hang >= 0; hang--)
    {
        loc.clear();
        if (check(store, hang) == false)
        {
            if (hang > 0)
            {
                dem++;
                store[hang - 1].first[loccur] = 0;
                continue;
            }
            if (hang == 0)
                break;
        }
        tim(store, loc, hang);
        for (auto &i : loc)
            store[hang].first[i] = 0;
        if (store[hang].second == true)
        {
            dem += (loc.back() - loccur) + 1;
            loccur = loc.back();
            loc.clear();
            if (hang > 0)
            {
                tim_loc_2(store, loc, hang - 1, loccur, dem);
                store[hang - 1].first[loccur] = 0;
                loc.clear();
                continue;
            }
            if (hang == 0)
                break;
        }
        if (store[hang].second == false)
        {
            dem += loccur - loc.front() + 1;
            loccur = loc.front();
            loc.clear();
            if (hang > 0)
            {
                tim_loc_2(store, loc, hang - 1, loccur, dem);
                store[hang - 1].first[loccur] = 0;
                loc.clear();
                continue;
            }
            if (hang == 0)
                break;
        }
    }
    cout << dem;
}

#if 0 // dùng struct
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

struct Row {
    int* values;
    bool isOdd;

    Row(int cols, bool isOdd) : isOdd(isOdd) {
        values = new int[cols];
        fill(values, values + cols, 0);
    }

    ~Row() {
        delete[] values;
    }
};

bool check(const vector<Row>& store, int hang) {
    return any_of(store[hang].values, store[hang].values + S, [](int val) { return val == 1; });
}

void tim(const vector<Row>& store, vector<int>& loc, int hang) {
    for (int run = 0; run < store.size(); run++)
        if (store[hang].values[run] == 1)
            loc.push_back(run);
}

int tim_loc_2(const vector<Row>& store, vector<int>& loc, int hang, int& loccur, int& dem) {
    if (!store[hang].isOdd) {
        for (int i = loccur; i < S; i++) {
            if (store[hang].values[i] == 1)
                loc.push_back(i);
        }
    } else {
        for (int i = loccur; i >= 0; i--) {
            if (store[hang].values[i] == 1)
                loc.push_back(i);
        }
    }

    if (!loc.empty()) {
        dem += abs(loccur - loc.back()) + 1;
        loccur = loc.back();
    }

    return loccur;
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(0, 1);

    int R, S, val;
    cin >> R >> S;
    vector<Row> store;

    for (int i = 0; i < R; i++) {
        bool isOdd = ((R - 1) & 1) ? (i & 1) : !(i & 1);
        store.emplace_back(S, isOdd);

        for (int j = 0; j < S; j++) {
            if (i == 0 && j == 0)
                store[i].values[j] = 2;
            else
                store[i].values[j] = distrib(gen);
        }
    }

    vector<int> loc;
    int dem = 0, loccur = 0;

    for (int hang = R - 1; hang >= 0; hang--) {
        loc.clear();

        if (!check(store, hang)) {
            if (hang > 0) {
                dem++;
                store[hang - 1].values[loccur] = 0;
            }
            continue;
        }

        tim(store, loc, hang);

        for (auto &i : loc) {
            store[hang].values[i] = 0;
        }

        if (store[hang].isOdd) {
            dem += abs(loccur - loc.back()) + 1;
            loccur = loc.back();
            loc.clear();

            if (hang > 0) {
                loccur = tim_loc_2(store, loc, hang - 1, loccur, dem);
                store[hang - 1].values[loccur] = 0;
                loc.clear();
            }
        } else {
            dem += abs(loccur - loc.front()) + 1;
            loccur = loc.front();
            loc.clear();

            if (hang > 0) {
                loccur = tim_loc_2(store, loc, hang - 1, loccur, dem);
                store[hang - 1].values[loccur] = 0;
                loc.clear();
            }
        }
    }

    cout << dem;
}

#endif