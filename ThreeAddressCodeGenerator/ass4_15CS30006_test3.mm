/*Loop Statements*/
int sum(int a,int b){
	return (a+b);
}

void main(){
	int i, j;
	int a = 3;
	int b = 4;
	Matrix m[3][4];
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			m[i][j] = i*j;
		}
	}
	i=0;
	Matrix n[3][4];
	while(i<a){
		n[i][0] = m[i][0];
		i++;
	}
	int test = 3;
	int t=0;
	int acc = 0;
	do{
		acc = sum(acc,b);
		t++;
	}while(t<test);
	return;

}