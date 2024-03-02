#include "temp_functions.h"

bool parse_csv_file(const char *filename, TemperatureReading **readings, int *num_readings) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return false;
    }

    // Read the first line (header) from the file and ignore it
    char header[1024];
    if (!fgets(header, sizeof(header), file)) {
        fprintf(stderr, "Failed to read header from file: %s\n", filename);
        fclose(file);
        return false;
    }

    // Allocate memory for the temperature readings
    *readings = NULL;
    *num_readings = 0;

    while (true) {
        // Resize the array to hold one more temperature reading
        *readings = realloc(*readings, sizeof(TemperatureReading) * (*num_readings + 1));
        if (!*readings) {
            fprintf(stderr, "Failed to allocate memory for temperature readings\n");
            fclose(file);
            return false;
        }

        // Read the next line from the file
        char line[1024];
        if (!fgets(line, sizeof(line), file)) {
            // End of file
            break;
        }

        // Parse the line into a temperature reading
        TemperatureReading *reading = &((*readings)[*num_readings]);
        int n = sscanf(line, "%d;%d;%d;%d;%d;%d",
                       &reading->year, &reading->month, &reading->day,
                       &reading->hour, &reading->minute, &reading->temperature);
        if (n != 6) {
            // Invalid format
            fprintf(stderr, "Invalid format on line %d of file: %s\n", *num_readings + 2, filename);
            continue;
        }

        // Increment the number of temperature readings
        (*num_readings)++;
    }

    fclose(file);
    return true;
}

void free_temperature_readings(TemperatureReading *readings) {
    free(readings);
}

void print_monthly_stats(TemperatureReading *readings, int num_readings, int month) {
    int min_temp = 100;
    int max_temp = -100;
    int total_temp = 0;
    int num_days = 0;

    for (int i = 0; i < num_readings; i++) {
        TemperatureReading *reading = &readings[i];
        if (reading->month == month) {
            min_temp = (reading->temperature < min_temp) ? reading->temperature : min_temp;
            max_temp = (reading->temperature > max_temp) ? reading->temperature : max_temp;
            total_temp += reading->temperature;
            num_days++;
        }
    }

    if (num_days > 0) {
        printf("Monthly statistics for month %d:\n", month);
        printf("  Average temperature: %.2f\n", (double)total_temp / num_days);
        printf("  Minimum temperature: %d\n", min_temp);
        printf("  Maximum temperature: %d\n", max_temp);
    } else {
        printf("No data for month %d\n", month);
    }
}

void print_yearly_stats(TemperatureReading *readings, int num_readings)

{
int min_temp = 100;
int max_temp = -100;
int total_temp = 0;
int num_days = 0;

for (int i = 0; i < num_readings; i++) {
    TemperatureReading *reading = &readings[i];
    min_temp = (reading->temperature < min_temp) ? reading->temperature : min_temp;
    max_temp = (reading->temperature > max_temp) ? reading->temperature : max_temp;
    total_temp += reading->temperature;
    num_days++;
}

printf("Yearly statistics:\n");
printf("  Average temperature: %.2f\n", (double)total_temp / num_days);
printf("  Minimum temperature: %d\n", min_temp);
printf("  Maximum temperature: %d\n", max_temp);

}