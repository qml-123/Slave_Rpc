//
// Created by ByteDance on 2022/5/24.
//

#include "threadpool.h"
#include "conf/conf.h"
#include "thread.h"

namespace rpc {namespace thread{
    
    static thread_local ThreadPool* t_threadPool = nullptr;
//    static thread_local Thread* t_thread = nullptr;
    
    ThreadPool::ThreadPool(size_t threads, const std::string& name)
        :m_name(name) {
        QML_ASSERT(threads > 0);
    
        QML_ASSERT(GetThis() == nullptr);
        t_threadPool = this;
 
        m_threadCount = threads;
        m_idleThreadCount = threads;
    }
    
    ThreadPool::~ThreadPool() {
        QML_ASSERT(m_stopping);
        if (GetThis() == this) {
            t_threadPool = nullptr;
        }
    }
    
    ThreadPool* ThreadPool::GetThis() {
        return t_threadPool;
    }
    
    void ThreadPool::start() {
        MutexType::Lock lock(m_mutex);
        if (!m_stopping) {
            return;
        }
        m_stopping = false;
        QML_ASSERT(m_threads.empty());
        
        m_threads.resize(m_threadCount);
        for (size_t i = 0; i < m_threadCount; i++) {
            m_threads[i].reset(new Thread(std::bind(&ThreadPool::run, this), m_name + "_" + std::to_string(i + 1)));
            m_threadIds.push_back(m_threads[i]->getId());
        }
    }
    
    void ThreadPool::stop() {
        if (stopping()) {
            return;
        }
        m_stopping = true;
        for (size_t i = 0; i < m_threadCount; ++i) {
            tickle();
        }
        sleep(5);
    }
    
    void ThreadPool::setThis() {
        t_threadPool = this;
    }
    
    void ThreadPool::run() {
    
    }
    
    void ThreadPool::tickle() {
    
    }
}}