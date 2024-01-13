#include <stdio.h>


int main(int argc, char const *argv[])
{
    int num1, len = 0;
    int even = 1;
    printf("Input number:\n");
    scanf("%d%n", &num1, &len);
    for(int i = 0; i < len; i++)
    {
        if((num1 % 10) % 2 == 0)
        {
            num1 = num1 / 10;
            continue;
        } else {
            even = 0;
            break;
        }
    }

    even ? printf("YES\n") : printf("NO\n");


    return 0;
}