/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Slave_H
#define Slave_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "slave_types.h"

namespace rpc { namespace slave {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class SlaveIf {
 public:
  virtual ~SlaveIf() {}
  virtual void Rsync(RsyncResponse& _return, const RsyncRequest& rsyncRequest) = 0;
  virtual void Try(TryResponse& _return, const TryRequest& tryRequest) = 0;
  virtual void Finish(FinishResponse& _return, const FinishRequest& finishRequest) = 0;
  virtual void Get( ::rpc::master::GetResponse& _return, const  ::rpc::master::GetRequest& getRequest) = 0;
  virtual void Set( ::rpc::master::SetResponse& _return, const  ::rpc::master::SetRequest& setRequest) = 0;
  virtual void Del( ::rpc::master::DelResponse& _return, const  ::rpc::master::DelRequest& delRequest) = 0;
};

class SlaveIfFactory {
 public:
  typedef SlaveIf Handler;

  virtual ~SlaveIfFactory() {}

  virtual SlaveIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SlaveIf* /* handler */) = 0;
};

class SlaveIfSingletonFactory : virtual public SlaveIfFactory {
 public:
  SlaveIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<SlaveIf>& iface) : iface_(iface) {}
  virtual ~SlaveIfSingletonFactory() {}

  virtual SlaveIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SlaveIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<SlaveIf> iface_;
};

class SlaveNull : virtual public SlaveIf {
 public:
  virtual ~SlaveNull() {}
  void Rsync(RsyncResponse& /* _return */, const RsyncRequest& /* rsyncRequest */) {
    return;
  }
  void Try(TryResponse& /* _return */, const TryRequest& /* tryRequest */) {
    return;
  }
  void Finish(FinishResponse& /* _return */, const FinishRequest& /* finishRequest */) {
    return;
  }
  void Get( ::rpc::master::GetResponse& /* _return */, const  ::rpc::master::GetRequest& /* getRequest */) {
    return;
  }
  void Set( ::rpc::master::SetResponse& /* _return */, const  ::rpc::master::SetRequest& /* setRequest */) {
    return;
  }
  void Del( ::rpc::master::DelResponse& /* _return */, const  ::rpc::master::DelRequest& /* delRequest */) {
    return;
  }
};

typedef struct _Slave_Rsync_args__isset {
  _Slave_Rsync_args__isset() : rsyncRequest(false) {}
  bool rsyncRequest :1;
} _Slave_Rsync_args__isset;

class Slave_Rsync_args {
 public:

  Slave_Rsync_args(const Slave_Rsync_args&);
  Slave_Rsync_args& operator=(const Slave_Rsync_args&);
  Slave_Rsync_args() {
  }

  virtual ~Slave_Rsync_args() throw();
  RsyncRequest rsyncRequest;

  _Slave_Rsync_args__isset __isset;

  void __set_rsyncRequest(const RsyncRequest& val);

