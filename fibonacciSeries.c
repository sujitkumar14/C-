//fibonacci series
//cannot calculate precise value if n is greater than 20

#include <stdio.h>
#include <math.h>


void fibonacci(int n,int last,int secLast){
	if(n==0){
		return;
	}

	printf("%d ",last+secLast);
	fibonacci(n-1,last+secLast,last);
}

int main()
{

	int n;
	scanf("%d",&n);
	printf("%d %d ",1,1);
	fibonacci(n-2,1,1);
	printf("\n");


	return 0;
}