#pragma once
#include <iostream>
class Num{
private:
    char* data;
    int n;
    static bool IsNum(char a){
        return (a >= '0' && a <= '9');
    };

    int DelZeros(int ind){
        bool minus = false;
        if(ind - 1 > -1 && data[ind - 1] == '-'){
            data[ind - 1] = '#';
            minus = true;
        };
        while(ind + 1 != n && data[ind] == '0' && IsNum(data[ind + 1])){
            data[ind] = '#';
            ind++;
        };
        if(minus) data[ind - 1] = '-';
        return ind;
    }

public:
    void GiveData(char* data, int n){
        this->data = data;
        this->n = n;
    }
    void FindNums(){
        for(int i = 0; i < n; i++){
            if(i < n - 1 && data[i] == '-' && IsNum(data[i + 1])) continue;
            if(i > 0 && IsNum(data[i]) && !IsNum(data[i - 1])){
                i = DelZeros(i);
                continue;
            };
            if(IsNum(data[i])) continue;
            data[i] = '#';
        }
    };
    char* PutOutData(){
        return data;
    }
    bool IsEqual(char* st, int m){
        if(n != m) return false;
        for(int i = 0 ; i < n; i++) if(data[i] != st[i]){
            std::cout << st[i] << ' ' << data[i] << std::endl;
            return false;
        } 
        return true;
    }
};

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