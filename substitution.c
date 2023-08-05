#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Requirements

Make program accept a single command line argument
!! DONE + Check if there's no argument/ is space or blank
!! DONE + Key is case-insensitive
!! DONE + Print "Usage: ./substitution key" AND return 1 when there's input error

Ask user for plaintext

Output ciphertext based on key
+ Each character of plaintext is replaced by corresponding character in key
+ Output reserves character case
+ Output ignores non alphabetical characters
+ Print new line at the end of ciphertext
+ Return 0 in main if program runs successfully

*/

bool key_check(string s);
bool repeated_char(string s);
bool string_isalpha(string s);
char substitute(char c, string key);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (key_check(argv[1]) == 1)
    {
        return 1;
    }

    else
    {
        // Prompt user to enter text
        string plaintext = get_string("plaintext:  ");

        printf("ciphertext: ");

        // Substitute each character in plaintext with corresponding char in key
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            printf("%c", substitute(plaintext[i], argv[1]));
        }
        printf("\n");

        return 0;
    }
}

// Function to check if user enters key correctly
bool key_check(string s)
{
    int output = 0;

    // Check if key contains alphabetical characters
    if (string_isalpha(s) == 1)
    {
        printf("Usage: ./substitution key\n");
        output = 1;
    }

    // Check if key contains 26 characters.
    else if (strlen(s) != 26)
    {
        printf("Key must contain 26 characters.\n");
        output = 1;
    }

    // Check if key do not contain repeated characters
    else if (repeated_char(s) == 1)
    {
        printf("Key must not contain repeated characters.\n");
        output = 1;
    }


    // If key is correctly entered, return 1
    else
    {
        output = 0;
    }
    return output;
}

// Function to check if a char is alphabetical.
// Yes: output = 0 | No: output = 1
bool string_isalpha(string s)
{
    int output;
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            output = 1;
            i = len;
        }
    }
    return output;
}


// Function to look for repeated characters in key
bool repeated_char(string s)

{
    int output;

    // Create an array for 26 alphabet characters in uppercase
    int upper_alpha[26];
    int y = 65;
    for (int x = 0; x < 26; x++)
    {
        upper_alpha[x] = y;
        y++;
    }

    // Convert key to uppercase
    for (int i = 0; i < 26; i++)
    {
        s[i] = toupper(s[i]);
    }

    int count[26];
    int dec_array[26];

    // Convert key to ascii array
    for (int i = 0; i < 26; i++)
    {
        int decimal_val = s[i];
        dec_array[i] = decimal_val;
    }

    // Compare individual key with upper_alpha referece array (upper_alpha)
    for (int j = 0; j < 26; j++)
    {
        int agg = 0;
        for (int i = 0; i < 26; i++)
        {
            if (dec_array[j] == upper_alpha[i])
            {
                agg++;
            }
            else
            {
                agg += 0;
            }
        }

        // Assign occurences of a character's appearance to its corresponding count array position
        // Find the reminder of the decimal interger of a character divided by 65, the add aggregate number to it
        count[dec_array[j] % 65] += agg;
    }


    // Check count array to see if there's a repeated character, the return output
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 1)
        {
            output = 1;
            i = 26;
        }
        else
        {
            output = 0;
        }
    }
    return output;
}



// Function to substitute a char in plaintext with a corresponding char in key
char substitute(char c, string key)
{
    int position = c;
    char subbed;

    if (isalpha(c))
    {
        if (isupper(c))
        {
            position = position % 65;
            subbed = key[position];
            subbed = toupper(subbed);
        }

        if (islower(c))
        {
            position = position % 97;
            subbed = key[position];
            subbed = tolower(subbed);
        }
    }

    else
    {
        subbed = c;
    }
    return subbed;
}