
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Client.h"
#include "Menu.h"

void getId(Client *pClients, unsigned short pos) {
    bool valId = false, valExist = true;
    unsigned long id;
    unsigned short i;
    
    do {
        do {
            printf(MSG_ID);
            scanf("%lu", &id);
            limparBufferEntradaDados();
            if(id > ID_MINIMUM && id < ID_MAXIMUM) {
                valId = true;
            } else {
                printf(MSG_ID_ERROR, NEWLINE);
            }
        } while(valId == false);
        for(i=0; i<CLIENTS_SIZE; i++){
            if(pClients[i].id == id) {
                printf(MSG_ID_EXIST_ERROR);
                valExist = true;
                break;
            } else {
                valExist = false;
            }
        }
    } while(valExist == true);
    pClients[pos].id = id;
}

void getName(Client *pClients, unsigned short pos) {
    bool val = false;
    char name[NAME_LENGTH];
    unsigned short i;
    
    do {
        printf(MSG_NAME);
        lerFrase(name, NAME_LENGTH);
        for(i=0; i<NAME_LENGTH && name[i] != '\0'; i++) {
            if(isalpha(name[i]) || isspace(name[i])) {
                val = true;
            } else {
                val = false;
                printf(MSG_NAME_ERROR);
                break;
            }
        }
    } while(val == false);
    strcpy(pClients[pos].name, name);
}

void getStreet(Client *pClients, unsigned short pos) {
    bool val = false;
    char street[STREET_LENGTH];
    unsigned short i;
    
    do {
        printf(MSG_STREET);
        lerFrase(street, STREET_LENGTH);
        for(i=0; i<STREET_LENGTH && street[i] != '\0'; i++) {
            if(isalpha(street[i]) || isspace(street[i])) {
                val = true;
            } else {
                val = false;
                printf(MSG_STREET_ERROR);
                break;
            }
        }
    } while(val == false);
    strcpy(pClients[pos].address.street, street);
}

void getNumber(Client *pClients, unsigned short pos) {
    bool val = false;
    unsigned short number;
    
        do {
            printf(MSG_NUMBER);
            scanf("%hu", &number);
            if(number > NUMBER_MINIMUM && number < NUMBER_MAXIMUM) {
                val = true;
            } else {
                printf(MSG_NUMBER_ERROR);
            }
        } while(val == false);
        pClients[pos].address.number = number;
}

// TODO: FIX BUFFER PROBLEM AFTER ERROR
void getPostalCode(Client *pClients, unsigned short pos) {
    bool val = false;
    char postalcode[POSTALCODE_LENGTH];
    unsigned short i;
    
    do {
        printf(MSG_POSTALCODE);
        limparBufferEntradaDados();
        lerFrase(postalcode, POSTALCODE_LENGTH);
        if(postalcode[PC_DASH] != '-' && postalcode[PC_END] != '\0'){
            val = false;
        } else {
            for(i=0; i<PC_DASH; i++) {
                if(isdigit(postalcode[i])) {
                    val = true;
                } else {
                    val = false;
                    break;
                }
            }
            if(val == true) {
                for(i=PC_ADASH; i<PC_END; i++) {
                    if(isdigit(postalcode[i])) {
                        val = true;
                    } else {
                        val = false;
                        break;
                    }
                }
            }
        }
    } while(val == false);
    strcpy(pClients[pos].address.postalCode, postalcode);
}

void getCity(Client *pClients, unsigned short pos) {
    bool val = false;
    char city[CITY_LENGTH];
    unsigned short i;
    
    do {
        printf(MSG_CITY);
        limparBufferEntradaDados();
        lerFrase(city, CITY_LENGTH);
        for(i=0; i<CITY_LENGTH && city[i] != '\0'; i++) {
            if(isalpha(city[i]) || isspace(city[i])) {
                val = true;
            } else {
                val = false;
                printf(MSG_CITY_ERROR);
                break;
            }
        }
    } while(val == false);
    strcpy(pClients[pos].address.city, city);
}

void getPhone(Client *pClients, unsigned short pos) {
    bool val = false;
    unsigned long phone;
    
    do {
        printf(MSG_PHONE);
        scanf("%lu", &phone);
        limparBufferEntradaDados();
        if(phone > VODAFONE_MINIMUM && phone < VODAFONE_MAXIMUM) {
            val = true;
        } else if (phone > ZON_MINIMUM && phone < ZON_MAXIMUM){
            val = true;
        } else if (phone > OPTIMUS_MINIMUM && phone < OPTIMUS_MAXIMUM){
            val = true;
        } else if (phone > TMN_MINIMUM && phone < TMN_MAXIMUM){
            val = true;
        } else if (phone > LANDLINE_MINIMUM && phone < LANDLINE_MAXIMUM){
            val = true;
        } else {
            printf(MSG_NUMBER_ERROR);
        }
    } while(val == false);
    pClients[pos].phone = phone;
}

void getBirthday(Client *pClients, unsigned short pos) {
    unsigned short day;
    unsigned short month;
    unsigned short year;
    
    printf(MSG_BIRTHDAY, NEWLINE);
    day = getDay();
    month = getMonth();
    year = getYear();
    
    pClients[pos].birthDay.tm_mday = day;
    pClients[pos].birthDay.tm_mon = month;
    pClients[pos].birthDay.tm_year = year;
    
}

