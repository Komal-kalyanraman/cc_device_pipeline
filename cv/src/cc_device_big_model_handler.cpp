// Code Specific Header File(s)
#include "inc/cc_device_big_model_handler.hpp"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

bigModelHandler* bigModelHandler::m_pInstance = NULL_PTR;

bigModelHandler* bigModelHandler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new bigModelHandler;
    }
    return m_pInstance;
}

bool bigModelHandler::bigModel_output()
{
    string output_path = IMG_PATH + time_stamp + BIG_MODEL_IMG;

    // [{"xmin":4.2053861618,"ymin":234.4476776123,"xmax":803.7391357422,"ymax":750.0233764648,"confidence":0.6580058336,"class":5.0,"name":"bus"},{"xmin":0.0,"ymin":550.5960083008,"xmax":76.6811904907,"ymax":878.669921875,"confidence":0.4505961835,"class":0.0,"name":"person"}];

    json big_model_response = R"({"xmin":4.2053861618,"ymin":234.4476776123,"xmax":803.7391357422,"ymax":750.0233764648,"confidence":0.6580058336,"class":5.0,"name":"bus"})"_json;

    string big_model_response_str = to_string(big_model_response);

    detection["big_model"] = big_model_response_str;

    return true;
}
