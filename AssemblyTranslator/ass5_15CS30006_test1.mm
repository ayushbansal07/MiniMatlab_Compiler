int printInt(int x);
int readInt(int *x);
int printFlt(double d);
int readFlt(double *x);

int add(int a, int b){
	return a+b;
}

int main(){
	int a= 6;
	int c;
	c = a+5+a;
	c = add(c,c);
	int d = c*5;
	int k = printInt(d);
}
