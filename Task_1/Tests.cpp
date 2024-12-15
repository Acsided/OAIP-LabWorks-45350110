#include <gtest/gtest.h>
#include "Class.cpp"
Num obj;

TEST(Task, EmptyLine){
    char* dataIN = new char[9]{'a','s','d','a','s','d','d','f','g'};
    char* dataOut = new char[9]{'#','#','#','#','#','#','#','#','#'};
    obj.GiveData(dataIN, 9);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 9));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, FullLine){
    char* dataIN = new char[5]{'-','1','0','0','0'};
    char* dataOut = new char[5]{'-','1','0','0','0'};
    obj.GiveData(dataIN, 5);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 5));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, PreveriosZeros){
    char* dataIN = new char[9]{'a','s','d','-','0','0','0','2','3'};
    char* dataOut = new char[9]{'#','#','#','#','#','#','-','2','3'};   
    obj.GiveData(dataIN, 9);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 9));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, MinusZero){
    char* dataIN = new char[7]{'a','s','d','-','0','0','0'};
    char* dataOut = new char[7]{'#','#','#','#','#','-','0'};  
    obj.GiveData(dataIN, 7);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 7));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData1) {
    char* dataIN = new char[14]{'s','d','f','1','2','3','a','s','d','f','-','1','1','0'};
    char* dataOut = new char[14]{'#','#','#','1','2','3','#','#','#','#','-','1','1','0'};
    obj.GiveData(dataIN, 14);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 14));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData2) {
    char* dataIN = new char[14]{'0','d','1','d','2','d','3','d','4','d','5','d','6','0'};
    char* dataOut = new char[14]{'0','#','1','#','2','#','3','#','4','#','5','#','6','0'};
    obj.GiveData(dataIN, 14);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 14));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData3) {
    char* dataIN = new char[24]{'s','a','d','f','s','a','d','f','a','d','s','f','a','s','d','f','a','s','d','f','d','s','f','k'};
    char* dataOut = new char[24]{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'};
    obj.GiveData(dataIN, 24);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 24));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData4) {
    char* dataIN = new char[65]{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
    char* dataOut = new char[65]{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
    obj.GiveData(dataIN, 65);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 65));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData5) {
    char* dataIN = new char[1]{'0'};
    char* dataOut = new char[1]{'0'};
    obj.GiveData(dataIN, 1);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 1));
    delete[] dataIN;
    delete[] dataOut;
}

TEST(Task, TrashData6) {
    char* dataIN = new char[16]{'a','c','a','s','d','c','.','-','j','-','a','s','d','f'};
    char* dataOut = new char[16]{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'};
    obj.GiveData(dataIN, 15);
    obj.FindNums();
    EXPECT_EQ(true, obj.IsEqual(dataOut, 15));
    delete[] dataIN;
    delete[] dataOut;
}
