#include<iostream>
#include<mpfr.h>
#include "../fpdebug.h"
int main()
{
	double a=0.0;
	unsigned int ha=0x43380000;
	unsigned int la=0x0;
	double ap;
	//VALGRIND_PRINT_ERROR(&"oa",&a);
	ap=0.0;
	unsigned char i;
	unsigned char *j;
	unsigned char *j1;
	unsigned char *j2;
	unsigned int sum=0;
	j = (unsigned char *)&a;
	j1= (unsigned char *)&ha;
	j2= (unsigned char *)&la;
	printf("%X\n",&a);
	for(int  i=0;i<sizeof(a);i++)
	{
		printf("%X[%d] ",j[i],j[i]);
	}
	printf("\n");
	for (i=sizeof(a)-5;i>(sizeof(a)-9);i--)
	{
		j[i]=j2[3-(sizeof(a)-5-i)];
	}
	printf("After Setting the low word of (double) a :%.30le\n",a);
	printf("\n");
	
	//VALGRIND_PRINT_ERROR(&"la",&a);
	
	for (i=sizeof(a)-1;i>(sizeof(a)-5);i--)
	{
		j[i]=j1[3-(sizeof(a)-1-i)];
	}
	printf("After setting the high word of (double) a :%.30le\n",a);
	printf("\n");
	//VALGRIND_PRINT_ERROR(&"ha",&a);
	ap=a-(int)a;
	a=(int)a+ap;
	for(int  i=0;i<sizeof(a);i++)
	{
		printf("%X[%d] ",j[i],j[i]);
	}
	VALGRIND_PRINT_ERROR(&"a",&a);
	return 0;
}
