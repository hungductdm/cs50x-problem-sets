#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    if (number == 1)
    {
        return false;
    }

    // Trial division between 2 up to square root number (truncated) to check its primality
    for (int i = 2; i <= (number / 2); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
