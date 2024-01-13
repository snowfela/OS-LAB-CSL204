/*    AIM: To implement file allocation methods
            a) Sequential
            b) Indexed
            c) Linked                                 */
____________________________________________________________

#include<stdio.h>
#define SEQ 0
#define LINK 1
#define INDEX 2
int i, j, msize=100,ftop=0, op;
struct memory{
	int taken, next;
} memory[100];
struct file{
	int start, size, type, index[100];
} files[10];
int Seq(struct memory memory[],int msize,struct file file){
	for(i=file.start;i<file.start+file.size;i++)
		if (memory[i].taken) return 0;
		else 
			memory[i].taken=1;// printf("%d ",i);
	return 1;			
}
int Linked(struct memory memory[],int msize,struct file file){
	if(memory[file.start].taken)	return 0;
	else memory[file.start].taken=1;
	int curr=file.start, next, fill=file.size-1;
	for(i=0;i<file.size-1;i++){
		for(j=0;j<102;j++){			
			next=j;	
			if(j==101){
				printf("No sufficient space in memory !!");
				return 0;
			}
			if(memory[next].taken) continue;
			else{
				memory[curr].next=next;
				curr=next;
				memory[curr].taken=1;
				fill--;
				break;
		}}}
	return 1;
}
int Indexed(struct memory memory[],int msize,struct file files[],int ftop){
	printf("Enter the indexes:");
	for(i=0;i<files[ftop].size;i++){
		scanf("%d",&(files[ftop].index[i]));
		if(memory[files[ftop].index[i]].taken)  return 0;
		else memory[files[ftop].index[i]].taken=1;
	}
	return 1;
}
int Display(struct memory memory[],int msize,struct file files[],int ftop){
	for(i=0;i<ftop;i++){
		printf("\nFile %d type %d: ",i+1,files[i].type);
		if(files[i].type==SEQ){
			printf("(Sequential) ");
			for(j=files[i].start;j<files[i].start+files[i].size;j++)
				printf("%d ",j); }
		else if(files[i].type==LINK){
			int next=files[i].start;
			printf("(Linked) ");
			for(j=0;j<files[i].size;j++){
				printf("%d ",next);
				next=memory[next].next;
		}}
		else if(files[i].type==INDEX){
		  printf("(Indexed) ");
			for(j=0;j<files[i].size;j++)
				printf("%d ",files[i].index[j]);

}}}
int main(){
	for(i=0;i<msize;i++)
		memory[i].taken=0;
	printf("0.To Exit and Display	1.Sequential	2.Linked	3.Indexed \nEnter choice: ");
	scanf("%d",&op);
	while(op){
		printf("Enter starting location & file size: ");
		scanf("%d %d",&files[ftop].start,&files[ftop].size);
		switch(op){
		    case 1: 
          if(Seq(memory,msize,files[ftop])){
					printf("Successfully allocated file %d \n",ftop+1);
					files[ftop].type=SEQ;
					ftop++;
				  }
			    else	printf("Failed to allocate file %d \n",ftop+1);
			    break;
		    case 2: 
          if(Linked(memory,msize,files[ftop])){
					printf("Successfully allocated file %d \n",ftop+1);
					files[ftop].type=LINK;
					ftop++;
				  }
			    else printf("Failed to allocate file %d \n",ftop+1);
			    break;
		    case 3: 
          if(Indexed(memory,msize,files,ftop)){
				  printf("Successfully allocated file %d \n",ftop+1);
				  files[ftop].type=INDEX;//printf(" type %d",files[ftop].type);
				  ftop++;
				  }
			    else	printf("Failed to allocate file %d \n",ftop+1);
			    break;	
		    }
		printf("Enter Choice: ");
		scanf("%d",&op);
	}
	Display(memory,msize,files,ftop);
}
