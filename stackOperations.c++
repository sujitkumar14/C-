//stack operations 

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>


using namespace std;

int stack[1000];
int sizeOfStack;
int top = -1;


void push(int n, string outputFileName){
	
	ofstream outputFile;
	outputFile.open(outputFileName);
	
	if(top+1>sizeOfStack){
		outputFile<<"overflow"<<endl;
	}
	else{
		top++;
		stack[top] = n;
		outputFile<<n<<" pushed"<<endl;
	}
	outputFile<<n<<" pushed";


}

void pop(string outputFileName){

	ofstream outputFile;
	outputFile.open(outputFileName);
	if(top<0){
		outputFile<<"underflow"<<endl;
	}
	else{
		outputFile<<"popped"<<stack[top];
		top--;
	}
}

void printStack(string outputFileName)
{
	ofstream outputFile;
	outputFile.open(outputFileName);
	int i=0;
	
	while(i<=top)){
		
		outputFile<<stack[i]<<" ";
	}
	
	outputFile<<endl;

}


int main(int argc,char *argv[]){
	
	
	const char *line;
	int i=0,j;
	ifstream inputFile(argv[1]);
	
	
	if(inputFile.is_open()){
		
		
		while(getline(inputFile,line)){
			if(i==0){
				sizeOfStack = atoi(line);	
			}
			else{
				
				if(strcmp(line,"print")==0){
					printStack(argv[2]);
				}
				else{
					
					const char *ops = line.substr(0,3);
					if(strcmp(ops,"psh")==0){
						push(atoi(substr(4,1)),argv[2]);
					}
					else{
						pop(argv[2]);
					}
				}
			}
		
		}
	}
	
	
	return 0;
	
}