#include <stdio.h>

/*
This code was NOT written by me.
Here's the link
    github.com/gleesik/The-C-Programming-Language-2nd-Edition-Solutions
*/

#define TRUE 1
#define FALSE 0

#define BUFFER 100

int main()
{
    /*
    I havn't really sort this (copied from someone) solution out.
    */

    int histogram[BUFFER];
    int in = FALSE;
    int newWord = FALSE;
    int i = 0;

    for (i = 0; i <= BUFFER; ++i)
    {
        histogram[i] = 0;
    }

    i = 0;
    int size = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            in = FALSE;

            if (!newWord)
            {
                newWord = TRUE;
                ++histogram[i - 1];

                if (size < i - 1)
                {
                    size = i - 1;
                }

                i = 0;
            }
        }
        else
        {
            in = TRUE;
            newWord = FALSE;
            ++i;
        }
    }

    // Add in the hist array a end of useful data char
    histogram[size + 1] = '$';

    // Print horizontal histogram
    printf("\n\n>>>>>>>>>> <<<<<<<<<<\n Horizontal Histogram\n>>>>>>>>>> <<<<<<<<<<\n");

    i = 0;
    while (histogram[i] != '$')
    {
        printf("%3d: \t", i + 1);

        int j;
        for (j = 0; j < histogram[i]; ++j)
        {
            putchar('#');
        }

        putchar('\n');

        ++i;
    }

    // Print a vertical histogram
    printf("\n<<<<<<<<<< >>>>>>>>>>\n Vertical Histogram\n<<<<<<<<<< >>>>>>>>>>\n");

    int max = size;
    for (max; max >= 0; --max)
    {
        i = 0;

        while (histogram[i] != '$')
        {
            if (max == 0)
            {
                printf("%2d ", i + 1);
            }
            else if (histogram[i] >= max)
            {
                printf("## ");
            }
            else
            {
                printf("   "); // Do NOT use '\t'
            }

            ++i;
        }

        putchar('\n');
    }

    return 0;
}