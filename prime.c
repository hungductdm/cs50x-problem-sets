#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool prime(int number);

int main(void)
{
    int min;
    // Ensure user enters a Minimum value larger than 0.
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    // Ensure user enters a Maximum value larger than Minimum value entered previously.
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Loop through each interger number between min and max and apply prime function.
    // If prime() returns true, print that number to screen.
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
    
    /* 
    1 is not a prime number and is handled separately as it does not meet the condition i = 2
    of the trial division (the "for" loop) below. Therefore, 1 will return true, which is incorrect.
    */ 
    if (number == 1)
    {
        return false;
    }

    // Trial division between 2 up to square root number (truncated) to check its primality
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
