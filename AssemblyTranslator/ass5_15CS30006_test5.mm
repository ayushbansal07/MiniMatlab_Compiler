int printInt(int x);
int readInt(int *x);
int printFlt(double d);
int readFlt(double *x);

int fact(int n){
	if(n==1) return 1;
	return n*fact(n-1);
}

int main(){
	int x = 5;
	int y = fact(x);
	printInt(x);
	printInt(y);
}