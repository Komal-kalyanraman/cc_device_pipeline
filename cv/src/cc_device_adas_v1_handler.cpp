// Code Specific Header File(s)
#include "inc/cc_device_adas_v1_handler.hpp"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

adasV1Handler* adasV1Handler::m_pInstance = NULL_PTR;

adasV1Handler* adasV1Handler::getInstance()
{
    if (NULL_PTR == m_pInstance) {
        m_pInstance = new adasV1Handler;
    }
    return m_pInstance;
}

bool adasV1Handler::adasV1_output()
{
    string output_path = IMG_PATH + time_stamp + ADAS_V1_IMG;

    // [{"xmin":0.0,"ymin":550.5960083008,"xmax":76.6811904907,"ymax":878.669921875,"confidence":0.4505961835,"class":0.0,"name":"person"}]

    json adas_v1_response = R"({})"_json;
    if(!adas_v1_response.contains("name")){
        cout << "adas_v1 did not find any class during its detection" << endl << endl;
    }

    string adas_v1_response_str = to_string(adas_v1_response);
    detection["adas_v1"] = adas_v1_response_str;

    return true;
}
