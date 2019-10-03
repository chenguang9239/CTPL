//
// Created by admin on 2019-10-02.
//

#include <iostream>
#include <unistd.h>
#include "ctpl.h"
#include "ctpl-debug.h"

int main() {
    {
        ctpl::thread_pool pool(10);
        auto task1 = []() { std::cout << "user task1" << std::endl; };
        auto task2 = []() { std::cout << "user task2" << std::endl; };
        pool.pushToQ(task1);
        pool.pushToQ(task2);
        pool.notifyAll();
        sleep(3);

        pool.push(task1);
        pool.push(task2);
        sleep(3);
    }

    {
        ctpl_debug::thread_pool pool(10);
        auto task1 = []() { std::cout << "user debug task1" << std::endl; };
        auto task2 = []() { std::cout << "user debug task2" << std::endl; };
        pool.pushWithTID(task1);
        pool.pushWithTID(task2);
        sleep(3);
    }

    return 0;
}