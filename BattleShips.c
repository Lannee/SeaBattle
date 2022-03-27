#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

//------------ships----------------------------------------------------------------
// typedef enum ships_types
// {
//     BOAT = 1, CRUISERS, DESTROYERS, BATTLESGIPS, SHIPS_TYPES_END 
// };

// int players_ships[SHIPS_TYPES_END] = {4, 3, 2, 1};

// int enemys_ships[SHIPS_TYPES_END] = {4, 3, 2, 1};
//------------ships-end------------------------------------------------------------

void print_field();
void shoot(char *, char[BZ_HEIGHT][BZ_WIDTH]);

int main()
{   
    print_field();
    shoot("A1", players_field);
    getch();
    print_field();
    shoot("J6", players_field);
    getch();
    print_field();
    shoot("D8", enemy_field);
    getch();
    print_field();
    return 0;
}

typedef enum
{
    A = 0,B,C,D,E,F,G,H,I,J
}field_coords_laters;

short* get_coords(char *position)
{
    short *coords = malloc(2 * sizeof(short *));
    coords[0] = position[0] - 65;
    coords[1]= position[1] - 48;
    return coords;
}

void shoot(char *position, char tabel[BZ_HEIGHT][BZ_WIDTH])
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

// void shoot(char *position, char **tabel)
// {
//     short *coords = get_coords(position);
//     // char *tabel[coords[0]][coords[1]] = *(tabel + coords[0]) + coords[1];
//     if(tabel[coords[0]][coords[1]] == draw_fields[SHIP]) {tabel[coords[0]][coords[1]] = draw_fields[STRIKE];}
//     else {tabel[coords[0]][coords[1]] = draw_fields[SHOT];}
// }