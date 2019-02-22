#include <iostream>
#include <gtest/gtest.h>
#include "fun.cpp"

using namespace std;

TEST(FirstTest, TestingFoo)
{
    EXPECT_EQ(4, foo(2));
    EXPECT_EQ(5, foo(2));
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
