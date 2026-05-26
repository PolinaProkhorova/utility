#include <stdio.h>
#include <string.h> 
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

// НОВАЯ функция для подсчета частоты встречаемости слов
void count_word_frequency(FILE *file) {
    char words_list[500][50]; // Уникальные слова
    int counts[500] = {0};     // Количества повторений
    int unique_count = 0;      // Счетчик уникальных слов
    char current_word[50];     // Текущее слово

    // Читаем файл
    while (fscanf(file, "%49s", current_word) == 1) {
        int found = 0;
        for (int i = 0; i < unique_count; i++) {
            if (strcmp(words_list[i], current_word) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // Добавляем слово с список
        if (found == 0 && unique_count < 500) {
            strcpy(words_list[unique_count], current_word);
            counts[unique_count] = 1;
            unique_count++;
        }
    }

    printf("\nЧастота встречаемости слов:\n");
    for (int i = 0; i < unique_count; i++) {
        printf("%s: %d\n", words_list[i], counts[i]);
    }
}
