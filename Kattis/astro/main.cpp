#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;


int timeToInt(const string& s) {
    int res{ 0 };
    res += (s[0] - '0') * 10;
    res += s[1] - '0';
    res *= 60;
    res += (s[3] - '0') * 10;
    res += s[4] - '0';

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int start1{ timeToInt(s1) };
    int start2{ timeToInt(s2) };
    int interval1{ timeToInt(s3) };
    int interval2{ timeToInt(s4) };

    vector<bool> stars(24 * 60 * 24 * 60, false);

    int curr{ start1 };
    while (curr < 24 * 60 * 24 * 60) {
        stars[curr] = true;
        curr += interval1;
    }

    bool same{ false };
    curr = start2;
    while (curr < 24 * 60 * 24 * 60) {
        if (stars[curr] == true) {
            same = true;
            break;
        }
        curr += interval2;
    }

    if (!same) {
        cout << "Never\n";
    } else {
        switch ((curr / (24 * 60) % 7)) {
            case 0:
                cout << "Saturday\n";
                break;
            case 1:
                cout << "Sunday\n";
                break;
            case 2:
                cout << "Monday\n";
                break;
            case 3:
                cout << "Tuesday\n";
                break;
            case 4:
                cout << "Wednesday\n";
                break;
            case 5:
                cout << "Thursday\n";
                break;
            case 6:
                cout << "Friday\n";
                break;
        }
        auto hrs{ (curr % (24 * 60)) / 60 };
        auto mins{ (curr % (24 * 60)) % 60 };
        cout << (hrs < 10 ? "0" : "") << hrs << ":" << (mins < 10 ? "0" : "") << mins << "\n";
    }
}
