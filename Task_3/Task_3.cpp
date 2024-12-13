#include <iostream>
#include "h.h"
#include <locale>
int main() {
    govno();
    std::setlocale(LC_ALL, "ru_RU.CP866");

    while (true) {
        char choice;
        std::cout << "Хотите запустить программу?[y/n]: " << '\n';
        std::cin >> choice;

        while (std::cin.fail() || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод, введите y/n: ";
            std::cin >> choice;
        }

        if (choice == 'n' || choice == 'N') {
            std::cout << "Конец работы" << "\n";
            break;
        }

        std::cout << "Введите уравнение (макс 80 символов): ";
        char* ch = new char[81];
        int i = 0;
        char c;


        std::cin.ignore();

        while ((c = getchar()) != '\n' && i < 80) {
            ch[i++] = c;
        }

        ch[i] = '\0';


        krek(ch);
    }
    return 0;
}
