int printInt(int x);
int readInt(int *x);
int printFlt(double d);
int readFlt(double *x);

int main(){
	Matrix A[2][3] = {1.0,2.0,3.0;4.0,5.0,6.0};
	double d = 0;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){printFlt(A[i][j]); d = d+A[i][j];}	
	}
	printFlt(d);
}
