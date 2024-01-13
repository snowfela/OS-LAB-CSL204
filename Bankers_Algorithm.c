/*    AIM: To implement Banker’s algorithm for deadlock avoidance      */
____________________________________________________________

#include <stdio.h>
void main(){
	int n, m, i, j, k, flag, index=0, alloc[10][10], max[10][10], avail[10], need[10][10], f[10], ans[10];
	printf("Enter no. of processes & resources: ");
  	scanf("%d %d", &n, &m);
  	printf("Enter no.of Availiable resources: ");
  	for(i = 0; i < m; i++){
    	scanf("%d", &avail[i]);
    	f[i] = 0;
  	}
  	printf("Enter the Allocation matrix:\n");
  	for(i = 0; i < n; i++)
    	for(j = 0; j < m; j++)
      	scanf("%d", &alloc[i][j]);
  	printf("Enter the Max matrix:\n");
  	for(i = 0; i < n; i++)
    	for(j = 0; j < m; j++){
      	scanf("%d", &max[i][j]);
      	need[i][j] = max[i][j] - alloc[i][j];
    	}
	for (k = 0; k < n; k++) 
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {
				flag = 0;
				for (j = 0; j < m; j++) 
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
				}
				if (flag == 0) {
					ans[index++] = i;
					for (j = 0; j < m; j++)
						avail[j]+=alloc[i][j];
					f[i] = 1;
	}}}
	flag = 1;
	for(i=0; i<n; i++)
	    if(f[i]==0){
		    flag=0;
		    printf("System Not Safe\n");
	    	break;
	}
	if(flag==1){
	    printf("Safe Sequence: ");
	    for (i = 0; i < n - 1; i++)
		    printf(" P%d ->", ans[i]);
	    printf(" P%d\n", ans[n - 1]);
}}
