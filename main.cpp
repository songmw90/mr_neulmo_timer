/*###############################################

늘모씨타이머 VER 10


이 프로그램은 늘모씨에 의한, 늘모씨에 의해 만들어졌습니다.

*수정사항

음악 *수정됨

YES/NO의 선택,좀더 디테일. * 끝만 바꾸면됨.

비프음의 완전 삭제 * 수정됨

유저에 의한 음악 선택  //나름 선택 ㅋㅋ

디테일 언제할꺼?

ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 병신새퀴

전함수화 / *수정됨
##################################################*/

#include "header.h"          //모든것을 가진 헤더


 FILE *fp;      //Exit 함수가 안처먹어줘서 전역변수로 수정.. 이 뭐병


void start();     //메인
void mainerror();    //메인 경고창
void option();     //옵션설정
void howto();     //설명
void InfiniteMode();   //무한모드
void Credit();     //크레딧
void Exit();     //꺼져모드
void NormalTimer();    //타이머
void TmbeepsMode();    //기간제(없음)
void StopwatchMode();   //스톱워치
void RealTimeMode();   //실제시간
void TimerSet();    //실제 타이머구간

void TimerSet(){
                //핵심적인 타이머 구간.
 sec = 1;  
setcursortype(NOCURSOR);
if(choice==-2 && choicehr == -2){
 sec = 0;
}
  system("cls");
  while(sec <61){


   if(choice >= 0 && choicehr >= 0){
  gotoxy(0,8);
  printf("입력된 시간 : %d시간 %d 분",choicehr,choice);     //타이머모드에서만 보인다.
   }
   else if(choice == -5 && choice == -5){        //-5가 입력되면...
   gotoxy(0,8);
 printf("목적된 시간 : %d시 %d분",targethr,targetmin);
   }
    
  if(choice == -2 && choicehr == -2){
   
    gotoxy(2,11);
    printf("                                                 ");
   }

  else if(choice == -5 && choicehr == -5){

 time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);
  
 if(t->tm_hour > 12){            //12를 넘길경우 오후,오전 등으로 표시.
  gotoxy(2,10);GREEN();
   printf("                                    오후 ");
WHITE(); }
 else{YELLOW();
  gotoxy(2,10);
  printf("                                   오전 ");
 WHITE();}
 hr= t->tm_hour;
 min = t->tm_min;
 sec= t->tm_sec;
  gotoxy(2,11);
  printf("                                    %02d시    \n",hr-12);
  gotoxy(2,12);
  printf("                                    %02d분    \n",min);
  gotoxy(2,13);
  printf("                                    %02d초    \n",t->tm_sec);
  
  }
  else {
  gotoxy(2,11);
WHITE();
  printf("                                %02d시간 경과\n",hr);
WHITE();
  }
  if(choice == -2 && choicehr == -2){
   
    gotoxy(2,11);
    printf("                                           ");
}


  if(choice == -2 && choicehr == -2){
PLUS();
  gotoxy(2,13);
  printf("                                 %02d초  경과 \n",sec);
WHITE();
  }
  else if(choice == -5 && choicehr == -5){

 time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);

  gotoxy(2,11);
  printf("                                    %02d시\n", t->tm_hour-minus);
  gotoxy(2,12);
  printf("                                    %02d분\n",t->tm_min);
  gotoxy(2,13);
  printf("                                    %02d초\n",t->tm_sec);


  }
  else{
     gotoxy(2,12);
YELLOW();
  printf("                                 %02d분 경과",min);
WHITE();
PLUS();
  gotoxy(2,13);
  printf("                                 %02d초  경과 \n",sec++);
WHITE();
  }

  if(choice == -2 && choicehr == -2){
   gotoxy(2,12);
   YELLOW();
  printf("                                 %02d분 경과",min);
GREEN();
 gotoxy(2,14);
 printf("                                 %02d초 경과\n",mssec++);
WHITE();
       
  gotoxy(0,23);
      printf("Main :↑Pause:↓Stop:←");
  }
  gotoxy(0,19);
  printf("버그등은 감사히 제보받습니다.");
  gotoxy(0,20);

  printf("늘모씨블로그 : ");
