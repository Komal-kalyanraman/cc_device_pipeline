// Code Specific Header File(s)
#include "inc/cc_device_data_aggregator_handler.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>

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
    string file_path = UPLOAD_PATH + time_stamp + TEXT_FILE;
    ofstream UndetectedObjectsFile(file_path);
    UndetectedObjectsFile << detection["big_model"];

    string image_src_path   = IMG_PATH + time_stamp + CAM_IMG;
    string image_dest_path  = UPLOAD_PATH + time_stamp + IMG_FILE;
    std::ifstream src(image_src_path, std::ios::binary);
    std::ofstream dest(image_dest_path, std::ios::binary);
    dest << src.rdbuf(); 
    
    string command = "zip -r ../data/" + time_stamp + ".zip ../data/upload";
    const char* cc = command.c_str();
    system(cc);

    return true;
}
