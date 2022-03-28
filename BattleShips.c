#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define BZ_HEIGHT 10
#define BZ_WIDTH 20


const char *field[] ={
    "  A B C D E F G H I J       A B C D E F G H I J  ",
    " /--------------------\\    /--------------------\\",
    "0|                    |   0|                    |",
    "1|                    |   1|                    |",
    "2|                    |   2|                    |",
    "3|                    |   3|                    |",
    "4|                    |   4|                    |",
    "5|                    |   5|                    |",
    "6|                    |   6|                    |",
    "7|                    |   7|                    |",
    "8|                    |   8|                    |",
    "9|                    |   9|                    |",
    " \\--------------------/    \\--------------------/"

};

char players_field[BZ_HEIGHT][BZ_WIDTH] = {
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};

char players_ships[BZ_HEIGHT][BZ_WIDTH] = {
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};

char enemy_field[BZ_HEIGHT][BZ_WIDTH] = {
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};

char enemy_ships[BZ_HEIGHT][BZ_WIDTH] = {
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    ",
    "                    "
};

const char *logo[] = {
" _______  _______  _______  _______  _______  _______  _______  ___      _______ ",
"|       ||       ||   _   ||  _    ||   _   ||       ||       ||   |    |       |",
"|  _____||    ___||  |_|  || |_|   ||  |_|  ||_     _||_     _||   |    |    ___|",
"| |_____ |   |___ |       ||       ||       |  |   |    |   |  |   |    |   |___ ",
"|_____  ||    ___||       ||  _   | |       |  |   |    |   |  |   |___ |    ___|",
" _____| ||   |___ |   _   || |_|   ||   _   |  |   |    |   |  |       ||   |___ ",
"|_______||_______||__| |__||_______||__| |__|  |___|    |___|  |_______||_______|"
}; 

char menu[2][15]  = {
    "  With Bot   ",
    "  With Friend"
};


int GAME_MODE;


//------------symbols-conformity---------------------------------------------------
typedef enum
{
    EMPTY = 0,SHOT,STRIKE,KILL,SHIP,EFIELD_INFO_END
}eField;

char draw_fields[EFIELD_INFO_END] = {
    ' ', //EMPTY 
    '@', //SHOT
    '*', //STRIKE
    'X', //KILL
    '#' //SHIP
};

// ------------ships----------------------------------------------------------------
typedef enum
{
    BOAT = 0, CRUISERS, DESTROYERS, BATTLESGIPS, SHIPS_TYPES_END 
}ships_types;

// int players_ships[SHIPS_TYPES_END] = {4, 3, 2, 1};

// int enemys_ships[SHIPS_TYPES_END] = {4, 3, 2, 1};
// ------------ships-end------------------------------------------------------------

void print_field();
void shoot(char *, char[BZ_HEIGHT][BZ_WIDTH]);
void choose_mode();
void print_menu(int);

int main()
{       
    choose_mode();
    
    return 0;
}

short* get_coords(char position[2])
{
    short *coords = malloc(2 * sizeof(short));
    coords[0] = toupper(position[0]) - 65;
    coords[1]= position[1] - 48;
    return coords;
}

void set_ships()
{


}

void shoot(char position[2], char tabel[BZ_HEIGHT][BZ_WIDTH])
{
    short *coords = get_coords(position);
    if(tabel[coords[1]][coords[0] * 2] == draw_fields[SHIP])
    {
        tabel[coords[1]][coords[0] * 2] = draw_fields[STRIKE];
        tabel[coords[1]][coords[0] * 2 + 1] = draw_fields[STRIKE];
    }
    else 
    {
        tabel[coords[1]][coords[0] * 2] = draw_fields[SHOT];
        tabel[coords[1]][coords[0] * 2 + 1] = draw_fields[SHOT];
    }
    free(coords);
}

void print_field()
{   
    system("cls");
    printf("%s\n%s\n", field[0], field[1]);
    for(int i = 0; i < BZ_HEIGHT; ++i)
    {
        for(int j = 0; j < 2; j++) printf("%c", field[i + 2][j]);

        //----------------1 person's ships---------------------
        for(int j = 0; j < BZ_WIDTH; j++) printf("%c", players_field[i][j]);
        //-----------------------------------------------------

        for(int j = BZ_WIDTH + 2; j < BZ_WIDTH + 8; j++) printf("%c", field[i + 2][j]);

        //----------------2 person's ships---------------------
        for(int j = 0; j < BZ_WIDTH; j++) printf("%c", enemy_field[i][j]);
        //-----------------------------------------------------

        printf("%c", field[i + 2][2 * BZ_WIDTH + 8]);
        printf("\n");
    }
    printf("%s\n", field[12]);
}

//--------------MENU------------------------------------------------
void choose_mode()
{   
    print_menu(0);

    int move = 0;
    char c;
    do{
        c = getch();
        if(c == 119 || c == 115){
            move++;
        }
        print_menu(move);

    }while(c != 13);
    GAME_MODE = move % 2;
    printf("%d", GAME_MODE);

}

void print_menu(int choice)
{
    system("cls");
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 17; j++)
            printf(" ");
        printf("%s\n", logo[i]);
    }
    printf("\n\n");
    menu[choice % 2][0] = '>';
    menu[(choice + 1) % 2][0] = ' ';
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 48; j++) printf(" ");
        printf("%s\n", menu[i]);
    }
}
//--------------MENU-end--------------------------------------------
// const char *field[] ={
//     "  ABCDEFGHIJ      ABCDEFGHIJ",
//     " *----------*    *----------*",
//     "0|          |   0|          |",
//     "1|          |   1|          |",
//     "2|          |   2|          |",
//     "3|          |   3|          |",
//     "4|          |   4|          |",
//     "5|          |   5|          |",
//     "6|          |   6|          |",
//     "7|          |   7|          |",
//     "8|          |   8|          |",
//     "9|          |   9|          |",
//     " *----------*    *----------*"
// };

// formula for random number in range from lower to upper:
// number = (rand() % (upper - lower + 1)) + lower