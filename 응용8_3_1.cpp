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

//Ű�� �Է� �޾� stopwatch�� ���� 
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
	   case 10 : //���� �Ǵ� ���� enterŰ 
		time_pass(start);
	   case 32 : //���� �ð��� 0���� �ʱ�ȭ �Ͽ� ����� space bar 
		start=time(NULL);
		time_pass(start);
		break;
	   case 27 : //���α׷� ���� escŰ 
		exit(0);
		break;
	}
   }while(key!=27);

}

//���۽ð��� ���� �ð������� ���� �ú��ʷ� ����ϴ� �Լ� 
void time_pass(time_t start)
{
	double hour, min, second;
	long nhour, nmin, nsecond;
	time_t now;
	while(!kbhit())
	{
		now=time(NULL);
		second=difftime(now, start); //�ʴ��� �ð��� ���̸� ���ϴ� �Լ� 
		hour= (second/3600.);
		nhour= (long) hour;
		min= fmod(second, 3600.)/60; //�Ǽ����� �������� �� �������� double�� �Ǽ��� �� ��� 
		nmin= (long) min;
		second= fmod(second, 60);
		nsecond= (long) second;
		display_time(nhour, nmin, nsecond);
 	}
}

//ȭ�鿡 �ð��� ����ϴ� �Լ� 
void display_time(long nhour, long nmin, long nsecond)
{
	system("cls");
	printf("stopwatch\n\n");
	printf("%.2ld�� %.2ld�� %.2ld�� \n\n", nhour, nmin, nsecond);
	printf("Enter:(����/����), SPACE:�����, Esc:����\n");

}
