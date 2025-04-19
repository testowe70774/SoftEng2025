
#include "Radix.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue> 

std::vector<int> radixSort(std::vector<int> L, int baza) {

    int maxVal = L[0];

    if (L.empty()) {
        std::cout << "pusta tablica\n";
    }
    else {
        for (int value : L) { // Iteracja przez wszystkie elementy
            if (value > maxVal) {
                maxVal = value;
            }
        }
    }
    std::cout << maxVal << "= maxVal\n";
    int k = 1;
    while (maxVal >= baza) {
        ++k;
        maxVal /= baza;
    }
    std::cout << k << " = K\n";
    for (int i = 0; i < k; ++i) {
        std::vector<std::queue<int>> buckets(baza);

        for (int num : L) {
            int digit = (num / static_cast<int>(std::pow(baza, i))) % baza;
            buckets[digit].push(num);
        }

        int index = 0;
        for (int j = 0; j < baza; ++j) {
            while (!buckets[j].empty()) {
                L[index++] = buckets[j].front();
                buckets[j].pop();
            }
        }

    }
    return L;
}

int main()
{
    std::vector<int> L1{ 1, 233, 3, 87, 44, 255, 111, 11, 32 };
    std::vector<int> L2{ 1, 233, 3, 87, 44, 255, 111, 11, 32 };
    L1 = radixSort(L1, 10);
    L2 = radixSort(L2, 16);
    for (int num : L1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for (int num : L2) {
        std::cout << num << " ";
    }
}
