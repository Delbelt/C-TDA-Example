#include <iostream>
#include <cstring>
#include <cstring>
#include <time.h>

#include "local_time.h" // header

struct LocalTimeStruct
{
   int hour;
   int minute;
   int second;
};

LocalTime LocalTime_of(int hour, int minute, int second)
{
    char dateAux[9]; // auxiliary - important: respect the positions of array

    // generate time current for formatted it
    time_t timer = time(NULL);
    struct tm Time = *localtime(&timer);

    // change time value
    Time.tm_hour= hour;
    Time.tm_min= minute;
    Time.tm_sec= second;

    // "%H:%M" format: hours and minutesormatt: year/month/day

    strftime(dateAux, sizeof dateAux, "%H:%M:%S", &Time); // struct localTime to *char (salve in dateAux)

    validateTimeFormat(dateAux, &hour, &minute, &second);

    LocalTime localTime = new LocalTimeStruct; // memory instance

    // variables assignament
    localTime-> hour    = hour;
    localTime-> minute  = minute;
    localTime-> second  = second;

    return localTime;
}

LocalTime LocalTime_now()
{
    char dateAux[9]; // auxiliary - important: respect the positions of array

    // generate time current for formatted it
    time_t timer = time(NULL);
    struct tm Time = *localtime(&timer);

    // "%H:%M" format: hours and minutesormatt: year/month/day

    strftime(dateAux, sizeof dateAux, "%H:%M:%S", &Time); // struct localTime to *char (salve in dateAux)

    int hour, minute, second; // auxiliaries

    validateTimeFormat(dateAux, &hour, &minute, &second);

    LocalTime localTime = new LocalTimeStruct; // memory instance

    // variables assignament
    localTime-> hour    = hour;
    localTime-> minute  = minute;
    localTime-> second  = second;

    return localTime;
}

void LocalTime_ToString(LocalTime localTime)
{
    if(getSecond(localTime) < 1) // in case there aren't seconds values
    {
        printf("\n"); // new line
        printf("%d:%d\n", localTime-> hour, localTime-> minute); // format output
    }

    else // in case there are seconds values
    {
        printf("\n"); // new line
        printf("%d:%d:%d\n", localTime-> hour, localTime-> minute, localTime-> second); // format output
    }
}

void validateTimeFormat(char date[], int *hour, int *minute, int *second)
{
    int index = 0; // loop index

    int hourPosition = 0, minutePosition = 0, secondPosition = 0; // time reference position

    char hourAux[10], minuteAux[10], secondAux[10]; // auxiliary time

    // positions search

    while(index < 11 && hourPosition == 0)
    {
        if(date[index] == ':') // condition: search the first '/' in the char
        {
            hourPosition = index; // add the index value to year
        }

        index ++; // important: increment index value
    }

    index = hourPosition + 1; // value hourPosition assigned to index for search next

    while(index < 11 && minutePosition == 0)
    {
        if(date[index] == ':') // condition: search the second '/' in the char
        {
            minutePosition = index; // add the index value to month
        }

        index ++; // important: increment index value
    }

    for(index = minutePosition + 1; index < 11; index ++)
    {
        secondPosition = index; // add the index value to day
    }

    //  value assign to auxiliaries dependence

    for(index = 0; index < hourPosition; index ++)
    {
        hourAux[index] = date[index]; // assign to year
    }

    for(index = hourPosition + 1; index < minutePosition; index ++)
    {
        minuteAux[index - hourPosition - 1] = date[index];  // assign to month
    }

    for(index = minutePosition + 1; index < secondPosition; index ++)
    {
        secondAux[index - minutePosition - 1] = date[index]; // assign to day
    }

    // casting chars to ints
    *hour = atoi(hourAux);
    *minute = atoi(minuteAux);
    *second = atoi(secondAux);
}

LocalTime LocalTime_plusHours(LocalTime localTime, int hoursToAdd)
{
    return LocalTime_of(getHour(localTime) + hoursToAdd, getMinute(localTime), getSecond(localTime));
}

LocalTime LocalTime_plusMinutes(LocalTime localTime, int minutesToAdd)
{
    return LocalTime_of(getHour(localTime), getMinute(localTime) + minutesToAdd, getSecond(localTime));
}

LocalTime LocalTime_plusSeconds(LocalTime localTime, int secondsToAdd)
{
    return LocalTime_of(getHour(localTime), getMinute(localTime), getSecond(localTime) + secondsToAdd);
}

LocalTime LocalTime_minusHours(LocalTime localTime, int hoursToSubtract)
{
    return LocalTime_of(getHour(localTime) - hoursToSubtract, getMinute(localTime), getSecond(localTime));
}

LocalTime LocalTime_minusMinutes(LocalTime localTime, int minutesToSubtract)
{
    return LocalTime_of(getHour(localTime), getMinute(localTime) - minutesToSubtract, getSecond(localTime));
}

LocalTime LocalTime_minusSeconds(LocalTime localTime, int secondsToSubtract)
{
    return LocalTime_of(getHour(localTime), getMinute(localTime), getSecond(localTime) - secondsToSubtract);
}

int getHour(LocalTime localTime)
{
	return localTime-> hour;
}

int getMinute(LocalTime localTime)
{
	return localTime-> minute;
}

int getSecond(LocalTime localTime)
{
	return localTime-> second;
}

void setHour(LocalTime localTime, int hour)
{
	localTime-> hour = hour;
}

void setMinute(LocalTime localTime, int minute)
{
	localTime-> minute = minute;
}

void setSecond(LocalTime localTime, int second)
{
	localTime-> second = second;
}

void localTime_destructor(LocalTime localTime)
{
    delete localTime;
}
