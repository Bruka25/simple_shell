#include "bk_shell.h"


/**
 *length_ofnum - Counts the length of a given digit
 * 
 *@num: Number to be measured
 *
 *Return: Length of the number
 */
int length_ofnum(int num)
{
        unsigned int num1;
        int len = 1;

        if (num < 0)
        {
                len++;
                num1 = num * -1;
        }
        else
        {
                num1 = num;
        }
        while (num1 > 9)
        {
                len++;
                num1 /= 10;
        }

        return (len);
}
