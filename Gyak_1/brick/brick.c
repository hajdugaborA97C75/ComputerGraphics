#include "brick.h"

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

void set_brick_size(Brick* brick, double a, double b, double c){
	brick->a= a;
	brick->b= b;
	brick->c= c;
}

double calculate_brick_volume (const Brick* brick){
	double volume= brick->a * brick->b * brick->c;
	return volume;
}

double calculate_brick_surface(const Brick* brick){
	double surface=2*(brick->a * brick->b + brick->a * brick->c + brick->c*brick->b);
	return surface;
}

bool has_square_side(const Brick* brick){
	bool res = false;
	if(brick->a == brick->b || brick->a==brick->c || brick->b==brick->c){
		res = true;
	}
	return res;
}