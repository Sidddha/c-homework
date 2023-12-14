#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int num2 = 0;
    printf("Input two numbers:\n");
    scanf("%d %d", &num1, &num2);

    int subst = num1-num2;
    printf("%d-%d=%d\n", num1, num2, subst);

    return 0;
}