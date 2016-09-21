#include <iostream>
#include "mThread/mThread.hpp"

using namespace std;
using namespace mThread;

static void *loop(void * info){
    for (int i = 0; i < 5; ++i) {
        cout << "loop" << endl;
    }

    return NULL;
}

int main() {
    cout << "Hello, World!" << endl;

    try {
        CommonThread test(loop, "test");
        test.start();
    }catch (ThreadException &e){
        cout << "ex:" << e << endl;
    }

    sleep(2);


    return 0;
}