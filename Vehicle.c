
#include <stdio.h>
#include <stdlib.h>

#include "Vehicle.h"

//getRegistration()

//getName()  PROVAVELMENTE DA PA METER O getName de Client em GENERAL E USAR PARA OS 2.

//getType()

//getEngine()

//getHp()

//getFuel()

//getSeats()

//getCurrentState()

//addVehicle()

//modifyVehicle()

//removeVehicle()



void createVehicleFile(Vehicle vehicles[]) {

    FILE *pVehicle = fopen("Vehicle", "w");
    if (pVehicle == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(vehicles, sizeof (Vehicle), VEHICLE_SIZE, pVehicle);
        fclose(pVehicle);
    }
}

Vehicle initVehicleFile(Vehicle vehicles[]) {
    int i;

    for (i = 0; i < VEHICLE_SIZE; i++) {
        vehicles[i].vehicleChars.engine = VEHICLE_INIT_ID;
    }
    return vehicles[VEHICLE_SIZE];
}

 Vehicle readVehicleFile(Vehicle vehicles[]) {

    FILE *pVehicle = fopen("Vehicles", "r");
    if (pVehicle == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createVehicleFile(vehicles);
        vehicles[VEHICLE_SIZE] = initVehicleFile(vehicles);
        saveVehicleFile(vehicles);
        puts("File created");
        readVehicleFile(vehicles);
    } else {
        fread(vehicles, sizeof (Vehicle), VEHICLE_SIZE, pVehicle);
        fclose(pVehicle);
    }
}
 
 void saveVehicleFile(Vehicle vehicles[]) {
    
    FILE *pVehicle = fopen("Vehicles", "w");
    if(pVehicle == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(vehicles, sizeof(Vehicle), VEHICLE_SIZE, pVehicle);
        puts("File saved.");
        fclose(pVehicle);
    }
}
