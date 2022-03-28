#ifndef BRICK_H
#define BRICK_H
#include <stdbool.h>

typedef struct Brick
{
	double a;
	double b;
	double c;
	
} Brick;

void set_brick_size(Brick* brick, double a, double b, double c);

double calculate_brick_volume (const Brick* brick);

double calculate_brick_surface(const Brick* brick);

bool has_square_side(const Brick* brick);

#endif