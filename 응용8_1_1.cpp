#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);//ȭ��ǥ Ű�� ���� ��ǥ x,y ���� 
void gotoxy(int x, int y);   //Ŀ���� ��ġ ���� 
void draw_check01(int c, int r); //���ڸ���� �ٵ��� ǥ�� 
void game_control(void); //�ٵ����� ǥ���ϰ� �ϳ��� ���� ȭ��ǥ Ű�� �����ӿ� ���� ���� 

int main(void)
{
	game_control();//�ٵ����� ǥ���ϰ� �ϳ��� ���� ȭ��ǥ Ű�� �����ӿ� ���� �����ϴ� �Լ� ���� 
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
    unsigned char a=0xa6;//��ȣ ���� 10���� �ڵ带 a�� �Է� 
    unsigned char b[12]; //�迭�� ũ�Ⱑ 12�� b���� 
    for(i=1;i<12;i++)
		b[i]=0xa0+i;  //0xa1���� 0xa11������ ���� ������� ���� 
		
    printf("%c%c",a, b[3]); //��ȣ ��� 
    for(i=0;i<c-1;i++)
	 	printf("%c%c", a, b[8]);//��ȣ ���   
    printf("%c%c", a, b[4]);//��ȣ ��� 
    printf("\n");
    for(i=0;i<r-1;i++)
    {
		printf("%c%c", a, b[7]);//��ȣ ��� 
		for(j=0;j<c-1;j++)
	    	printf("%c%c", a, b[11]);//��ȣ ��� 
		printf("%c%c",a, b[9]);//��ȣ ��� 
		printf("\n");
    }
    printf("%c%c", a, b[6]);//��ȣ ��� 
    for(i=0;i<c-1;i++)
		printf("%c%c", a, b[10]);//��ȣ ��� 
    printf("%c%c", a, b[5]);//��ȣ ��� 
    printf("\n");
}

void game_control(void)
{
    int x=1, y=1;
    char key;
    do
    {
	gotoxy(1,1);       //Ŀ���� ��ġ�� �����ϴ� �Լ��� �Ű����� ���� ���� 
	draw_check01(18, 18);  //���ڸ���� �ٵ��� ǥ���ϴ� �Լ��� �Ű��������� ���� 
	gotoxy(x, y);     //Ŀ���� ��ġ ���� 
	printf("��");     //��ȣ ��� 
	gotoxy(1, 21);    //Ŀ���� ��ġ ���� 
	printf("����Ű�� �����ÿ�.");
	key=getch();   //����ڰ� �Է��� Ű�� �ƽ�Ű�ڵ尪�� key�� ���� 
	if (key==27)
		exit(0); //�������� 
	else if (key>=72)
		move_arrow_key(key, &x, &y, 37, 19); //�����κ�
   }while(1); //���ѹݺ� 
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)//ȭ��ǥ Ű�� ���� ��ǥ x, y�����ϴ� �Լ��� �Ű�����  
{
	switch(key) //�Ű� ���� key�� ���� ���� 
	{  //switch���� ���� 
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;        //���ʹ������� 1�� ���� 
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;         // �� 
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-2;             //������������ 2�� ����
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;          // �� 
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //������������ 2�� ����
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
		break;         // �� 
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;            //�Ʒ� �������� 1�� ���� 
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
		break;         // �� 
	default:   // break�� switch���� ���� 
		return;//
	}
}

