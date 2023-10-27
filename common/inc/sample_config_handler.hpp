#ifndef _CONFIG_HANDLER_H_
#define _CONFIG_HANDLER_H_

// C++ Header File(s)
#include "sample_common.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

/// @brief Defining ConfigHandler as singleton class Easy to access across the multiple classes The responsibility of this class is to parse the

class ConfigHandler
{
  private:
    /// @brief Static pointer instance to make this class singleton.
    static ConfigHandler* m_pInstance;

  public:
    /// @brief Public static method getInstance(). This function is responsible for object creation.
    static ConfigHandler* getInstance();

    /// @brief get the value from containerManagement.conf file based on key
    /// @return value
    std::string getValue();

  private:
    /// @brief  Define constructor in the private section to make this class as singleton.
    ConfigHandler();

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~ConfigHandler();

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    ConfigHandler(const ConfigHandler& obj)
    {
    }

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const ConfigHandler& obj)
    {
    }
};

#endif // End of _CONFIG_READER_H_