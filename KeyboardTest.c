#include<stdio.h>
#include<curses.h>
int main()
{
    char ch ='k';

    do {
        ch = getch();
        printf("%c", ch);
    }while(ch != 'k');
    return 0;
}
