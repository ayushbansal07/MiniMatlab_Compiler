/*Recursive functions*/
int fib(int n){
	if(n<=1){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

int ncr(int n, int r){
	if(n==r){
		return 1;
	}
	if(n==1){
		return 1;
	}
	return ncr(n-1,r) + ncr(n-1,r-1);
}


int main(){
	int x;
	x = 5;
	int ans = fib(5);
	int n = 3;
	int r = 2;
	int result = ncr(n,r);
	return 0;
}
