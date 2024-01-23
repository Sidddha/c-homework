#include <stdio.h>

int is_happy_number(int n)
{
    int isHappy = 0;
    int sum = 0;
    int prod = 1;
    while(n / 10 > 0) 
    {
        sum += n % 10;
        prod *= n % 10;
        n = n / 10;
    }
    sum += n;   
    prod *= n;    
    if(sum == prod) isHappy = 1;
    return isHappy;

}

int main(int argc, char const *argv[])
{
    int num1;
    while (1)
    {
        printf("Input number:\n");
        scanf("%d", &num1);
        if(num1 >= 0) {
            break;
        } else {
            printf("Number should be positive!\n");
        }
    }

    printf("%s\n", is_happy_number(num1) ? "YES" : "NO");

    return 0;
}