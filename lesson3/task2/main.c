#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[5];
    int min = 0;
    printf("Input five numbers:\n");
    scanf("%d%d%d%d%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);


    for(int i = 0; i < 5; i++) {
        if(min > nums[i])
            min = nums[i];
    }
    printf("%d\n", min);
    return 0;
}