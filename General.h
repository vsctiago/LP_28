/* 
 * File:   General.h
 * Author: Psycku
 *
 * Created on 30 de Janeiro de 2014, 15:03
 */

#ifndef GENERAL_H
#define	GENERAL_H

#include <string.h>
#include <time.h>

#include "Utils.h"

#define MSG_LIST_TRYOUT "Client POS: %d | id: %lu | Name: %s %c"
#define MSG_LIST_CLIENT "Client id: %lu | Name: %s %c"
#define MSG_LIST_ERROR "No clients found. %c"
#define MSG_ID "Insert ID(10000000-99999999): "
#define MSG_ID_EXIST_ERROR "ERROR: ID already exists. "
#define MSG_ID_ERROR "ERROR: ID invalid. %c"
#define MSG_CLIENTS_FULL_ERROR "ERROR: Can't add more clients. "
#define MSG_CLIENT_ADDED "Client added successfully. "
#define MSG_NAME "Insert name: "
#define MSG_NAME_ERROR "ERROR: Name invalid. "
#define MSG_STREET "Insert street name: "
#define MSG_STREET_ERROR "ERROR: Street name invalid. "
#define MSG_NUMBER "Insert number(1-9999): "
#define MSG_NUMBER_ERROR "ERROR: Number must be between 1 and 9999. "
#define MSG_POSTALCODE "Insert postal code(1111-111): "
#define MSG_POSTALCODE_ERROR "ERROR: Postal code not within limits. "
#define MSG_CITY "Insert city: "
#define MSG_CITY_ERROR "ERROR: City name invalid. "
#define MSG_PHONE "Insert phone number: "
#define MSG_PHONE_ERROR "ERROR: Phone number invalid. (91, 92, 93, 96 or 253"
#define MSG_BIRTHDAY "Insert Birthday. %c"
#define MSG_SIGNUPDATE "Insert Signup date. %c"
#define MSG_DAY "Day: "
#define MSG_DAY_ERROR "ERROR: Day must be between 1 and 31. %c"
#define MSG_MONTH "Month: "
#define MSG_MONTH_ERROR "ERROR: Month must be between 1 and 12. %c"
#define MSG_YEAR "Year: "
#define MSG_YEAR_ERROR "ERROR: Year must be between 1900 and 2100. %c"

//MSG CARRROS
#define MSG_VEHICLE_NOT_FOUND "Vehicle not found. %c"
#define MSG_VEHICLE_SPACE_FULL "Delete one car, before adding another car. %c"
#define MSG_VEHICLE_FEATURES "Vehicle Features. %c" 
#define MSG_REGISTRATION "Insert registration: "
#define MSG_REGISTRATION_ERROR "ERROR: Registration not valid. %c"
#define MSG_VEHICLENAME "Insert vehicle brand and model: "
#define MSG_VEHICLENAME_ERROR "ERROR: Vehicle name not valid. %c"
#define MSG_CARTYPES "CAR TYPES%c1. CONVERTIBLE%c2. COUPE%c3. HYBRID%c4. LUXURY%c"
#define MSG_CARTYPES2 "5. SEDAN%c6. SUV%c7. TRUCK%c8. VAN%c9. WAGON%c"
#define MSG_TYPE "Insert type of car: "
#define MSG_TYPE_ERROR "ERROR: Car type not recognized. %c"
#define MSG_DISPLACEMENT "Insert engine displacement (1-9999cc): "
#define MSG_DISPLACEMENT_ERROR "ERROR: Engine displacement not within limits. %c"
#define MSG_HP "Insert HorsePower(1-9999hp): "
#define MSG_HP_ERROR "ERROR: HP not within limits. %c"
#define MSG_FUEL_TYPES "Fuel types%c1. DIESEL%c2. ELETRIC%c3. GAS%c4. GASOLINE%c"
#define MSG_FUEL "Insert fuel type: "
#define MSG_FUEL_ERROR "ERROR: Fuel type not recognized. %c"
#define MSG_SEATS "Insert seats of cars: "
#define MSG_SEATS_ERROR "ERROR: Seats value not within limits. %c"
#define MSG_CURRENTSTATE "Insert current state of vehicle(A = GOOD | B = BAD): "
#define MSG_CURRENTSTATE_ERROR "ERROR: Current state input not recognized. %c"


#define MSG_FEB_ERROR "ERROR: February only has 28 days. "
#define MSG_DAYS_ON_MONTH_ERROR "ERROR: Month inserted doesn't have 31 days. "
#define MSG_BIRTHDAY_DAY "Insert birthday day: "
#define MSG_BIRTHDAY_MONTH "Insert birthday month: "
#define MSG_BIRTHDAY_YEAR "Insert birthday year: "
#define MSG_SIGNUPDATE_DAY "Insert signup day: "
#define MSG_SIGNUPDATE_MONTH "Insert signup month: "
#define MSG_SIGNUPDATE_YEAR "Insert signup year: "
#define MSG_DATE_ERROR "ERROR: Invalid day, month or year. "
#define DATE_DAY 0
#define DATE_MONTH 1
#define DATE_YEAR 2
#define DATE_SIZE 3

static const int DAY_MINIMUM = 1;
static const int DAY_MAXIMUM = 31;
static const int MONTH_MINIMUM = 1;
static const int MONTH_MAXIMUM = 12;
static const int YEAR_MINIMUM = 1900;
static const int YEAR_MAXIMUM = 2100;

typedef struct tm Date;

unsigned short getDay();

unsigned short getMonth();

unsigned short getYear();

unsigned short getDate();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* GENERAL_H */

