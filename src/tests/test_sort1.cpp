#include <gtest/gtest.h>
#include <vector>        // potrzebne, bo używamy std::vector
#include "Sorter.h"      


TEST(test_sort1, AddFunction)
{
    Sorter* sorter = new Sorter();
	ASSERT_NE(sorter, nullptr);
    
    delete sorter;
    sorter = nullptr;
    
    ASSERT_EQ(sorter, nullptr);
}

// Test 1: Domyślna technika sortuje wektor int rosnąco 
TEST(test_sort1, DefaultTechniqueSortsInt)
{
    // Przygotowujemy nieposortowany wektor intów
    std::vector<int> v{5, 1, 4, 2, 3};
    Sorter sorter;

    sorter.sort(v);

    // Weryfikujemy, że każdy element jest >= poprzedniego
    for (size_t i = 1; i < v.size(); ++i) {
        ASSERT_LE(v[i-1], v[i]) << "Wektor intów nie jest posortowany na pozycji " << i;
    }
}

// Test 2: Domyślna technika sortuje wektor floatów rosnąco 
TEST(test_sort1, DefaultTechniqueSortsFloat)
{
    // Przygotowujemy nieposortowany wektor floatów
    std::vector<float> v{3.14f, 2.71f, 0.0f, -1.0f, 1.23f};
    Sorter sorter;

    sorter.sort(v);

    for (size_t i = 1; i < v.size(); ++i) {
        ASSERT_LE(v[i-1], v[i]) << "Wektor floatów nie jest posortowany na pozycji " << i;
    }
}

//  Test 3: Domyślna technika sortuje wektor double rosnąco 
TEST(test_sort1, DefaultTechniqueSortsDouble)
{
    // Przygotowujemy nieposortowany wektor double
    std::vector<double> v{9.99, 3.33, 7.77, 1.11, 5.55};
    Sorter sorter;

    sorter.sort(v);

    for (size_t i = 1; i < v.size(); ++i) {
        ASSERT_LE(v[i-1], v[i]) << "Wektor double nie jest posortowany na pozycji " << i;
    }
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
