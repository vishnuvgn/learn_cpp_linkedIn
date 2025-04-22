#include <iostream>


bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    }
    if (year % 100 != 0) {
        return true;
    }
    if  (year % 400 != 0) {
        return false;
    }
    return true;
}


int main() {

    int birth_year, birth_month, birth_day;

    std::cout << "Enter your birth year: " << std::flush;
    std::cin >> birth_year;

    std::cout << "Enter your birth month as a number: " << std::flush;
    std::cin >> birth_month;

    std::cout << "Enter your birth day as a number: " << std::flush;
    std::cin >> birth_day;


    time_t now = time(0);
    struct tm tstruct = *localtime(&now);

    int current_day = tstruct.tm_mday;
    int current_month = tstruct.tm_mon + 1;
    int current_year = tstruct.tm_year + 1900;

    const int month_length[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int age = 0;
    int day = birth_day, month = birth_month, year = birth_year;


    while (day != current_day || month != current_month || year != current_year) {
        age++;
        day++;

        if (day > month_length[month - 1]) {
            if (month == 2 && day == 29 && is_leap_year(year)) {
                continue;
            }
            else {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
             
        }



    }

    std::cout << "You are " << age << " days old" << std::endl;


}