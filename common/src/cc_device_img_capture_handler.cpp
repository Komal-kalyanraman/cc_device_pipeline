// Code Specific Header File(s)
#include "inc/cc_device_img_capture_handler.hpp"
#include <sstream>

using namespace std;

ImgCaptureHandler* ImgCaptureHandler::m_pInstance = NULL_PTR;

ImgCaptureHandler::ImgCaptureHandler()
{

}

ImgCaptureHandler::~ImgCaptureHandler()
{

}

ImgCaptureHandler* ImgCaptureHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new ImgCaptureHandler;
    }
    return m_pInstance;
}

string ImgCaptureHandler::getValue()
{
    string value = "true";

    return value;
}
