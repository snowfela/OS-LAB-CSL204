/*    AIM: To implement Memory Allocation methods
            a)First Fit
            b)Worst Fit
            c)Best Fit                           */
____________________________________________________________

#include<stdio.h>
#include<stdlib.h>
int i, j, op, np, nb, b[100], p[100], alloc[100];
void read(int *nb,int *np){
    printf("Enter no of blocks: ");
    scanf("%d",nb);
    printf("Enter size of \n");
    for(i=0;i<*nb;i++){
        printf(" Block %d: ",i+1);
        scanf("%d",&b[i]);
    }
    printf("Enter no. of processes: ");
    scanf("%d",np);
    printf("Enter size of \n");
    for(i=0;i<*np;i++){
        printf(" Process %d: ",i+1);
        scanf("%d",&p[i]);
        alloc[i]=-1;
}}
void display(){
    printf("Process \tProcess Size\tBlock Allocated\n");
    for(int i=0;i<np;i++){
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(alloc[i]==-1)
            printf("-\n");
        else
            printf("%d\n",alloc[i]+1); 
}}
void first(){
    read(&nb, &np);
    for(i=0;i<np;i++)
        for(j=0;j<nb;j++)
            if(b[j]>=p[i]){
                alloc[i]=j;
                b[j]-=p[i];
                printf("Process %d allocated in block %d\n",i+1,j+1);
                break;
    }
    display();
}
void best(){
    read(&nb, &np);
    for(i=0;i<np;i++){
        int min=1000000, index=-1;
        for(j=0;j<nb;j++)
            if(b[j]>=p[i] && b[j]<min){
                min=b[j];
                index=j;
            }   
        if (index!=-1){
            alloc[i]=index;
            b[index]-=p[i];
            printf("Process %d allocated in block %d\n",i+1,index+1);
    }}
    display();
}
void worst(){
    read(&nb, &np);
    for(i=0;i<np;i++){
        int max=-1, index=-1;
        for(j=0;j<nb;j++)
          if(b[j]>=p[i] && b[j]>max){
            max=b[j];
            index=j;
        }
        if(index!=-1){
            alloc[i]=index;
            b[index]-=p[i];
            printf("Process %d allocated in block %d \n",i+1,index+1);
    }}
    display();
}
void main(){
    while(1) {
        printf("\n1. First Fit   2. Best Fit   3. Worst Fit   4.Exit\nEnter the choice: ");
		    scanf("%d", &op);
		    switch(op){
			      case 1: first();
					      break;
		      	case 2: best();
					      break;
			      case 3: worst();
				      	break;
            case 4: exit(0);
			      default: printf("Invalid choice!!\n");
                break;
}}}
