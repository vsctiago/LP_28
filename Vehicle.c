
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

void listVehicle (Vehicle vehicles[]) {
    int i;
    
    for(i=0; i<VEHICLE_SIZE; i++){
        
        if(vehicles[i].vehicleChars.engine == VEHICLE_INIT_ID) {
//            puts(MSG_VEHICLS_NOT_FUND, NEWLINE);
        }else{
         printf("");
         printf("");
        }
            
    }
    
}

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

 /*
 
#include <stdio.h>
#include <stdlib.h>

#include "Vehicle.h"

void getRegistration(Vehicle *vehicle) {


}

//getName()  PROVAVELMENTE DA PA METER O getName de Client em GENERAL E USAR PARA OS 2.

//getType()

//getEngine()

//getHp()

//getFuel()

//getSeats()

//getCurrentState()

int getPositionVehicle(Vehicle vehicles) {

    int i;

    for (i = 0; i < VEHICLE_SIZE; i++) {
        if (vehicles.registration == VEHICLE_INIT_ID)
            return i;
    }
    return EOF;
}

Vehicle addVehicle(Vehicle *vehicles[]) {
    int position;
    position = getPositionVehicle(vehicle[position]);
    if (position == EOF) {
        puts(MSG_VEHICLE_SPACE_FULL, NEWLINE);
    } else {
        getRegistration(&vehicle);

    }

}

//modifyVehicle()

//removeVehicle()

void listVehicle(Vehicle vehicles[]) {
    int i;
<<<<<<< HEAD

    for (i = 0; i < VEHICLE_SIZE; i++) {

        if (vehicles[i].registration == VEHICLE_INIT_ID) {
            puts(MSG_VEHICLE_NOT_FUND, NEWLINE);
        } else {
            printf("");
            printf("");
=======
    
    for(i=0; i<VEHICLE_SIZE; i++){
        
        if(vehicles[i].vehicleChars.engine == VEHICLE_INIT_ID) {
<<<<<<< HEAD
            //puts("MSG_VEHICLS_NOT_FUND", NEWLINE);
=======
            puts("MSG_VEHICLE_NOT_FUND", NEWLINE);
>>>>>>> 4beac7853f7578892b069eb20616885101c89a60
        }else{
         printf("");
         printf("");
>>>>>>> c3bbbfa50f78a872d0ed34aeb95eb35298722382
        }

    }

}

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
<<<<<<< HEAD

void saveVehicleFile(Vehicle *pVehicles) {

=======
 
 void saveVehicleFile(Vehicle vehicles[]) {
    

    FILE *pVehicle = fopen("Vehicles", "w");
    if (pVehicle == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
<<<<<<< HEAD
        fwrite(pVehicles, sizeof (Vehicle), VEHICLE_SIZE, pVehicle);
=======
        fwrite(vehicles, sizeof(Vehicle), VEHICLE_SIZE, pVehicle);
>>>>>>> c3bbbfa50f78a872d0ed34aeb95eb35298722382
        puts("File saved.");
        fclose(pVehicle);
    }
}
*/