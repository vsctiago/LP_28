
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vehicle.h"
#include "Menu.h"
#include "Utils.h"

void getRegistrationVehicle(Vehicle *vehicle, unsigned short int pos) {


};

void getNameVehicle(Vehicle *vehicle, unsigned short int pos) {
    bool val = false;
    char name[NAME_LENGTH];
    unsigned short i;

    do {
        printf(MSG_NAME);
        lerFrase(name, NAME_LENGTH);
        for (i = 0; i < NAME_LENGTH && name[i] != '\0'; i++) {
            if (isalpha(name[i]) || isspace(name[i])) {
                val = true;
            } else {
                val = false;
                printf(MSG_NAME_ERROR);
                break;
            }
        }
    } while (val == false);
    strcpy(vehicle[pos].name, name);
}

void getType(Vehicle *vehicle, unsigned short int pos) {


}

void getEngine(Vehicle *vehicle, unsigned short int pos) {

    unsigned short eng;
    bool valid;
    do {
        printf(MSG_ENG);
        scanf("%lu", &eng);
        limparBufferEntradaDados();
        if (eng > ENG_MINIMUM && eng < ENG_MAXIMUM) {
            valid = true;
        } else {
            printf(MSG_ENG_ERROR, NEWLINE);
        }
    } while (valid == false);

    vehicle[pos].vehicleChars.engine = eng;

}

void getHp(Vehicle *vehicle, unsigned short int pos) {
    unsigned short hp;
    bool valid;
    do {
        printf(MSG_HP);
        scanf("%lu", &hp);
        limparBufferEntradaDados();
        if (hp > HP_MINIMUM && hp < HP_MAXIMUM) {
            valid = true;
        } else {
            printf(MSG_HP_ERROR, NEWLINE);
        }
    } while (valid == false);
    vehicle[pos].vehicleChars.hp = hp;
}

void getFuel(Vehicle *vehicle, unsigned short int pos) {


}

void getSeats(Vehicle *vehicle, unsigned short int pos) {

    unsigned short seats;
    bool valid;
    do {
        printf(MSG_SEATS);
        scanf("%lu", &seats);
        limparBufferEntradaDados();
        if (seats > HP_MINIMUM && seats < HP_MAXIMUM) {
            valid = true;
        } else {
            printf(MSG_SEATS_ERROR, NEWLINE);
        }
    } while (valid == false);
    vehicle[pos].vehicleChars.seats = seats;
}

void getCurrentState(Vehicle *vehicle, unsigned short int pos) {


}

unsigned short int getPositionVehicle(Vehicle *vehicle) {

    int i;

    for (i = 0; i < VEHICLE_SIZE; i++) {
        if (vehicle[i].registration == VEHICLE_INIT_ID)
            return i;
    }
    return EOF;
}

void addVehicle(Vehicle *vehicle) {
    unsigned short int position;
    position = getPositionVehicle(vehicle);
    if (position == EOF) {
        printf(MSG_VEHICLE_SPACE_FULL, NEWLINE);
    } else {
        vehicle[position].rentedstate = false;
        getNameVehicle(vehicle, position);
        getRegistrationVehicle(vehicle, position);
        printf(MSG_VEHICLE_FEATURES, NEWLINE);
        getEngine(vehicle, position);
        getHp(vehicle, position);

    }

}

//modifyVehicle()

//removeVehicle()

void listVehicle(Vehicle vehicles[]) {
    int i;

    for (i = 0; i < VEHICLE_SIZE; i++) {

        if (vehicles[i].vehicleChars.engine == VEHICLE_INIT_ID) {
            //            puts(MSG_VEHICLS_NOT_FUND, NEWLINE);
        } else {
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
    if (pVehicle == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(vehicles, sizeof (Vehicle), VEHICLE_SIZE, pVehicle);
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