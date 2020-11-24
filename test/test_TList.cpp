#include "TList.h"

#include <gtest.h>


TEST(TList, konstruktor_rabotaet)
{
	EXPECT_NO_THROW(TList<int> list);
}

TEST(TList, GetListLenght_rabotaet)
{
	TList<int> list;
	EXPECT_EQ(0, list.GetListLenght());
}

TEST(TList, IsEmpty_vozvrashatt_true)
{
	TList<int> list;
	EXPECT_TRUE(list.IsEmpty());
}

TEST(TList, IsEmpty_vozvrashatt_false)
{
	TList<int> list;
	list.InsFirst(5);
	EXPECT_FALSE(list.IsEmpty());
}

TEST(TList, InsFirst_rabotaet)
{
	TList<int> list;
	EXPECT_NO_THROW(list.InsFirst(5));
}

TEST(TList, InsLast_rabotaet)
{
	TList<int> list;
	EXPECT_NO_THROW(list.InsLast(5));
}

TEST(TList, DelFirst_rabotaet)
{
	TList<int> list;
	list.InsFirst(1);
	EXPECT_NO_THROW(list.DelFirst());
}

TEST(TList, DelLast_rabotaet)
{
	TList<int> list;
	list.InsFirst(1);
	EXPECT_NO_THROW(list.DelLast());
}

TEST(TList, DelFirst_rabotaet_pri_pustom_spiske)
{
	TList<int> list;
	EXPECT_NO_THROW(list.DelFirst());
}

TEST(TList, DelLast_rabotaet_pri_pustom_spiske)
{
	TList<int> list;
	EXPECT_NO_THROW(list.DelLast());
}

TEST(TList, DelList_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	list.DelList();
	EXPECT_EQ(0,list.GetListLenght());
}

TEST(TList, InsValue_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	
	EXPECT_NO_THROW(list.InsValue(0, 2));
}

TEST(TList, DelValue_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	EXPECT_NO_THROW(list.DelValue(0));
}

TEST(TList, Search_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	EXPECT_NO_THROW(list.search(0));
}

TEST(TList, Search_vozvrashaet_true)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	EXPECT_TRUE(list.search(0));
}

TEST(TList, Search_vozvrashaet_false)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	EXPECT_FALSE(list.search(10));
}

TEST(TList, Reverse_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsFirst(i);
	}
	EXPECT_NO_THROW(list.Reverse());
}

TEST(TList, get_vozvr_znachenya)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsLast(i);
	}
	EXPECT_EQ(0,list.get(0));
}

TEST(TList, get_kidaet_oshibky)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsLast(i);
	}
	EXPECT_ANY_THROW(list.get(-1));
}

TEST(TList, Merge_rabotaet)
{
	TList<int> list;
	TList<int> list1;
	TList<int> list2;
	for (int i = 0; i < 10; i++)
	{
		list1.InsLast(i);
		list2.InsLast(i+10);
	}

	EXPECT_NO_THROW(list.Merge(list1,list2));
}

TEST(TList, Merge_kidaet_oshibky_kogda_spiski_ne_otsortirivanbI)
{
	TList<int> list;
	TList<int> list1;
	TList<int> list2;
	for (int i = 0,j = 10; i < 10; i++,j--)
	{
		list1.InsLast(i);
		list2.InsLast(j);
	}
	EXPECT_ANY_THROW(list.Merge(list1, list2));
}

TEST(TList, ExchangeOfValues_rabotaet)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsLast(i);
	}
	EXPECT_NO_THROW(list.ExchangeOfValues(0,9));
}

TEST(TList, ExchangeOfValues_menyaet_znachenya)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsLast(i);
	}
	list.ExchangeOfValues(0, 9);
	EXPECT_EQ(9,list.get(0));
}

TEST(TList, ExchangeOfValues_kidaet_oshibky)
{
	TList<int> list;
	for (int i = 0; i < 10; i++)
	{
		list.InsLast(i);
	}
	
	EXPECT_ANY_THROW(list.ExchangeOfValues(0, -5));
}