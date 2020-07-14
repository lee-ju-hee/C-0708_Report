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
	game_control(); // 게임 컨트롤 함수
	return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); // 라이브러리에 있는 함수를 사용한다
}

void draw_check01(int c, int r)
{
	int i, j;//int형 변수 i,j 선언
	unsigned char a = 0xa6;//확장 완성형 코드의 1번째 바이트
	unsigned char b[12];//2바이트 사용
	
	for (i = 1; i<12; i++)
		b[i] = 0xa0 + i;//배열 b에 확장 완성형 코드 초기화
	printf("%c%c", a, b[3]);//┌출력
	
	for (i = 0; i<c - 1; i++)
		printf("%c%c", a, b[8]);//┬ 출력
	printf("%c%c", a, b[4]);//┐ 출력
	printf("\n");

	for (i = 0; i<r - 1; i++){
		printf("%c%c", a, b[7]);//├출력
		for (j = 0; j<c - 1; j++)
			printf("%c%c", a, b[11]); // c-1만큼 ┼ 출력
		printf("%c%c", a, b[9]);//┤출력
		printf("\n");//줄바꿈
	}
	
	printf("%c%c", a, b[6]);//└출력
	for (i = 0; i<c - 1; i++)
		printf("%c%c", a, b[10]);//c-1 만큼 ┴ 출력
		
	printf("%c%c", a, b[5]);//c-1만큼 ┘ 출력
	printf("\n");//줄바꿈
}

//번갈아가며흑백의바둑돌을놓는함수game_control
void game_control(void)
{
   int x=1, y=1, other=0; 
   int matrix[2][20][20]={0}; // 흑돌의 위치를 저장하는 2차원 배열
   char key;
   char *stone[2]={"○","●"};
   do
   {
		gotoxy(1,1);  // 시작 좌표 1,1
		draw_check01(18, 18); // 18x18 모눈 생성
		gotoxy(x, y);// 1,1 좌표에 바둑돌 생성
		printf("%s", stone[other]);// 바둑돌 이미지
		display_stone(matrix); // 놓아둔 돌의 위치를 기억하는 함수
		gotoxy(1, 20); // 커서 좌표 1,20 이동
		printf("방향키로 움직이고 ");
		printf("스페이스 키를 누르시오.");
		gotoxy(1,21);
        printf("돌을 놓았으면 상대방 차례입니다. ");
		key=getch(); // 바둑돌 이동을 위한 키입력 받음
		if (key==27) // esc 입력시 종료
			exit(0);; //종료
		else if(key==32) // 스페이스바 입력 인식
		{
			matrix[other][(x+1)/2][y]=1; // 스페이스바를 사용한 좌표를 1로 초기화시킨다.
        	other=1-other;  //수정한 부분(획인)
		}
		else if (key>=72)
			move_arrow_key(key, &x, &y, 37, 19);
   	}while(1);
}

//바둑판위에놓은돌을흑돌과백돌로구분하여출력하는함수
void display_stone(int matrix[][20][20])
{
	int i, x, y;
	char  *stone[2]={"○", "●"};

	for(i=0;i<2;i++)
		for(x=1;x<20;x++)//x좌표 0~19 순회 
			for(y=1;y<20;y++)//y좌표 0~19 순회
			{
				if (matrix[i][x][y]==1) //배열의 값이 1일때 
				{
					gotoxy(x*2-1, y);// x좌표의 경우 모눈이 2칸마다 있으므로 2배를 적용하여 커서를 이동시킨다
					printf("%s", stone[i]);
				}
			}
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //위쪽(상) 방향의 화살표 키 입력
		*y1=*y1-1;
		if (*y1<1)	*y1=1; //y좌표의 최소값
		break;
	case 75:  //왼쪽(좌) 방향의 화살표 키 입력
		*x1=*x1-2;              // 모눈 가로가 두칸씩이므로 두칸씩 이동 
		if (*x1<1)	*x1=1; //x좌표의 최소값
		break;
	case 77:  //오른쪽(우) 방향의 화살표 키 입력
		*x1=*x1+2;               //우측방향으로 2씩 증가
		if (*x1>x_b)  *x1=x_b; //x좌표의 최대값(경계)
		break;
	case 80:  //아래쪽(하) 방향의 화살표 키 입력
		*y1=*y1+1;
		if (*y1>y_b)  *y1=y_b; //y좌표의 최대값(경계)
		break;
	default: // 화살표키 이외의 값 입력시 멈춘다.
		return;
	}
}

