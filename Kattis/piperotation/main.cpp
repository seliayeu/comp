#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> M >> N;

    vector<bool> curr(N, false), prev(N);
    vector<char> stack;
    stack.reserve(N);
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'A')
            continue;
        if (s[i] == 'D') {
            cout << "Impossible\n";
            return 0;
        }

        if (s[i] == 'B' && stack.size() == 0 ) {
            cout << "Impossible\n";
            return 0;
        }

        if (s[i] == 'C' && stack.size() == 0) {
            stack.push_back('C');
            curr[i] = true;
            continue;
        }

        if (s[i] == 'B' && stack.size() >= 1) {
            stack.push_back('B');
            continue;
        }

        if (s[i] == 'C' && stack.size() >= 1) {
            stack.clear();
            curr[i] = true;
            continue;
        }

        cout << "Impossible\n";
        return 0;
    }

    if (stack.size() > 0) {
        cout << "Impossible\n";
        return 0;
    }

    swap(curr, prev);
    for (int i = 1; i < M; ++i) {
        curr = vector<bool>(N, false);
        stack.resize(0);
        cin >> s;
        for (int i = 0; i < N; ++i) {
            auto c{ s[i] };
            if (c == 'D') {
                if (i == 0 || i == N - 1 || !prev[i] || stack.size() == 0) {
                    cout << "Impossible\n";
                    return 0;
                }
                stack.push_back('D');
                curr[i] = true;
            }

            if (c == 'B') {
                if (prev[i] == true) {
                    if (stack.size() != 0) {
                        cout << "Impossible\n";
                        return 0;
                    }
                    curr[i] = true;
                } else {
                    if (stack.size() == 0) {
                        cout << "Impossible\n";
                        return 0;
                    }
                    stack.push_back('B');
                }
            }

            if (c == 'C') {
                if (stack.size() == 0) {
                    stack.push_back('C');
                } else {
                    stack.clear();
                }
                curr[i] = !prev[i];
            }
        }
        if (stack.size() > 0) {
            cout << "Impossible\n";
            return 0;
        }
        swap(curr, prev);
    }

    if (count(prev.begin(), prev.end(), false) != prev.size()) {
        cout << "Impossible\n";
    } else 
        cout << "Possible\n";
}
