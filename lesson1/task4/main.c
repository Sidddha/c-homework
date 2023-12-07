#include <stdio.h>
#include <stdlib.h>
/*
Делать просто соты скучно поэтому я сделал параметрические соты :)
*/
#define UP      " __ "
#define MID     "/  \\"
#define DOWN   "\\__/"
void print_hex_string(int length)
{

    printf("\n");
    for(int i = 0; i < length; i++)    
    {
        if(i % 2 == 0) printf("%s", MID);
        else printf("__");       
    }
    printf("\n");
    for(int i = 0; i < length; i++)
    {
        if(i % 2 == 0) printf("%s", DOWN);
        else printf("  "); 
    }
}

void print_hex_array(int length, int width)
{
    for(int i = 0; i < length; i++)
    {
        if(i % 2 == 0) printf("%s", UP);
        else printf("  ");
    }
    for(int i = 0; i < width; i++)
    {
        print_hex_string(length);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int length = 1;
    int width = 1;
    printf("Input hex array length:\n");
    scanf("%d", &length);
    if(length <= 0)
    {
        printf("Invalid value. Input should be greather then 0.");
        return -1;
    }
    printf("Input hex array width:\n");
    scanf("%d", &width);
    if(width <= 0)
    {
        printf("Invalid value. Input should be greather then 0.");
        return -1;
    }

    print_hex_array(length, width);


    return 0;
}