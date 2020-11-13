#include "multistack.h"

#include <gtest.h>


TEST(multistack, konstructor_rabotaet)
{
	EXPECT_NO_THROW(TMultistack ms);
}

TEST(multistack, IsEmpty_rabotaet)
{
	TMultistack ms;
	EXPECT_TRUE(ms.IsEmpty(1));
}

TEST(multistack, IsEmpty_vozvrashaet_false)
{
	TMultistack ms;
	ms.Put(1, 1);
	EXPECT_FALSE(ms.IsEmpty(1));
}

TEST(multistack, IsFull_vozvrashaet_false)
{
	TMultistack ms;
	EXPECT_FALSE(ms.IsFull(1));
}

TEST(multistack, IsFull_rabotaet)
{
	TMultistack ms;
	for (int i = 0; i < 10; i++)
	{
		ms.Put(1, i);
	}
	EXPECT_TRUE(ms.IsFull(1));
}

TEST(multistack, Put_rabotaet)
{
	TMultistack ms;
	EXPECT_NO_THROW(ms.Put(1,1));
}

TEST(multistack, Get_rabotaet)
{
	TMultistack ms;
	ms.Put(1, 1);
	EXPECT_NO_THROW(ms.Get(1));
}

TEST(multistack, Get_kidaet_iskluchenie_esli_stack_pust)
{
	TMultistack ms;
	EXPECT_ANY_THROW(ms.Get(1));
}

TEST(multistack, Perepackovka_rabotaet)
{
	TMultistack ms;
	for (int i = 0; i < 10; i++)
	{
		ms.Put(1, i);
	}
	EXPECT_NO_THROW(ms.Put(1,1));
}

