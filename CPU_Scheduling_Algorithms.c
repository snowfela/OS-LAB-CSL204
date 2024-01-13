/*    AIM: To implement CPU scheduling algorithms
            a)FCFS 
            b)SJF Pre-emptive
            c)SJF Non Pre-emptive 
            d)Priority Pre-emptive
            e)Priority Non Pre-emptive
            f)Round Robin Scheduling(TQ=3s)         */
____________________________________________________________

#include<stdio.h>
#include<stdlib.h> 
int n, i, j, op, front=-1, rear=-1, queue[20];  
struct process{
    int id,AT,CT,WT,TAT,BT,PR;
}a[10];
void swap(int *b,int *c){
    int temp=*c;
    *c=*b;
    *b=temp;
}
void print_table(struct process p[], int n){
    printf("\n+*********+*********+*********+*********+\n|   PID   |    CT   |    WT   |   TAT   |\n+*********+*********+*********+*********+\n");
    for(i=0; i<n; i++) 
        printf("|   %2d    |    %2d   |    %2d   |   %2d    |\n+---------+---------+---------+---------+\n", p[i].id, p[i].CT, p[i].WT, p[i].TAT );
}
void FCFS(){
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time and Burst time of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d", &a[i].AT, &a[i].BT);
        a[i].id = i+1;
    }
    printf("Order of exeution: ");
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){ //sorting on the basis of AT
            if(a[j].AT>a[j+1].AT){
                swap(&a[j].id, &a[j+1].id);
                swap(&a[j].AT, &a[j+1].AT);
                swap(&a[j].BT, &a[j+1].BT);
        }}
        printf("P%d   ", a[i].id);
        if (i==0){
            a[0].WT=0;
            a[0].CT=a[0].AT+a[0].BT; }
        if(a[i+1].AT>a[i].CT)
            a[i+1].CT=a[i+1].AT+a[i+1].BT;
        else
            a[i+1].CT=a[i].CT+a[i+1].BT;
        a[i].TAT=a[i].CT-a[i].AT;
        a[i].WT=a[i].TAT-a[i].BT;
        total_WT+=a[i].WT;
        total_TAT+=a[i].TAT;
    }
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f \n",avg_WT, avg_TT);
}
void SJF_pre(){  //srtf
    int count=0, short_P, temp[10];
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time & Burst time of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d", &a[i].AT, &a[i].BT);
        a[i].id = i+1;
        temp[i]=a[i].BT;
    }
    printf("Order of execution: ");
    a[9].BT=10000; //max BT
    for(j=0;count!=n;j++){
        short_P=9;
        for(i=0;i<n;i++){
            if(a[i].BT<a[short_P].BT && a[i].AT<=j && a[i].BT>0)
                short_P=i;
        }
        a[short_P].BT--;
        if(a[short_P].BT==0){  //if any process is completed
            count++;  //1 process completes
            a[short_P].CT=j+1;
            a[short_P].TAT=j+1-a[short_P].AT;
            a[short_P].WT=a[short_P].TAT-temp[short_P];
            total_WT+=a[short_P].WT;
            total_TAT+=a[short_P].TAT;
        }
        printf("P%d   ", a[short_P].id);} 
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
void SJF_nonpre(){
    int check=0;
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time & Burst time of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d", &a[i].AT, &a[i].BT);
        a[i].id = i+1;
        if(i==0)
            check=a[i].AT; 
        if(check!=a[i].AT)
            check=1;
    }
    printf("Order of execution: ");
    if (check!=0){ //different arrival time
        for(i=0; i<n; i++)  //sorting based on AT
            for(j=0;j<n-i-1;j++)
                if(a[j].AT>a[j+1].AT){
                    swap(&a[j].id, &a[j+1].id);
                    swap(&a[j].AT, &a[j+1].AT);
                    swap(&a[j].BT, &a[j+1].BT);
    }}
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) //sorting based on BT
            if(a[i].BT<a[j].BT){
                swap(&a[i].id, &a[j].id);
                swap(&a[i].AT, &a[j].AT);
                swap(&a[i].BT, &a[j].BT);
    }}
    for(i=0;i<n;i++){
        printf("P%d   ", a[i].id);
        if (i==0){
            a[0].WT=0;
            a[0].CT=a[0].AT+a[0].BT; }
        if(a[i+1].AT>a[i].CT)
            a[i+1].CT=a[i+1].AT+a[i+1].BT;
        else
            a[i+1].CT=a[i].CT+a[i+1].BT;
        a[i].TAT=a[i].CT-a[i].AT;
        a[i].WT=a[i].TAT-a[i].BT;
        total_WT+=a[i].WT;
        total_TAT+=a[i].TAT;
    }
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
void Prio_pre(){
    int count=0, short_p, temp[10];
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time, Burst time & Priority of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d %d", &a[i].AT, &a[i].BT, &a[i].PR);
        a[i].id = i+1;
        temp[i]=a[i].BT;
    }
    printf("Order of execution: ");
    a[9].PR=10000;
    for(j=0;count!=n;j++){
        short_p=9;
        for(i=0;i<n;i++){
            if(a[short_p].PR>a[i].PR && a[i].AT<=j && a[i].BT>0)
                short_p=i;
        }
        a[short_p].BT--;
        if(a[short_p].BT==0){ //any process completed
            count++;  //1 process completes
            a[short_p].CT=j+1;
            a[short_p].TAT=j+1-a[short_p].AT;
            a[short_p].WT=a[short_p].TAT-temp[short_p];
            total_WT+=a[short_p].WT;
            total_TAT+=a[short_p].TAT;
        }
        printf("P%d   ", a[short_p].id);}
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
void Prio_nonpre(){
    int check=0;
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time, Burst time & Priority of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d %d", &a[i].AT, &a[i].BT, &a[i].PR);
        a[i].id = i+1;
        if(i==0)
            check=a[i].AT; 
        if(check!=a[i].AT )
            check=1;
    }
    printf("Order of execution: ");
    if (check!=0){ //different arrival time
        for(i=0; i<n; i++)  //sorting based on AT
            for(j=0;j<n-i-1;j++)
                if(a[j].AT>a[j+1].AT){
                    swap(&a[j].id, &a[j+1].id);
                    swap(&a[j].AT, &a[j+1].AT);
                    swap(&a[j].BT, &a[j+1].BT);
                    swap(&a[j].PR, &a[j+1].PR);
    }}
    for(i=0; i<n; i++){
        for(j=0; j<n; j++) //sorting based on PR
            if(a[i].PR<a[j].PR){
                swap(&a[i].id, &a[j].id);
                swap(&a[i].AT, &a[j].AT);
                swap(&a[i].BT, &a[j].BT);
                swap(&a[i].PR, &a[j].PR);
    }}
    for(i=0;i<n;i++){
        printf("P%d   ", a[i].id);
        if (i==0){
            a[0].WT=0;
            a[0].CT=a[0].AT+a[0].BT; }
        if(a[i+1].AT>a[i].CT)
            a[i+1].CT=a[i+1].AT+a[i+1].BT;
        else
            a[i+1].CT=a[i].CT+a[i+1].BT;
        a[i].TAT=a[i].CT-a[i].AT;
        a[i].WT=a[i].TAT-a[i].BT;
        total_WT+=a[i].WT;
        total_TAT+=a[i].TAT;
    }
    avg_WT=total_WT/n;
    avg_TT=total_TAT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
