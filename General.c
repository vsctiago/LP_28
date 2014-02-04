
#include <stdio.h>
#include <stdlib.h>

#include "General.h"
#include "Client.h"

unsigned short getDay() {
    bool val = false;
    unsigned short day;
    
    do {
        printf(MSG_DAY);
        scanf("%hu", &day);
        if(day >= DAY_MINIMUM && day <= DAY_MAXIMUM) {
            val = true;
        } else {
            printf(MSG_DAY_ERROR, NEWLINE);
        }
    } while(val == false);
    
    return day;
}

unsigned short getMonth() {
    bool val = false;
    unsigned short month;
    
    do {
        printf(MSG_MONTH);
        scanf("%hu", &month);
        if(month >= MONTH_MINIMUM && month <= MONTH_MAXIMUM) {
            val = true;
        } else {
            printf(MSG_MONTH_ERROR, NEWLINE);
        }
    } while(val == false);
    
    return month;
}

unsigned short getYear() {
    bool val = false;
    unsigned short year;
    
    do {
        printf(MSG_YEAR);
        scanf("%hu", &year);
        if(year >= YEAR_MINIMUM && year <= YEAR_MAXIMUM) {
            val = true;
        } else {
            printf(MSG_YEAR_ERROR, NEWLINE);
        }
    } while(val == false);
    
    return year;
}

// TODO: VALIDATION FOR BISIX YEARS
unsigned short getDate() {
    bool val = false;
    unsigned short date[DATE_SIZE];
        
    do {
        printf(MSG_DAY);
        scanf("%hu", &date[DATE_DAY]);
        printf(MSG_MONTH);
        scanf("%hu", &date[DATE_MONTH]);
        printf(MSG_YEAR);
        scanf("%hu", &date[DATE_YEAR]);
        if(date[DATE_DAY] >= DAY_MINIMUM && date[DATE_DAY] <= DAY_MAXIMUM){
            if(date[DATE_MONTH] >= MONTH_MINIMUM && date[DATE_MONTH] <= MONTH_MAXIMUM) {
                if(date[DATE_DAY] > 28 && date[DATE_MONTH] == 2){
                    printf(MSG_FEB_ERROR);
                    printf("%c", NEWLINE);
                    val = false;
                } else if(date[DATE_DAY] == 31 && date[DATE_MONTH] != 1 && date[DATE_MONTH] != 3
                        && date[DATE_MONTH] != 5 && date[DATE_MONTH] != 7 && date[DATE_MONTH] != 8
                        && date[DATE_MONTH] != 10 && date[DATE_MONTH] != 12){
                    printf(MSG_DAYS_ON_MONTH_ERROR);
                    printf("%c", NEWLINE);
                    val = false;
                } else {
                    if(date[DATE_YEAR] >= YEAR_MINIMUM && date[DATE_YEAR] <= YEAR_MAXIMUM){
                        val = true;
                    }
                }
            } else {
                printf(MSG_MONTH_ERROR, NEWLINE);
            }
        } else {
            printf(MSG_DAY_ERROR, NEWLINE);
            printf("%c", NEWLINE);
        }
    } while(val == false);
    
    return date[DATE_SIZE];
}

