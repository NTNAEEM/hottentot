/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 02-05-2016 05:18:41
 * Name: authenticate_service_proxy_builder.cc
 * Description:
 *   This file contains implementation of the proxy builder class.
 ******************************************************************/

#include "authenticate_service_proxy_builder.h"
#include "authenticate_service_proxy.h"


namespace naeem {
namespace hottentot {
namespace examples {
namespace auth {
namespace proxy {
  AuthenticateService*
  AuthenticateServiceProxyBuilder::Create(std::string host, uint32_t port) {
    return new AuthenticateServiceProxy(host, port);
  }
  void
  AuthenticateServiceProxyBuilder::Destroy(AuthenticateService *service) {
    delete service;
  }
} // END OF NAMESPACE proxy
} // END OF NAMESPACE auth
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE naeem