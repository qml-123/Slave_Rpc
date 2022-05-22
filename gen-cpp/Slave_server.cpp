// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Slave.h"
#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>

#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>

#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TNonblockingServerSocket.h>

#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using namespace  ::rpc::slave;

class SlaveHandler : virtual public SlaveIf {
public:
    SlaveHandler() {
        // Your initialization goes here
    }
    
    void Rsync(RsyncResponse& _return, const RsyncRequest& RsyncRequest) {
        // Your implementation goes here
        printf("Rsync\n");
    }
    
    void Try(TryResponse& _return, const TryRequest& tryRequest) {
        // Your implementation goes here
        printf("Try\n");
    }
    
    void Get( ::rpc::master::GetResponse& _return, const  ::rpc::master::GetRequest& getRequest) {
        // Your implementation goes here
        printf("Get\n");
    }
    
    void Set( ::rpc::master::SetResponse& _return, const  ::rpc::master::SetRequest& setRequest) {
        // Your implementation goes here
        printf("Set\n");
    }
    
    void Del( ::rpc::master::DelResponse& _return, const  ::rpc::master::DelRequest& delRequest) {
        // Your implementation goes here
        printf("Del\n");
    }
    
};

int main(int argc, char **argv) {
    int port = 9091;
    ::apache::thrift::stdcxx::shared_ptr<SlaveHandler> handler(new SlaveHandler());
    ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new SlaveProcessor(handler));
    ::apache::thrift::stdcxx::shared_ptr<TNonblockingServerSocket> serverTransport(new TNonblockingServerSocket(port));
    ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    ::apache::thrift::stdcxx::shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    ::apache::thrift::stdcxx::shared_ptr<PosixThreadFactory> threadFactory(new PosixThreadFactory());
    
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    
    TNonblockingServer server(processor, protocolFactory, serverTransport, threadManager);
    server.serve();
    return 0;
}

