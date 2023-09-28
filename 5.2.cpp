#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(int argc, char* argv[]) {
    // Write C++ code here
    std::cout << "Hello world!";
    printf("Hello world from pid: %d\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        printf("fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        printf("Hello I am child pid:%d\n", (int)getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("Hello parent %d pid: %d\n", rc, (int)getpid());
        printf("This is the wait value %d\n", rc_wait);
    }

    return 0;
}