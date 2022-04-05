#ifndef LOCAL_TIME_H_INCLUDED
#define LOCAL_TIME_H_INCLUDED

struct LocalTimeStruct; // structure signature

typedef struct LocalTimeStruct *LocalTime; // pointer to a structure

LocalTime LocalTime_of(int hour, int minute, int second); // constructor: time customized

LocalTime LocalTime_now(); // constructor: time current

void LocalTime_ToString(LocalTime localTime); // show time

void validateTimeFormat(char date[], int *hour, int *minute, int *second); // validate if the time format is load correctly

LocalTime LocalTime_plusHours(LocalTime localTime, int hoursToAdd); // add hours to time
LocalTime LocalTime_plusMinutes(LocalTime localDate, int minutesToAdd);// add minutes to time
LocalTime LocalTime_plusSeconds(LocalTime localTime, int secondsToAdd);// add seconds to time

LocalTime LocalTime_minusHours(LocalTime localTime, int hoursToSubtract); // subtract hours to time
LocalTime LocalTime_minusMinutes(LocalTime localTime, int minutesToSubtract); // subtract minutes to time
LocalTime LocalTime_minusSeconds(LocalTime localTime, int secondsToSubtract); // subtract seconds to time

// getters
int getHour(LocalTime localTime);
int getMinute(LocalTime localTime);
int getSecond(LocalTime localTime);

// setters
void setHour(LocalTime localTime, int hour);
void setMinute(LocalTime localTime, int minute);
void setSecond(LocalTime localTime, int second);

// destroyer
void localTime_destructor(LocalTime localTime); // free memory

#endif // LOCAL_TIME_H_INCLUDED
