/*
В этом задании у меня получилось что если число заканчивается на 0 то 
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int len = 0;
    float avg = 0.0;
    LABLE : printf("Input number:\n");
    scanf("%d%n", &num1, &len);
    if(len < 4) {
        printf("Number should be at least 4 digit\n");
        goto LABLE;
    }

    for(int i = 0; i <= len-1; i++) {
        avg += num1%10;
        num1 /= 10;
    }

     avg /= len*1.0;
    printf("%.2f\n", avg);

    return 0;
}