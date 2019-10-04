#include <iostream>
#include <thread>
#include <mutex>

std::mutex g_display_mutex;
std::mutex lock_guard_mutex;

void thread_function (int & a){
    g_display_mutex.lock();
    std::thread::id this_id = std::this_thread::get_id();
    std::cout<< "My thread id is: " << this_id << std::endl;
    g_display_mutex.unlock();
}


void thread_function2(int &b) {
    std::lock_guard<std::mutex> guard(lock_guard_mutex);
    std::thread::id this_id = std::this_thread::get_id();
    std::cout<< "From thread" << this_id <<std::endl;
}


int main (){
    int b = 5;
    unsigned int n_o_t = std::thread::hardware_concurrency();

    std::cout<<"The optimal number of threads is :"<<n_o_t<<std::endl;

    std::thread t1(thread_function,std::ref(b));
    std::thread t2(thread_function,std::ref(b));

    t1.join();
    t2.join();

    std::thread t3(thread_function2,std::ref(b));
    std::thread t4(thread_function2,std::ref(b));

    t3.join();
    t4.join();
    return EXIT_SUCCESS;
}