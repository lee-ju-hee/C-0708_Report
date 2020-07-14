#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);//화살표 키에 따라 좌표 x,y 변경 
void gotoxy(int x, int y);   //커서의 위치 제어 
void draw_check01(int c, int r); //격자모양의 바둑판 표시 
void game_control(void); //바둑판을 표시하고 하나의 돌을 화살표 키로 움직임에 대한 제어 

int main(void)
{
	game_control();//바둑판을 표시하고 하나의 돌을 화살표 키로 움직임에 대한 제어하는 함수 실행 
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r)
{
    int i, j;
    unsigned char a=0xa6;//기호 └의 10진수 코드를 a에 입력 
    unsigned char b[12]; //배열의 크기가 12인 b선언 
    for(i=1;i<12;i++)
		b[i]=0xa0+i;  //0xa1부터 0xa11까지의 값을 순서대로 저장 
		
    printf("%c%c",a, b[3]); //기호 출력 
    for(i=0;i<c-1;i++)
	 	printf("%c%c", a, b[8]);//기호 출력   
    printf("%c%c", a, b[4]);//기호 출력 
    printf("\n");
    for(i=0;i<r-1;i++)
    {
		printf("%c%c", a, b[7]);//기호 출력 
		for(j=0;j<c-1;j++)
	    	printf("%c%c", a, b[11]);//기호 출력 
		printf("%c%c",a, b[9]);//기호 출력 
		printf("\n");
    }
    printf("%c%c", a, b[6]);//기호 출력 
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[10]);//기호 출력 
    printf("%c%c", a, b[5]);//기호 출력 
    printf("\n");
}

void game_control(void)
{
    int x=1, y=1;
    char key;
    do
    {
	gotoxy(1,1);       //커서의 위치를 제어하는 함수에 매개변수 값을 전달 
	draw_check01(18, 18);  //격자모양의 바둑판 표시하는 함수에 매개변수값을 전달 
	gotoxy(x, y);     //커서의 위치 제어 
	printf("○");     //기호 출력 
	gotoxy(1, 21);    //커서의 위치 제어 
	printf("방향키를 누르시오.");
	key=getch();   //사용자가 입력한 키의 아스키코드값을 key에 전달 
	if (key==27)
		exit(0); //강제종료 
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19); //수정부분
   }while(1); //무한반복 
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)//화살표 키에 따라 좌표 x, y변경하는 함수의 매개변수  
{
	switch(key) //매개 변수 key의 값을 대입 
	{  //switch문의 시작 
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;        //위쪽방향으로 1씩 감소 
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;         // 끝 
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;             //좌측방향으로 2씩 감소
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;          // 끝 
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;         // 끝 
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;            //아래 방향으로 1씩 증가 
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;         // 끝 
	default:   // break로 switch문이 끝남 
		return;//
	}
}

