#include "..\TStack\TStack.h"

#include "gtest.h"

TEST(TBitField, can_create_TStack_with_positive_length)
{
  ASSERT_NO_THROW(TStack <int> ts);
}