void insert(int x){
    if(front==-1)
        front=0;
    rear++;
    queue[rear]=x;
    printf("P%d   ", a[x].id);
}
int delete(){
    int x=queue[front];
    front++;
    return x;
}
void roundrobin(){
    int q, p, t=0, temp[10], exist[10]={0};
    float avg_WT=0.00, avg_TT=0.00, total_WT=0.00, total_TAT=0.00;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter Arrival time & Burst time of \n");
    for(i=0;i<n;i++){
        printf("P%d: ", i+1);
        scanf("%d %d", &a[i].AT, &a[i].BT);
        a[i].id = i+1;
        temp[i]=a[i].BT;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &q);
    printf("Order of execution: ");
    insert(0); //insert first process
    exist[0]=1;
    while(front<=rear){
        p=delete();
        if(a[p].BT>=q){
            a[p].BT-=q;
            t+=q;
        }
        else{
            t+=a[p].BT;
            a[p].BT=0;
        }
        for(i=0;i<n;i++){  //process not existing in ready queue even a single time 
            if(exist[i]==0 && a[i].AT<=t){
                insert(i);  //insert if it arrives at time 't'
                exist[i]=1;
        }}
        if(a[p].BT==0){  //process completed
            a[p].CT=t;
            a[p].TAT=t-a[p].AT;
            a[p].WT=a[p].TAT-temp[p];
            total_TAT+=a[p].TAT;
            total_WT+=a[p].WT;
        }
        else
            insert(p);
    }
    avg_TT=total_TAT/n;
    avg_WT=total_WT/n;
    print_table(a,n);
    printf("Average WT = %.2f \tAverage TAT = %.2f\n",avg_WT, avg_TT);
}
void main(){
    printf("\n1. FCFS   2. SJF (Non-Preemptive)   3. SJF (Preemptive)   4.Priority Scheduling (Non-Preemptive)   5.Priority Scheduling (Preemptive)   6. Round Robin Scheduling   7. Exit\n");
    while(1) {
        printf("\nEnter the algorithm to perform: ");
		    scanf("%d", &op);
		    switch(op){
			      case 1: FCFS();
					      break;
			      case 2: SJF_nonpre();
					      break;
			      case 3: SJF_pre();
					      break;
            case 4: Prio_nonpre();
					      break;
            case 5: Prio_pre();
					      break;
            case 6: roundrobin();
					      break;
			      case 7: exit(0);
			      default: printf("Invalid choice!!\n");
                break;
}}}
____________________________________________________________
//output:
1. FCFS   2. SJF (Non-Preemptive)   3. SJF (Preemptive)   4.Priority Scheduling (Non-Preemptive)   5.Priority Scheduling (Preemptive)   6. Round Robin Scheduling   7. Exit

