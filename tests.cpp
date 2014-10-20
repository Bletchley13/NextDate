#include "NextDate.h"
#include <gtest/gtest.h>

void testNextDate(int preYear, int preMonth, int preDay, int nextYear, int nextMonth, int nextDay){
	Date* a= NewDateInstance( preYear, preMonth, preDay);
	Date* b= NextDate(a);
	bool ret = checkDate(a, nextYear, nextMonth, nextDay);
	free(a);
	free(b);
	EXPECT_TRUE(ret);
}


TEST(BoundaryTest, Year) { 
	testNextDate( 0, 1, 1 , 0, 1, 2);
	testNextDate( 1, 7, 9 , 1, 7, 10);
	testNextDate( 9999, 6, 10 , 9999, 6, 11);	
	testNextDate( 10000, 10, 20 , 10000, 10, 30);
}
 
TEST(BoundaryTest, Month) {
	testNextDate( 1234 , 1, 1 , 1234, 1, 2);
	testNextDate( 1234 , 2, 10 , 1234, 2, 11);
	testNextDate( 2014 , 12, 1 , 0, 12, 2);
	testNextDate( 1234 , 11, 29 , 1234, 11, 30);
}

TEST(BoundaryTest, Day) {
        testNextDate( 1234 , 3, 1 , 1234, 3, 2);
        testNextDate( 1234 , 4, 2 , 1234, 4, 3);
        testNextDate( 2014 , 5, 31 , 0, 6, 1);
        testNextDate( 1234 , 6, 30 , 1234, 7, 1);
	testNextDate( 2013 , 7, 30 , 1234, 7, 31);
	testNextDate( 1900 , 3, 30 , 1234, 8, 31);
}
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
