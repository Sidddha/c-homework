#include <stdio.h>


int main(int argc, char const *argv[])
{
    int num1, num2, sum = 0;

    while(1) {
        printf("Input two numbers:\n");
        scanf("%d%d", &num1, &num2);
        if((num1 > 100 || num1 < -100) || (num2 > 100 || num2 < -100) || num2 < num1) {
            printf("Invalid input. numbers should be in range (-100:100)");
        } else {
            break;
        }
    }


    for(int i = num1; i <= num2; i++) {
        sum += i * i;
    }
    printf("%d\n", sum);
    return 0;
}