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
#define NAME_LENGTH 100+1
#define VEHICLE_INIT_ID 0

static const int VEHICLE_SIZE = 10;
static const int ENGINE_MINIMUM = 1;
static const int ENGINE_MAXIMUM = 9999;
static const int HP_MINIMUM = 0;
static const int HP_MAXIMUM = 9999;
static const int SEATS_MINIMUM = 1;
static const int SEATS_MAXIMUM = 20;

typedef enum type {
    CONVERTIBLE, COUPE, SEDAN, LUXURY, SUV, VAN, TRUCK, HYBRID, WAGON
} Type;

typedef enum fuel {
    DIESEL, GASOLINE, GAS, ELECTRIC
} Fuel;

typedef enum currentState {
    A, B
} CurrentState;

typedef struct vehicleChars {
    unsigned short engine;
    unsigned short hp;
    Fuel fuel;
    unsigned short seats;
} VehicleChars;

typedef struct vehicle {
    char registration[REGISTRATION_LENGTH];
    char name[NAME_LENGTH];
    Type type;
    VehicleChars vehicleChars;
    CurrentState currentState;
} Vehicle;

Vehicle initVehicleFile(Vehicle *pVehicles);

void createVehicleFile(Vehicle vehicles[]);

Vehicle readVehicleFile(Vehicle vehicles[]);


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* VEHICLE_H */

