#include<iostream>
#include<mpfr.h>
#include<algorithm>
#define precision 53

void set_h1(double *x,unsigned int a)
{
	unsigned char i;
	unsigned char *j;
	unsigned char *j1;
	unsigned int sum=0;
	j= (unsigned char *)x;
	j1= (unsigned char *)&a;
	for (i=sizeof(x)-1;i>(sizeof(x)-5);i--)
	{
		j[i]=j1[3-(sizeof(x)-1-i)];
	}
}
void set(mp_limb_t *x,mp_limb_t a)
{
	unsigned char i;
	unsigned char *j;
	unsigned char *j1;
	unsigned int sum=0;
	j= (unsigned char *)x;
	j1= (unsigned char *)&a;
	for (i=sizeof(x)-1;i>=0;i--)
	{
		j[i]=j1[i];
	}
}
int main()
{
	
	//	unsigned int a=0xBF4622D6;
	unsigned int a=0x446CC3B0;//1258.23
	unsigned int b=0;//0x851EB852; 
	double x=0.0;
	set_h1(&x,a);//0xC3380000,43380000,BF4622D6,0x4093A8EB,0x85 
	printf("%.30le\n",x); 
	mpfr_t t;
	mpfr_init2 (t, precision);
	mpfr_set_d (t,x, MPFR_RNDN);
	mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
	printf("\n\n");
int cell_bit=sizeof(mp_limb_t)*8;
	int pos=((t->_mpfr_prec)%cell_bit==0?(t->_mpfr_prec)/cell_bit:(t->_mpfr_prec)/cell_bit+1)-1;

	unsigned char i;
	unsigned char *j;
	j=(unsigned char *)&t;
	for(i=0;i<sizeof(t);i++)
		printf("%x[%d] ",j[i],j[i]);
		printf("\n\n");
	printf("%X \n",t->_mpfr_d[pos]);

	mpfr_set_d (t,0.0, MPFR_RNDN);


	int sign=(a>>31)!=1;

	mpfr_sign_t _mpfr_sign = ((a>>31)!=1?1:0xFFFFFFFF);//set sign 
	
	mpfr_exp_t exptmp= a>>20&0x7FF;
	mpfr_exp_t   _mpfr_exp=(exptmp-0x3FF+1);//set 

	mpfr_prec_t  _mpfr_prec=precision;
	
	
	printf("%X \n",a);
	mp_limb_t _mpfr_dl=t->_mpfr_d[pos]<<21;//保存低位,注释掉即为低位置0的情况 
	printf("%X \n",_mpfr_dl);
	mp_limb_t dtemp=((a&0xFFFFF)+0x100000);
	printf("%X \n",0x100000+dtemp);
	mp_limb_t _mpfr_d0=(dtemp)<<(cell_bit-21)+(_mpfr_dl>>21);//还原低位 
	

	
	mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
	printf("\n\n");
		for(i=0;i<sizeof(t);i++)
		printf("%x[%d] ",j[i],j[i]);
		printf("\n\n");
		
	t->_mpfr_sign=_mpfr_sign;
	t->_mpfr_exp=_mpfr_exp;
	t->_mpfr_prec=_mpfr_prec;
	
	t->_mpfr_d[pos]=_mpfr_d0;
	printf("%X \n",t->_mpfr_d[pos]);

	
	printf ("\n");

	for(i=0;i<sizeof(t);i++)
		printf("%x[%d] ",j[i],j[i]);
		printf("\n\n");
		
	printf ("\nset High:");
	mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
	
	mp_limb_t _mpfr_hl=t->_mpfr_d[pos]>>(cell_bit-21);
	mp_limb_t ltemp=(b<<(cell_bit-53));
	mp_limb_t _mpfr_dl0=ltemp+(_mpfr_hl<<((cell_bit-21)));
	t->_mpfr_d[pos]=_mpfr_dl0;
	printf ("\nset High and Low:");
	
	mpfr_out_str (stdout, 10, 0, t, MPFR_RNDN);
	printf ("\n");
	return 0;
}
