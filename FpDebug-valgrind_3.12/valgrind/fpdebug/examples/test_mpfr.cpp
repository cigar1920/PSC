#include<iostream>
#include<mpfr.h>
#include<algorithm>
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

int main(int argc, char *argv[])
{
mpfr_t pre;
mpfr_init2 (pre, atoi(argv[1]));
mpfr_set_ui (pre, atoi(argv[1]), MPFR_RNDN);

mpfr_t base;
mpfr_init2 (base, atoi(argv[1]));
mpfr_set_d (base, 2.0, MPFR_RNDN);


double a=0.0;
mpfr_t t;
mpfr_init2 (t, atoi(argv[1]));
mpfr_set_d (t, 2e-70, MPFR_RNDN);

mpfr_acos(t,t,MPFR_RNDD);

printf("acos:");
mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
printf("\n\n\n\n");
printf("2* acos:");
mpfr_mul_ui(t,t,2,MPFR_RNDN);
mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);

printf("\n\n\n\n");

mpfr_t t1;
mpfr_init2 (t1,  atoi(argv[1]));
mpfr_set_d (t1, 212431.12341234, MPFR_RNDN);
//mpfr_sub_ui(pre,pre,1,MPFR_RNDN);
//mpfr_pow(t1,base,pre,MPFR_RNDN);




mpfr_t t2;
mpfr_init2 (t2,  atoi(argv[1]));
mpfr_set_d (t2, 212431.12341234, MPFR_RNDN);
mpfr_sub_ui(pre,pre,1,MPFR_RNDN);
mpfr_pow(t2,base,pre,MPFR_RNDN);






mpfr_mul(t,t1,t1,MPFR_RNDN);
mpfr_sub(t,t,t,MPFR_RNDN);
	printf ("Sum is ");
mpfr_out_str (stdout, 10, 2e-58, t, MPFR_RNDN);
printf ("\n");


unsigned char *j;
printf("precisions size %d,and max precion is %X\n",sizeof(mpfr_prec_t),MPFR_PREC_MAX);
printf("sign size %d\n",sizeof(mpfr_sign_t));
printf("exp size %d and max exp is %X\n",sizeof(mpfr_exp_t),MPFR_EMAX_DEFAULT);
printf("mpfrlimb size %d\n",sizeof(mp_limb_t));
j=(unsigned char *)&t;
unsigned int i;
char *fmw="./a.txt";
FILE *fwp;
fwp=fopen(fmw,"w+");
unsigned char ii;
for(int i=0;i<((t->_mpfr_prec)%64==0?(t->_mpfr_prec)/64:(t->_mpfr_prec)/64+1);i++)
{
	printf("%d\n",t->_mpfr_d[i]);	
}
printf("\n");
printf("%d\n",t->_mpfr_exp);
printf("\n");

for(i=1;i<=10;i++)
{
	mpfr_add_d(t, t, 1.5, MPFR_RNDN);
	a+=1.5;
  	mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
  	printf("\n");
	
	printf("\n");
	fprintf(fwp,"%X--",&t);
	for(ii=0;ii<sizeof(t);ii++)
	{
		fprintf(fwp,"%X[%d] ",j[ii],j[ii]);
		printf("%X[%d] ",j[ii],j[ii]);
	}
	printf("\n");
	
	printf("\n");
	printf("%x\n",&t);
	printf("%x\n",&(t->_mpfr_prec));
	printf("%x\n",&(t->_mpfr_sign));
	printf("%x\n",&(t->_mpfr_exp));
	for(int i=((t->_mpfr_prec)%64==0?(t->_mpfr_prec)/64:(t->_mpfr_prec)/64+1)-1;i>=0;i--)
	{
	printf("%x\n",*(t->_mpfr_d+i));	
	}

	
	getBit(a);
	fprintf(fwp,"\n");
}
	mpfr_out_str (stdout, 10, 0, t1, MPFR_RNDN);
	printf("\n");
	t1->_mpfr_prec=atoi(argv[1]);
	for(int i=((t->_mpfr_prec)%64==0?(t->_mpfr_prec)/64:(t->_mpfr_prec)/64+1)-1;i>=0;i--)
	{ 
	t1->_mpfr_d[i]=mp_limb_t(0);	
	mpfr_out_str (stdout, 10, 0, t1, MPFR_RNDN);
		printf("\n");
	}
	mpfr_out_str (stdout, 10, 0, t1, MPFR_RNDN);
	
return 0;
}
