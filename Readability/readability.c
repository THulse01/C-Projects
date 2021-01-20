#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>

/*
    Get String

    0.0588
    * L (Avg num of letters per 1oo words)
    * S (Avg num of sentences per 100 words)

    Grade X
    Grade 16+
    Before Grade 1
    */

int main(void)
{

    // User Input
    string msg = get_string("Text: ");

    // Initialise Variables
    int sentences = 0;
    int letters = 0;
    int words = 1;
    int tempcount = 0;

    // Get sentence, word & letter count
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        if ((msg[i] >= 'a' && msg[i] <= 'z') || (msg[i] >= 'A' && msg[i] <= 'Z'))
        {
            letters++;
        }
        else if (msg[i] == ' ')
        {
            words++;
        }
        else if (msg[i] == '.' || msg[i] == '?' || msg[i] == '!')
        {
            sentences++;
        }
    }

    // Get Multiplier ready
    float mult = 100 / (float) words;

    // Get avg num of letters & sentences per 100 words
    float lper = letters * mult;
    float sper = sentences * mult;
    float ans1 = 0.0588 * lper - 0.296 * sper - 15.8;
    int ans = round(ans1);

    // Print Grade
    if (ans < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ans > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", ans);
    }

}