#include <stdio.h>
#include <omp.h>

static long num_steps = 100000; 
double step;
//double omp_get_wtime(void);

int main (){
	int i; 
	double x=0.0,pi,max_threads,start,time;
	double sum=0.0;
 	step = 1.0/(double) num_steps;
	omp_set_num_threads(4); 	
	//omp_get_max_threads();
	start=omp_get_wtime();
	
 #pragma omp parallel
       {
	
	#pragma omp for reduction(+:sum) schedule(static) private(x) //reduction to get local copy
		for (i=0;i<num_steps;i++){
		x=(i+0.5)*step;
 		sum += 4.0/(1.0+x*x);
		}
	//max_threads=omp_get_max_threads();
 	}
 time=omp_get_wtime()-start;
 pi=step*sum;
 printf("pi=(%f)\t run_time(%f)\n",pi,time);//,max_threads);
 return 0;
}

/*
static long num_steps = 100000;
double step;
int main (){
	 int i;
	 double x, pi, sum = 0.0;
 	step = 1.0/(double) num_steps;
 		for (i=0;i< num_steps; i++){
 			x = (i+0.5)*step;
 			sum = sum + 4.0/(1.0+x*x);
		 }
 	pi = step * sum;
	printf("pi=(%f)\n",pi);
}*/
