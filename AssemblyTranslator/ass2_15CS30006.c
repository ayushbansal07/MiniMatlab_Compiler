#include "myl.h"
#define BUFF_SIZE_INT 20
#define BUFF_SIZE_STR 1000000
#define BUFF_SIZE_FLT 30
#define PRECISION 6

int printStr(char * str){
	char buff[1000000];
	int i=0;
	while(str[i]!='\0'){
		buff[i]=str[i];
		i++;
	}
	buff[i]='\0';
	__asm__ __volatile__(
			"movl $1, %%eax \n\t"
			"movq $1, %%rdi \n\t"
			"syscall \n\t"
			:
			:"S"(buff),"d"(i+1)
		);
	return i;
}

int printFlt(float f){
	char buff[BUFF_SIZE_FLT];
	int i=0,j,k;
	if(f<0){
		buff[i++]='-';
		f = -f;
	}
	long long int n = (long long int) f;
	long long int n1 = n;
	if(n==0){
		buff[i++] = '0';
	}
	else{
		j=0;
		while(n){
			int d = n%10;
			buff[i++] = (char) (d + '0');
			n/=10;
		} 
		if(buff[0] == '-'){
			j=1;
		}
		k=i-1;
		while(j<k){
			char temp = buff[j];
			buff[j++] = buff[k];
			buff[k--] = temp;
		}
	}
	buff[i++]='.';
	f-=n1;
	int p;
	for(p=0;p<PRECISION;p++){
		f*=10.0;
		int d = (int) f;
		buff[i++] = (char)(d + '0');
		f-=d;
	}
	int len = 0;
	buff[i] = '\n';
	__asm__ __volatile__(
			"movl $1, %%eax \n\t"
			"movq $1, %%rdi \n\t"
			"syscall \n\t"
			:"=a"(len)
			:"S"(buff),"d"(i+1)
		);
	if(len<0)
		return ERR;
	return i;
}

int printInt(int n){
	char buff[BUFF_SIZE_INT];
	int i=0,j,k;
	if(n==0){
		buff[i++] = '0';
	}
	else{
		j=0;
		if(n<0){
			buff[i++] = '-';
			n = -n;
		}
		while(n){
			int d = n%10;
			buff[i++] = (char) (d + '0');
			n/=10;
		}
		if(buff[0] == '-'){
			j=1;
		}
		k=i-1;
		while(j<k){
			char temp = buff[j];
			buff[j++] = buff[k];
			buff[k--] = temp;
		}
	}
	int len = 0;
	buff[i]='\n';
	__asm__ __volatile__(
			"movl $1, %%eax \n\t"
			"movq $1, %%rdi \n\t"
			"syscall \n\t"
			:"=a"(len)
			:"S"(buff),"d"(i+1)
		);
	if(len<0)
		return ERR;
	return i;
}

int readInt(int * x){
	char buff[BUFF_SIZE_STR];
	int sz = 0;
	__asm__ __volatile__ (
			"movq $0, %%rax \n\t"
			"movq $0, %%rdi \n\t"
			"syscall \n\t"
			: "=a"(sz)
			: "S"(buff), "d"(BUFF_SIZE_STR)
		);
	int n = 0;
	int isNeg = 0;
	int i = 0;
	if(buff[0]=='-'){
		isNeg=1;
		i++;
	}
	while(i<sz-1){
		int d = buff[i]-'0';
		if(d<0 || d>9){
			*x = 0;
			return ERR;
		}
		n = (n*10) + d;
		i++;
	}
	if(isNeg){
		n=-n;
	}
	*x = n;
	if(sz<0)
		return ERR;
	return OK;
}

int readFlt(float *x){
	char buff[BUFF_SIZE_FLT];
	int sz = 0;
	__asm__ __volatile__ (
			"movq $0, %%rax \n\t"
			"movq $0, %%rdi \n\t"
			"syscall \n\t"
			: "=a"(sz)
			: "S"(buff), "d"(BUFF_SIZE_FLT)
		);
	float n = 0;
	int i=0;
	int isNeg = 0;
	if(buff[0]=='-'){
		isNeg = 1;
		i++;
	}
	if(sz<0)
		return ERR;
	while(i<sz-1 && buff[i]!='.'){
		int d = buff[i]-'0';
		if(d<0 || d>9){
			*x = 0;
			return ERR;
		}
		n = (n*10) + d;
		i++;
	}
	if(i==sz-1){
		if(isNeg){
			n=-n;
		}
		*x = n;
		return OK;
	}
	i++;
	float f = 0.1;
	while(i<sz-1){
		int d = buff[i]-'0';
		if(d<0 || d>9){
			*x = 0;
			return ERR;
		}
		n = n + (d*f);
		f/=10.0;
		i++;
	}
	if(isNeg){
			n=-n;
		}
	*x = n;
	return OK;

}