#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int e;
    int years;

    // Prompt for start size
    do
    {
        n = get_int("Start Size: ");
    }
    while (n < 9);
    do
    {
        e = get_int("End Size: ");
    }
    while (e < n);

    // Calculate number of years until we reach threshold
    int count = 0;

    // Output 0 if n and e are the equal

    if (e == n)
    {
        count = 0;
    }
    else
    {
        do
        {
            int born = n / 3;
            int die = n / 4;
            n = (n + born) - die;
            count++;
        }
        while (n < e);
    }

    // Print number of years
    printf("Years: %i\n", count);
}