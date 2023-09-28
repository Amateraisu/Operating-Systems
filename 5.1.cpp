#include <iostream>
#include <unistd.h>
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
        printf("Hello parent %d pid: %d\n", rc, (int)getpid());
    }

    return 0;
}
