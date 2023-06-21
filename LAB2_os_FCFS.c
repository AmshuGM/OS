//FCFS algorithm
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    int* wtarr=(int *)malloc(n*sizeof(int));
    int* tatarr=(int *)malloc(n*sizeof(int));
    int* atarr=(int *)malloc(n*sizeof(int));
    int* cputarr=(int *)malloc(n*sizeof(int));
    printf("Enter the arrival and burst length of each process\n");
    int awt=0;
    int atat=0;
    int sumtime=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",atarr+i,cputarr+i);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(atarr+j)<*(atarr+i))
            {
                int temp=*(atarr+i);
                *(atarr+i)=*(atarr+j);
                *(atarr+j)=temp;
                temp=*(cputarr+i);
                *(cputarr+i)=*(cputarr+j);
                *(cputarr+j)=temp;
                
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        sumtime+=*(cputarr+i);
        *(tatarr+i)=sumtime;
        *(wtarr+i)=*(tatarr+i)-*(cputarr+i);
        awt+=*(wtarr+i);
        atat+=*(tatarr+i);
    }
    for(int i=0;i<n;i++)
    {
        printf("P%d : waiting time=%d\tturaround time=%d\n",i,*(wtarr+i),*(tatarr+i));
    }
    printf("The average waiting time = %f\nThe average Turnaround time =%f Throughput = %f\n",(float)awt/n,(float)atat/n,(float)sumtime/n);
   
   

    return 0;
}