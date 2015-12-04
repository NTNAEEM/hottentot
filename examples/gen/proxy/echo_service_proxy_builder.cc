/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 04-12-2015 10:23:42
 * Name: echo_service_proxy_builder.cc
 * Description:
 *   This file contains implementation of the proxy builder class.
 ******************************************************************/

#include "echo_service_proxy_builder.h"
#include "echo_service_proxy.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace echoer {
namespace proxy {
  EchoService*
  EchoServiceProxyBuilder::Create(std::string host, uint32_t port) {
    return new EchoServiceProxy(host, port);
  }
  void
  EchoServiceProxyBuilder::Destroy(EchoService *service) {
    delete service;
  }
} // END OF NAMESPACE proxy
} // END OF NAMESPACE echoer
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir