#include "..\lab3stack\TCalculator.h"

#include "gtest.h"

TEST(TCalculator, can_set_infix)
{
	TCalculator tc;
	ASSERT_NO_THROW(tc.setinfix("2+2"));
}

TEST(TCalculator, can_get_infix)
{
	TCalculator tc;
	tc.setinfix("2+2");
	EXPECT_EQ("2+2",tc.getinfix());
}

TEST(TCalculator, can_get_postfix)
{
	TCalculator tc;
	tc.setinfix("2+2");
	EXPECT_EQ("2 2+",tc.getpostfix());
}


TEST(TCalculator, can_calculate_simple)
{
	TCalculator tc;
	tc.setinfix("2+2");
	EXPECT_EQ(4,tc.calk());
}

TEST(TCalculator, can_calculate_operation_with_negative_number)
{
	TCalculator tc;
	tc.setinfix("3*(-4)");
	EXPECT_EQ(-12,tc.calk());
}

TEST(TCalculator, can_calculate_complicated)
{
	TCalculator tc;
	tc.setinfix("2+2*2^(3+3)*8");
	EXPECT_EQ(1026,tc.calk());
}

TEST(TCalculator, throws_when_can_calculate_empty_string)
{
	TCalculator tc;
	tc.setinfix("");
	ASSERT_ANY_THROW(tc.calk());
}

TEST(TCalculator, throws_when_can_calculate_incorrect_operations_string)
{
	TCalculator tc;
	tc.setinfix("+");
	ASSERT_ANY_THROW(tc.calk());
}

TEST(TCalculator, throws_when_can_calculate_not_complete_operations_string)
{
	TCalculator tc;
	tc.setinfix("+2");
	ASSERT_ANY_THROW(tc.calk());
}

TEST(TCalculator, throws_when_can_calculate_incorrect_brackets_string)
{
	TCalculator tc;
	tc.setinfix("((()");
	ASSERT_ANY_THROW(tc.calk());
}