#include "NextDate.h"
#include <gtest/gtest.h>

void testNextDate(int preYear, int preMonth, int preDay, int nextYear, int nextMonth, int nextDay){
	Date* a= NewDateInstance( preYear, preMonth, preDay);
	Date* b= NextDate(a);
	//bool ret = checkDate(b, nextYear, nextMonth, nextDay);
	//free(a);
	//free(b);
	EXPECT_EQ(nextYear, b->year);
	EXPECT_EQ(nextMonth, b->month);
	EXPECT_EQ(nextDay, b->day);
	//free(a);
        //free(b);
}

void testInvalid(int preYear, int preMonth, int preDay){
	Date* a= NewDateInstance( preYear, preMonth, preDay);
	Date* b= NextDate(a);
	free(a);
	free(b);
	EXPECT_TRUE(b==NULL);
}

TEST(BoundaryTest, Year) { 
	testNextDate( 1812, 1, 1 , 1812, 1, 2);
	testNextDate( 1813, 7, 9 , 1813, 7, 10);
	testNextDate( 2012, 6, 10 , 2012, 6, 11);	
	testNextDate( 2011, 10, 20 , 2011, 10, 21);

	//invalid testing
	testInvalid(1811, 1, 1);
	testInvalid(1811, 12, 31);
	testInvalid(2013, 12, 31);
	testInvalid(2013, 1, 1);
}
 
TEST(BoundaryTest, Month) {
	testNextDate( 2000 , 1, 1 , 2000, 1, 2);
	testNextDate( 2001 , 2, 10 , 2001, 2, 11);
	testNextDate( 2002 , 12, 1 , 2002, 12, 2);
	testNextDate( 2003 , 11, 29 , 2003, 11, 30);

	//invalid testing
	testInvalid( 1875 , 0, 1);
	testInvalid( 1876 , -1, 1);
}

TEST(BoundaryTest, Day) {
        testNextDate( 1900 , 3, 1 , 1900, 3, 2);
        testNextDate( 1901 , 4, 2 , 1901, 4, 3);
        testNextDate( 1902 , 5, 31 , 1902, 6, 1);
        testNextDate( 1903 , 6, 30 , 1903, 7, 1);
	testNextDate( 1904 , 7, 30 , 1904, 7, 31);
	testNextDate( 1905 , 7, 1 , 1905, 7, 2);

	//invalid testing
	testInvalid( 1975 , 1, 0);
        testInvalid( 1976 , 12, 32);
	testInvalid( 1975 , 6, 31);
        testInvalid( 1976 , 9, 32);
}
 
TEST(EquivalentClassTest, SmallMonthNormalYear)
{
	testNextDate( 1813 , 4, 1 , 1813, 4, 2);
        testNextDate( 1814 , 6, 2 , 1814, 6, 3);
        testNextDate( 1815 , 9, 30, 1815, 10, 1);
	testNextDate( 1913 , 11, 1 , 1913, 11, 2);
        testNextDate( 1914 , 9, 2 , 1914, 9, 3);
        testNextDate( 1915 , 6, 30, 1915, 7, 1);

	//invalid testing
        testInvalid( 1989 , 4, 31);
        testInvalid( 1990 , 6, 0);
        testInvalid( 1991 , 9, 31);
        testInvalid( 1993 , 11, -1);
}

TEST(EdgeTest, SmallMonthNormalYear)
{
        testNextDate( 1863 , 4, 1 , 1863, 4, 2);
        testNextDate( 1874 , 6, 2 , 1874, 6, 3);
        testNextDate( 1875 , 9, 30, 1875, 10, 1);
        testNextDate( 1973 , 11, 30 , 1973, 12, 1);
        testNextDate( 1974 , 9, 29 , 1974, 9, 30);
        testNextDate( 1975 , 6, 29, 1975, 6, 30);

        //invalid testing
        testInvalid( 1939 , 11, 31);
        testInvalid( 1950 , 7, 0);
        testInvalid( 1951 , 6, 31);
        testInvalid( 1953 , 4, -1);
}

