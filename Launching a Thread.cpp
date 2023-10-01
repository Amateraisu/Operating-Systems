#include <thread>
#include <iostream>

void do_some_work() {
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

    std::thread my_thread(f);
    return 0;
}
