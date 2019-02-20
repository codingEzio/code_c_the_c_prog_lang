#include <stdio.h>

// [Related]
//  METHOD   exercise_count_lines_words_chars_wow
#define IN 1
#define OUT 0

// [Related]
//  METHOD  officialdoc_getchar
//  USED    EXIT_FAILURE, EXIT_SUCCESS
#include <stdlib.h>

int simplest_putchar();
int putchar_while_EOF_v1();
int putchar_while_EOF_v2_simpler();

int count_char_len_v1();
int count_char_len_v2_for();
int count_line_v1();
int count_lines_words_chars_wow();
int count_digits_space_and_others();

int exercise_getchar_return_value_and_EOF();
int exercise_count_blank_tab_newline();
int exercise_replace_multiblank_as_one();
int exercise_replace_tab_as_slashb_and_similar_ones();
int exercise_print_one_word_per_line();

int officialdoc_getchar();

int main()
{
    // simplest_putchar();
    // putchar_while_EOF_v1();
    // putchar_while_EOF_v2_simpler();

    // count_char_len_v1();
    // count_char_len_v2_for();
    // count_line_v1();
    // count_lines_words_chars_wow();
    count_digits_space_and_others();

    // exercise_getchar_return_value_and_EOF();
    // exercise_count_blank_tab_newline();
    // exercise_replace_multiblank_as_one();
    // exercise_replace_tab_as_slashb_and_similar_ones();
    // exercise_print_one_word_per_line();

    // officialdoc_getchar();

    return 0;
}

int simplest_putchar()
{
    int c;

    c = getchar();

    putchar(c);
    printf("%c", c);

    return 0;
}

int putchar_while_EOF_v1()
{
    /*
    What this method does is similar to the `putchar` example (doc).

    Procedure
        TYPE    PRINT   ..
        TYPE    PRINT   ..
        TYPE    PRINT   ..  EOF
    */

    int c;

    c = getchar();

    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }

    return 0;
}

int putchar_while_EOF_v2_simpler()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    return 0;
}

int count_char_len_v1()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
    {
        ++nc;
    }

    // You might need to press 'ctrl + D' twice to exit
    printf("\nTotal len: %ld\n", nc);

    return 0;
}

int count_char_len_v2_for()
{
    // You could still use `int` OR `long` though
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
    {
        ;
    }

    printf("\nTotal len: %.0f\n", nc);

    return 0;
}

int count_line_v1()
{
    int c, nl;

    nl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("\nTotal line len: %d\n", nl);

    return 0;
}

int count_lines_words_chars()
{
    /*
    Issues
        Line count won't be increased 
        unless I explicitly press "Enter" (i.e. an '\n').

    */

    // Input, Counting, State
    int c;
    int nl, nw, nc;
    int state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }

    printf("\n");
    printf("Line : [%2d]\n", nl);
    printf("Word : [%2d]\n", nw);
    printf("Char : [%2d]\n", nc);

    return 0;
}

int count_digits_space_and_others()
{
    /*
    This method counts { digits, spaces, other(alphabets) }.
    
    Expected
        INPUT   a b c 1 1 2 2 (then press 'ctrl + D')
        OUTPUT  Digits = 0220000000, space = 5, other = 3

    Things in output
        0111..  0: 0, 1: 2, 2: 2, .. ..)
        space   space, literally
        other   alphabets, apparently XD
    */

    int c;
    int i;
    int nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
    {
        ndigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        }
        else
        {
            ++nother;
        }
    }

    printf("\n");
    printf("Digits = ");

    for (i = 0; i < 10; ++i)
    {
        printf("%d", ndigit[i]);
    }

    printf(", space = %d, other = %d\n", nwhite, nother);

    return 0;
}

int exercise_getchar_return_value_and_EOF()
{
    int c;

    // 0    EOF (caused by 'ctrl + D')
    // 1    anything except EOF
    c = (getchar() != EOF);
    printf("Returned value: %d\n", c);

    // value of EOF
    printf("\nEOF = %d\n", EOF);

    return 0;
}

int exercise_count_blank_tab_newline()
{
    int c;
    int blank = 0;
    int tabs = 0;
    int newline = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++blank;
        }
        if (c == '\t')
        {
            ++tabs;
        }
        if (c == '\n')
        {
            ++newline;
        }
    }

    printf("\nLEN :: Blank      %d", blank);
    printf("\nLEN :: Tabs       %d", tabs);
    printf("\nLEN :: Newline    %d\n", newline);

    return 0;
}
int exercise_replace_multiblank_as_one()
{
    /*
    This code was NOT written by myself.
    
    Here's the link
    github.com/gleesik/The-C-Programming-Language-2nd-Edition-Solutions
    */

    char c;
    char last_c;

    while ((c = getchar()) != EOF)
    {
        /*
        The basics of '||'
            TF FT TT -> T
            FF       -> F

        That means, 
            if the current char is ' ' (c)
                and the previous char is ' ' (last_c) as well
            
            Then this `if ..` will not executed
                only the `last_c = c` will be exec_ed.
        */
        if (c != ' ' || last_c != ' ')
        {
            printf("1");
            putchar(c);
        }

        // Remember the previous char
        last_c = c;
    }

    return 0;
}

int exercise_replace_tab_as_slashb_and_similar_ones()
{
    /*
    Replace { TAB, BACKSPACE, BACKSLASH, LINEFEED } with its "name".
    */

    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            // This one is actually kinda complicated
            //  just skip this part (no '\b' being printed!).
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else if (c == '\n')
        {
            putchar('\\');
            putchar('n');
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}

int exercise_print_one_word_per_line()
{
    /*
    'hello world'   =>  'hello'
                        'world'
    */

    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar('\n');
        }
        else if (c == '\n')
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}

int officialdoc_getchar()
{
    int ch;
    while ((ch = getchar()) != EOF)
    {
        printf("%c", ch); // Type stuff, print stuff
    }

    if (feof(stdin))
    {
        // Executes when you pressed 'ctrl + D' (cause EOF)
        puts("End of file reached :D");
    }
    else if (ferror(stdin))
    {
        // I can't make this happend (error except EOF)
        perror("getchar()");
        fprintf(stderr, "getchar() failed in file %s at lien # %d\n",
                __FILE__, __LINE__ - 9);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}