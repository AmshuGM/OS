#include<stdio.h>
#include<stdlib.h>

int at[50],cput[50],tat[50],wt[50],n,current_time=0;


void shortest_job_t(){
    int completed=0;
    int remaining[n];
    int completed_t[n];
    
    for(int i=0;i<n;i++){
        remaining[i]=cput[i];
    }

    while(completed!=n){
        int shortest=-1;
        int min_time=1000;
        for(int i=0;i<n;i++){
            if(at[i]<=current_time && remaining[i]<min_time && remaining[i]>0){
                shortest=i;
                min_time=remaining[i];
            }
        }
        
        if(shortest==-1){
            current_time++;
            continue;
        }

        
        current_time+=1;
        remaining[shortest]-=1;
        if(remaining[shortest]==0){
            completed++;
            completed_t[shortest]=current_time;
        }
        tat[shortest]=completed_t[shortest]-at[shortest];
        wt[shortest]=tat[shortest]-cput[shortest];

    }
}





int main(){
    printf("Enter number of processes\n");
    scanf("%d",&n);
    printf("\nEnter arrival and cpu time\n");
    for(int i=0;i<n;i++){
        scanf("%d %d",&at[i],&cput[i]);
    }
    shortest_job_t();
    float count=0,countw=0;
    for(int i=0;i<n;i++){
        count+=tat[i];
        countw+=wt[i];
        printf("P%d : Waiting time = %d ,Turnaround time = %d\n",i,wt[i],tat[i]);
    }
    printf("\nAvgWT=%f",(float)(countw)/n);
    printf("\nThroughput=%f",(float)(current_time)/n);
    printf("\nAvgTAT=%f",(float)(count)/n);
    return 0;
}