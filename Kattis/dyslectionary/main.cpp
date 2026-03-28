#include <bits/stdc++.h>
#include <ranges>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true) {
        size_t maxSize{ 0 };
        string l;
        vector<string> v;
        bool end{ false };
        while (true) {
            auto& done{ getline(cin, l) };
            if (!done) {
                end = true;
                break;
            }
            if (l.empty())
                break;
            v.push_back(l);
            maxSize = max(maxSize, l.size());
        }

        auto comp{ [](const string& a, const string& b) {
            return lexicographical_compare(a.rbegin(), a.rend(), b.rbegin(), b.rend());
        }};

        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < v.size(); ++i) {
            cout << setfill(' ') << setw(maxSize) << v[i] << "\n";
        }
        if (end)
            break;
        cout << "\n";
    }

}
