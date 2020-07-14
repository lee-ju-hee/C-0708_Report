#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);
void display_stone(int matrix[][20][20]);

int main(void)
{
	game_control(); // ���� ��Ʈ�� �Լ�
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // ���̺귯���� �ִ� �Լ��� ����Ѵ�
}

void draw_check01(int c, int r)
{
	int i, j;//int�� ���� i,j ����
	unsigned char a = 0xa6;//Ȯ�� �ϼ��� �ڵ��� 1��° ����Ʈ
	unsigned char b[12];//2����Ʈ ���
	
	for (i = 1; i<12; i++)
		b[i] = 0xa0 + i;//�迭 b�� Ȯ�� �ϼ��� �ڵ� �ʱ�ȭ
	printf("%c%c", a, b[3]);//�����
	
	for (i = 0; i<c - 1; i++)
		printf("%c%c", a, b[8]);//�� ���
	printf("%c%c", a, b[4]);//�� ���
	printf("\n");

	for (i = 0; i<r - 1; i++){
		printf("%c%c", a, b[7]);//�����
		for (j = 0; j<c - 1; j++)
			printf("%c%c", a, b[11]); // c-1��ŭ �� ���
		printf("%c%c", a, b[9]);//�����
		printf("\n");//�ٹٲ�
	}
	
	printf("%c%c", a, b[6]);//�����
	for (i = 0; i<c - 1; i++)
		printf("%c%c", a, b[10]);//c-1 ��ŭ �� ���
		
	printf("%c%c", a, b[5]);//c-1��ŭ �� ���
	printf("\n");//�ٹٲ�
}

//�����ư�������ǹٵϵ��������Լ�game_control
void game_control(void)
{
   int x=1, y=1, other=0; 
   int matrix[2][20][20]={0}; // �浹�� ��ġ�� �����ϴ� 2���� �迭
   char key;
   char *stone[2]={"��","��"};
   do
   {
		gotoxy(1,1);  // ���� ��ǥ 1,1
		draw_check01(18, 18); // 18x18 �� ����
		gotoxy(x, y);// 1,1 ��ǥ�� �ٵϵ� ����
		printf("%s", stone[other]);// �ٵϵ� �̹���
		display_stone(matrix); // ���Ƶ� ���� ��ġ�� ����ϴ� �Լ�
		gotoxy(1, 20); // Ŀ�� ��ǥ 1,20 �̵�
		printf("����Ű�� �����̰� ");
		printf("�����̽� Ű�� �����ÿ�.");
		gotoxy(1,21);
        printf("���� �������� ���� �����Դϴ�. ");
		key=getch(); // �ٵϵ� �̵��� ���� Ű�Է� ����
		if (key==27) // esc �Է½� ����
			exit(0);; //����
		else if(key==32) // �����̽��� �Է� �ν�
		{
			matrix[other][(x+1)/2][y]=1; // �����̽��ٸ� ����� ��ǥ�� 1�� �ʱ�ȭ��Ų��.
        	other=1-other;  //������ �κ�(ȹ��)
		}
		else if (key>=72)
			move_arrow_key(key, &x, &y, 37, 19);
   	}while(1);
}

//�ٵ����������������浹���鵹�α����Ͽ�����ϴ��Լ�
void display_stone(int matrix[][20][20])
{
	int i, x, y;
	char  *stone[2]={"��", "��"};

	for(i=0;i<2;i++)
		for(x=1;x<20;x++)//x��ǥ 0~19 ��ȸ 
			for(y=1;y<20;y++)//y��ǥ 0~19 ��ȸ
			{
				if (matrix[i][x][y]==1) //�迭�� ���� 1�϶� 
				{
					gotoxy(x*2-1, y);// x��ǥ�� ��� ���� 2ĭ���� �����Ƿ� 2�踦 �����Ͽ� Ŀ���� �̵���Ų��
					printf("%s", stone[i]);
				}
			}
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
		break;
	case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1-2;              // �� ���ΰ� ��ĭ���̹Ƿ� ��ĭ�� �̵� 
		if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
		break;
	case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
		*x1=*x1+2;               //������������ 2�� ����
		if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
		break;
	default: // ȭ��ǥŰ �̿��� �� �Է½� �����.
		return;
	}
}

