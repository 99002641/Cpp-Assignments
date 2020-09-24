#include <iostream>>
#include <gtest/gtest.h>
#include "box.h"

TEST(Account,DefaultConstructor) {
    Box b1;
    EXPECT_EQ(0, b1.length());
    EXPECT_EQ(0, b1.breadth());
    EXPECT_EQ(0, b1.height());
}
TEST(Box,ParameterizedConstructor) {
    Box b1(2,2,2);
    EXPECT_EQ(2, b1.length());
    EXPECT_EQ(2, b1.breadth());
    EXPECT_EQ(2, b1.height());
}
TEST(Box,OneParameterizedConstructor) {
    Box b1(3);
    EXPECT_EQ(3, b1.length());
}
TEST(Box,CopyConstructor) {
    Box b1(4,4,4);
    Box b2(b1);
    EXPECT_EQ(4, b1.length());
    EXPECT_EQ(4, b1.breadth());
    EXPECT_EQ(4, b1.height());
}
TEST(Account,VolumeTest) {
    Box b1(1,2,3);
    EXPECT_EQ(6, b1.volume());
}
TEST(Box,DisplayTest) {
    Box b1(5,10,15);
    std::string ExpectedOut="5,10,15\n";
    testing::internal::CaptureStdout();
    b1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}
