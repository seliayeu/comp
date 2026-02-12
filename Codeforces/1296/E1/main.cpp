#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;

    std::string sorted{ s };
    std::sort(sorted.begin(), sorted.end());
    
    std::vector<int> res(n, -1);

    for (size_t i{ 0 }; i < n; ++i) {
        if (s[i] == sorted[i])
            continue;
        auto iter{ std::find(sorted.begin(), sorted.end(), s[i]) };
        
        if (std::distance(sorted.begin(), iter) - static_cast<int>(i) > 0) {
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }

    std::vector<int> colors(res);

    for (size_t i{ 0 }; i < n; ++i) {
        if (s[i] == sorted[i])
            continue;
        auto iter{ std::find(s.begin() + i, s.end(), sorted[i]) };
        auto foundInd{ std::distance(s.begin(), iter) };

        for (long j{ foundInd }; j > i; --j) {
            if (colors[j] == colors[j - 1]) {
                std::cout << "NO\n";
                return 0;
            }
            if (colors[j] == -1) {
                colors[j] = !colors[j - 1];
                res[j] = !colors[j - 1];
            } else if (colors[j - 1] == -1) {
                colors[j - 1] = !colors[j];
                res[j - 1] = !colors[j];
            }

            std::swap(colors[j], colors[j - 1]);
            std::swap(s[j], s[j - 1]);
        }
    }

    std::cout << "YES\n";

    for (size_t i{ 0 }; i < n; ++i) {
        if (res[i] == -1)
            res[i] = 0;
        std::cout << res[i];
    }
    std::cout << "\n";
}

// c b a
//
//
//
// c b a
// c c c c z z z z z z z z z 
// z z z z z c z z z z c c c
// 0 0 0 0 0 1 0 0 0 0 1 1 1
// 
//
//
