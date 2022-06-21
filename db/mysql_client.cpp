//
// Created by ByteDance on 2022/5/22.
//

#include "mysql_client.h"
#include "conf/conf.h"
#include "log/elog.h"
#include <mysql/mysql.h>
using namespace ::rpc::conf::db;

namespace rpc {namespace db {
        Mysql_Base::Mysql_Base() {
            mysql_init(&con);
            if (!connect()) {
            } else {
                log_e("mysql_real_connect error");
            }
            mysql_autocommit(&con,0);
        }
        
        int Mysql_Base::connect() {
            return !mysql_real_connect(&con, MysqlConf::host.c_str(), MysqlConf::user_name.c_str(), MysqlConf::password.c_str(), MysqlConf::db_name.c_str(), 0, NULL, 0);
        }
        
        int Mysql_Base::query(std::string sql) {
            log_i(("exec " + sql).c_str());
            return mysql_query(&con, sql.c_str());
        }
        
        int Mysql_Base::begin() {
            log_i("begin;");
            return query("BEGIN;");
        }
        
        int Mysql_Base::delete_savepoint(std::string savepoint) {
            return query("RELEASE SAVEPOINT " + savepoint + ";");
        }
        
        int Mysql_Base::save_point(std::string savepoint) {
            return query("SAVEPOINT " + savepoint + ";");
        }
        
        int Mysql_Base::exec(std::string func) {
            if (func == "commit") {
                return commit();
            } else if (func == "rollback") {
                return rollback();
            } else {
                return 1;
            }
        }
        
        int Mysql_Base::rollback() {
            return query("ROLLBACK;");
        }
        
        int Mysql_Base::commit() {
            log_i("commit;");
            return query("COMMIT;");
        }
        
        Mysql_Base::~Mysql_Base() {
            mysql_close(&con);
        }
        
        int MysqlClient::put(std::string key, std::string value, std::string func_call) {
            std::string sql;
            if (is_insert(func_call)) {
                sql = "INSERT INTO infoTable(k, v) VALUES('" + key + "','" + value + "')";
            } else {
                sql = "UPDATE infoTable SET v='" + value + "' where k='" + key + "'";
            }
            if (query(sql)) {
                std::cout << "exec sql=" + sql + " err" << std::endl;
                return 1;
            }
            return 0;
        }
        
        std::string MysqlClient::get(std::string key) {
            log_i(("get key=" + key).c_str());
            std::string sql = "SELECT v FROM infoTable WHERE k='" + key + "'";
            if (query(sql)) {
                std::cout << "exec sql=" + sql + " err" << std::endl;
                return "";
            }
            mysql_res res(get_con());
            if (res.get_next_row()) {
                log_i(("key=" + key + " is not exists").c_str());
                return "";
            }
            
            return res.get_row()[0];
        }
        
        int MysqlClient::del(std::string key) {
            std::string sql = "DELETE FROM infoTable WHERE k='" + key + "'";
            if (query(sql)) {
                std::cout << "exec sql=" + sql + " err" << std::endl;
                return 1;
            }
            return 0;
        }
        
        bool MysqlClient::check_key(std::string key) {  //后续加锁
            return this->get(key) != "";
        }
        
    }}