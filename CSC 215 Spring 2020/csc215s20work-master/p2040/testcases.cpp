#include "..\catch.hpp"
#include "strFunctions.h"

TEST_CASE("ctrim back - a tab is inserted")
{
    char original[100] = "This is a test  \t ";
    char answer[100] = "This is a test";
    ctrim(original, BACK);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim back - every white space character inserted")
{
    char original[100] = "Coding is hard\n\t\f";
    char answer[100] = "Coding is hard";
    ctrim(original, BACK);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim back - Empty space test")
{
    char original[100] = "          ";
    char answer[100] = "";
    ctrim(original, BACK);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim back - one spot removed from the back")
{
    char original[100] = "The roads are bad ";
    char answer[100] = "The roads are bad";
    ctrim(original, BACK);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim front - a new line and a tab off the front")
{
    char original[100] = "\n\tThis is a test";
    char answer[100] = "This is a test";
    ctrim(original, FRONT);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim front - one space off the front")
{
    char original[100] = " Coding is fun.";
    char answer[100] = "Coding is fun.";
    ctrim(original, FRONT);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim front - Ten spaces off the front")
{
    char original[100] = "          Hello, it's me";
    char answer[100] = "Hello, it's me";
    ctrim(original, FRONT);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim front - every whitespace character off from the front")
{
    char original[100] = " \t\n\f\r\vHelp";
    char answer[100] = "Help";
    ctrim(original, FRONT);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim both - Removing one from both ends")
{
    char original[100] = " Music to my ears ";
    char answer[100] = "Music to my ears";
    ctrim(original, BOTH);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim both - every whitespace character were inserted")
{
    char original[100] = " \n\t\f\r\vI hate snow  ";
    char answer[100] = "I hate snow";
    ctrim(original, BOTH);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim both - taking two tabs off each end")
{
    char original[100] = "      I'm hungry      ";
    char answer[100] = "I'm hungry";
    ctrim(original, BOTH);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE("ctrim both - Nothing but white space")
{
    char original[100] = "                    ";
    char answer[100] = "";
    ctrim(original, BOTH);
    REQUIRE(strcmp(answer, original) == 0);
}
TEST_CASE ("strim back - empty string")
{
    string original = "";
    string answer = "";
    strim (original, BACK);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim back - take one spot off the back")
{
    string original = "This needs to work ";
    string answer = "This needs to work";
    strim (original, BACK);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim back - Nothing but whitespace")
{
    string original = "                 ";
    string answer = "";
    strim (original, BACK);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim back - every whitespace character off the back")
{
    string original = "Don't crash \n\t\v\f\r";
    string answer = "Don't crash";
    strim (original, BACK);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim front - empty string check")
{
    string original = "";
    string answer = "";
    strim (original, FRONT);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim front - take one space off the front")
{
    string original = " The code is 6364";
    string answer = "The code is 6364";
    strim (original, FRONT);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim front - Nothing but whitespace")
{
    string original = "  \n\t\r\f\v ";
    string answer = "";
    strim (original, FRONT);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim front - everywhite space character off the front")
{
    string original = " \n\t\v\r\fThese classes are required";
    string answer = "These classes are required";
    strim (original, FRONT);
    REQUIRE( answer == original );
}
TEST_CASE ("strim both - a tab is entered on both sides")
{
    string original = "    message recieved    ";
    string answer = "message recieved";
    strim (original, BOTH);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim both - every whitespace character entered on both sides")
{
    string original = " \n\t\v\f\rTesting 1, 2, 3 \n\t\v\f\r";
    string answer = "Testing 1, 2, 3";
    strim (original, BOTH);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim both - taking one off of each end")
{
    string original = " To be or not to be ";
    string answer = "To be or not to be";
    strim (original, BOTH);
    REQUIRE(  answer == original );
}
TEST_CASE ("strim both - Nothing but whitespace")
{
    string original = "                         ";
    string answer = "";
    strim (original, BOTH);
    REQUIRE(  answer == original );
}

TEST_CASE ("strim priv - WS on Front")
{
    string original = "  \n\t\r\f\v Hello\f  \n\t\r\f\v ";
    string answer = "Hello\f  \n\t\r\f\v ";
    strim (original, FRONT);
    REQUIRE(  answer == original );
}