Enter the algorithm to perform: 1
Enter no. of processes: 3
Enter Arrival time and Burst time of 
P1: 0 2
P2: 1 4
P3: 2 3
Order of execution: P1   P2   P3   
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    1    |     2   |     0   |    2    |
+---------+---------+---------+---------+
|    2    |     6   |     1   |    5    |
+---------+---------+---------+---------+
|    3    |     9   |     4   |    7    |
+---------+---------+---------+---------+
Average WT = 1.67       Average TAT = 4.67 

Enter the algorithm to perform: 2
Enter no. of processes: 4
Enter Arrival time & Burst time of 
P1: 0 2
P2: 2 3
P3: 2 4
P4: 3 3
Order of execution: P1   P2   P4   P3
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    1    |     2   |     0   |    2    |
+---------+---------+---------+---------+
|    2    |     5   |     0   |    3    |
+---------+---------+---------+---------+
|    4    |     8   |     2   |    5    |
+---------+---------+---------+---------+
|    3    |    12   |     6   |   10    |
+---------+---------+---------+---------+
Average WT = 2.00       Average TAT = 5.00

Enter the algorithm to perform: 3
Enter no. of processes: 3
Enter Arrival time & Burst time of
P1: 0 7
P2: 2 3
P3: 7 2
Order of execution: P1   P1   P2   P2   P2   P1   P1   P3   P3   P1   P1   P1
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    1    |    12   |     5   |   12    |
+---------+---------+---------+---------+
|    2    |     5   |     0   |    3    |
+---------+---------+---------+---------+
|    3    |     9   |     0   |    2    |
+---------+---------+---------+---------+
Average WT = 1.67       Average TAT = 5.67

Enter the algorithm to perform: 4
Enter no. of processes: 4
Enter Arrival time, Burst time & Priority of
P1: 0 5 3
P2: 1 2 4
P3: 2 2 1
P4: 3 6 2
Order of execution: P3   P4   P1   P2
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    3    |     4   |     0   |    2    |
+---------+---------+---------+---------+
|    4    |    10   |     1   |    7    |
+---------+---------+---------+---------+
|    1    |    15   |    10   |   15    |
+---------+---------+---------+---------+
|    2    |    17   |    14   |   16    |
+---------+---------+---------+---------+
Average WT = 6.25       Average TAT = 10.00

Enter the algorithm to perform: 5
Enter no. of processes: 3
Enter Arrival time, Burst time & Priority of
P1: 0 3 3
P2: 1 5 1
P3: 2 2 2
Order of execution: P1   P2   P2   P2   P2   P2   P3   P3   P1   P1
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    1    |    10   |     7   |   10    |
+---------+---------+---------+---------+
|    2    |     6   |     0   |    5    |
+---------+---------+---------+---------+
|    3    |     8   |     4   |    6    |
+---------+---------+---------+---------+
Average WT = 3.67       Average TAT = 7.00

Enter the algorithm to perform: 6
Enter no. of processes: 3
Enter Arrival time & Burst time of
P1: 0 5
P2: 2 7
P3: 4 6
Enter the time quantum: 3
Order of execution: P1   P2   P1   P3   P2   P3   P2
+*********+*********+*********+*********+
|   PID   |    CT   |    WT   |   TAT   |
+*********+*********+*********+*********+
|    1    |     8   |     3   |    8    |
+---------+---------+---------+---------+
|    2    |    18   |     9   |   16    |
+---------+---------+---------+---------+
|    3    |    17   |     7   |   13    |
+---------+---------+---------+---------+
Average WT = 6.33       Average TAT = 12.33

Enter the algorithm to perform: 7
