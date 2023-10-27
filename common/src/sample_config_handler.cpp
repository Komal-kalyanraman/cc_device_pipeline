// Code Specific Header File(s)
#include "inc/sample_config_handler.hpp"
#include <sstream>

using namespace std;

ConfigHandler* ConfigHandler::m_pInstance = NULL_PTR;

ConfigHandler::ConfigHandler()
{

}

ConfigHandler::~ConfigHandler()
{

}

ConfigHandler* ConfigHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new ConfigHandler;
    }
    return m_pInstance;
}

string ConfigHandler::getValue()
{
    string value = "true";

    return value;
}
