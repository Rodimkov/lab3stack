#include "..\lab-3\TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_count)
{
  TCalculator tc;
  tc.setinfix("2+2*2^(3+3)*8");
  EXPECT_EQ(1026,tc.calk());
}

TEST(TCalculator, throws_when_set_empty_string)
{
  TCalculator tc;
  ASSERT_ANY_THROW(tc.setinfix(""););
}

TEST(TCalculator, throws_when_set_incorrect_operations_string)
{
  TCalculator tc;
  ASSERT_ANY_THROW(tc.setinfix("+"););
}

TEST(TCalculator, throws_when_set_not_complete_operations_string)
{
  TCalculator tc;
  ASSERT_ANY_THROW(tc.setinfix("+2"););
}

TEST(TCalculator, throws_when_set_incorrect_brackets_string)
{
  TCalculator tc;
  tc.setinfix("((()");
  ASSERT_ANY_THROW(tc.calk());
}
