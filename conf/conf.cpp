//
// Created by ByteDance on 2022/5/22.
//

#include "conf.h"
#include <string>

bool is_insert(std::string func_call) {
    if (func_call == "insert") {
        return true;
    }
    return false;
}