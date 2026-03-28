#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        auto gt{ [](const string_view a, const string_view b) {
            if (a == "lower")
                return false;
            if (a == "middle" && b == "lower")
                return true;
            if (a == "upper" && b != "upper")
                return true;
            return false;
        }};

        auto comp{ [&gt](const pair<vector<string>, string>& a, const pair<vector<string>, string>& b) {
            int indA{ static_cast<int>(a.first.size()) - 1 };
            int indB{ static_cast<int>(b.first.size()) - 1 };

            while (indA >= 0 || indB >= 0) {
                string_view currA{ indA >= 0 ? string_view(a.first[indA]) : "middle" };
                string_view currB{ indB >= 0 ? string_view(b.first[indB]) : "middle" };

                if (gt(currA, currB))
                    return true;
                if (gt(currB, currA))
                    return false;

                indA--;
                indB--;
            }

            return a.second < b.second;
        }};


        vector<pair<vector<string>, string>> v;
        for (int i = 0; i < n; ++i) {
            string name;
            cin >> name;
            name.pop_back();

            string tmp;
            cin >> tmp;

            vector<string> cl;

            auto iter{ tmp.begin() };
            while (true) {
                auto next{ find(iter, tmp.end(), '-') };
                cl.push_back(string(iter, next));
                if (next == tmp.end())
                    break;
                next++;
                iter = next;
            }
        
            v.push_back({ cl, name });
            
            cin >> tmp;
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << v[i].second << endl;
        //     for (int j = 0; j < v[i].first.size(); ++j) {
        //         cout << v[i].first[j] << " ";
        //     }
        //     cout << endl;
        // }
        //
        //
        // cout << endl << endl;
        //
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < n; ++i) {
            cout << v[i].second << "\n";
        }

        cout << "==============================\n";
    }
}
