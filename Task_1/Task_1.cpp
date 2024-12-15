#include <iostream>
#include "Tests.cpp"
#include "Class.cpp"

int main(){
    std::cout << "Работу выполнил студент группы 453502 Филон Денис Александрович." << std::endl;
    std::cout << "Программа принимает на вход строку из пользовательского ввода, которая содержит 2 или более слов и меняет четное и нечетное слово местами, если слов нечетное количество последнее слово остаеться низменным" << std::endl;
    std::cout << std::endl;
    while(true){
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

        char* s = new char[82]{};
        int n = 0;

        std::cout << "Введите строку с числами, нажмите Enter, если хототе закончить ввод." << std::endl;

        while(std::cin.get() != '\n');

        std::cin;

        while(std::cin.peek() != '\n' && n < 81){
            s[n] = std::cin.get();
            n++;
        };
        std::cin.get();

        Num obj;
        obj.GiveData(s, n);
        obj.FindNums();
        s = obj.PutOutData();

        std::cout << "Целые числа, найденные в строке:" << std::endl;

        for(int i = 0; i < n - 1; i++) 
            if(s[i] == '#' && s[i + 1] != '#') std::cout << std::endl; else 
                if(s[i] != '#') std::cout << s[i];
        if(s[n - 1] != '#') std::cout << s[n - 1];

        std::cout << std::endl;

        delete[] s;
    };
    return 0;
}