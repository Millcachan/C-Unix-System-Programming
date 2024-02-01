/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef MY_H
    #define MY_H

    #define SUCCESS 0
    #define ERROR 84
    #define HELP 42

int my_is_prime(int nb);
int my_isnum(char *str);
int my_strlen(char *str);
int my_prime_sup(int nb);
int my_isneg(long long n);
int my_isalpha(char *str);
int my_islower(char *str);
int my_isupper(char *str);
int my_square_root(int nb);
char *my_revstr(char *str);
char *my_strdup(char const *src);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_isalphanumeric(char c);
int my_isprintable(char *str);
int my_putchar(char c, int fd);
long long my_getnbr(char *str);
char *my_strlowcase(char *str);
int my_putstr(char *str, int fd);
int my_strcmp(char *s1, char *s2);
char *my_strcapitalize(char *str);
void my_puttab(char **tab, int fd);
int my_putnbr(long long nbr, int fd);
int word_position(char *str, int pos);
char **my_str_to_word_array(char *str);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);
int my_strncmp(char *s1, char *s2, int n);
char *my_strstr(char *str, char *to_find);
void my_sort_int_array(int *tab, int size);
long long my_power_rec(long long nb, int p);
int len_word(char *str, int pos, int isalpha);
char *my_strncpy(char *dest, char *src, int n);
char *my_strncat(char *dest, char *src, int nb);

#endif
