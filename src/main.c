#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <имя_файла>\n", argv[0]);
        return EXIT_FAILURE; // Если файл не указан, выходим с ошибкой  
    }

    FILE *file = fopen(argv[1], "r");
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

    return EXIT_SUCCESS;
}
