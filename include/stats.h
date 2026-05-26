#ifndef STATS_H  
#define STATS_H
#include <stdio.h>

// Объявление функций для подсчета  
void count_stats(FILE *file, int *lines, int *words, int *chars);
void count_word_frequency(FILE *file);

#endif
