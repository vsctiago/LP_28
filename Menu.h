/* 
 * File:   Menu.h
 * Author: Psycku
 *
 * Created on 3 de Fevereiro de 2014, 15:48
 */

#ifndef MENU_H
#define	MENU_H

#include "Utils.h"

#define MSG_OPTION "Option: "
#define MSG_MENU "---MAIN MENU--- %c"
#define MSG_MENU_CLIENT "1. Client menu. %c"
#define MSG_MENU_VEHICLE "2. Vehicle menu. %c"
#define MSG_MENU_RENT "3. Rent menu. %c"
#define MSG_MENU_DELIVERY "4. Delivery menu. %c"
#define MSG_MENU_EXIT "5. Exit. %c"
#define MSG_CLIENT_MENU "--CLIENT MENU-- %c"
#define MSG_CLIENT_MENU_ADD "1. Add Client. %c"
#define MSG_CLIENT_MENU_MODIFY "2. Modify Client. %c"
#define MSG_CLIENT_MENU_REMOVE "3. Remove Client. %c"
#define MSG_CLIENT_MENU_LIST "4. List Clients. %c"
#define MSG_MODIFY_MENU "-Modify Menu. %c"
#define MSG_MODIFY_NAME "1. Modify name. %c"
#define MSG_MODIFY_ADDRESS "2. Modify Address. %c"
#define MSG_MODIFY_PHONE "3. Modify phone. %c"
#define MSG_MODIFY_BIRTHDAY "4. Modify birthday. %c"
#define MSG_MODIFY_SIGNUPDATE "5. Modify signup date. %c"
#define MSG_MODIFY_ADDRESS_MENU "-Modify Address. %c"
#define MSG_MODIFY_STREET "1. Modify street. %c"
#define MSG_MODIFY_NUMBER "2. Modify number. %c"
#define MSG_MODIFY_POSTALCODE "3. Modify postalcode. %c"
#define MSG_MODIFY_CITY "4. Modify city. %c"
#define MSG_MENU_ERROR "Option invalid. %c"
#define MSG_ID_DOESNT_EXIST_ERROR "ID doesn't exist. %c"

void Menu();

void ClientMenu();

void ModifyMenu();

void AddressModifyMenu();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */

