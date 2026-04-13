#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

struct Dist {
    ll dist;
    int jInd;
    int tfInd;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin >> n >> m >> p;

    vector<pair<ll, ll>> judges(n);
    vector<pair<ll, ll>> tarRepos(m);
    vector<pair<ll, ll>> feathers(p);
 
    vector<bool> jDone(n, false);
    vector<bool> tDone(m, false);
    vector<bool> fDone(p, false);
    vector<double> finalDists;
    finalDists.reserve(n * 2);

    vector<Dist> tDists, fDists;
    tDists.reserve(n * m);
    fDists.reserve(n * p);

    for (int i = 0; i < n; ++i)
        cin >> judges[i].first >> judges[i].second;
    for (int i = 0; i < m; ++i)
        cin >> tarRepos[i].first >> tarRepos[i].second;
    for (int i = 0; i < p; ++i)
        cin >> feathers[i].first >> feathers[i].second;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tDists.push_back({ (judges[i].first - tarRepos[j].first) * (judges[i].first - tarRepos[j].first) + (judges[i].second - tarRepos[j].second) * (judges[i].second - tarRepos[j].second), i, j });
        }
    }

    sort(tDists.begin(), tDists.end(), [](auto a, auto b){ 
        if (a.dist == b.dist) {
            if (a.jInd == b.jInd)
                return a.tfInd < b.tfInd;
            return a.jInd < b.jInd;
        }
        return a.dist < b.dist;
    });

    for (int i = 0; i < tDists.size(); ++i) {
        if (jDone[tDists[i].jInd] || tDone[tDists[i].tfInd])
            continue;
        finalDists.push_back(sqrt(tDists[i].dist));
        tDone[tDists[i].tfInd] = true;
        jDone[tDists[i].jInd] = true;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            fDists.push_back({ (judges[i].first - feathers[j].first) * (judges[i].first - feathers[j].first) + (judges[i].second - feathers[j].second) * (judges[i].second - feathers[j].second), i, j });
        }
    }

    sort(fDists.begin(), fDists.end(), [](auto a, auto b){ 
        if (a.dist == b.dist) {
            if (a.jInd == b.jInd)
                return a.tfInd < b.tfInd;
            return a.jInd < b.jInd;
        }
        return a.dist < b.dist;
    });

    jDone = vector<bool>(n, false);
    for (int i = 0; i < fDists.size(); ++i) {
        if (jDone[fDists[i].jInd] || fDone[fDists[i].tfInd])
            continue;
        finalDists.push_back(sqrt(fDists[i].dist));
        fDone[fDists[i].tfInd] = true;
        jDone[fDists[i].jInd] = true;
    }

    double res{ accumulate(finalDists.begin(), finalDists.end(), 0.0) };
    cout << fixed << setprecision(8) <<  res << endl;
}
