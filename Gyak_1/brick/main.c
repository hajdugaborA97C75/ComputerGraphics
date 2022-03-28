#include "brick.h"

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]){
	Brick brick;
	double a, b, c, g;
	double surface, volume;
	bool hasSquare;
	int con=0;


	do{
		printf ("The 'a' side size: \n" );
			scanf ("%lf" , &a);
		
		printf ("The 'b' side size: \n" );
			scanf ("%lf" , &b);
		
		printf ("The 'c' side size: \n" );
			scanf ("%lf" , &c);
			
		if(a>0 && b>0 && c>0){
			con=1;
			set_brick_size(&brick, a, b, c);
		}
		else{
			printf("\n HIBA \n");
		}
	}while(con!=1);
	
	printf("\n\nResults: \n\n");

	printf("\nSet Data: %g %g %g \n\n" ,brick.a ,brick.b, brick.c);
	
	volume=calculate_brick_volume(&brick);
	printf("Volume of the brick: %g \n\n", volume);
	
	surface=calculate_brick_surface(&brick);
	printf("Surface of the brick: %g \n\n" ,surface);
	
	hasSquare=has_square_side(&brick);
	printf((hasSquare)?("The brick has a side that is a square! \n\n"):("The brick has no side that is a square! \n\n"));
	
	return 0;
}