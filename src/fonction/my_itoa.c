/*
** EPITECH PROJECT, 2022
** my_itoa
** File description:
** convert a number into a string
*/

#include <stdlib.h>

char *my_itoa(int number)
{
    int i = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 12);

    if (str == NULL)
        return (NULL);
    number < 0 ? str[i++] = '-' : 0;
    number < 0 ? number = number * -1 : 0;
    for (; number > 0; i++) {
        str[i] = number % 10 + 48;
        number /= 10;
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        k = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = k;
    }
    return (str);
}
