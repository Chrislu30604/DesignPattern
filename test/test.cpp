#include "singleton_test.hpp"
#include <gtest/gtest.h>

TEST(TestSingletonSuite, TestSingletonCat) {
    EXPECT_TRUE(SingletonTestSuite::TestSingletonCat());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
