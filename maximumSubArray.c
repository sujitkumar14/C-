//kadan's algorithm
//if element is all negative than set isAllnegative flag


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maximumSubArray(int *a,int n,int isAllNegative){
	

	int curSum = 0, maxSum = 0;

	if(!isAllNegative){
		for(int i=0;i<n;i++){

			curSum = curSum + a[i];
			if(curSum>maxSum){
				maxSum = curSum;
			}
			else if(curSum<0){
				curSum = 0;
			}
		} 
	}
	else{

		maxSum = -9999999;

		for(int i=0;i<n;i++){

			if(a[i]>maxSum){
				maxSum = a[i];
			}
		}

	}

	return maxSum;
}



int main(){

	int n;
	scanf("%d",&n);

	int a[n];
	int isAllNegative =1;

	for(int i=0;i<n;i++){

		scanf("%d",&a[i]);
		if(a[i]>0){
			isAllNegative = 0;
		}
	}

	

	printf("%d\n",maximumSubArray(a,n,isAllNegative));
	return 0;
}