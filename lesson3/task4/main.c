#include <stdio.h>
#include <string.h>

int in_range(int num, int min, int max)
{
    int result = 0;
    if((num >= min) && (num <= max)) {
        result = 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int month = 0;
    char season[] = "winter";
    while (1)
    {
        printf("Input month:\n");
        scanf("%d", &month);
        if (month < 1 || month > 12)
            printf("There are 12 monthes in the year. Input correct value.");
        else
            break;
    }

    if (in_range(month, 3, 5))
        strcpy(season, "spring");
    else if (in_range(month, 6, 8))
        strcpy(season, "summer");
    else if (in_range(month, 9, 11))
        strcpy(season, "autumn");

    printf("%s\n", season);
    return 0;
}