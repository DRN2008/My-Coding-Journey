#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long copy = number;
    int sum = 0;
    int digit_count = 0;
    int first_two_digits = 0;

    // Apply Luhn's algorithm while counting digits and retaining the first two.
    for (int position = 0; copy > 0; position++)
    {
        int digit = copy % 10;
        copy /= 10;
        digit_count++;

        if (copy < 100)
        {
            first_two_digits = copy * 10 + digit;
        }

        if (position % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum += doubled / 10 + doubled % 10;
        }
    }

    if (digit_count == 0 || sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    if (digit_count == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (digit_count == 16 && first_two_digits >= 51 && first_two_digits <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) && first_two_digits / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
