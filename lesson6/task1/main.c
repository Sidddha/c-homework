#include <stdio.h>

void print_digits_rec(int *nums, int i, int len)
{
    printf("%d ", nums[i]);
    if(i < len)
    {
        print_digits_rec(nums, i++, len);
    } else {
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int num1;
    int len;
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

    for(int i = len - 1; i >= 0; i--)
    {
        digits[i] = num1 % 10;
        num1 = num1 / 10;
        printf("%d ", digits[i]);
    }

    print_digits_rec(digits, 0, len);

    return 0;
}