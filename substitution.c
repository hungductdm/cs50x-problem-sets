#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Requirements

Step 1: Make program accept a single command line argument
+ Check if there's no argument or argument is space(s) or blank
+ Key is case-insensitive.
+ Print "Usage: ./substitution key" AND return 1 when there's input error

Step 2: Ask user for plaintext

Step 3: Output ciphertext based on key
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
    // Check if there's only one command line argument.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Run custom function to check if user entered the correct "key"
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
/* METHOD
- Convert individual characters of key into decimal format (ASCII table) and store them into a new array: dec_array[] 
- Compare each element of dec_array against an ordinary alphabet also in decimal: upper_alpha[]
    + If there's a match, store the number of times that character is repeated into a new array named count[].
    + If count[] contains any element other than 1, there's a repeated character OR a character in the alphabet is missing.
    + If all 26 elements of count[] array is 1, the key is entered correctly. Key in this case contains all 26 unique characters of the alphabet.
*/
bool repeated_char(string s)

{
    int output;

    // Create a reference array for 26 alphabet characters in uppercase
    // This array contains the 26 ordinary alphabet characters in decimal type (refer to ASCII table)
    int upper_alpha[26];
    int y = 65;
    for (int x = 0; x < 26; x++)
    {
        upper_alpha[x] = y;
        y++;
    }

    // Convert all characters in key to uppercase
    for (int i = 0; i < 26; i++)
    {
        s[i] = toupper(s[i]);
    }

    int count[26];
    int dec_array[26];

    // Convert all characters in key to decimal type (refer to ASCII table), then assign to dec_array array
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


    // Check count array to see if there's a repeated or missing character, the return output
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
