#include <gtest/gtest.h>
#include <cstring>
#include "Funclions.cpp"

TEST(SwapTextTest, SingleSwap) {
    char* arr = new char[12]{'h','e','l','l','o',' ','w','o','r','l','d'};
    int n = 11;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "world hello");
    delete[] arr;
}

TEST(SwapTextTest, MultipleWords) {
    char arr[] = "the quick brown fox";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "quick the fox brown");
}

TEST(SwapTextTest, NoSwapNeeded) {
    char arr[] = "one";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "one");
}

TEST(SwapTextTest, OddNumberOfWords) {
    char arr[] = "one two three";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "two one three");
}

TEST(SwapTextTest, LeadingSpaces) {
    char arr[] = "  leading spaces  text";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);

    EXPECT_STREQ(arr, " spaces leading text  ");
}

TEST(SwapTextTest, TrailingSpaces) {
    char arr[] = "trailing spaces   text";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "spaces trailing text  ");
}

TEST(SwapTextTest, Punctuation) {
    char arr[] = "hello, world!";
    int n = 13;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "world! hello,");
}

TEST(SwapTextTest, Numbers) {
    char arr[] = "123 456 789";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "456 123 789");
}

TEST(SwapTextTest, SpecialCharacters) {
    char arr[] = "!@ #$ %^";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "#$ !@ %^");
}

TEST(SwapTextTest, MixedContent) {
    char arr[] = "abc 123 def";
    int n = sizeof(arr) / sizeof(arr[0]) - 1;
    SwapText(arr, n);
    EXPECT_STREQ(arr, "123 abc def");
}