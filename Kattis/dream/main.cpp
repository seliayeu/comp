#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> stack;
    unordered_map<string, int> s;
    string line;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        if (line[0] == 'E') {
            int ind{ stack.empty() ? 0 : s[stack.back()] + 1 };
            stack.push_back(line.substr(2));
            s[stack.back()] = ind;
            continue;
        }
        stringstream ss(line);
        string tmp;
        ss >> tmp;
        int num;
        ss >> num;
        if (line[0] == 'D') {
            for (int j = 0; j < num; ++j) {
                s.erase(stack.back());
                stack.pop_back();
            }
            continue;
        }

        int maxH{ -1 }, minDh{ numeric_limits<int>::max() };
        for (int j = 0; j < num; ++j) {
            string curr;
            ss >> curr;

            if (curr[0] == '!') {
                if (s.contains(curr.substr(1)))
                    minDh = min(minDh, s[curr.substr(1)]);
            } else {
                if (!s.contains(curr)) {
                    maxH = -7;
                    break;
                }
                maxH = max(maxH, s[curr]);
            }
        }

        int changes{ 0 };

        if (maxH == -7 || minDh <= maxH)
            changes = -1;
        else if (minDh != numeric_limits<int>::max()) {
            changes = stack.size() - minDh;
        }

        if (changes == 0)
            cout << "Yes\n";
        else if (changes == -1)
            cout << "Plot Error\n";
        else {
            cout << changes << " Just A Dream\n";
        }
    }
}
