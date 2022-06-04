//
// Created by ByteDance on 2022/5/24.
//

#ifndef MASTER_RPC_THREADPOOL_H
#define MASTER_RPC_THREADPOOL_H

#include "noncopyable.h"
#include "mutex.h"
#include "thread.h"
#include "../conf/conf.h"
#include <functional>
#include <vector>
#include <iostream>
#include <atomic>
#include <queue>

namespace rpc{namespace thread{
        class ThreadPool : Noncopyable{
        public:
            struct ThreadTask {
                //执行函数
                std::function<void(void*, const void*)> cb;
                //thread id
                int thread;
                const void* request;
                void* response;
                
                ThreadTask(std::function<void(void*, const void*)> f, int thr, const void* _request, void* _response)
                        : cb(f), thread(thr), request(_request), response(_response) {
            
                }
        
                ThreadTask()
                        : thread(-1), request(nullptr), response(nullptr) {
                }
            };
            
        public:
            typedef std::shared_ptr<ThreadPool> ptr;
            typedef Mutex MutexType;
            
            ThreadPool(size_t threads = 1, const std::string& name = "");
            
            virtual ~ThreadPool();
            
            const std::string& getName()const {return m_name;}
            
            static ThreadPool* GetThis();
            
            virtual void start();
            
            virtual void stop();
    
            virtual void addTask(ThreadTask threadTask) {m_taskQueue.push(threadTask); m_taskCount++; tickle(); }
    
            bool hasIdleThreads() {return m_idleThreadCount > 0;}
            
        protected:
            /*
             *  通知任务到达
             */
            virtual void tickle();
            
            //调度
            virtual void run();
            
            
            //是否可以停止
            virtual bool stopping() {return m_stopping; }
            
            
            void setThis();
            
            bool hasTaskCount() {return m_taskCount > 0; }
            
            ThreadTask getTask() {
                ThreadTask ret = m_taskQueue.front();
                m_taskQueue.pop();
                m_taskCount--;
                return ret;
            }
            //idle thread count 空闲
            std::atomic<size_t> m_idleThreadCount = {0};
            
        private:
            // mutex
            MutexType m_mutex;
            //线程池
            std::vector<Thread::ptr> m_threads;
            //task queue
            std::queue<ThreadTask> m_taskQueue;
            
            std::string m_name;
            
            //thread id
            std::vector<int> m_threadIds;
            
            Thread::ptr m_rootThread;
            size_t m_threadCount = 0;
            
            //task count
            std::atomic<size_t> m_taskCount = {0};
            //是否停止
            bool m_stopping = true;
            //主线程id
            int m_rootThreadId = 0;
        };
    }
}


#endif //MASTER_RPC_THREADPOOL_H
