#include "..\TStack\TCalculator.h"
#include "..\TStack\TCalculator.cpp"
#include "gtest.h"


TEST(TCalculator, can_create_TCalculator)
{
	ASSERT_NO_THROW(TCalculator tc );
}

TEST(TCalculator, can_SetInfix_TCalculator)
{
	
	TCalculator ts;
	string temp = "32";

	ASSERT_NO_THROW(ts.SetInfix(temp));
}

TEST(TCalculator, can_GetInfix_TCalculator_N1)
{

	TCalculator ts;
	string temp = ("1+2-3");
	ts.SetInfix(temp);

	ASSERT_NO_THROW(ts.GetInfix());
}

TEST(TCalculator, can_GetInfix_TCalculator_N2)
{

	TCalculator ts;
	string temp = "1+ 2 -3";
	ts.SetInfix(temp);

	EXPECT_EQ("1+ 2 -3" ,ts.GetInfix());
}

TEST(TCalculator, can_GetPostfix_TCalculator_N1)
{
	TCalculator ts;
	ASSERT_NO_THROW(ts.GetPostfix());
}

TEST(TCalculator, can_calculate_size_of_string_N1)
{
	string temp;

	EXPECT_EQ(0, Size(temp));
}
TEST(TCalculator, can_calculate_size_of_string_N2)
{
	string temp="231";

	EXPECT_EQ(3, Size(temp));
}

TEST(TCalculator,  can_define_Priority_N1)
{
	string temp = "+*^)";
	TCalculator tc;
	tc.SetInfix(temp);

	EXPECT_EQ(1, tc.Priority(0));
}
TEST(TCalculator, can_define_Priority_N2)
{
	string temp = "+*^)";
	TCalculator tc;
	tc.SetInfix(temp);

	EXPECT_EQ(2, tc.Priority(1));
}
TEST(TCalculator, can_define_Priority_N3)
{
	string temp = "+*^)";
	TCalculator tc;
	tc.SetInfix(temp);

	EXPECT_EQ(3, tc.Priority(2));
}
TEST(TCalculator, can_define_Priority_N4)
{
	string temp = "+*^)";
	TCalculator tc;
	tc.SetInfix(temp);

	EXPECT_EQ(0, tc.Priority(3));
}
TEST(TCalculator, cant_define_Priority_N1)
{
	string temp = "a";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_ANY_THROW(tc.Priority(0));
}

TEST(TCalculator, can_ChecBrackets_N1)
{
	string temp = "()(  )()";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_NO_THROW(tc.ChecBrackets());
}
TEST(TCalculator, can_ChecBrackets_N2)
{
	string temp = "()()(";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_ANY_THROW(tc.ChecBrackets());
}
TEST(TCalculator, can_ChecBrackets_N3)
{
	string temp = ")()()";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_ANY_THROW(tc.ChecBrackets());
}
TEST(TCalculator, can_ChecBrackets_N4)
{
	string temp = "()((()())(((())(((((";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_ANY_THROW(tc.ChecBrackets());
}
TEST(TCalculator, cant_ToPostfix)
{
	string temp = "15+32)- 344";
	TCalculator tc;
	tc.SetInfix(temp);

	ASSERT_ANY_THROW(tc.ToPostfix());
}
