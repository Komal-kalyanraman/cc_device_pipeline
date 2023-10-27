#ifndef _SAMPLE_THREAD_HANDLER_HPP_
#define _SAMPLE_THREAD_HANDLER_HPP_

#include <condition_variable>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

class ThreadHandler
{
  private:
    /// @brief Static pointer instance to make this class singleton.
    static ThreadHandler* mpInstance;
    std::thread mThreadCreateHandler;
    std::mutex mMutex;
    std::condition_variable mThreadCv;
    volatile bool mIsShutdown = false;

  public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static ThreadHandler* getInstance();

    /// @brief Start Thread handler thread
    bool Start();

    /// @brief Wait for Thread handler thread shutdown
    void WaitShutdown();

    /// @brief Trigger shutdown the thread
    void TriggerShutdown();

    /// @brief Init the map of this handler
    void InitThreadHandler();

  private:
    /// @brief used to getthe image details from the map
    /// @param tag key value for the map
    /// @return
    void* ProcessThread();

    /// @brief Define constructor in the private section to make this class as singleton.
    ThreadHandler() = default;
    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~ThreadHandler() = default;
    /// @brief Delete to not violate the singleton policy
    ThreadHandler(const ThreadHandler& obj) = delete;
    void operator=(const ThreadHandler& obj) = delete;
};

#endif // End of _SAMPLE_THREAD_HANDLER_HPP_
