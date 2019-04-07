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


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 8
#define MAX_COLUMNS 10
#define ARRAY_ADJUSTER 1
#define TOTAL_HEALTH 18
#define CARRIER_HEALTH 5
#define CRUISER_HEALTH 4
#define SUBMARINES_HEALTH 6
#define ENFORCER_HEALTH 2
#define RECON_HEALTH 1
#define TAILLE_MAX 100

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

void showScoreboard() {

    FILE *Pseudo = NULL;
    FILE *Shots = NULL;
    FILE *Missed = NULL;

    char shots[TAILLE_MAX] = "";

    char missed[TAILLE_MAX] = "";

    char pseudo[TAILLE_MAX] = "";

    Pseudo = fopen("P:\\CLion_Projects\\Sandbox\\MA-20\\N.W.S\\cmake-build-debug\\Pseudo.txt", "r");

    if (Pseudo != NULL) {
        fgets(pseudo, TAILLE_MAX, Pseudo);
        fclose(Pseudo);
    } else {
        printf("[Impossible de lire le fichier Pseudo.txt !]\n");
    }

    Shots = fopen("P:\\CLion_Projects\\Sandbox\\MA-20\\N.W.S\\cmake-build-debug\\Tirs.txt", "r");

    if (Shots != NULL) {
        fgets(shots, TAILLE_MAX, Shots);
        fclose(Shots);
    } else {
        printf("[Impossible de lire le fichier Tirs.txt !]\n");
    }

    Missed = fopen("P:\\CLion_Projects\\Sandbox\\MA-20\\N.W.S\\cmake-build-debug\\Rates.txt", "r");

    if (Missed != NULL) {
        fgets(missed, TAILLE_MAX, Missed);
        fclose(Missed);
    } else {
        printf("[Impossible de lire le fichier Rates.txt !]\n");
    }


    printf("======================================================================\n");
    printf("                        _                         _ \n"
           "                       | |                       | |\n"
           " ___  ___ ___  _ __ ___| |__   ___   __ _ _ __ __| |\n"
           "/ __|/ __/ _ \\| '__/ _ \\ '_ \\ / _ \\ / _` | '__/ _` |\n"
           "\\__ \\ (_| (_) | | |  __/ |_) | (_) | (_| | | | (_| |\n"
           "|___/\\___\\___/|_|  \\___|_.__/ \\___/ \\__,_|_|  \\__,_|\n"
           "                                                    \n");
    printf("======================================================================\n");
    printf("Username                     Shots Fired                  Missed Shots\n");
    printf("[%s]                         [%s]                     [%s]\n", pseudo, shots, missed);
    printf("======================================================================\n");

    system("PAUSE");
    system("CLS");

} //This function will show the last user and his score

int winningCondition(int shots_fired, int missed_shots, int total_hp, char *name_transfer) {
    int Win = 0, shots = 0, missed = 0;
    char pseudo[TAILLE_MAX] = "";

    strcpy(pseudo, name_transfer);

    shots = shots_fired;
    missed = missed_shots;

    FILE *Pseudo = NULL;
    FILE *Shots = NULL;
    FILE *Missed = NULL;

    if (total_hp == 0) { //winning dialogue
        printf("[Radio Command] Seems like we got em all, we got no more hostile activity on the radar.\n");
        printf("You: Well that was easy ! Let's leave this sea and rest.\n");
        getch();

        system("CLS");

        printf("=================================================================================\n");
        printf("                                 _         _       _   _                 \n"
               "                                | |       | |     | | (_)                \n"
               "  ___ ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___ \n"
               " / __/ _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __|\n"
               "| (_| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\\n"
               " \\___\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/\n"
               "                  __/ |                                                  \n"
               "                 |___/                                                   \n");
        printf("=================================================================================\n");
        printf("User %s won, you shot %d times and missed %d times.\n", name_transfer, shots_fired, missed_shots);
        printf("Congratulation ! And most importantly...\n");
        printf("OwO [T H A N K  Y O U  F O R  P L A Y I N G] OwO\n");

        //Writes the score info on an external file
        Pseudo = fopen("cmake-build-debug\\Pseudo.txt", "w");

        if (Pseudo != NULL) {
            fprintf(Pseudo, "%s", pseudo);
            fclose(Pseudo);
        } else {
            printf("[Impossible d'enregistrer l'utilisateur dans le fichier Pseudo.txt !]\n");
        }

        Shots = fopen("cmake-build-debug\\Tirs.txt", "w");

        if (Shots != NULL) {
            fprintf(Shots, "%d", shots);
            fclose(Shots);
        } else {
            printf("[Impossible d'enregistrer le nombre de tirs dans le fichier Tirs.txt !]\n");
        }

        Missed = fopen("cmake-build-debug\\Rates.txt", "w");

        if (Missed != NULL) {
            fprintf(Missed, "%d", missed);
            fclose(Missed);
        } else {
            printf("[Impossible d'enregistrer le nombre d'echecs (tirs) dans le fichier Rates.txt !]\n");
        }

        system("PAUSE");
        system("CLS");
        Win = 1;
        return (Win);
    }
} //This function checks if the player has won or not

void showMenu() {
    printf("[1] Help\n");
    printf("[2] Info\n");
    printf("[3] About us\n");
    printf("[4] Play\n");
    printf("[5] Quit\n");
} //This function shows the available options of the menu

