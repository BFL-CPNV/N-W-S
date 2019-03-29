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
//| This program is a game, the user can play against another one,     |
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
//| This program was created for a project of the developper's         |
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
//| 1.  Add a functional menu              status : 90% done           |
//| 2.  Add an help menu for the game      status : DONE               |
//| 3.  Add a static map for testing       status : DONE               |
//| 4.  Add a gaming mechanic              status : DONE               |
//| 5.  Verify the program                 status : In progress        |
//| 6.  Create maps to be used randomly    status : To do              |
//| 7.  Verify the program                 status : To do              |
//| 8.  Create a logging system            status : To do              |
//| 9.  Create an Highscores board         status : To do              |
//| 10. Verify the program                 status : To do              |
//| 11. Check with the client              status : To do              |
//======================================================================
//======================================================================

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_LINES 8
#define MAX_COLUMNS 10
#define ARRAY_ADJUSTER 1
#define TOTAL_HEALTH 18
#define CARRIER_HEALTH 5
#define CRUISER_HEALTH 4
#define SUBMARINES_HEALTH 6
#define ENFORCER_HEALTH 2
#define RECON_HEALTH 1

int StaticMap[9][11] = { //This array is the static grid, each numbers represent different object
        1, 1, 1, 1, 1, 1, 1, 7, 7, 7, 1,        //5 is a Recon wich takes 1 case
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,        //6 is an Enforcer wich takes 2 cases
        1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 1,        //7 are the Submarines wich take 3 cases
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9,        //8 is the Cruiser wich takes 4 cases
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 9,        //9 is the Carrier wich takes 5 cases
        1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 9,
        1, 1, 5, 1, 1, 1, 7, 1, 1, 1, 9,
        1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 9,
        8, 8, 8, 8, 1, 1, 1, 1, 1, 1, 1
};


int winningCondition(int shots_fired, int missed_shots, int total_hp, char name_transfer) {
    int Win = 0;

    if (total_hp == 0) { //winning dialogue
        printf("[Radio Command] Seems like we got em all, we got no more hostile activity on the radar.\n");
        printf("You: Well that was easy ! Let's leave this sea and rest.\n");
        getch();
        printf("===================================================================================================================\n");
        printf(" ****   ****   **   *    ****   ****    ****   *******   *    *   *      ****   *******    *****     ****    **   *\n");
        printf("*      *    *  * *  *   *       *   *  *    *     *      *    *   *     *    *     *         *      *    *   * *  *\n");
        printf("*      *    *  *   **   *   *   ****   ******     *      *    *   *     ******     *         *      *    *   *   **\n");
        printf(" ****   ****   *    *    ****   *   *  *    *     *       ****    ****  *    *     *       *****     ****    *    *\n");
        printf("===================================================================================================================\n");
        //printf("User %s won, you shot %d times and missed %d times.\n", name_transfer, shots_fired, missed_shots);
        printf("Congratulation ! And most importantly...\n");
        printf("OwO [T H A N K  Y O U  F O R  P L A Y I N G] OwO\n");
        system("PAUSE");
        system("CLS");
        Win = 1;
        return (Win);
    }
} //This function checks if the player has won or not

void showMenu() {
    printf("[1] Help\n");
    printf("[2] Settings\n");
    printf("[3] Info\n");
    printf("[4] About us\n");
    printf("[5] Play\n");
    printf("[6] Quit\n");
} //This function shows the available options of the menu

