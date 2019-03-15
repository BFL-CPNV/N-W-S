//======================================================================
//======================================================================
//| Title     : [N.W.S.] Naval Warfare Simulator                       |
//| Author    : Fardel Bastien                                         |
//| Version   : 1.0                                                    |
//| Date      : 08.03.2019 (Creation date)                             |
//======================================================================
//======================================================================
//|[               So what is this program suposed to be ?            ]|
//|--------------------------------------------------------------------|
//| This program is a game, the user can play against an A.I., it works|
//| just like the board game called Naval Battle.                      |
//======================================================================
//======================================================================
//|[               If I need help, who should I contact ?             ]|
//|--------------------------------------------------------------------|
//| You can view the help of the game if you have problems with it but |
//| you can also contact the developper at bastien.fardel@cpnv.ch      |
//======================================================================
//======================================================================
//|[               What is the purpose of this program ?              ]|
//|--------------------------------------------------------------------|
//| This program was created for as a project of the developper's      |
//| learning.                                                          |
//======================================================================
//======================================================================
//**********************************************************************
//0101010101000011100000100001000011100001000010001000000111100001001001
//**********************************************************************
//======================================================================
//======================================================================
//|                           TO DO LIST                               |
//|--------------------------------------------------------------------|
//| 1.  Add a functional menu              status : 50% done           |
//| 2.  Add an help menu for the game      status : 50% done           |
//| 3.  Add a static map for testing       status : In progress        |
//| 4.  Add a gaming mechanic              status : In progress        |
//| 5.  Verify the program                 status : In progress        |
//| 6.  Create maps to be used randomly    status : In progress        |
//| 7.  Verify the program                 status : In progress        |
//| 8.  Add a functional A.I.              status : In progress        |
//| 9.  Verify the program                 status : In progress        |
//| 10. Create a logging system            status : In progress        |
//| 11. Create an Highscores board         status : In progress        |
//| 12. Verify the program                 status : In progress        |
//| 13. Check with the client              status : In progress        |
//======================================================================
//======================================================================

#include <stdio.h>


void showMenu() {
    printf("[1] Help\n");
    printf("[2] Settings\n");
    printf("[3] Info\n");
    printf("[4] About us\n");
    printf("[5] Play\n");
    printf("[6] Quit\n");
}

void menuSwitch(int Choice) {
    int Choice2;

    switch (Choice) {
        case 1:
            do {
                printf("======================================================================\n");
                printf("\t\t\t  Help Menu [N.W.S]\n");
                printf("======================================================================\n");
                printf("[1] How to play\n");
                printf("[2] How to start playing\n");
                printf("[3] How to enable the A.I.\n");
                printf("[4] Info button\n");
                printf("[5] About us button\n");
                printf("[6] Settings button\n");
                printf("[7] Game not working\n");
                printf("[8] Go back to main menu\n");
                printf("======================================================================\n");
                printf("Your choice : ");
                scanf("%d", &Choice2);
                printf("======================================================================\n");

                switch (Choice2) {
                    case 1:
                        printf("======================================================================\n");
                        printf("Your goal is to find and sink all of your opponent's boats by\n");
                        printf("shooting them, it's a turn based game and your goal is also to\n");
                        printf("not miss too many times\n");
                        printf("======================================================================\n");

                        break;

                    case 2:
                        printf("======================================================================\n");
                        printf("To start playing, type the number 5 in the main menu\n");
                        printf("======================================================================\n");

                        break;

                    case 3:
                        printf("======================================================================\n");
                        printf("Error, file //sc-c133-pc15//users//NWS_A.I. doesn't exist yet\n");
                        printf("======================================================================\n");

                        break;

                    case 4:
                        printf("======================================================================\n");
                        printf("The Info button ([3]) of the main menu will give you basic info of the\n");
                        printf("game, it's version as well as its known bugs if there are any and a\n");
                        printf("link to the github page of the game");
                        printf("======================================================================\n");

                        break;

                    case 5:
                        printf("======================================================================\n");
                        printf("The About us button ([4]) of the main menu will give you info about\n");
                        printf("the author of this game and the people who helped test this game\n");
                        printf("======================================================================\n");

                        break;

                    case 6:
                        printf("======================================================================\n");
                        printf("The Settings button ([2]) of the main menu will let you change a few\n");
                        printf("things in the game suchs as activating the A.I., etc...\n");
                        printf("======================================================================\n");

                        break;

                    case 7:
                        printf("======================================================================\n");
                        printf("If your game crashes or is not working correctly, send a message to\n");
                        printf("the author of this game, you can reach him by email at this address :\n");
                        printf("bastien.fardel@cpnv.ch\n");
                        printf("\nRemember that when making choices it is important that you write\n");
                        printf("what is given to you, for exemple don't write letters if your choices\n");
                        printf("are in numbers\n");
                        printf("======================================================================\n");

                        break;
                }
            } while (Choice2 != 8);

            break;


    }

}


int main() {
    int Choice;
    printf("======================================================================\n");
    printf("Welcome to Naval.Warfare.Simulator !\n");
    printf("======================================================================\n");
    printf("Version\t: 1.0\n");
    printf("Author\t: Fardel Bastien\n");
    printf("Created using CLion\n");
    printf("======================================================================\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("======================================================================\n");
    showMenu();
    printf("======================================================================\n");
    printf("Your choice : ");
    scanf("%d", &Choice);
    printf("======================================================================\n");
    menuSwitch(Choice);

    return 0;
}