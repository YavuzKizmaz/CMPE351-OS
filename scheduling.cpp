#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 5
#define LINE_MAX 1024


struct linkedList {
	
    	int Name; //Name
    	int bTime; //Brust Time
    	int aTime; //Arrival Time
    	int wTime; //Waiting Time
    	int p; //Priority    	
    	int sr; //Show Result
		
}

linkedList;

void FCFS(struct linkedList process[], FILE *fp){
	
    	struct linkedList *temp;
    	temp = (struct linkedList *) malloc (SIZE*sizeof(struct linkedList));
    	int i;
   	 	int totalWaiting=0;
    	double averageWaiting;

    for(i=0;i<SIZE;i++)
        temp[i]=process[i];

    struct linkedList list;
    int a,b;
    for(a=1;a<SIZE;a++) {
        for (b = 0; b < SIZE - a; b++) 
		
		{
            if (temp[b].aTime > temp[b + 1].aTime) {
            list = temp[b];
            temp[b] = temp[b + 1];
            temp[b + 1] = list;
            
            }
        }
    }

    totalWaiting = temp[0].wTime = 0;

    for(i = 1; i < SIZE; i++){
        temp[i].wTime = (temp[i-1].bTime + temp[i-1].aTime + temp[i-1].wTime) - temp[i].aTime;
        
        totalWaiting += temp[i].wTime;
    }
    
    	averageWaiting = (double)totalWaiting/SIZE;
    		printf("Scheduling Method : First Come First Served\nProcess Waiting Times:\n");

    for(i = 0; i < SIZE; i++) {
        printf("\nP%d: %d ms\n", i+1, temp[i].wTime);
    }
    
    printf("\nAverage waiting time: %f ms\n",averageWaiting);
    
    fprintf(fp,"Scheduling Method : First Come First Served\nProcess Waiting Times:\n");

    for(i = 0; i < SIZE; i++) 
	
	{
		
        fprintf(fp,"\nP%d: %d ms", i+1, temp[i].wTime);
    
	}
	
	
    fprintf(fp,"\nAverage waiting time: %f ms\n",averageWaiting);
    fclose(fp);
}

void SJFS_nonpreemptive(struct linkedList process[], FILE *fp)

{
    	struct linkedList *temp, list, list2;
   	 	temp = (struct linkedList *) malloc (SIZE*sizeof(struct linkedList));
    	int i,a,b;
    	int totalWaitingTime=0;
    	double averageWaitingTime;

    for(i=0;i<SIZE;i++) {
        temp[i] = process[i];
        
    }

    for(a=1;a<SIZE;a++) {
        for (b = 0; b < SIZE - a; b++) 
		
		{
           		if (temp[b].aTime > temp[b + 1].aTime) {
            list2 = temp[b];
            temp[b] = temp[b + 1];
            temp[b + 1] = list2;
            
            }
        }
    }

    for(a=2;a<SIZE;a++) {
        for (b = 1; b < SIZE - a+1; b++) 
		{
            	if (temp[b].bTime > temp[b + 1].bTime) {
            list = temp[b];
            temp[b] = temp[b + 1];
            temp[b + 1] = list;
            }
        }
    }

    totalWaitingTime = temp[0].wTime = 0;

    for(i = 1; i < SIZE; i++)
	
	{
        temp[i].wTime = (temp[i-1].bTime + temp[i-1].aTime + temp[i-1].wTime) - temp[i].aTime;
        totalWaitingTime += temp[i].wTime;
    }

    averageWaitingTime = (double)totalWaitingTime/SIZE;

    for(a=1;a<SIZE;a++) 
	
	{
        for (b = 0; b < SIZE - a; b++) 
		
		{
            	if (temp[b].Name > temp[b + 1].Name) {
            list = temp[b];
            temp[b] = temp[b + 1];
            temp[b + 1] = list;
            }
        }
    }

    printf("Scheduling Method : Priority Scheduling (Preemptive)\nProcess Waiting Times:");
   
    for(i = 0; i < SIZE; i++) 
	
	{
        printf("\nP%d: %d ms", i+1, temp[i].wTime);
    }
    
    
    printf("\nAverage waiting time: %f ms\n",averageWaitingTime);

    fprintf(fp,"Scheduling Method : Priority Scheduling (Preemptive)\nProcess Waiting Times:");

    for(i = 0; i < SIZE; i++) 
	
	{
        fprintf(fp,"\nP%d: %d ms", i+1, temp[i].wTime);
    }
    
    
    fprintf(fp,"\nAverage waiting time: %f ms\n",averageWaitingTime);
    fclose(fp);
    
}
