#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

void time_pass(time_t start);
void display_time(long nhour, long nmin, long nsecond);
void control_watch(void);

int main(void)
{
	display_time(0, 0, 0);
	getch();
	control_watch();
	printf("press any key to continue.......");
	getch();
	
	return 0;
}

//키를 입력 받아 stopwatch를 제어 
void control_watch(void)
{
   char key;
   time_t start;
   start=time(NULL);
   time_pass(start);
   do
   {
	key=getch();
	switch(key)
	{
	   case 10 : //시작 또는 정지 enter키 
		time_pass(start);
	   case 32 : //시작 시간을 0으로 초기화 하여 재시작 space bar 
		start=time(NULL);
		time_pass(start);
		break;
	   case 27 : //프로그램 종료 esc키 
		exit(0);
		break;
	}
   }while(key!=27);

}

//시작시간과 현재 시간사이의 차를 시분초로 계산하는 함수 
void time_pass(time_t start)
{
	double hour, min, second;
	long nhour, nmin, nsecond;
	time_t now;
	while(!kbhit())
	{
		now=time(NULL);
		second=difftime(now, start); //초단위 시간의 차이를 구하는 함수 
		hour= (second/3600.);
		nhour= (long) hour;
		min= fmod(second, 3600.)/60; //실수끼리 나누었을 때 나머지가 double형 실수일 때 사용 
		nmin= (long) min;
		second= fmod(second, 60);
		nsecond= (long) second;
		display_time(nhour, nmin, nsecond);
 	}
}

//화면에 시간을 출력하는 함수 
void display_time(long nhour, long nmin, long nsecond)
{
	system("cls");
	printf("stopwatch\n\n");
	printf("%.2ld시 %.2ld분 %.2ld초 \n\n", nhour, nmin, nsecond);
	printf("Enter:(시작/정지), SPACE:재시작, Esc:종료\n");

}
