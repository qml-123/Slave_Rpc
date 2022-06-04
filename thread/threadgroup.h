//
// Created by ByteDance on 2022/5/25.
//

#ifndef SLAVE_RPC_THREADGROUP_H
#define SLAVE_RPC_THREADGROUP_H

#include "threadpool.h"
#include <iostream>
#include <memory>
namespace rpc {namespace thread {
        class ThreadGroup : public ThreadPool{
        public:
            typedef std::shared_ptr<ThreadGroup> ptr;

            ThreadGroup(size_t threads = 1, const std::string& name = "");
            
            ~ThreadGroup();

        protected:
            void tickle() override;
            void run() override;
            
        private:
            int m_epfd = 0;
            int m_tickleFds[2];
            
            MutexType m_mutex;
        };
        
    }
}

#endif //SLAVE_RPC_THREADGROUP_H
