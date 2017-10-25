#include "..\lab-3\Tstack.h"

#include "gtest.h"

TEST(Tstack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Tstack<int> bf());
}