TEST(EquivalentClassTest, BigMonthNormalYear)
{
	testNextDate( 1851 , 1, 19 , 1851, 1, 20);
        testNextDate( 1853 , 3, 20 , 1853, 3, 21);
        testNextDate( 1854 , 5, 31 , 1854, 6, 1);
	testNextDate( 1855 , 7, 30 , 1855, 7, 31);
	testNextDate( 1857 , 8, 20 , 1857, 8, 21);
	testNextDate( 1858 , 10, 25 , 1858, 10, 26);
	testNextDate( 1859 , 12, 6 , 1859, 12, 7);

	//invalid testing
	testInvalid( 1951 , 1, 0);
        testInvalid( 1953 , 3, -1);
        testInvalid( 1954 , 5, 32);
        testInvalid( 1955 , 7, 33);
        testInvalid( 1957 , 8, 32);
        testInvalid( 1958 , 10, -1);
        testInvalid( 1959 , 12, 0);
}

TEST(EdgeTest, BigMonthNormalYear)
{
        testNextDate( 1851 , 1, 1 , 1851, 1, 2);
        testNextDate( 1853 , 3, 2 , 1853, 3, 3);
        testNextDate( 1854 , 5, 30 , 1854, 5, 31);
        testNextDate( 1855 , 12, 31 , 1856, 1, 1);

        //invalid testing
        testInvalid( 2000 , 1, 32);
        testInvalid( 2001 , 3, -1);
        testInvalid( 2002 , 5, 32);
}


TEST(EquivalentClassTest, FebruaryNormalYear)
{
	testNextDate( 1971 , 2, 1 , 1971, 2, 2);
	testNextDate( 1973 , 2, 5 , 1973, 2, 6);
	testNextDate( 1975 , 2, 10 , 1975, 2, 11);
	testNextDate( 1977 , 2, 20 , 1977, 2, 21);
	testNextDate( 1979 , 2, 28 , 1979, 3, 1);

	//invalid testing
	testInvalid( 1925 , 2, 0);
	testInvalid( 1926 , 2, -1);
	testInvalid( 1927 , 2, 29);
	testInvalid( 1929 , 2, 30);
}

TEST(EdgeTest, FebruaryNormalYear)
{
        testNextDate( 1969 , 2, 1 , 1969, 2, 2);
        testNextDate( 1973 , 2, 1 , 1973, 2, 2);
        testNextDate( 1975 , 2, 28 , 1975, 3, 1);
        testNextDate( 1977 , 2, 28 , 1977, 3, 1);
	testNextDate( 1900 , 2, 28 , 1900, 3, 1);

        //invalid testing
        testInvalid( 1833 , 2, 0);
        testInvalid( 1833 , 2, -1);
        testInvalid( 1834 , 2, 29);
        testInvalid( 1835 , 2, 30);
	testInvalid( 1900 , 2, 29);
}


TEST(EquivalentClassTest, SmallMonthLeapYear)
{
	testNextDate( 1812 , 4, 5 , 1812, 4, 6);
        testNextDate( 1816 , 6, 10 , 1816, 6, 11);
        testNextDate( 1820 , 9, 13, 1820, 9, 14);
        testNextDate( 1924 , 11, 19 , 1924, 11, 20);
        testNextDate( 1928 , 9, 25 , 1928, 9, 26);
        testNextDate( 1932 , 6, 30, 1932, 7, 1);

        //invalid testing
        testInvalid( 1989 , 4, 31);
        testInvalid( 1990 , 6, 0);
        testInvalid( 1991 , 9, 31);
        testInvalid( 1993 , 11, -1);
}

