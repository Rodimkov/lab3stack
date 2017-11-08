#include "..\lab-3\TCalculator.h"

#include "gtest.h"

TEST(Tstack, can_count1)
{
  TCalculator test;
  test.setinfix("2+)*2^(3+3)*8");
  EXPECT_EQ(8,test.calk());
}
/*
TEST(Tstack, can_count2)
{
  TCalculator test;
  test.setinfix("2+2*2");
  EXPECT_EQ(6,test.calk());
}

TEST(Tstack, can_count3)
{
  TCalculator test;
  test.setinfix("0+0");
  EXPECT_EQ(0,test.calk());
}

TEST(Tstack, can_count4)
{
  TCalculator test;
  test.setinfix("2^3");
  EXPECT_EQ(8,test.calk());
}

TEST(Tstack, can_count5)
{
  TCalculator test;
  test.setinfix("2^3+3");
  EXPECT_EQ(11,test.calk());
}

TEST(Tstack, can_count6)
{
  TCalculator test;
  test.setinfix("2^(3+3)");
  EXPECT_EQ(64,test.calk());
}
*/
TEST(Tstack, throws_when_set_empty_string)
{
  TCalculator test;
  test.setinfix("");
  ASSERT_ANY_THROW(test.calk());
}

TEST(Tstack, throws_when_set_incorrect_operations_string)
{
  TCalculator test;
  test.setinfix("+");
  ASSERT_ANY_THROW(test.calk());
}

TEST(Tstack, throws_when_set_incorrect_brackets_string)
{
  TCalculator test;
  test.setinfix("((()");
  ASSERT_ANY_THROW(test.calk());
}
