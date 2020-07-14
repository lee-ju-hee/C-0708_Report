#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void control_scoreboard(int st,int end,int r[],int h[],int e[], int b[]);
void display_scoreboard(int r[], int h[], int e[], int b[]);
void draw_check02(int c, int r);
void gotoxy(int x, int y);

int main(void)
{
	//baseball은 두팀의 회차별 점수를 저장
	//2차원 배열의 첫 번째 첨자는 회차를 구분
	//두번째 첨자는 공격순서(0은 원정팀, 1은 홈팀)를 구분
	//회차는 9회가 끝나고 연장전의 점수를 저장하기 위해 크기를 12 
	int  baseball[12][2]={0};
	int r[2]={0}; //득점수 저장 / [0]은 원정팀 점수, [1]은 홈팀 점수합 
	int h[2]={0}; //각각 팀의 안타숫자 
	int e[2]={0}; //각각 팀의 실책숫자 
	int b[2]={0}; //각각 팀의 포볼숫자 
	display_scoreboard(r, h, e, b);	 //스코어보드 제어(1회 ~ 9회) 
	control_scoreboard(1, 9, r, h, e, b);//스코어보드 제어(연장전) 
	control_scoreboard(10, 12, r, h, e, b);//스코어보드 제어(무승부) 
	gotoxy(1, 15);//커서 위치 제어 
	printf("무승부입니다. 아무키나 누르시오\n");
	getch();
	return 0;
}

 //격자모양을 출력 
void draw_check02(int c, int r)
{
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[12]; 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;
    printf("%c%c",a, b[3]);
    for(i=0;i<c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[8]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r-1;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<c;j++)
	{
		printf("  ");
		printf("%c%c",a, b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[7]);
	for(j=0;j<c-1;j++)
	{
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[11]);
	}
	printf("%c%c",a, b[1]);
	printf("%c%c",a, b[9]);
	printf("\n");
    }
    printf("%c%c", a, b[2]);
    for(j=0;j<c;j++)
    {
	printf("  ");
	printf("%c%c",a, b[2]);
    }
    printf("\n");
    printf("%c%c", a, b[6]);
    for(i=0;i<c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[10]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}

//득점판 출력 
void display_scoreboard(int r[], int h[], int e[], int b[])
{
	int i, j;
	printf("스코어보드 \n");
	draw_check02(17, 3);
	for(i=1;i<=12;i++)
	{
		gotoxy(i*4+3, 3);
		printf("%2d", i);
	}
	gotoxy(13*4+4, 3);
	printf("R");
	gotoxy(14*4+4, 3);
	printf("H");
	gotoxy(15*4+4, 3);
	printf("E");
	gotoxy(16*4+4, 3);
	printf("B");
	gotoxy(3, 5);
	printf("CL");
	gotoxy(3, 7);
	printf("TG");
	for(j=0;j<=1;j++)
	{
		gotoxy(13*4+3, 5+2*j);
		printf("%2d", r[j]);
		gotoxy(14*4+3, 5+2*j);
		printf("%2d", h[j]);
		gotoxy(15*4+3, 5+2*j);
		printf("%2d", e[j]);
		gotoxy(16*4+3, 5+2*j);
		printf("%2d", b[j]);
	}
}

//각 회차별 정보를 득점판에 출력 
void control_scoreboard(int st,int end, int r[], int h[], int e[], int b[])
{
   int i, j, k, rr, hh, ee, bb;
   char state[3];
   for(i=st;i<=end;i++)
   {
 	for(j=0;j<=1;j++)
	{
		if (j==0)
			strcpy(state, "초");
		else
			strcpy(state, "말");
		gotoxy(i*4+3, 5+2*j);
		printf("%2d", 0);
		gotoxy(1, 10);
		printf("%d회%s 결과 ", i, state);
		gotoxy(1, 11);

		printf("안타수 입력 : ");
		scanf("%d", &hh);
		h[j]+=hh;
		gotoxy(14*4+3, 5+2*j);
		printf("%2d", h[j]);
		gotoxy(1, 12);

		printf("실책수 입력 : ");
		scanf("%d", &ee);
		e[j]+=ee;
		gotoxy(15*4+3, 5+2*(1-j));
		printf("%2d", e[j]);

		gotoxy(1, 13);
		printf("포볼수 입력 : ");
		scanf("%d", &bb);
		b[j]+=bb;
		gotoxy(16*4+3, 5+2*j);
		printf("%2d", b[j]);
		gotoxy(1, 14);
		printf("점수   입력 : ");
		scanf("%d", &rr);
		r[j]+=rr;
		gotoxy(13*4+3, 5+2*j);
		printf("%2d", r[j]);

		gotoxy(i*4+3, 5+2*j);
		printf("%2d", rr);

		gotoxy(1, 15);
		printf("아무키나 누르시오....");
		getch();
		for(k=10; k<=15; k++)
		{
			gotoxy(1, k);
		    	printf("                       ");
		}
		//경기가 종료되는 상황을 조건문으로 제어하는 부분 
		if (9<=i&&((j==0&& r[0]<r[1]) || (j==1 && r[0]!=r[1])))
		{
			gotoxy(1, 15);
			printf("경기가 끝났습니다. 아무키나 누르시오\n");
			getch();
			exit(0);
		}
	}
   }
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
