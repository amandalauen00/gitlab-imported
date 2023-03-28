#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "..\catch.hpp"
#include "recCString.h"

TEST_CASE("recCmp - Go until last letter")
{
    char str1[100] = "aaaaaaaaaaab";
    char str2[100] = "aaaaaaaaaaaa";
    int result;

    result = recCmp(str1, str2, 0);
    CHECK(result > 0);

    result = recCmp(str2, str1, 0);
    CHECK(result < 0);
}
TEST_CASE("recCmp - Both words are different")
{
    char str1[100] = "Coding sucks";
    char str2[100] = "coding Sucks";
    int result;

    result = recCmp(str1, str2, 0);
    CHECK(result < 0);

    result = recCmp(str2, str1, 0);
    CHECK(result > 0);
}
TEST_CASE("recCmp - Both words are the same")
{
    char str1[100] = "New Calculator";
    char str2[100] = "New Calculator";
    int result;

    result = recCmp(str1, str2, 0);
    CHECK(result == 0);

    result = recCmp(str2, str1, 0);
    CHECK(result == 0);
}
TEST_CASE("recCmp - Empty string check")
{
    char str1[100] = "";
    char str2[100] = "";
    int result;

    result = recCmp(str1, str2, 0);
    CHECK(result == 0);

    result = recCmp(str2, str1, 0);
    CHECK(result == 0);
}
TEST_CASE("fixTitle - Change every letter")
{
    char str[100] = "a b c d e f g";
    char ans[100] = "A B C D E F G";
    fixTitle(str,0);
    REQUIRE(strcmp(str,ans) == 0);
}
TEST_CASE("fixTitle - Empty string check")
{
    char str[100] = "";
    char ans[100] = "";
    fixTitle(str,0);
    REQUIRE(strcmp(str,ans) == 0);
}
TEST_CASE("fixTitle - capitalizing one word")
{
    char str[100] = "hello";
    char ans[100] = "Hello";
    fixTitle(str,0);
    REQUIRE(strcmp(str,ans) == 0);
}
TEST_CASE("fixTitle - capitalizing multiple words in title")
{
    char str[100] = "the mortal instruments: city of bones";
    char ans[100] = "The Mortal Instruments: City Of Bones";
    fixTitle(str,0);
    REQUIRE(strcmp(str,ans) == 0);
}