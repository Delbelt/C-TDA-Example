#include <iostream>
#include <cstring>
#include <cstring>
#include <time.h>

#include "local_date.h" // header

struct LocalDateStruct
{
   int year;
   int month;
   int day;
};

LocalDate LocalDate_of(int year, int month, int day)
{
    char dateAux[11]; // auxiliary - important: respect the positions of array

    // generate date current for validate it
    time_t timer = time(NULL);
    struct tm localTime = *localtime(&timer);

    // change date value
    localTime.tm_year = localTime.tm_year - (localTime.tm_year - (year - 1900)); // get year
    localTime.tm_mon = (localTime.tm_mon - localTime.tm_mon) + (month - 1); // get month
    localTime.tm_mday = (localTime.tm_mday - localTime.tm_mday) + day; // get day

    // "%Y/%m/%d" formatt: year/month/day

    strftime(dateAux, sizeof dateAux, "%Y/%m/%d", &localTime); // struct localTime to *char (salve in dateAux)

    LocalDate localDate = new LocalDateStruct; // memory instance

    validateDateFormat(dateAux, &year, &month, &day);

    // variables assignament
    localDate-> year    = year;
    localDate-> month   = month;
    localDate-> day     = day;

    return localDate;
}

LocalDate LocalDate_now()
{
    char dateAux[11]; // auxiliary - important: respect the positions of array

    // generate time current for formatted it
    time_t timer = time(NULL);
    struct tm localTime = *localtime(&timer);

    strftime(dateAux, sizeof dateAux, "%Y/%m/%d", &localTime); // struct localTime to *char (salve in dateAux)

    LocalDate localDate = new LocalDateStruct; // memory instance

    int year, month, day; // auxiliaries

    validateDateFormat(dateAux, &year, &month, &day);

    // variables assignament
    localDate-> year    = year;
    localDate-> month   = month;
    localDate-> day     = day;

    return localDate; // return: date
}

void LocalDate_ToString(LocalDate localDate)
{
    printf("\n"); // new line
    printf("%d-%d-%d\n", getYear(localDate), getMonth(localDate), getDay(localDate)); // format output
}

void validateDateFormat(char date[], int *numberYear, int *numberMonth, int *numberDay)
{
    int index = 0; // loop index

    int yearPosition = 0, monthPosition = 0, dayPosition = 0; // calendar reference position

    char yearAux[10], monthAux[10], dayAux[10]; // auxiliary calendar

    // positions search

    while(index < 11 && yearPosition == 0)
    {
        if(date[index] == '/') // condition: search the first '/' in the char
        {
            yearPosition = index; // add the index value to year
        }

        index ++; // important: increment index value
    }

    index = yearPosition + 1; // value yearPosition assigned to index for search next

    while(index < 11 && monthPosition == 0)
    {
        if(date[index] == '/') // condition: search the second '/' in the char
        {
            monthPosition = index; // add the index value to month
        }

        index ++; // important: increment index value
    }

    for(index = monthPosition + 1; index < 11; index ++)
    {
        dayPosition = index; // add the index value to day
    }

    //  value assign to auxiliaries dependence

    for(index = 0; index < yearPosition; index ++)
    {
        yearAux[index] = date[index]; // assign to year
    }

    for(index = yearPosition + 1; index < monthPosition; index ++)
    {
        monthAux[index - yearPosition - 1] = date[index];  // assign to month
    }

    for(index = monthPosition + 1; index < dayPosition; index ++)
    {
        dayAux[index - monthPosition - 1] = date[index]; // assign to day
    }

    // casting chars to ints
    *numberYear = atoi(yearAux);
    *numberMonth = atoi(monthAux);
    *numberDay = atoi(dayAux);
}

LocalDate LocalDate_plusYears(LocalDate localDate, int yearsToAdd)
{
    return LocalDate_of(getYear(localDate) + yearsToAdd, getMonth(localDate), getDay(localDate));
}

LocalDate LocalDate_plusMonths(LocalDate localDate, int monthsToAdd)
{
    return LocalDate_of(getYear(localDate), getMonth(localDate) + monthsToAdd, getDay(localDate));
}

LocalDate LocalDate_plusDays(LocalDate localDate, int daysToAdd)
{
    return LocalDate_of(getYear(localDate), getMonth(localDate), getDay(localDate) + daysToAdd);
}

LocalDate LocalDate_minusYears(LocalDate localDate, int yearsToSubtract)
{
    return LocalDate_of(getYear(localDate) - yearsToSubtract, getMonth(localDate), getDay(localDate));
}

LocalDate LocalDate_minusMonths(LocalDate localDate, int monthsToSubtract)
{
    return LocalDate_of(getYear(localDate), getMonth(localDate) - monthsToSubtract, getDay(localDate));
}

LocalDate LocalDate_minusDays(LocalDate localDate, int daysToSubtract)
{
    return LocalDate_of(getYear(localDate), getMonth(localDate), getDay(localDate) - daysToSubtract);
}

int getYear(LocalDate localDate)
{
	return localDate-> year;
}

int getMonth(LocalDate localDate)
{
	return localDate-> month;
}

int getDay(LocalDate localDate)
{
	return localDate-> day;
}

void setYear(LocalDate localDate, int year)
{
	localDate-> year = year;
}

void setMonth(LocalDate localDate, int month)
{
	localDate-> month = month;
}

void setDay(LocalDate localDate, int day)
{
	localDate-> day = day;
}

void LocalDate_destructor(LocalDate localDate)
{
    delete localDate;
}
