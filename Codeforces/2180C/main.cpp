#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t; 
    while (t--) {
        unsigned n, k;
        std::cin >> n >> k;

        if (k == 1) {
            std::cout << n << "\n";
            continue;
        }

        unsigned numShifts{ 0 };
        auto nCopy{ n };
        while (nCopy >>= 1)
            numShifts++;
        unsigned bit = 1U << numShifts;
        if (k % 2 == 0) {
            unsigned numShifts2{ 0 };
            auto what{ n - bit };
            while (what >>= 1)
                numShifts2++;
            unsigned mask{ 0 };
            for (int i = 0; i <= numShifts2; ++i)
                mask |= 1U << i;
            auto other{ (n - bit) ^ mask };
            if (n - bit == 0)
                other = 0;
            std::cout << ((n - bit) | other) << " " << (bit | other) << " ";
            for (int i = 0; i < k - 2; ++i)
                std::cout << n << " ";
            std::cout << "\n";
        } else {
            for (int i = 0; i < k; ++i)
                std::cout << n << " ";
            std::cout << "\n";
        }
    }
}
