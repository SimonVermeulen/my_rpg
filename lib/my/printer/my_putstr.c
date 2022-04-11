/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday04-younes1.bahri
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
