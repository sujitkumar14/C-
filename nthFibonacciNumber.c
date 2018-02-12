//fibonacci series
//find nth number

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){
	
	int n;
	scanf("%d",&n);

	double rootFive = sqrt(5.0);
	double oneByRootFive = 1/rootFive;
	double rootFiveByTwo = rootFive;

	//can solve in contant time
	int result = (int)(oneByRootFive* (pow((1+rootFiveByTwo)/2,n) - pow((1-rootFiveByTwo)/2,n)));

	printf("%d\n",result);

	
	return 0;
}