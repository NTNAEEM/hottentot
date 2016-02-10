/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 10-02-2016 11:35:21
 * Name: phone_manager_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_SERVICES__PROXY__PHONE_MANAGER_SERVICE_PROXY_H_
#define _IR_NTNAEEM_SERVICES__PROXY__PHONE_MANAGER_SERVICE_PROXY_H_

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "phone_manager_service.h"


namespace ir {
namespace ntnaeem {
namespace services {
class Person;
class Phone;
namespace proxy {
  class PhoneManagerServiceProxy : public PhoneManagerService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    PhoneManagerServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~PhoneManagerServiceProxy() {}
  public:
    virtual void GetPhonebook(
      ::ir::ntnaeem::services::map<Person,list<Phone>> &out
    );
    virtual void AddEntry(
      ::ir::ntnaeem::services::Person &person, 
      ::ir::ntnaeem::services::Phone &phone, 
      ::naeem::hottentot::runtime::types::Date &d
    );
    virtual void FFF(
      ::naeem::hottentot::runtime::types::Utf8String &abc, 
      ::ir::ntnaeem::services::map<list<Person>,string> &out
    );
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE services
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif