/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 04-12-2015 10:23:42
 * Name: echo_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_ECHOER__PROXY__ECHO_SERVICE_PROXY_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_ECHOER__PROXY__ECHO_SERVICE_PROXY_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "../echo_service.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace echoer {
class RequestMessage;
class ResponseMessage;
namespace proxy {
  class EchoServiceProxy : public ::ir::ntnaeem::hottentot::examples::echoer::EchoService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    EchoServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~EchoServiceProxy() {}
  public:
ResponseMessage* EchoMessage(RequestMessage *req);
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE echoer
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif