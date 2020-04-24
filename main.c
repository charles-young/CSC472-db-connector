#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char queryCode, cmd[150];
    while (1) {
        printf("Select query to execute:\n");
        printf("a)\tFor each type of plane, list the type code (C8), the type description (C30), the capacity (D3), and the flight range (D4)./n");
        printf("b)\tFor each aircraft, list the serial number (C12), and the code and description of the type of plane.\n");
        printf("c)\tFor each pilot, list the pilot number (D5) and the name of the pilot (C30).  In addition, list the type code and description of each of the types of planes on which the pilot is certified as well as the flight number (D3), date, and aircraft serial number for all flights on which the pilot is currently scheduled./n");
        printf("d)\tFor each city served, list the code for the city (C3), then name of the city (C30), the name of the state (C2), and a description of the airport (C30).  Should be in city name order.\n");
        printf("e)\tFor each aircraft, list the serial number, year it was manufactured, the last date it was serviced and its next service date.\n");
        printf("f)\tFor a given point of origination and destination, list all flights scheduled that still have seats available and include the number of seats available and the date.  Note:  should be in alphabetical order of origination city.\n");
        printf("g)\tFor a given date, list all of the pilots scheduled for flight including the pilot number (ID), pilot name and the serial number of the aircraft and plane type description.\n");
        printf("h)\tFor a given flight, list the flight number, the code and name of the city of origination, the time of departure, the code and name of the destination city, and the time of arrival.\n");
        printf("x: exit program.\n");

        scanf(" %c", &queryCode);

        switch (queryCode) {
            default:
                break;
            case 'a':
                system("mysql --login-path=local -e 'call GetPlanes();' project");
                break;
            case 'b':
                system("mysql --login-path=local -e 'call GetAircraftDesc();' project");
                break;
            case 'c':
                system("mysql --login-path=local -e 'call GetPilots();' project");
                break;
            case 'd':
                system("mysql --login-path=local -e 'call GetCityServed();' project");
                break;
            case 'e':
                system("mysql --login-path=local -e 'call GetService();' project");
                break;
            case 'f':
                printf("Please input orgin code (C3), dest code (C3):\n");
                char origin[4], dest[4];
                scanf("%s %s", origin, dest);
                sprintf(cmd, "mysql --login-path=local -e 'call GetAvaliableSeats('%s', '%s');' project", origin, dest);
                system(cmd);
                break;
            case 'g':
                printf("Please input date:\n");
                char date[11];
                scanf("%s", date);
                sprintf(cmd, "mysql --login-path=local -e 'call GetScheduledPilots('%s');' project", date);
                system(cmd);
                break;
            case 'h':
                printf("Please input flight number:\n");
                char flight[4];
                scanf("%s", flight);
                sprintf(cmd, "mysql --login-path=local -e 'call GetFlights('%s');' project", flight);
                system(cmd);
                break;
            case 'x':
                return 0;
        }
        printf("\n");
    }
}
