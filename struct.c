/* Minigame using struct */
#include <stdio.h>
#include <string.h>

#define LEVELCAP 4

struct player_stats {
    unsigned int HP;
    unsigned int MP;
    unsigned int XP;
    unsigned int LVL;
};

struct player_specs {
    unsigned int STR : 4;
    unsigned int PER : 4;
    unsigned int END : 4;
    unsigned int CHR : 4;
    unsigned int INT : 4;
    unsigned int AGL : 4;
    unsigned int LCK : 4;
};

char *enter_name(void);
int character_init(char *str);


void main(void)
{
    char *player_name;
    int choice;

    player_name = enter_name();

    choice = character_init(player_name);
}


/* Take player's name and say welcome */
char *enter_name(void)
{
    static char str[20];
    printf("Welcome to Randy's mingame.\n");

    do {
        printf("Enter a valid name shorter than 20 characters:\n");
        gets(str);
    } while (!str[0] || strlen(str) > 20);

    printf("\nWelcome, %s\n\n", str);
    return str;
}

/* Player chooses character number */
int character_init(char *str)
{
    char a[50];
    int b;

    printf("\t1. Developer Hogang\n");
    printf("\t\t\n");
    printf("\t2. Rap-monster Woon\n");
    printf("\t\t\n");
    printf("\t3. KATUSA Benny\n");
    printf("\t\t\n");
    printf("\t4. Sleeping Juice\n");
    printf("\t\t\n");

    do {
        printf("Select a character to start with.\n");
        printf("Remember %s, this is crucial to your gameplay.\n", str);
        gets(a);
        b = atoi(a);
    } while (b > 4 || b < 1);

    printf("You have chosen %d\n", b);
    return b;
}
