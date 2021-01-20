#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get name as string
    string name = get_string("What's your name? ");
    // Greet User
    printf("Hello, %s", name);
    printf("\n");
}