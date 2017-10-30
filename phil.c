#include <stdio.h>
#define NUM_PHIL 5
void* philosopher(void *argc);

void* philosopher(void *argc)  {
        //  printf("%p", *argc);
	  int id = *((int*) argc);         // id of philosophe	 
	  int left = id;                   // id of lock for left fork
	  int right = (id + 1) % NUM_PHIL;
	  printf("ID is :%d\n",id);
	  printf("RIGHT is:%d\n",right);
}

void main(){
  int ids = 20;
  philosopher(&ids);

}
