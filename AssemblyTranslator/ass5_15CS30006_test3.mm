int printInt(int x);
int readInt(int *x);
int printFlt(double d);
int readFlt(double *x);

int fib(int n){
	if(n<=1) return 1;
	return fib(n-1) + fib(n-2);
}

int main(){
	double d;
	readFlt(&d);
	double d2 = -d;
	d2 = d2*5.3;
	printFlt(d2);
	printInt(fib(5));
}
