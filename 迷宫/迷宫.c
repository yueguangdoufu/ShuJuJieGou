#include <stdio.h>
#include <stdlib.h>

#define END_I 8
#define END_J 7
#define START_I 0
#define START_J 0


int VistMaze(int maze[][8], int i, int j)
{
	int end = 0;
	maze[i][j] = 2;//假设能够走通
	if (i == END_I && j == END_J){	
		end = 1;
	}
	if (end != 1 && j + 1 <= END_J && maze[i][j + 1] == 0){		//右
		if (VistMaze(maze, i, j + 1) == 1)
			return 1;
	}
	if (end != 1 && i + 1 <= END_I && maze[i + 1][j] == 0){	//下
		if (VistMaze(maze, i + 1, j) == 1)
			return 1;
	}
	if (end != 1 && j - 1 >= START_J && maze[i][j - 1] == 0){	//左
		if (VistMaze(maze, i, j - 1) == 1)
			return 1;
	}
	if (end != 1 && i - 1 >= START_I && maze[i - 1][j] == 0){	//上
		if (VistMaze(maze, i - 1, j) == 1)
			return 1;
	}	
	if (end != 1){
		maze[i][j] = 0;//四周都不通
	}
	return end;
}
int main(void)
{ 
	int i, j;
	int maze[9][8] = {
	{0,0,1,0,0,0,1,0},
	{0,0,1,0,0,0,1,0},
	{0,0,0,0,1,1,0,1},
	{0,1,1,1,0,0,1,0},
	{0,0,0,1,0,0,0,0},
	{0,1,0,0,0,1,0,1},
	{0,1,1,1,1,0,0,1},
	{1,1,0,0,1,1,0,1},
	{1,1,0,0,0,0,0,0}
	};
	//打印迷宫
	printf("原迷宫：\n");
	for(i = 0; i <= 9; i++)
		printf("-");
	printf("\n");
	for (i = 0; i < 9; i++){
		printf("|");
		for (j = 0; j < 8; j++){
			if (maze[i][j] == 1)
				printf("@");
			else
				printf(" ");
		}
		printf("|\n");
	}
	for(i = 0; i <= 9; i++)
		printf("-");
	printf("\n");

	if (VistMaze(maze, 0, 0) == 0){
		printf("没有路径可走\n");
		exit(0);
	}

	
	printf("迷宫和路径：\n");//打印出迷宫和路径
	for(i = 0; i <= 9; i++)
		printf("-");
	printf("\n");
	for (i = 0; i < 9; i++){
		printf("|");
		for (j = 0; j < 8; j++){
			if (maze[i][j] == 1)
				printf("@");
			else if (maze[i][j] == 2)
				printf("%%");
			else
				printf(" ");
		}
		printf("|\n");
	}
	for(i = 0; i <= 9; i++)
		printf("-");
	printf("\n");

	return 0;
}