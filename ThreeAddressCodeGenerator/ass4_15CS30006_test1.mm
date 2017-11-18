/*Basic Arithmetic Operations, pointers, jump statements*/
void main(){
	Matrix A[2][3] = {1.0,2.0,3.0;4.0,5.0,6.0};
	Matrix B[3][2] = A.';
	int c = 4;
	int d;
	d = A[1][2]++*B[0][1] - c;
	double e = --A[2][1];
	e = d++ + 6;
	Matrix C[3][4] = {1,1,1,1;2,2,2,2;e,e,c,c};
	Matrix D[2][4] = A*C;

	if(c==4){
		c++;
	}
	if(c<4){
		d++;
	}
	else{
		if(c>=4){
			return;
		}
		else{
			c = c%d;
		}
		e = e/c;
	}

	int * a;
	a++;
	a = &c;
	e = (*a)++;

	double * x = &e;
	*x = A[1][2];

	A[1][1] = c==2 ? c : d;
	c = d<<2;
	*a = e;

	int *w = &c;
	double e;
    e = e + *a;
    c = c * d + -c / d - c % d;
    d = c << 1 + d >> 2;

    char z = 'd';
    x = c&d^d|c;
    z = c>0?c:0;

	return;
}