GREEN();
  printf("blog.naver.com/songmw90");
WHITE();
  gotoxy(0,23);
  printf("Main :↑Pause:↓");

 

 if(choice == -2 && choicehr == -2){
    delay(10);              //마이크로초가 1000이지만 여기서는 100이다. 따라서 딜레이를 10줌으로서 1000의 효과를 낼수있다.
}
 else
 Sleep(1000);              //일반적인 경우 그냥 1초.

   if(kbhit()){
   ch = getch();
   if(ch == 0XE0){
    ch=getch();
    switch(ch){
     case UP :
   sec = 0;
   min = 0;
   choicehr = 0;
   choice = 0;
   beep = 0;
   hr = 0;
   msec = 0;
   fmin=0,fsec=0,fmsec=0;
   omin=0,osec=0,omsec=0;
   opbeeps = 0;beepsfortime = 0;
   i = 0;
          //화면을 벗어난다면 모두 싹다 초기화시켜준다.
   start();

  case DOWN :               //멈추는 구간.
  system("cls");
  gotoxy(35,13);
YELLOW();
   printf("Pause!");
WHITE();
   getch();
      break;
  
  case LEFT :              //스톱워치에서만 작동하는 키. -2로 설정되어서 그렇다.
   if(choice ==-2 && choicehr ==-2){
  fmin = min;
  fsec = sec;
  fmsec = mssec;

  gotoxy(60,0);
YELLOW();
  printf("정지한 횟수 : %02d",i+1-5);
WHITE();
  gotoxy(50,1);
RED();
   printf("그이전값 : %02d분 %02d초 %02d초",omin,osec,omsec-1);
WHITE();
  gotoxy(50,2);
  omsec = fmsec; 
  omin = fmin;
  osec = fsec;
GREEN();
  printf("이전값 : %02d분 %02d초 %03d초",fmin,fsec,fmsec-1); 
WHITE();
   i++;
  getch();
   break;
   
   }
 }
  
   }
 
    }
 
  //Tmbeeps(beepsfortime);


if(choice == min && choicehr == hr){
 system("cls");
 gotoxy(0,0);
 printf("시간이 충족되었습니다.프로그램을 종료합니다.\n");  
 gotoxy(15,7);
 printf("입력하신 시간 %d시간 %d분의 카운트가 모두 끝났습니다.\n",choicehr,choice);
okbeeps();
 getch();

 

 gotoxy(15,9);
 printf("더 시간을 재길 원하시면 Y,아니라면 아무키나 누르세요");
 gotoxy(23,10);
 printf("선택 : ");
 fflush(stdin);
 scanf("%c",&choiceonemore);

 choice = 0;
 choicehr = 0;
 beep = 0;

 if(choiceonemore == 'Y'||choiceonemore=='y'){
  system("cls");
 start();
  getch();
 }


 else {break;}


 break;
 }

else if(targetmin == min && targethr+12 == hr){ 
 

 system("cls");
 gotoxy(0,0);
 printf("시간이 충족되었습니다.프로그램을 종료합니다.\n");  
 getch();
 

 gotoxy(15,9);
 printf("더 시간을 재길 원하시면 Y,아니라면 아무키나 누르세요");
 gotoxy(23,10);
 printf("선택 : ");
 fflush(stdin);
 scanf("%c",&choiceonemore);

 choice = 0;
 choicehr = 0;
 beep = 0;

 if(choiceonemore == 'Y'||choiceonemore=='y'){
  system("cls");
 start();
  getch();
 }


 else {break;}


 break;
}


if(choice >59){                  //이하 안내멘트.
GREEN();
 system("cls");
gotoxy(0,0);
 printf("59까지 입력할수 있습니다");
WHITE();
 start();}
