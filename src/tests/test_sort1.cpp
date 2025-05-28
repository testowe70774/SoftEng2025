#include <gtest/gtest.h>
#include <vector> // potrzebne, bo używamy std::vector
#include "Sorter.h"
#include "SortData.h" // potrzebne, bo sorter.sort(...) przyjmuje SortData<...>&

TEST(test_sort1, AddFunction)
{
    Sorter* sorter = new Sorter();
    ASSERT_NE(sorter, nullptr) << "Na stercie powinien powstać obiekt Sorter";

    delete sorter;
    sorter = nullptr;
    ASSERT_EQ(sorter, nullptr) << "Po usunięciu wskaźnik powinien być nullptr";
}

// --- Test 1: domyślna technika sortowania dla intów ---
TEST(test_sort1, DefaultTechniqueSortsInt)
{
    // 1) przygotowujemy nieposortowany kontener intów
    std::vector<int> v{ 5, 1, 4, 2, 3 };

    SortData<int, std::vector> data(v);
    Sorter sorter;

    // 2) wywołujemy sortowanie
    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS) << "sort() powinien zwrócić SE_SUCCESS";

    // 3) sprawdzamy, czy wynik jest posortowany
    const auto& sorted = data.getData();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        ASSERT_LE(sorted[i - 1], sorted[i])
            << "Wektor intów nie jest posortowany na pozycji " << i;
    }
}

// --- Test 2: domyślna technika sortowania dla floatów ---
TEST(test_sort1, DefaultTechniqueSortsFloat)
{
    std::vector<float> v{ 3.14f, 2.71f, 0.0f, -1.0f, 1.23f };
    SortData<float, std::vector> data(v);
    Sorter sorter;

    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS) << "sort() powinien zwrócić SE_SUCCESS";

    const auto& sorted = data.getData();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        ASSERT_LE(sorted[i - 1], sorted[i])
            << "Wektor floatów nie jest posortowany na pozycji " << i;
    }
}

// --- Test 3: domyślna technika sortowania dla double ---
TEST(test_sort1, DefaultTechniqueSortsDouble)
{
    std::vector<double> v{ 9.99, 3.33, 7.77, 1.11, 5.55 };
    SortData<double, std::vector> data(v);
    Sorter sorter;

    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS) << "sort() powinien zwrócić SE_SUCCESS";

    const auto& sorted = data.getData();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        ASSERT_LE(sorted[i - 1], sorted[i])
            << "Wektor double nie jest posortowany na pozycji " << i;
    }
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
