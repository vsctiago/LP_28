/* 
 * File:   Vehicle.h
 * Author: psycku
 *
 * Created on 3 de Fevereiro de 2014, 18:57
 */

#ifndef VEHICLE_H
#define	VEHICLE_H

#include "Utils.h"
#include "General.h"

#define REGISTRATION_LENGTH 8+1
#define REG_FIRSTDASH 2
#define REG_AFIRSTDASH 3
#define REG_SECONDASH 5
#define REG_ASECONDASH 6
#define REG_END 8
#define VEHICLENAME_LENGTH 100+1
#define VEHICLE_INIT_ID 0

static const int VEHICLES_SIZE = 10;
static const int ENG_MINIMUM = 1;
static const int ENG_MAXIMUM = 9999;
static const int HP_MINIMUM = 1;
static const int HP_MAXIMUM = 9999;
static const int SEATS_MINIMUM = 1;
static const int SEATS_MAXIMUM = 9;

typedef enum type {
    CONVERTIBLE = 1, COUPE, HYBRID, LUXURY, SEDAN, SUV, TRUCK, VAN, WAGON
} Type;

typedef enum fuel {
    DIESEL, ELECTRIC, GAS, GASOLINE
} Fuel;

typedef enum currentState {
    A, B
} CurrentState;

typedef struct vehicleChars {
    unsigned short displacement;
    unsigned short hp;
    Fuel fuel;
    unsigned short seats;
} VehicleChars;

typedef struct vehicle {
    char registration[REGISTRATION_LENGTH];
    char name[VEHICLENAME_LENGTH];
    Type type;
    VehicleChars vehicleChars;
    CurrentState currentState;
    bool rentedState;
} Vehicle;

void getRegistration(Vehicle *pVehicles, unsigned short int pos);

void getNameVehicle(Vehicle *pVehicles, unsigned short int pos);

void getType(Vehicle *pVehicles, unsigned short int pos);

void getDisplacement(Vehicle *pVehicles, unsigned short int pos);

void getHp(Vehicle *pVehicles, unsigned short int pos);

void getFuel(Vehicle *pVehicles, unsigned short int pos);

void getSeats(Vehicle *pVehicles, unsigned short int pos);

void getCurrentState(Vehicle *pVehicles, unsigned short int pos);

unsigned short int verifyEmptyVehiclePosition(Vehicle *pVehicles);

void createVehicleFile(Vehicle vehicles[]);

Vehicle initVehicleFile(Vehicle vehicles[]);

Vehicle readVehicleFile(Vehicle vehicles[]);

void saveVehicleFile(Vehicle vehicles[]);

void addVehicle(Vehicle *pVehicles);

//modifyVehicle

//removeVehicle

void listVehicle(Vehicle vehicles[]);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* VEHICLE_H */