if(choice >= 0){
GREEN();
 gotoxy(0,0);
 printf("타이머 모드입니다.\n");
WHITE();}
else if(choice == -1 || choicehr == -1){
GREEN();
gotoxy(0,0);
 printf("무한모드입니다\n");
WHITE();
}
else if(choice == -2 && choicehr == -2){
GREEN();
gotoxy(0,0);
printf("스톱워치 모드입니다\n");
WHITE();
}
else if(choice == -5 && choicehr == -5){
GREEN();
gotoxy(0,0);
printf("현재 시간을 표시중입니다.\n");
WHITE();

}
else{
GREEN();
gotoxy(0,0);
printf("입력값이 정확치 않습니다.");
WHITE();
start();}

 


 if(choice==-2 && choicehr == -2){             //모든 타이머가 아래처럼 간단한 구간으로 이루어지고 돌아간다.
 

  if(mssec == 100){  
  sec++;
  mssec = 0;
  }
  if(sec ==60){
  sec = 0;
  min++;
  }

 if(min == 60){
  min = 0;
  hr++;
 }

 

 } 
 


 else {
  
  if(sec ==60){
  sec = 0;
  min++;
  if(opchoice != 4){
  beepsfortime++;
  }
 }

 if(min == 60){
  min = 0;
  hr++;
 }

 }


if(choicehr == 0 && choice !=0){
continue;}
 }

 

getch();

}
int main(void){


    time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);
/*정확한 시간을 기록하기 위해 타이머 선언.. 위는 함수로 설정하지 않았다.*/

fp = fopen("DAT.txt","a");

fprintf(fp,"\n%d년 %d월 %d일 %d시 %d분 %d초에 프로그램이 시작되었습니다\n",t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);


 int i = 5;


start();

 


///*################################################################################################여기까지 완료*/

}

 

 

