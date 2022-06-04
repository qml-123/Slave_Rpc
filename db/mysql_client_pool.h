//
// Created by ByteDance on 2022/6/4.
//

#ifndef SLAVE_RPC_MYSQL_CLIENT_POOL_H
#define SLAVE_RPC_MYSQL_CLIENT_POOL_H

#include "../conf/client_pool.h"
#include "mysql_client.h"

using namespace ::rpc::conf;
using namespace ::rpc::conf::db;

namespace rpc{namespace db{
    class MysqlClientPool : public ClientPool<MysqlClient> {
    public:
        
        static std::shared_ptr<MysqlClientPool> get() {
            return instance;
        }
        
        void addClient() {
            idle.push_front(std::shared_ptr<MysqlClient> (new MysqlClient));
        }
        
        static std::shared_ptr<MysqlClientPool> instance;
    private:
        MysqlClientPool() {
            for (int i = 0; i < MysqlConf::mysql_client_count; i++) {
                idle.push_back(std::shared_ptr<MysqlClient> (new MysqlClient));
            }
        }
    };
    
    std::shared_ptr<MysqlClientPool> MysqlClientPool::instance(new MysqlClientPool());
}}

#endif //SLAVE_RPC_MYSQL_CLIENT_POOL_H
