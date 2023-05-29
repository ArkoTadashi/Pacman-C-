

#include "iGraphics.h"
#include <windows.h>
#include <math.h>

#pragma comment(lib,"winmm.lib")

#define pi acos(-1.0)



//resolutions
int scheight = 690, scwidth = 1100;





//maze
int maze[23][29] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
{1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
//
{1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1},
{0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
{1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},

{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
{1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1},
{0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
{1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
//
{1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
{1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
{1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int balls[23][29];






//screens
int Main = 1, NewG, Pause, High, Help, Cred, Sett, Exit;





//structures
typedef struct _time {
    int hour;
    int minute;
    int second;
    int millisecond;
} times;

typedef struct _character {
    int x;
    int y;
    int dx;
    int dy;
    int cidx;
    int st;
    int fr;
    int eat;
    int tx;
    int ty;
    times tai;
} character;


void updateCharacter (character* p, int x, int y, int dx, int dy, int cidx, int st, int fr, int eat) {
    p->x = x;
    p->y = y;
    p->dx = dx;
    p->dy = dy;
    p->cidx = cidx;
    p->st = st;
    p->fr = fr;
    p->eat = eat;
}

void timeReset (times* t) {
    t->hour = t->millisecond = t->minute = t->second = 0;
}


void updateTime (times* t) {
    t->millisecond += 20;
    if (t->millisecond >= 1000) {
        t->millisecond = 0;
        t->second += 1;
    }
    if (t->second == 60) {
        t->second = 0;
        t->minute += 1;
    }
    if (t->minute == 60) {
        t->minute = 0;
        t->hour += 1;
    }
}





//variables
int color[10][3] = {{255, 255, 255}, {255, 0, 0}, {255, 165, 0}, {255, 255, 0}, {191, 255, 0}, {0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {128, 0, 128}, {255, 0, 255}};
character player;
character blinky;
character pinky;
character inky;
character clyde;
times t1, t2, t3;
int eatidx = -1;
int pidx;
int velocity = 3;
int gvelocity = 2;
int b_count;
int level = 1;
int life = 3;
int score;
char tstr[50];
char sstr[20];
int rx, ry, rt;
char nameStr[100];
int len;

int ddx[4] = {-1, 0, 1, 0};
int ddy[4] = {0, 1, 0, -1};

char HSNAME[10][100];
int HSSCORE[10];
char HSNSCORE[10][100];


//bool variables
int up, down, left, right, turns, fright, eatch, tchk, tshow, hscore, sound;
int alive = 1;
int gMode;
int gOver;





//bmps
char mpac[8][20] = {"Sprites\\l1pac.bmp", "Sprites\\l2pac.bmp", "Sprites\\u1pac.bmp", "Sprites\\u2pac.bmp", "Sprites\\r1pac.bmp", "Sprites\\r2pac.bmp", "Sprites\\d1pac.bmp", "Sprites\\d2pac.bmp"};
char blink[8][20] = {"Sprites\\l1b.bmp", "Sprites\\l2b.bmp", "Sprites\\u1b.bmp", "Sprites\\u2b.bmp", "Sprites\\r1b.bmp", "Sprites\\r2b.bmp", "Sprites\\d1b.bmp", "Sprites\\d2b.bmp"};
char pink[8][20] = {"Sprites\\l1p.bmp", "Sprites\\l2p.bmp", "Sprites\\u1p.bmp", "Sprites\\u2p.bmp", "Sprites\\r1p.bmp", "Sprites\\r2p.bmp", "Sprites\\d1p.bmp", "Sprites\\d2p.bmp"};
char ink[8][20] = {"Sprites\\l1i.bmp", "Sprites\\l2i.bmp", "Sprites\\u1i.bmp", "Sprites\\u2i.bmp", "Sprites\\r1i.bmp", "Sprites\\r2i.bmp", "Sprites\\d1i.bmp", "Sprites\\d2i.bmp"};
char clyd[8][20] = {"Sprites\\l1c.bmp", "Sprites\\l2c.bmp", "Sprites\\u1c.bmp", "Sprites\\u2c.bmp", "Sprites\\r1c.bmp", "Sprites\\r2c.bmp", "Sprites\\d1c.bmp", "Sprites\\d2c.bmp"};

char death[12][20] = {"Sprites\\dead1.bmp", "Sprites\\dead2.bmp", "Sprites\\dead3.bmp", "Sprites\\dead4.bmp", "Sprites\\dead5.bmp", "Sprites\\dead6.bmp", "Sprites\\dead7.bmp", "Sprites\\dead8.bmp", "Sprites\\dead9.bmp", "Sprites\\dead10.bmp", "Sprites\\dead11.bmp", "Sprites\\dead12.bmp"};
char power[3][20] = {"Sprites\\power1.bmp", "Sprites\\power2.bmp", "Sprites\\power3.bmp"};
char party[4][20] = {"Sprites\\party1.bmp", "Sprites\\party2.bmp", "Sprites\\party3.bmp", "Sprites\\party4.bmp"};
char eaten[4][20] = {"Sprites\\le.bmp", "Sprites\\ue.bmp", "Sprites\\re.bmp", "Sprites\\de.bmp"};
char eat[4][20] = {"Sprites\\ep1.bmp", "Sprites\\ep2.bmp", "Sprites\\ep3.bmp", "Sprites\\ep4.bmp"};

char sounds[8][25] = {"Sounds\\MouseClick.wav", "Sounds\\Eat.wav", "Sounds\\Turn.wav", "Sounds\\Music2.wav"};

char name[10][20] = {"", "", "", "", "", "", "", "", "", ""};

char files[2][20] = {"HS_Name.txt", "HS_Score.txt"};


//functions


void arrHS (char* fname, char* fscore) {
    FILE* fpn = fopen (fname, "r");
    FILE* fps = fopen (fscore, "r");


    int i = 0;
    int x, y, z;
    char p[100] = "";
    char q[100] = "";
    while (1) {
        fgets (HSNAME[i], sizeof(HSNAME[i]), fpn);
        fscanf (fps, "%d", &z);
        //printf ("%d\n", z);
        //fgets (HSNSCORE[i], sizeof(HSNSCORE[i]), fps);
        sprintf (q, "%d", z);
        HSSCORE[i++] = z;
//        strcat (p, HSNAME[i++]);
//        x = strlen (p);
//        p[x-1] = '\0';
//        //strcat (p, HSNSCORE[i++]);
//        strcat (p, q);
//        //printf ("%s", p);
//        strcpy (p, "");


        if (feof (fps)) {
            break;
        }

    }

    fclose (fpn);
    fclose (fps);

}

void getHS (char* fname, char* fscore) {
    FILE* fpn = fopen (fname, "r");
    FILE* fps = fopen (fscore, "r");


    int i = 0;
    int x, y, z;
    char p[100] = "";
    char q[100] = "";
    while (1) {
        fgets (HSNAME[i], sizeof(HSNAME[i]), fpn);
        //fscanf (fps, "%d", &z);
        //printf ("%d\n", z);
        fgets (HSNSCORE[i], sizeof(HSNSCORE[i]), fps);
        //sprintf (q, "%d", z);
        //HSSCORE[i] = z;
        strcat (p, HSNAME[i]);
        x = strlen (p);
        p[x-1] = '\0';
        p[x] = '\0';
        strcat (p, HSNSCORE[i++]);
        x = strlen (p);
        p[x-1] = '\0';
        p[x] = '\0';
        //strcat (p, q);
        strcat (p, "\n");
        iText (400, 350-i*30, p, GLUT_BITMAP_9_BY_15);
//        if (i == 5) {
//            x = strlen (p);
//            p[x-1] = '\0';
//            iText (300, 500-i*30, p, GLUT_BITMAP_9_BY_15);
//        }
//        else {
//            iText (300, 500-i*30, p, GLUT_BITMAP_9_BY_15);
//        }



        strcpy (p, "");


        if (feof (fps)) {
            break;
        }

    }

    fclose (fpn);
    fclose (fps);


}

int chkHS (char* fname, char* fscore, int score) {
    FILE* fpn = fopen (fname, "a+");
    FILE* fps = fopen (fscore, "a+");

    int i = 0;
    int x = 0, y = 0;
    while (1) {
        //fgets (HSNAME[i], sizeof(HSNAME[i]), fpn);
        fscanf (fps, "%d", &x);
        //printf ("%d", x);
        i++;
        if (i == 10) {
            if (score > x) {
                y = 1;
            }
        }


        if (feof (fps)) {
            break;
        }

    }

    if (y) {
        strcpy (HSNAME[9], "");
        HSSCORE[9] = 0;
    }

    fclose (fpn);
    fclose (fps);


    return y;
}

void putHS (char* fname, char* fscore, int score, char name[100]) {
    FILE* fpn = fopen (fname, "w+");
    FILE* fps = fopen (fscore, "w+");

    HSSCORE[9] = score;
    strcpy (HSNAME[9], name);

    int i, j;
    int x = strlen (name);

    for (i = 0; i < 13-x; i++) {
        strcat (HSNAME[9], " ");
    }
    strcat (HSNAME[9], ": \n");

    for (i = 0; i < 10; i++) {
        for (j = i+1; j < 10; j++) {
            if (HSSCORE[i] < HSSCORE[j]) {
                int temp = HSSCORE[i];
                HSSCORE[i] = HSSCORE[j];
                HSSCORE[j] = temp;

                char stemp[100] = "";
                strcpy(stemp, HSNAME[i]);
                strcpy (HSNAME[i], HSNAME[j]);
                strcpy (HSNAME[j], stemp);

            }

        }
    }

    for (i = 0; i < 10; i++) {
        fputs (HSNAME[i], fpn);
        fprintf (fps, "%d\n", HSSCORE[i]);
    }


    fclose (fpn);
    fclose (fps);

}




void bCount () {
    if (b_count == 0 && level == 1) {

    }
    if (b_count == 0 && level == 2) {

    }
    if (b_count == 0 && level == 3) {

    }

}







void tReset () {
    timeReset (&t1);
    timeReset (&blinky.tai);
    timeReset (&pinky.tai);
    timeReset (&inky.tai);
    timeReset (&clyde.tai);
}

void filled_square (double x, double y, double p) {
    iFilledRectangle (x, y, p, p);
}

void coloring (int x) {
    iSetColor (color[x][0], color[x][1], color[x][2]);
}

void black_col () {
    iSetColor (0, 0, 0);
}







int check (int x, int y) {
    if (maze[y][x] == 1) {
        return 0;
    }
    else {
        return 1;
    }
}

double dist (int x1, int y1, int x2, int y2) {
    double ans = 0;
    ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    ans = sqrt (ans);

    return ans;
}







void turn (character* p) {
    int nx = p->x/30 + ddx[(p->st+2) % 4];
    int ny = p->y/30 + ddy[(p->st+2) % 4];
    if (check (nx, ny)) {
        p->dx = -p->dx;
        p->dy = -p->dy;
        p->st = (p->st+2) % 4;
    }

}

void deadClash (character* p) {
    if ((((p->x >= player.x-25) && (p->x <= player.x+25)) && ((p->y >= player.y-25) && (p->y <= player.y+25))) && p->fr == 0 && p->eat == 0) {
        alive = 0;
        life--;
        player.cidx = 0;
        iPauseTimer (0);
        iPauseTimer (2);
        timeReset (&t1);
        timeReset (&t2);
        timeReset (&blinky.tai);
        timeReset (&pinky.tai);
        timeReset (&inky.tai);
        timeReset (&clyde.tai);
        tchk = 0;
    }
    else if ((((p->x >= player.x-25) && (p->x <= player.x+25)) && ((p->y >= player.y-25) && (p->y <= player.y+25))) && p->fr == 1) {
        p->cidx = 0;
        p->fr = 0;
        p->eat = 1;
        eatidx++;
        score += 100*pow(2,(eatidx+1));
        eatch = 1;
        rt = t1.second;
        rx = player.x;
        ry = player.y;
        timeReset (&((*p).tai));
    }
}

void posChange (character* p) {
    p->x += p->dx;
    p->y += p->dy;
}

void playing () {
    if (left) {
        if (((player.x) % 30 == 0) && ((player.y) % 30 == 0)) {
            int x = (player.x) / 30;
            int y = (player.y) / 30;
            if (check (x-1, y)) {
                player.dx = -velocity;
                player.dy = 0;
                player.st = 0;
                //PlaySound (sounds[2], NULL, SND_ASYNC);
            }
        }

    }
    if (right) {
        if (((player.x) % 30 == 0) && ((player.y) % 30 == 0)) {
            int x = (player.x) / 30;
            int y = (player.y) / 30;
            if (check (x+1, y)) {
                player.dx = velocity;
                player.dy = 0;
                player.st = 2;
                //PlaySound (sounds[2], NULL, SND_ASYNC);
            }
        }

    }
    if (up) {
        if (((player.x) % 30 == 0) && ((player.y) % 30 == 0)) {
            int x = (player.x) / 30;
            int y = (player.y) / 30;
            if (check (x, y+1)) {
                player.dx = 0;
                player.dy = velocity;
                player.st = 1;
                //PlaySound (sounds[2], NULL, SND_ASYNC);
            }
        }
    }
    if (down) {
        if (((player.x) % 30 == 0) && ((player.y) % 30 == 0)) {
            int x = (player.x) / 30;
            int y = (player.y) / 30;
            if (check (x, y-1)) {
                player.dx = 0;
                player.dy = -velocity;
                player.st = 3;
                //PlaySound (sounds[2], NULL, SND_ASYNC);
            }
        }
    }
}

void blockage (character* p) {
    if (p->dx > 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (!check (x+1, y)) {
                p->dx = 0;
                p->dy = 0;
            }
        }
    }
    if (p->dx < 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (!check (x-1, y)) {
                p->dx = 0;
                p->dy = 0;
            }
        }
    }
    if (p->dy > 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (!check (x, y+1)) {
                p->dx = 0;
                p->dy = 0;
            }
        }
    }
    if (p->dy < 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (!check (x, y-1)) {
                p->dx = 0;
                p->dy = 0;
            }
        }
    }
}

void passthrough (character* p) {
    if (p->dx > 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (((p->x) / 30 == 28) && p->y == (11*30)) {
                p->x = 0;
                p->dx = velocity;
                p->st = 2;
            }

        }
    }
    if (p->dx < 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x = (p->x) / 30;
            int y = (p->y) / 30;
            if (((p->x) / 30 == 0) && p->y == (11*30)) {
                p->x = 840;
                p->dx = -velocity;
                p->st = 0;
            }

        }
    }
}

void ghostShow (character* p) {
    if (p->fr == 1) {
        iShowBMP2 (p->x, p->y, party[p->cidx], 0x070707);
    }
    else if (p->eat == 1) {
        iShowBMP2 (p->x, p->y, eaten[p->cidx], 0x070707);
    }

}









void topEye (character* p) {
    if (p->eat == 1) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x1 = 420;
            int y1 = 360;
            if ((p->y-y1) > 0 && p->y > y1) {
                p->dx = 0;
                p->dy = -10;
                p->st = 3;
            }
            else if ((p->y-y1) < 0 && p->y < y1) {
                p->dx = 0;
                p->dy = 10;
                p->st = 1;
            }
            else if ((p->x-x1) > 0 && p->x > x1) {
                p->dx = -10;
                p->dy = 0;
                p->st = 0;
            }
            else if ((p->x-x1) < 0 && p->x < x1) {
                p->dx = 10;
                p->dy = 0;
                p->st = 2;
            }

            if (p->x == x1 && p->y == y1) {
                p->fr = 0;
                p->eat = 0;
                timeReset (&p->tai);
                p->tai.second = 3;
                p->dx = gvelocity;
                p->dy = 0;
                p->st = 2;
            }


        }
    }

}

void botEye (character* p) {
    if (p->eat == 1) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            int x1 = 420;
            int y1 = 300;
            if ((p->y-y1) > 0 && p->y > y1) {
                p->dx = 0;
                p->dy = -10;
                p->st = 3;
            }
            else if ((p->y-y1) < 0 && p->y < y1) {
                p->dx = 0;
                p->dy = 10;
                p->st = 1;
            }
            else if ((p->x-x1) > 0 && p->x > x1) {
                p->dx = -10;
                p->dy = 0;
                p->st = 0;
            }
            else if ((p->x-x1) < 0 && p->x < x1) {
                p->dx = 10;
                p->dy = 0;
                p->st = 2;
            }

            if (p->x == x1 && p->y == y1) {
                p->fr = 0;
                p->eat = 0;
                timeReset (&p->tai);
                p->tai.second = 3;
                p->dx = -gvelocity;
                p->dy = 0;
                p->st = 0;
            }


        }
    }
}







