/*    AIM: To implement page replacement algorithms
            a)FIFO 
            b)LRU 
            c)OPT                                       */
____________________________________________________________

#include<stdio.h>
#include<stdlib.h>
int i, j, k, n, refStr[100], temp[100], op;
int checkFault(int fsize, int need, int f[100]){
    for(i = 0; i < fsize; i++){
        if(f[i] == -1){
            f[i] = need;
            return 2;    //empty frame
        }
        if(need == f[i]) return 0;    //already present
    }
    return 1; //replacement needed
}
void fifo(int n, int ref[100]){
    int frameSize, frames[100], outEnd=0, fault, count=0;
    printf("Enter frame size: ");
    scanf("%d", &frameSize);
    for(i = 0; i < frameSize; i++)
        frames[i] = -1;
    for(i=0; i<n; i++){
        fault = checkFault(frameSize, ref[i], frames);
        if(fault == 1){
            frames[outEnd] = ref[i];
            outEnd = (outEnd+1)%frameSize;
        }
        if(fault) 
            count++;
    } printf("No of Page faults = %d\n", count);
}
void lru(int n, int ref[100]){
    int frameSize, frames[100], used[100], fault, count=0, max = 0, lruind;
    printf("Enter frame size: ");
    scanf("%d", &frameSize);
    for(i = 0; i < frameSize; i++){
        frames[i] = -1;
        used[i] = -1;
    }
    for(int i = 0; i <n; i++){
        fault = checkFault(frameSize, ref[i], frames);
        if(fault==1) {
            for(j = 0; j<frameSize; j++)
                for(k = i; k>=0; k--)        //least recently used 
                    if(frames[j]==ref[k]){
                        used[j] = i-k;
                        break;
                    }
            for(j = 0; j < frameSize; j++){
                if(used[j]>max){
                    max = used[j];
                    lruind = j;
            }}
            frames[lruind] = ref[i];
        }
         if(fault) 
            count++;
    } printf("No of Page faults = %d\n", count);
}
void opt(int n, int ref[100]){
    int frameSize, frames[100], used[100], fault, count=0, max = 0, optind;
    printf("Enter frame size: ");
    scanf("%d", &frameSize);
    for(i = 0; i < frameSize; i++){
        frames[i] = -1;
        used[i] = -1;
    }
    for(int i = 0; i <n; i++){
        fault = checkFault(frameSize, ref[i], frames);
        if(fault==1) {
            for(j = 0; j<frameSize; j++)
                for(k = i; k<n; k++){
                    used[j] = 100;
                    if(frames[j]==ref[k]){
                        used[j] = k-i;
                        break;
                }}
            for(j = 0; j < frameSize; j++){
                if(used[j]>max){
                    max = used[j];
                    optind = j;
            }}
            frames[optind] = ref[i];
        }
         if(fault) 
            count++;
    } printf("No of Page faults = %d\n", count);
}
void main(){
    printf("Enter no of terms in the reference string: ");
    scanf("%d",&n);
    printf("Enter reference string: ");
    for(i=0; i<n; i++)
        scanf("%d",&refStr[i]);
	  while(1) {
		    for(i=0; i<n; i++)
            temp[i] = refStr[i];
        printf("\n1. FIFO   2. OPT   3. LRU   4.Exit\nEnter the choice: ");
		    scanf("%d", &op);
		    switch(op){
			      case 1: fifo(n, temp);
                    break;
            case 2: opt(n, temp);
                    break;
            case 3: lru(n, temp);
                    break;
            case 4: exit(0);
			      default: printf("Invalid choice!!\n");
                    break;
}}}
