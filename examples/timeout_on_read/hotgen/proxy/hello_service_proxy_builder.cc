/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 25-03-2016 03:14:16
 * Name: hello_service_proxy_builder.cc
 * Description:
 *   This file contains implementation of the proxy builder class.
 ******************************************************************/

#include "hello_service_proxy_builder.h"
#include "hello_service_proxy.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace timeout_on_read {
namespace proxy {
  HelloService*
  HelloServiceProxyBuilder::Create(std::string host, uint32_t port) {
    return new HelloServiceProxy(host, port);
  }
  void
  HelloServiceProxyBuilder::Destroy(HelloService *service) {
    delete service;
  }
} // END OF NAMESPACE proxy
} // END OF NAMESPACE timeout_on_read
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir