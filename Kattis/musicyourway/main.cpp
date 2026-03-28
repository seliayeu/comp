#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string l;
    getline(cin, l);
    stringstream ss(l);

    string s;
    vector<string> cat;
    while (ss >> s) {
        cat.push_back(s);
    }

    int n;
    cin >> n;

    vector<pair<vector<string>, int>> es(n);

    for (int i = 0; i < n; ++i) {
        pair<vector<string>, int> e{ vector<string>(cat.size()), i };
        for (int j = 0; j < cat.size(); ++j)
            cin >> e.first[j];
        es[i] = std::move(e);
    }

    int q;
    cin >> q;
    
    size_t ind;
    auto comp{ [&ind](const pair<vector<string>, int>& a, const pair<vector<string>, int>& b) {
        if (a.first[ind] < b.first[ind])
            return true;
        if (b.first[ind] < a.first[ind])
            return false;
        return a.second < b.second;
    }};
    
    for (int i = 0; i < q; ++i) {
         cout << l << "\n";
        cin >> s;
        auto iter{ find(cat.begin(), cat.end(), s) };
        ind = distance(cat.begin(), iter);

        sort(es.begin(), es.end(), comp);
        for (int j = 0; j < n; ++j)
            es[j].second = j;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < cat.size(); ++k) {
                cout << es[j].first[k] << " ";
            }
            cout  << "\n";
        }
        cout  << "\n";

    }
}
