#include <iostream>


void govno() {
    std::cout << "******************************" << '\n';
    std::cout << " Найти в каждой строке матрицы максимальный элемент." << '\n';
    std::cout << "Выполнил: Козич Арсений Павлович, ГР : 453502" << '\n';
    std::cout << "******************************" << '\n';
}

int find_index(char* str, char* target) {
    int index = -1;

    while (*str) {
        if (strncmp(str, target, strlen(target)) == 0) {
            if ((*str & 0x80) == 0) {
                index++;
            }

        }

        if ((*str & 0x80) == 0) {
            str++;
            index++;
        }

        if ((*str & 0xC0) == 0x70) {
            str += 2;
            index += 2;
        }
    }

    return index;
}



void kek(char ch[], int k) {
    int t = -1;

    // Находим последний пробел до позиции k
    for (int j = k - 1; j >= 0; --j) {
        if (ch[j] == ' ') {
            t = j;
            break;
        }
    }

    if (t == -1) {
        std::cout << "Ошибка ввода, пробел не найден" << std::endl;
        return;
    }

    int b = t;

    // Находим следующее слово (между пробелами)
    while (ch[b] != '\0') {
        // Проверяем, какой символ (UTF-8)
        unsigned char c = static_cast<unsigned char>(ch[b]);

        if ((c & 0x80) == 0) {
            // ASCII символ (1 байт)
            b += 1;
        } else if ((c & 0xE0) == 0xC0) {
            // 2-байтовый символ
            b += 2;
        } else if ((c & 0xF0) == 0xE0) {
            // 3-байтовый символ
            b += 3;
        } else if ((c & 0xF8) == 0xF0) {
            // 4-байтовый символ
            b += 4;
        } else {
            // Некорректный символ
            break;
        }

        // Если встретился пробел, останавливаемся
        if (ch[b] == ' ') {
            break;
        }
    }

    // Выводим строку от t до b
    for (int i = t; i < b; i++) {
        std::cout << ch[i];
    }

    std::cout << "\n";
}