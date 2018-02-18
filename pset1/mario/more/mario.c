#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height;

    // Prompt user to enter a non-negative integer no greater than 23
    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);

    // Iterate through number of columns
    for (int i = 1; i <= height; i++)
    {

        // Create the left half of tower
        // .. populate left row
        for (int j = 1; j <= height; j++)
        {
            if (j <= height - i)
            {
                printf (" ");
            }
            else
            {
                printf ("#");
            }
        }

        // After left tower row created, add a 2 char gap
        printf (" ");
        printf (" ");

        // Create the right half of tower
        // .. populate right row
        for (int j = height; j >= 1; j--)
        {

            if (j > height - i)
            {
                printf ("#");
            }
        }

        printf("\n");
    }

}