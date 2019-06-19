#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int check=0;


void *processor1(int Que1[5]);
void *processor2(int Que2[5]);

int main(){
	int Que1[5]={5,8,3,5,4};
	int Que2[5]={4,7,3,8,7};
	int flag=1,i;
	while(flag==1){
		pthread_t proc1,proc2;
		check=pthread_create(&proc1, NULL, processor1, Que1);
		check=pthread_create(&proc2, NULL, processor2, Que2);
		pthread_join(proc1, NULL);
		pthread_join(proc2, NULL);
		if(check==1){
			for(i=1;i<4;i++){
				if(Que1[i]>0){
					Que2[0]=Que1[i];
					Que1[i]=0;
					flag=1;
					break;
				}
				else{
					flag=0;
				}
			}
		}
		else{
			for(i=1;i<4;i++){
				if(Que2[i]>0){
					Que1[0]=Que2[i];
					Que2[i]=0;
					flag=1;
					break;
				}
				else{
					flag=0;
				}
			}
		}
	}
	pthread_t proc1,proc2;
	check=pthread_create(&proc1, NULL, processor1, Que1);
	check=pthread_create(&proc2, NULL, processor2, Que2);
	pthread_join(proc1, NULL);
	pthread_join(proc2, NULL);
	pthread_exit(NULL);
}

void *processor1(int *Que1){
	while(1){
		int i=0,flag_check=0,flag=0,j,temp;
		while(Que1[i]<=0){
			i=i%5;
			Que1[i]=Que1[i]-2;
			i++;
			flag_check++;
			if(flag_check==5){
				flag=1;
				break;
			}
		}
		if(flag==0||check==0){
			Que1[i]=Que1[i]-2;
			for(j=0;j<5;j++){
				temp=Que1[j];
				Que1[j]=Que1[j+1];
				Que1[j+1]=temp;
			}
			printf("\t\tProcessor # 1\n");
		}
		else{
			break;
		}
	}
	check=1;
	pthread_exit(NULL);
}


void *processor2(int Que2[5]){
	while(1){
		int i=0,flag_check=0,flag=0,j,temp;
		while(Que2[i]<=0){
			i=i%5;
			Que2[i]=Que2[i]-2;
			i++;
			flag_check++;
			if(flag_check==5){
				flag=1;
				break;
			}
		}
		if(flag==0||check==0){
			Que2[i]=Que2[i]-2;
			for(j=0;j<5;j++){
				temp=Que2[j];
				Que2[j]=Que2[j+1];
				Que2[j+1]=temp;
			}
			printf("Processor # 2\n");
		}
		else{
			break;
		}
	}
	check=2;
	pthread_exit(NULL);
}
