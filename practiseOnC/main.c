#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

int main () { 
   run(); 
   return 0;
}
void run(){
//Mouse Path
   const char *mousePath = "/dev/input/mice";

   //Mouse open - close state
   int fd;

   //Open Mouse
   fd = open(mousePath, O_RDWR);

   // If mouse did not opened.
   if(fd == -1){
        printf("ERROR Opening %s\n", mousePath);
   }



   int currentX = 0;
   int currentY = 0;

   char dataArray[4];

   int byte;
   int i=0;
   //This loop provides continuous mouse control
   while(1){
      i++;
      byte = read(fd,dataArray,sizeof(dataArray));
      if(byte > 0){
      printf("%d\n", i);
         currentX += dataArray[1];
         currentY += dataArray[2];

         printf("X=%d, Y=%d \n", currentX, currentY) ;
      }
   }
   close(fd);
}
