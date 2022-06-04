//
// Created by ByteDance on 2022/5/25.
//

#include "threadgroup.h"
#include "../conf/conf.h"
#include "thread.h"

void fun1(void* xx, const void* yy) {
    int x = *((int*)xx), y = *((int*)yy);
    print("func1, x:" + std::to_string(x) + " y:" + std::to_string(y));
    sleep(2);
}

void fun2() {
    print("func2");
    sleep(2);
}

void fun3() {
    print("func3");
}

int main() {
//    rpc::thread::ThreadPool::ptr threadPool(new rpc::thread::ThreadPool(1, "12"));
//    std::cout << threadPool->getName();
    rpc::thread::ThreadGroup::ptr threadGroup(new rpc::thread::ThreadGroup(5, "qml"));
    std::function<void(void*,const void*)> cb(&fun1);
    int x = 1;
    const int y = 2;
    rpc::thread::ThreadPool::ThreadTask threadTask1(cb, 1, &y, &x);

    threadGroup->addTask(threadTask1);
//    rpc::thread::ThreadPool::ThreadTask threadTask2(&fun2, 2);
//    threadGroup->addTask(threadTask2);
//    rpc::thread::ThreadPool::ThreadTask threadTask3(&fun3, 3);
//    threadGroup->addTask(threadTask3);
//    threadGroup->stop();
//    while (1){}
    sleep(5);
    return 0;
}
