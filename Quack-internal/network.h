#pragma once
#include "pch.h"
#include "constants.h"


class Communication {
private:
    inline static httplib::Client cli{ "localhost", constants::IPC_PORT };
public:
    static bool SendData(const nlohmann::json& body);
};