void start(){{
SETS();             //SETS함수는 모든 색을 관리한다
WHITE(); 
SetY = 6;

 


/*-----------------시작 음악 구간---------------------------------------------*/

startsong();

 

/*-----------------시작 음악 구간 -------------------------------------------------*/

setcursortype(NOCURSOR);     //start구간으로 지정. 일반커서타입을 설정.

WHITE();


gotoxy(0,0);
system("cls");
printf("Blog.naver.com/songmw90");
gotoxy(3,6);
printf("┌메뉴설명────────┐");
gotoxy(3,7);
printf("│                        │");
gotoxy(3,8);
printf("│                        │");
gotoxy(3,9);
printf("│                        │");
gotoxy(3,10);
printf("│                        │");
gotoxy(3,11);
printf("│                        │");
gotoxy(3,12);
printf("└────────────┘");
gotoxy(28,3);
GREEN();            //초록색 글자표시 이하 색()들은 주석 생략
printf("늘 모 씨 타 이 머 V E R _ 0 9");

/* 초기 제목 구간 신경쓸것 없다.*/
gotoxy(36,6);
YELLOW();
printf("▶");
PLUS();
printf("  1.Start Timer");
gotoxy(40,9);
GREEN();
printf("2.Option");
gotoxy(40,12);
RED();
printf("3.Credit");
gotoxy(40,15);
WHITE();
printf("4.Exit");


while(1){

   if(kbhit()){
   ch=getch();
   if(ch == 0XE0){
    ch=getch();
    switch(ch){
     case UP :
   YELLOW();
   Temp = SetY;  
   if(SetY > 10){
 
    SetY = min(SetY-3,Temp);
   }
   else{
   SetY = min(SetY+3,6);
   }
   gotoxy(SetX,SetY);
   printf("▶");
  
   gotoxy(SetX,Temp);
   printf("  ");

      if(SetY == 6){
 
    gotoxy(SetX,6);
    printf("▶"); 
 gotoxy(5,7);
 printf("타이머를 시작합니다");
 gotoxy(5,8);
 printf("                        ");
 gotoxy(5,9);
 printf("                        ");

   }
   else if(SetY == 9){
    gotoxy(5,7);printf("                     ");
    gotoxy(5,7);printf("옵션을 설정합니다");
    gotoxy(5,8);printf("                     ");
    gotoxy(5,8);printf("이 메뉴에서는 타이머를");
    gotoxy(5,9);printf("상세하게 설정합니다");
   }
   else if(SetY == 12){
 gotoxy(5,7);
 printf("만든이를 소개합니다.");
 gotoxy(5,8);
 printf("                        ");
 gotoxy(5,9);
 printf("                        ");
   
   }
   else if(SetY == 15){
 gotoxy(5,7);
 printf("종료합니다               ");
 gotoxy(5,8);
 printf("                        ");
 gotoxy(5,9);
 printf("                        ");
   
   
   }

   break;

  case DOWN :   
   YELLOW();
   Temp = SetY;
   SetY = min(SetY+3,15);
   gotoxy(SetX,SetY);
   printf("▶");
   gotoxy(SetX,Temp);
   printf("  ");

   if(SetY == 9){
    gotoxy(5,7);printf("                     ");
    gotoxy(5,7);printf("옵션을 설정합니다");
    gotoxy(5,8);printf("                     ");
    gotoxy(5,8);printf("이 메뉴에서는 타이머를");
    gotoxy(5,9);printf("상세하게 설정합니다");
   }
 else if(SetY == 12){
 gotoxy(5,7);
 printf("만든이를 소개합니다.");
 gotoxy(5,8);
 printf("                        ");
 gotoxy(5,9);
 printf("                        ");
   }
   else if(SetY == 15){
 
    gotoxy(SetX,15);
    printf("▶");
 gotoxy(5,7);
 printf("종료합니다              ");
 gotoxy(5,8);
 printf("                        ");
 gotoxy(5,9);
 printf("                        ");
   }
   break;

   }
 }

   if(IsKeyDown(VK_RETURN)){

  if(SetY == 6){

   if(choice == 0 && choicehr == 0){        //선택 결과가 아무것도 없을경우 출력. 가령 무한모드는 -1로 설정되어있다.
   mainerror();
   }

   else{
     /*if(timerh > 0){*/                //선택이 제대로 되었다면 timer로 이동한다.
 STOP();
menubeep();

  system("cls");
WHITE();
 gotoxy(25,13);
 printf("타이머로 이동합니다");
 GREEN();
 gotoxy(30,14);
 printf("Press Enter!");
 WHITE();
 getch();
 
STOP();
 TimerSet();
   }
 
  }
  

  
  else if(SetY == 9){ 
   option();
  }
  else if(SetY == 12){ 
   Credit();
  }
  else if(SetY == 15){ 
   Exit();
  }
 }
   }

}

}


}
void mainerror(){{

  setcursortype(NOCURSOR);
  system("cls");
 
WHITE();
STOP();
errorbeeps();

  gotoxy(25,10);
  printf("아무것도 선택되지 않았습니다");
  gotoxy(25,11);

  printf("메인화면의 ");
GREEN();
  printf("Option");
WHITE();
  printf("을 확인해주세요");
  getch();
  system("cls");
   setcursortype(NOCURSOR);
   //main = 0;

STOP();
  start();
 


}

}

