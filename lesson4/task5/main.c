#include <stdio.h>
#include <math.h>

int sum_of_digits(int num)
{
    int sum = 0;
    while(num / 10 > 0) 
    {
        sum += num % 10;
        num = num / 10;
    }
    sum += num;
    return sum;
}

int prod_of_digits(int num)
{
    int prod = 1;
    while(num / 10 > 0) 
    {
        prod *= num % 10;
        num = num / 10;
    }
    prod *= num;
    return prod;
}

int main(int argc, char const *argv[])
{
    int num1, len = 0, sum = 0, prod = 0;
    while (1)
    {
        printf("Input number:\n");
        scanf("%d%n", &num1, &len);
        if(num1 > 10) {
            break;
        } else {
            printf("Number should be graether then 10!\n");
        }
    }

    int index = 0;
    int number = 10;
    while(number <= num1){
        if(sum_of_digits(number) == prod_of_digits(number))
        {
            index++;
        }
        number++;

    }

    int luckyDigitsArray[index];
    index = 0;
    number = 10;
    while(number <= num1){
        if(sum_of_digits(number) == prod_of_digits(number))
        {
            luckyDigitsArray[index] = number;
            index++;
        }
        number++;
    }
    int size = sizeof(luckyDigitsArray) / sizeof(luckyDigitsArray[0]);
    for(int i = 0; i < size; i++)
    {
        printf("%d ", luckyDigitsArray[i]); 
    }
    printf("\n");

    return 0;
}