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