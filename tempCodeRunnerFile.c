// else if(c==' '){
        //     if(your_weapon==1){
        //         if(khanjar>=1){
        //             char c=getch();
        //             if(c=='d'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     y++;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='a'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     y--;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='w'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='x'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }
        //             }
        //             else if(c=='e'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='q'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='c'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='z'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             khanjar--;
        //             refresh();
        //         }
        //         else{
        //             mvprintw(0,0,"you don't have enough weapons!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             refresh();
        //         }

        //     }
        //     else if(your_weapon==2){
        //         if(asa>=1){
        //             char c=getch();
        //             if(c=='d'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     y++;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='a'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     y--;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");

        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='w'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=10){
        //                     count++;
        //                     x--;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");

        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='x'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=10){
        //                     count++;
        //                     x++;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");

        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }
        //             }
        //             else if(c=='e'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     x--;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='q'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     x--;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         mvprintw(0,0,"                                  ");
        //                         usleep(2000000);
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");

        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");

        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='c'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     x++;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='z'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=10){
        //                     count++;
        //                     x++;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=15;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=15;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=15;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=15;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=15;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             asa--;
        //             refresh();
        //         }
        //         else{
        //             mvprintw(0,0,"you don't have enough weapons!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             refresh();
        //         }
        //     }
        //     else if(your_weapon==3){
        //         if(tir>=1){
        //             char c=getch();
        //             if(c=='d'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     y++;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='a'){
        //                 int count=0;
        //                 int target=0;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     y--;
        //                     if(map[adamak.x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[adamak.x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='w'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='x'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     if(map[x][adamak.y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][adamak.y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }
        //             }
        //             else if(c=='e'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             else if(c=='q'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x--;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='c'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     y++;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }


        //             }
        //             else if(c=='z'){
        //                 int count=0;
        //                 int target=0;
        //                 int x=adamak.x;
        //                 int y=adamak.y;
        //                 while(count!=5){
        //                     count++;
        //                     x++;
        //                     y--;
        //                     if(map[x][y]=='D'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.d-=12;
        //                         if(joon.d<=0){
        //                             mvprintw(0,0,"deamon was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='F'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         mvprintw(0,0,"                                  ");
        //                         usleep(2000000);
        //                         joon.f-=12;
        //                         if(joon.f<=0){
        //                             mvprintw(0,0,"fire breathing monster was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='U'){
        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.u-=12;
        //                         if(joon.u<=0){
        //                             mvprintw(0,0,"undeed was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='C'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         usleep(2000000);
        //                         mvprintw(0,0,"                                  ");
        //                         joon.g-=12;
        //                         if(joon.g<=0){
        //                             mvprintw(0,0,"giant was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"giant's health  %d ",joon.g);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                     else if(map[x][y]=='S'){

        //                         mvprintw(0,0,"hit the target!");
        //                         refresh();
        //                         mvprintw(0,0,"                                  ");
        //                         usleep(2000000);
        //                         joon.s-=12;
        //                         if(joon.s<=0){
        //                             mvprintw(0,0,"snake was destroyed");
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         else{
        //                             mvprintw(0,0,"snake's health  %d ",joon.s);
        //                             refresh();
        //                             usleep(2000000);
        //                             mvprintw(0,0,"                                  ");
        //                         }
        //                         target=1;
        //                         break;
        //                     }
        //                 }
        //                 if(target==0){
        //                     mvprintw(0,0,"it did not hit the target!");
        //                     refresh();
        //                     usleep(2000000);
        //                     mvprintw(0,0,"                                  ");
        //                 }

        //             }
        //             tir--;
        //             refresh();
        //         }
        //         else{
        //             mvprintw(0,0,"you don't have enough weapons!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             refresh();
        //         }

        //     }
        //     else if(your_weapon==4){
        //         if(map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x+1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'){
        //             joon.d-=10;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.d<=0){
        //                 mvprintw(0,0,"deamon was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.d=5;
        //             }
        //             else{
        //                 mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x+1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'){
        //             joon.f-=10;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.f<=0){
        //                 mvprintw(0,0,"fire breathing monster was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.f=10;
        //             }
        //             else{
        //                 mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x+1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'){
        //             joon.g-=10;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.g<=0){
        //                 mvprintw(0,0,"Giant was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.g=15;
        //             }
        //             else{
        //                 mvprintw(0,0,"Giant's health  %d ",joon.g);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x+1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'){
        //             joon.s-=10;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.s<=0){
        //                 mvprintw(0,0,"snake was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.s=20;
        //             }
        //             else{
        //                 mvprintw(0,0,"snake's health  %d ",joon.s);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x+1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'){
        //             joon.u-=10;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.u<=0){
        //                 mvprintw(0,0,"undeed was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.u=30;
        //             }
        //             else{
        //                 mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         refresh();
        //     }
        //     else{
        //         if(map[adamak.x][adamak.y]=='D'||map[adamak.x+1][adamak.y]=='D'||map[adamak.x-1][adamak.y]=='D'||map[adamak.x][adamak.y+1]=='D'||map[adamak.x][adamak.y-1]=='D'||map[adamak.x+1][adamak.y+1]=='D'||map[adamak.x-1][adamak.y-1]=='D'||map[adamak.x+1][adamak.y-1]=='D'||map[adamak.x-1][adamak.y+1]=='D'){
        //             joon.d-=5;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.d<=0){
        //                 mvprintw(0,0,"deamon was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.d=5;
        //             }
        //             else{
        //                 mvprintw(0,0,"deamon's health  %d ",joon.d);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='F'||map[adamak.x+1][adamak.y]=='F'||map[adamak.x-1][adamak.y]=='F'||map[adamak.x][adamak.y+1]=='F'||map[adamak.x][adamak.y-1]=='F'||map[adamak.x+1][adamak.y+1]=='F'||map[adamak.x-1][adamak.y-1]=='F'||map[adamak.x+1][adamak.y-1]=='F'||map[adamak.x-1][adamak.y+1]=='F'){
        //             joon.f-=5;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.f<=0){
        //                 mvprintw(0,0,"fire breathing monster was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.f=10;
        //             }
        //             else{
        //                 mvprintw(0,0,"fire breathing monster's health  %d ",joon.f);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='C'||map[adamak.x+1][adamak.y]=='C'||map[adamak.x-1][adamak.y]=='C'||map[adamak.x][adamak.y+1]=='C'||map[adamak.x][adamak.y-1]=='C'||map[adamak.x+1][adamak.y+1]=='C'||map[adamak.x-1][adamak.y-1]=='C'||map[adamak.x+1][adamak.y-1]=='C'||map[adamak.x-1][adamak.y+1]=='C'){
        //             joon.g-=5;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.g<=0){
        //                 mvprintw(0,0,"Giant was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.g=15;
        //             }
        //             else{
        //                 mvprintw(0,0,"Giant's health  %d ",joon.g);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='S'||map[adamak.x+1][adamak.y]=='S'||map[adamak.x-1][adamak.y]=='S'||map[adamak.x][adamak.y+1]=='S'||map[adamak.x][adamak.y-1]=='S'||map[adamak.x+1][adamak.y+1]=='S'||map[adamak.x-1][adamak.y-1]=='S'||map[adamak.x+1][adamak.y-1]=='S'||map[adamak.x-1][adamak.y+1]=='S'){
        //             joon.s-=5;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.s<=0){
        //                 mvprintw(0,0,"snake was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.s=20;
        //             }
        //             else{
        //                 mvprintw(0,0,"snake's health  %d ",joon.s);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         else if(map[adamak.x][adamak.y]=='U'||map[adamak.x+1][adamak.y]=='U'||map[adamak.x-1][adamak.y]=='U'||map[adamak.x][adamak.y+1]=='U'||map[adamak.x][adamak.y-1]=='U'||map[adamak.x+1][adamak.y+1]=='U'||map[adamak.x-1][adamak.y-1]=='U'||map[adamak.x+1][adamak.y-1]=='U'||map[adamak.x-1][adamak.y+1]=='U'){
        //             joon.u-=5;
        //             mvprintw(0,0,"hit the target!");
        //             refresh();
        //             usleep(2000000);
        //             mvprintw(0,0,"                                  ");
        //             if(joon.u<=0){
        //                 mvprintw(0,0,"undeed was destroyed");
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //                 joon.u=30;
        //             }
        //             else{
        //                 mvprintw(0,0,"undeed's health  %d ",joon.u);
        //                 refresh();
        //                 usleep(2000000);
        //                 mvprintw(0,0,"                                  ");
        //             }
        //         }
        //         refresh();
        //     }
        // }