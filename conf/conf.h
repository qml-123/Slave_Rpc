//
// Created by ByteDance on 2022/5/22.
//

#ifndef MASTER_RPC_CONF_H
#define MASTER_RPC_CONF_H
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <string.h>
#include <sstream>
#include <execinfo.h>
#include <unistd.h>


bool is_insert(std::string func_call);
void print(const std::string& st);
#endif //MASTER_RPC_CONF_H
