/*##########################################################################################################################

편집 by 늘모씨

This Engein Developed by 늘모씨.

닥치고 개조도 늘모씨

전무 늘모씨.

사실 여러 소스 합쳤다고 말못해


ver2

#############################################################################################################################*/

 

 /*############################################# 절대값 #################################################*/

#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)   //RGB색을 섞어 만든 흰색
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)       //RGB색을 섞어 만든 노랑색
#define FOREGROUND_PLUS (FOREGROUND_BLUE | FOREGROUND_GREEN)       //RGB색을 섞어 만든 청록색
#define ENT 13                  //'ENTER'의 아스키코드값
#define MAX 1024
#define LEFT 75                   //왼쪽방향표의 아스키코드값
#define RIGHT 77                  //오른쪽방향표의 아스키코드값
#define UP 72                   //위쪽방향표의 아스키코드값
#define DOWN 80                   //아래방향표의 아스키코드값
#define ESC 27                   //'ESC'의 아스키코드값
#define SPACE 32                  //'SPACE'의 아스키코드값


/*############################################# 타이머에 쓰여진 변수 #################################################*/

 char *mname[] = {"","Start.wma","Error.wma","Set.wma","End.wma","User.wma","Tmbeepss.wma"};
 int sec = 1;                   //초기 초 초기화
 int min = 0;                   //초기 분 초기화
 int hr = 0;                   //초기 시간 초기화
 int msec = 0;                   //STOPWATCH에 사용된 마이크로초 초기화
 int choice = 0;                  //타이머 값(분) 
 int choicehr = 0;                  //타이머 값(시간)
 char choiceonemore;                 //타이머 재시작 혹은 종료를 묻는 변수
 int beep=0;                   //비프음 초기화
 char choiceoption;                  //옵션선택
 int opbeeps=0;                   //비프음
 int ch;
 int mssec = 1;
 int i=0;
 int fmin,fsec,fmsec;                 //스톱워치 변수들
 int omin=0,osec=0,omsec=0;                //스톱워치 변수들
 int beepsfortime = 0;                 //기간마다 비프음을 울리게 하는 변수설정
 int realhr=0,realmin=0;                //실제시간 표시
 int targethr = 0,targetmin = 0;
 char pmoram;
 int timerh = 0; 
 int minus = 0; 
 int opchoice = 0;
 /*방향 전환에 힘써준 좌표님들(..)*/
 int SetY = 6;
 int SetX = 36;
 int Temp = 0;
 int OpSetY = 8;
 int OpSetX = 12;
 int OpTemp = 0;
 int TmSetX = 13;
 char szCommand[256], szReturnStr[256];   //음악

 /*############################################# 타이머에 쓰여진 변수 끝 #################################################*/
#ifndef TURBOC_HEADER
#define TURBOC_HEADER
/*############################################# 헤더설정 #################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>                 //getch
#include <time.h>                 //time함수를 쓴다.
#include <windows.h>                //gotoxy등 API함수를 끌어온다.
#include <dos.h>
#include <math.h>
#include <ctype.h>
#include <mmsystem.h>
 /*############################################# 헤더 끝 #################################################*/

 /*############################################# 함수정의 #################################################*/
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void beeps();

void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);
void STOP();
bool IsKeyDown(int Key){      // 키 입력 받는 함수

 return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}
 /*############################################# 함수정의 끝#################################################*/

#define delay(n) Sleep(n)        //n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))   // 난수 발생기 초기화
#define random(n) (rand() % (n))      // 0~n까지의 난수 발생

// 이 매크로가 정의되어 있으면 함수의 원형만 선언하고 정의는 하지 않는다.
#ifndef TURBOC_PROTOTYPE_ONLY

// 화면을 모두 지운다.
void clrscr()  //=system("cls");
{
 system("cls");
}

void STOP(){
mciSendString("stop mydev", szReturnStr, sizeof(szReturnStr), NULL);
mciSendString("close mydev", szReturnStr, sizeof(szReturnStr), NULL);
}
/*############################################# gotoxy함수 #################################################*/
void gotoxy(int x, int y){

 COORD Cur;
 Cur.X=x;
 Cur.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

/*############################################# gotoxy함수 끝###############################################*/

// 커서의 x좌표를 조사한다.
int wherex()
{
 CONSOLE_SCREEN_BUFFER_INFO Buflnfo;

 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&Buflnfo);
 return Buflnfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.
int wherey()
{
 CONSOLE_SCREEN_BUFFER_INFO Buflnfo;

 GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&Buflnfo);
 return Buflnfo.dwCursorPosition.Y;
}

/*############################################# 커서타입 설정 #################################################*/
void setcursortype(CURSOR_TYPE c){
 CONSOLE_CURSOR_INFO CurInfo;

 switch(c){

  case NOCURSOR :            //커서타입이 이것으로 설정되면 화면에서 커서를 없앤다.
   CurInfo.dwSize=1;
   CurInfo.bVisible=FALSE;
   break;
  case SOLIDCURSOR :
   CurInfo.dwSize=100;
   CurInfo.bVisible=TRUE;
   break;
  case NORMALCURSOR :           //일반적인 커서타입
   CurInfo.dwSize=20;
   CurInfo.bVisible=TRUE;
   break;
 }
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}
/*############################################# 커서타입 설정 끝 ###############################################*/

/*############################################# beep음을 관리하는 함수 #################################################*/
void beeps(){

 

    wsprintf(szCommand, "open %s alias mydev", mname[5]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);

}

/*############################################# beep음을 관리하는 함수 끝###############################################*/

/*#############################################음악 설정 구간 #################################################*/

void startsong();

void startsong(){
  wsprintf(szCommand, "open %s alias mydev", mname[1]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);  
}

void errorbeeps();

void errorbeeps(){
  wsprintf(szCommand, "open %s alias mydev", mname[2]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);  
}
void menubeep();

void menubeep(){
  wsprintf(szCommand, "open %s alias mydev", mname[3]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);  
}
void Existbeep();

void Existbeep(){
  wsprintf(szCommand, "open %s alias mydev", mname[4]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);  
}
void okbeeps();

void okbeeps(){
  wsprintf(szCommand, "open %s alias mydev", mname[5]);
  mciSendString(szCommand, szReturnStr, sizeof(szReturnStr), NULL);
  mciSendString("play mydev from 0", szReturnStr, sizeof(szReturnStr), NULL);  
}


/*#############################################음악 설정 구간 #################################################*/

 

/*#############################################색 설정 구간 #################################################*/

void WHITE(void);    /* 흰색을 표시하는 함수 */
void WHITE(void){

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  
      FOREGROUND_WHITE | FOREGROUND_INTENSITY);
}

void GREEN(void);    /*초록색을 표시하는 함수*/
void GREEN(void){

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  
      FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void RED(void);     /*빨강색을 표시하는 함수*/
void RED(void){

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  
      FOREGROUND_RED | FOREGROUND_INTENSITY);

}

void PLUS(void);    /*청록색을 표시하는 함수*/
void PLUS(void){

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  
      FOREGROUND_PLUS | FOREGROUND_INTENSITY);

}

void YELLOW(void);
void YELLOW(void){

 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  
      FOREGROUND_YELLOW | FOREGROUND_INTENSITY);
}


void SETS();
void SETS(){
  WORD old_attrb;

   CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );
   old_attrb = csbi.wAttributes;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),csbi.wAttributes);
}
/*#############################################색 설정 구간 끝 ##############################################*/


#endif // TURBOC_PROTOTYPE_ONLY
#endif // TURBOC_HEADER

 
