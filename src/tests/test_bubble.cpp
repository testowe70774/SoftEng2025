#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_bubble, AddFunction)
{
    Sorter* sorter = new Sorter();

    // pêtla od pierwszego elementu

#if 0
    SortData<float, std::list> data;
#else
    SortData<float, std::vector> data;
#endif
    std::vector<float> unsorted_data = { 5.3, 2.1, 9.7, 1.4, 5.0, 6.2 };
    for (auto num : unsorted_data) data.add(num);

    auto error = sorter->sort<float, std::vector, STT_BUBBLE>(data);

    ASSERT_EQ(error, SE_SUCCESS);

    bool is_sorted = true;
    for (size_t i = 1; i < data.size(); ++i)
    {
        if (data[i - 1] > data[i])
        {
            is_sorted = false;
            break;
        }
    }

    ASSERT_TRUE(is_sorted) << "Bubble Sort NIE dziala poprawnie!";
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}