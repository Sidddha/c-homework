/*#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
        if (argc < 2) {
        printf("Программа выводит статистику температуры по каждому месяцу и общую статистику за год.\n"
                "Можно вывести статистику отдельно для указанного месяца.\n"
                "Usage: temp_stat [FILE] [OPTION]\n"
                "Example: temp_stat -f temp.csv -m 5\n"
                "\t-f <ﬁlename.csv> входной файл csv для обработки.\n"
                "\t-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц.\n"
                "\t-h вывести данное сообщение и завершить работу.\n"); 
        return 1;
    }
    int rez=0;
    while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
        switch (rez){
            case 'h': 
                printf("Программа выводит статистику температуры по каждому месяцу и общую статистику за год.\n"
                        "Можно вывести статистику отдельно для указанного месяца.\n"
                        "Usage: temp_stat [FILE] [OPTION]\n"
                        "Example: temp_stat -f temp.csv -m 5\n"
                        "\t-f <ﬁlename.csv> входной файл csv для обработки.\n"
                        "\t-m <номер месяца> если задан данный ключ, то выводится только статистика за указанный месяц.\n"
                        "\t-h вывести данное сообщение и завершить работу.\n"); 
                break;
            case 'f': 
                printf("found argument \"b = %s\".\n",optarg);
                break;
            case 'm': 
                printf("found argument \"C = %s\".\n",optarg);
                break;
            case '?': 
                printf("Invalid argument!\n");
                break;
        };
    };
};*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [-h] [-f <filename.csv>] [-m <month>]\n", argv[0]);
        return 1;
    }

    const char *filename = NULL;
    int month = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf("Options:\n");
            printf("  -h              Show this help message\n");
            printf("  -f <filename>   CSV file to process\n");
            printf("  -m <month>      Month to show statistics for (1-12)\n");
            return 0;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            filename = argv[++i];
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            month = atoi(argv[++i]);
            if (month < 1 || month > 12) {
                fprintf(stderr, "Invalid month: %d\n", month);
                return 1;
            }
        } else {
            fprintf(stderr, "Invalid option: %s\n", argv[i]);
            return 1;
        }
    }

    if (!filename) {
        fprintf(stderr, "No input file specified\n");
        return 1;
    }

    TemperatureReading *readings;
    int num_readings;
    if (!parse_csv_file(filename, &readings, &num_readings)) {
        return 1;
    }

    if (month >= 0) {
        print_monthly_stats(readings, num_readings, month);
    } else {
        for (int i = 1; i <= 12; i++) {
            print_monthly_stats(readings, num_readings, i);
        }
        print_yearly_stats(readings, num_readings);
    }

    free_temperature_readings(readings);
    return 0;
}