#include <stdio.h>
#include <stdint.h>


#ifdef stackexcercise
int main(void){
	int x[5];
	int y;
	int *p = x;
	for(int i =0; i < 5; i++){
		x[i] = i;
		printf("%d",x[i]);

	}
	printf("\n");
	for(int i =1; i < 5; i++){
		printf("%d",p);
		p = p + 1;
	}
}
#endif


#ifdef understandingstack
void doit(int32_t a, int32_t *p){
	int32_t* q = &a;
	*q = 7;
	*p =3;
	printf("The address of new a is %d\n",&a);
	printf("The address of p should be pointing to b %d\n",p);
	printf("The address of q is: %d \n",q);
	printf("%d \n", q+1);
	printf("%d \n",q[0]);
	printf("%d \n",q[1]);
	q[1] = q[1] + 4;
	printf("%d \n",q[1]);
	*p = 1;
}
int main(void){
	int32_t a= 5;
	int32_t b = 10;
	printf("The address of a is: %d \n",&a);
	printf("The address of b is: %d \n",&b);
	doit(a,&b);
	printf("%d %d",a,b);
}
#endif

#ifdef values
int main(void){
	int xsize;
	int ysize;
	xsize = sizeof(char);
	ysize = sizeof(int);
	printf("%d %d\n",xsize,ysize);

	char *x;
	int *y;

	x=0;
	y=0;

	printf("%d %d\n",x,y);
	x=x+1;
	y=y+1;
	printf("%d %d\n",x,y);
}
#endif

#ifdef fall20131
void doit(int32_t a, int32_t b[]){
	a = 42;
	b[0] = 17;
	b[1] = 7;
}
int main(void){
	int32_t a = 5;
	int32_t b[1]={10};
	//doit(a,b);
	printf("%d %d",a,b[1]);
	printf("\n");
	printf("The address of a and b are %d %d %d\n", &a,b,&b[1]);


}
#endif


void doit(char x[], char y[]){
x = y-1;
x[0] = 'M';
printf("%s", x);
}

int main(void){
	char x[4] = "Hey";
	char y[4] = "Joe";
	doit(x,y);
	printf("%s %s", x,y);
}

#ifdef x
int main(void){
//	unsigned char
//	char
//	int loan = 1000;
//	int rate = 10;
//	double decimalr = rate;
//
//	double decimalrate = 1+ decimalr/100;
//	printf("%f\n",decimalrate);
//
//	double newloan = decimalrate*loan;
//	printf("%f\n",newloan);
	int N = (1<<31)-1;
	int x =	N & -N;
	printf("%d\n",N);
	printf("%d",x);
}
#endif

