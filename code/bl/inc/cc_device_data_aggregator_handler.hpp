#ifndef _DATA_AGGREGATOR_HANDLER_H_
#define _DATA_AGGREGATOR_HANDLER_H_

#include <iostream>
#include "inc/cc_device_common.hpp"

class dataAggregatorHandler
{
    private:

    /// @brief Static pointer instance to make this class singleton.
    static dataAggregatorHandler* m_pInstance;

    public:
    /// @brief Public static method getInstance(). This function is
    // responsible for object creation.
    static dataAggregatorHandler* getInstance();

    /// @brief process the image from folder
    /// @return returns the detected classes along with coordinates as JSON string
    bool dataAggregator_output();

    private:

    /// @brief Define constructor in the private section to make this class as singleton.
    dataAggregatorHandler() = default;

    /// @brief Define destructor in private section, so no one can delete the instance of this class.
    ~dataAggregatorHandler() = default;

    /// @brief Define copy constructor in the private section, so that no one can voilate the singleton policy of this class
    dataAggregatorHandler(const dataAggregatorHandler& obj){}

    /// @brief Define assignment operator in the private section, so that no one can voilate the singleton policy of this class
    void operator=(const dataAggregatorHandler& obj){}

};

#endif // End of _DATA_AGGREGATOR_HANDLER_H_