void option(){

            //실질적인 타이머의 기능을 모두 표시하고 있는 구간
 {
 STOP();
menubeep();

 system("cls"); /*main = 0;*/
 fflush(stdin);
 gotoxy(0,0);
 GREEN();
 printf("옵션입니다");
 gotoxy(0,3);
 printf("아래 지시사항에서, 선택해주세요.");
 YELLOW();
 gotoxy(12,8);
 printf("▶");
 WHITE();
 gotoxy(15,8);
 printf("§ 각 타이머에 대한 설명"); 
 gotoxy(15,10);
 printf("§ 무한모드");
 gotoxy(15,12);
 printf("§ 타이머모드");
 RED();
 gotoxy(15,14);
 printf("§ 기간알림모드");
 WHITE();
 gotoxy(15,16);
 printf("§ 스톱 워치모드");
 gotoxy(15,18);
 printf("§ 실제시간 타이머모드");
 gotoxy(15,20);
 printf("§ 메인으로");

 while(1){
   if(kbhit()){
   ch=getch();
   if(ch == 0XE0){
    ch=getch();
    switch(ch){
     case UP :
   YELLOW();
   OpTemp = OpSetY;  
   if(OpSetY > 8){
 
    OpSetY = min(OpSetY-2,OpTemp);
   }
   else{   
   OpSetY = min(OpSetY+2,8);
   }
   gotoxy(OpSetX,OpSetY);
   printf("▶");
   
   gotoxy(OpSetX,OpTemp);
   printf("  ");

      if(OpSetY == 8){
 
    gotoxy(OpSetX,8);
    printf("▶");
   }
   break;

  case DOWN :      
   YELLOW();
   OpTemp = OpSetY;
   OpSetY = min(OpSetY+2,20);
   gotoxy(OpSetX,OpSetY);
   printf("▶");
   gotoxy(OpSetX,OpTemp);
   printf("  ");

   if(OpSetY == 20){
 
    gotoxy(OpSetX,20);
    printf("▶");
   }
   break;

   }

 }

if(IsKeyDown(VK_RETURN)){

  if(OpSetY == 8){
   howto();
  }
  else if(OpSetY == 10){ 
   InfiniteMode();
  }
  else if(OpSetY == 12){ 
   NormalTimer();
  }
  else if(OpSetY == 14){ 
   TmbeepsMode();
  }
  else if(OpSetY == 16){ 
   StopwatchMode();
  }
  else if(OpSetY == 18){ 
   RealTimeMode();
  }
  else if(OpSetY == 20){ 
              
   opchoice = 0;   OpSetY = 8; timerh = 7;//메인으로
  system("cls");
STOP();
menubeep();
  start();


  }

 }

}
 }
 }

 }

 

void howto(){
           //설명 구간
 setcursortype(NOCURSOR);          //커서 없앰
  system("cls");
  gotoxy(13,11);
STOP();
menubeep();
GREEN();
  printf("무한모드");
WHITE();
  printf("는 말그대로, 시간을 무한대로 재는것입니다.");
  gotoxy(13,12);
  printf("자신이 얼마나 컴퓨터를 사용하고 있는지 알아볼때 편리합니다.");
  getch();
  system("cls");
  gotoxy(13,11);
GREEN();
  printf("타이머모드");
WHITE();
  printf("는, 자신이 시간을 입력하고, 그 시간만큼이 충족되면");
  gotoxy(13,12);
  printf("알려주는 모드입니다");
  getch();
  //system("cls");
  //gotoxy(13,11);
//GREEN();
//  printf("기간알림모드");
//WHITE();
//  printf("는 실질적 무한모드로서 알려줄 시간을 입력을받습니다");
//  gotoxy(13,12);
//  printf("가령5분을입력하면, 5분마다 비프음을 울리게 됩니다");
  //getch();
  gotoxy(10,11);
GREEN();
  printf("스톱워치모드");
WHITE();
  printf("는 ←를 누르시면 시간이 멈추게 됩니다");
  gotoxy(10,12);
  printf("그경우 이전값에 시간이 저장되고 최대 2회까지 시간이 저장되게 됩니다.");
  getch();
  system("cls");
  GREEN();
  gotoxy(3,11);
  printf("실제시간 타이머모드");
WHITE();
printf("는 실제시간을 표시해주고, 타겟된 시간에 알리는 모드입니다.");
getch();
  system("cls");
   setcursortype(NOCURSOR);
   opchoice = 0;
   OpSetY = 8;

  option();
 
}

void InfiniteMode(){
STOP();
menubeep();
  choice = -1;
  choicehr = -1;
  system("cls");
  gotoxy(25,13);
  GREEN();
  printf("타이머를 실행하시면 무한모드가 가동됩니다");
  getch();
  WHITE();
  opchoice = 0;   OpSetY = 8;  timerh = 2;
  start();
}

 