void frightChange () {
    if (fright == 1) {
        if (blinky.eat == 0 && !(blinky.x >= 390 && blinky.x <= 450 && blinky.y >= 270 && blinky.y <= 390)) {
            blinky.fr = 1;
        }
        if (pinky.eat == 0 && !(pinky.x >= 390 && pinky.x <= 450 && pinky.y >= 270 && pinky.y <= 390)) {
            pinky.fr = 1;
        }
        if (inky.eat == 0 && !(inky.x >= 390 && inky.x <= 450 && inky.y >= 270 && inky.y <= 390)) {
            inky.fr = 1;
        }
        if (clyde.eat == 0 && !(clyde.x >= 390 && clyde.x <= 450 && clyde.y >= 270 && clyde.y <= 390)) {
            clyde.fr = 1;
        }
    }


    blinky.cidx = pinky.cidx = inky.cidx = clyde.cidx = 0;
}

void frightCheck () {
    if (blinky.fr == 0 && pinky.fr == 0 && inky.fr == 0 && clyde.fr == 0) {
        fright = 0;
    }
}








void pcidxChange(character* p) {
    if (alive == 1) {
        p->cidx = (p->cidx+1) % 2;
        if (p->dx > 0) {
            p->st = 2;
        }
        if (p->dx < 0) {
            p->st = 0;
        }
        if (p->dy > 0) {
            p->st = 1;
        }
        if (p->dy < 0) {
            p->st = 3;
        }

        p->cidx += p->st*2;
    }
    else {
        p->cidx = p->cidx + 1;

        if (p->cidx == 12 && life > 0) {
            alive = 1;
            left = right = up = down = 0;
            updateCharacter (&player, 420, 30, velocity, 0, 5, 2, 0, 0);
            updateCharacter (&blinky, 390, 390, 0, 0, 7, 3, 0, 0);
            updateCharacter (&pinky, 450, 390, 0, 0, 7, 3, 0, 0);
            updateCharacter (&inky, 390, 270, 0, 0, 3, 1, 0, 0);
            updateCharacter (&clyde, 450, 270, 0, 0, 3, 1, 0, 0);
            iPauseTimer (1);
            iResumeTimer (2);
        }
        else if (p->cidx == 12 && life == 0) {
            gOver = 1;
            iPauseTimer (1);
            iResumeTimer (2);
        }
    }

}

