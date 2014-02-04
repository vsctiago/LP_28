
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vehicle.h"
#include "Menu.h"
#include "Utils.h"

void getRegistration(Vehicle *pVehicles, unsigned short int pos) {
    bool val = false;
    char registration[REGISTRATION_LENGTH];
    unsigned short i;
    
    do {
        printf(MSG_REGISTRATION);
        lerFrase(registration, REGISTRATION_LENGTH);
        if(registration[REG_FIRSTDASH] != '-'
                && registration[REG_SECONDASH] != '-') {
            printf(MSG_REGISTRATION_ERROR, NEWLINE);
            val = false;
        } else {
            for(i=0; i<REG_FIRSTDASH; i++) {
                if(isdigit(registration[i])) {
                    val = true;
                } else {
                    printf(MSG_REGISTRATION_ERROR, NEWLINE);
                    val = false;
                    break;
                }
            }
            if(val == true) {
                for(i=REG_AFIRSTDASH; i<REG_SECONDASH; i++) {
                    if(isalpha(registration[i])) {
                        val = true;
                    } else {
                        printf(MSG_REGISTRATION_ERROR, NEWLINE);
                        val = false;
                        break;
                    }
                }
            }
            if(val == true) {
                for(i=REG_ASECONDASH; i<REG_END; i++) {
                    if(isdigit(registration[i])) {
                        val = true;
                    } else {
                        printf(MSG_REGISTRATION_ERROR, NEWLINE);
                        val = false;
                        break;
                    }
                }
            }
        }
        limparBufferEntradaDados();
    } while(val == false);
    strcpy(pVehicles[pos].registration, registration);
};

void getNameVehicle(Vehicle *pVehicles, unsigned short int pos) {
    bool val = false;
    char name[VEHICLENAME_LENGTH];
    unsigned short i;

    do {
        printf(MSG_NAME);
        lerFrase(name, VEHICLENAME_LENGTH);
        for (i = 0; i < VEHICLENAME_LENGTH && name[i] != '\0'; i++) {
            if (isalpha(name[i]) || isspace(name[i])) {
                val = true;
            } else {
                val = false;
                printf(MSG_NAME_ERROR);
                break;
            }
        }
    } while (val == false);
    strcpy(pVehicles[pos].name, name);
}

void getType(Vehicle *pVehicles, unsigned short int pos) {
    unsigned short type;
    bool val = false;
    
    do {
        printf(MSG_CARTYPES, NEWLINE, NEWLINE, NEWLINE, NEWLINE, NEWLINE);
        printf(MSG_CARTYPES2, NEWLINE, NEWLINE, NEWLINE, NEWLINE, NEWLINE);
        printf(MSG_TYPE);
        scanf("%hu", &type);
        if(type == 1) {
            pVehicles[pos].type = CONVERTIBLE;
            val = true;
        } else if(type == 2) {
            pVehicles[pos].type = COUPE;
            val = true;
        } else if(type == 3) {
            pVehicles[pos].type = HYBRID;
            val = true;
        } else if(type == 4) {
            pVehicles[pos].type = LUXURY;
            val = true;
        } else if(type == 5) {
            pVehicles[pos].type = SEDAN;
            val = true;
        } else if(type == 6) {
            pVehicles[pos].type = SUV;
            val = true;
        } else if(type == 7) {
            pVehicles[pos].type = TRUCK;
            val = true;
        } else if(type == 8) {
            pVehicles[pos].type = VAN;
            val = true;
        } else if(type == 9) {
            pVehicles[pos].type = WAGON;
            val = true;
        } else {
            printf(MSG_TYPE_ERROR, NEWLINE);
            val = false;
        }
    } while(val == false);
}

void getDisplacement(Vehicle *pVehicles, unsigned short int pos) {

    unsigned short displacement;
    bool valEng;
    do {
        printf(MSG_DISPLACEMENT);
        scanf("%hu", &displacement);
        limparBufferEntradaDados();
        if (displacement >= ENG_MINIMUM && displacement <= ENG_MAXIMUM) {
            valEng = true;
        } else {
            printf(MSG_DISPLACEMENT_ERROR, NEWLINE);
        }
    } while (valEng == false);

    pVehicles[pos].vehicleChars.displacement = displacement;

}