void Credit(){

        
 STOP();    //CREDIT부분
menubeep();
   setcursortype(NOCURSOR);
GREEN();
 system("cls");
 gotoxy(25,12);
 printf("This Program Developed by 늘모씨");
 getch();
 gotoxy(23,12);
RED();
 printf("Special Thanks to Ryuz,Gang,Keita,울산댁");
 getch();
 WHITE();
 system("cls");
 gotoxy(4,2);
 printf("늘모씨타이머 VER 01 : 중심변수의 구축. 타이머의 뼈대작성");
 gotoxy(4,4);
 printf("늘모씨타이머 VER 02 : 비프음을 대폭증가. 3분시에 라면멘트");
 gotoxy(4,6);
 printf("늘모씨타이머 VER 03 : 문자열에대한 호환. 시간입력 가능");
 gotoxy(4,8);
 printf("늘모씨타이머 VER 04 : 3버전의 버그를 수정");
 gotoxy(4,10);
 printf("늘모씨타이머 VER 04+ : 문자열 재배열. 60을 넣어도 돌아가던 버그의 수정");
 gotoxy(4,12);
 printf("늘모씨타이머 VER 05 : gotoxy함수사용. 화면 반짝임을 없앰.");
 gotoxy(4,14);
 printf("늘모씨타이머 VER 06 : 메뉴도입.모드추가도입. 비프음의 숫자 설정가능");
 gotoxy(4,16);
 printf("늘모씨타이머 VER 07 : 스톱워치도입.키 입력으로 메인으로 돌아갈수있게함.");
 gotoxy(4,18);
 printf("늘모씨타이머 VER 08 : 소스간결화. 실제시간 모드 도입");
 gotoxy(4,20);
 printf("늘모씨타이머 VER 09 : 방향키의 조작. 오전 버그 수정");
 gotoxy(4,22);
 printf("늘모씨타이머 VER 10 : 음향효과 설정 디테일");
 getch();
 system("cls");
 gotoxy(4,2);
 printf("만든이 : 늘모씨(17)");
 gotoxy(4,4);
 printf("소속 : 울산애니원고등학교");
 gotoxy(4,6);
 printf("건의사항이나 버그는"); 
GREEN();
 gotoxy(4,8);
 printf("Blog.naver.com/songmw90");
 WHITE();
 gotoxy(4,10);
 printf("에서 해주세요!");
 GREEN();
 gotoxy(60,23);
 printf("Press Enter To Main");
 WHITE();
 getch();

 start();

}

