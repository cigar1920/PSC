#include<iostream>
#include<mpfr.h>
#include "../fpdebug.h"
using namespace std;
void getBit(double da)
{
	unsigned char i;
	unsigned char *j;
	j=(unsigned char *)&da;
	//printf("%X\n",&da);
	for(int  i=0;i<sizeof(da);i++)
	{
		printf("%X[%d] ",j[i],j[i]);
	}
	printf("\n");
}
int set_l(double x,double *ap,unsigned int a)
{
	//VALGRIND_PRINT_ERROR(&"set_l x",&x);
	*ap=0.0;
	unsigned char i;
	unsigned char *j;
	unsigned char *j1;
	unsigned int sum=0;
	j = (unsigned char *)&x;
	j1= (unsigned char *)&a;
	printf("%X\n",&x);
	for (i=sizeof(x)-5;i>(sizeof(x)-9);i--)
	{
		j[i]=j1[3-(sizeof(x)-5-i)];
	}
	*ap=x-(int)x;
	//VALGRIND_PRINT_ERROR(&"set_l x",&x);
	return x;
 }
 int set_h(double x,double *ap,unsigned int a)
{
	//VALGRIND_PRINT_ERROR(&"set_h x",&x);
	*ap=0.0;
	unsigned char i;
	unsigned char *j;
	unsigned char *j1;
	unsigned int sum=0;
	j = (unsigned char *)&x;
	j1= (unsigned char *)&a;
	printf("%X\n",&x);
	for (i=sizeof(x)-1;i>(sizeof(x)-5);i--)
	{
		j[i]=j1[3-(sizeof(x)-1-i)];
	}
	*ap=x-(int)x;
	//VALGRIND_PRINT_ERROR(&"set_h x",&x);
	return x;
 }
int main()
{
double a=0.0;//6755399441055744.0;
double b=0.0;//6755399441055744.0;
double ap=0.0;

//VALGRIND_PRINT_ERROR(&"no set l&h a(0.0)",&a);

b=set_h(b,&ap,0x43380000);
b+=ap;
//VALGRIND_PRINT_ERROR(&"hb",&b);
printf("%.30le\n",b);

a=set_h(a,&ap,0x000000000);

a+=ap;
VALGRIND_PRINT_ERROR(&"ha",&a);

VALGRIND_ShadowValueToFloat(&a,&a);

a=set_h(a,&ap,0x43380000);

a+=ap;
VALGRIND_PRINT_ERROR(&"ha",&a);




//a=set_l(a,&ap,0x0);
//a+=ap;
//VALGRIND_PRINT_ERROR(&"la",&a);


getBit(a);

for(int i=1;i<=10;i++)
{
	a+=0.2;
	printf("%.30le\n",a);
	VALGRIND_PRINT_ERROR(&"a",&a);
}
return 0;
}
