#include <boost/noncopyable.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/thread/thread.hpp>
#include "task_wrapped.hpp"
class boost_asio_tasks_processor : public boost::noncopyable {
protected:
    static boost::asio::io_service& get_ios() {
        static boost::asio::io_service ios;
        static boost::asio::io_service::work work(ios);
        return ios;
    }
public:
    template <class T>
    static void push_task(T *task_unwrapped) {
        get_ios().post(make_task_wrapped(task_unwrapped));
    }
    static void start() {
        get_ios().run();
    }
    static void stop() {
        get_ios().stop();
    }
};