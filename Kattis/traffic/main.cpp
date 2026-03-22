#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll x1, x2;
    cin >> x1 >> x2;

    vector<ll> car1(3000001);
    vector<ll> car2(3000001);

    ll n1;
    cin >> n1;
    vector<ll> t1(n1);
    for (ll i = 0; i < n1; ++i)
        cin >> t1[i];
    ll n2;
    cin >> n2;
    vector<ll> t2(n2);
    for (ll i = 0; i < n2; ++i)
        cin >> t2[i];

    ll ind1{ 0 };
    bool moving{ false };
    car1[0] = x1;
    for (ll i = 1; i <= 3000000; ++i) {
        car1[i] = moving ? car1[i - 1] + 1 : car1[i - 1];
        if (ind1 < n1 && i == t1[ind1]) {
            moving = !moving;
            ind1++;
        }
    }

    ll ind2{ 0 };
    moving = false;
    car2[0] = x2;
    bool b{ false };
    for (ll i = 1; i <= 3000000; ++i) {
        car2[i] = moving ? car2[i - 1] + 1 : car2[i - 1];

        if (abs(car1[i] - car2[i]) < 5) {
            cout << "bumper tap at time " << i << "\n";
            b = true;
            break;
        }
        if (ind2 < n2 && i == t2[ind2]) {
            moving = !moving;
            ind2++;
        }
    }

    if (!b) {
        cout << "safe and sound\n";
    }
}
