#include <stdio.h>

int nod(int a, int b)
{
    int nod, min;
    (a < b) ? (min = a) : (min = b);
    for(int i = 1; i <= min; i++)
    {
        if((a % i == 0) && (b % i == 0)) nod = i;
    }
    return nod;
}

int main(int argc, char const *argv[])
{
    int num1, num2;
    while (1)
    {
        printf("Input two positive numbers:\n");
        scanf("%d%d", &num1, &num2);
        if(num1 <= 0 || num2 <= 0) {
            printf("Number should be greather then 0!\n");
        } else {
            break;
        }
    }
    printf("%d\n", nod(num1, num2));

    return 0;
}