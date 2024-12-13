#include <iostream>


void govno() {
    std::cout << "******************************" << '\n';
    std::cout << " Найти в каждой строке матрицы максимальный элемент." << '\n';
    std::cout << "Выполнил: Козич Арсений Павлович, ГР : 453502" << '\n';
    std::cout << "******************************" << '\n';
}



/*
bool isVowel(char* symbol, int size) {
    // Гласные буквы русского и английского алфавитов
    const char* vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";

    // Проверяем первый символ в массиве
    if (size > 0) {
        unsigned char t = static_cast<unsigned char>(symbol[0]);

        // Перебираем гласные буквы
        for (int i = 0; vowels[i] != '\0'; ++i) {
            if (t == vowels[i]) {
                return true; // Символ найден в списке гласных
            }
        }
    }

    return false; // Не гласная буква
}



void krek(char ch[]) {
    char * p =ch;
    int x = 0;
    for (int i = 0;ch[i] != '\0';) {   if ((ch[i] & 0x80) == 0) {
        if (ch[i] == ' ') {i++;}
        // ASCII символ (1 байт)
        x += 1;
    } else if ((ch[i] & 0xE0) == 0xC0) {
        // 2-байтовый символ
        x += 2;
    } else if ((ch[i] & 0xF0) == 0xE0) {
        // 3-байтовый символ
        x += 3;
    } else if ((ch[i] & 0xF8) == 0xF0) {
        // 4-байтовый символ
        x += 4;
    }
        if (isVowel(p+i,x)==true) {
            int g=i;
            while (ch[g] != '\0' || ch[g]!=0) {
                // Проверяем, какой символ (UTF-8)
                unsigned char c = static_cast<unsigned char>(ch[g]);

                if ((c & 0x80) == 0) {
                    // ASCII символ (1 байт)
                    g += 1; x++;
                } else if ((c & 0xE0) == 0xC0) {
                    // 2-байтовый символ
                    g += 2;x+=2;
                } else if ((c & 0xF0) == 0xE0) {
                    // 3-байтовый символ
                    g += 3;x+=3;
                } else if ((c & 0xF8) == 0xF0) {
                    // 4-байтовый символ
                    g += 4;x += 4;
                } else {
                    // Некорректный символ
                    break;
                }
            }
            if (isVowel(p+i+g-x,x)==true) {
                for (; i <= i+g; i++) {
                    std::cout << ch[i];
                }
                ++i;
                std::cout << "\n";
            }
        }
    }
}*/// Функция для проверки, является ли символ гласной буквой
bool isVowel(char c) {
    // Гласные буквы русского и английского алфавитов
    const char* vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";

    c = std::tolower(static_cast<unsigned char>(c));  // Преобразуем в нижний регистр

    // Перебираем гласные буквы
    while (*vowels) {
        if (*vowels == c) {
            return true;
        }
        vowels++;
    }

    return false;
}

void krek(char ch[]) {
    int start = 0;  // Индекс начала слова
    int i = 0;      // Индекс для текущего символа

    while (ch[i] != '\0') {
        // Пропускаем пробелы и ищем начало следующего слова
        if (ch[i] == ' ') {
            i++;
            continue;
        }

        start = i;  // Запоминаем начало слова

        // Перебираем символы в слове
        while (ch[i] != ' ' && ch[i] != '\0') {
            i++;
        }

        // Проверяем, начинается ли слово с гласной
        if (isVowel(ch[start])) {
            // Проверяем, заканчивается ли слово на гласную
            if (isVowel(ch[i - 1])) {
                // Выводим слово
                for (int j = start; j < i; j++) {
                    std::cout << ch[j];
                }
                std::cout << "\n";
            }
        }
    }
}