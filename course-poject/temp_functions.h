#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureReading;

bool parse_csv_file(const char *filename, TemperatureReading **readings, int *num_readings);
void free_temperature_readings(TemperatureReading *readings);
void print_monthly_stats(TemperatureReading *readings, int num_readings, int month);
void print_yearly_stats(TemperatureReading *readings, int num_readings);

#endif