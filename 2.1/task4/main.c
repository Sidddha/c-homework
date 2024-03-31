// Задание 4. Шифр Цезаря
// На стандартном потоке ввода задается целое неотрицательное число N и последовательность допустимых символов в кодировке ASCII, 
// оканчивающаяся точкой. Допустимые символы – латинские буквы 'a' ... 'z', 'A' ... 'Z' и пробел. 
// Требуется закодировать латинские буквы ('a' ... 'z', 'A' ... 'Z') шифром Цезаря, пробелы вывести без изменения. 
// Число N задает сдвиг в шифре. Шифр Цезаря заключается в следующем преобразовании. Пусть буквы алфавита пронумерованы от 0 до K - 1, 
// где K - число символов в алфавите. Тогда символ с номером n кодируется символом с номером p = (n + N) mod K (mod - операция взятия остатка). 
// На стандартном потоке вывода напечатать зашифрованное сообщение, оканчивающееся точкой. 
// Преобразование требуется выполнять независимо для заглавных и строчных латинских букв.
// Указание: использовать массивы запрещается.
// Данные на входе: Натуральное число N (N > 0), после которого следует
// сообщение.
// Данные на выходе: Зашифрованное сообщение.

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

char caesarEncrypt(char ch, int shift) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = 'A' + (ch - 'A' + shift) % ALPHABET_SIZE;
    } else if (ch >= 'a' && ch <= 'z') {
        ch = 'a' + (ch - 'a' + shift) % ALPHABET_SIZE;
    }
    return ch;
}


// int main(int argc, char const *argv[])
// {
//     uint32_t N = 0;
//     uint32_t result = 0;
//     char  ch = -1;
//     char * pch = &ch;
//     printf("Input N:\n");
//     scanf("%u", &N);
//     getchar();
//     while(1)
//     {
//         *pch = getchar();
//         // scanf("\n%c", pch);
//         if(*pch == '\n') continue;
//         if (isalpha(*pch) || isspace(*pch)) {
//             if(!isspace(*pch))
//             {
//                 *pch = caesarEncrypt(*pch, (char)N);
//             }
//             // printf("\tptr = %c\n", *(pch));
//             // printf("\tptr = %d\n", *(pch));
            
//             pch++;
//         }
//         if (*pch == '.') break;
//     }
//     pch = &ch;
//     while(1)
//     {
//         if(*pch == '.')
//         {
//             printf(".\n");
//             break;
//         }
//         putchar(*pch);
//         pch++;
//     }
//     return 0;
// }

int main(int argc, char const *argv[])
{
    uint32_t N = 0;
    char *input = NULL;
    char *pch = NULL;
    size_t bufsize = 0;

    printf("Input N:\n");
    scanf("%u", &N);
    getchar(); // consume newline character

    printf("Input text (up to 1023 characters):\n");

    // Encrypt input characters and store them in a separate buffer
    size_t outsize = strlen(input) + 1;
    char *output = (char *) malloc(outsize);
    char *pout = output;
    pch = input;
    while ((*pch != '\0') || (*pch != '.') ) {
    *input = getchar();
        if (isalpha(*pch) || isspace(*pch)) {
            if (!isspace(*pch)) {
                *pout = caesarEncrypt(*pch, N);
            }
            pout++;
        }
        pch++;
    }
    *pout = '\0'; // null-terminate output buffer

    // Print encrypted output
    printf("Encrypted text:\n%s\n", output);

    // Free allocated memory
    free(output);
    free(input);

    return 0;
}