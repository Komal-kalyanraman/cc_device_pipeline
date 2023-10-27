// Code Specific Header File(s)
#include "inc/cc_device_data_aggregator_handler.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

dataAggregatorHandler* dataAggregatorHandler::m_pInstance = NULL_PTR;

dataAggregatorHandler* dataAggregatorHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new dataAggregatorHandler;
    }
    return m_pInstance;
}

bool dataAggregatorHandler::dataAggregator_output()
{
    for(auto it = detection.begin(); it != detection.end(); it++){
        cout << it->first << " " << it->second << endl << endl;
    }

    cout << std::setw(4) << json::meta() << endl;

    return true;
}
