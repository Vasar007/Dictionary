#include "key_not_found_exception.hpp"
#include "my_dictionary.hpp"

#include "gtest/gtest.h"


namespace tests
{

TEST(DictionaryTests, IsEmptyInitially)
{
	const vv::MyDictionary<int, int> dict;
	EXPECT_EQ(0, dict.Size());
}

TEST(DictionaryTests, GetForEmpty)
{
	const vv::MyDictionary<int, int> dict;
	EXPECT_THROW(dict.Get(0), vv::KeyNotFoundException<int>);
}

TEST(DictionaryTests, IsSetForEmpty)
{
	const vv::MyDictionary<int, int> dict;
	EXPECT_FALSE(dict.IsSet(0));
}

TEST(DictionaryTests, SetOneElement)
{
	vv::MyDictionary<int, int> dict;

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	int element;
	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(0, element);
}

TEST(DictionaryTests, SetOneElementGetAnother)
{
	vv::MyDictionary<int, int> dict;

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_FALSE(dict.IsSet(1));
	EXPECT_EQ(1, dict.Size());
	EXPECT_THROW(dict.Get(1), vv::KeyNotFoundException<int>);
}

TEST(DictionaryTests, SetTwoElements)
{
	vv::MyDictionary<int, int> dict;

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	int element;
	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(0, element);

	EXPECT_NO_THROW(dict.Set(1, 1));
	EXPECT_TRUE(dict.IsSet(1));
	EXPECT_EQ(2, dict.Size());

	ASSERT_NO_THROW(element = dict.Get(1));
	EXPECT_EQ(1, element);
}

TEST(DictionaryTests, UpdateElement)
{
	vv::MyDictionary<int, int> dict;

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	int element;
	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(0, element);

	EXPECT_NO_THROW(dict.Set(0, 1));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(1, element);
}

TEST(DictionaryTests, UpdateElementWithSameValue)
{
	vv::MyDictionary<int, int> dict;

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	int element;
	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(0, element);

	EXPECT_NO_THROW(dict.Set(0, 0));
	EXPECT_TRUE(dict.IsSet(0));
	EXPECT_EQ(1, dict.Size());

	ASSERT_NO_THROW(element = dict.Get(0));
	EXPECT_EQ(0, element);
}

} // namespace tests