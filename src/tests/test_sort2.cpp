
#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_sort2, AddFunction)
{
    Sorter* sorter = new Sorter();

    SortData<float, std::vector> data;


    data.add(1.f);
    data.add(5.f);
    data.add(3.f);


    auto error = sorter->sort(data);

    ASSERT_NE(error, SE_SUCCESS);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}