#include <bits/stdc++.h>
using namespace std;

// from https://usaco.guide/gold/dsu?lang=cpp
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;
  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int numCases{};
    cin >> numCases;
    
    while (numCases--) {
        int n{};
        vector<int> p;
        cin >> n;
        for (int i{ 0 }; i < n; ++i) {
            int tmp{};
            cin >> tmp;
            p.push_back(tmp - 1);
        }

    
        auto ds{ DisjointSets(p.size()) };

        vector<int> reverseMax(p.size());

        auto currMax{ -1 };
        for (unsigned int i{ 0 }; i < p.size(); ++i) { 
            if (p[p.size() - 1 - i] > currMax)
                currMax = p[p.size() - 1 - i];
            reverseMax[p.size() - 1 - i] = currMax;
        }

        vector<int> forwardMin(p.size());
        auto currMin{ numeric_limits<int>::max() };

        for (unsigned int i{ 0 }; i < p.size(); ++i) { 
            if (p[i] < currMin)
                currMin = p[i];
            forwardMin[i] = currMin;
        }

        for (auto i{ 0 }; i < p.size(); ++i) {
            // for (auto j{ i + 1 }; j < p.size(); ++j) {
            //     if (p[i] < p[j])
            //         ds.unite(p[i], p[j]);
            // }
            // ds.unite(p[i], forwardMin[i]);
            ds.unite(p[i], reverseMax[i]);
            if (i > 0 && forwardMin[i - 1] < reverseMax[i])
                ds.unite(forwardMin[i - 1], reverseMax[i]);
            //
            // if (numCases == 7) {
            //     cout << p[i] << ", " << forwardMin[i] << ", " << reverseMax[i] << "\n";
            // }
        }
        
        bool allSame{ true };
        auto parent{ ds.find(p[0]) };
        for (auto i{ 0u }; i < p.size(); ++i) {
            if (ds.find(p[i]) != parent) {
                allSame = false;
                break;
            }
        }

        cout << (allSame ? "Yes\n" : "No\n" );
    }
}
