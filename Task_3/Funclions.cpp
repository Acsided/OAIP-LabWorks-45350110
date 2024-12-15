#pragma once
#include <iostream>

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

void Swap(char* arr, int i, int j){
    char buf = arr[i];
    arr[i] = arr[j];
    arr[j] = buf;
}

void SwapWords(char* arr, int l, int r){
    int ind = 0;

    for(ind = l; arr[ind] != ' ' && ind < r + 1; ind++); 

    if(ind == r) return;

    for(int i = ind; i < r; i++)
        for(int j = 0; j < ind - l + 1; j++)
            Swap(arr, i - j + 1, i - j);

    for(int i = 0; i < ind - l; i++) Swap(arr, r - i - 1, r - i);
}

int ClearData(char* arr, int n){
    bool flag = false;
    int steper = 0;
    for(int i = 0; i < n; i++){
        if(flag  && arr[i] == ' '){
            steper++;
            continue;
        };
        flag = false;
        if(arr[i] == ' ') flag = true;
        arr[i - steper] = arr[i];
    }
    for(int i = n - steper; i < n; i++) arr[i] = ' ';
    return n - steper;
}

int InputData(char* arr){
    int n = 0;

    while(std::cin.get() != '\n');

    std::cin;
    while(std::cin.peek() != '\n'){
        arr[n] = std::cin.get();
        n++;    
    }

    while(std::cin.get() != '\n');

    n = ClearData(arr, n);

    return n;
}

void SwapText(char* arr, int n){
    int l = -2, r = -2, coutSpaces = 0;
    bool flag = false;

    if(arr[0] != ' ') {
        r = -1;
        flag = true;
    };

    n = ClearData(arr, n);

    for(int i = 0; i < n; i++){
        if(arr[i] == ' ') flag = !flag;
        if((arr[i] == ' ' && flag) || (i == n - 1 && !flag)){
            l = r; 
            r = i;
            if(r != -2 && l != -2) SwapWords(arr, l + 1, (i == n - 1 ? r : r - 1));
        }
    }
}