void getHp(Vehicle *pVehicles, unsigned short int pos) {
    unsigned short hp;
    bool valHp;
    do {
        printf(MSG_HP);
        scanf("%hu", &hp);
        limparBufferEntradaDados();
        if (hp >= HP_MINIMUM && hp <= HP_MAXIMUM) {
            valHp = true;
        } else {
            printf(MSG_HP_ERROR, NEWLINE);
        }
    } while (valHp == false);
    pVehicles[pos].vehicleChars.hp = hp;
}

void getFuel(Vehicle *pVehicles, unsigned short int pos) {
    unsigned short fuelType;
    bool val = false;
    
    do {
        printf(MSG_FUEL_TYPES, NEWLINE, NEWLINE, NEWLINE, NEWLINE, NEWLINE);
        printf(MSG_FUEL);
        scanf("%hu", &fuelType);
        if(fuelType == 1) {
            pVehicles[pos].vehicleChars.fuel = DIESEL;
            val = true;
        } else if(fuelType == 2) {
            pVehicles[pos].vehicleChars.fuel = ELECTRIC;
            val = true;
        } else if(fuelType == 3) {
            pVehicles[pos].vehicleChars.fuel = GAS;
            val = true;
        } else if(fuelType == 4) {
            pVehicles[pos].vehicleChars.fuel = GASOLINE;
            val = true;
        } else {
            printf(MSG_FUEL_ERROR);
            val = false;
        }
    } while(val == false);
}

void getSeats(Vehicle *pVehicles, unsigned short int pos) {

    unsigned short seats;
    bool valSeats;
    do {
        printf(MSG_SEATS);
        scanf("%hu", &seats);
        limparBufferEntradaDados();
        if (seats >= SEATS_MINIMUM && seats <= SEATS_MAXIMUM) {
            valSeats = true;
        } else {
            printf(MSG_SEATS_ERROR, NEWLINE);
        }
    } while (valSeats == false);
    pVehicles[pos].vehicleChars.seats = seats;
}

void getCurrentState(Vehicle *pVehicles, unsigned short int pos) {


}

unsigned short int verifyEmptyVehiclePosition(Vehicle *pVehicles) {

    int i;

    for (i = 0; i < VEHICLES_SIZE; i++) {
        if (pVehicles[i].registration == VEHICLE_INIT_ID)
            return i;
    }
    return EOF;
}

void createVehicleFile(Vehicle vehicles[]) {

    FILE *pVehicle = fopen("Vehicle", "w");
    if (pVehicle == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(vehicles, sizeof (Vehicle), VEHICLES_SIZE, pVehicle);
        fclose(pVehicle);
    }
}

Vehicle initVehicleFile(Vehicle vehicles[]) {
    int i;

    for (i = 0; i < VEHICLES_SIZE; i++) {
        vehicles[i].vehicleChars.displacement = VEHICLE_INIT_ID;
    }
    return vehicles[VEHICLES_SIZE];
}

Vehicle readVehicleFile(Vehicle vehicles[]) {

    FILE *pVehicle = fopen("Vehicles", "r");
    if (pVehicle == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createVehicleFile(vehicles);
        vehicles[VEHICLES_SIZE] = initVehicleFile(vehicles);
        saveVehicleFile(vehicles);
        puts("File created");
        readVehicleFile(vehicles);
    } else {
        fread(vehicles, sizeof (Vehicle), VEHICLES_SIZE, pVehicle);
        fclose(pVehicle);
    }
}

void saveVehicleFile(Vehicle vehicles[]) {

    FILE *pVehicle = fopen("Vehicles", "w");
    if (pVehicle == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(vehicles, sizeof (Vehicle), VEHICLES_SIZE, pVehicle);
        puts("File saved.");
        fclose(pVehicle);
    }
}

void addVehicle(Vehicle *pVehicles) {
    int pos;
    
    pos = verifyEmptyVehiclePosition(pVehicles);
    if (pos == EOF) {
        printf(MSG_VEHICLE_SPACE_FULL, NEWLINE);
    } else {
        pVehicles[pos].rentedState = false;
        getNameVehicle(pVehicles, pos);
        getRegistration(pVehicles, pos);
        printf(MSG_VEHICLE_FEATURES, NEWLINE);
        getDisplacement(pVehicles, pos);
        getHp(pVehicles, pos);

    }

}

//modifyVehicle()

//removeVehicle()

void listVehicle(Vehicle vehicles[]) {
    int i;

    for (i = 0; i < VEHICLES_SIZE; i++) {
        if (vehicles[i].vehicleChars.displacement == VEHICLE_INIT_ID) {
            
        }
    }
}
