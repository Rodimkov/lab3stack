#include "..\lab3stack\Tstack.h"

#include "gtest.h"

TEST(Tstack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Tstack<int> st(3));
}

TEST(Tstack, can_set_top_element)
{
  Tstack<int> st(3);
  ASSERT_NO_THROW(st.push(10));
}

TEST(Tstack, can_clear_top_element)
{
  Tstack<int> st(3);
  st.push(10);
  ASSERT_NO_THROW(st.pop());
}

TEST(Tstack, can_get_top_element)
{
  Tstack<int> st(3);
  st.push(10);
  EXPECT_EQ(10,st.top());
}

TEST(Tstack, can_create_copied_stack)
{
  Tstack<int> st1(3);
  ASSERT_NO_THROW(Tstack<int> st2(st1));
}

TEST(Tstack, test_for_empty)
{
  Tstack<int> st(3);
  EXPECT_EQ(1,st.isempty());
  st.push(10);
	EXPECT_EQ(0,st.isempty());
}

TEST(Tstack, test_for_full)
{
  Tstack<int> st(3);
  st.push(10);
	EXPECT_EQ(0,st.isfull());
	st.push(11);
	st.push(12);
  EXPECT_EQ(1,st.isfull());
}

TEST(Tstack, throws_when_set_top_element_with_too_large_position)
{
  Tstack<int> st(1);
  st.push(11);
  ASSERT_ANY_THROW(st.push(12));
}


TEST(Tstack, throws_when_getting_an_item_from_an_empty_stack_top)
{
  Tstack<int> st(1);
  ASSERT_ANY_THROW(st.top());
}

TEST(Tstack, throws_when_getting_an_item_from_an_empty_stack_pop)
{
  Tstack<int> st(1);
  ASSERT_ANY_THROW(st.pop());
}

TEST(Tstack, can_assign_stack_of_equal_size)
{
  const int size = 2;
  Tstack<int> st(size), st1(size);

  st.push(11);
  st.push(10);
  st1 = st;

  EXPECT_NE(11, st1.pop());
  EXPECT_NE(10, st1.pop());
}

TEST(Tstack, can_assign_stack_of_non_equal_size)
{
  const int size1 = 2, size2 = 5;
  Tstack<int> st(size1), st1(size2);

  st.push(11);
  st.push(10);
  st1 = st;

  EXPECT_NE(11, st1.pop());
  EXPECT_NE(10, st1.pop());
}

TEST(Tstack, copied_stack_is_equal_to_source_one)
{
  Tstack<int> st(3);
  st.push(10);
  st.push(11);

  Tstack<int> st1(st);

  EXPECT_EQ(11, st1.pop());
  EXPECT_EQ(10, st1.pop());
}

TEST(Tstack, copied_stack_has_its_own_memory)
{
  Tstack<int> st(3),st1(st);
  st.push(10);
  st1.push(11); 

  EXPECT_EQ(10, st.top() );
  EXPECT_EQ(11, st1.top() );
}