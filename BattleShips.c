#include <stdio.h>

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

char *players_field[] = {
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

char *enemy_field[] = {
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

char *enemy_ships[] = {
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
//------------symbols-conformity-end-----------------------------------------------

typedef enum
{
    A = 0,B,C,D,E,F,G,H,I,J
}field_coords_laters;

//------------ships----------------------------------------------------------------
typedef enum ships_types
{
    BOAT = 1, CRUISERS, DESTROYERS, BATTLESGIPS, SHIPS_TYPES_END 
};

int players_ships[SHIPS_TYPES_END] = {NULL, 4, 3, 2, 1};

int enemys_ships[SHIPS_TYPES_END] = {NULL, 4, 3, 2, 1};
//------------ships-end------------------------------------------------------------

void print_field();
void shoot(char**);

int main()
{
    print_field();
    return 0;
}

int* get_coords(const char*)
{
    
}

void shoot(char* position, char** tabel)
{


}

void print_field()
{
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
    printf("%s", field[12]);
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