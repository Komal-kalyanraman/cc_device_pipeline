#ifndef _BIG_MODEL_HANDLER_H_
#define _BIG_MODEL_HANDLER_H_

#include <iostream>
#include "inc/cc_device_common.hpp"

class bigModelHandler
{
    private:

    /// @brief Static pointer instance to make this class singleton.
    static bigModelHandler* m_pInstance;

    public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static bigModelHandler* getInstance();

    /// @brief process the image from folder
    /// @return returns the detected classes along with coordinates as JSON string
    bool bigModel_output();

    private:

    /// @brief Define constructor in the private section to make this class as singleton.
    bigModelHandler() = default;

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~bigModelHandler() = default;

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    bigModelHandler(const bigModelHandler& obj){}

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const bigModelHandler& obj){}

};

#endif // End of _BIG_MODEL_HANDLER_H_
