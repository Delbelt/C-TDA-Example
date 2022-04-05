#ifndef LOCAL_DATE_H_INCLUDED
#define LOCAL_DATE_H_INCLUDED

struct LocalDateStruct; // structure signature

typedef struct LocalDateStruct *LocalDate; // pointer to a structure

LocalDate LocalDate_of(int year, int month, int day); // constructor: date customized

LocalDate LocalDate_now(); // constructor: date current

void LocalDate_ToString(LocalDate localDate); // show date

void validateDateFormat(char date[], int *numberYear, int *numberMonth, int *numberDay); // validate if the date format is load correctly

LocalDate LocalDate_plusYears(LocalDate localDate, int yearsToAdd); // add years to one date
LocalDate LocalDate_plusMonths(LocalDate localDate, int monthsToAdd); // add months to one date
LocalDate LocalDate_plusDays(LocalDate localDate, int daysToAdd); // add days to one date

LocalDate LocalDate_minusYears(LocalDate localDate, int yearsToSubtract); // subtract years to one date
LocalDate LocalDate_minusMonths(LocalDate localDate, int monthsToSubtract); // subtract months to one date
LocalDate LocalDate_minusDays(LocalDate localDate, int daysToSubtract); // subtract days to one date

// getters
int getYear(LocalDate localDate);
int getMonth(LocalDate localDate);
int getDay(LocalDate localDate);

// setters
void setYear(LocalDate localDate, int year);
void setMonth(LocalDate localDate, int month);
void setDay(LocalDate localDate, int day);

void LocalDate_destructor(LocalDate localDate); // free memory

#endif // LOCAL_DATE_H_INCLUDED
