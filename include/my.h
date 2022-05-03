/*
** EPITECH PROJECT, 2021
** my header
** File description:
** does what it says
*/

#pragma once

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

//MY_LIB
void my_putchar(char c);
bool my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
unsigned int my_put_nbr_uns(unsigned int nb);
int my_put_nbr(int nb);
void my_put_nbr_base(long nb, char *base);
int my_strncmp(char *s1, char *s2, int n);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str);
int my_put_nbr_long(long nb);
void my_free(void *element);
void my_free_array(void **arr);
void *my_realloc(void *ptr, size_t size, size_t old_size);
void *my_calloc(size_t nmemb, size_t size);
void *my_memset(void *dest, int value, size_t len);
void *my_memcpy(void *dest, const void *src, size_t len);
char *my_strsep(char *str, const char *delim, char **saveptr);

//my_printf

int my_printf(const char *format, ...);
void print_char(va_list list);
void print_str(va_list list);
void print_int(va_list list);
void print_uns(va_list list);
void print_pointer(va_list list);
void print_octal(va_list list);
void print_hex(va_list list);
void print_hex_cap(va_list list);
void print_bin(va_list list);
void special_str(va_list list);

typedef struct flag {
    char flag;
    void (*fn)(va_list);
} flag_t;

extern const flag_t FLAGS_FUNC[];
