#include <stdio.h>
#include "stats.h"

// Функция для подсчета строк, слов и символов  
void count_stats(FILE *file, int *lines, int *words, int *chars) {
    char ch;
    int in_word = 0;

    *lines = *words = *chars = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*chars)++; // Увеличиваем счетчик символов

        if (ch == '\n') {
            (*lines)++; // Увеличиваем счетчик строк  
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            in_word = 0; // Выход из слова
        } else {
            if (in_word == 0) {
                in_word = 1; // Вошли в новое слово  
                (*words)++;  // Увеличиваем счетчик слов  
            }
        }
    }
}
