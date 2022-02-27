#include<stdio.h>
#include<math.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
  int f0, f1, f2, charCount, switchPoint;
  char buff [1];
  f0=open("main.txt", O_RDONLY);
  while(read(f0, buff, 1) != 0){
    charCount++;
  }
  close(f0);
  f0=open("main.txt", O_RDONLY);
  
  switchPoint=floor(charCount/2);
  f1=open("file1.txt", O_RDWR);
  f2=open("file2.txt", O_RDWR);
  while(charCount != 0){
    if(switchPoint <= charCount){
      read(f0, buff, 1);
      write(f1, buff, 1);
    }
    else{
      read(f0, buff, 1);
      write(f2, buff, 1);
    }
    charCount--;
  }
  close(f0);
  close(f1);
  close(f2);
  
  return 0;
}