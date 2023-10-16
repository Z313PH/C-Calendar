#include <stdio.h>
#include <time.h>

// Function to print the header for a month
void printMonthHeader(int month, int year) {
    char* months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    printf("\n-------------------------\n");
    printf("     %s %d\n", months[month - 1], year);
    printf("-------------------------\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
}

// Function to get the day of the week for the first day of a month
int getDayOfWeek(int year, int month) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = 1;
    mktime(&timeinfo);
    return timeinfo.tm_wday;
}

// Function to print a calendar for a specific month
void printMonth(int year, int month) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfWeek, day;
    int i;

    dayOfWeek = getDayOfWeek(year, month);

    printMonthHeader(month, year);

    // Print leading spaces
    for (i = 0; i < dayOfWeek; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (day = 1; day <= daysInMonth[month]; day++) {
        printf("%4d", day);
        if (++dayOfWeek > 6) {
            dayOfWeek = 0;
            printf("\n");
        }
    }

    // Print a newline if the last line is not complete
    if (dayOfWeek != 0) {
        printf("\n");
    }
}

int main() {
    int year;

    // Input the year
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year < 0) {
        printf("Please enter a valid year.\n");
        return 1;
    }

    // Print calendars for each month of the year
    for (int month = 1; month <= 12; month++) {
        printMonth(year, month);
    }

    return 0;
}
