#ifndef _ADAS_V1_HANDLER_H_
#define _ADAS_V1_HANDLER_H_

#include <iostream>
#include "inc/cc_device_common.hpp"

class adasV1Handler
{
    private:

    /// @brief Static pointer instance to make this class singleton.
    static adasV1Handler* m_pInstance;

    public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static adasV1Handler* getInstance();

    /// @brief process the image from folder
    /// @return returns the detected classes along with coordinates as JSON string
    bool adasV1_output();

    private:

    /// @brief Define constructor in the private section to make this class as singleton.
    adasV1Handler() = default;

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~adasV1Handler() = default;

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    adasV1Handler(const adasV1Handler& obj){}

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const adasV1Handler& obj){}

};

#endif // End of _ADAS_V1_HANDLER_H_
