
#include <gtest/gtest.h>
#include "Sorter.h"
#include "SortData.h"

TEST(test_bubble, AddFunction)
{
    Sorter* sorter = new Sorter();

#if 0
    SortData<float, std::list> data;
#else
    SortData<float, std::vector> data;
#endif
    int dsize = 128 + rand() % 100;
    for (unsigned i = 0; i < dsize; i++)
      data.add(float(rand() % 1024) / 4096);

    auto error = sorter->sort<float, std::vector, STT_BUBBLE>(data);

    ASSERT_EQ(error, SE_SUCCESS);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}