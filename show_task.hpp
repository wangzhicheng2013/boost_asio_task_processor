#pragma once
#include <iostream>
#include "task_base.hpp"
class show_task : public task_base {
public:
    virtual void operator() () override {
        std::cout << "show task!" << std::endl;
    }
};