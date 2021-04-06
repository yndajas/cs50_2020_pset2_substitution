#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // break if no cipher argument provided (or too many arguments)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // declare cipher length variable
    int cipher_len = strlen(argv[1]);
    
    // break if cipher length is not 26
    if (cipher_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    // break if not all characters are alphabetical
    int invalid_characters = 0;
    
    for (int i = 0; i < cipher_len; i++)
    {
        if (!((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122)))
        {
            invalid_characters++;
        }
    }
    
    if (invalid_characters > 0)
    {
        printf("Key must contain only alphabetical characters.\n");
        return 1;
    }

    // break if duplicate characters
    
    for (int i = 0; i < cipher_len - 1; i++) // check until the penultimate character (the last character has nothing to check against)
    {
        for (int j = i + 1; j < cipher_len; j++) // compare with all characters after the character you're checking
        {
            if (argv[1][i] == argv[1][j]) // if they're the same, break
            {
                printf("Key must not contain duplicate values.\n");
                return 1;
            }
        }
    }
    
    // get string and assign it to string variable plaintext
    string plaintext = get_string("plaintext: ");
    
    // declare text length variable
    int text_len = strlen(plaintext);
    
    // initiate cipher variable
    int cipher[cipher_len];
    
    // convert CLI argument to upper case and add to cipher variable
    for (int i = 0; i < cipher_len; i++)
    {
        cipher[i] = toupper(argv[1][i]);
    }
    
    // initiate ciphertext variable
    int ciphertext[text_len];
    
    // cipher each character (or leave untouched if non-alphabetical) and add it to ciphertext
    for (int i = 0; i < text_len; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90) // if upper case
        {
            // to the right of the assignment operator, the code is getting the integer value of the character from plaintext, subtracting 65 (the start of the upper case alphabet) to get an index at which to find the ciphered character in cipher
            ciphertext[i] = cipher[(int) plaintext[i] - 65];
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122) // if lower case
        {
            // similar to the above, but minus 97 to find the ciphered letter from lower case, then plus 32 to convert it back to lower case
            ciphertext[i] = cipher[(int) plaintext[i] - 97] + 32;
        }
        else // if non-alphabetical
        {
            ciphertext[i] = plaintext[i];
        }
    }
    
    // print text that precedes ciphertext
    printf("ciphertext: ");
    
    // print cipher text
    for (int i = 0; i < text_len; i++)
    {
        printf("%c", ciphertext[i]);
    }
    
    // print new line
    printf("\n");
    
}