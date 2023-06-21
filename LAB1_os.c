#include <stdio.h>
#include<stdlib.h>

void SumRow(int arr[][100],int m,int n)
{
    printf("Sum of rows:\n");
    for(int i=0;i<m;i++)
    {
        printf("Sum of row %d is : ",i);
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[i][j];
        }
        printf("%d\n",sum);
    }
}
void SumCol(int arr[][100],int m,int n)

{
    printf("Sum of Columns:\n");
    for(int i=0;i<m;i++)
    {
        printf("Sum of Column %d is : ",i);
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j][i];
        }
        printf("%d\n",sum);
    }
}
void addArr(int arr[][100],int arr2[][100],int m,int n,int m1,int n1)
{
    if(m!=m1 || n!=n1){printf("invalid size\n");return;}
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             arr[i][j]+=arr2[j][i];
        }
        
    }
    printf("After summation\n");
    for(int i=0;i<m;i++)
    {
        
        for(int j=0;j<n;j++)
        {
    
            printf("%d ",arr[i][j]);}
        
        printf("\n");}
    
}
void SubArr(int arr[][100],int arr2[][100],int m,int n,int m1,int n1)
{
    if(m!=m1 || n!=n1){printf("invalid size\n");return;}

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
             arr[i][j]-=arr2[j][i];
        }
        
    }
    printf("After subtraction\n");
    for(int i=0;i<m;i++)
    {
        
        for(int j=0;j<n;j++)
        {
    
            printf("%d ",arr[i][j]);}
        
        printf("\n");}
}
void MultiplyArr(int arr[][100],int arr2[][100],int m,int n,int m1,int n1)
{
    if(n!=m1){printf("arrays cannot be multiplied\n");return;}
    else 
    {
        int res[m][n1];
        for(int k=0;k<n;k++)
        {
        for(int i=0;i<m;i++ )
        {
            for(int j=0;j<n1;j++)
            {
                res[i][j]+=arr[i][k]*arr2[k][j];
            }
        }
        }
        printf("After multiplication\n");
    for(int i=0;i<m;i++)
    {
        
        for(int j=0;j<n;j++)
        {
    
            printf("%d ",arr[i][j]);}
        
        printf("\n");}
}

    
}
void input(int arr[][100],int arr2[][100],int* m1,int* n1,int* m,int* n)
{
    printf("enter the size of first arr :\n");
    scanf("%d%d",m,n);
printf("enter the array elements\n");
    for(int i=0;i<*m;i++)
    {
        for(int j=0;j<*n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the size of second arr :\n");
    scanf("%d%d",m1,n1);
    printf("enter the array elements\n");
    for(int i=0;i<*m1;i++)
    {
        for(int j=0;j<*n1;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    
    
}
void input1(int arr[][100],int * m, int *n)
{
    printf("enter the size of the array\n");
    scanf("%d%d",m,n);
    printf("enter the array elements\n");
    for(int i=0;i<*m;i++)
    {
        for(int j=0;j<*n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

int main()
{
    
   
    while(1)
    {
        int ch;
        printf("\n\nMAIN MENU\n\n1)Sum of Rows\n2)Sum of Columns\n3)Add two matrix\n4)Subtract two matrix\n5)Multiply two matrix\n6)Exit\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:{int arr[100][100];int m;int n;input1(arr,&m,&n);SumRow(arr,m,n);break;}
            case 2:{int arr[100][100];int m;int n;input1(arr,&m,&n);SumCol(arr,m,n);break;}
            case 3:{int arr[100][100],arr2[100][100];int m,n,m1,n1;
            input(arr,arr2,&m,&n,&m1,&n1);
            addArr(arr,arr2,m,n,m1,n1);
            break;}
            case 4:{int arr[100][100],arr2[100][100];int m,n,m1,n1;
            input(arr,arr2,&m,&n,&m1,&n1);
            SubArr(arr,arr2,m,n,m1,n1);
            break;}
            case 5:{int arr[100][100],arr2[100][100];int m,n,m1,n1;
            input(arr,arr2,&m,&n,&m1,&n1);
            MultiplyArr(arr,arr2,m,n,m1,n1);
            break;}
            default : exit(0);
        }
    }
    

    return 0;
}
