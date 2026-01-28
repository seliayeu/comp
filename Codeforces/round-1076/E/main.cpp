#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        a.reserve(n);
        unordered_map<int, int> contains;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (contains.find(tmp) != contains.end())
                continue;
            a.push_back(tmp);
            contains[tmp] = 1;
        }

        sort(a.begin(), a.end());

        for (int i = 1; i <= n; ++i) {
            if (contains.find(i) != contains.end()) {
                cout << contains[i] << " ";
                continue;
            }

            bool found{ false };
            int res{ numeric_limits<int>::max() };
            
            auto iter{ upper_bound(a.begin(), a.end(), i) };
            if (iter == a.begin()) {
                cout << "-1 ";
                continue;
            }

            int ind = distance(a.begin(), iter);
            ind--;

            // cout <<"found " << i << "at IND " << ind << endl;

            for (int j = ind; j >= 0 ; --j) {
                if (a[j] > i) {
                    break;
                } 
                if (i % a[j] == 0) {
                    if (contains.find(i / a[j]) != contains.end()) {
                        contains[i] = contains[i / a[j]] + contains[a[j]];
                        res = min(res, contains[i]);
                        found = true;
                        break;
                    } 
                }
            }
            if (!found)
                cout << "-1 ";
            else 
                cout << res << " ";
        }
        cout << "\n";
    }
}
