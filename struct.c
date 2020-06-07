/* Minigame using struct */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_MAX 21
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

    printf("\nWelcome, %s\n\n", str);
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

    do {
        printf("번호를 입력하여 캐릭터를 선택하십시오.\n");
        printf("기억하십시오 %s님. 당신이 고른 캐릭터로 군생활을 하는것입니다.\n", str);
        fgets(a, sizeof(a), stdin);
        /* TODO: look into the meaning of sizeof(a) here. Also, if I use 3
                 instead of sizeof(a), the do-while loop seems to run
                 automatically when inputting multi-character strings. */
        b = atoi(a);
    } while (b > 4 || b < 1);

    printf("You have chosen %d\n", b);
    return b;
}
