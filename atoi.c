#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    // Base case
    if (input[0] == '\0')
    {
        return 0;
    }

    // Get the index of the last char in string
    int last_char = strlen(input);

    // Convert last character into numeric form
    int to_int = input[last_char - 1] - 48;

    // Remove the last char from input
    input[strlen(input) - 1] = input[strlen(input)];

    return to_int + 10 * convert(input);
}