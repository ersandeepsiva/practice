#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int print_fun(int i)
{
	printf("print no %d from thread\n", i);
	return 0;
}

int wifison_listen_event()
{
	int i=10;
	while(1) {
		//sleep(5);
		print_fun(i);
		i--;
		if(i==0)
			break;
	}
	return 0;
}

int daemonize()
{
	int ret;
	size_t stacksize;
	pthread_t wifison_thread;
	pthread_attr_t tattr;

	pthread_attr_init(&tattr);
	pthread_attr_getstacksize(&tattr, &stacksize);
	printf("Thread stack size is %d\n",(int)stacksize);

	pthread_create(&wifison_thread, &tattr, (void*)wifison_listen_event, NULL);
	
	pthread_join(wifison_thread, (void **)&ret);
	printf("Return value is %d\n",ret);
	if(ret != 0) {
		printf("Error\n");
	} else {
		printf("Exit Success\n");
	}
	pthread_attr_destroy(&tattr);
	return 0;
}

int main()
{
	print_fun(11);
	daemonize();
	printf("daemon done\n");
	return 0;
}
