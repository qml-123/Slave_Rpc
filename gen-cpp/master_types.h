/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef master_TYPES_H
#define master_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>


namespace rpc { namespace master {

class GetRequest;

class GetResponse;

class SetRequest;

class SetResponse;

class DelRequest;

class DelResponse;

typedef struct _GetRequest__isset {
  _GetRequest__isset() : key(false) {}
  bool key :1;
} _GetRequest__isset;

class GetRequest : public virtual ::apache::thrift::TBase {
 public:

  GetRequest(const GetRequest&);
  GetRequest& operator=(const GetRequest&);
  GetRequest() : key() {
  }

  virtual ~GetRequest() throw();
  std::string key;

  _GetRequest__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const GetRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const GetRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GetRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GetRequest &a, GetRequest &b);

std::ostream& operator<<(std::ostream& out, const GetRequest& obj);

typedef struct _GetResponse__isset {
  _GetResponse__isset() : value(false), message(false), connection_id(false) {}
  bool value :1;
  bool message :1;
  bool connection_id :1;
} _GetResponse__isset;

class GetResponse : public virtual ::apache::thrift::TBase {
 public:

  GetResponse(const GetResponse&);
  GetResponse& operator=(const GetResponse&);
  GetResponse() : value(), message(), connection_id(0) {
  }

  virtual ~GetResponse() throw();
  std::string value;
  std::string message;
  int64_t connection_id;

  _GetResponse__isset __isset;

  void __set_value(const std::string& val);

  void __set_message(const std::string& val);

  void __set_connection_id(const int64_t val);

  bool operator == (const GetResponse & rhs) const
  {
    if (!(value == rhs.value))
      return false;
    if (!(message == rhs.message))
      return false;
    if (!(connection_id == rhs.connection_id))
      return false;
    return true;
  }
  bool operator != (const GetResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GetResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GetResponse &a, GetResponse &b);

std::ostream& operator<<(std::ostream& out, const GetResponse& obj);

typedef struct _SetRequest__isset {
  _SetRequest__isset() : key(false), value(false), func_call(false) {}
  bool key :1;
  bool value :1;
  bool func_call :1;
} _SetRequest__isset;

class SetRequest : public virtual ::apache::thrift::TBase {
 public:

  SetRequest(const SetRequest&);
  SetRequest& operator=(const SetRequest&);
  SetRequest() : key(), value(), func_call() {
  }

  virtual ~SetRequest() throw();
  std::string key;
  std::string value;
  std::string func_call;

  _SetRequest__isset __isset;

  void __set_key(const std::string& val);

  void __set_value(const std::string& val);

  void __set_func_call(const std::string& val);

  bool operator == (const SetRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    if (!(func_call == rhs.func_call))
      return false;
    return true;
  }
  bool operator != (const SetRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SetRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SetRequest &a, SetRequest &b);

std::ostream& operator<<(std::ostream& out, const SetRequest& obj);

typedef struct _SetResponse__isset {
  _SetResponse__isset() : connection_id(false), message(false) {}
  bool connection_id :1;
  bool message :1;
} _SetResponse__isset;

class SetResponse : public virtual ::apache::thrift::TBase {
 public:

  SetResponse(const SetResponse&);
  SetResponse& operator=(const SetResponse&);
  SetResponse() : connection_id(0), message() {
  }

  virtual ~SetResponse() throw();
  int64_t connection_id;
  std::string message;

  _SetResponse__isset __isset;

  void __set_connection_id(const int64_t val);

  void __set_message(const std::string& val);

  bool operator == (const SetResponse & rhs) const
  {
    if (!(connection_id == rhs.connection_id))
      return false;
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const SetResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SetResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SetResponse &a, SetResponse &b);

std::ostream& operator<<(std::ostream& out, const SetResponse& obj);

typedef struct _DelRequest__isset {
  _DelRequest__isset() : key(false) {}
  bool key :1;
} _DelRequest__isset;

class DelRequest : public virtual ::apache::thrift::TBase {
 public:

  DelRequest(const DelRequest&);
  DelRequest& operator=(const DelRequest&);
  DelRequest() : key() {
  }

  virtual ~DelRequest() throw();
  std::string key;

  _DelRequest__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const DelRequest & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const DelRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DelRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DelRequest &a, DelRequest &b);

std::ostream& operator<<(std::ostream& out, const DelRequest& obj);

typedef struct _DelResponse__isset {
  _DelResponse__isset() : connection_id(false), message(false) {}
  bool connection_id :1;
  bool message :1;
} _DelResponse__isset;

class DelResponse : public virtual ::apache::thrift::TBase {
 public:

  DelResponse(const DelResponse&);
  DelResponse& operator=(const DelResponse&);
  DelResponse() : connection_id(0), message() {
  }

  virtual ~DelResponse() throw();
  int64_t connection_id;
  std::string message;

  _DelResponse__isset __isset;

  void __set_connection_id(const int64_t val);

  void __set_message(const std::string& val);

  bool operator == (const DelResponse & rhs) const
  {
    if (!(connection_id == rhs.connection_id))
      return false;
    if (!(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const DelResponse &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DelResponse & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DelResponse &a, DelResponse &b);

std::ostream& operator<<(std::ostream& out, const DelResponse& obj);

}} // namespace

#endif
