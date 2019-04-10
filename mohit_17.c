#include<stdio.h>

int n=0;//total number of processes
int clock = 0;//a clock having the current time
int c_p=9999;
int c_index=-1;
int rr_index=0;

struct process{
	int id;//process id
	int at;//arival time
	int bt;//burst time
	int p;//priority
	int s_time[100];//index containg all the starting times of process
	int s_index=0;//current index of start_time
	int status = -1;//process status waiting: -1 , finished: 0, running:1;
	int waiting_time=0;//total time the process was in waiting
	int next_process_index=0;//next process address
	int my_index;//current process address
	int visited=0;
}proc[2][50];

int q=0;//queue number
int q1_proc,q2_proc;//number of process in q1 qnd q2

//to sort by arrival time
void sort_arival(int n){
	struct process a;
	int min,pos;
	
	for(int i=0;i<n-1;i++){
		min = proc[q][i].at;
		pos = i;	
		for(int j=i+1;j<n;j++){
			if(min>proc[q][j].at){
				min = proc[q][j].at;
				pos = j;
			}
		}
		
		if(i!=pos){
			a=proc[q][i];
			proc[q][i]=proc[q][pos];
			proc[q][pos]=a;
		}
	}
}

int get_next(int index){
	int n=0;//if 0 current process will continue runnig else it will be sent to q2
	for(int i=0;i<q1_proc;i++){
		if(proc[q][i].at<=clock && proc[q][i].bt!=0){
			printf("hello");
			proc[q][i].my_index=i;
			if(proc[q][i].p<c_p){
				proc[q][index].next_process_index=i;
				c_p=proc[q][i].p;
				n=1;
			}
		}
	}
	return n;
}

void move_to_last(){
	struct process a;
	int i=0;
	a = proc[q][0];
	
	while(i<q2_proc-1){
		proc[q][i]=proc[q][i+1];
		i++;
	}
	proc[q][i]=a;
}

void pop(){
	int i=0;
	while(i<q2_proc-1){
		proc[q][i]=proc[q][i+1];
		i++;
	}
	q2_proc--;
}

main(){
	int val,res_index,a;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	struct process result[n];
	q1_proc = n;
	q2_proc = 0;
	res_index = 0;
	//get the process imformation
	
	for(int i=0;i<n;i++){
		printf("\nEnter the process information for the process %d :",i+1);
		printf("\nprocess Id : ");
		scanf("%d",&val);
		proc[q][i].id=val;
		printf("\nprocess arival time :");
		scanf("%d",&val);
		proc[q][i].at=val;
		printf("\nprocess burst time :");
		scanf("%d",&val);
		proc[q][i].bt=val;
		printf("\nprocess priority :");
		scanf("%d",&val);
		proc[q][i].p=val;
	}
	
	sort_arival(q1_proc);
	
	get_next(0);
	c_index = proc[q][c_index].next_process_index;
	
	while(q1_proc!=0 || q2_proc!=0){
		if(q1_proc!=0){
			printf("\nID %d",proc[q][c_index].id);
			printf("\nat %d",proc[q][c_index].at);
			printf("\nbt %d",proc[q][c_index].bt);
			printf("\np %d",proc[q][c_index].p);
			printf("\nstatus %d",proc[q][c_index].status);
			//for queue 1
			q=0;
			if((proc[q][c_index].status!=0) && (proc[q][c_index].at<=clock)){
				proc[q][c_index].s_time[proc[q][c_index].s_index]=clock;
				proc[q][c_index].s_index++;
				clock++;
				proc[q][c_index].bt--;
				a=c_index;
				if(proc[q][c_index].bt==0){
					q1_proc--;
					c_p=9999;
					get_next(c_index);
					c_index = proc[q][c_index].next_process_index;
					proc[q][a].status=0;
					result[res_index]=proc[q][a];
					res_index++;
					for(int i=a;i<q1_proc;i++){
						proc[q][i]=proc[q][i+1];
					}
				}
				if(get_next(c_index)){
					get_next(c_index);
					c_index = proc[q][c_index].next_process_index;
					proc[q+1][rr_index]=proc[q][a];
					rr_index++;
					q2_proc++;
					q1_proc--;
					for(int i=a;i<q1_proc;i++){
						proc[q][i]=proc[q][i+1];
					}
				}
			}
			else{
				clock++;
			}
		}
		else if(q2_proc!=0){
			//for queue 2
			q=1;
			val=1;
			if(proc[q][c_index].status!=0){
				for(int i=0;i<2;i++){
					proc[q][0].s_time[proc[q][0].s_index]=clock;
					proc[q][0].s_index++;
					clock++;
					proc[q][0].bt--;
					if(proc[q][0].bt==0){
						q2_proc--;
						proc[q][0].status=0;
						result[res_index]=proc[q][0];
						res_index++;
						val=0;
						pop();
						break;
					}
				}
				if(val){
					move_to_last();
				}
			}	
		}
		else{
			clock++;
		}
	}
	
	for(int i=0;i<=res_index;i++){
		for(int j=0;j<=result[i].s_index;j++){
			printf("\nThe process %d was running at time %d sec.",result[i].id,result[i].s_time[j]);
		}
	}
}

