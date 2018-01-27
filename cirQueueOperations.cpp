//circular priority queue operations 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;
int queue[100];
int maxSizeOfQueue;
int rear=-1;
int front = -1;

string line;

int main(int argc,char *argv[]){
	
	fstream inputFile,outputFile;
	inputFile.open(argv[1],ios::in);
	outputFile.open(argv[2],ios::out);
	
	int k;
	for(k=0;k<100;k++)
		queue[k] = (-1);
	
	int i=0,priority,data,maxIndex;
	
	while(getline(inputFile,line))
	{	
		if(i==0){
			const char *str = line.c_str();
			maxSizeOfQueue = atoi(str);
			
		}
		else{
			//const char *str = line.c_str();
			const char *temp = (line.substr(0,3)).c_str();
			const char *enqueue = "enq";
			const char *dequeue = "deq";
			
			if(strcmp(temp,enqueue)==0){
				const char *data1 = (line.substr(4,1)).c_str();
				const char *priority1 = (line.substr(6,1)).c_str(); 
				priority = atoi(priority1);
				data = atoi(data1);
				if((front == rear+1)||(front == 0 && rear == maxSizeOfQueue-1)){
					outputFile<<"overflow"<<endl;
				}
				else{
					if(front==-1){
						rear = (rear+1)%maxSizeOfQueue;
						front = (front+1)%maxSizeOfQueue;
						//max = data;
						maxIndex = priority;
						queue[priority] = data;
					}
					else if(rear == maxSizeOfQueue-1){
						rear = 0;
						queue[priority] = data;
						if(priority>maxIndex){
							maxIndex = priority;
						}
					}
					else{
						rear++;
						queue[priority] = data;
						if(priority>maxIndex){
							maxIndex = priority;
							//max = queue[priority];
						}
					}
					outputFile<<data<<" added"<<endl;
					
				}
				
			}
			else if(strcmp(temp,dequeue)==0){
				if((front == -1)&&(rear == -1)){
					outputFile<<"underflow"<<endl;
					
				}
				else{
					outputFile<<"removed "<<queue[maxIndex]<<endl;
					queue[maxIndex] = -1;
					
					if(front == rear)
						front = rear = (-1);
					else if(front == maxSizeOfQueue-1)
						front = 0;
					else
						front++;
					
					for(k=maxIndex;k>=0;k--){
						if(queue[k]!=(-1)){
							maxIndex = k;
							//max = queue[k];
							break;
						}
					}
				}
			}
			else{
				int j,flag=0;
				for(j=maxIndex;j>=0;j--){
					if(queue[j]!=(-1)){
						flag=1;
						outputFile<<queue[j]<<" ";
					}
					else
					continue;
				}
				if(flag ==1)
				outputFile<<endl;
				else
				outputFile<<"NIL\n";
			}
			
		}
		//cout<<line<<endl;
		i++;
	}
	return 0;
	
}
