#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPS(const string &pattern)
{
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // LPS[0] is always 0

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search function
int KMPsearch(const string &text, const string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    int count = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            count++;        // Found a match
            j = lps[j - 1]; // Prepare j for the next potential match
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1]; // Use LPS to skip comparisons
            }
            else
            {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    vector<pair<string, string>> a;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string key, value;
        cin >> key >> value;
        a.push_back({key, value});
    }

    for (const auto &p : a)
    {
        string longer = p.first;
        string shorter = p.second;

        if (shorter.size() > longer.size())
            swap(longer, shorter);

        int count = KMPsearch(longer, shorter);

        if (count == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << count << endl;
        }
    }

    return 0;
}
