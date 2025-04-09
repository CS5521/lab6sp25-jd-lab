#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
	int forks = fkc(1);
	printf(1, "number of forks when program starts: %d\n", forks);
	int pid1 = fork();
	if(pid1 == 0) {
		exit();
	}

	int pid2 = fork();
	if(pid2 == 0) {
		exit();
	}
	wait();
	wait();
	
	printf(1, "number of forks after two more forks: %d\n", fkc(1));
	
	printf(1, "number of forks after fork count cleared: %d\n", fkc(0));

	int pid3 = fork();
	if(pid3 == 0) {
		exit();
	}

	int pid4 = fork();
	if(pid4 == 0) {
		exit();
	}

	int pid5 = fork();
	if(pid5 == 0) {
		exit();
	}
	wait();
	wait();
	wait();
	printf(1, "number of forks after three more forks: %d\n", fkc(1));
	exit();
}
