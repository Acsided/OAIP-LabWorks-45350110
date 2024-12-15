#include <iostream>
#include "Functions.cpp"
#include "Tests.cpp"

int main(){
    std::cout << "Работу выполнил студент группы 453502 Филон Денис Александрович." << std::endl;
    std::cout << "Программа принимает на вход строку из пользовательского ввода, которая содержит 2 или более слов и меняет четное и нечетное слово местами, если слов нечетное количество последнее слово остаеться низменным" << std::endl;
    std::cout << std::endl;
    while(true){

        std::cout << "Введите 1 если хотите продолжить выполнение программы и 2 если хотите выйти. Введите 3, если хотите видеть результаты тестов." << std::endl;

        int choise = 0;
        while(true){
            choise = IntInput();
            if(choise < 1 || choise > 3){
                std::cout << "Uncorrect input! Please Try againe" << std::endl;
                continue;
            }
            break;
        }

        if(choise == 2) break;

        if(choise == 3){
            RUN_ALL_TESTS();
            continue;
        }

        int n = 300, m = 900, nLines = 0;

        char** arr = new char*[n];
        for(int i = 0; i < n; i++) arr[i] = new char[m];

        int* arrSizes = new int[n];

        std::cout << "Введите символ, который хотите удалить. Если символов введено несколько, то будет взят первый введенный символ." << std::endl;
        char deleter;
        std::cin >> deleter;

        std::cout << "Построчно вводите текст используя Enter для перевода строки. Нажмите дважды Enter, если хотите окончить ввод." << std::endl;
        nLines = InputArray(arr, arrSizes, n, m);
        DeleteSymb(arr, arrSizes, nLines, deleter);
        for(int i = 0; i < nLines; i++){
            for(int j = 0; j < arrSizes[i]; j++) std::cout << arr[i][j];
            std::cout << std::endl;
        }
        
        for(int i = 0; i < n; i++) delete[] arr[i];
        delete[] arr;
        delete[] arrSizes;
    }
    return 0;
}
