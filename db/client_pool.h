//
// Created by ByteDance on 2022/6/4.
//

#ifndef SLAVE_RPC_DBCLIENTPOOL_H
#define SLAVE_RPC_DBCLIENTPOOL_H

#include "mysql_client.h"
#include "thread/mutex.h"
#include "conf/dbconf.h"
#include <list>
#include <memory>
#include <algorithm>

using namespace rpc::thread;
using namespace rpc::conf::db;
using namespace rpc::db;

namespace rpc {
    template<class T>
    class DbClientPool : public Noncopyable {
    public:
        ~DbClientPool() {
            idle.clear();
            busy.clear();
        }
        std::shared_ptr<MysqlClient> getClient() {
            Mutex::Lock lock(mutex);
            std::shared_ptr<MysqlClient> client = idle.back();
            idle.pop_back();
            busy.push_back(client);
            return client;
        }
        void delClient(std::shared_ptr<MysqlClient> client) {
            Mutex::Lock lock(mutex);
            busy.erase(find(busy.begin(), busy.end(), client));
            idle.push_back(client);
        }

        std::shared_ptr<DbClientPool> get() {
            
        }
        
    private:
        DbClientPool() {
            for (int i = 0; i < MysqlConf::mysql_client_count; i++) {
                idle.push_back(std::shared_ptr<MysqlClient>(new MysqlClient()));
            }
        }
        std::list<std::shared_ptr<MysqlClient>> idle, busy; //空闲， 被使用
        Mutex mutex;
    };
}}

#endif //SLAVE_RPC_DBCLIENTPOOL_H
