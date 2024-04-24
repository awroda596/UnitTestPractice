/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, ALL_CAPS){
	Password my_password;
	int actual = my_password.has_mixed_case("AZ"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, all_lower){
	Password my_password;
	int actual = my_password.has_mixed_case("az"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, lower_then_upper){
	Password my_password;
	int actual = my_password.has_mixed_case("aZ"); 
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, multiple_cap_before_lower){
	Password my_password;
	int actual = my_password.has_mixed_case("AAZAAZZzz"); 
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, many_lower_before_cap){
	Password my_password;
	int actual = my_password.has_mixed_case("aazzaaA"); 
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, numbers){
	Password my_password;
	int actual = my_password.has_mixed_case("123"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, numbers_all_lower){
	Password my_password;
	int actual = my_password.has_mixed_case("abcdefgh123"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, numbers_all_upper){
	Password my_password;
	int actual = my_password.has_mixed_case("123ABCDEFGH"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, mixed_case_with_numbers){
	Password my_password;
	int actual = my_password.has_mixed_case("a2Z"); 
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, alot_of_mixed){
	Password my_password;
	int actual = my_password.has_mixed_case("abcDEFghiJKLmnoPQRstuVWXyz"); 
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, only_specials){
	Password my_password;
	int actual = my_password.has_mixed_case("@#$%"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, lower_and_specials){
	Password my_password;
	int actual = my_password.has_mixed_case("abc@#$%"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, upper_and_specials){
	Password my_password;
	int actual = my_password.has_mixed_case("ABC@#$%"); 
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, mixed_case_specials){
	Password my_password;
	int actual = my_password.has_mixed_case("ABC@#$abc"); 
	ASSERT_EQ(1,actual);
}