// Задание 1. Сколько раз встречается максимум
// На стандартном потоке ввода задается натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
// На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум.
// Указание: использовать массивы запрещается.

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N = 0;
    printf("Input N:\n");
    scanf("%d", &N);
    int max = 0;
    int current = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &current);
        if(current > max)
        {
            max = current;
            cnt = 1;
        } else if (current == max)
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
