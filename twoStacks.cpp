//stack operations 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;
int stack1[1000];
int stack2[1000];
int maxSizeofStack1;
int maxSizeofStack2;
int top1=-1;
int top2 = -1;



std::string line;


int main(int argc,char *argv[]){
	
	fstream inputFile,outputFile;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	
	int i=0,j;
	while(std::getline(inputFile,line))
	{	
		if(i==0){
			const char *str = line.c_str();
			int temp_size = atoi(str);
			maxSizeofStack1 = 	temp_size/2;
			maxSizeofStack2 = temp_size-maxSizeofStack1;
			
		}
		else{
			const char *str = line.c_str();
			const char *temp = (line.substr(0,3)).c_str();
			const char *psh = "psh";
			const char *pop = "pop";
			
			if(strcmp(temp,psh)==0){
				const  char *data = (line.substr(4,1)).c_str();
				const char *stack_number = (line.substr(6,1)).c_str();
				
				if(atoi(stack_number)==1){
					if(top1+1>maxSizeofStack1){
						outputFile<<"overflow"<<endl;
					}
					else{
						top1++;
						stack1[top1] = atoi(data);
						outputFile<<data<<" pushed in stack 1"<<endl;
					
					}
				}
				else if(atoi(stack_number)==2){
					if(top2+1>maxSizeofStack2){
						outputFile<<"overflow"<<endl;
					}
					else{
						top2++;
						stack2[top2] = atoi(data);
						outputFile<<data<<" pushed in stack 2"<<endl;
					
					}
				}
				
				
			}
			else if(strcmp(temp,pop)==0){
				if(stack_number==1){
					if(top1<0){
						outputFile<<"underflow"<<endl;
						
					}
					else{
						outputFile<<"popped "<<stack1[top1]<<" from stack 1"<<endl;
						top1--;	
					}
				}
				if(stack_number==2){
					if(top2<0){
						outputFile<<"underflow"<<endl;
						
					}
					else{
						outputFile<<"popped "<<stack2[top2]<<" from stack 2"<<endl;
						top2--;	
					}
				}
				
				
				
			}
			else{
				stack_number = (line.substr(2,1)).c_str();
				if(stack_number==1){
					
					for(j=0;j<top1;j++){
						outputFile<<stack1[1]<<" "; 
					}
					outputFile<<endl;
					
				}
				else{
					
					for(j=0;j<top2;j++){
						outputFile<<stack2[j]<<" "; 
					}
					outputFile<<endl;
					
				}
			}
			
		}
		//cout<<line<<endl;
		i++;
	}
	return 0;
	
}