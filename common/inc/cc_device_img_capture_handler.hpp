#ifndef _IMG_CAPTURE_HANDLER_H_
#define _IMG_CAPTURE_HANDLER_H_

// C++ Header File(s)
#include "cc_device_common.hpp"
// #include "opencv2/imgcodecs.hpp"
// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

/// @brief Defining ConfigHandler as singleton class Easy to access across the multiple classes The responsibility of this class is to parse the

class ImgCaptureHandler
{
  private:
    /// @brief Static pointer instance to make this class singleton.
    static ImgCaptureHandler* m_pInstance;

  public:
    /// @brief Public static method getInstance(). This function is responsible for object creation.
    static ImgCaptureHandler* getInstance();

    /// @brief get the value from containerManagement.conf file based on key
    /// @return value
    std::string getValue();

  private:
    /// @brief  Define constructor in the private section to make this class as singleton.
    ImgCaptureHandler();

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~ImgCaptureHandler();

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    ImgCaptureHandler(const ImgCaptureHandler& obj)
    {
    }

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const ImgCaptureHandler& obj)
    {
    }
};

#endif // End of _IMG_CAPTURE_HANDLER_H_