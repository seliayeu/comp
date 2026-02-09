#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;


int find(vector<int>& s, int a) {
    if (s[a] < 0)
        return a;
    auto root{ find(s, s[a]) };
    s[a] = root;
    return root;
}

void join(vector<int>& s, int a, int b) {
    auto aRoot{ find(s, a) }, bRoot{ find(s, b) };
    if (aRoot == bRoot)
        return;

    if (s[aRoot] < s[bRoot]) { // a has more elements
        s[aRoot] += s[bRoot];
        s[bRoot] = aRoot;
    } else {
        s[bRoot] += s[aRoot];
        s[aRoot] = bRoot;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> s(N);
    for (int i = 0; i < N; ++i)
        s[i] = -1;
    while (Q--) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;

        if (op == '?') {
            auto aRoot{ find(s, a) }, bRoot{ find(s, b) };
            if (aRoot == bRoot)
                cout << "yes\n";
            else
                cout << "no\n";
        } else {
            join(s, a, b);
        }
    }
}
