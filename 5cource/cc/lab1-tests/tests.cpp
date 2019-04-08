#include "../lab1/DKA.h"
#include "gtest/gtest.h"
using namespace std;
TEST(lab1, fullEqual)
{
    //streambuf* orig_buf = cout.rdbuf();
    cout.rdbuf(nullptr);
    //cout.rdbuf(orig_buf);
    DKA dka("ab");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("ab"));
}

TEST(lab1, invalidSymbol)
{
    cout.rdbuf(nullptr);
    DKA dka("abd");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_FALSE(FA.checkRegex("abc"));
}
TEST(lab1, operationOr)
{
    cout.rdbuf(nullptr);
    DKA dka("a|b");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("a"));
    ASSERT_TRUE(FA.checkRegex("b"));
    ASSERT_TRUE(FA.checkRegex("ab"));
}

TEST(lab1, operationAnd)
{
    cout.rdbuf(nullptr);
    DKA dka("ab");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("ab"));

    DKA dka2("a.b");
    ASSERT_TRUE(dka2.IsValid());
    Automatia FA2 = dka2.buildDka();
    ASSERT_TRUE(FA.checkRegex("ab"));
}

TEST(lab1, operationParentheses)
{
    cout.rdbuf(nullptr);
    DKA dka("(ab)");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("ab"));
}

TEST(lab1, operationStar)
{
    cout.rdbuf(nullptr);
    DKA dka("a*");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("aaaaaaaa"));
    ASSERT_TRUE(FA.checkRegex(""));
}
TEST(lab1, operationPlus)
{
    cout.rdbuf(nullptr);
    DKA dka("a+");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("aaaaaaaa"));
    ASSERT_FALSE(FA.checkRegex(""));
}
//integration
TEST(lab1, integrationStarPlus)
{
    cout.rdbuf(nullptr);
    DKA dka("a*b+");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("aaaaaaaab"));
    ASSERT_TRUE(FA.checkRegex("b"));
    ASSERT_FALSE(FA.checkRegex("aa"));
}
TEST(lab1, integrationStarAnd)
{
    cout.rdbuf(nullptr);
    DKA dka("ab*");
    ASSERT_TRUE(dka.IsValid());
    Automatia FA = dka.buildDka();
    ASSERT_TRUE(FA.checkRegex("aaaaaaaab"));
    ASSERT_TRUE(FA.checkRegex("a"));
    ASSERT_FALSE(FA.checkRegex("b"));
}
