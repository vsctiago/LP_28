
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Client.h"
#include "Vehicle.h"
#include "Menu.h"

void Menu() {    
    printf(MSG_MENU, NEWLINE);
    printf(MSG_MENU_CLIENT, NEWLINE);
    printf(MSG_MENU_VEHICLE, NEWLINE);
    printf(MSG_MENU_RENT, NEWLINE);
    printf(MSG_MENU_DELIVERY, NEWLINE);
    printf(MSG_MENU_EXIT, NEWLINE);
    printf(MSG_OPTION);
    
}

void ClientMenu() {
    printf(MSG_CLIENT_MENU, NEWLINE);
    printf(MSG_CLIENT_MENU_ADD, NEWLINE);
    printf(MSG_CLIENT_MENU_MODIFY, NEWLINE);
    printf(MSG_CLIENT_MENU_REMOVE, NEWLINE);
    printf(MSG_CLIENT_MENU_LIST, NEWLINE);
    printf(MSG_OPTION);
}

void ModifyMenu() {    
    printf(MSG_MODIFY_MENU, NEWLINE);
    printf(MSG_MODIFY_NAME, NEWLINE);
    printf(MSG_MODIFY_ADDRESS, NEWLINE);
    printf(MSG_MODIFY_PHONE, NEWLINE);
    printf(MSG_MODIFY_BIRTHDAY, NEWLINE);
    printf(MSG_MODIFY_SIGNUPDATE, NEWLINE);
    printf(MSG_OPTION);
}

void AddressModifyMenu() {
    printf(MSG_MODIFY_ADDRESS_MENU, NEWLINE);
    printf(MSG_MODIFY_STREET, NEWLINE);
    printf(MSG_MODIFY_NUMBER, NEWLINE);
    printf(MSG_MODIFY_POSTALCODE, NEWLINE);
    printf(MSG_MODIFY_CITY, NEWLINE);
    printf(MSG_OPTION);
}

void VehicleMenu() {
    printf(MSG_VEHICLE_MENU, NEWLINE);
    printf(MSG_VEHICLE_MENU_ADD, NEWLINE);
    printf(MSG_VEHICLE_MENU_MODIFY, NEWLINE);
    printf(MSG_VEHICLE_MENU_REMOVE, NEWLINE);
    printf(MSG_VEHICLE_MENU_LIST, NEWLINE);
    printf(MSG_OPTION);
}
// TODO: CHANGE THIS TO MATCH VEHICLE STRUCT

/*
void VehicleModifyMenu() {    
    printf(MSG_MODIFY_MENU, NEWLINE);
    printf(MSG_MODIFY_NAME, NEWLINE);
    printf(MSG_MODIFY_ADDRESS, NEWLINE);
    printf(MSG_MODIFY_PHONE, NEWLINE);
    printf(MSG_MODIFY_BIRTHDAY, NEWLINE);
    printf(MSG_MODIFY_SIGNUPDATE, NEWLINE);
    printf(MSG_OPTION);
}
*/
