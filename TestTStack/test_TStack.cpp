#include "..\TStack\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_TStack_with_positive_length)
{
  ASSERT_NO_THROW(TStack <int> ts(3));
}

TEST(TStack, can_create_TStack_with_standart_length)
{
	ASSERT_NO_THROW(TStack <int> ts);
}

TEST(TStack, cant_create_TStack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack <int> ts(-1));
}

TEST(TStack, can_create_empty_stack)
{
	TStack <int> ts;

	EXPECT_EQ( 1,ts.IsEmpty() );
}

TEST(TStack, cant_Pop_elem_if_stack_IsEmpty)
{
	TStack <int> ts(1);

	ASSERT_ANY_THROW(ts.Pop());
}

TEST(TStack, can_create_full_stack)
{
	TStack <int> ts(1);
		ts.Push(3);
    

	EXPECT_EQ(true, ts.IsFull());
}

TEST(TStack, can_push_elem)
{
	TStack <int> ts;
	ts.Push(3);

	EXPECT_EQ(3, ts.Top());
}

TEST(TStack, cant_push_elem_if_stack_IsFull)
{
	TStack <int> ts(1);
	ts.Push(3);

	ASSERT_ANY_THROW(ts.Push(4));
}

TEST(TStack, can_coppy_stack)
{
	TStack <int> ts;
	ts.Push(3);


	ASSERT_NO_THROW(TStack<int> ts1(ts));
}

TEST(TStack, coppy_stack_equals_the_first_stack)
{
	TStack <int> ts;
	ts.Push(3);

	TStack<int> ts1(ts);

	EXPECT_EQ( ts.Top(), ts1.Top() );
}

TEST(TStack, can_Pop_stack_N1)
{
	TStack <int> ts(1);
	ts.Push(3);

	ts.Pop();

	EXPECT_EQ(true, ts.IsEmpty());
}

TEST(TStack, can_Pop_stack_N2)
{
	TStack <int> ts(1);
	ts.Push(3);

	ASSERT_NO_THROW(ts.Pop());
}

TEST(TStack, can_clear_stack)
{
	TStack <int> ts;
	ts.Push(3);
	
	ts.Clr();

	EXPECT_EQ(true, ts.IsEmpty());
}

