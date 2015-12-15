// HashMapTests.cpp
//
// ICS 45C Fall 2015
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
   HashMap empty;
   ASSERT_EQ(0, empty.size());
}

TEST(TestHashMap, bucketCountofNewHM)
{
	HashMap empty;
	ASSERT_EQ(10, empty.bucketCount());
}
TEST(TestHashMap, add)
{
	HashMap a;
	std::string key{"KEY"};
	std::string value{"VALUE"};
	a.add(key,value);
	ASSERT_EQ(1, a.size());
	ASSERT_EQ("VALUE", a.value("KEY"));
	ASSERT_EQ(true, a.contains("KEY"));
}

TEST(TestHashMap, remove)
{
	HashMap a;
	std::string key{"KEY"};
	std::string value{"VALUE"};
	a.add(key, value);
	ASSERT_EQ(true, a.contains("KEY"));
	ASSERT_EQ(1, a.size());
	a.remove("KEY");
	ASSERT_EQ(false, a.contains("KEY"));
	ASSERT_EQ(0, a.size());
}

TEST(TestHashMap, removeSomethingThatIsNotThere)
{
	HashMap hm;
	std::string key{"KEY"};
	std::string value{"VALUE"};
	hm.add(key, value);
	hm.remove("NOTKEY");
	ASSERT_EQ(false, hm.contains("NOTKEY"));
	ASSERT_EQ(true, hm.contains("KEY"));
}

TEST(TestHashMap, removeSomethingFromEmptyHM)
{
	HashMap empty;
	empty.remove("KEY");
	ASSERT_EQ(false, empty.contains("KEY"));
}

TEST(TestHashMap, contains)
{
	HashMap a;
	std::string key{"KEY"};
	std::string value{"VALUE"};
	a.add(key, value);
	ASSERT_EQ(true, a.contains("KEY"));
	ASSERT_EQ(false, a.contains("VALUE"));
	ASSERT_EQ(false, a.contains("a1"));
}

TEST(TestHashMap, rehash)
{
	HashMap a;
	std::string key{"KEY"};
	std::string value{"VALUE"};
	a.add(key, value);
	ASSERT_EQ(10, a.bucketCount());
	a.add("a2", "b2");
	a.add("a3", "b3");
	a.add("a4", "b4");
	a.add("a5", "b5");
	a.add("a6", "b6");
	a.add("a7", "b7");
	a.add("a8", "b8");
	ASSERT_EQ(0.80, a.loadFactor());
	a.add("a9", "b9");
	ASSERT_EQ(21, a.bucketCount());
}

TEST(TestHashMap, load)
{
	HashMap hm;
	ASSERT_EQ(0.0, hm.loadFactor());
	hm.add("a1" , "b2");
	ASSERT_EQ(.10, hm.loadFactor());
}

TEST(TestHashMap, size)
{
	HashMap a;
	std::string key("KEY");
	std::string value("VALUE");
	a.add(key, value);
	ASSERT_EQ(1, a.size());
	a.add("a2", "b2");
	a.add("a3", "b3");
	a.add("a4", "b4");
	ASSERT_EQ(4, a.size());
	a.remove("a4");
	ASSERT_EQ(3, a.size());
}

TEST(TestHashMap, value)
{
	HashMap a;
	std::string key("KEY");
	std::string value("VALUE");
	a.add(key, value);
	ASSERT_EQ("VALUE", a.value("KEY"));
	ASSERT_EQ("", a.value("a1"));
}

TEST(TestHashMap, clear)
{
	HashMap a;
	a.add("a1", "b1");
	a.add("a2", "b2");
	a.add("a3", "b3");
	a.add("a4", "b4");
	ASSERT_EQ(4, a.size());
	a.clear();
	ASSERT_EQ(0, a.size());
	ASSERT_EQ(false, a.contains("a1"));
}
