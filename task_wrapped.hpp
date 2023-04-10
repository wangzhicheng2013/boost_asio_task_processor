#pragma once
#include <iostream>
#include <cassert>
template <class T>
struct task_wrapped {
private:
    T *task_unwrapped;
public:
    task_wrapped(T *t) : task_unwrapped(t) {
        assert(task_unwrapped != nullptr);
    }
    void operator() () {
        try {
            (*task_unwrapped)();
        } catch(std::exception &e) {
            std::cerr << "task wrapped exception:" << e.what() << std::endl;
        } catch (...) {
            std::cerr << "task wrapped unknown exception!" << std::endl;
        }
    }
};
template <class T>
task_wrapped<T> make_task_wrapped(T* task_unwrapped) {
    return task_wrapped<T>(task_unwrapped);
}