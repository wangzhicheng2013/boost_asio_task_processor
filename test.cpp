#include <memory>
#include "show_task.hpp"
#include "boost_asio_tasks_processor.hpp"
void stop_processor() {
    sleep(2);
    boost_asio_tasks_processor::stop();
}
int main() {
    auto task_ptr1 = std::make_unique<show_task>();
    auto task_ptr2 = std::make_unique<show_task>();
    boost_asio_tasks_processor::push_task(task_ptr.get());
    boost::thread s(stop_processor);
    boost_asio_tasks_processor::start();    // will loop here untiless call boost_asio_tasks_processor::stop() 
    s.join();
    
    return 0;
}