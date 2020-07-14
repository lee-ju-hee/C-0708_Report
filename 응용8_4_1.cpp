#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
char sol[10][11];  //������� �Է� ���� ������ �迭
int main(void)
{
	intro_game();
	display_question();
	printf("\n����Ǯ�̰� ��� �������ϴ�.\n");
	printf("\n\nǮ�̸� ������ �ƹ�Ű�� �����ÿ�.");
	getch();
	display_result();
	printf("press any key to continue.......");
	getch();
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_text(int count) //Ŀ���̵� 
{
	gotoxy(1,2);
	printf("���� ������ �а� ���� �Է��Ͻÿ�.\n\n");
	printf("(%d�� ����) \n\n", count+1);

}

//�ɸ��׽�Ʈ�� ����ǥ��(����ó��) 
void display_question(void)
{
	FILE *fp1;
	char chr1[82];
	int line=5, count=0;
	char *file1="�ɸ��׽�Ʈ����.txt";
	fp1=fopen(file1, "r");
	system("cls");
	while(!feof(fp1))
	{
		fgets(chr1, 80, fp1);//������ ����� �ؽ�Ʈ ������ �о� ���� 
		if (chr1[0]==10) //�ټ����� �̳� 
		{
			display_text(count);
			gotoxy(1, line);
			scanf("%s", sol[count]); //������ ǥ���ϰ� �������� ������ �Է¹��� 
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	display_text(count);
	gotoxy(1, line);
	scanf("%s", sol[count]);
	fclose(fp1);

}

//������ �信 ���� �ؼ�(����ó��) 
void display_result(void)
{
	FILE *fp2;
	char chr1[82];
	int line=5, count=0;
	char *file2="�ɸ��׽�Ʈ�ؼ�.txt";
	fp2=fopen(file2, "r");
	system("cls");
	while(!feof(fp2)) //�ؼ��� ����� �ؽ�Ʈ ������ �о� ���� 
	{
		fgets(chr1, 80, fp2);
		if (chr1[0]==10)
		{
			gotoxy(1, line+1);
			printf("����� ���� : %s\n", sol[count]); //�� ������ ���� �ؼ��� ǥ���ϰ� �������� ������ ǥ�� 
			printf("���������� �ؼ��� �ƹ�Ű�� �����ÿ�.");
			getch();
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	gotoxy(1, line+1);
	printf("����� ���� : %s\n", sol[count]);
	fclose(fp2);

}
void intro_game(void)
{
	system("cls");
	printf("�ɸ��׽�Ʈ ����\n\n");
	printf("���õǴ� ������ ��� ���� �ϰ���\n");
	printf("�ؼ��� ��µ˴ϴ�.\n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�. ");
	getch();

}
