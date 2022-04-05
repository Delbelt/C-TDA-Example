#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"
#include "local_date.h"
#include "local_time.h"

using namespace std;

// definitions

int main()
{
    // create LocalDate for tests
    LocalTime time = LocalTime_of(15,30,0);
    LocalTime timeCurrent = LocalTime_now();

    LocalTime_ToString(time); // expected output: 15:30
    LocalTime_ToString(timeCurrent); // expected output: time current in the moment the compilation, format: HOUR:MINUTE:SECOND

    LocalTime_ToString(LocalTime_plusHours(time, 1)); // expected output: 16:30
    LocalTime_ToString(LocalTime_plusMinutes(time, 1)); // expected output: 15:31
    LocalTime_ToString(LocalTime_plusSeconds(time, 15)); // expected output: 15:30:15

    LocalTime_ToString(LocalTime_minusHours(time, 1)); // expected output: 14:30
    LocalTime_ToString(LocalTime_minusMinutes(time, 1)); // expected output: 15:29
    LocalTime_ToString(LocalTime_minusSeconds(time, 0)); // expected output: 15:30

    //cout << "" << endl; // new line

    return 0;
}

// implementations
