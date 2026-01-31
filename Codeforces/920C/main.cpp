#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::string s;
    std::cin >> s;

    bool possible{ true };
    
    for (size_t l{ 0 }; l < n - 1; ++l) {
        size_t r{ l };
        while (s[r] == '1')
            ++r;

        if (r == l) {
            if (a[l] != l + 1) {
                possible = false;
                break;
            } else
                continue;
        }

        auto lIter{ a.begin() }, rIter{ a.begin() };
        std::advance(lIter, l);
        std::advance(rIter, std::min(n, r + 1));

        std::sort(lIter, rIter);

        for (size_t i{ l }; i < r; ++i)
            s[i] = '0';
    }

    std::cout << (possible ? "YES\n" : "NO\n");
}
