/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** copy n characters of a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
