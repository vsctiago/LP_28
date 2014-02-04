/* 
 * File:   Client.h
 * Author: Psycku
 *
 * Created on 30 de Janeiro de 2014, 15:06
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include "General.h"

#define NAME_LENGTH 100+1
#define STREET_LENGTH 100+1
#define POSTALCODE_LENGTH 8+1
#define CITY_LENGTH 50+1
#define PC_DASH 4
#define PC_ADASH 5
#define PC_END 8
#define CLIENTS_INIT_ID 0
#define CLIENTS_SIZE 50

static const int ID_MINIMUM = 10000000;
static const int ID_MAXIMUM = 99999999;
static const int NUMBER_MINIMUM = 1;
static const int NUMBER_MAXIMUM = 9999;
static const int VODAFONE_MINIMUM = 910000000;
static const int VODAFONE_MAXIMUM = 919999999;
static const int ZON_MINIMUM = 920000000;
static const int ZON_MAXIMUM = 929999999;
static const int OPTIMUS_MINIMUM = 930000000;
static const int OPTIMUS_MAXIMUM = 939999999;
static const int TMN_MINIMUM = 960000000;
static const int TMN_MAXIMUM = 969999999;
static const int LANDLINE_MINIMUM = 253000000;
static const int LANDLINE_MAXIMUM = 253999999;

typedef struct address {
    char street[STREET_LENGTH];
    unsigned short number;
    char postalCode[POSTALCODE_LENGTH];
    char city[CITY_LENGTH];
} Address;

typedef struct client {
    unsigned long id;
    char name[NAME_LENGTH];
    Address address;
    unsigned long phone;
    Date birthDay;
    Date signupDate;
} Client;

void getId(Client *pClients, unsigned short pos);

void getName(Client *pClients, unsigned short pos);

void getStreet(Client *pClients, unsigned short pos);

void getNumber(Client *pClients, unsigned short pos);

void getPostalCode(Client *pClients, unsigned short pos);

void getCity(Client *pClients, unsigned short pos);

void getPhone(Client *pClients, unsigned short pos);

void getBirthday(Client *pClients, unsigned short pos);

void getSignupDate(Client *pClients, unsigned short pos);

int verifyIfPosEmpty(Client *pClients);

int verifyClientToModify(Client *pClients, unsigned long id);

void createClientFile(Client clients[]);

Client initClientFile(Client clients[]);

Client readClientFile(Client clients[]);

void saveClientFile(Client clients[]);

void addClient(Client *pClients);

void modifyClient(Client *pClients);

void listClients(Client clients[]);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CLIENT_H */