void helpMenu(int Choice) {
    int Choice2 = 0;

    switch (Choice) {
        case 1: //This case shows the help menu and its content

            while (Choice2 != 8) { //This will keep repeating so that the user doesn't have to reopen the help menu
                //each times he choose a question, however he can go back to the main menu if he
                //inputs the number [8], Go back to main menu

                system("CLS");

                printf("======================================================================\n");
                printf("\t\t\t  Help Menu [N.W.S.]\n");
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

                switch (Choice2) { //This switch will show the help info of the corresponding question

                    case 1: //How to play [1]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("Your goal is to find and sink all of your opponent's boats by\n");
                        printf("shooting them, it's a turn based game and your goal is also to\n");
                        printf("not miss too many times\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 2: //How to start playing [2]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("To start playing, type the number 5 in the main menu\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 3: //How to enable the A.I. [3]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("Error, file //sc-c133-pc15//users//NWS_A.I. doesn't exist yet\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 4: //Info button [4]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("The Info button ([3]) of the main menu will give you basic info of the\n");
                        printf("game, it's version as well as its known bugs if there are any and a\n");
                        printf("link to the github page of the game");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 5: //About us button [5]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("The About us button ([4]) of the main menu will give you info about\n");
                        printf("the author of this game and the people who helped test this game\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 6: //Settings button [6]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("The Settings button ([2]) of the main menu will let you change a few\n");
                        printf("things in the game suchs as activating the A.I., etc...\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 7: //Game not working [7]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("If your game crashes or is not working correctly, send a message to\n");
                        printf("the author of this game, you can reach him by email at this address :\n");
                        printf("bastien.fardel@cpnv.ch\n");
                        printf("\nRemember that when making choices it is important that you write\n");
                        printf("what is given to you, for exemple don't write letters if your choices\n");
                        printf("are in numbers\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 8:
                        break;

                    default: //Default case if a number that isn't part of the options is chosen by the user

                        system("CLS");

                        printf("\t\t    [!] This isn't an option [!]\n");

                        system("PAUSE");
                        break;
                }
            }
            break;

        default:
            break;
    }
    system("CLS");

} //This function shows Help menu

void settingsMenu(int Choice) {
    //W.I.P.
} //This function shows the Settings Menu

void infoMenu(int Choice) {

    if (Choice == 3) {
        system("CLS");

        printf("=======================================================================\n");
        printf("\t\t\t  Info Menu [N.W.S.]\n");
        printf("======================================================================\n");
        printf("You are currently playing Naval Warfare Simulator [N.W.S.]\n");
        printf("Version        : 1.0\n");
        printf("Known bugs     : When typing a letter instead of a number, the game\n"
               "                 crashes.\n");
        printf("Github page    : https://github.com/FardelusDeletus/N-W-S\n");
        printf("======================================================================\n");
        system("PAUSE");
        system("CLS");

    }
} //This function shows the Info Menu

void aboutUsMenu(int Choice) {
    //W.I.P.
} //This function shows the About Us Menu

void showGrid() {
    int lines = 0, columns = 0;

    printf("   | A | B | C | D | E | F | G | H | I | J | K |\n");
    printf("---|---|---|---|---|---|---|---|---|---|---|---|\n");

    for (lines = 0; lines <= MAX_LINES; lines++) {

        if (lines == 0) {
            printf(" 1 ");
        } else {
            if (lines == 1) {
                printf(" 2 ");
            } else {
                if (lines == 2) {
                    printf(" 3 ");
                } else {
                    if (lines == 3) {
                        printf(" 4 ");
                    } else {
                        if (lines == 4) {
                            printf(" 5 ");
                        } else {
                            if (lines == 5) {
                                printf(" 6 ");
                            } else {
                                if (lines == 6) {
                                    printf(" 7 ");
                                } else {
                                    if (lines == 7) {
                                        printf(" 8 ");
                                    } else {
                                        if (lines == 8) {
                                            printf(" 9 ");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        for (columns = 0; columns <= MAX_COLUMNS; columns++) {


            if (StaticMap[lines][columns] == 1) { //1 equals to water
                printf("| ~ ");
            } else {
                if (StaticMap[lines][columns] == 2) { //2 equals to missed
                    printf("| X ");
                } else {
                    if (StaticMap[lines][columns] == 3) { //3 equals to hit
                        printf("| O ");
                    } else {
                        if (StaticMap[lines][columns] == 4) { //4 equals to sunken
                            printf("| S ");
                        } else { //prints water to hide boats
                            printf("| ~ ");
                        }
                    }
                }
            }
        }
        printf("|\n");
        printf("---|---|---|---|---|---|---|---|---|---|---|---|\n");
    }
} //This function shows the grid

void shoot(char name, int i) {
    int target_line = 0, target_col = 0, shots_fired = 0, missed_shots = 0, total_hp = TOTAL_HEALTH, recon_hp = RECON_HEALTH, enforcer_hp = ENFORCER_HEALTH,
            submarines_hp = SUBMARINES_HEALTH, cruiser_hp = CRUISER_HEALTH, carrier_hp = CARRIER_HEALTH, win_game;

    char name_transfer = name;

    do {

        system("CLS");

        showGrid();

        printf("[Radio Command] It's your turn, choose a target.\n");

        do { //This will make sure the user doesn't crash the game by inputing a wrong number
        printf("Column : ");
            scanf("%d", &target_col);
            target_col =
                    target_col -
                    ARRAY_ADJUSTER; //Removes 1 from the choice to make sure it respects the array's standards

            if (target_col > 10) {
                printf("[Radio Command] Hum.... Sir this isn't in the range, the range is of 11.\n");
            }
        } while (target_col > 10);

        do { //This will make sure the user doesn't crash the game by inputing a wrong number
            printf("Ligne : ");
            scanf("%d", &target_line);
            target_line =
                    target_line -
                    ARRAY_ADJUSTER; //Remove 1 from the choice to make sure it respects the array's standards

                    if (target_line > 8){
                        printf("[Radio Command] Hum... Sir this isn't in the range, the range is of 9.\n");
                    }
        }while(target_line > 8);

        printf("[READY TO FIRE] press any key to fire\n");
        getch();
        printf("[Radio Command] Shot fired !\n");
        if (StaticMap[target_line][target_col] == 5 || StaticMap[target_line][target_col] == 6 ||
            StaticMap[target_line][target_col] == 7 || StaticMap[target_line][target_col] == 8 ||
            StaticMap[target_line][target_col] == 9) {
            printf("[Radio Command] Target hit, nice shot !\n");

            //This will remove HPs from the corresponding category of boat and from the total HP
            if (StaticMap[target_line][target_col] == 5) {
                recon_hp = recon_hp - 1;
                printf("[Radio Command] Recon boat has been destroyed !\n");
            } else {
                if (StaticMap[target_line][target_col] == 6) {
                    enforcer_hp = enforcer_hp - 1;
                    if (enforcer_hp == 0) {
                        printf("[Radio Command] Enforcer boats have been destroyed !\n");
                    }
                } else {
                    if (StaticMap[target_line][target_col] == 7) {
                        submarines_hp = submarines_hp - 1;
                        if (submarines_hp == 0) {
                            printf("[Radio Command] Hostile submarines have been destroyed !\n");
                        }
                    } else {
                        if (StaticMap[target_line][target_col] == 8) {
                            cruiser_hp = cruiser_hp - 1;
                            if (cruiser_hp == 0) {
                                printf("[Radio Command] We destroyed the enemy cruiser !\n");
                            }
                        } else {
                            if (StaticMap[target_line][target_col] == 9) {
                                carrier_hp = carrier_hp - 1;
                                if (carrier_hp == 0) {
                                    printf("[Radio Command] We destroyed their carrier !");
                                }
                            }
                        }
                    }
                }
            }

            StaticMap[target_line][target_col] = 3;
            shots_fired = shots_fired + 1;
            total_hp = total_hp - 1;

        } else {
            if (StaticMap[target_line][target_col] == 1) {
                printf("[Radio Command] Target missed, we'll get 'em next time !\n");
                StaticMap[target_line][target_col] = 2;
            } else {
                if (StaticMap[target_line][target_col] == 2 || StaticMap[target_line][target_col] == 3) {
                    printf("[Radio Command] We already shot here...\n");
                }
                shots_fired = shots_fired + 1;
                missed_shots = missed_shots + 1;
            }
        }

        win_game = winningCondition(shots_fired, missed_shots, total_hp, name_transfer);

        system("PAUSE");

    } while (win_game != 1);
} //This function lets the player shoot

void play(int Choice) {

    if (Choice == 5) {

        int i = 0;

        char name;

        system("CLS");

        printf("\t    Here's a little reminder about how to play !\n");
        printf("======================================================================\n");
        printf("1) To fire, choose a line and then a column and finally you must write\n");
        printf("   numbers only so for exemple line 2 and column 3.\n");
        printf("\n");
        printf("2) Choose carefully, you can always see wich case you shot, they are\n");
        printf("   marked with symbols, here's the meaning of each one of them :\n");
        printf("\t- [X] means that you shot but missed\n");
        printf("\t- [O] means that you shot and hit a boat\n");
        printf("\t- [S] means that the case is a sunken boat\n");
        printf("======================================================================\n");
        printf("What is your name captain ? (Please do not input spaces)");
        scanf("%s", &name);

        shoot(name, i);

    }
} //This function starts the game


int main() {
    int Choice;

    do { //This while loop will keep repeating until an option is chosen or the user quits by typing [6]
        printf("======================================================================\n"); //showing the main interface
        printf("                **     *    *           *      ***** \n");
        printf("                * *    *     *         *      *      \n");
        printf("                *  *   *      *       *        ****  \n");
        printf("                *   *  *       *  *  *             * \n");
        printf("                *    * *   .    *   *      .  *****  .\n");
        printf("======================================================================\n");
        printf("Version\t: 1.0\n");
        printf("Author\t: Fardel Bastien\n");
        printf("Created using CLion\n");
        printf("======================================================================\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("======================================================================\n");
        showMenu(); //Calls upon the showMenu function to show the options available
        printf("======================================================================\n");
        printf("Your choice : ");
        scanf("%d", &Choice);
        printf("======================================================================\n");

        helpMenu(Choice); //Calls upon the HelpMenu function
        settingsMenu(Choice); //Calls upon the settingsMenu function
        infoMenu(Choice); //Calls upon the infoMenu function
        aboutUsMenu(Choice); //Calls upon the aboutUsMenu function
        play(Choice); //Calls upon the play function

        if (Choice > 6 || Choice <= 0) {
            printf("\t\t    [!] This isn't an option [!]\n");
        }
    } while (Choice != 6);

    return 0;
}
