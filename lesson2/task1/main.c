#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    printf("Input three numbers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1+num2+num3;
    printf("%d+%d+%d=%d\n", num1, num2, num3, sum);

    return 0;
}