void gcidxChange(character* p) {
    if (alive == 1 && p->fr == 0 && p->eat == 0) {
        p->cidx = (p->cidx+1) % 2;

        p->cidx += p->st*2;
    }
    else if (alive == 1 && p->fr == 1) {
        if (t1.second < 9) {
            p->cidx = (p->cidx+1) % 2;
        }
        else {
            p->cidx = (p->cidx+1) % 4;
        }

    }
    else if (p->eat == 1) {
        p->cidx = p->st;
    }

}







void gChasePoint () {
    if (gMode == 0) {
        blinky.tx = player.x;
        blinky.ty = player.y;
        pinky.tx = player.x + 4*30*ddx[player.st];
        pinky.ty = player.y + 4*30*ddy[player.st];
        inky.tx = player.x + 2*30*ddx[player.st];
        inky.ty = player.y + 2*30*ddy[player.st];
        inky.tx = inky.tx - (blinky.x - inky.tx);
        inky.ty = inky.ty - (blinky.y - inky.ty);
        if (dist (clyde.x, clyde.y, player.x, player.y) <= 7*30) {
            clyde.tx = 0;
            clyde.ty = 0;
        }
        else {
            clyde.tx = player.x;
            clyde.ty = player.y;
        }
    }
    else if (gMode == 1) {
        blinky.tx = 660;
        blinky.ty = 840;
        pinky.tx = 0;
        pinky.ty = 840;
        inky.tx = 660;
        inky.ty = 0;
        clyde.tx = 0;
        clyde.ty = 0;
    }

}

