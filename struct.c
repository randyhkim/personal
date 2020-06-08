/* Minigame using struct */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 21
#define LEVELCAP 4
#define PREMADE_WARRIORS 5

struct player_specs {
    unsigned int STR : 4;
    unsigned int PER : 4;
    unsigned int END : 4;
    unsigned int CHR : 4;
    unsigned int INT : 4;
    unsigned int AGL : 4;
    unsigned int LCK : 4;
} specs;

struct player_stats {
    char name[10];
    unsigned int HP;
    unsigned int MP;
    unsigned int XP;
    unsigned int LVL;
    struct player_specs specs;
};

char *enter_name(void);
int character_init(char *str);
void character_stat(struct player_stats warrior);
void accept(void);


void main(void)
{
    char *player_name;
    int choice;

    struct player_stats warriors[PREMADE_WARRIORS];
    struct player_specs specs;

    strcpy(warriors[0].name, "Hogang");
    warriors[0].HP = 100;
    warriors[0].MP = 100;
    warriors[0].XP = 0;
    warriors[0].LVL = 1;
    warriors[0].specs.PER = 3;
    warriors[0].specs.STR = 3;
    warriors[0].specs.END = 3;
    warriors[0].specs.CHR = 3;
    warriors[0].specs.INT = 3;
    warriors[0].specs.AGL = 3;
    warriors[0].specs.LCK = 3;

    strcpy(warriors[1].name, "Woon");
    warriors[1].HP = 100;
    warriors[1].MP = 100;
    warriors[1].XP = 0;
    warriors[1].LVL = 1;
    warriors[1].specs.PER = 3;
    warriors[1].specs.STR = 3;
    warriors[1].specs.END = 3;
    warriors[1].specs.CHR = 3;
    warriors[1].specs.INT = 3;
    warriors[1].specs.AGL = 3;
    warriors[1].specs.LCK = 3;

    strcpy(warriors[2].name, "Bug");
    warriors[2].HP = 100;
    warriors[2].MP = 100;
    warriors[2].XP = 0;
    warriors[2].LVL = 1;
    warriors[2].specs.PER = 3;
    warriors[2].specs.STR = 3;
    warriors[2].specs.END = 3;
    warriors[2].specs.CHR = 3;
    warriors[2].specs.INT = 3;
    warriors[2].specs.AGL = 3;
    warriors[2].specs.LCK = 3;

    strcpy(warriors[3].name, "Juice");
    warriors[3].HP = 100;
    warriors[3].MP = 100;
    warriors[3].XP = 0;
    warriors[3].LVL = 1;
    warriors[3].specs.PER = 3;
    warriors[3].specs.STR = 3;
    warriors[3].specs.END = 3;
    warriors[3].specs.CHR = 3;
    warriors[3].specs.INT = 3;
    warriors[3].specs.AGL = 3;
    warriors[3].specs.LCK = 3;

    strcpy(warriors[4].name, "Diva");
    warriors[4].HP = 100;
    warriors[4].MP = 100;
    warriors[4].XP = 0;
    warriors[4].LVL = 1;
    warriors[4].specs.PER = 3;
    warriors[4].specs.STR = 3;
    warriors[4].specs.END = 3;
    warriors[4].specs.CHR = 3;
    warriors[4].specs.INT = 3;
    warriors[4].specs.AGL = 3;
    warriors[4].specs.LCK = 3;

    printf("STR is %d\n", warriors[0].specs.STR);

    player_name = enter_name();

    choice = character_init(player_name);

    character_stat(warriors[choice - 1]);
    
    accept();
}


/* Take player's name and say welcome */
char *enter_name(void)
{
    static char str[NAME_MAX];
    printf("Welcome to Randy's mingame.\n");

    do {
        printf("Enter a valid name (max %d characters):\n", NAME_MAX - 1);
        fgets(str, NAME_MAX, stdin);
    } while (!str[1] || strlen(str) > NAME_MAX - 1);
    /* TODO: even if input is longer than 20, while loop doesn't execute.
             Instead, str is cut off after 20 letters without any message.

    /* Cut off str starting from trailing newline */
    for(int i; str[i]; i++) {
        if (str[i] == '\n') {
            str[i] = EOF;
            break;
        }
    }

    printf("\n[Welcome, %s]\n\n", str);
    return str;
}

/* Player chooses character number */
int character_init(char *str)
{
    char a[256];
    int b;

    printf("당신은 시공의 폭풍에 빨려들어갑니다.\n\n");
    printf("===========================================================\n\n");
    printf("정신을 차려보니 나는 논산훈련소에서 신검을 받고 있다.\n");
    printf("신검 검사표를 읽어보니 이름이 익숙치 않다.\n");
    printf("'저기에 적혀있는 내 이름은 뭐지?'\n\n");

    printf("\t1. American Hogang\n");
    printf("\t\t패시브: Bald Eagle\n");
    printf("\t\t설명: 전직 시 어학병 선택 가능.\n");
    printf("\n");
    printf("\t2. Rap-monster Woon\n");
    printf("\t\t패시브: Hong-dae Master\n");
    printf("\n");
    printf("\t3. KATUSA Bug\n");
    printf("\t\t패시브: TGIF\n");
    printf("\n");
    printf("\t4. Sleeping Juice\n");
    printf("\t\t패시브: Natural Leader\n");
    printf("\n");
    printf("\t5. Diva\n");
    printf("\t\t패시브: Busan Gashina\n");
    printf("\n");

    do {
        printf("번호를 입력하여 전사를 선택하십시오.\n");
        printf("기억하십시오 %s님. 당신이 고른 전사로 군생활을 하는것입니다.\n", str);
        fgets(a, sizeof(a), stdin);
        /* TODO: look into the meaning of sizeof(a) here. Also, if I use 3
                 instead of sizeof(a), the do-while loop seems to run
                 automatically when inputting multi-character strings. */
        b = atoi(a);
    } while (b > PREMADE_WARRIORS || b < 1);

    printf("\n[You have chosen %d]\n\n", b);
    return b;
}

/* Read and edit character stats. */
void character_stat(struct player_stats warrior)
{
    printf("자세히 보니, 내 이름은 %s이군...\n", warrior.name);
    printf("[검진표를 자세히 보니 수치가 보인다]\n\n");
    printf("=====================================\n");
    printf("==== HP ==== MP ==== XP ==== LVL ====\n");
    printf("=====================================\n");
    printf("|  %4d    %4d    %4d      %4d   |\n", warrior.HP, warrior.MP, warrior.XP, warrior.LVL);
    printf("=====================================\n");
    printf("=====================================\n");
    printf("|   STR || %d                        |\n", warrior.specs.STR);
    printf("|   PER || %d                        |\n", warrior.specs.PER);
    printf("|   END || %d                        |\n", warrior.specs.END);
    printf("|   CHR || %d                        |\n", warrior.specs.CHR);
    printf("|   INT || %d                        |\n", warrior.specs.INT);
    printf("|   AGL || %d                        |\n", warrior.specs.AGL);
    printf("|   LCK || %d                        |\n", warrior.specs.LCK);
    printf("=====================================\n");
    printf("\n");
    // TODO: Add functionality to edit character stats.
}

/* Prompt 확인 button */
void accept(void)
{
    char s[256];
    do {
        printf("[Enter눌러서 확인]\n");
        fgets(s, sizeof(s), stdin);
    } while (s[0] != '\n');
    printf("확인완료\n");
}