#ifndef _sample_Init_Handler_H_
#define _sample_Init_Handler_H_

#include <unistd.h>
#include <iostream>
#include <vector>
#include "inc/sample_config_handler.hpp"

class sampleInitHandler
{
    private:

    /// @brief Static pointer instance to make this class singleton.
    static sampleInitHandler* m_pInstance;

    public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static sampleInitHandler* getInstance();

    /// @brief initialize crm to check for podman running status. Also check and create folders for atos
    /// and trimble inside /vapp, /vappdata and /vapplog folders
    bool sample_init();

    private:

    /// @brief Define constructor in the private section to make this class as singleton.
    sampleInitHandler() = default;

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~sampleInitHandler() = default;

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    sampleInitHandler(const sampleInitHandler& obj){}

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const sampleInitHandler& obj){}

};

#endif // End of _sample_Init_Handler_H_
