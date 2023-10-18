#include "bk_shell.h"

/**
 *itoa - An integer to a string converter
 *
 *@num: Integer to be converted
 *
 *Return: Converted str
 */
char *_itoa(int num)
{
        char *buffer;
        int len = length_ofnum(num);
        unsigned int num1;

        buffer = malloc(sizeof(char) * (len + 1));
        if (!buffer)
                return (NULL);

        buffer[len] = '\0';

        if (num < 0)
        {
                num1 = num * -1;
                buffer[0] = '-';
        }
        else
        {
                num1 = num;
        }

        len--;
        do {
                buffer[len] = (num1 % 10) + '0';
                num1 /= 10;
                len--;
        } while (num1 > 0);

        return (buffer);
}
