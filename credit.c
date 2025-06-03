#include <cs50.h>
#include <stdio.h>

int length(long card_number);
int first_digits(long card_number);
long get_number(void);
int first_sum(long card_number);
int second_sum(long card_number);
void checksum(long card_number);

int main(void)
{
    // Getting user credit card input
    long card_number = get_number();
    checksum(card_number);
}

// Ask for a credit card number input
long get_number(void)
{
    long number = get_long("Credit Card Number: ");
    return number;
}

// Adding sum of every other digit multiplied by 2.
int first_sum(long card_number)
{
    int sum1 = 0;
    for (long i = card_number / 10; i > 0; i = i / 100)
    {
        int digit = (i % 10) * 2;
        if (digit < 10)
        {
            sum1 = sum1 + digit;
        }
        else
        {
            sum1 = sum1 + (digit % 10) + (digit / 10);
        }
    }
    return sum1;
}

// Adding sum of every other digit starting from the last
int second_sum(long card_number)
{
    int sum2 = 0;
    for (long i = card_number; i > 0; i = i / 100)
    {
        sum2 = sum2 + (i % 10);
    }
    return sum2;
}

// Checking sum
void checksum(long card_number)
{
    int sum1 = first_sum(card_number);
    int sum2 = second_sum(card_number);
    int sum3 = sum1 + sum2;

    int card_length = length(card_number);
    int digits = first_digits(card_number);

    if (sum3 % 10 == 0)
    {
        if (card_length == 15 &&
            (digits == 34 || digits == 37))
        {
            printf("AMEX\n");
        }
        else if (card_length == 16 &&
                 (digits == 51 || digits == 52 ||
                  digits == 53 || digits == 54 ||
                  digits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if (digits == 4 &&
                 (card_length == 13 || card_length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int length(long card_number)
{
    int counter = 0;
    for (long i = card_number; i > 0; i = i / 10)
    {

        counter++;
    }
    return counter;
}

int first_digits(long card_number)
{
    long i = card_number;
    for (; i >= 100; i = i / 10)
        ;
    if (i / 10 == 4)
    {
        return 4;
    }
    else
    {
        return (int) i;
    }
}