void Exit(){

 gotoxy(40,16); //종료멘트 출력
 printf("좋은하루되세요");
     time_t timer;
    struct tm *t;
    timer = time(NULL);
    t = localtime(&timer);
 STOP();
 fprintf(fp,"\n%d년 %d월 %d일 %d시 %d분 %d초에 프로그램이 종료되었습니다\n",t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
Existbeep();
i = 0;
  while(1){
 Sleep(1000);
  if(i == 1){
  break;
  }
 
 i++;
 }
STOP();
 exit(1);
}

void NormalTimer(){
STOP(); SetY = 9;

menubeep();
      opchoice = 0;   OpSetY = 8; timerh = 3;
 system("cls");
 GREEN();
 gotoxy(0,5);
    printf("몇시간 재시길 원하십니까? : ");

  while(1){WHITE();
   fflush(stdin);
   if(!(scanf("%d",&choicehr))){          //이것으로 숫자이외의 값도 튕기지 않고 받아쳐낼수 있다.
    printf("다시 입력하세요! : ");
 GREEN();
    continue;
   }
   else break;
  }


   if(choicehr == -1){

   system("cls");
   start();
  }  GREEN();
   gotoxy(0,7);
  printf("몇 분재길 원하십니까? : ");
  while(1){WHITE();
   fflush(stdin);
   if(!(scanf("%d",&choice))){
    printf("다시입력하세요! : ");
  GREEN();
    continue;
   }
   else break;
  }

    if(choice == -1){

   system("cls");
   start();
  }
  while(1){

 


 
   system("cls");
   WHITE();
   gotoxy(13,5);
   printf("님이 입력한 시간은 : ");
   gotoxy(15,6);
   printf("%02d시간 %02d분",choicehr,choice);

   gotoxy(15,7);
   printf("맞으면 YES, 틀리면 NO");
   YELLOW();
   gotoxy(13,9);
   printf("▶");
   WHITE();
   gotoxy(16,9);
   printf("YES");
   gotoxy(16,11);
   printf("NO");
GREEN();
   gotoxy(13,10);
 fflush(stdin);
WHITE();

while(1){{
   if(kbhit()){
   ch=getch();
   if(ch == 0XE0){
    ch=getch();
    switch(ch){
     case UP :
   YELLOW();
   Temp = SetY;  
   if(SetY > 12){
 
    SetY = min(SetY-3,Temp);
   }
   else{
   SetY = min(SetY+3,9);
   }
   gotoxy(TmSetX,SetY);
   printf("▶");
  
   gotoxy(TmSetX,Temp);
   printf("  ");

      if(SetY == 9){
 
    gotoxy(TmSetX,9);
    printf("▶");

   }

   break;

  case DOWN :   
   YELLOW();
   Temp = SetY;
   SetY = min(SetY+3,11);
   gotoxy(TmSetX,SetY);
   printf("▶");
   gotoxy(TmSetX,Temp);
   printf("  ");

  if(SetY == 11){
 gotoxy(13,9);
 printf("   ");
    gotoxy(TmSetX,11);
    printf("▶");

   }
   break;

   }
 }

if(IsKeyDown(VK_RETURN)){

  if(SetY == 9){
 start();
  }
  else if(SetY == 11){ 
   system("cls");
   NormalTimer();
  }
 }

}

}

  }
  }
}

void TmbeepsMode(){
 
           //기간제비프음
system("cls");
 STOP();
 gotoxy(30,13);
 printf("이 모드는 현재 지원하지 않는 모드입니다.");
 gotoxy(30,14);
 printf("후에 다시 개발 할 예정입니다.");
 getch();
 opchoice = 0; OpSetY = 8;timerh = 0;
   option();
 
}


void StopwatchMode(){

           //스톱워치 (설정 -2)
STOP();
menubeep();
  choicehr = -2;
  choice = -2;

  system("cls");
  GREEN();
  gotoxy(25,13);
  printf("타이머를 시작하시면 스톱워치 모드를 실행합니다");
  getch();
  WHITE();
     opchoice = 0;   OpSetY = 8;timerh = 5;
  start();

 

}


void RealTimeMode(){{

 
             //현재시간을 5번을 누를때 마다 재설정시킨다.
STOP();
menubeep();
  
  opchoice = 0;   OpSetY = 8;timerh = 6;
  time_t timer;
    struct tm *t;

    timer = time(NULL);
    t = localtime(&timer);

system("cls");

gotoxy(22,11);
GREEN();
printf("현재시각은");
WHITE();
   gotoxy(33,11);
 if(t->tm_hour > 12){//12를 넘길경우 오후,오전 등으로 표시.
  minus = 12;
  YELLOW();printf("오후 ");WHITE();
  printf("%02d시%02d분\n",t->tm_hour-minus, t->tm_min);
 }
 else if(t->tm_hour < 12){
  minus = 0;
  YELLOW();printf("오전 ");WHITE();
  printf("%02d시%02d분\n",t->tm_hour-minus, t->tm_min);
 }
 RED();
  gotoxy(0,0);
  printf("이 시간은 절대적으로 컴퓨터의 시간에 의해 표시되고 있습니다");
  WHITE();
  gotoxy(20,12);
  printf("몇시 몇분에 알려드리길 원하십니까?(입력예시 : 7 49)");
  GREEN();
  gotoxy(20,13);
  printf("입력 : ");
  WHITE();
  scanf("%d %d",&targethr,&targetmin);
  gotoxy(20,14);
  system("cls");
 choice = -5;
 choicehr = -5;
  start();

 }

}
