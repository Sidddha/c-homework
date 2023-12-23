#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[5];
    int len = 0;
    int max = 0;
    printf("Input five numbers:\n");
    scanf("%d%d%d%d%d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);


    for(int i = 0; i < 5; i++) {
        if(max < nums[i])
            max = nums[i];
    }
    printf("%d\n", max);
    return 0;
}