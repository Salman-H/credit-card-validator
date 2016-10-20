/**
 * Prompts the user for a credit card number and then reports (via printf)
 * whether it is a valid American Express, MasterCard, or Visa card number.
 * @author Salman Hashmi
 */
#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* function prototypes */
int get_length(long long num);
int get_identifier(long long num, int len);

int main(void)
{
	return 0;
}

/**
 * Computes length of a whole number 
 * @param num  a number of type long long
 * @return length of num
 */ 
int get_length(long long num)
{
    // ceil returns the smallest int >= log10(num) e.g. ceil(log10(4510)) = ceil(3.6) = 4
    return ceil(log10(num));
}

/**
 * computes the first 2 digits of a whole number
 * @param num  a number of type long long
 * @param len  length of this number of type int
 * @return the first 2 digits of this number
 */ 
int get_identifier(long long num, int len)
{
    // Example:  4510 / 10^(4-2) = 45
    return num / (long long) pow(10, len - 2);
}