void gChase (character* p) {
    double dis, lwst = 1200;
    int i, bst;
    for (i = 0; i < 4; i++) {
        if ((i+2)%4 != p->st) {
            int nx = p->x/30 + ddx[i];
            int ny = p->y/30 + ddy[i];
            if (check (nx, ny) == 0) {
                continue;
            }
            dis = dist (nx, ny, p->tx/30, p->ty/30);
            if (lwst > dis) {
                lwst = dis;
                bst = i;
            }
        }
    }


    if (bst == 0) {
        p->dx = -gvelocity;
        p->dy = 0;
    }
    else if (bst == 1) {
        p->dx = 0;
        p->dy = gvelocity;
    }
    else if (bst == 2) {
        p->dx = gvelocity;
        p->dy = 0;
    }
    else if (bst == 3) {
        p->dx = 0;
        p->dy = -gvelocity;
    }
    p->st = bst;

}

void frightened (character* p) {
    /*double dis, hgst = 0;
    int i, bst;
    for (i = 0; i < 4; i++) {
        if ((i+2)%4 != p->st) {
            int nx = p->x/30 + ddx[i];
            int ny = p->y/30 + ddy[i];
            if (check (nx, ny) == 0) {
                continue;
            }
            dis = dist (nx, ny, p->tx/30, p->ty/30);
            if (hgst < dis) {
                hgst = dis;
                bst = i;
            }
        }
    }


    if (bst == 0) {
        p->dx = -gvelocity;
        p->dy = 0;
    }
    else if (bst == 1) {
        p->dx = 0;
        p->dy = gvelocity;
    }
    else if (bst == 2) {
        p->dx = gvelocity;
        p->dy = 0;
    }
    else if (bst == 3) {
        p->dx = 0;
        p->dy = -gvelocity;
    }
    p->st = bst;*/
    if (((p->x) % 30 == 0) && ((p->y) % 30 == 0) && p->eat == 0) {
        int i;
        int cnt = 0;
        for (i = 0; i < 4; i++) {
            if ((i+2)%4 != p->st) {
                int nx = p->x/30 + ddx[i];
                int ny = p->y/30 + ddy[i];
                if (check (nx, ny) == 0) {
                    continue;
                }
                cnt++;
            }
        }
        int random = rand() % cnt;

        cnt = 0;
        for (i = 0; i < 4; i++) {
            if ((i+2)%4 != p->st) {
                int nx = p->x/30 + ddx[i];
                int ny = p->y/30 + ddy[i];
                if (check (nx, ny) == 0) {
                    continue;
                }
                if (cnt == random) {
                    if (i == 0) {
                        p->dx = -gvelocity;
                        p->dy = 0;
                    }
                    else if (i == 1) {
                        p->dx = 0;
                        p->dy = gvelocity;
                    }
                    else if (i == 2) {
                        p->dx = gvelocity;
                        p->dy = 0;
                    }
                    else if (i == 3) {
                        p->dx = 0;
                        p->dy = -gvelocity;
                    }
                    p->st = i;

                    break;
                }
                cnt++;
            }
        }
    }
}

