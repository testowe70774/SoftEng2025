
#include <gtest/gtest.h>
#include "Sorter.h"

TEST(test_sort1, AddFunction)
{
    Sorter* sorter = new Sorter();

    ASSERT_NE(sorter, nullptr);

    delete sorter;
    sorter = nullptr;

    ASSERT_EQ(sorter, nullptr);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}