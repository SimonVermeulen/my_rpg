/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a double from the given buff
*/

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "linked_list.h"
#include "json_parser.h"
#include "my.h"

static int get_nb(const char *buff, int index, double *result)
{
    int len = 0;

    for (; buff[len] &&
        (is_number(buff[len]) || buff[len] == '.' || buff[len] == '-');
        len++);
    result[index] = atof(buff);
    return (len);
}

static int get_double_array(const char *buff, int nb_elements, double *result)
{
    int len = 0;

    for (int i = 0; i < nb_elements; i++) {
        len += get_nb(&buff[len], i, result);
        if (buff[len] && buff[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        } else if (i != nb_elements - 1) {
            len++;
        }
    }
    return (len);
}

int get_double(const char *buff, node_t *new_node, int nb_elements)
{
    int len = 0;
    double *result = NULL;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    result = malloc(sizeof(double) * (new_node->len));
    if (!result)
        return (-1);
    if (nb_elements == 0)
        len = get_nb(buff, 0, result);
    else
        len = get_double_array(buff, nb_elements, result);
    new_node->value = result;
    new_node->len = (nb_elements == 0) ? 0 : nb_elements;
    return (len);
}
