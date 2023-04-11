#include <stdio.h>	// printf, scanf
#include <stdlib.h>	// malloc, free

typedef struct	s_turn
{
	int	time;
	char	direct;
}		t_turn;

typedef struct	s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct	s_snake
{
	t_coord	head;
	int	length;
	int	direction;	// WNES
	t_coord* body;
}		t_snake;

int	eat_apple(t_snake snake, t_coord* apples)
{
	int	idx;

	idx = 0;
	while ((apples + idx)->x != '\0')
	{
		if (snake.head.x == (apples + idx)->x && snake.head.y == (apples + idx)->y)
		{
			(apples + idx)->x = -1;
			(apples + idx)->y = -1;
			return (1);
		}
		idx++;
	}
	return (0);
}

void	grow_up(t_snake* snake)
{
	t_coord* new_body;
	int	idx;

	if (!(new_body = (t_coord*)malloc(sizeof(t_coord) * (snake->length - 1))))
		return;
	idx = 0;
	while (idx < snake->length - 2)
	{
		(new_body + idx)->x = (snake->body + idx)->x;
		(new_body + idx)->y = (snake->body + idx)->y;
		idx++;
	}
	if (snake->length >= 3)
		free(snake->body);
	snake->body = new_body;
}

int	head_body_crash(t_snake snake)
{
	int	idx;

	idx = 0;
	while (idx < snake.length - 1)
	{
		if (snake.head.x == (snake.body + idx)->x && snake.head.y == (snake.body + idx)->y)
			return (1);
		idx++;
	}
	return (0);
}

void	store_snake_body(t_snake* snake, t_coord pre_coord)
{
	int	idx;

	idx = snake->length - 2;
	while (idx > 0)
	{
		(snake->body + idx)->x = (snake->body + idx - 1)->x;
		(snake->body + idx)->y = (snake->body + idx - 1)->y;
		idx--;
	}
	(snake->body + idx)->x = pre_coord.x;
	(snake->body + idx)->y = pre_coord.y;
}

void	get_time(int size, t_coord* apples, t_turn* turns)
{
	int	survival_time;
	t_snake snake;
	t_coord pre_coord;
	int	turn_idx;

	snake.head.x = 1;
	snake.head.y = 1;
	snake.length = 1;
	snake.direction = 2;
	survival_time = 0;
	turn_idx = 0;
	while (1 <= snake.head.x && snake.head.x <= size &&
		1 <= snake.head.y && snake.head.y <= size)
	{
		pre_coord.x = snake.head.x;
		pre_coord.y = snake.head.y;
		// snake's movement
		if (snake.direction == 1)	// 1: N
			snake.head.x -= 1;
		else if (snake.direction == 2)	// 2: E
			snake.head.y += 1;
		else if (snake.direction == 0)	// 0: W
			snake.head.y -= 1;
		else if (snake.direction == 3)	// 3: S
			snake.head.x += 1;
		// When a snake eats an apple
		if (apples && eat_apple(snake, apples))
		{
			snake.length += 1;
			grow_up(&snake);
		}
		survival_time++;
		// When the head crashes into a body
		if (head_body_crash(snake))
			break;
		// Store and verify the location of the snake's torso
		if (snake.length >= 2)
			store_snake_body(&snake, pre_coord);
		// A snake's turn
		if (turns && survival_time == (turns + turn_idx)->time)
		{
			if ((turns + turn_idx)->direct == 'L')
				snake.direction = (snake.direction - 1) % 4;
			else if ((turns + turn_idx)->direct == 'D')
				snake.direction = (snake.direction + 1) % 4;
			if (snake.direction == -1)
				snake.direction = 3;
			turn_idx++;
		}
	}
	printf("%d\n", survival_time);
	if (apples)
		free(snake.body);
}

int	main(void)
{
	int	size;	// Size of board
	int	apple_count;	// Number of apples
	int	L;	// Number of directional conversions
	int	idx;
	t_coord* apples;
	t_turn* turns;

	scanf("%d", &size);	// size
	// apple_count, x, y
	scanf("%d", &apple_count);
	apples = 0;
	if (apple_count)
	{
		if (!(apples = (t_coord*)malloc(sizeof(t_coord) * apple_count)))
			return (0);
		idx = -1;
		while (++idx < apple_count)
			scanf("%d %d", &(apples + idx)->x, &(apples + idx)->y);
	}
	// L, time, direct
	scanf("%d", &L);
	if (!(turns = (t_turn*)malloc(sizeof(t_turn) * L)))
		return (0);
	idx = -1;
	while (++idx < L)
		scanf("%d %c", &(turns + idx)->time, &(turns + idx)->direct);
	get_time(size, apples, turns);
	if (apple_count)
		free(apples);
	free(turns);
	return (0);
}
