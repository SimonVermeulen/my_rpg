/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday06-younes1.bahri
** File description:
** my_putchar.c
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
