//stack operations 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;
int queue[1000];
int maxSizeOfQueue;
int rear=-1;
int front = -1;
int k=0;





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
			maxSizeOfQueue = atoi(str);
			
		}
		else{
			const char *str = line.c_str();
			const char *temp = (line.substr(0,3)).c_str();
			const char *enqueue = "enq";
			const char *dequeue = "deq";
			
			if(strcmp(temp,enqueue)==0){
				const  char *data = (line.substr(4,1)).c_str();
				if((rear-front+1)>maxSizeOfQueue){
					outputFile<<"overflow"<<endl;
				}
				else{
					if(rear==-1){
						rear++;
						front++;
						k = front;
					}
					else{
						rear++;
					}
					queue[rear] = atoi(data);
					outputFile<<data<<" added"<<endl;
					
				}
				
			}
			else if(strcmp(temp,dequeue)==0){
				if((rear-k)==0){
					outputFile<<"underflow"<<endl;
					
				}
				else{
					outputFile<<"removed "<<queue[front]<<endl;
					queue[front] = -1;
					front++;
					
					
				}
				
				
				
			}
			else{
				int j=front;
				for(;j<=rear;j++){
					if(queue[j]!=-1)
						outputFile<<queue[j]<<" ";
				}
				outputFile<<endl;
			}
			
		}
		//cout<<line<<endl;
		i++;
	}
	return 0;
	
}