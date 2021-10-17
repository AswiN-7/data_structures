#include<stdio.h>
#include"queue.h"
int main()
{
   Queue*q1,*q2;
  q1=createQueue();
  q2=createQueue();
  input_fun(q1,q2);
  printf("Queue 1 \nAverage time is: %f\n",cal_average(q1));
  output_fun(q1);
   printf("Queue 2 \nAverage time is: %f\n",cal_average(q2));
  output_fun(q2);
  return 0;
}
/*
SAMPLE I/O :
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex6$ gcc Queue.c -o q
aswin@aswin-pavilion-15:~/Desktop/sem3/data structures in c/lab/ex6$ ./q
enter how many input you are going to give (already one job is inserted in both the queues so input taken as n-2 ):10
enter job name 3:j3
enter burstime : 2
enter job name 4:j4
enter burstime : 3
enter job name 5:j5
enter burstime : 7
enter job name 6:j6
enter burstime : 3
enter job name 7:j7
enter burstime : 7
enter job name 8:j8
enter burstime : 2
enter job name 9:j9
enter burstime : 3
enter job name 10:j10
enter burstime : 7
Queue 1 
Average time is: 8.200000
job name          : j1  j4  j6  j7  j10  
Buresting time : 6    3    3    7    7    
Queue 2 
Average time is: 10.200000
job name          : j2  j3  j5  j8  j9  
Buresting time : 5    2    7    2    3    
*/