  bool operator == (const Slave_Rsync_args & rhs) const
  {
    if (!(rsyncRequest == rhs.rsyncRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Rsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Rsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Rsync_pargs {
 public:


  virtual ~Slave_Rsync_pargs() throw();
  const RsyncRequest* rsyncRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Rsync_result__isset {
  _Slave_Rsync_result__isset() : success(false) {}
  bool success :1;
} _Slave_Rsync_result__isset;

class Slave_Rsync_result {
 public:

  Slave_Rsync_result(const Slave_Rsync_result&);
  Slave_Rsync_result& operator=(const Slave_Rsync_result&);
  Slave_Rsync_result() {
  }

  virtual ~Slave_Rsync_result() throw();
  RsyncResponse success;

  _Slave_Rsync_result__isset __isset;

  void __set_success(const RsyncResponse& val);

  bool operator == (const Slave_Rsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Rsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Rsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Rsync_presult__isset {
  _Slave_Rsync_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Rsync_presult__isset;

class Slave_Rsync_presult {
 public:


  virtual ~Slave_Rsync_presult() throw();
  RsyncResponse* success;

  _Slave_Rsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Slave_Try_args__isset {
  _Slave_Try_args__isset() : tryRequest(false) {}
  bool tryRequest :1;
} _Slave_Try_args__isset;

class Slave_Try_args {
 public:

  Slave_Try_args(const Slave_Try_args&);
  Slave_Try_args& operator=(const Slave_Try_args&);
  Slave_Try_args() {
  }

  virtual ~Slave_Try_args() throw();
  TryRequest tryRequest;

  _Slave_Try_args__isset __isset;

  void __set_tryRequest(const TryRequest& val);

  bool operator == (const Slave_Try_args & rhs) const
  {
    if (!(tryRequest == rhs.tryRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Try_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Try_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Try_pargs {
 public:


  virtual ~Slave_Try_pargs() throw();
  const TryRequest* tryRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Try_result__isset {
  _Slave_Try_result__isset() : success(false) {}
  bool success :1;
} _Slave_Try_result__isset;

class Slave_Try_result {
 public:

  Slave_Try_result(const Slave_Try_result&);
  Slave_Try_result& operator=(const Slave_Try_result&);
  Slave_Try_result() {
  }

  virtual ~Slave_Try_result() throw();
  TryResponse success;

  _Slave_Try_result__isset __isset;

  void __set_success(const TryResponse& val);

  bool operator == (const Slave_Try_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Try_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Try_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Try_presult__isset {
  _Slave_Try_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Try_presult__isset;

class Slave_Try_presult {
 public:


  virtual ~Slave_Try_presult() throw();
  TryResponse* success;

  _Slave_Try_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Slave_Finish_args__isset {
  _Slave_Finish_args__isset() : finishRequest(false) {}
  bool finishRequest :1;
} _Slave_Finish_args__isset;

class Slave_Finish_args {
 public:

  Slave_Finish_args(const Slave_Finish_args&);
  Slave_Finish_args& operator=(const Slave_Finish_args&);
  Slave_Finish_args() {
  }

  virtual ~Slave_Finish_args() throw();
  FinishRequest finishRequest;

  _Slave_Finish_args__isset __isset;

  void __set_finishRequest(const FinishRequest& val);

  bool operator == (const Slave_Finish_args & rhs) const
  {
    if (!(finishRequest == rhs.finishRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Finish_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Finish_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Finish_pargs {
 public:


  virtual ~Slave_Finish_pargs() throw();
  const FinishRequest* finishRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Finish_result__isset {
  _Slave_Finish_result__isset() : success(false) {}
  bool success :1;
} _Slave_Finish_result__isset;

class Slave_Finish_result {
 public:

  Slave_Finish_result(const Slave_Finish_result&);
  Slave_Finish_result& operator=(const Slave_Finish_result&);
  Slave_Finish_result() {
  }

  virtual ~Slave_Finish_result() throw();
  FinishResponse success;

  _Slave_Finish_result__isset __isset;

  void __set_success(const FinishResponse& val);

  bool operator == (const Slave_Finish_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Finish_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Finish_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Finish_presult__isset {
  _Slave_Finish_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Finish_presult__isset;

class Slave_Finish_presult {
 public:


  virtual ~Slave_Finish_presult() throw();
  FinishResponse* success;

  _Slave_Finish_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Slave_Get_args__isset {
  _Slave_Get_args__isset() : getRequest(false) {}
  bool getRequest :1;
} _Slave_Get_args__isset;

class Slave_Get_args {
 public:

  Slave_Get_args(const Slave_Get_args&);
  Slave_Get_args& operator=(const Slave_Get_args&);
  Slave_Get_args() {
  }

  virtual ~Slave_Get_args() throw();
   ::rpc::master::GetRequest getRequest;

  _Slave_Get_args__isset __isset;

  void __set_getRequest(const  ::rpc::master::GetRequest& val);

  bool operator == (const Slave_Get_args & rhs) const
  {
    if (!(getRequest == rhs.getRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Get_pargs {
 public:


  virtual ~Slave_Get_pargs() throw();
  const  ::rpc::master::GetRequest* getRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Get_result__isset {
  _Slave_Get_result__isset() : success(false) {}
  bool success :1;
} _Slave_Get_result__isset;

class Slave_Get_result {
 public:

  Slave_Get_result(const Slave_Get_result&);
  Slave_Get_result& operator=(const Slave_Get_result&);
  Slave_Get_result() {
  }

  virtual ~Slave_Get_result() throw();
   ::rpc::master::GetResponse success;

  _Slave_Get_result__isset __isset;

  void __set_success(const  ::rpc::master::GetResponse& val);

  bool operator == (const Slave_Get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Get_presult__isset {
  _Slave_Get_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Get_presult__isset;

class Slave_Get_presult {
 public:


  virtual ~Slave_Get_presult() throw();
   ::rpc::master::GetResponse* success;

  _Slave_Get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Slave_Set_args__isset {
  _Slave_Set_args__isset() : setRequest(false) {}
  bool setRequest :1;
} _Slave_Set_args__isset;

class Slave_Set_args {
 public:

  Slave_Set_args(const Slave_Set_args&);
  Slave_Set_args& operator=(const Slave_Set_args&);
  Slave_Set_args() {
  }

  virtual ~Slave_Set_args() throw();
   ::rpc::master::SetRequest setRequest;

  _Slave_Set_args__isset __isset;

  void __set_setRequest(const  ::rpc::master::SetRequest& val);

  bool operator == (const Slave_Set_args & rhs) const
  {
    if (!(setRequest == rhs.setRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Set_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Set_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Set_pargs {
 public:


  virtual ~Slave_Set_pargs() throw();
  const  ::rpc::master::SetRequest* setRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Set_result__isset {
  _Slave_Set_result__isset() : success(false) {}
  bool success :1;
} _Slave_Set_result__isset;

class Slave_Set_result {
 public:

  Slave_Set_result(const Slave_Set_result&);
  Slave_Set_result& operator=(const Slave_Set_result&);
  Slave_Set_result() {
  }

  virtual ~Slave_Set_result() throw();
   ::rpc::master::SetResponse success;

  _Slave_Set_result__isset __isset;

  void __set_success(const  ::rpc::master::SetResponse& val);

  bool operator == (const Slave_Set_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Set_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Set_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Set_presult__isset {
  _Slave_Set_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Set_presult__isset;

class Slave_Set_presult {
 public:


  virtual ~Slave_Set_presult() throw();
   ::rpc::master::SetResponse* success;

  _Slave_Set_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Slave_Del_args__isset {
  _Slave_Del_args__isset() : delRequest(false) {}
  bool delRequest :1;
} _Slave_Del_args__isset;

class Slave_Del_args {
 public:

  Slave_Del_args(const Slave_Del_args&);
  Slave_Del_args& operator=(const Slave_Del_args&);
  Slave_Del_args() {
  }

  virtual ~Slave_Del_args() throw();
   ::rpc::master::DelRequest delRequest;

  _Slave_Del_args__isset __isset;

  void __set_delRequest(const  ::rpc::master::DelRequest& val);

  bool operator == (const Slave_Del_args & rhs) const
  {
    if (!(delRequest == rhs.delRequest))
      return false;
    return true;
  }
  bool operator != (const Slave_Del_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Del_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Slave_Del_pargs {
 public:


  virtual ~Slave_Del_pargs() throw();
  const  ::rpc::master::DelRequest* delRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Del_result__isset {
  _Slave_Del_result__isset() : success(false) {}
  bool success :1;
} _Slave_Del_result__isset;

class Slave_Del_result {
 public:

  Slave_Del_result(const Slave_Del_result&);
  Slave_Del_result& operator=(const Slave_Del_result&);
  Slave_Del_result() {
  }

  virtual ~Slave_Del_result() throw();
   ::rpc::master::DelResponse success;

  _Slave_Del_result__isset __isset;

  void __set_success(const  ::rpc::master::DelResponse& val);

  bool operator == (const Slave_Del_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Slave_Del_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Slave_Del_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Slave_Del_presult__isset {
  _Slave_Del_presult__isset() : success(false) {}
  bool success :1;
} _Slave_Del_presult__isset;

class Slave_Del_presult {
 public:


  virtual ~Slave_Del_presult() throw();
   ::rpc::master::DelResponse* success;

  _Slave_Del_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SlaveClient : virtual public SlaveIf {
 public:
  SlaveClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SlaveClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Rsync(RsyncResponse& _return, const RsyncRequest& rsyncRequest);
  void send_Rsync(const RsyncRequest& rsyncRequest);
  void recv_Rsync(RsyncResponse& _return);
  void Try(TryResponse& _return, const TryRequest& tryRequest);
  void send_Try(const TryRequest& tryRequest);
  void recv_Try(TryResponse& _return);
  void Finish(FinishResponse& _return, const FinishRequest& finishRequest);
  void send_Finish(const FinishRequest& finishRequest);
  void recv_Finish(FinishResponse& _return);
  void Get( ::rpc::master::GetResponse& _return, const  ::rpc::master::GetRequest& getRequest);
  void send_Get(const  ::rpc::master::GetRequest& getRequest);
  void recv_Get( ::rpc::master::GetResponse& _return);
  void Set( ::rpc::master::SetResponse& _return, const  ::rpc::master::SetRequest& setRequest);
  void send_Set(const  ::rpc::master::SetRequest& setRequest);
  void recv_Set( ::rpc::master::SetResponse& _return);
  void Del( ::rpc::master::DelResponse& _return, const  ::rpc::master::DelRequest& delRequest);
  void send_Del(const  ::rpc::master::DelRequest& delRequest);
  void recv_Del( ::rpc::master::DelResponse& _return);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SlaveProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<SlaveIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SlaveProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_Rsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Try(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Finish(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Set(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Del(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SlaveProcessor(::apache::thrift::stdcxx::shared_ptr<SlaveIf> iface) :
    iface_(iface) {
    processMap_["Rsync"] = &SlaveProcessor::process_Rsync;
    processMap_["Try"] = &SlaveProcessor::process_Try;
    processMap_["Finish"] = &SlaveProcessor::process_Finish;
    processMap_["Get"] = &SlaveProcessor::process_Get;
    processMap_["Set"] = &SlaveProcessor::process_Set;
    processMap_["Del"] = &SlaveProcessor::process_Del;
  }

  virtual ~SlaveProcessor() {}
};

class SlaveProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SlaveProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< SlaveIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< SlaveIfFactory > handlerFactory_;
};

class SlaveMultiface : virtual public SlaveIf {
 public:
  SlaveMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<SlaveIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SlaveMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<SlaveIf> > ifaces_;
  SlaveMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<SlaveIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void Rsync(RsyncResponse& _return, const RsyncRequest& rsyncRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Rsync(_return, rsyncRequest);
    }
    ifaces_[i]->Rsync(_return, rsyncRequest);
    return;
  }

  void Try(TryResponse& _return, const TryRequest& tryRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Try(_return, tryRequest);
    }
    ifaces_[i]->Try(_return, tryRequest);
    return;
  }

  void Finish(FinishResponse& _return, const FinishRequest& finishRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Finish(_return, finishRequest);
    }
    ifaces_[i]->Finish(_return, finishRequest);
    return;
  }

  void Get( ::rpc::master::GetResponse& _return, const  ::rpc::master::GetRequest& getRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Get(_return, getRequest);
    }
    ifaces_[i]->Get(_return, getRequest);
    return;
  }

  void Set( ::rpc::master::SetResponse& _return, const  ::rpc::master::SetRequest& setRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Set(_return, setRequest);
    }
    ifaces_[i]->Set(_return, setRequest);
    return;
  }

  void Del( ::rpc::master::DelResponse& _return, const  ::rpc::master::DelRequest& delRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Del(_return, delRequest);
    }
    ifaces_[i]->Del(_return, delRequest);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class SlaveConcurrentClient : virtual public SlaveIf {
 public:
  SlaveConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SlaveConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void Rsync(RsyncResponse& _return, const RsyncRequest& rsyncRequest);
  int32_t send_Rsync(const RsyncRequest& rsyncRequest);
  void recv_Rsync(RsyncResponse& _return, const int32_t seqid);
  void Try(TryResponse& _return, const TryRequest& tryRequest);
  int32_t send_Try(const TryRequest& tryRequest);
  void recv_Try(TryResponse& _return, const int32_t seqid);
  void Finish(FinishResponse& _return, const FinishRequest& finishRequest);
  int32_t send_Finish(const FinishRequest& finishRequest);
  void recv_Finish(FinishResponse& _return, const int32_t seqid);
  void Get( ::rpc::master::GetResponse& _return, const  ::rpc::master::GetRequest& getRequest);
  int32_t send_Get(const  ::rpc::master::GetRequest& getRequest);
  void recv_Get( ::rpc::master::GetResponse& _return, const int32_t seqid);
  void Set( ::rpc::master::SetResponse& _return, const  ::rpc::master::SetRequest& setRequest);
  int32_t send_Set(const  ::rpc::master::SetRequest& setRequest);
  void recv_Set( ::rpc::master::SetResponse& _return, const int32_t seqid);
  void Del( ::rpc::master::DelResponse& _return, const  ::rpc::master::DelRequest& delRequest);
  int32_t send_Del(const  ::rpc::master::DelRequest& delRequest);
  void recv_Del( ::rpc::master::DelResponse& _return, const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#endif
