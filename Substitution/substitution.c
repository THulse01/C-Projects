#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/*
    plaintext:
    ciphertext:
    +32 between capital to lower
*/

int main(int argc, string argv[])
{
    // Check Correct Command arguments.
    if (argc != 2)
    {
        printf("Usage: ./substitution [KEY]\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Your key must have 26 characters.\n");
        return 1;
    }

    // Check for Invalid chars in key & Lowercase key
    string key = argv[1];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
        {
            key[i] = tolower(key[i]);
        }
        else
        {
            printf("Non A-Z or a-z char detected.\n");
            return 1;
        }
    }

    // Check for Duplicate Values in Key
    int count;
    string keycopy = argv[1];
    for (int i = 0, n = strlen(keycopy); i < n; i++)
    {
        count = 1;
        for (int e = i + 1; e < strlen(keycopy); e++)
        {
            if (keycopy[i] == keycopy[e] && keycopy[i] != ' ')
            {
                count++;
                keycopy[0] = '0';
            }
        }
        if (count > 1 && keycopy[i] != '0')
        {
            return 1;
        }
    }

    // Get Variables Ready for Cipher
    string msg = get_string("plaintext: ");
    char temp[strlen(msg)];

    // Switch to Lower Case to handle upper case key chars
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = tolower(key[i]);
    }

    // Cipher Msg
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        // Switch chars between a - z
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            temp[i] = key[msg[i] - 'a'];
        }
        // Switch chars between A - Z
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            temp[i] = toupper(key[msg[i] - ('A') ]);
        }
        // Keep other chars
        else
        {
            temp[i] = msg[i];
        }
    }
    temp[strlen(msg)] = '\0';

    // Print Ciphertext to user
    printf("ciphertext: %s\n", temp);
}