#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
  int f1, f2;
  char file1 [100];
  char file2 [100];
  printf("enter file1: ");
  scanf("%s", file1);
  printf("enter file2: ");
  scanf("%s", file2);
  
  if(open(file1, O_RDONLY) != -1){
    f1=open(file1, O_RDONLY);
    char buff [1];
    if(open(file2, O_RDONLY) == -1){
      creat(file2, O_RDWR);
    }
    f2=open(file2, O_WRONLY);
    while(read(f1, buff, 1) != 0){
      write(f2, buff, 1);
    }
    
    close(f1);
    close(f2);
  }
  else{
    printf("file1 does not exist \n");
  }
  
  return 0;
}
