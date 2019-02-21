#include <stdio.h>

/*
    Other valid stmts
    -- int power(int, int);
    -- int power(int m, int n);
*/
int calc_power(int base, int n);

int main()
{
    // This `i` here not conflicts
    //  with the `i` defined in the `power()`.
    int result, i;

    for (i = 0; i <= 9; ++i)
    {
        result = 3 * i;
        printf("3 ** %d = %5d\n", i, calc_power(3, i));
    }

    return 0;
}

int calc_power(int base, int n)
{
    /*
    About each of those variables
        i, n    kinda like `range(start, end)`
        p       storing computed result
        base    multiple NEEDED times (by `i, n`)

    Also, the the `..(int base, int n)`
        It DOES defines variables | yet a temporary one.
    */

    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
    {
        p *= base;
    }

    return p;
}