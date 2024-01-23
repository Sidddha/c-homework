#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1;
    int seeds = 1;
    while (1)
    {
        printf("Input number:\n");
        scanf("%d", &num1);
        if(num1 <= 64 || num1 >= 1) {
            break;
        } else {
            printf("Number should be in range (1; 64)!\n");
        }
    }
    if(num1 > 1) 
    {
        for(int i = 2; i <= num1; i++)
        {
            seeds *= 2;
        }

    }
    printf("%d\n", seeds);

    return 0;
}