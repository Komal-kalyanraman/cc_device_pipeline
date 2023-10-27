#include "inc/sample_threadHandler.hpp"
#include "inc/sample_config_handler.hpp"
#include <iostream>

using namespace std;

ThreadHandler* ThreadHandler::mpInstance = NULL;

ThreadHandler* ThreadHandler::getInstance()
{
    if (NULL == mpInstance) {
        mpInstance = new ThreadHandler;
    }
    return mpInstance;
}

bool ThreadHandler::Start()
{
    mThreadCreateHandler = std::thread(&ThreadHandler::ProcessThread, this);
    if (!mThreadCreateHandler.joinable()) {
        std::cout << "ThreadHandler: Failed to create thread" << std::endl;
        return false;
    }
    std::cout << "ThreadHandler: Thread created successfully" << std::endl;
    return true;
}

void ThreadHandler::WaitShutdown()
{
    if (mThreadCreateHandler.joinable()) {
        std::cout << "ThreadHandler: Waiting thread to be joined" << std::endl;
        mThreadCreateHandler.join();
    }
    else {
        std::cout << "ThreadHandler: Failed to join thread" << std::endl;
    }
}

void ThreadHandler::InitThreadHandler()
{
    std::cout << "ThreadHandler: Handler is initiated" << std::endl;
}

void* ThreadHandler::ProcessThread()
{
    std::cout << "ThreadHandler: Handler is running" << std::endl;
    return NULL;
}

void ThreadHandler::TriggerShutdown()
{
    mIsShutdown = true;
    mThreadCv.notify_all();
}
