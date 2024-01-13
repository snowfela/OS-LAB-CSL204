/*    AIM: Write a program to open two files ,read from the first file and write the contents of the first file to the second file.     */
____________________________________________________________

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define buffsize 1024
void main(){
   int in, out;
   char buffer[buffsize];
   ssize_t b;
   in = open("in.txt",O_RDONLY);
   out = open("copy.txt",O_WRONLY | O_CREAT | O_TRUNC, 0666);
   if (in==-1 || out==-1){
       printf("Error opening file\n");
       exit(1);
   }
   while((b=read(in, buffer, buffsize))>0) {
   	if(write(out, buffer, b)!=b){
   		perror("Write");
   		exit(1);
   }}
   printf("Copied Succesfully\n");
   close(in); 
   close(out);
}
