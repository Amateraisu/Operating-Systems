#include <thread>
#include <iostream>
using namespace std;

void do_something() {
    cout << "DO SOMERTHING\n";
}
void do_something_else() {
    cout << "DO SOMETHING ELSE \n";
}
class background_task {
public:
    void operator() () const { // operator overloading for functors, when an object
        do_something();
        do_something_else();
    }
};

int main() {
    background_task f;

    std::thread my_thread(f); // copying here, we dont want that
    std::thread my_thread2{background_task()};
    return 0;
}
