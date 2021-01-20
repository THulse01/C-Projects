#include <stdio.h>
#include <cs50.h>

void pyramid(int height);

int main(void)
{
    // Initialise
    int height;

    // Get height if input is between 1-8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Make Pyramid
    pyramid(height);
}

void pyramid(height)
{
    // Repeat {Height} times
    for (int i = 0; i < height; i++)
    {
        // Make space before #
        for (int spc = (height - i); spc > 1; spc--)
        {
            printf(" ");
        }

        // Print #
        for (int hash = 0; hash <= i; hash++)
        {
            printf("#");
        }

        // Spaces in between halves
        printf("  ");

        //Second half of pyramid.
        for (int hash = 0; hash <= i; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}