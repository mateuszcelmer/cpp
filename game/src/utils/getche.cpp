#include <termios.h>
#include <stdio.h>

static struct termios old, a_new;

/* Initialize a_new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old);       /* grab old terminal i/o settings */
    a_new = old;              /* make a_new settings same as old settings */
    a_new.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo)
    {
        a_new.c_lflag |= ECHO; /* set echo mode */
    }
    else
    {
        a_new.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &a_new); /* use these a_new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/* Read 1 character without echo */
char getch(void)
{
    return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
    return getch_(1);
}
