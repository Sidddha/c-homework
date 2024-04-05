#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

#define MAX_X 20
#define MAX_Y 20

#define SPEED 300 //ms
// snake movement direction 
#define UP		1
#define DOWN	-1
#define RIGHT	2
#define LEFT	-2


typedef struct tail_t{
	int x;
	int y;
} tail_t;
	
typedef struct snake_t{
	int dir;
	int x;
	int y;
	struct tail_t * tail;
	size_t tsize;
} snake_t;

typedef struct  food_t{
	int x;
	int y;
} food_t;

void updateScreen(snake_t snake);

void clrscr()
{
	char matrix[MAX_X][MAX_Y];
	for (int i = 0; i < MAX_X; ++i){
		for (int j = 0; j < MAX_Y; ++j)
		{
			matrix[i][j] = ' ';
			}}	
}

void generateFood(food_t * food)
{
	food->x = rand() % (MAX_X + 1); 
	food->y = rand() % (MAX_Y + 1);
}

snake_t initSnake(int dir, int x, int y, size_t tsize){
	snake_t snake;
	snake.dir = dir;
	snake.x = x;
	snake.y = y;
	snake.tsize = tsize;
	snake.tail = (tail_t *) malloc (sizeof(tail_t) * 100);
	for (int i =0; i < tsize; ++i){
		snake.tail[i].x = x + i +1;
		snake.tail[i].y = y;
		}
	return snake;
}

void delay(unsigned milliseconds)
{
    clock_t pause;
    clock_t start;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    start = clock();
    while( (clock() - start) < pause );
}

void changeDir(snake_t * snake, int dir)
{
	if(snake->dir == (dir * -1)) return;
	else
	{
		snake->dir = dir;
	}
}

void scanKey(snake_t * snake)
{
	if(kbhit())
	{
		char c = getch();
		switch (c)
		{
		case 'W': 
		case 'w':
			changeDir(snake, UP);
			break;
		
		case 'S': 
		case 's':
			changeDir(snake, DOWN);
			break;
		
		case 'A':
		case 'a':
			changeDir(snake, LEFT);
			break;
		

		case 'D':
		case 'd':
			changeDir(snake, RIGHT);
			break;
		
		default:
			break;
		}
	}
}

void gameOver(snake_t snake)
{
	for(int i = 0; i < 5; i++)
	{
		system("cls");
		clrscr();
		delay(500);
		system("cls");
		updateScreen(snake);
		printf("***** Game Over *****");
		delay(1000);
	}
	exit(0);
}

int checkCollision(snake_t snake)
{
	for(int i = 0; i < snake.tsize; i++)
	{
		if((snake.x == snake.tail[i].x) && (snake.y == snake.tail[i].y))
		{
			return 1;
		}
	}
	return 0;
}

// @**
void updateScreen(snake_t snake){
		char matrix[MAX_X][MAX_Y];
		for (int i = 0; i < MAX_X; ++i){
			for (int j = 0; j < MAX_Y; ++j)
			{
				matrix[i][j] = ' ';
				}}
		
		for (int i = 0; i < snake.tsize; ++i)
		{
			matrix[snake.tail[i].x][snake.tail[i].y] = '*';
		}
		matrix[snake.x][snake.y] = '@';
		
		
		for (int j = 0; j < MAX_Y; ++j)
		{
			for (int i = 0; i < MAX_X; ++i)
			{
				printf("%c", matrix[i][j]);
			}
				printf("\n");
		}
		

	}

void moveSnake(snake_t * snake)
{
	for (int i = snake->tsize - 1; i > 0; i--)
	{
		snake->tail[i] = snake->tail[i-1];
	}
	snake->tail[0].x = snake->x;
	snake->tail[0].y = snake->y;

	if(snake->dir == UP)
	{		
		snake->y = snake->y - 1;	
		if (snake->y < 0)
		{
			snake->y = MAX_Y - 1;
		}
	}

	if(snake->dir == DOWN)
	{		
		snake->y = snake->y + 1;	
		if (snake->y < 0)
		{
			snake->y = MAX_Y + 1;
		}
	}

	if(snake->dir == LEFT)
	{
		snake->x = snake->x - 1;	
		if (snake->x < 0)
		{
			snake->x = MAX_X - 1;
		}
	}	
	
	if(snake->dir == RIGHT)
	{
		snake->x = snake->x + 1;	
		if (snake->x < 0)
		{
			snake->x = MAX_X + 1;
		}
	}
}

	
int main()
{
	snake_t snake = initSnake(LEFT, 10, 5, 5);
	food_t food;
	generateFood(&food);
	clrscr();
	updateScreen(snake);
	while(1)
	{
		scanKey(&snake);
		moveSnake(&snake);
		delay(SPEED);
		system("cls");
		updateScreen(snake);
		if(checkCollision(snake)) gameOver(snake);
	}
	return 0;
}
