#include "Quantlab/Foo.hpp"

#include "gtest/gtest.h"

class FooTest : public ::testing::Test {};

TEST(FooTest, ReturnsFoo)
{
    EXPECT_EQ(Foo(), "Foo");
}