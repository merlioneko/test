#include<stdio.h>
//#include<unistd.h>
#include<pthread.h>

void func(int x);
int count = 0;
pthread_mutex_t count_mutex;

int main(){
        pthread_t t1;
        pthread_t t2;
	pthread_mutex_init(&count_mutex, NULL);
        pthread_create(&t1, NULL, (void*)func, (void*)1);
        pthread_create(&t2, NULL, (void*)func, (void*)2);
        puts("main()");
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
	printf("count = %d\n",count);
        return 0;
}

void func(int x){
        int i;
<<<<<<< Updated upstream
        for(i = 0; i < 10000000; i++){
		pthread_mutex_lock(&count_mutex);
                count++;
		pthread_mutex_unlock(&count_mutex);
=======
        for(i = 0; i < 10; i++){
                printf("func(%d): %d\n", x, i);
		switch(x){
			case 1:usleep(100000);break;
			case 2:usleep(200000);break;
			default: puts("ERROR!!!");break;
			}
>>>>>>> Stashed changes
        }
}
