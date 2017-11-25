int printInt(int x);
int readInt(int *x);
int printFlt(double d);
int readFlt(double *x);

int main(){
	int x;
	readInt(&x);
	double d1 = 5.86 + x;
	printFlt(d1);
}