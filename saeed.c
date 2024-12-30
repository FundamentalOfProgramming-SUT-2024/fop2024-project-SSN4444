//saeednoferesti 403106838
//49*183
//MENU->create account->back to MENU->Login->startgame->generatemap->
//پله در اتاق اخر ۱۰*۱۰ قرار دارد <
//اتاق طلسم شماره ۴ است
//اتاق گنج در طبقه ۴  و اتاق شماره ی ۳ است
//Tنماد طلسم
//Gنماد طلا است
//فعلا کاراکتر U به عنوان ادمک در نظر گرفته شده
//  سلاح اعداد ۱تا۹
#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
// #include<locale.h>
char map[49][183];
//برای شمارش طلا ها 
int GOLD=0;
int HEALTH=100;
//  سلاح اعداد ۱تا۹
char SELAH[9];
struct ADAMAK{
    int x;
    int y;
    int dir;
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
int randomInRange(int min,int max){
    return min+rand()%(max-min+1);
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
void generatemap(int tabagheh){
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
     int count=0;
     while(count!=3){
        int xG1=randomInRange(room[1].xs+2,room[1].xs+8);
        int yG1=randomInRange(room[1].ys+2,room[1].ys+8);
        if(map[xG1][yG1]=='.'){
            map[xG1][yG1]='G';
            count++;
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
    //اتاق گنج
    //برای شمارش و گذاشتن مقدار زیادی تلهو طلا 
    if(tabagheh==4){
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
     map[door[4].x][room[4].ys]='?';
     //اتاق طلسم 
     int countTT=0;
     while(countTT!=3){
        int xTT4=randomInRange(room[4].xs+2,room[4].xs+4);
        int yTT4=randomInRange(room[4].ys+2,room[4].ys+4);
        if(map[xTT4][yTT4]=='.'){
            map[xTT4][yTT4]='T';
            countTT++;
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
        int xp5=randomInRange(room[5].xs+2,room[5].xs+8);
        int yp5=randomInRange(room[5].ys+2,room[5].ys+8);
        map[xp5][yp5]='<';
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
    map[door[6].x][room[5].ys+10]='+';
    map[door[5].x][room[5].ys]='+';
    int xG5=randomInRange(room[5].xs+2,room[5].xs+8);
    int yG5=randomInRange(room[5].ys+2,room[5].ys+8);
    if(map[xG5][yG5]=='.'){
        map[xG5][yG5]='G';
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
int startgame(){
    clear();
    int tabagheh=1;
    generatemap(tabagheh);
    adamak.x=27;
    adamak.y=1;
    char u='U';
    while(1){
        for(int i=0;i<49;i++){
            for(int j=0;j<183;j++){
                printw("%c",map[i][j]);
            }
            printw("\n");
        }    
        //نمایش کاراکتر
        mvprintw(adamak.x,adamak.y,"%c",u); 
        //نمایش تعداد طلا ها در نوار بازی
        mvprintw(49,0,"GOLD:%d  ",GOLD); 
        //نمایش طبقه
        mvprintw(49,9,"FLOOR:%d  ",tabagheh);
        mvprintw(49,19,"HEALTH:%d",HEALTH);
        refresh();
        char c=getch();
        //دکمه های حرکت
        if(c=='w'){
            adamak.x--;
            //در صورت برخورد با موانع بازگشت به حالت قبل
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
            }
            //درصورت برخورد با طلا جمع اوری طلا
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            //برخورد با طلسم

            //برخورد با غذا

            //برخورد با سلاح

            //برخورد با پله
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
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
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='d'){
            adamak.y++;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.y--;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='x'){
            adamak.x++;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='a'){
            adamak.y--;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.y++;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='q'){
            adamak.x--;
            adamak.y--;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
                adamak.y++;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='z'){
            adamak.y--;
            adamak.x++;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
                adamak.y++;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='e'){
            adamak.y++;
            adamak.x--;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x++;
                adamak.y--;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
            }
        }
        else if(c=='c'){
            adamak.y++;
            adamak.x++;
            if(map[adamak.x][adamak.y]==' '||map[adamak.x][adamak.y]=='o'||map[adamak.x][adamak.y]=='|'||map[adamak.x][adamak.y]=='_'||adamak.y>183||adamak.y<0||adamak.x>49||adamak.x<0){
                adamak.x--;
                adamak.y--;
            }
            else if(map[adamak.x][adamak.y]=='G'){
                GOLD++;
                map[adamak.x][adamak.y]='.';
            }
            else if(map[adamak.x][adamak.y]=='<'){
                clear();
                adamak.x=27;
                adamak.y=1;
                mvprintw(20,60,"Move to the next floor");
                refresh();
                usleep(3000000);
                tabagheh++;
                generatemap(tabagheh);
            }
            else if(map[adamak.x][adamak.y]=='^'){
                if(HEALTH<=0){
                    clear();
                    mvprintw(20,60,"you lost");
                    refresh();
                    usleep(5000000);
                    return 0;
                }
                HEALTH -= 5;
                mvprintw(0,0,"you hit a trap !");
                refresh();
                usleep(3000000);
                mvprintw(0,0,"                ");
                refresh();
                map[adamak.x][adamak.y]='.';
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
                    //savegame();
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
//برای چک پسورد برای login
int checkpasword2(char b[],int target){
    FILE *passwords=fopen("passwords.txt","r");
    int current_line=0;
    char passwordchek[1000];
    while(fgets(passwordchek,sizeof(passwordchek),passwords)!=NULL){
        if(current_line==target){
            if(strncmp(passwordchek,b,strlen(passwordchek)-1)==0){
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
        if(strncmp(userchek,a,strlen(a))==0){
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
            mvprintw(20,60,"Loading...");
            refresh();
            usleep(4000000);
            startgame();
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
        if(strncmp(userchek,a,strlen(a))==0){
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
        int score=0;
        int rank=0;
        int gold=0;
        int games=0;
        int time=0;
        fprintf(usernames,"%s %d %d %d %d %d\n",a,score,rank,gold,games,time);
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
            MENU();
            break;
        // case 3:
        //     guest account();
        //     break;
        // case 4:
        //     Settings();
        //     break;
        // case 5:
        //     Scoreboard();
        case 6:
            return 0;
    }
}
int main(){
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