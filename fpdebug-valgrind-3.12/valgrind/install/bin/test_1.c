#include <stdio.h>
#include "../../fpdebug/fpdebug.h"

int main( int argc, const char* argv[] )
{
	printf("Test program: machine epsilon, client request\n");
	
	/* IEEE 745 single precision machine epsilon: 0.00000006f */
	float e = 0.00000005f;

	float sum = 1.0f;
	int i;
	for (i = 0; i < 5; i++) {
		sum += e;
	}

	/* expected value for sum: 1.0 (exactly)
	   expected absolute error: 5 * e
	   works with both SSE and x87 FPU
	*/
	printf("Sum: %.7e\n", sum);


}

