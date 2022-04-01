#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define BZ_HEIGHT 10
#define BZ_WIDTH 20


const char *BZ[] = {
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

const char *logo[] = {
" _______  _______  _______  _______  _______  _______  _______  ___      _______ ",
"|       ||       ||   _   ||  _    ||   _   ||       ||       ||   |    |       |",
"|  _____||    ___||  |_|  || |_|   ||  |_|  ||_     _||_     _||   |    |    ___|",
"| |_____ |   |___ |       ||       ||       |  |   |    |   |  |   |    |   |___ ",
"|_____  ||    ___||       ||  _   | |       |  |   |    |   |  |   |___ |    ___|",
" _____| ||   |___ |   _   || |_|   ||   _   |  |   |    |   |  |       ||   |___ ",
"|_______||_______||__| |__||_______||__| |__|  |___|    |___|  |_______||_______|"
}; 

char menu[3][15]  = {
    "  With Bot   ",
    "  With Friend",
    "  Exit!"
};


int GAME_MODE;


//------------symbols-conformity---------------------------------------------------
typedef enum
{
    EMPTY = 0,SHOT_L,SHOT_R,STRIKE_L,STRIKE_R,KILL_L,KILL_R,SHIP_L,SHIP_R,AIM_L,AIM_R,EFIELD_INFO_END
}eField;

char draw_fields[EFIELD_INFO_END] = {
    ' ',       //EMPTY 
    '(', ')',  //SHOT_L AND SHOT_R
    '>', '<',  //STRIKE_L AND STRICK_R
    '}', '{',  //KILL_L AND KILL_R
    '[', ']',  //SHIP_L AND SHIP_R
    ':', ':'
       //AIM_L AND AIM_R
};

// ------------ships----------------------------------------------------------------
typedef enum
{
    BOAT = 0, CRUISERS, DESTROYERS, BATTLESGIPS, SHIPS_TYPES_END 
}ships_types;
// ------------ships-end------------------------------------------------------------

typedef struct
{
    char shots[BZ_HEIGHT * BZ_WIDTH];
    char fleet[BZ_HEIGHT * BZ_WIDTH];
    int ships[SHIPS_TYPES_END];
    int is_bot;
    
}Player;

void print_bz(Player *, Player *);
void shoot(int *, Player *);
int choose_mode();
void print_menu(int, int);
void set_player(Player *);
int *set_target(Player *);

Player player1, player2;
Player *player1_p = &player1;
Player *player2_p = &player2;

int main()
{       
    set_player(player1_p);
    set_player(player2_p);

    player1.fleet[BZ_WIDTH + 2] = draw_fields[SHIP_L];
    player1.fleet[BZ_WIDTH + 3] = draw_fields[SHIP_R];

    for(int i = 0; i < 10; i++){
        int *target = set_target(player1_p);
        shoot(target, player1_p);
        print_bz(player1_p, player2_p);
    }
}

void set_player(Player *plr)
{
    memset(plr->fleet, draw_fields[EMPTY], sizeof(plr->fleet));
    memset(plr->shots, draw_fields[EMPTY], sizeof(plr->shots));
    for(int i = 0, j = SHIPS_TYPES_END; i < SHIPS_TYPES_END; i++, j--){
        plr->ships[i] = j;
    }
    plr->is_bot = 0;
}

short* get_coords(char position[2])
{
    short *coords = malloc(2 * sizeof(short));
    coords[0] = toupper(position[0]) - 65;
    coords[1]= position[1] - 48;
    return coords;
}

int *set_target(Player *plr1)
{
    int point_x = 5 * BZ_WIDTH / 10;
    int point_y = 5 * BZ_HEIGHT / 10;
    char c;

    char prev_symb_l = plr1->shots[point_y * BZ_WIDTH + point_x];
    char prev_symb_r = plr1->shots[point_y * BZ_WIDTH + point_x + 1];
    plr1->shots[point_y * BZ_WIDTH + point_x] = draw_fields[AIM_L];
    plr1->shots[point_y * BZ_WIDTH + point_x + 1] = draw_fields[AIM_R];

    do{
        print_bz(player1_p, player2_p);

        plr1->shots[point_y * BZ_WIDTH + point_x] = prev_symb_l;
        plr1->shots[point_y * BZ_WIDTH + point_x + 1] = prev_symb_r;

        c = getch();
        if(c == 100) point_x +=2;
        else if(c == 97) point_x -=2;
        else if(c == 115) point_y++;
        else if(c == 119) point_y--;

        point_x %= BZ_WIDTH;
        point_y %= BZ_HEIGHT;
        if(point_x < 0) point_x += BZ_WIDTH;
        if(point_y < 0) point_y += BZ_HEIGHT;

        prev_symb_l = plr1->shots[point_y * BZ_WIDTH + point_x];
        prev_symb_r = plr1->shots[point_y * BZ_WIDTH + point_x + 1];
        plr1->shots[point_y * BZ_WIDTH + point_x] = draw_fields[AIM_L];
        plr1->shots[point_y * BZ_WIDTH + point_x + 1] = draw_fields[AIM_R];
        
    }while(c != 13);

    int *position = malloc(2 * sizeof(int));
    position[0] = point_x;
    position[1] = point_y;
    return position;
}


void set_ships(char tabel[BZ_HEIGHT][BZ_WIDTH])
{
    // for(int i = 3; i >= 0; i--){
    //     for(int j = )
    // }

}

void shoot(int position[2], Player *plr)
{
    if(plr->fleet[position[1] * BZ_WIDTH + position[0]] == draw_fields[SHIP_L])
    {
        plr->shots[position[1] * BZ_WIDTH + position[0]] = draw_fields[STRIKE_L];
        plr->shots[position[1] * BZ_WIDTH + position[0] + 1] = draw_fields[STRIKE_R];
    }
    else 
    {
        plr->shots[position[1] * BZ_WIDTH + position[0]] = draw_fields[SHOT_L];
        plr->shots[position[1] * BZ_WIDTH + position[0] + 1] = draw_fields[SHOT_R];
    }
}

void print_bz(Player *plr1, Player *plr2)
{   
    system("cls");
    printf("\n%s\n%s\n", BZ[0], BZ[1]);
    for(int i = 0; i < BZ_HEIGHT; ++i)
    {
        for(int j = 0; j < 2; j++) printf("%c", BZ[i + 2][j]);

        // ----------------1 person's ships---------------------
        for(int j = 0; j < BZ_WIDTH; j++) printf("%c", plr1->shots[i * BZ_WIDTH + j]);
        // -----------------------------------------------------

        for(int j = BZ_WIDTH + 2; j < BZ_WIDTH + 8; j++) printf("%c", BZ[i + 2][j]);

        //----------------2 person's ships---------------------
        for(int j = 0; j < BZ_WIDTH; j++) printf("%c", plr2->shots[i * BZ_WIDTH + j]);
        //-----------------------------------------------------

        printf("%c", BZ[i + 2][2 * BZ_WIDTH + 8]);
        printf("\n");
    }
    printf("%s\n", BZ[12]);
}

//--------------MENU------------------------------------------------
int choose_mode()
{   
    int menu_items = sizeof(menu)/(sizeof(menu[0]) / sizeof(char));

    print_menu(0, menu_items);
    int point = 0;
    char c;
    do{
        c = getch();
        if(c == 115) point++;
        else if(c == 119) point--;

        point %= menu_items;
        if(point < 0) point += menu_items;
        print_menu(point, menu_items);
    }while(c != 13);

    return point;
}

void print_menu(int choice, int items)
{
    system("cls");
    printf("\n");
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 17; j++)
            printf(" ");
        printf("%s\n", logo[i]);
    }
    printf("\n\n");

    for(int i = 0; i < items; i++) menu[i][0] = ' ';
    menu[choice][0] = '>';

    for(int i = 0; i < items; i++){
        for(int j = 0; j < 48; j++) printf(" ");
        printf("%s\n", menu[i]);
    }
}
//--------------MENU-end--------------------------------------------

// formula for random number in range from lower to upper:
// number = (rand() % (upper - lower + 1)) + lower