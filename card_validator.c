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
bool is_checksum_valid(long long num);
bool is_amex(int len, int id);
bool is_mastercard(int len, int id);
bool is_visa(int len, int id);

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
 * Uses two helper functions, get_first_luhn_sum() and get_second_luhn_sum() to implement 
 * the Luhn Algorithm to compute and validate the checksum of a card number.
 *
 * @param num  a number of type long long
 * @return true if last digit of checksum is zero, false otherwise
 */
bool is_checksum_valid(long long num)
{
    int checksum = get_first_luhn_sum(num) + get_second_luhn_sum(num);
    
    // checksum % 10 gives last digit of checksum
    return checksum % 10 == 0
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

/**
 * Checks if card has a valid AmEx number length and id
 *  
 *  Company     |  valid len  |   valid id
 *  ------------+-------------+------------
 *   AmEx       |     15      |    34, 37
 *  
 * @param len  length of card number of type int
 * @param id  card company identifier of type int
 * @return true if len and id have valid values for AmEx, false otherwise
 */
bool is_amex(len, id)
{
	return len == 15 && ( id == 34 || id == 37 )
}

/**
 * Checks if card has a valid MasterCard number length and id
 *  
 *  Company     |  valid len  |      valid id
 *  ------------+-------------+--------------------
 *  MasterCard  |    16       |  51, 52, 53, 54, 55
 *  
 * @param len  length of card number of type int
 * @param id  card company identifier of type int
 * @return true if len and id have valid values for MasterCard, false otherwise
 */
bool is_mastercard(len, id)
{
	return len == 16 && ( id == 51 || id == 52 || id == 53 || id == 54 || id == 55 )
}

/**
 * Checks if card has a valid MasterCard number length and id
 *  
 *  Company     |  valid len  |  valid id
 *  ------------+-------------+-----------
 *   Visa       |   13, 16    |      4
 *  
 * @param len  length of card number of type int
 * @param id  card company identifier of type int
 * @return true if len and id have valid values for Visa, false otherwise
 */
bool is_visa(len, id)
{
    // since all Visa numbers start with 4, we have to check the first of the two digits of id
    return ( len == 13 || len == 16 ) && ( id / 10 == 4 )
}