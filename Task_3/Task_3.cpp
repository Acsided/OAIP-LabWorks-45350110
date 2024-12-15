#include <iostream>
#include "Funclions.cpp"
#include "Tests.cpp"

int main(){
    while(true){
        std::cout << "Работу выполнил студент группы 453502 Филон Денис Александрович." << std::endl;
        std::cout << "Программа принимает на вход строку из пользовательского ввода, которая содержит 2 или более слов и меняет четное и нечетное слово местами, если слов нечетное количество последнее слово остаеться низменным" << std::endl;
        std::cout << std::endl;
        std::cout << "Введите 1 если хотите продолжить выполнение программы и 2 если хотите выйти. Введите 3, если хотите видеть результаты тестов." << std::endl;
        int choise;
        while(true){
            choise = IntInput();
            if(choise < 1 || choise > 3 ){
                std::cout << "Incorrect input" << std::endl;
                continue;
            }
            break;
        }

        if(choise == 2) return 0;

        if(choise == 3){
             RUN_ALL_TESTS();
             continue;
        };

        char* arr = new char[1024];

        std::cout << "Введите строку со словами в формате слово пробел слово:" << std::endl;
        int n = InputData(arr);

        SwapText(arr, n);

        std::cout << std::endl;
        for(int i = 0; i < n; i++) std::cout << arr[i];
        std::cout << std::endl;

        delete[] arr;
    };
    return 0;
}