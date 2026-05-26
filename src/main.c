#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "stats.h"

int main(int argc, char *argv[]) {
    char manual_filename[256];
    char *filename;

    if (argc == 2) {
        filename = argv[1];
    } else {
        printf("Имя файла не указано при запуске.\n");
        printf("Введите имя файла: ");
        scanf("%255s", manual_filename);
        filename = manual_filename;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return EXIT_FAILURE; // Если файл не удалось открыть, выходим с ошибкой  
    }

    int lines, words, chars;
    count_stats(file, &lines, &words, &chars); // Вызываем функцию подсчета

    fclose(file); // Закрываем файл

    // Выводим результаты  
    printf("Строки: %d\n", lines);
    printf("Слова: %d\n", words);
    printf("Символы: %d\n", chars);

    // Открываем файл заново для функции частоты слов
    file = fopen(filename, "r");
    if (file != NULL) {
        count_word_frequency(file);
        fclose(file);
    }

    return EXIT_SUCCESS;
}
