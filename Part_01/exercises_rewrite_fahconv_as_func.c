#include <stdio.h>

float celsius_to_fahrenheit(int celsius);

int main()
{
    /*
    Originally I've written my own version.
    
    But I felt the code is pretty dumb, 
    the code here right now is copied from this man
        https://github.com/gleesik
        /The-C-Programming-Language-2nd-Edition-Solutions
    */

    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celsius_to_fahrenheit(celsius);
        printf("%3.0f\t%6.2f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

float celsius_to_fahrenheit(int celsius)
{
    return (9.0 / 5.0) * celsius + 32.0f;
}