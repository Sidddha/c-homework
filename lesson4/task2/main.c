#include <stdio.h>


int main(int argc, char const *argv[])
{
    int num1, len = 0;

    printf("Input number:\n");
    scanf("%d%n", &num1, &len);
    len == 3 ? printf("YES\n") : printf("NO\n");
    return 0;
}