#include <stdio.h>

/*
This code was NOT written by me.
Here's the link
    github.com/gleesik/The-C-Programming-Language-2nd-Edition-Solutions
*/

#define ALPHA_NR 26
#define NUM_NR 10

int main()
{
    /*
    Just typing the characters randomly.
    No need for 'space', '\n' kind of stuff.

    Since the previous example does requires 
    typing (valid for program) accurate characters.

    For this program, you don't need to do that.
    */

    // Array :: create
    char chars_freq[ALPHA_NR + NUM_NR];
    int i;

    // Array :: initial values
    for (i = 0; i < (ALPHA_NR + NUM_NR); ++i)
    {
        chars_freq[i] = 0;
    }

    // Count chars from stdin
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            // Procedure    Array[index], ++THE_VAL
            // Example      Array['a' - 'a'] => Array[0], ++'a'
            ++chars_freq[c - 'a'];
        }
        else if (c >= '0' && c <= '9')
        {
            // Same as alphabet (+26 to reach the digits' index)
            ++chars_freq[c - '0' + ALPHA_NR];
        }
    }

    // Print the horizontal histogram
    for (i = 0; i < (ALPHA_NR + NUM_NR); ++i)
    {
        // COND
        //  If alphabet | If digits
        // OUTCOME
        //  Simply prining 'a~z' or '1~9'
        if (i < ALPHA_NR)
        {
            printf("%c: ", 'a' + i);
        }
        else if (i >= ALPHA_NR)
        {
            printf("%c: ", '0' + i - ALPHA_NR);
        }

        // Draw the actual freq-chart (using '#')
        int j;
        for (j = 0; j < chars_freq[i]; ++j)
        {
            printf("#");
        }

        // For the next char
        putchar('\n');
    }

    return 0;
}