void blinkyChase (character* p) {
    if ((p->x == 390 && p->y <= 390 && p->y > 360) && p->eat == 0 && p->fr == 0) {
        p->dy = -gvelocity;
        p->dx = 0;
        p->st = 3;
    }
    else if ((p->y == 360 && (p->x >= 390 && p->x < 510))&& p->eat == 0 && p->fr == 0) {
        p->dy = 0;
        p->dx = gvelocity;
        p->st = 2;
    }
    else if (p->eat == 0 && p->fr == 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            gChase (&blinky);
        }
    }


}

void pinkyChase (character* p) {
    if ((p->tai.second < 3) && p->eat == 0 && p->fr == 0) {

    }
    else if ((p->x == 450 && p->y <= 390 && p->y > 360) && p->eat == 0 && p->fr == 0) {
        p->dy = -gvelocity;
        p->dx = 0;
        p->st = 3;
    }
    else if ((p->y == 360 && (p->x >= 450 && p->x < 510)) && p->eat == 0 && p->fr == 0) {
        p->dy = 0;
        p->dx = gvelocity;
        p->st = 2;
    }
    else {
        if ((((p->x) % 30 == 0) && ((p->y) % 30 == 0))&& p->eat == 0 && p->fr == 0) {
            gChase (&pinky);
        }
    }


}

void inkyChase (character* p) {
    if ((p->tai.second < 3) && p->eat == 0 && p->fr == 0) {

    }
    else if ((p->x == 390 && p->y >= 270 && p->y < 300) && p->eat == 0 && p->fr == 0) {
        p->dy = gvelocity;
        p->dx = 0;
        p->st = 1;
    }
    else if ((p->y == 300 && (p->x > 330 && p->x <= 390)) && p->eat == 0 && p->fr == 0) {
        p->dy = 0;
        p->dx = -gvelocity;
        p->st = 0;
    }
    else if (p->eat == 0 && p->fr == 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            gChase (&inky);
        }
    }


}

void clydeChase (character* p) {
    if ((p->x == 450 && p->y >= 270 && p->y < 300) && p->eat == 0 && p->fr == 0) {
        p->dy = gvelocity;
        p->dx = 0;
        p->st = 1;
    }
    else if ((p->y == 300 && (p->x > 330 && p->x <= 450)) && p->eat == 0 && p->fr == 0) {
        p->dy = 0;
        p->dx = -gvelocity;
        p->st = 0;
    }
    else if (p->eat == 0 && p->fr == 0) {
        if (((p->x) % 30 == 0) && ((p->y) % 30 == 0)) {
            gChase (&clyde);

        }
    }

}







void iDraw () {
    iClear ();

    if (Main) {
        if (sound == 0) {
            PlaySound (sounds[3], NULL, SND_ASYNC);
            sound = 1;
        }
        iShowBMP (0, 0, "Sprites\\MainMenu.bmp");
    }
    if (NewG) {
        if (gOver == 1 && chkHS (files[0], files[1], score)) {
            hscore = 1;
        }

        if (gOver == 0) {
            int i, j;
            for (i = 0; i < 23; i++) {
                for (j = 0; j < 29; j++) {
                    if ((j == 12 && i == 10) || (j == 16 && i == 12)) {
                        coloring (0);
                        iFilledRectangle (j*30+13, i*30, 4, 30);
                        continue;
                    }
                    if ((j == 16 && i == 10) || (j == 12 && i == 12)) {
                        coloring (2);
                        iFilledRectangle (j*30+7, i*30, 16, 30);
                        continue;
                    }
                    if ((((j >= 4) && (j <= 8)) || ((j >= 12) && (j <= 16)) || ((j >= 20) && (j <= 24))) && ((i >= 8) && (i <= 14))) {
                        coloring (2);
                    }
                    else {
                        coloring (6);
                    }
                    if (maze[i][j] == 1) {
                        filled_square (j*30, i*30, 30);
                    }
                }
            }

            for (i = 0; i < 23; i++) {
                for (j = 0; j < 29; j++) {
                    coloring (3);

                    if (balls[i][j] == 1) {
                        iFilledCircle (j*30+15, i*30+15, 3);
                    }
                }
            }

            coloring (8);
            iFilledRectangle (870, 0, scwidth-870, scheight);
            black_col ();
            iFilledRectangle (890, 30, scwidth-910, 100);
            iFilledRectangle (890, scheight-130, scwidth-910, 100);
            iFilledRectangle (890, scheight-280, scwidth-910, 100);
            iFilledRectangle (890, 180, scwidth-910, 100);
            iFilledRectangle (890, 320, scwidth-910, 50);

            coloring (0);
            iText (920, 245, "SCORE", GLUT_BITMAP_9_BY_15);
            iText (920, 215, sstr, GLUT_BITMAP_9_BY_15);

            iText (920, 95, "LIFES", GLUT_BITMAP_9_BY_15);
            for (i = 0; i < life; i++) {
                iShowBMP (915+i*25, 55, "Sprites\\lifeShow.bmp");
            }

            if (tshow) {
                iText (920, 340, tstr, GLUT_BITMAP_9_BY_15);
            }
            else {
                iText (920, 340, "NO BOOSTS", GLUT_BITMAP_9_BY_15);
            }





            coloring (1);
            iLine (30, 330, 30, 360);
            iLine (840, 330, 840, 360);

            if (blinky.fr == 0 && blinky.eat == 0) {
                iShowBMP2 (blinky.x, blinky.y, blink[blinky.cidx], 0x070707);
            }
            else {
                ghostShow (&blinky);
            }

            if (pinky.fr == 0 && pinky.eat == 0) {
                iShowBMP2 (pinky.x, pinky.y, pink[pinky.cidx], 0x070707);
            }
            else {
                ghostShow (&pinky);
            }

            if (inky.fr == 0 && inky.eat == 0) {
                iShowBMP2 (inky.x, inky.y, ink[inky.cidx], 0x070707);
            }
            else {
                ghostShow (&inky);
            }

            if (clyde.fr == 0 && clyde.eat == 0) {
                iShowBMP2 (clyde.x, clyde.y, clyd[clyde.cidx], 0x070707);
            }
            else {
                ghostShow (&clyde);
            }



            if (alive) {
                iShowBMP2 (player.x, player.y, mpac[player.cidx], 0x070707);
            }
            else {
                iShowBMP2 (player.x, player.y, death[player.cidx], 0x070707);
            }

            if (t1.second - rt <= 1) {
                if (eatch) {
                    iShowBMP2 (rx, ry, eat[eatidx], 0x070707);
                }
                if (t1.second - rt == 1) {
                    eatch = 0;
                    rx = ry = rt = 0;
                }
            }



            if (balls[6][1]) {
                iShowBMP2 (1*30, 6*30, power[pidx], 0x070707);
            }
            if (balls[18][1]) {
                iShowBMP2 (1*30, 18*30, power[pidx], 0x070707);
            }
            if (balls[6][27]) {
                iShowBMP2 (27*30, 6*30, power[pidx], 0x070707);
            }
            if (balls[18][27]) {
                iShowBMP2 (27*30, 18*30, power[pidx], 0x070707);
            }
        }
        else {

            iShowBMP (500, 500, "Sprites\\GAME_OVER.bmp");
            if (hscore) {
                coloring (0);
                iRectangle (340, 290, 400, 30);
                iText(350, 300, nameStr, GLUT_BITMAP_9_BY_15);
            }
            else {
                iText(350, 300, "YOU HAVE BECOME GHOST!", GLUT_BITMAP_9_BY_15);
            }

        }




    }
    if (Pause) {
        iShowBMP (0, 0, "Sprites\\Pause.bmp");
    }
    if (High) {
        iShowBMP (0, 0, "Sprites\\HighScore.bmp");
        getHS (files[0], files[1]);


    }
    if (Help) {
        iShowBMP (0, 0, "Sprites\\Help.bmp");
    }
    if (Cred) {

    }
    if (Sett) {

    }
    if (Exit) {
        iShowBMP (0, 0, "Sprites\\Exit.bmp");
    }



}

void iMouse (int button, int state, int mx, int my) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        if (Main) {
            arrHS (files[0], files[1]);
            if (mx >= 377 && mx <= 654 && my >= 324 && my <= 363) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                NewG = 1;
                iResumeTimer (2);



                int i, j;
                for (i = 0; i < 23; i++) {
                    for (j = 0; j < 29; j++) {
                        if ((((j >= 0) && (j <= 1)) || ((j >= 27) && (j <= 28))) && (i == 9 || i == 13)) {
                            continue;
                        }
                        if (((j >= 10) && (j <= 18)) && ((i >= 7) && (i <= 15))) {
                            continue;
                        }
                        if ((j == 0 || j == 28) && i == 11) {
                            continue;
                        }
                        if (maze[i][j] == 0 && balls[i][j] == 0) {
                            balls[i][j] = 1;
                            b_count++;
                        }

                    }
                }
                balls[1][14] = 0;
                updateCharacter (&player, 420, 30, velocity, 0, 5, 2, 0, 0);
                updateCharacter (&blinky, 390, 390, 0, 0, 7, 3, 0, 0);
                updateCharacter (&pinky, 450, 390, 0, 0, 7, 3, 0, 0);
                updateCharacter (&inky, 390, 270, 0, 0, 3, 1, 0, 0);
                updateCharacter (&clyde, 450, 270, 0, 0, 3, 1, 0, 0);
                score = 0;
                turns = 0;
                tReset ();


            }
            if (mx >= 379 && mx <= 653 && my >= 261 && my <= 302) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                High = 1;
            }
            if (mx >= 373 && mx <= 553 && my >= 191 && my <= 239) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                Help = 1;
            }
            if (mx >= 379 && mx <= 594 && my >= 133 && my <= 167) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                Cred = 1;
            }
            if (mx >= 371 && mx <= 616 && my >= 71 && my <= 112) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                Sett = 1;
            }
            if (mx >= 29 && mx <= 120 && my >= 20 && my <= 56) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Main = 0;
                Exit = 1;
            }
        }

        if (Pause) {

            if (mx >= 289 && mx <= 395 && my >= 269 && my <= 293) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Pause = 0;
                NewG = 1;
                iResumeTimer (0);
                iResumeTimer (1);
                iResumeTimer (2);
            }
            if (mx >= 288 && mx <= 619 && my >= 220 && my <= 243) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Pause = 0;
                Main = 1;
            }
        }

        if (Exit) {
               // printf ("%d %d\n", mx, my);
            if (mx >= 401 && mx <= 453 && my >= 233 && my <= 255) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                exit (0);
            }
            if (mx >= 657 && mx <= 693 && my >= 233 && my <= 255) {
                PlaySound (sounds[0], NULL, SND_ASYNC);
                Exit = 0;
                Main = 1;
            }
        }


    }

}


void iMouseMove (int mx, int my) {
}


void iKeyboard (unsigned char key) {
    if (Main) {
        if (key == 27) {
            Main = 0;
            Exit = 1;

        }
    }
    if (NewG) {
        if (key == 27 && gOver == 0) {
            NewG = 0;
            Pause = 1;
            iPauseTimer (0);
            iPauseTimer (1);
            iPauseTimer (2);

        }
        if (hscore == 1 && gOver == 1 && ((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key >= 48 && key <= 57) || key == 8 || key == 32 || key == '\r')){
            if (key == '\r') {
                len = 0;
                NewG = 0;
                High = 1;
                putHS (files[0], files[1], score, nameStr);
            }
            else {
                if (len+1 <= 13) {
                    nameStr[len++] = key;
                }

            }

            if (key == 8) {
                len -= 2;
                nameStr[len] = '\0';
                nameStr[len+1] = '\0';
            }





        }
    }
    if (High) {
        if (key == 27) {
            High = 0;
            Main = 1;

        }
    }
    if (Help) {
        if (key == 27) {
            Help = 0;
            Main = 1;

        }
    }
    if (Cred) {
        if (key == 27) {
            Cred = 0;
            Main = 1;

        }
    }
    if (Sett) {
        if (key == 27) {
            Sett = 0;
            Main = 1;

        }
    }


}

void iSpecialKeyboard (unsigned char key) {
    if (NewG) {
        if (key == GLUT_KEY_LEFT) {
            right = up = down = 0;
            if (player.dx) {
                left = 1;
            }
            else if (player.dy) {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (player.dy > 0) {
                    int i;
                    for (i = y; i <= 22; i++) {
                        if (check (x-1, i)) {
                            left = 1;
                            break;
                        }
                    }
                }
                else {
                    int i;
                    for (i = y; i >= 1; i--) {
                        if (check (x-1, i)) {
                            left = 1;
                            break;
                        }
                    }
                }
            }
            else {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (check (x-1, y)) {
                    player.dx = -velocity;
                }
            }


        }
        if (key == GLUT_KEY_RIGHT) {
            left = up = down = 0;
            if (player.dx) {
                right = 1;
            }
            else if (player.dy) {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (player.dy > 0) {
                    int i;
                    for (i = y; i <= 22; i++) {
                        if (check (x+1, i)) {
                            right = 1;
                            break;
                        }
                    }
                }
                else {
                    int i;
                    for (i = y; i >= 1; i--) {
                        if (check (x+1, i)) {
                            right = 1;
                            break;
                        }
                    }
                }
            }
            else {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (check (x+1, y)) {
                    player.dx = velocity;
                }
            }


        }
        if (key == GLUT_KEY_UP) {
            right = left = down = 0;
            if (player.dy) {
                up = 1;
            }
            else if (player.dx) {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (player.dx > 0) {
                    int i;
                    for (i = x; i <= 28; i++) {
                        if (check (i, y+1)) {
                            up = 1;
                            break;
                        }
                    }
                }
                else {
                    int i;
                    for (i = x; i >= 1; i--) {
                        if (check (i, y+1)) {
                            up = 1;
                            break;
                        }
                    }
                }
            }
            else {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (check (x, y+1)) {
                    player.dy = velocity;
                }
            }


        }
        if (key == GLUT_KEY_DOWN) {
            right = up = left = 0;
            if (player.dy) {
                down = 1;
            }
            else if (player.dx) {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (player.dx > 0) {
                    int i;
                    for (i = x; i <= 28; i++) {
                        if (check (i, y-1)) {
                            down = 1;
                            break;
                        }
                    }
                }
                else {
                    int i;
                    for (i = x; i >= 1; i--) {
                        if (check (i, y-1)) {
                            down = 1;
                            break;
                        }
                    }
                }
            }
            else {
                int x = (player.x) / 30;
                int y = (player.y) / 30;
                if (check (x, y-1)) {
                    player.dy = -velocity;
                }
            }


        }
    }
}








