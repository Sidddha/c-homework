#include <stdio.h>

int sum_1_to_n(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int num1;
    while (1)
    {
        printf("Input number:\n");
        scanf("%d", &num1);
        if(num1 >= 1) {
            break;
        } else {
            printf("Number should be greather then 0!\n");
        }
    }

    printf("%d\n", sum_1_to_n(num1));

    return 0;
}