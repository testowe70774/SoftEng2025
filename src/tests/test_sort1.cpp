#include <gtest/gtest.h>
#include <vector> // std::vector
#include <algorithm> // std::is_sorted
#include "Sorter.h" // Sorter, SortError
#include "SortData.h" // SortData<>

//
// 1) Sprawdzenie, że można skonstruować i zniszczyć Sorter
//
TEST(test_sort1, AddFunction)
{
    Sorter* sorter = new Sorter();
    ASSERT_NE(sorter, nullptr);

    delete sorter;
    sorter = nullptr;

    ASSERT_EQ(sorter, nullptr);
}

//
// 2) Domyślna technika sortuje int-y
//
TEST(test_sort1, DefaultTechniqueSortsInt)
{
    std::vector<int> input{ 5, 3, 1, 4, 2 };

    SortData<int, std::vector> data;
    data.add(input.data(), static_cast<unsigned int>(input.size()));

    Sorter sorter;
    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS);

    const auto& result = data.data();
    ASSERT_TRUE(std::is_sorted(result.begin(), result.end()))
        << "Int vector nie jest posortowany!";
}

//
// 3) Domyślna technika sortuje float-y
//
TEST(test_sort1, DefaultTechniqueSortsFloat)
{
    std::vector<float> input{ 3.14f, -1.0f, 0.0f, 2.71f, 1.23f };

    SortData<float, std::vector> data;
    data.add(input.data(), static_cast<unsigned int>(input.size()));

    Sorter sorter;
    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS);

    const auto& result = data.data();
    ASSERT_TRUE(std::is_sorted(result.begin(), result.end()))
        << "Float vector nie jest posortowany!";
}

//
// 4) Domyślna technika sortuje double
//
TEST(test_sort1, DefaultTechniqueSortsDouble)
{
    std::vector<double> input{ 9.99, 3.33, 7.77, 1.11, 5.55 };

    SortData<double, std::vector> data;
    data.add(input.data(), static_cast<unsigned int>(input.size()));

    Sorter sorter;
    SortError err = sorter.sort(data);
    ASSERT_EQ(err, SE_SUCCESS);

    const auto& result = data.data();
    ASSERT_TRUE(std::is_sorted(result.begin(), result.end()))
        << "Double vector nie jest posortowany!";
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
