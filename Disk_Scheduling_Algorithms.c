/*    AIM: To implement disk scheduling algorithms
            a) FCFS
            b) SSTF
            c) SCAN
            d) C-SCAN
            e) LOOK
            f) C-LOOK                                  */
____________________________________________________________

#include<stdio.h>
#include<stdlib.h>
int i, j, n, op;
void copy(int arr[], int copy[], int size){
  for (i=0; i<size; ++i) copy[i] = arr[i];
}
void Sort(int arr[], int n){
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
            if (arr[j] > arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
}}
int diff(int a,int b){ return (a>b)?(a-b):(b-a); }
void fifo(int arr[],int n){
    int seektime=0;
    for(i=0;i<n-1;i++)
        seektime+=diff(arr[i],arr[i+1]);
    printf("Seektime = %d\n",seektime);
}
void sstf(int arr[],int n){
    int seektime=0,curr=0,smallpos;
    for(i=0;i<n-1;i++){
        int smallest=9999;
        for(j=0;j<n;j++){
            if(j==curr) continue;
            if(diff(arr[curr],arr[j])<smallest){
                smallest=diff(arr[curr],arr[j]);
                smallpos=j;
        }}
        seektime+=smallest;
        arr[curr]=9999;
        curr=smallpos;
    } printf("Seektime = %d\n",seektime);
}
int scan(int arr[],int headpos,int n,int right,int end,int c){
    if(headpos==0)return diff(arr[n-1],arr[0]);
    if(right)return c?(end-arr[headpos]+end+arr[headpos-1]):(end-arr[headpos]+end-arr[0]);
    else return c?(arr[headpos]+end+end-arr[headpos+1]):(arr[headpos]+arr[n-1]);
}
int look(int arr[],int headpos,int n,int right,int end,int c){
    if(headpos==0)return diff(arr[n-1],arr[0]);
    if(right)return c?(arr[n-1]-arr[headpos] + arr[n-1]-arr[0] + arr[headpos-1]-arr[0]):(arr[n-1]-arr[headpos] + arr[n-1]-arr[0]);
    else return c?(arr[headpos]-arr[0] + arr[n-1]-arr[0] + arr[n-1]-arr[headpos+1]):(arr[headpos]-arr[0] + arr[n-1]-arr[0]);
}
void main(){
    printf("Enter the number of sectors:");
    scanf("%d",&n);
    int arr[n],arrcpy[n], prev, head, headpos;
    printf("Enter the sectors(first sector = head): ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the previous sector: ");
    scanf("%d",&prev);
    head=arr[0]; copy(arr,arrcpy,n); Sort(arrcpy,n);
    for (i=0;i<n;i++)
        if(arrcpy[i]==head)  headpos=i;
    printf("1. FCFS   2. SSTF   3. SCAN   4. C-SCAN   5. LOOK   6. C-LOOK   7. Exit");
    while(1) {
        printf("\nEnter the choice: ");
		    scanf("%d", &op);
		    switch(op){
			      case 1: copy(arr,arrcpy,n);
                    fifo(arrcpy,n);
                    break;
            case 2: copy(arr,arrcpy,n);
                    sstf(arrcpy,n);
                    break;
            case 3: copy(arr,arrcpy,n);
                    Sort(arrcpy,n);
                    printf("Seektime = %d\n",scan(arrcpy,headpos,n,prev<head,199,0));
                    break;
            case 4: copy(arr,arrcpy,n);
                    Sort(arrcpy,n);
                    printf("Seektime = %d\n",scan(arrcpy,headpos,n,prev<head,199,1));   // 199 last sector 
                    break;
            case 5: copy(arr,arrcpy,n);
                    Sort(arrcpy,n);
                    printf("Seektime = %d\n",look(arrcpy,headpos,n,prev<head,199,0));
                    break;
            case 6: copy(arr,arrcpy,n);
                    Sort(arrcpy,n);
                    printf("Seektime = %d\n",look(arrcpy,headpos,n,prev<head,199,1));
                    break;
            case 7: exit(0);
			      default: printf("Invalid choice!!\n");
                    break;
}}}