void helpMenu(int Choice) {
    int Choice2 = 0;

    switch (Choice) {
        case 1: //This case shows the help menu and its content

            while (Choice2 != 6) { //This will keep repeating so that the user doesn't have to reopen the help menu
                //each times he choose a question, however he can go back to the main menu if he
                //inputs the number [6], Go back to main menu

                system("CLS");

                printf("======================================================================\n");
                printf("\t\t\t  Help Menu [N.W.S.]\n");
                printf("======================================================================\n");
                printf("[1] How to play\n");
                printf("[2] How to start playing\n");
                printf("[3] Info button\n");
                printf("[4] About us button\n");
                printf("[5] Game not working\n");
                printf("[6] Go back to main menu\n");
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


                    case 3: //Info button [3]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("The Info button ([3]) of the main menu will give you basic info of the\n");
                        printf("game, it's version as well as its known bugs if there are any and a\n");
                        printf("link to the github page of the game");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 4: //About us button [4]

                        system("CLS");

                        printf("======================================================================\n");
                        printf("The About us button ([4]) of the main menu will give you info about\n");
                        printf("the author of this game and the people who helped test this game\n");
                        printf("======================================================================\n");

                        system("PAUSE");

                        break;

                    case 5: //Game not working [5]

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

                    case 6:
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

void infoMenu(int Choice) {

    if (Choice == 2) {
        system("CLS");

        printf("=======================================================================\n");
        printf("\t\t\t  Info Menu [N.W.S.]\n");
        printf("======================================================================\n");
        printf("You are currently playing Naval Warfare Simulator [N.W.S.]\n");
        printf("Version        : 1.0\n");
        printf("Known bugs     : When typing a letter instead of a number, the game\n"
               "                 crashes.\n");
        printf("\n");
        printf("                 The program will crash when any spaces or non asked\n"
               "                 characters are inserted in a question.\n");
        printf("\n");
        printf("Github page    : https://github.com/FardelusDeletus/N-W-S\n");
        printf("======================================================================\n");
        system("PAUSE");
        system("CLS");

    }
} //This function shows the Info Menu

void aboutUsMenu(int Choice) {
    if (Choice == 3) {
        system("CLS");

        printf("======================================================================\n");
        printf("\t\t\t  About Us [N.W.S.]\n");
        printf("======================================================================\n");
        printf("I, the developper, am a first year at the CPNV and I'm looking to\n");
        printf("become an IT, and so I had to make this game as a test in my learning.\n");
        printf("======================================================================\n");
        printf("Developper      : Fardel Bastien\n");
        printf("Email Address   : bastien.fardel@cpnv.ch\n");
        printf("======================================================================\n");
        printf("Testers         : Gacon Kevin\n");
        printf("Email Address   : gacon.kevin@cpnv.ch\n");
        printf("======================================================================\n");
        printf("Head of project : Benzonana Pascal\n");
        printf("Email Address   : benzonana.pascal@cpnv.ch\n");
        printf("======================================================================\n");
        printf("Expert          : Xavier Carrel\n");
        printf("Email Address   : xavier.carrel@cpnv.ch\n");
        printf("======================================================================\n");
        system("PAUSE");
        system("CLS");
    }
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

void shoot(char *name, int i) {
    int target_line = 0, target_col = 0, shots_fired = 0, missed_shots = 0, total_hp = TOTAL_HEALTH, recon_hp = RECON_HEALTH, enforcer_hp = ENFORCER_HEALTH,
            submarines_hp = SUBMARINES_HEALTH, cruiser_hp = CRUISER_HEALTH, carrier_hp = CARRIER_HEALTH, win_game;

    char name_transfer[TAILLE_MAX];

    strcpy(name_transfer, name);

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

            if (target_line > 8) {
                printf("[Radio Command] Hum... Sir this isn't in the range, the range is of 9.\n");
            }
        } while (target_line > 8);

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

                        if (submarines_hp == 3) {
                            printf("[Radio Command] We got one of their submarines !\n");
                        } else {
                            if (submarines_hp == 0) {
                                printf("[Radio Command] Hostile submarines have been destroyed !\n");
                            }
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
                                    printf("[Radio Command] We destroyed their carrier !\n");
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

                shots_fired = shots_fired + 1;
                missed_shots = missed_shots + 1;
            } else {

                if (StaticMap[target_line][target_col] == 2 || StaticMap[target_line][target_col] == 3) {
                    printf("[Radio Command] We already shot here...\n");
                }
                shots_fired = shots_fired + 1;
                missed_shots = missed_shots + 1;
            }
        }

        win_game = winningCondition(shots_fired, missed_shots, total_hp, name_transfer);

        showScoreboard();

    } while (win_game != 1);
} //This function lets the player shoot

void play(int Choice) {

    if (Choice == 4) {

        int i = 0;

        char name[TAILLE_MAX];

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
        printf("======================================================================\n");
        printf("What is your name captain ? (Please do not input spaces)");
        scanf("%s", name);

        shoot(name, i);

    }
} //This function starts the game


int main() {
    int Choice;

    do { //This while loop will keep repeating until an option is chosen or the user quits by typing [6]
        printf("======================================================================\n"); //showing the main interface
        printf("                __/___            \n"
               "          _____/______|           \n"
               "  _______/_____\\_______\\_____     \n"
               "  \\              < < <       |    \n"
               "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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
        infoMenu(Choice); //Calls upon the infoMenu function
        aboutUsMenu(Choice); //Calls upon the aboutUsMenu function
        play(Choice); //Calls upon the play function

        if (Choice > 5 || Choice <= 0) {
            printf("\t\t    [!] This isn't an option [!]\n");
        }
    } while (Choice != 5);

    return 0;
}