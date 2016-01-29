/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 16-01-2016 01:33:10
 * Name: echo_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <sstream>

#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>

#include "echo_service_impl.h"

#include "../gen/request_message.h"
#include "../gen/response_message.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace echoer {
  void
  EchoServiceImpl::OnInit() {
    // TODO: Called when service is initializing.
  }
  void
  EchoServiceImpl::OnShutdown() {
    // TODO: Called when service is shutting down.
  }
  void
  EchoServiceImpl::EchoMessage(::ir::ntnaeem::hottentot::examples::echoer::RequestMessage &req, ::ir::ntnaeem::hottentot::examples::echoer::ResponseMessage &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "EchoServiceImpl::EchoMessage() is called." << std::endl;
    }
    std::stringstream ss;
    ss << "Hello " << req.GetName().Serialize(NULL) << "\r\n";
    ::naeem::hottentot::runtime::types::Utf8String responseString(ss.str().c_str());
    out.SetMessage(responseString);
  }
} // END OF NAMESPACE echoer
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir