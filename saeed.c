//saeednoferesti 403106838
#include<stdio.h>
#include<ncursesw/ncurses.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
char map[49][183];
int mark_color[49][183];
int GOLD=0;
int HEALTH=100;
int food=0;
int shamshir=0;
int khanjar=0;
int tir=0;
int asa=0;
int T_damage=0;
int T_health=0;
int T_speed=0; 
int tabagheh=1;
int Ancient_Key=0;
int your_weapon=1000;
//میزان کاهش جان(درجه سختی بازی)
int decrease=5;
//انتخاب شخصیت بازی
const char *unicode_char8095="🤖";
//برای تعداد خطای در رمز دار
int khata=0;
//رمز متغیر
int const_int;
//username
char username1234[100];
//عدد برای اتاق گنج
int vv=0;
//سلامت هیولا
struct JOON{
    int D=5;
    int F=10;
    int G=15;
    int U=30;
    int S=20;
};
struct JOON joon;
//اتاق گنج
struct end_room{
    int X;
    int Y;
};
struct end_room END_ROOM;
struct MARK{
    int m[49][183];
};
struct MARK mark;
struct ADAMAK{
    int x;
    int y;
};
struct ADAMAK adamak;
struct ROOM{
    int xs;
    int ys;
};
struct ROOM room[6];
struct DOOR{
    int x;
    int y;
};
struct DOOR door[7];
typedef struct {
    char name[50];
    int gold;
    int score;
    int amount;
} User;
User user[100];
int randomInRange(int min,int max){
    return min+rand()%(max-min+1);
}
int correctcode(int key,char a[]){
    for(int i=0;i<strlen(a);i++){
        if(a[i]<'0'||a[i]>'9') return 0;
    }
    if(key==atoi(a)){
        return 1;
    }
    else return 0;
}
void svaescore(char username[],int GOLD){
    FILE*score1=fopen("score.txt","r");
    int i=0;
    int check=0;
    char a[1000];
    while(fgets(a,sizeof(a),score1)!=NULL){
        char user[100];
        sscanf(a,"%s",user);
        if(strcmp(user,username)==0){
            check=1;
            break;
        }
        else{
            i++;
        }
    }
    // mvprintw(20,3,"%d,%d",check,i);
    // refresh();
    // usleep(5000000);
    if(check==0){
        FILE*score=fopen("score.txt","a");
        fprintf(score,"%s %d %d %d\n",username,GOLD,GOLD*10,1);
        fclose(score);
    }
    else if(check==1){
        FILE*score=fopen("score.txt","r+");
        FILE*temp=fopen("temp.txt","w");
        int lineNumber=0;
        char b[1000];
        while(fgets(b,sizeof(b),score)!=NULL){
            if(lineNumber==i){
                char name[50];
                int value1,value2,value3;
                sscanf(b,"%s %d %d %d", name,&value1,&value2,&value3);
                fprintf(temp,"%s %d %d %d\n",name,value1+GOLD,value2+GOLD*10,value3+1);
            }
            else{
                fputs(b,temp);
            }
            lineNumber++;
        }
        fclose(score);
        fclose(temp);
        remove("score.txt");
        rename("temp.txt","score.txt");
    }
}
int compare(const void *a, const void *b) {
    User *studentA=(User*)a;
    User *studentB=(User*)b;
    return studentB->gold-studentA->gold;
}
void Scoreboard(){
    clear();
    mvprintw(0,0,"Scoreboard(USERNAME,GOLD,SCORE,NUMBER OF TIMES PLAYED)");
    FILE * score=fopen("score.txt","r");
    char a[100];
    move(1,0);
    int count=0;
    while(fscanf(score,"%s %d %d %d",user[count].name,&user[count].gold,&user[count].score,&user[count].amount)!=EOF){
        count++;
    }
    fclose(score);
    qsort(user,count,sizeof(User),compare);
    for(int i=0;i<count;i++){
        //🏅🥈🥉
        if(strcmp(user[i].name,username1234)==0){
            printw("*");
        }
        if(i==0){
            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
            attron(A_BOLD);
            attron(COLOR_PAIR(1));
            const char*medal="🏅";
            printw("%s  %d:  %s  %d  %d  %d  %s\n",medal,i+1,user[i].name,user[i].gold,user[i].score,user[i].amount,"(LEGEND)");
            attroff(COLOR_PAIR(1));
            attroff(A_BOLD);
        }
        else if(i==1){
            init_pair(2,COLOR_BLUE,COLOR_BLACK);
            attron(A_BOLD);
            attron(COLOR_PAIR(2));
            const char*medal="🥈";
            printw("%s  %d:  %s  %d  %d  %d  %s\n",medal,i+1,user[i].name,user[i].gold,user[i].score,user[i].amount,"(GOAT)");
            attroff(COLOR_PAIR(2));
            attroff(A_BOLD);
        }
        else if(i==2){
            init_pair(3,COLOR_RED,COLOR_BLACK);
            attron(A_BOLD);
            attron(COLOR_PAIR(3));
            const char*medal="🥉";
            printw("%s  %d:  %s  %d  %d  %d\n",medal,i+1,user[i].name,user[i].gold,user[i].score,user[i].amount);
            attroff(COLOR_PAIR(3));
            attroff(A_BOLD);
        }
        else{
            init_pair(5,COLOR_GREEN,COLOR_BLACK);
            bkgd(COLOR_PAIR(5));
            printw("    %d:  %s  %d  %d  %d\n",i+1,user[i].name,user[i].gold,user[i].score,user[i].amount);
        }
    }
    char c=getch();
}
void savegame(const char username[],const char username_filename[]){
    char filename[100];
    char filename2[100];
    snprintf(filename2,sizeof(filename2),"%s.txt",username);
    FILE*savefile_name=fopen(filename2,"a");
    fprintf(savefile_name,"%s\n",username_filename);
    snprintf(filename,sizeof(filename),"%s.txt",username_filename);
    FILE*savefile=fopen(filename,"w");
    for(int i=0;i<49;i++){
        for(int j=0;j<183;j++){
            if(map[i][j]==' '){
                fprintf(savefile,"%c\n",'!');
            }
            else{
                fprintf(savefile,"%c\n",map[i][j]);
            }
        }
    }
    fprintf(savefile,"%d\n",GOLD);
    fprintf(savefile,"%d\n",HEALTH);
    fprintf(savefile,"%d\n",food);
    fprintf(savefile,"%d\n",shamshir);
    fprintf(savefile,"%d\n",khanjar);
    fprintf(savefile,"%d\n",tir);
    fprintf(savefile,"%d\n",asa);
    fprintf(savefile,"%d\n",T_damage);
    fprintf(savefile,"%d\n",T_health);
    fprintf(savefile,"%d\n",T_speed);
    fprintf(savefile,"%d\n",tabagheh);
    fprintf(savefile,"%d\n",adamak.x);
    fprintf(savefile,"%d\n",adamak.y);
    fprintf(savefile,"%d\n",Ancient_Key);
    fprintf(savefile,"%s\n",username1234);
    fprintf(savefile,"%d\n",your_weapon);
    for(int i=0;i<49;i++){
        for(int j=0;j<183;j++){
            fprintf(savefile,"%d\n",mark.m[i][j]);
        }
    }
    fclose(savefile);
    fclose(savefile_name);
}
void foodmenu(){
    clear();
    mvprintw(0,0,"YOUR FOOD");
    const char*nan="🍔";
    mvprintw(3,0,"%s:%d",nan,food);
    mvprintw(4,0,"THE DEGREE OF HUNGER");
    int j=1;
    const char*y="🟨";
    int h=HEALTH;
    mvprintw(5,0,"[");
    while(h>0){
        mvprintw(5,j,"%s",y);
        h=h-5;
        j++;
    }
    mvprintw(5,22,"]");
    refresh();
    while(1){
        mvprintw(7,0,"EAT TO INCREASE YOUR HEALTH LEVEL(press o)");
        noecho();
        char c=getch();
        if(c=='o'){
            if(food<=0){
                mvprintw(20,60,"THERE IS NOT ENOUGH FOOD");
                refresh();
                noecho();
                usleep(2000000);
                mvprintw(20,60,"                          ");
                refresh();
                continue;
            }
            if(HEALTH<100){
                HEALTH+=5;
                food--;
                if(HEALTH>100){
                    HEALTH=100;
                }
            }
            foodmenu();
        }
        else{
            break;
        }
    }
    echo();
    
}
void gunandspellmenu(){
    clear();
    mvprintw(0,0,"YOUR WEAPONS AND SPELLS");
    const char*sh="⚔️";
    const char*kh="🗡️";
    const char*asa1="🪄";
    const char*tir1="➳";
    const char*tabar="🪓";
    //✦ , ⚝ ,  ✧ , ✿ , ☽
    const char *T_health1="⚝";
    const char *T_speed1="✦";
    const char *T_damage1="☽";
    // 🗡️1
    //🪄 2
    //  ➳   تیر3
    // ⚔️  4 شمشیر
    //🪓  سلاح اولیه
    mvprintw(1,0,"Short range weapon:");
    mvprintw(2,0,"(1)  %s :",sh);
    if(shamshir>=1){
        mvprintw(2,8,"%d",1);
    }
    else if(shamshir==0){
        mvprintw(2,8,"%d",0);
    }
    mvprintw(2,10,"damage:%d",10);
    mvprintw(4,0,"(2)  %s:",tabar);
    mvprintw(4,8,"%d",1);
    mvprintw(4,11,"damage:%d",5);
    mvprintw(1,60,"Long range weapon:");
    mvprintw(2,60,"(3)  %s :",kh);
    mvprintw(2,68,"%d",khanjar);
    mvprintw(2,71,"damage:%d",12);
    mvprintw(2,85,"range:%d",5);
    mvprintw(4,60,"(4)  %s:",asa1);
    mvprintw(4,68,"%d",asa);
    mvprintw(4,85,"range:%d",10);
    mvprintw(4,71,"damage:%d",15);
    mvprintw(6,60,"(5)  %s :",tir1);
    mvprintw(6,68,"%d",tir);
    mvprintw(6,71,"damage:%d",5);
    mvprintw(6,85,"range:%d",5);
    mvprintw(1,120,"Spells:");
    mvprintw(2,120,"(6)  %s :",T_health1);
    mvprintw(2,128,"%d",T_health);
    mvprintw(4,120,"(7)  %s :",T_speed1);
    mvprintw(4,128,"%d",T_speed);
    mvprintw(6,120,"(8)  %s :",T_damage1);
    mvprintw(6,128,"%d",T_damage);
    mvprintw(20,55,"Press the (c) button to put the weapon in the backpack");
    refresh();
    char q=getch();
        if(q=='c'){
            your_weapon=-1;
            clear();
            mvprintw(20,70,"you have no weapon in your hand now");
            refresh();
            usleep(2000000);
        }
        else if(q=='1'){
            if(your_weapon!=-1){
                clear();
                mvprintw(20,70,"First, put your previous weapon in the backpack");
                refresh();
                usleep(2000000);
            }
            else if(shamshir==0){
                clear();
                mvprintw(20,70,"you don't have this weapon");
                refresh();
                usleep(2000000);
            }
            else{
                your_weapon=4;
                clear();
                mvprintw(20,70,"your weapon has changed to a sword");
                refresh();
                usleep(2000000);
            }
        }
        else if(q=='2'){
            if(your_weapon!=-1){
                clear();
                mvprintw(20,70,"First, put your previous weapon in the backpack");
                refresh();
                usleep(2000000);
            }
            else{
                your_weapon=1000;
                clear();
                mvprintw(20,70,"your weapon has changed to a mace");
                refresh();
                usleep(2000000);
            }
        }
        else if(q=='3'){
            if(your_weapon!=-1){
                clear();
                mvprintw(20,70,"First, put your previous weapon in the backpack");
                refresh();
                usleep(2000000);
            }
            else if(khanjar==0){
                clear();
                mvprintw(20,70,"you don't have this weapon");
                refresh();
                usleep(2000000);
            }
            else{
                your_weapon=1;
                clear();
                mvprintw(20,70,"your weapon has changed to a dagger");
                refresh();
                usleep(2000000);
            }
        }
        else if(q=='4'){
            if(your_weapon!=-1){
                clear();
                mvprintw(20,70,"First, put your previous weapon in the backpack");
                refresh();
                usleep(2000000);
            }
            else if(asa==0){
                clear();
                mvprintw(20,70,"you don't have this weapon");
                refresh();
                usleep(2000000);
            }
            else{
                your_weapon=2;
                clear();
                mvprintw(20,70,"your weapon has changed to a magic wand");
                refresh();
                usleep(2000000);
            }
        }
        else if(q=='5'){
            if(your_weapon!=-1){
                clear();
                mvprintw(20,70,"First, put your previous weapon in the backpack");
                refresh();
                usleep(2000000);
            }
            else if(tir==0){
                clear();
                mvprintw(20,70,"you don't have this weapon");
                refresh();
                usleep(2000000);
            }
            else{
                your_weapon=3;
                clear();
                mvprintw(20,70,"your weapon has changed to a normal arrow");
                refresh();
                usleep(2000000);
            }
        }
    return;
}
void generateRandomPath(){
    for(int i=1;i<45;i++){
        map[27][i]='#';
    }
    for(int i=44;i<90;i++){
        map[26][i]='#';
    }
    map[27][89]='#';
    for(int i=89;i<140;i++){
        map[28][i]='#';
    }
    map[27][139]='#';
    for(int i=139;i<182;i++){
        map[26][i]='#';
    }
    if(map[door[0].x][door[0].y+1]==' '){
        int i=door[0].x;
        while(map[i][door[0].y+1]!='#'){
            map[i][door[0].y+1]='#';
            i++;
        }
    }
    else{
        int i=door[0].x;
        while(map[i][door[0].y-1]!='#'){
            map[i][door[0].y-1]='#';
            i++;
        }
    }
    if(map[door[1].x][door[1].y+1]==' '){
        int i=door[1].x;
        while( map[i][door[1].y+1]!='#'){
            map[i][door[1].y+1]='#';
            i++;
        }
    }
    else{
        int i=door[1].x;
        while(map[i][door[1].y-1]!='#'){
            map[i][door[1].y-1]='#';
            i++;
        }
    }
     if(map[door[2].x][door[2].y+1]==' '){
        int i=door[2].x;
        while( map[i][door[2].y+1]!='#'){
            map[i][door[2].y+1]='#';
            i++;
        }
    }
    else{
        int i=door[2].x;
        while(map[i][door[2].y-1]!='#'){
            map[i][door[2].y-1]='#';
            i++;
        }
    }
    if(map[door[3].x][door[3].y+1]==' '){
        int i=door[3].x;
        while( map[i][door[3].y+1]!='#'){
            map[i][door[3].y+1]='#';
            i--;
        }
    }
    else{
        int i=door[3].x;
        while(map[i][door[3].y-1]!='#'){
            map[i][door[3].y-1]='#';
            i--;
        }
    }
    if(map[door[3].x][door[3].y-9]==' '){
        int i=door[3].x;
        while( map[i][door[3].y-9]!='#'){
            map[i][door[3].y+1]='#';
            i--;
        }
    }
    else{
        int i=door[3].x;
        while(map[i][door[3].y-11]!='#'){
            map[i][door[3].y-11]='#';
            i--;
        }
    }
     if(map[door[4].x][door[4].y+1]==' '){
        int i=door[4].x;
        while( map[i][door[4].y+1]!='#'){
            map[i][door[4].y+1]='#';
            i--;
        }
    }
    else{
        int i=door[4].x;
        while(map[i][door[4].y-1]!='#'){
            map[i][door[4].y-1]='#';
            i--;
        }
    }
    if(map[door[5].x][door[5].y+1]==' '){
        int i=door[5].x;
        while( map[i][door[5].y+1]!='#'){
            map[i][door[5].y+1]='#';
            i--;
        }
    }
    else{
        int i=door[5].x;
        while(map[i][door[5].y-1]!='#'){
            map[i][door[5].y-1]='#';
            i--;
        }
    }
    if(map[door[6].x][door[6].y+1]==' '){
        int i=door[6].x;
        while( map[i][door[6].y+1]!='#'){
            map[i][door[6].y+1]='#';
            i--;
        }
    }
    else{
        int i=door[6].x;
        while(map[i][door[6].y-1]!='#'){
            map[i][door[6].y-1]='#';
            i--;
        }
    }
}
void generatemap(int tabagheh,int v){
    if(v==1){
        clear();
        for(int i=0;i<49;i++){
            for(int j=0;j<183;j++){
                map[i][j]=' ';
            }
        }
        END_ROOM.Y=randomInRange(55,70);
        END_ROOM.X=randomInRange(10,17);
        adamak.x=END_ROOM.X+1;
        adamak.y=END_ROOM.Y+1;
        for(int i=END_ROOM.X+1;i<END_ROOM.X+25;i++){
            map[i][END_ROOM.Y]='|';
            map[i][END_ROOM.Y+1]='.';
            map[i][END_ROOM.Y+2]='.';
            map[i][END_ROOM.Y+3]='.';
            map[i][END_ROOM.Y+4]='.';
            map[i][END_ROOM.Y+5]='.';
            map[i][END_ROOM.Y+6]='.';
            map[i][END_ROOM.Y+7]='.';
            map[i][END_ROOM.Y+8]='.';
            map[i][END_ROOM.Y+9]='.';
            map[i][END_ROOM.Y+10]='.';
            map[i][END_ROOM.Y+11]='.';
            map[i][END_ROOM.Y+12]='.';
            map[i][END_ROOM.Y+13]='.';
            map[i][END_ROOM.Y+14]='.';
            map[i][END_ROOM.Y+15]='.';
            map[i][END_ROOM.Y+16]='.';
            map[i][END_ROOM.Y+17]='.';
            map[i][END_ROOM.Y+18]='.';
            map[i][END_ROOM.Y+19]='.';
            map[i][END_ROOM.Y+20]='.';
            map[i][END_ROOM.Y+21]='.';
            map[i][END_ROOM.Y+22]='.';
            map[i][END_ROOM.Y+23]='.';
            map[i][END_ROOM.Y+24]='.';
        }
        for(int i=END_ROOM.X+1;i<END_ROOM.X+25;i++){
            map[i][END_ROOM.Y+25]='|';
        }
        for(int j=END_ROOM.Y+1;j<END_ROOM.Y+25;j++){
            map[END_ROOM.X][j]='_';
        }
        for(int j=END_ROOM.Y+1;j<END_ROOM.Y+25;j++){
            map[END_ROOM.X+24][j]='_';
        }
        int count1234=0;
        while(count1234!=1){
            int xT5=randomInRange(END_ROOM.X+20,END_ROOM.X+22);
            int yT5=randomInRange(END_ROOM.Y+20,END_ROOM.Y+22);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='e';
                count1234++;
            }  
        }
        //غذا
        int count0=0;
        while(count0!=6){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='0';
                count0++;
            }
        }
        //غذای فاسد
        int count1=0;
        while(count1!=2){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]=':';
                count1++;
            }
        }
        //طلا
        int count2=0;
        while(count2!=7){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='g';
                count2++;
            }
        }
        int count3=0;
        while(count3!=5){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='G';
                count3++;
            }
        }
        int count4=0;
        while(count4!=5){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='j';
                count4++;
            }
        }
        //هیولا ها
        int count5=0;
        while(count5!=2){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='D';
                count5++;
            }
        }
        int count6=0;
        while(count6!=1){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='S';
                count6++;
            }
        }
        int count7=0;
        while(count7!=2){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='F';
                count7++;
            }
        }
        //تله
        int count8=0;
        while(count8!=35){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='^';
                count8++;
            }
        }
        int count9=0;
        while(count9!=2){
            int xg0=randomInRange(END_ROOM.X+2,END_ROOM.X+23);
            int yg0=randomInRange(END_ROOM.Y+2,END_ROOM.Y+23);
            if(map[xg0][yg0]=='.'){
                map[xg0][yg0]='C';
                count9++;
            }
        }

    }
    ///////////////////////////////////////////////////////////////////////////////////
    else{
    room[0].ys=randomInRange(4,20);
    room[0].xs=randomInRange(4,14);
    room[1].ys=randomInRange(28,54);
    room[1].xs=randomInRange(4,14);
    room[2].ys=randomInRange(100,111);
    room[2].xs=randomInRange(4,14);
    room[3].ys=randomInRange(4,20);
    room[3].xs=randomInRange(31,35);
    room[4].ys=randomInRange(40,60);
    room[4].xs=randomInRange(31,35);
    room[5].ys=randomInRange(110,123);
    room[5].xs=randomInRange(31,35);
    for(int i=0;i<49;i++){
        for(int j=0;j<183;j++){
            map[i][j]=' ';
        }
    }
     for(int i=room[0].xs+1;i<room[0].xs+6;i++){
        map[i][room[0].ys]='|';
        map[i][room[0].ys+1]='.';
        map[i][room[0].ys+2]='.';
        map[i][room[0].ys+3]='.';
        map[i][room[0].ys+4]='.';
        map[i][room[0].ys+5]='.';
     }
     //برای ستون
     int xo0=randomInRange(room[0].xs+2,room[0].xs+4);
     int yo0=randomInRange(room[0].ys+2,room[0].ys+4);
     map[xo0][yo0]='o';
     //
     for(int i=room[0].xs+1;i<room[0].xs+6;i++){
        map[i][room[0].ys+6]='|';
     }
     for(int j=room[0].ys+1;j<room[0].ys+6;j++){
         map[room[0].xs][j]='_';
     }
     for(int j=room[0].ys+1;j<room[0].ys+6;j++){
         map[room[0].xs+5][j]='_';
    }
    door[0].x=randomInRange(room[0].xs+2,room[0].xs+4);
    door[0].y=room[0].ys;
    map[door[0].x][room[0].ys]='+';
    //گذاشتن رندم طلا در این اتاق
    int xG0=randomInRange(room[0].xs+2,room[0].xs+4);
    int yG0=randomInRange(room[0].ys+2,room[0].ys+4);
    if(map[xG0][yG0]=='.'){
        map[xG0][yG0]='G';
    }
    int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
    int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
    if(map[xg0][yg0]=='.'){
        map[xg0][yg0]='g';
    }
    int count6=0;
    while(count6!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]='0';
            count6++;
        }
    }
    int count61=0;
    while(count61!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]=':';
            count61++;
        }
    }
     int count66=0;
    while(count66!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]='4';
            count66++;
        }
    }
    int count662=0;
    while(count662!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]='D';
            count662++;
        }
    }
     int count666=0;
    while(count666!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]='3';
            count666++;
        }
    }
     int count6666=0;
    while(count6666!=1){
        int xg0=randomInRange(room[0].xs+2,room[0].xs+4);
        int yg0=randomInRange(room[0].ys+2,room[0].ys+4);
        if(map[xg0][yg0]=='.'){
            map[xg0][yg0]='9';
            count6666++;
        }
    }
     //===============================================
     for(int i=room[1].xs+1;i<room[1].xs+10;i++){
        map[i][room[1].ys]='|';
        map[i][room[1].ys+1]='.';
        map[i][room[1].ys+2]='.';
        map[i][room[1].ys+3]='.';
        map[i][room[1].ys+4]='.';
        map[i][room[1].ys+5]='.';
        map[i][room[1].ys+6]='.';
        map[i][room[1].ys+7]='.';
        map[i][room[1].ys+8]='.';
        map[i][room[1].ys+9]='.';
     }
     //برای ستون
     int xo1=randomInRange(room[1].xs+2,room[1].xs+8);
     int yo1=randomInRange(room[1].ys+2,room[1].ys+8);
     map[xo1][yo1]='o';
     //
     for(int i=room[1].xs+1;i<room[1].xs+10;i++){
         map[i][room[1].ys+10]='|';
     }
     for(int j=room[1].ys+1;j<room[1].ys+10;j++){
         map[room[1].xs][j]='_';
     }
     for(int j=room[1].ys+1;j<room[1].ys+10;j++){
         map[room[1].xs+9][j]='_';
     }
    door[1].x=randomInRange(room[1].xs+2,room[1].xs+8);
    door[1].y=room[1].ys+10;
    map[door[1].x][room[1].ys+10]='+';
     //گذاشتن رندم طلا در این اتاق
    int xj1=randomInRange(room[1].xs+2,room[1].xs+8);
    int yj1=randomInRange(room[1].ys+2,room[1].ys+8);
    if(map[xj1][yj1]=='.'){
        map[xj1][yj1]='j';
    }
     int count=0;
     while(count!=3){
        int xg1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yg1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xg1][yg1]=='.'){
            map[xg1][yg1]='g';
            count++;
        }
     }
     //هیولای G
     int count121212=0;
     while(count121212!=1){
        int xg1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yg1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xg1][yg1]=='.'){
            map[xg1][yg1]='C';
            count121212++;
        }
     }
     int count21=0;
     while(count21!=1){
        int xg1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yg1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xg1][yg1]=='.'){
            map[xg1][yg1]='F';
            count21++;
        }
     }
     int count2=0;
     while(count2!=2){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]='G';
            count2++;
        }
     }
     int count9=0;
     while(count9!=2){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]='0';
            count9++;
        }
     }
    int count93=0;
    while(count93!=1){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]=':';
            count93++;
        }
    }
     int count19=0;
     while(count19!=2){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]='3';
            count19++;
        }
     }
     int count192=0;
     while(count192!=1){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]='1';
            count192++;
        }
     }
     //=======================================================
     for(int i=room[2].xs+1;i<room[2].xs+6;i++){
         map[i][room[2].ys]='|';
         map[i][room[2].ys+1]='.';
        map[i][room[2].ys+2]='.';
        map[i][room[2].ys+3]='.';
        map[i][room[2].ys+4]='.';
        map[i][room[2].ys+5]='.';
     }
     //برای ستون
    int xo2=randomInRange(room[2].xs+2,room[2].xs+4);
    int yo2=randomInRange(room[2].ys+2,room[2].ys+4);
    map[xo2][yo2]='o';
     //
     for(int i=room[2].xs+1;i<room[2].xs+6;i++){
         map[i][room[2].ys+6]='|';
     }
     for(int j=room[2].ys+1;j<room[2].ys+6;j++){
         map[room[2].xs][j]='_';
     }
     for(int j=room[2].ys+1;j<room[2].ys+6;j++){
         map[room[2].xs+5][j]='_';
     }
     door[2].x=randomInRange(room[2].xs+2,room[2].xs+4);
    door[2].y=room[2].ys;
     map[door[2].x][room[2].ys]='+';
    int count333=0;
    while(count333!=1){
        int xT5=randomInRange(room[2].xs+1,room[2].xs+4);
        int yT5=randomInRange(room[2].ys+1,room[2].ys+4);
        if(map[xT5][yT5]=='.'){
            map[xT5][yT5]=':';
            count333++;
        }  
    }
    int count5=0;
    while(count5!=1){
        int xT5=randomInRange(room[2].xs+1,room[2].xs+4);
        int yT5=randomInRange(room[2].ys+1,room[2].ys+4);
        if(map[xT5][yT5]=='.'){
            map[xT5][yT5]='M';
            count5++;
        }  
    }
    //=======================================================
     for(int i=room[3].xs+1;i<room[3].xs+10;i++){
         map[i][room[3].ys]='|';
         map[i][room[3].ys+1]='.';
        map[i][room[3].ys+2]='.';
        map[i][room[3].ys+3]='.';
        map[i][room[3].ys+4]='.';
        map[i][room[3].ys+5]='.';
        map[i][room[3].ys+6]='.';
        map[i][room[3].ys+7]='.';
        map[i][room[3].ys+8]='.';
        map[i][room[3].ys+9]='.';
     }
     //برای ستون
    int xo3=randomInRange(room[3].xs+2,room[3].xs+8);
    int yo3=randomInRange(room[3].ys+2,room[3].ys+8);
    map[xo3][yo3]='o';
     //
     for(int i=room[3].xs+1;i<room[3].xs+10;i++){
         map[i][room[3].ys+10]='|';
     }
     for(int j=room[3].ys+1;j<room[3].ys+10;j++){
         map[room[3].xs][j]='_';
     }
     for(int j=room[3].ys+1;j<room[3].ys+10;j++){
         map[room[3].xs+9][j]='_';
     }
     door[3].x=randomInRange(room[3].xs+2,room[3].xs+8);
    door[3].y=room[3].ys+10;
    //در رمز دار
    map[door[3].x][room[3].ys+10]='@';
    map[door[3].x][room[3].ys]='+';
        int count7=0;
        while(count7!=2){
            int xj5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yj5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xj5][yj5]=='.'){
                map[xj5][yj5]='0';
                count7++;
            }  
        }
        int count85674=0;
        while(count85674!=1){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='&';
                count85674++;
            }  
        }
        int count00=0;
        while(count00!=1){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='S';
                count00++;
            }  
        }
    //اتاق گنج
    //برای شمارش و گذاشتن مقدار زیادی تلهو طلا 
    if(tabagheh==4){
        //گذاشتن eبرای اتمام بازی 
        int count1234=0;
            while(count1234!=1){
                int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
                int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
                if(map[xT5][yT5]=='.'){
                    map[xT5][yT5]=';';
                    count1234++;
                }  
            }
        int counttale=0;
        while(counttale!=5){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='^';
                counttale++;
            }  
        }
        int countgold=0;
        while(countgold!=5){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='G';
                countgold++;
            }  
        }
        int countgold3=0;
        while(countgold3!=1){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='4';
                countgold3++;
            }  
        }
        int countgold4=0;
        while(countgold4!=1){
            int xT5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yT5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xT5][yT5]=='.'){
                map[xT5][yT5]='3';
                countgold4++;
            }  
        }
        int countgold2=0;
        while(countgold2!=2){
            int xj5=randomInRange(room[3].xs+2,room[3].xs+8);
            int yj5=randomInRange(room[3].ys+2,room[3].ys+8);
            if(map[xj5][yj5]=='.'){
                map[xj5][yj5]='j';
                countgold2++;
            }  
        }
    }
     //=====================================================
     for(int i=room[4].xs+1;i<room[4].xs+6;i++){
        map[i][room[4].ys]='|';
        map[i][room[4].ys+1]='.';
        map[i][room[4].ys+2]='.';
        map[i][room[4].ys+3]='.';
        map[i][room[4].ys+4]='.';
        map[i][room[4].ys+5]='.';
     }
     //برای ستون
    int xo4=randomInRange(room[4].xs+2,room[4].xs+4);
    int yo4=randomInRange(room[4].ys+2,room[4].ys+4);
    map[xo4][yo4]='o';
     //
     for(int i=room[4].xs+1;i<room[4].xs+6;i++){
         map[i][room[4].ys+6]='|';
     }
     for(int j=room[4].ys+1;j<room[4].ys+6;j++){
         map[room[4].xs][j]='_';
     }
     for(int j=room[4].ys+1;j<room[4].ys+6;j++){
         map[room[4].xs+5][j]='_';
     }
    door[4].x=randomInRange(room[4].xs+2,room[4].xs+4);
    door[4].y=room[4].ys;
    //در مخفی//
     map[door[4].x][room[4].ys]='+';
     //اتاق طلسم 
     int countTT_h=0;
     while(countTT_h!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='5';
            countTT_h++;
        }
     }
     int countTT_s=0;
     while(countTT_s!=2){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='6';
            countTT_s++;
        }
     }
     int countTT_d=0;
     while(countTT_d!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='7';
            countTT_d++;
        }
     }
     int countgold=0;
     while(countgold!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='g';
            countgold++;
        }
     }
     int countgold1=0;
     while(countgold1!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='1';
            countgold1++;
        }
     }
     int countgold22=0;
     while(countgold22!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='3';
            countgold22++;
        }
     }
     int count4=0;
     while(count4!=1){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='0';
            count4++;
        }
     }
     //===================================================
     for(int i=room[5].xs+1;i<room[5].xs+10;i++){
         map[i][room[5].ys]='|';
         map[i][room[5].ys+1]='.';
        map[i][room[5].ys+2]='.';
        map[i][room[5].ys+3]='.';
        map[i][room[5].ys+4]='.';
        map[i][room[5].ys+5]='.';
        map[i][room[5].ys+6]='.';
        map[i][room[5].ys+7]='.';
        map[i][room[5].ys+8]='.';
        map[i][room[5].ys+9]='.';
     }
     //برای ستون
    int xo5=randomInRange(room[5].xs+2,room[5].xs+8);
    int yo5=randomInRange(room[5].ys+2,room[5].ys+8);
    map[xo5][yo5]='o';
    //برای پله 
    if(tabagheh!=4){
        int counter123=0;
        while(counter123!=1){
            int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
            int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
            if(map[xG5][yG5]=='.'){
                map[xG5][yG5]='<';
                counter123++;
            }
        }
    }
     //
     for(int i=room[5].xs+1;i<room[5].xs+10;i++){
         map[i][room[5].ys+10]='|';
     }
     for(int j=room[5].ys+1;j<room[5].ys+10;j++){
         map[room[5].xs][j]='_';
     }
     for(int j=room[5].ys+1;j<room[5].ys+10;j++){
         map[room[5].xs+9][j]='_';
     }
    door[6].x=randomInRange(room[5].xs+2,room[5].xs+8);
    door[6].y=room[5].ys+10;
    door[5].x=randomInRange(room[5].xs+2,room[5].xs+8);
    door[5].y=room[5].ys;
    map[door[6].x][room[5].ys+10]=',';
    map[door[5].x][room[5].ys]='+';
    int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
    int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
    if(map[xG5][yG5]=='.'){
        map[xG5][yG5]='G';
    }
    int counter1=0;
    while(counter1!=2){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='j';
            counter1++;
        }
    }
    int count11=0;
    while(count11!=1){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='U';
            count11++;
        }
    }
    int counter11=0;
    while(counter11!=1){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='1';
            counter11++;
        }
    }
    int counter12=0;
    while(counter12!=2){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='3';
            counter12++;
        }
    }
    int counter123=0;
    while(counter123!=1){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='2';
            counter123++;
        }
    }
    //غذا
    int count3=0;
    while(count3!=2){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]='0';
            count3++;
        }
    }
    int count34=0;
    while(count34!=1){
        int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
        if(map[xG5][yG5]=='.'){
            map[xG5][yG5]=':';
            count34++;
        }
    }
    //====================================================
    //ساخت مسیر بین درب ها  
    generateRandomPath();
    //گذاشتن تله به صورت رندم در بعضی اتاق ها 
    int xT1=randomInRange(room[1].xs+2,room[1].xs+8);
    int yT1=randomInRange(room[1].ys+2,room[1].ys+8);
    if(map[xT1][yT1]=='.'){
        map[xT1][yT1]='^';
    }
    int xT3=randomInRange(room[3].xs+2,room[3].xs+8);
    int yT3=randomInRange(room[3].ys+2,room[3].ys+8);
    if(map[xT3][yT3]=='.'){
        map[xT3][yT3]='^';
    }
    int xT5=randomInRange(room[5].xs+2,room[5].xs+8);
    int yT5=randomInRange(room[5].ys+2,room[5].ys+8);
    if(map[xT5][yT5]=='.'){
        map[xT5][yT5]='^';
    }
    }
}
int startgame(int v,int tabagheh2){
    clear();
    noecho();
    if(v==0||v==2){
        generatemap(tabagheh,0);
        adamak.x=27;
        adamak.y=1;
        for(int i=0;i<49;i++){
            for(int j=0;j<183;j++){
                mark.m[i][j]=0;    
            }
        }
    }
    for(int i=0;i<25;i++){
        for(int j=0;j<30;j++){
            mark_color[i][j]=1;
        }
    }
    for(int i=0;i<25;i++){
        for(int j=30;j<90;j++){
            mark_color[i][j]=2;
        }
    }
    for(int i=0;i<25;i++){
        for(int j=90;j<183;j++){
            mark_color[i][j]=3;
        }
    }
    for(int i=25;i<49;i++){
        for(int j=0;j<30;j++){
            mark_color[i][j]=4;
        }
    }
    for(int i=25;i<49;i++){
        for(int j=30;j<90;j++){
            mark_color[i][j]=5;
        }
    }
    for(int i=25;i<49;i++){
        for(int j=90;j<183;j++){
            mark_color[i][j]=6;
        }
    }
    time_t start_time,current_time;
    double elapsed_time;
    bool condition=false;
    start_time=time(NULL);
    while(1){
        //پایان بازی دز صوزت حان زیر۰  
        if(HEALTH<=0){
            clear();
            mvprintw(20,65,"YOU LOST");
            mvprintw(21,65,"YOUR GOLD: %d",GOLD);
            mvprintw(22,65,"YOUR SCORE: %d ",GOLD*10);
            mvprintw(23,65,"PLEAS ENTER ANY KEY TO MOVE TO THE MENU...");
            char c=getch();
            refresh();
            HEALTH=100;
            break;
        }
        //اضافه شدن جان بعد از ۲۰ ثانیه
        current_time=time(NULL);
        elapsed_time=difftime(current_time,start_time);
        if(elapsed_time>=20){
            if(HEALTH<=99){
                HEALTH+=1;
            }
            start_time=time(NULL);
        }
            for(int i=0;i<49;i++){
                for(int j=0;j<182;j++){
                    if(mark_color[i][j]==1){
                        init_pair(1,COLOR_RED,COLOR_BLACK);
                        attron(COLOR_PAIR(1));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }

                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(1));
                    }
                    else if(mark_color[i][j]==2){
                        init_pair(2,COLOR_BLUE,COLOR_BLACK);
                        attron(COLOR_PAIR(2));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(2));
                    }
                    else if(mark_color[i][j]==3){
                        init_pair(3,COLOR_GREEN,COLOR_BLACK);
                        attron(COLOR_PAIR(3));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(3));
                    }
                    else if(mark_color[i][j]==4){
                        init_pair(4,COLOR_YELLOW,COLOR_BLACK);
                        attron(COLOR_PAIR(4));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(4));
                    }
                    else if(mark_color[i][j]==5){
                        init_pair(5,COLOR_WHITE,COLOR_BLACK);
                        attron(COLOR_PAIR(5));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(5));
                    }
                    else if(mark_color[i][j]==6){
                        init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
                        attron(COLOR_PAIR(6));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='e'){
                            const char *unicode_char="🏁";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(6));
                    }
                }
                printw("\n");
            }
        //جا هایی که ادمک رفته دیگه باید نمایان باشند
        mark.m[adamak.x][adamak.y]=1;
        // مسیر پیش رو تا ۵ خانه باید نمایان باشند
        for(int i=adamak.x-5;i<adamak.x+5;i++){
            for(int j=adamak.y-5;j<adamak.y+7;j++){
                if(i>49||i<0||j>183||j<0){
                    continue;
                }
                if(map[i][j]=='#'){
                    mark.m[i][j]=1;
                }
            }
        }
        //برای نمایش اتاق ها وقتی ادمک به +میرسد
        if(map[adamak.x][adamak.y]=='+'||map[adamak.x][adamak.y]=='@'||map[adamak.x][adamak.y]=='$'||map[adamak.x][adamak.y]=='?'){
            for(int i=adamak.x-10;i<adamak.x+10;i++){
                for(int j=adamak.y-10;j<adamak.y+12;j++){
                    if(i>49||i<0||j>183||j<0){
                        continue;
                    }
                    else{
                        mark.m[i][j]=1;
                    }
            }
        }      
        }
        if(vv!=1000&&tabagheh2!=5){
            for(int i=1;i<48;i++){
                for(int j=0;j<183;j++){
                    if(mark.m[i][j]==0){
                        mvprintw(i,j,"%c",' ');
                    }
                    else if(mark.m[i][j]==1){
                        continue;
                    }
                }
                printw("\n");
            }
        }
        refresh();    
        //نمایش کاراکتر
        //🤖 , 👾 ,⛄️ ,🛹,🥷
        mvprintw(adamak.x,adamak.y,"%s",unicode_char8095);
        refresh(); 
        //نمایش تعداد طلا ها در نوار بازی
        mvprintw(49,0,"GOLD  :%d",GOLD);
        const char *tala="💰";
        mvprintw(49,4,"%s",tala); 
        //نمایش طبقه
        mvprintw(49,10,"FLOOR:%d  ",tabagheh);
        //نمایش سلامتی
        const char *ghalb="♥️";
        mvprintw(49,20,"HEALTH :%d",HEALTH);
        mvprintw(49,25,"%s",ghalb);
        //نمایش اسلحه در دست
        if(your_weapon!=-1){
            const char*sh="⚔️";
            const char*kh="🗡️";
            const char*asa1="🪄";
            const char*tir1="➳";
            const char*tabar="🪓";
            const char *T_health1="⚝";
            const char *T_speed1="✦";
            const char *T_damage1="☽";
            if(your_weapon==4){
                if(shamshir!=0){
                    mvprintw(49,35,"WEAPON READY TO USE  :%s",sh);
                }
                else{
                    your_weapon=-1;
                }
            }
            else if(your_weapon==1){
                if(khanjar!=0){
                    mvprintw(49,35,"WEAPON READY TO USE  :%s",kh);
                }
                else{
                    your_weapon=-1;
                }
            }
            else if(your_weapon==2){
                if(asa!=0){
                    mvprintw(49,35,"WEAPON READY TO USE  :%s",asa1);
                }
                else{
                    your_weapon=-1;
                }
            }
            else if(your_weapon==3){
                if(tir!=0){
                    mvprintw(49,35,"WEAPON READY TO USE  :%s",tir1);
                }
                else{
                    your_weapon=-1;
                }
            }
            else{
                mvprintw(49,35,"WEAPON READY TO USE  :%s",tabar);
            }
        }
        refresh();
        char c=getch();
        //برای دیدن لیست اسلحه ها
        if(c=='i'){
            gunandspellmenu();
            clear();
        }
        //برای اینمه در موقع باگ به مسیر برگردد
        else if(c=='}'){
            adamak.x=door[3].x;
            adamak.y=door[3].y-9;
        }
        else if(c=='{'){
            adamak.x=27;
            adamak.y=1;
        }
        // یرای دیدن کل نقشه
        else if(c=='M'){
            clear();
            for(int i=0;i<49;i++){
                for(int j=0;j<182;j++){
                    if(mark_color[i][j]==1){
                        init_pair(1,COLOR_RED,COLOR_BLACK);
                        attron(COLOR_PAIR(1));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(1));
                    }
                    else if(mark_color[i][j]==2){
                        init_pair(2,COLOR_BLUE,COLOR_BLACK);
                        attron(COLOR_PAIR(2));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(2));
                    }
                    else if(mark_color[i][j]==3){
                        init_pair(3,COLOR_GREEN,COLOR_BLACK);
                        attron(COLOR_PAIR(3));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(3));
                    }
                    else if(mark_color[i][j]==4){
                        init_pair(4,COLOR_YELLOW,COLOR_BLACK);
                        attron(COLOR_PAIR(4));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(4));
                    }
                    else if(mark_color[i][j]==5){
                        init_pair(5,COLOR_WHITE,COLOR_BLACK);
                        attron(COLOR_PAIR(5));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(5));
                    }
                    else if(mark_color[i][j]==6){
                        init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
                        attron(COLOR_PAIR(6));
                        if(map[i][j]=='G'){
                        const char *unicode_char="🎗️";
                            printw("%s",unicode_char);           
                        }
                        else if(map[i][j]=='C'){
                            printw("%c",'G');
                        }
                        else if(map[i][j]==';'){
                            const char *unicode_char="⚜️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]==':'){
                            const char *unicode_char="❤";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='g'){
                            const char *unicode_char="▫️";
                            addstr(unicode_char);
                        }
                        else if(map[i][j]=='j'){
                            const char *unicode_char="⚱️";
                            printw("%s",unicode_char);
                        }
                        //در مخفی
                        else if(map[i][j]==','){
                            printw("%c",'|');
                        }
                        else if(map[i][j]=='^'){
                            printw("%c",'.');
                        }
                        //وقتی تله غیر فعال میشود با این نماد نشان میدهیم {
                        else if(map[i][j]=='{'){
                            printw("%c",'^');
                        }
                        else if(map[i][j]=='1'){
                            const char *unicode_char="🗡️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='2'){
                            const char *unicode_char="🪄";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='3'){
                            const char *unicode_char="➳";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='4'){
                            const char *unicode_char="⚔️";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='5'){
                            const char *unicode_char="⚝";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='6'){
                            const char *unicode_char="✦";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='7'){
                            const char *unicode_char="☽";
                            printw("%s",unicode_char);
                        }
                        else if(map[i][j]=='0'){ 
                            printw("%s","❤");
                        }
                        else if(map[i][j]=='@'){
                            init_pair(1,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",map[i][j]);
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='$'){
                            init_pair(1,COLOR_GREEN,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            printw("%c",'@');
                            attroff(COLOR_PAIR(1));
                        }
                        else if(map[i][j]=='9'){
                            init_pair(7,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(7));
                            const char*kilid="△";
                            printw("%s",kilid);
                            attroff(COLOR_PAIR(7));
                        }
                        else{
                            printw("%c",map[i][j]);
                        }
                        attroff(COLOR_PAIR(6));
                    }
                }
                printw("\n");
            }
            refresh();
            char t=getch();
        }
        //استفاده از سلاح
        else if(c==' '){
            if(your_weapon==1){
                if(khanjar>=1){
                    char c=getch();
                    if(c=='d'){
                        int count=0;
                        int target=0;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            y++;
                            if(map[adamak.x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='S'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='a'){
                        int count=0;
                        int target=0;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            y--;
                            if(map[adamak.x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='w'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        while(count!=5){
                            count++;
                            x--;
                            if(map[x][adamak.y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='x'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        while(count!=5){
                            count++;
                            x++;
                            if(map[x][adamak.y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }
                    }
                    else if(c=='e'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            x--;
                            y++;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='q'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            x--;
                            y--;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }


                    }
                    else if(c=='c'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            x++;
                            y++;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }


                    }
                    else if(c=='z'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=5){
                            count++;
                            x++;
                            y--;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=12;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=12;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=12;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=12;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=12;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    khanjar--;
                }
                else{
                    mvprintw(0,0,"you don't have enough weapons!");
                    refresh();
                    mvprintw(0,0,"                                  ");
                    usleep(2000000);
                }

            }
            else if(your_weapon==2){
                if(asa>=1){
                    char c=getch();
                    if(c=='d'){
                        int count=0;
                        int target=0;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            y++;
                            if(map[adamak.x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='S'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='a'){
                        int count=0;
                        int target=0;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            y--;
                            if(map[adamak.x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[adamak.x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='w'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        while(count!=10){
                            count++;
                            x--;
                            if(map[x][adamak.y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='x'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        while(count!=10){
                            count++;
                            x++;
                            if(map[x][adamak.y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][adamak.y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }
                    }
                    else if(c=='e'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            x--;
                            y++;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    else if(c=='q'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            x--;
                            y--;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }


                    }
                    else if(c=='c'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            x++;
                            y++;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }


                    }
                    else if(c=='z'){
                        int count=0;
                        int target=0;
                        int x=adamak.x;
                        int y=adamak.y;
                        while(count!=10){
                            count++;
                            x++;
                            y--;
                            if(map[x][y]=='D'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.d-=15;
                                if(joon.d<=0){
                                    mvprintw(0,0,"deamon was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"deamon's health  %d ",joon.d);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='F'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.f-=15;
                                if(joon.f<=0){
                                    mvprintw(0,0,"fire breathing monster was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='U'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.u-=15;
                                if(joon.u<=0){
                                    mvprintw(0,0,"undeed was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"undeed's health  %d ",joon.u);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='C'){

                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.g-=15;
                                if(joon.g<=0){
                                    mvprintw(0,0,"giant was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"giant's health  %d ",joon.g);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                            else if(map[x][y]=='S'){
                                mvprintw(0,0,"hit the target!");
                                refresh();
                                mvprintw(0,0,"                                  ");
                                usleep(2000000);
                                joon.s-=15;
                                if(joon.s<=0){
                                    mvprintw(0,0,"snake was destroyed");
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                else{
                                    mvprintw(0,0,"snake's health  %d ",joon.s);
                                    refresh();
                                    mvprintw(0,0,"                                  ");
                                    usleep(2000000);
                                }
                                target=1;
                                break;
                            }
                        }
                        if(target==0){
                            mvprintw(0,0,"it did not hit the target!");
                            refresh();
                            mvprintw(0,0,"                                  ");
                            usleep(2000000);
                        }

                    }
                    asa--;
                }
                else{
                    mvprintw(0,0,"you don't have enough weapons!");
                    refresh();
                    mvprintw(0,0,"                                  ");
                    usleep(2000000);
                }
            }
            else if(your_weapon==3){


            }
            else if(your_weapon==4){

            }
            else{

            }

        }
        //برای دیدن لیست غذا و مصرف غذا
        else if(c=='E'){
            foodmenu();
            clear();
        }
        //دکمه های حرکت
        else if(c=='f'){
            char c2=getch();
            if(c2=='w'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.x--;   
                }
                adamak.x++; 
            }
            else if(c2=='x'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.x++;   
                }
                adamak.x--;
            }
            else if(c2=='a'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y--;   
                }
                adamak.y++; 
            }
            else if(c2=='d'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y++;   
                }
                adamak.y--;
            }
            else if(c2=='q'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y--;
                    adamak.x--;   
                }
                adamak.y++;
                adamak.x++; 
            }
            else if(c2=='e'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y++;
                    adamak.x--;   
                }
                adamak.y--;
                adamak.x++;
            }
            else if(c2=='z'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y--;
                    adamak.x++;   
                }
                adamak.y++;
                adamak.x--;
            }
             else if(c2=='c'){
                while(!(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0)){
                    adamak.y++;
                    adamak.x++;   
                }
                adamak.y++;
                adamak.x--;
            }
        }
        else if(c=='g'){
            char c2=getch();
            if(c2=='w'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.x--;   
                }
                adamak.x++; 
            }
            else if(c2=='x'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.x++;   
                }
                adamak.x--;
            }
            else if(c2=='a'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y--;   
                }
                adamak.y++; 
            }
            else if(c2=='d'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y++;   
                }
                adamak.y--;
            }
            else if(c2=='q'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y--;
                    adamak.x--;   
                }
                adamak.y++;
                adamak.x++; 
            }
            else if(c2=='e'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y++;
                    adamak.x--;   
                }
                adamak.y--;
                adamak.x++;
            }
            else if(c2=='z'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y--;
                    adamak.x++;   
                }
                adamak.y++;
                adamak.x--;
            }
             else if(c2=='c'){
                while(map[adamak.x][adamak.y]=='.'||map[adamak.x][adamak.y]=='#'||map[adamak.x][adamak.y]=='+'){
                    adamak.y++;
                    adamak.x++;   
                }
                adamak.y++;
                adamak.x--;
            }
        }
        else if(c=='w'){
            adamak.x--;
            int key=randomInRange(1000,9999);
            //در صورت برخورد با موانع بازگشت به حالت قبل
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
            }
            //برخورد با هیولا 
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=1;
                mvprintw(0,0,"you were hurt!  -1");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            //پایان بازی
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                refresh();
                move(22,60);
                refresh();
                echo();
                char username[50];
                char username_filename[50];
                scanf("%s",username);
                scanf("%s",username_filename);
                savegame(username,username_filename);
                svaescore(username1234,GOLD);
                }
                break;
            }
            //برخورد با کلید تولید دکمه رمز
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            //در رمز دار
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.x++;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.x++;
                }
            }
            //در مخفی
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            //درصورت برخورد با طلا جمع اوری طلا
            //طلای عادی
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            //کیسه طلا
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            //انتقال به اتاق گنچ
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                vv=1000;
                tabagheh++;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            //طلای سیاه
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            //برخورد با طلسم
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            //برخورد با غذا
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            //برخورد با سلاح
            else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            //برخورد با پله
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            //برخورد با تله
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
        }
        else if(c=='d'){
            adamak.y++;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.y--;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt! -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                refresh();
                move(22,60);
                refresh();
                echo();
                char username[50];
                char username_filename[50];
                scanf("%s",username);
                scanf("%s",username_filename);
                savegame(username,username_filename);
                svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.y--;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.y--;
                }
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
           else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='x'){
            adamak.x++;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                refresh();
                move(22,60);
                refresh();
                echo();
                char username[50];
                char username_filename[50];
                scanf("%s",username);
                scanf("%s",username_filename);
                savegame(username,username_filename);
                svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.x--;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.x--;

                }
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
           else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='a'){
            adamak.y--;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.y++;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                    mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                    refresh();
                    move(22,60);
                    refresh();
                    echo();
                    char username[50];
                    char username_filename[50];
                    scanf("%s",username);
                    scanf("%s",username_filename);
                    savegame(username,username_filename);
                    svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.y++;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.y++;
                }
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir++;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='q'){
            adamak.x--;
            adamak.y--;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
                adamak.y++;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                refresh();
                move(22,60);
                refresh();
                echo();
                char username[50];
                char username_filename[50];
                scanf("%s",username);
                scanf("%s",username_filename);
                savegame(username,username_filename);
                svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.x++;
                        adamak.y++;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.x++;
                    adamak.y++;
                }
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir++;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='z'){
            adamak.y--;
            adamak.x++;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
                adamak.y++;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                refresh();
                move(22,60);
                refresh();
                echo();
                char username[50];
                char username_filename[50];
                scanf("%s",username);
                scanf("%s",username_filename);
                savegame(username,username_filename);
                svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                 if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.x++;
                        adamak.y--;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.x++;
                    adamak.y--;
                }
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir++;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='e'){
            adamak.y++;
            adamak.x--;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
                adamak.y--;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                    mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                    refresh();
                    move(22,60);
                    refresh();
                    echo();
                    char username[50];
                    char username_filename[50];
                    scanf("%s",username);
                    scanf("%s",username_filename);
                    savegame(username,username_filename);
                    svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x+1][adamak.y]=='?'){
                map[adamak.x+1][adamak.y]='+';
            }
            else if( map[adamak.x][adamak.y+1]=='?'){
                 map[adamak.x][adamak.y+1]='+';
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    map[adamak.x][adamak.y]='$';
                    refresh();
                    usleep(3000000);
                    continue;
                }
                    clear();
                    echo();
                    if(khata<3){
                        mvprintw(20,60,"pleas enter the code");
                        refresh();
                        char a[30];
                        scanf("%s",a);
                        if(!correctcode(const_int,a)){
                            adamak.x--;
                            adamak.y++;
                            clear();
                            khata++;
                            if(khata==1){
                                init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                                attron(COLOR_PAIR(1));
                                mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                                refresh();
                                attroff(COLOR_PAIR(1));
                                usleep(3000000);
                            }
                            else if(khata==2){
                                init_pair(2,COLOR_RED,COLOR_YELLOW);
                                attron(COLOR_PAIR(2));
                                mvprintw(20,60,"the password is incorrect(one opportunities left)");
                                refresh();
                                attroff(COLOR_PAIR(2));
                                usleep(3000000);
                            }
                            else if(khata==3){
                                init_pair(3,COLOR_RED,COLOR_BLACK);
                                attron(COLOR_PAIR(3));
                                mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                                refresh();
                                attroff(COLOR_PAIR(3));
                                usleep(3000000);
                            }
                        }
                        else {
                            map[adamak.x][adamak.y]='$';
                        }
                    }
                    else{
                        adamak.x--;
                        adamak.y++;
                    }
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir++;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        else if(c=='c'){
            adamak.y++;
            adamak.x++;
            int key=randomInRange(1000,9999);
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
                adamak.y--;
            }
            else if(map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'||map[adamak.x+1][adamak.y-1]=='D'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'||map[adamak.x+1][adamak.y-1]=='F'){
                HEALTH-=3;
                mvprintw(0,0,"you were hurt!  -3");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'||map[adamak.x+1][adamak.y-1]=='C'){
                HEALTH-=5;
                mvprintw(0,0,"you were hurt!  -5");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'||map[adamak.x+1][adamak.y-1]=='S'){
                HEALTH-=7;
                mvprintw(0,0,"you were hurt!  -7");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'||map[adamak.x+1][adamak.y-1]=='U'){
                HEALTH-=9;
                mvprintw(0,0,"you were hurt!  -9");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                           ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='e'){
                clear();
                mvprintw(20,60,"Congratulations, you have completed the game");
                mvprintw(22,60,"The amount of GOLD you have collected : %d",GOLD);
                mvprintw(24,60,"your score : %d",GOLD*10);
                refresh();
                usleep(4000000);
                clear();
                if(v!=0){
                    mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                    refresh();
                    move(22,60);
                    refresh();
                    echo();
                    char username[50];
                    char username_filename[50];
                    scanf("%s",username);
                    scanf("%s",username_filename);
                    savegame(username,username_filename);
                    svaescore(username1234,GOLD);
                }
                break;
            }
            else if(map[adamak.x][adamak.y]=='9'){
                map[adamak.x][adamak.y]='.';
                Ancient_Key=1;
            }
            else if(map[adamak.x][adamak.y]==';'){
                clear();
                mvprintw(20,65,"you are being transported to the treasure room");
                tabagheh++;
                vv=1000;
                generatemap(4,1);
                refresh();
                usleep(2000000);
            }
            else if(map[adamak.x][adamak.y]=='&'){
                clear();
                printw("your code : %d",key);
                const_int=key;
                refresh();
                usleep(4000000);
            }
            else if(map[adamak.x+1][adamak.y]==','){
                map[adamak.x+1][adamak.y]='?';
            }
            else if( map[adamak.x][adamak.y+1]==','){
                 map[adamak.x][adamak.y+1]='?';
            }
            else if(map[adamak.x][adamak.y]=='@'){
                if(Ancient_Key==1){
                    Ancient_Key=0;
                    clear();
                    mvprintw(20,60,"the door was opened with a Ancient Key");
                    refresh();
                    usleep(3000000);
                    map[adamak.x][adamak.y]='$';
                    continue;
                }
                clear();
                echo();
                if(khata<3){
                    mvprintw(20,60,"pleas enter the code");
                    refresh();
                    char a[30];
                    scanf("%s",a);
                    if(!correctcode(const_int,a)){
                        adamak.x--;
                        adamak.y--;
                        clear();
                        khata++;
                        if(khata==1){
                            init_pair(1,COLOR_YELLOW,COLOR_BLACK);
                            attron(COLOR_PAIR(1));
                            mvprintw(20,60,"the password is incorrect(Two opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(1));
                            usleep(3000000);
                        }
                        else if(khata==2){
                            init_pair(2,COLOR_RED,COLOR_YELLOW);
                            attron(COLOR_PAIR(2));
                            mvprintw(20,60,"the password is incorrect(one opportunities left)");
                            refresh();
                            attroff(COLOR_PAIR(2));
                            usleep(3000000);
                        }
                        else if(khata==3){
                            init_pair(3,COLOR_RED,COLOR_BLACK);
                            attron(COLOR_PAIR(3));
                            mvprintw(20,60,"the password is incorrect(SECURITY MODE)");
                            refresh();
                            attroff(COLOR_PAIR(3));
                            usleep(3000000);
                        }
                    }
                    else {
                        map[adamak.x][adamak.y]='$';
                    }
                }
                else{
                    adamak.x--;
                    adamak.y--;
                }
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD+=3;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='0'){
                if(food<=4){
                    map[adamak.x][adamak.y]='.';
                    food++;
                    mvprintw(0,0,"Food added");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                     ");
                    refresh();
                }
                else{
                    mvprintw(0,0,"Not enough space available");
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                           ");
                    refresh();
                }
            }
            else if(map[adamak.x][adamak.y]==':'){
                    map[adamak.x][adamak.y]='.';
                    HEALTH-=5;
                    const char *const_char="😈"; 
                    mvprintw(0,0,"the food was poisonous    %s   ",const_char );
                    refresh();
                    usleep(2000000);
                    mvprintw(0,0,"                                     ");
                    refresh();
            }
            else if(map[adamak.x][adamak.y]=='5'){
                map[adamak.x][adamak.y]='.';
                T_health++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            } 
            else if(map[adamak.x][adamak.y]=='6'){
                map[adamak.x][adamak.y]='.';
                T_speed++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }    
            else if(map[adamak.x][adamak.y]=='7'){
                map[adamak.x][adamak.y]='.';
                T_damage++;
                mvprintw(0,0,"spell added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='j'){
                GOLD+=10;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected a BAG OF GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='g'){
                GOLD+=1;
                map[adamak.x][adamak.y]='.';
                mvprintw(0,0,"Congratulations,You have collected black GOLD!");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                                         ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                for(int i=0;i<49;i++){
                    for(int j=0;j<183;j++){
                        mark.m[i][j]=0;
                    }
                }
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(2000000);
                tabagheh++;
                if(tabagheh==4||tabagheh==2){
                    adamak.x=26;
                    adamak.y=170;
                }
                generatemap(tabagheh,0);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= decrease;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='{';
            }
             else if(map[adamak.x][adamak.y]=='4'){
                //;
                map[adamak.x][adamak.y]='.';
                shamshir++;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='2'){
                //;
                map[adamak.x][adamak.y]='.';
                asa+=8;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='1'){
                //;
                map[adamak.x][adamak.y]='.';
                khanjar+=10;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
            else if(map[adamak.x][adamak.y]=='3'){
                //;
                map[adamak.x][adamak.y]='.';
                tir+=20;
                mvprintw(0,0,"Weapon added");
                refresh();
                usleep(2000000);
                mvprintw(0,0,"                     ");
                refresh();
            }
        }
        //برای خروج پ فرایند سیو شدن بازی
        else if(c=='`'){
            mvprintw(0,0,"are you want to exit the game?(to exit press[ y ])");
            refresh();
            char c2=getch(); 
            if(c2=='y'){
                clear();
                mvprintw(20,60,"are you want to save the game?(to save press[ y ])");
                refresh();
                char c1=getch();
                if(c1=='y'){
                    clear();
                    mvprintw(20,60,"plaes enter your username and filename:(username  and  username_filename )");
                    refresh();
                    move(22,60);
                    refresh();
                    echo();
                    char username[50];
                    char username_filename[50];
                    scanf("%s",username);
                    scanf("%s",username_filename);
                    savegame(username,username_filename);
                    return 0;
                }
                else{
                    return 0;
                }
            }
        }
        clear();
    }
}
void Loadgame(const char username[]){
    clear();
    char filename[100];
    //خوندن نام بازی های سیوی کاربر
    snprintf(filename,sizeof(filename),"%s.txt",username);
    FILE*fptr=fopen(filename,"r");
    char a[50];
    move(0,0);
    while(fgets(a,sizeof(a),fptr)!=NULL){
        printw("%s",a);
    }
    refresh();
    echo();
    mvprintw(20,60,"pleas enter the name of the saved game:");
    refresh();
    move(21,60);
    char name[50];
    scanf("%s",name);
    refresh();
    clear();
    char filename1[100];
    snprintf(filename1,sizeof(filename1),"%s.txt",name);
    FILE* game =fopen(filename1,"r");
    char temp[49*183][2];
    for(int i=0;i<49*183;i++){
        fscanf(game,"%s",temp[i]);
    }
    for(int i=0;i<49;i++){
        for(int j=0;j<183;j++){
            if(temp[(183*i)+j][0]=='!'){
                map[i][j]=' ';
            }
            else{
                map[i][j]=temp[(183*i)+j][0];
            }
        }
    }   
    int GOLD2;
    int HEALTH2;
    int food2;
    int shamshir2;
    int khanjar2;
    int tir2;
    int asa2;
    int T_damage2;
    int T_health2;
    int T_speed2;
    int tabagheh2;
    int x;
    int y;
    int Ancient_Key1;
    fscanf(game,"%d",&GOLD2);
    GOLD=GOLD2;
    fscanf(game,"%d",&HEALTH2);
    HEALTH=HEALTH2;
    fscanf(game,"%d",&food2);
    food=food2;
    fscanf(game,"%d",&shamshir2);
    shamshir=shamshir2;
    fscanf(game,"%d",&khanjar2);
    khanjar=khanjar2;
    fscanf(game,"%d",&tir2);
    tir=tir2;
    fscanf(game,"%d",&asa2);
    asa=asa2;
    fscanf(game,"%d",&T_damage2);
    T_damage=T_damage2;
    fscanf(game,"%d",&T_health2);
    T_health=T_health2;
    fscanf(game,"%d",&T_speed2);
    T_speed=T_speed2;
    fscanf(game,"%d",&tabagheh2);
    tabagheh=tabagheh2;
    fscanf(game,"%d",&x);
    adamak.x=x;
    fscanf(game,"%d",&y);
    adamak.y=y;
    fscanf(game,"%d",&Ancient_Key1);
    Ancient_Key=Ancient_Key1;
    fscanf(game,"%s",username1234);
    fscanf(game,"%d",&your_weapon);
    for(int i=0;i<49;i++){
        for(int j=0;j<183;j++){
            fscanf(game,"%d",&mark.m[i][j]);
        }
    }
    fclose(fptr);
    fclose(game);
    // clear();
    // for(int i=0;i<49;i++){
    //     for(int j=0;j<183;j++){
    //         printw("%c",map[i][j]);
    //     }
    //     printw("\n");
    // }
    // refresh();
    // usleep(30000000);
    startgame(1,tabagheh2);
}
//برای چک پسورد برای login
int checkpasword2(char b[],int target){
    FILE *passwords=fopen("passwords.txt","r");
    int current_line=0;
    char passwordchek[1000];
    while(fgets(passwordchek,sizeof(passwordchek),passwords)!=NULL){
        if(current_line==target){
            passwordchek[strlen(passwordchek)-1]='\0';
            if(strcmp(passwordchek,b)==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        current_line++;
    }
}
//چک کردن یوزرنیم برای login
int checkusername2(char a[]){
    FILE *usernames1=fopen("usernames.txt","r");
    int i=0;
    char userchek[1000];
    while(fgets(userchek,1000,usernames1)!=NULL){
        userchek[strlen(userchek)-1]='\0';
        if(strcmp(userchek,a)==0){
            return i;
        }
        i++;
    }
    return -1;
}
int Login(){
    clear();
    mvprintw(20,60,"pleas enter your username:");
    refresh();
    char a[1000];
    scanw("%s",a);
    if(checkusername2(a)!=-1){
        //درواقع اینجا ردیف پسورد را ذخیره میکنیم برای تطابق رمز
        int target=checkusername2(a);
        clear();
        mvprintw(20,60,"pleas enter your password:");
        refresh();
        char b[1000];
        scanw("%s",b);
        if(checkpasword2(b,target)){
            //وارد شدن به بازی
            clear();
            strcpy(username1234,a);
            const char *unicode_char="⏳";
            mvprintw(20,71,"%s",unicode_char);
            mvprintw(20,60,"Loading...");
            refresh();
            usleep(3000000);
            clear();
            mvprintw(20,60,"to play the NEW game press(1)");
            mvprintw(21,60,"to play the saved game press(2)");
            refresh();
            char c6=getch();
            if(c6=='1'){
                startgame(2,tabagheh);
            }
            else if(c6=='2'){
                Loadgame(a);    
            }
            clear();
            return 0;
        }
        else{
            clear();
            mvprintw(20,60,"invalid password!pleas try again");
            refresh();
            usleep(4000000);
            Login();
        }
    }
    else{
        clear();
        mvprintw(20,60,"invalid username!pleas try again");
        //برای اینکه فرصت نمایش به کاربر داده شود
        refresh();
        usleep(4000000);
        Login();
    }
}
int checkemail(char a[]){
    int len_a=strlen(a);
    //q1برای چک کردن @
    int q1=0;
    //q2 برای چک کردن .
    int q2=0;
    //برای اینکه بین @و.حتما کاراکتری وجود داشته باشد
    int q3=0;
    if(a[0]=='@'||a[0]==' '){
        return 0;
    }
    if(a[len_a-1]=='.'){
        return 0;
    }
    for(int i=0;i<len_a;i++){
        if(a[i]=='@'){
            q1=1;
            q3=i;
        }
        else if(a[i]=='.'){
            q2=1;
        }
    }
    if(a[q3+1]=='.'){
        return 0;
    }
    if(q1&&q2){
        return 1;
    }
    else{
        return 0;
    }
}
int checkusername(char a[]){
    char userchek[1000];
    FILE *usernames1=fopen("usernames.txt","r");
    while(fgets(userchek,1000,usernames1)!=NULL){
        userchek[strlen(userchek)-1]='\0';
        if(strcmp(userchek,a)==0){
            return 0;
        }
    }
    return 1;
}
int checkpasword(char a[]){
    if(strlen(a)<7){
        clear();
        mvprintw(20,60,"invalid password try again:");
        return 0;
    }
    int lowercase=0;
    int uppercase=0;
    int number=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]>='A'&&a[i]<='Z'){
            uppercase=1;
        }
        if(a[i]>='a'&&a[i]<='z'){
            lowercase=1;
        }
        if(a[i]>='0'&&a[i]<='9'){
            number=1;
        }
    }
    if(number&&lowercase&&uppercase){
        return 1;
    }
    else{
        clear();
        mvprintw(20,60,"invalid password try again:");
        return 0;
    }

}
void savepassword(){
    char a[100];
    scanw("%s",a);
    if(checkpasword(a)){
    FILE *passwords=fopen("passwords.txt","a");
    fprintf(passwords,"%s\n",a);
    fclose(passwords);
    }
    else{
        savepassword();
    }
}
void saveemail(){
    char a[100];
    scanw("%s",a);
    if(checkemail(a)){
        FILE *emails=fopen("emails.txt","a");
        fprintf(emails,"%s\n",a);
        fclose(emails);
    }
    else{
        clear();
        mvprintw(20,60,"invalid email! try again:");
        saveemail(); 
    }
}
void saveusername(){
    char a[100];
    scanw("%s",a);
    if(checkusername(a)){
        FILE *usernames=fopen("usernames.txt","a");
        // int score=0;
        // int rank=0;
        // int gold=0;
        // int games=0;
        // int time=0;
        fprintf(usernames,"%s\n",a);
        fclose(usernames);
    }
    else{
        clear();
        mvprintw(20,60,"the username is duplicate! try again:");
        saveusername();
    }
}
void createaccount(){
    clear();
    move(20,60);
    printw("plaese enter your username:");
    saveusername();
    move(22,60);
    printw("plaese enter your emai:");
    saveemail();
    move(24,60);
    printw("plaese enter your password:");
    savepassword();
    clear();
    mvprintw(20,55,"congratulations! your account has been successfully created");
    mvprintw(22,55,"plaes press any key...");
    //گرفتن یک چر الکی که صفحه تا زدن دکمه توسط کاربر باقی بماند 
    char p=getch();
}
void Settings(){
    clear();
    mvprintw(18,60,"choose the difficulty level of the game (1)");
    mvprintw(20,60,"choose the character of the game (2)");
    refresh();
    char c=getch();
    if(c=='1'){
        clear();
        mvprintw(18,60,"easy(1)");
        mvprintw(20,60,"intermediate(2)");
        mvprintw(22,60,"hard(3)");
        refresh();
        char c1=getch();
        if(c1=='1'){
            decrease=5;
        }
        else if(c1=='2'){
            decrease=10;
        }
        else if(c1=='3'){
            decrease=15;
        }
    }
    else if(c=='2'){
        //unicode_char8095
        // 🤖, 👾 ,⛄️ ,🛹,🥷
        clear();
        mvprintw(0,0,"choose your character");
        const char*unicode_char1="🤖";
        mvprintw(18,68,"%s",unicode_char1);
        mvprintw(18,70,"(1)");
        const char*unicode_char2="👾";
        mvprintw(20,68,"%s",unicode_char2);
        mvprintw(20,70,"(2)");
        const char*unicode_char3="⛄️";
        mvprintw(22,68,"%s",unicode_char3);
        mvprintw(22,70,"(3)");
        const char*unicode_char4="🛹";
        mvprintw(24,68,"%s",unicode_char4);
        mvprintw(24,70,"(4)");
        const char*unicode_char5="🥷";
        mvprintw(26,68,"%s",unicode_char5);
        mvprintw(26,70,"(5)");
        refresh();
        char c3=getch();
        if(c3=='1'){
            unicode_char8095="🤖";
        }
        else if(c3=='2'){
            unicode_char8095="👾";
        }
        else if(c3=='3'){
            unicode_char8095="⛄️";
        }
        else if(c3=='4'){
            unicode_char8095="🛹";
        }
        else if(c3=='5'){
            unicode_char8095="🥷";
        }
        else{
            Settings();
        }
    }
    else{
        return;
    }
    Settings();
}
void display_menu(WINDOW *menu_win,int highlight,char *options[],int n_options){
    int x,y,i;
    x=2; 
    y=2; 
    box(menu_win,0,0);
    for(i=0;i<n_options;i++){
        if(highlight==i+1){
            wattron(menu_win,A_REVERSE);
            mvwprintw(menu_win,y+i,x,"%s",options[i]);
            wattroff(menu_win,A_REVERSE);
        }
        else{
            mvwprintw(menu_win,y+i,x,"%s",options[i]);
        }
    }
    wrefresh(menu_win);
}
int MENU(){
    char *options[6]={"Craete a new acconut","Login acconut","Settings","guest account","Scorboard","exit game"};
    int highlight=1;
    int choice=0;
    int c;
    refresh();
    keypad(stdscr,TRUE);
    refresh();
    while(1){
        display_menu(stdscr,highlight,options,6);
        c=getch();
        switch(c){
            case KEY_UP:
                if(highlight==1){
                    highlight=6;
                }
                else{
                    highlight--;
                }
                break;
            case KEY_DOWN:
                if(highlight==6){
                    highlight=1;
                }
                else{
                    highlight++;
                }
                break;
            case 10:
                choice=highlight;
                break;
            default:
                break;
        }
        if(choice!=0){
            break;
        }
    }
    switch(choice){
        case 1:
            createaccount();
            clear();
            MENU();
            break;
        case 2:
            Login();
            clear();
            init_pair(5,COLOR_GREEN,COLOR_BLACK);
            bkgd(COLOR_PAIR(5));
            MENU();
            break;
        case 3:
            Settings();
            clear();
            MENU();
            break;
        case 4:
            startgame(0,tabagheh);
            clear();
            init_pair(5,COLOR_GREEN,COLOR_BLACK);
            bkgd(COLOR_PAIR(5));
            MENU();
            break;
        case 5:
            Scoreboard();
            clear();
            init_pair(5,COLOR_GREEN,COLOR_BLACK);
            bkgd(COLOR_PAIR(5));
            echo();
            MENU();
        case 6:
            return 0;
    }
}
int main(){
    setlocale(LC_CTYPE, "");
    initscr();
    srand(time(NULL));
    start_color();
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    curs_set(FALSE);
    keypad(stdscr,TRUE);
    MENU();
    endwin();
    return 0;
}