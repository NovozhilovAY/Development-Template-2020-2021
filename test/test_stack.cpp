#include "stack.h"

#include <gtest.h>


TEST(stack, konstruktor_rabotaet)
{
	EXPECT_NO_THROW(TStack st(5));
}

TEST(stack, IsEmpty_rabotaet_na_pustom_steke)
{
	TStack st(5);
	EXPECT_TRUE(st.IsEmpty());
}

TEST(stack, IsEmpty_vozvrashaet_false_esli_stack_ne_pust)
{
	TStack st(5);
	st.Put(1);
	EXPECT_FALSE(st.IsEmpty());
}

TEST(stack, IsIsFull_rabotaet_na_polnom_steke)
{
	TStack st(5);
	for (int i = 0; i < 5; i++)
	{
		st.Put(i);
	}
	EXPECT_TRUE(st.IsFull());
}

TEST(stack, IsFull_vozvrashaet_false_esli_stack_ne_polon)
{
	TStack st(5);
	EXPECT_FALSE(st.IsFull());
}

TEST(stack, Put_rabotaet)
{
	TStack st(5);
	EXPECT_NO_THROW(st.Put(1));
}

TEST(stack, Put_kidaet_iskluchenie_kogda_stack_polon)
{
	TStack st(5);
	for (int i = 0; i < 5; i++)
	{
		st.Put(i);
	}
	EXPECT_ANY_THROW(st.Put(1));
}

TEST(stack, Get_rabotaet)
{
	TStack st(5);
	for (int i = 0; i < 5; i++)
	{
		st.Put(i);
	}
	EXPECT_NO_THROW(st.Get());
}

TEST(stack, GET_kidaet_iskluchenie_kogda_stack_pust)
{
	TStack st(5);

	EXPECT_ANY_THROW(st.Get());
}