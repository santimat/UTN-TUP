#include <stdio.h>

char returnDayLetter(int day);
int main()
{
    int num = 0;
    printf("Ingrese el numero de dia del 1 al 7\n");
    scanf("%i", &num);

    char day = returnDayLetter(num);
    printf("%c", day);
    return 0;
}

char returnDayLetter(int day)
{
    switch (day)
    {
    case 1:
        return 'L';
    case 2:
        return 'M';
    case 3:
        return 'X';
    case 4:
        return 'J';
    case 5:
        return 'V';
    case 6:
        return 'S';
    case 7:
        return 'D';
    default:
        return '?';
    }
}