#pragma once
#include<iostream>

int IntInput(){
    int x;
    bool flag = true;
    while (flag) {
        flag = false;

        std::cin.clear();

        std::cin >> x;

        while (std::cin.peek() != '\n') {
            if (std::cin.get() != ' ') flag = true;
            std::cin.clear();
        };

        if (flag) std::cout << (char)-1 << ' ' << "Incorrect Input\n";
    };
    return x;
}

int InputArray(char** arr, int* arrSizes, int n, int m){
    int nLines = 0;
    while(true){
        while(std::cin.get() != '\n');
        std::cin;
        int k = 0;
        if(std::cin.peek() == '\n') break;
        while(std::cin.peek() != '\n' && k < m){
            arr[nLines][k] = std::cin.get();
            k++;
        }
        arrSizes[nLines] = k;
        nLines++;
    }
    return nLines;
}

void DeleteSymb(char** arr, int* arrSizes, int nLines, char deleter){
    for(int i = 0; i < nLines; i++){
        int steper = 0;
        for(int j = 0; j < arrSizes[i]; j++)
            if(arr[i][j] == deleter) steper++; else arr[i][j - steper] = arr[i][j];
        arrSizes[i] -= steper;
    }
}