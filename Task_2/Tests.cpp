#include "Functions.cpp"
#include <gtest/gtest.h>

TEST(DeleteSymbTest, NoDeleterChar) {
    char** arr = new char*[2];
    arr[0] = new char[6]{'h','e','l','l','o'};
    arr[1] = new char[6]{'w','o','r','l','d'};
    int* sizes = new int[2]{ 5, 5 };
    DeleteSymb(arr, sizes, 2, 'x');
    EXPECT_STREQ(arr[0], "hello");
    EXPECT_STREQ(arr[1], "world");
    EXPECT_EQ(sizes[0], 5);
    EXPECT_EQ(sizes[1], 5);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, SingleDeleterChar) {
    char** arr = new char*[2];
    arr[0] = new char[6]{'h','e','l','l','o'};
    arr[1] = new char[6]{'w','o','r','l','d'};
    int* sizes = new int[2]{ 5, 5 };
    DeleteSymb(arr, sizes, 2, 'o');
    EXPECT_STREQ(arr[0], "hello");
    EXPECT_STREQ(arr[1], "wrldd");
    EXPECT_EQ(sizes[0], 4);
    EXPECT_EQ(sizes[1], 4);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, MultipleDeleterChar) {
    char** arr = new char*[2];
    arr[0] = new char[6]{'h','e','l','l','o'};
    arr[1] = new char[6]{'w','o','r','l','d'};
    int* sizes = new int[2]{ 5, 5 };
    DeleteSymb(arr, sizes, 2, 'l');
    EXPECT_STREQ(arr[0], "heolo");
    EXPECT_STREQ(arr[1], "wordd");
    EXPECT_EQ(sizes[0], 3);
    EXPECT_EQ(sizes[1], 4);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, AllDeleterChar) {
    char** arr = new char*[2];
    arr[0] = new char[5]{'l','l','l','l'};
    arr[1] = new char[5]{'l','l','l','l'};
    int* sizes = new int[2]{ 4, 4 };
    DeleteSymb(arr, sizes, 2, 'l');
    EXPECT_STREQ(arr[0], "llll");
    EXPECT_STREQ(arr[1], "llll");
    EXPECT_EQ(sizes[0], 0);
    EXPECT_EQ(sizes[1], 0);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, EmptyArray) {
    char** arr = new char*[2];
    arr[0] = new char[1]{};
    arr[1] = new char[1]{};
    int* sizes = new int[2]{ 0, 0 };
    DeleteSymb(arr, sizes, 2, 'a');
    EXPECT_STREQ(arr[0], "");
    EXPECT_STREQ(arr[1], "");
    EXPECT_EQ(sizes[0], 0);
    EXPECT_EQ(sizes[1], 0);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, MixedContent) {
    char** arr = new char*[2];
    arr[0] = new char[7]{'a','b','c','a','b','c'};
    arr[1] = new char[7]{'x','y','z','x','y','z'};
    int* sizes = new int[2]{ 6, 6 };
    DeleteSymb(arr, sizes, 2, 'b');
    EXPECT_STREQ(arr[0], "acacbc");
    EXPECT_STREQ(arr[1], "xyzxyz");
    EXPECT_EQ(sizes[0], 4);
    EXPECT_EQ(sizes[1], 6);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, LargeArray) {
    char** arr = new char*[2];
    arr[0] = new char[17]{'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h'};
    arr[1] = new char[17]{'i','i','j','j','k','k','l','l','m','m','n','n','o','o','p','p'};
    int* sizes = new int[2]{ 16, 16 };
    DeleteSymb(arr, sizes, 2, 'g');
    EXPECT_STREQ(arr[0], "aabbccddeeffhhhh");
    EXPECT_STREQ(arr[1], "iijjkkllmmnnoopp");
    EXPECT_EQ(sizes[0], 14);
    EXPECT_EQ(sizes[1], 16);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, NumbersInArray) {
    char** arr = new char*[2];
    arr[0] = new char[7]{'1','2','3','4','5','6'};
    arr[1] = new char[7]{'7','8','9','0','1','2'};
    int* sizes = new int[2]{ 6, 6 };
    DeleteSymb(arr, sizes, 2, '2');
    EXPECT_STREQ(arr[0], "134566");
    EXPECT_STREQ(arr[1], "789012");
    EXPECT_EQ(sizes[0], 5);
    EXPECT_EQ(sizes[1], 5);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, SpecialCharacters) {
    char** arr = new char*[2];
    arr[0] = new char[6]{'!','@','#','$','%'};
    arr[1] = new char[6]{'^','&','*','(',')'};
    int* sizes = new int[2]{ 5, 5 };
    DeleteSymb(arr, sizes, 2, '@');
    EXPECT_STREQ(arr[0], "!#$%%");
    EXPECT_STREQ(arr[1], "^&*()");
    EXPECT_EQ(sizes[0], 4);
    EXPECT_EQ(sizes[1], 5);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}

TEST(DeleteSymbTest, NewlineCharacter) {
    char** arr = new char*[2];
    arr[0] = new char[12]{'h','e','l','l','o','\n','w','o','r','l','d'};
    arr[1] = new char[9]{'n','e','w','\n','l','i','n','e'};
    int* sizes = new int[2]{ 11, 8 };
    DeleteSymb(arr, sizes, 2, '\n');
    EXPECT_STREQ(arr[0], "helloworldd");
    EXPECT_STREQ(arr[1], "newlinee");
    EXPECT_EQ(sizes[0], 10);
    EXPECT_EQ(sizes[1], 7);
    delete[] arr[0];
    delete[] arr[1];
    delete[] arr;
    delete[] sizes;
}