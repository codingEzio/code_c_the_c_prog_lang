#include <stdio.h>

// Do NOT add semicolon (;) !!
#define LOWER 0
#define UPPER 100
#define STEP 20

int conv_fah_to_cel_v1_type_int();
int conv_fah_to_cel_v2_type_float();
int conv_fah_to_cel_v3_for();
int conv_fah_to_cel_v4_for_define_constant();

int exercise_fah_to_cel_reversed();
int exercise_conv_cel_to_fah();

int main()
{
    // You could concat a long string
    //  using multiple "PART" like Python.
    printf("Yo, what's up\n"
           "and I'm at the 2nd line!\n");

    // conv_fah_to_cel_v1_type_int();
    // conv_fah_to_cel_v2_type_float();
    // conv_fah_to_cel_v3_for();
    conv_fah_to_cel_v4_for_define_constant();

    // exercise_fah_to_cel_reversed();
    // exercise_conv_cel_to_fah();

    return 0;
}

int conv_fah_to_cel_v1_type_int()
{
    int fah, cel;
    int lower, upper, step;

    lower = 0;
    upper = 100; // cel: 37
    step = 20;

    fah = lower;
    while (fah <= upper)
    {
        cel = 5 * (fah - 32) / 9;
        printf("%d\t%d\n", fah, cel);

        fah = fah + step;
    }

    return 0;
}

int conv_fah_to_cel_v2_type_float()
{
    /*
    We're using `float` numbers this time.

    A bit notes about `%d, %f`
        % 6           . 2           f
        % WHOLE_WIDTH . PREICISION  FMT_TYPE
    */

    float fah, cel;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    printf("\n----- Fah to Cel -----\n");

    fah = lower;
    while (fah <= upper)
    {
        cel = (5.0 / 9.0) * (fah - 32.0);
        printf("%3.0f\t%6.2f\n", fah, cel);

        fah = fah + step;
    }
    printf("----- Fah to Cel -----\n\n");

    return 0;
}

int conv_fah_to_cel_v3_for()
{
    int fah;

    for (fah = 0; fah <= 100; fah = fah + 20)
    {
        printf("%3d\t%6.1f\n", fah, (5.0 / 9.0) * (fah - 32));
    }

    return 0;
}

int conv_fah_to_cel_v4_for_define_constant()
{
    int fah;

    for (fah = UPPER; fah <= LOWER; fah = fah - STEP)
    {
        printf("%3d\t%6.1f\n", fah, (5.0 / 9.0) * (fah - 32));
    }

    return 0;
}

int exercise_conv_cel_to_fah()
{
    /*
    This time we'll convert Celsius to Fahrenheit :D 

    Formula
        Fah to Cel         (5.0 / 9.0) * (fah - 32.0)
        Cel to Fah   cel * (9.0 / 5.0) *      + 32.0 
    */

    float cel, fah;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    printf("\n----- Cel to Fah -----\n");

    cel = lower;
    while (cel <= upper)
    {
        fah = cel * (9.0 / 5.0) + 32.0;
        printf("%3.0f\t%6.2f\n", cel, fah);

        cel = cel + step;
    }
    printf("----- Cel to Fah -----\n\n");

    return 0;
}

int exercise_fah_to_cel_reversed()
{
    /*
    Print the temperature in reversed order. (300F to 0F)
    */

    int fah;

    for (fah = 300; fah >= 0; fah = fah - 20)
    {
        printf("%3d\t%6.1f\n", fah, (5.0 / 9.0) * (fah - 32));
    }

    return 0;
}