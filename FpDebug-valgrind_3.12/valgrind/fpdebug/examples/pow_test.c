#include <stdio.h>
#include "fdlibm.h"
#include "../fpdebug.h"
int main()
{
	double a =0.1;
	unsigned int h= 0x4093A8EB;
	unsigned int l= 0x851EB852;
	SET_HIGH_WORD(a,h);
	SET_LOW_WORD(a,l);
	printf("%.20le",a);
	VALGRIND_ShowShadowValue(&"a",&a);
	return 0;
}