TEST(EdgeTest, SmallMonthLeapYear)
{
        testNextDate( 1840 , 4, 1 , 1840, 4, 2);
        testNextDate( 1844 , 6, 1 , 1844, 6, 2);
        testNextDate( 1848 , 9, 30, 1848, 10, 1);
        testNextDate( 1852 , 11, 30 , 1852, 12, 1);
        testNextDate( 1856 , 6, 30 , 1856, 7, 1);

        //invalid testing
        testInvalid( 1960 , 4, 31);
        testInvalid( 1964 , 6, 0);
}

TEST(EquivalentClassTest, BigMonthLeapYear)
{
	testNextDate( 1852 , 1, 3 , 1852, 1, 4);
        testNextDate( 1856 , 3, 8 , 1856, 3, 9);
        testNextDate( 1860 , 5, 13 , 1860, 5, 14);
        testNextDate( 1864 , 7, 18 , 1864, 7, 19);
        testNextDate( 1868 , 8, 23 , 1868, 8, 24);
        testNextDate( 1872 , 10, 28 , 1872, 10, 29);
        testNextDate( 1876 , 12, 31 , 1877, 1, 1);

        //invalid testing
        testInvalid( 1952 , 1, 0);
        testInvalid( 1956 , 3, -1);
        testInvalid( 1960 , 5, 32);
}

TEST(EdgeTest, BigMonthLeapYear)
{
        testNextDate( 1924 , 1, 3 , 1924, 1, 4);
        testNextDate( 1856 , 3, 8 , 1856, 3, 9);
        testNextDate( 1860 , 5, 13 , 1860, 5, 14);
        testNextDate( 1864 , 7, 18 , 1864, 7, 19);
        testNextDate( 1868 , 8, 23 , 1868, 8, 24);
        testNextDate( 1872 , 10, 28 , 1872, 10, 29);
        testNextDate( 1876 , 12, 31 , 1877, 1, 1);

        //invalid testing
        testInvalid( 1952 , 1, 0);
        testInvalid( 1956 , 3, -1);
        testInvalid( 1960 , 5, 32);
}


TEST(EquivalentClassTest, FebruaryLeapYear)
{
	testNextDate( 1972 , 2, 1 , 1972, 2, 2);
        testNextDate( 1976 , 2, 5 , 1976, 2, 6);
        testNextDate( 1980 , 2, 10 , 1980, 2, 11);
        testNextDate( 1984 , 2, 20 , 1984, 2, 21);
        testNextDate( 1988 , 2, 28 , 1988, 2, 29);
	testNextDate( 1992 , 2, 29 , 1992, 3, 1);

        //invalid testing
        testInvalid( 1932 , 2, 0);
        testInvalid( 1936 , 2, -1);
        testInvalid( 1940 , 2, 30);
}

TEST(EdgeTest, FebruaryLeapYear)
{
        testNextDate( 1992 , 2, 1 , 1992, 2, 2);
        testNextDate( 1996 , 2, 1 , 1996, 2, 2);
        testNextDate( 1984 , 2, 29 , 1984, 3, 1);
        testNextDate( 1952 , 2, 29 , 1952, 3, 1);
        testNextDate( 2000 , 2, 29 , 2000, 3, 1);

        //invalid testing
        testInvalid( 2000 , 2, 30);
        testInvalid( 1936 , 2, 0);
        testInvalid( 1980 , 2, 30);
}

TEST(Coverage, C0_1)
{
	testInvalid( 1992 , 1, 40);
	testNextDate( 1996 , 2, 1 , 1996, 2, 2);
	testNextDate( 1876 , 12, 31 , 1877, 1, 1);
        testNextDate( 1876 , 11, 30 , 1876, 12, 1);
	testNextDate( 1997 , 2, 1 , 1997, 2, 2);
}

TEST(Coverage, C2_1)
{
	testInvalid( 1800 , 8, 1);
	testInvalid( 1900 , 12, -1);
	testInvalid( 1900 , 13, 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
