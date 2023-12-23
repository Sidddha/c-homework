#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[3];
    int ascending = 1;
    printf("Input three numbers:\n");
    scanf("%d%d%d", &nums[0], &nums[1], &nums[2]);


    for(int i = 0; i < 2; i++) {
        if(nums[i] > nums[i+1])
            ascending = 0;
    }
    printf("%s\n", ascending ? "YES" : "NO");
    return 0;
}