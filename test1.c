// Trabajo algoritmia

// Librerias usadas
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define BASE 10



// Karatsuba >> Es un algortimo para multuplicar numeros grandes de forma eficiente.

unsigned long long pe;

unsigned long long mem,maxmem;

//Funcion para pedir memoria
int *pidemem(int n)
{
	mem+n;
	return (int *)calloc(n,sizeof(int));
}
// Funcion para liberar memoria
int liberamem(int *p,int k)
{
	mem-=k;
	free(p);
}


void sumal(int *a, int n, int *b, int m, int k)
{

	int l,carry=0;
	for(l=0;l<m;++l)
	{
		a[l+k]+=b[l]+carry;
		carry=a[l+k]/BASE;
		a[l+k]%=BASE;
	}
	if(carry>0) a[m+k]+=carry;
}
//de el resultado en a , devuelve el acarreo
int restal(int *a, int n, int *b, int m, int k)
{

	int l,carry=0;
	for(l=0;l<m;++l)
	{
		a[l+k]-=b[l]+carry;
		if(a[l+k]<0)
		{
			a[l+k]+=BASE;
			carry=1;
		}
		else carry=0;
		++l;
	}
	return carry;
}
// Compara
int compara(int *a, int *b, int n)
{
	int i;
  	for(i=n-1;i>=0;--i)
  	{
    	if(a[i]>b[i]) return 1;
   		if(a[i]<b[i]) return -1;
   	}
  	return 0;
}
int *copia(int *a, int i, int j, int k)
{	
	int l,*b=(int *)calloc(k,sizeof(int));
	for(l=i;l<=j;++l) b[l-i]=a[l];
	return b;

}
int *producto(int *a, int *b, int n)
{

	int *c=(int *)calloc(2*n,sizeof(int));
	if(n==1)
	{
		c[0]=a[0]*b[0];
		c[1]=c[0]/BASE;
		c[0]=c[0]%BASE;
		++pe;

	}
	else
	{
		int k=(n+1)/2;
		int *a1,*a2,*b1,*b2,*c1,*c2,*c3,*c4;
		a1=copia(a,0,k-1,k);
		a2=copia(a,k,n-1,k);
		b1=copia(b,0,k-1,k);
		b2=copia(b,k,n-1,k);
		// productos
		c1=producto(a1,b1,k);
		c2=producto(a1,b2,k);
		c3=producto(a2,b1,k);
		c4=producto(a2,b2,n-k);
		// sumas
		sumal(c,2*n,c1,2*k,0);
		sumal(c,2*n,c2,2*k,k);
		sumal(c,2*n,c3,2*k,k);
		sumal(c,2*n,c4,2*(n-k),2*k);
		// liberamos la memoria no necesaria
		free(a1);free(a2);free(b1);free(b2);
		free(c1);free(c2);free(c3);free(c4);
	}
	return c;
}

int *karatsuba(int *a,int *b, int n)
{
	int *c=(int *)calloc(2*n,sizeof(int));
	if(n==1)
	{
		c[0]=a[0]*b[0];
		c[1]=c[0]/BASE;
		c[0]=c[0]%BASE;
		++pe;

	}
	else
	{
		int k=(n+1)/2,s=1;
		int *a1,*a2,*b1,*b2,*c1,*c2,*c3;
		a1=copia(a,0,k-1,k);
		a2=copia(a,k,n-1,k);
		b1=copia(b,0,k-1,k);
		b2=copia(b,k,n-1,k);

		c1=karatsuba(a1,b1,k);
		c2=karatsuba(a2,b2,n-k);

		sumal(c,2*n,c1,2*k,0);
		sumal(c,2*n,c2,2*(n-k),2*k);
		sumal(c,2*n,c1,2*k,k);
		sumal(c,2*n,c2,2*(n-k),k);
		free(c1),free(c2);

		if(compara(a1,a2,k)>=0)
		{
			restal(a1,k,a2,n-k,0);
			free(a2);
		}
		else
		{
			restal(a2,k,a1,k,0);
			free(a1);
			a1=a2;
			s=-s;
		}
		if(compara(b1,b2,k)>=0)
		{
			restal(b1,k,b2,n-k,0);
			free(b2);
		}
		else
		{
			restal(b2,k,b1,k,0);
			free(b1);
			b1=b2;
			s=-s;
		}
		c3=karatsuba(a1,b1,k);
		if(s>0) restal(c,2*n,c3,2*k,k);
		else sumal(c,2*n,c3,2*k,k);

		free(a1);free(b1);free(c3);
	}
	return c;
}

int *getnum(char *s,int n)
{
	
	int l,*b=(int *)calloc(n,sizeof(int));
	int m=strlen(s);
	for(l=0;l<=m;l++) b[m-1-l]=s[l]-'0';
	return b;
}

void pinta(char *s,int *a,int n)
{
	int i;
	printf("%s",s);
	for(i=n-1;i>=0;--i) printf("%d", a[i]);
	printf("\n");
}
int llama_karatsuba(int *a, int *b, int *c, int n, int m, int argc_1)
{
	
  
  if(argc_1<3) { 
      printf("Uso: producto num1 num2\n");
      exit(1); 
    }
  
  if(m>n) n=m; // n=maximo de las dos longi77tudes
  //pinta("a=",a,n);
  //pinta("b=",b,n);
  c=producto(a,b,n);
  //printf("productos elementales: %llu\n",pe);
  //pinta("p=",c,2*n);
  free(c);pe=0;
  c=karatsuba(a,b,n);
  //printf("productos elementales: %llu\n",pe);
  //pinta("k=",c,2*n);
  return 0;
}

int main (int argc, char *argv[]){
    int *a, *b, *c, n, m;
    a=getnum(argv[1],n);
    b=getnum(argv[2],n);
    n=strlen(argv[1]);
    m=strlen(argv[2]);
    printf("\n \n Llama a llama_karatsuba \n");
	printf("\n \n \n");
    llama_karatsuba(a,b,c,n,m,argc);


}
