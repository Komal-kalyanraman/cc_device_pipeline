#ifndef _ADAS_V2_Handler_H_
#define _ADAS_V2_Handler_H_

#include <iostream>
#include "inc/cc_device_common.hpp"

class adasV2Handler
{
    private:

    /// @brief Static pointer instance to make this class singleton.
    static adasV2Handler* m_pInstance;

    public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static adasV2Handler* getInstance();

    /// @brief process the image from folder
    /// @return returns the detected classes along with coordinates as JSON string
    string adasV2_output();

    private:

    /// @brief Define constructor in the private section to make this class as singleton.
    adasV2Handler() = default;

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~adasV2Handler() = default;

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    adasV2Handler(const adasV2Handler& obj){}

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const adasV2Handler& obj){}

};

#endif // End of _ADAS_V2_Handler_H_
