#include "matrix.h"

#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
	float d[3][3];
	float e[3][3];
	
    init_zero_matrix(b);
	
	printf("\na\n");
    print_matrix(a);
	
	printf("\nb(zeromatrix)\n");
    print_matrix(b);
    
    add_matrices(a, b, c);

	printf("\nc(a+b)\n");
    print_matrix(c);
	
	init_identity_matrix(d);
	printf("\nd(identitymatrix)\n");
	print_matrix(d);
	
	scalar_multiply(a, 3);
	printf("\na*3\n");
	print_matrix(a);
	
	multiply_matrices(a, d, e);
	printf("\ne(a*d)\n");
	print_matrix(e);
	
	//calc_translate_matrix(m, dx, dy);
	//calc_rotation_matrix(m, alpha);
	//calc_scale_matrix(m, sx, sy);
	
	return 0;
}