void playerChange () {
    deadClash (&blinky);
    deadClash (&pinky);
    deadClash (&inky);
    deadClash (&clyde);

    posChange (&player);
    posChange (&blinky);
    posChange (&pinky);
    posChange (&inky);
    posChange (&clyde);

    passthrough (&player);
    passthrough (&blinky);
    passthrough (&pinky);
    passthrough (&inky);
    passthrough (&clyde);


    playing ();

    if (((player.x) % 30 == 0) && ((player.y) % 30 == 0)) {
        int x = (player.x) / 30;
        int y = (player.y) / 30;
        if (balls[y][x] == 1) {
            balls[y][x] = 0;
            score += 100;
            b_count--;
            if (b_count == 0) {
                gOver = 1;
            }
            PlaySound (sounds[1], NULL, SND_ASYNC);
            if (player.x == 1*30 && player.y == 6*30) {
                eatidx = -1;
                fright = 1;
                frightChange ();
                tReset ();
            }
            if (player.x == 1*30 && player.y == 18*30) {
                eatidx = -1;
                fright = 1;
                frightChange ();
                tReset ();
            }
            if (player.x == 27*30 && player.y == 6*30) {
                eatidx = -1;
                fright = 1;
                frightChange ();
                tReset ();
            }
            if (player.x == 27*30 && player.y == 18*30) {
                eatidx = -1;
                fright = 1;
                frightChange ();
                tReset ();
            }

        }
    }

    sprintf (sstr, "%03d", score);


    frightCheck ();

    topEye (&blinky);
    topEye (&pinky);
    botEye (&inky);
    botEye (&clyde);


    gChasePoint ();
    blinkyChase (&blinky);
    pinkyChase (&pinky);
    inkyChase (&inky);
    clydeChase (&clyde);



    if (fright == 1) {
        if (turns == 0 || turns == 1) {
            turn (&blinky);
            turn (&pinky);
            turn (&inky);
            turn (&clyde);
            turns = 2;
        }
        if (t1.second > 12) {
            timeReset (&t1);
            fright = 0;
            eatidx = -1;
            blinky.fr = pinky.fr = inky.fr = clyde.fr = 0;
        }
        frightened (&blinky);
        frightened (&pinky);
        frightened (&inky);
        frightened (&clyde);
    }
    else if (((t1.minute == 0 || t1.minute == 1) && ((t1.second >= 0 && t1.second <= 15) || (t1.second >= 25 && t1.second <= 35) || (t1.second >= 50 && t1.second <= 55))) || (t1.minute >= 2)) {
        gMode = 0;
        if (turns == 1 || turns == 2) {
            turn (&blinky);
            turn (&pinky);
            turn (&inky);
            turn (&clyde);
            turns = 0;
        }
    }
    else {
        gMode = 1;
        if (turns == 0 || turns == 2) {
            turn (&blinky);
            turn (&pinky);
            turn (&inky);
            turn (&clyde);
            turns = 1;
        }
    }

    blockage (&player);

    if (fright) {
        tshow = 1;
    }
    else {
        tshow = 0;
    }

    //printf ("%d\n", b_count);

}

void bmpChange () {
    pcidxChange (&player);
    gcidxChange (&blinky);
    gcidxChange (&pinky);
    gcidxChange (&inky);
    gcidxChange (&clyde);

    pidx = (pidx+1) % 3;
}

void timeChange () {
    if (t2.second > 2) {
        iResumeTimer (0);
        iResumeTimer (1);
        if (tchk == 0) {
            timeReset (&t1);
            timeReset (&blinky.tai);
            timeReset (&pinky.tai);
            timeReset (&inky.tai);
            timeReset (&clyde.tai);
            tchk = 1;
        }
    }
    updateTime (&t1);
    updateTime (&t2);
    updateTime (&blinky.tai);
    updateTime (&pinky.tai);
    updateTime (&inky.tai);
    updateTime (&clyde.tai);

    if (t1.millisecond == 0) {
        sprintf (tstr, "%02d:%02d", 13-t1.second, t1.millisecond/10);
    }
    else if (t1.millisecond == 100) {
        sprintf (tstr, "%02d:%02d", 12-t1.second, 100-t1.millisecond/10);
    }
    else {
        sprintf (tstr, "%02d:%02d", 12-t1.second, 100-t1.millisecond/10);
    }



    //printf ("%s\n\n", tstr);
    //printf ("%d\n", pinky.tai.second);
}

//void mTimeChange () {
//    updateTime (&t3);
//    if (t3.second > 44) {
//        sound = 0;
//    }
//}

void tcheck () {
    //printf ("T1: %d\n\n", t1.second);
    //printf ("T2: %d\n\n", t2.second);
//    printf ("B: %d\n", blinky.tai.second);
//    printf ("P: %d\n", pinky.tai.second);
//    printf ("I: %d\n", inky.tai.second);
//    printf ("C: %d\n\n", clyde.tai.second);
//

//    printf ("P: %d\n", player.cidx);
//    printf ("B: %d\n", blinky.cidx);
//    printf ("P: %d\n", pinky.cidx);
//    printf ("I: %d\n", inky.cidx);
//    printf ("C: %d\n\n", clyde.cidx);

 //   printf ("Turn: %d\n\n", turns);

    //printf ("%d\n", eatidx);

    //printf ("%d\n\n", fright);

}





int main () {



    iSetTimer (20, playerChange);
    iSetTimer (150, bmpChange);
    iSetTimer (20, timeChange);
   // iSetTimer (20, mTimeChange);
    iSetTimer (1000, tcheck);
    iPauseTimer (0);
    iPauseTimer (1);
    iPauseTimer (2);

    iInitialize (scwidth, scheight, "Pacman!");
    return 0;
}
