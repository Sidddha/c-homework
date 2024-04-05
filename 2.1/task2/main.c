// Задание 2. Инверсия старших
// На вход программе подается беззнаковое 32-битное целое число N. 
// Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.
// Данные на входе: Беззнаковое 32-битное целое число N
// Данные на выходе: Одно целое число.

#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    uint32_t N = 0;
    uint8_t mask;
    printf("Input N:\n");
    scanf("%d", &N);
    mask = ~(N >> 24);
    for(int i = 24; i < 32; i++)
    {
        N &= ~(1 << i);
    }
    N |= mask << 24; 
    printf("%u\n", N);

    return 0;
}