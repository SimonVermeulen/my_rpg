/*
** EPITECH PROJECT, 2021
** B-CPE-100-TLS-1-1-cpoolday03-younes1.bahri
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

void print_number(int n)
{
    int i;

    if (n > 0) {
        i = n % 10;
        n = n / 10;
        print_number(n);
        my_putchar(48 + i);
    }
}

void print_min_int(void)
{
    int max = 147483648;

    my_putchar('-');
    my_putchar('2');
    print_number(max);
}

int verify_min_int(int number)
{
    if (number == -2147483648) {
        print_min_int();
        return 0;
    }
    return 1;
}

int my_put_nbr(int number)
{
    int min = verify_min_int(number);

    if (number < 0 && min == 1) {
        my_putchar('-');
        number = number * -1;
    }
    if (number == 0)
        my_putchar('0');
    if (min == 1)
        print_number(number);
    return 0;
}
