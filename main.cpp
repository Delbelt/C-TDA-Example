#include <iostream>
#include <cstring>

// TDA's libraries
#include "bank.h"
#include "customer.h"
#include "local_date.h"

using namespace std;

// definitions

int main()
{
    // create LocalDate for tests
    LocalDate fecha = LocalDate_of(1997, 8, 5);
    LocalDate fechaActual = LocalDate_now();

    LocalDate_ToString(fecha); // expected output: 1997-8-5

    LocalDate_ToString(fechaActual); // expected output: date current in the moment the compilation, format: YEAR-MONTH-DAY

    LocalDate_ToString(LocalDate_plusDays(fecha, 1)); // expected output: 1997-8-6
    LocalDate_ToString(LocalDate_plusMonths(fecha, 1)); // expected output: 1997-9-5
    LocalDate_ToString(LocalDate_plusYears(fecha, 1)); // expected output: 1998-8-5

    LocalDate_ToString(LocalDate_minusDays(fecha, 1)); // expected output: 1997-8-4
    LocalDate_ToString(LocalDate_minusMonths(fecha, 1)); // expected output: 1997-7-5
    LocalDate_ToString(LocalDate_minusYears(fecha, 1)); // expected output: 1996-8-5

    //cout << "" << endl; // new line

    return 0;
}

// implementations
