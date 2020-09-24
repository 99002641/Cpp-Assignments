#include <iostream>>
#include <gtest/gtest.h>
#include "account.h"

TEST(Account,DefaultConstructor) {
    Account a1;
    EXPECT_EQ(0.0,a1.getBalance());

}
TEST(Account,ParameterizedConstructor) {
    Account a1(2669,"John",10000.0);
    EXPECT_EQ(10000.0,a1.getBalance());
}
TEST(Account,CopyConstructor) {
    Account a1(2669,"John",10000.0);
    Account a2(a1);
    EXPECT_EQ(10000.0,a2.getBalance());
}
TEST(Account,CreditTest) {
    Account a1(2669,"John",10000.0);
    a1.credit(3000);
    EXPECT_EQ(13000.0,a1.getBalance());
}
TEST(Account,DebitTest) {
    Account a1(2669,"John",10000.0);
    a1.debit(2000);
    EXPECT_EQ(8000.0,a1.getBalance());
}
TEST(Account,TransactionTest) {
    Account a1(2669,"John",10000.0);
    a1.debit(1000);
    a1.credit(3000);
    a1.debit(2000);
    a1.credit(3000);
    EXPECT_EQ(13000.0,a1.getBalance()) << "Invalid Balance";
}
TEST(Account,DisplayTest) {
    Account a1(2669,"John",10000.0);
    std::string ExpectedOut="2669,John,10000\n";
    testing::internal::CaptureStdout();
    a1.display();
    std::string ActualOut = testing::internal::GetCapturedStdout();
    EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
}