void getSignupDate(Client *pClients, unsigned short pos) {
    unsigned short day;
    unsigned short month;
    unsigned short year;
    
    printf(MSG_SIGNUPDATE, NEWLINE);
    day = getDay();
    month = getMonth();
    year = getYear();
    
    pClients[pos].birthDay.tm_mday = day;
    pClients[pos].birthDay.tm_mon = month;
    pClients[pos].birthDay.tm_year = year;
    
}

int verifyIfPosEmpty(Client *pClients) {
    int pos;
    
    for(pos=0; pos<CLIENTS_SIZE; pos++) {
        if(pClients[pos].id == CLIENTS_INIT_ID) {
            return pos;
        }
    }
    return EOF;
}

int verifyClientToModify(Client *pClients, unsigned long id) {
    int pos;
    
    for(pos=0; pos<CLIENTS_SIZE; pos++) {
        if(pClients[pos].id == id) {
            return pos;
        }
    }
    return EOF;
}

void createClientFile(Client clients[]) {
    
    FILE *pClient = fopen("Clients", "w");
    if(pClient == (FILE *) NULL) {
        puts("Couldn't create file.");
    } else {
        fwrite(clients, sizeof(Client), CLIENTS_SIZE, pClient);
        fclose(pClient);
    }
}

Client initClientFile(Client clients[]) {
    int i;
    
    for(i=0; i<CLIENTS_SIZE; i++) {
        clients[i].id = 0;
        printf("%d - %lu \n", i, clients[i].id);
    }
    return clients[CLIENTS_SIZE];
}

Client readClientFile(Client clients[]) {
    int i;
    FILE *pClient = fopen("Clients", "r");
    if(pClient == (FILE *) NULL) {
        puts("File doesn't exist");
        puts("Creating file now...");
        createClientFile(clients);
        clients[CLIENTS_SIZE] = initClientFile(clients);
        saveClientFile(clients);
        puts("File created");
        readClientFile(clients);
    } else {
        fread(clients, sizeof(Client), CLIENTS_SIZE, pClient);
        fclose(pClient);
    }
}

void saveClientFile(Client clients[]) {
    
    FILE *pClient = fopen("Clients", "w");
    if(pClient == (FILE *) NULL) {
        puts("File doesn't exist.");
        puts("Couldn't save.");
    } else {
        fwrite(clients, sizeof(Client), CLIENTS_SIZE, pClient);
        puts("File saved.");
        fclose(pClient);
    }
}

void addClient(Client *pClients) {
    int pos;
    
    pos = verifyIfPosEmpty(pClients);
    if(pos == EOF) {
        printf(MSG_CLIENTS_FULL_ERROR);
    } else {
        getId(pClients, pos);
        getName(pClients, pos);
        getStreet(pClients, pos);
        getNumber(pClients, pos);
        getPostalCode(pClients, pos);
        getCity(pClients, pos);
        getPhone(pClients, pos);
        getBirthday(pClients, pos);
        getSignupDate(pClients, pos);
        // TODO: SORT CLIENTS IN ORDER
        printf(MSG_CLIENT_ADDED);
    }
}

void modifyClient(Client *pClients) {
    unsigned long id;
    int pos, modifyOpt, addressOpt;
    bool valId = false;
    
    do {
        printf(MSG_ID);
        scanf("%lu", &id);
        if(id > ID_MINIMUM && id < ID_MAXIMUM){
            valId = true;
        } else {
            printf(MSG_ID_ERROR, NEWLINE);
        }
    } while(valId == false);
    pos = verifyClientToModify(pClients, id);
    if(pos != EOF) {
        ModifyMenu();
        limparBufferEntradaDados();
        scanf("%d", &modifyOpt);
        if(modifyOpt == 1){
            getName(pClients, pos);
        } else if(modifyOpt == 2) {
            AddressModifyMenu();
            scanf("%d", &addressOpt);
            limparBufferEntradaDados();
            if(addressOpt == 1) {
                getStreet(pClients, pos);
            } else if(addressOpt == 2) {
                getNumber(pClients, pos);
            } else if(addressOpt == 3) {
                getPostalCode(pClients, pos);
            } else if(addressOpt == 4) {
                getCity(pClients, pos);
            } else {
                printf(MSG_MENU_ERROR, NEWLINE);
            }
        } else if(modifyOpt == 3) {
            getPhone(pClients, pos);
        } else if(modifyOpt == 4) {
            getBirthday(pClients, pos);
        } else if(modifyOpt == 5) {
            getSignupDate(pClients, pos);
        } else {
            printf(MSG_MENU_ERROR, NEWLINE);
        }
        saveClientFile(pClients);
    } else {
        printf(MSG_ID_DOESNT_EXIST_ERROR, NEWLINE);
    }
}

void listClients(Client clients[]) {
    int i;
    
    for(i=0; i<CLIENTS_SIZE; i++) {
        printf("%d - %lu \n", i, clients[i].id);
    }
}


