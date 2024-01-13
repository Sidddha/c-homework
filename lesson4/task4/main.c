#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int num1, len = 0;
    while (1)
    {
        printf("Input number:\n");
        scanf("%d%n", &num1, &len);
        if(num1 >= 0) {
            break;
        } else {
            printf("Number should be positive!\n");
        }
    }
    int digits[len];

    for(int i = 0; i < len; i++)
    {
        digits[i] = num1 % 10;
        num1 = num1 / 10;
    }
    for(int i = len-1, j = 0; i >=0; i--, j++)
    {
        num1 += digits[i] * pow(10.0, (double)j);
    }
    printf("%d\n", num1);

    return 0;
}