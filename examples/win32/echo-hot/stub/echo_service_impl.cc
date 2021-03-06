/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 01-02-2016 01:45:06
 * Name: echo_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>

#include "echo_service_impl.h"

#include "../echo_request.h"
#include "../echo_response.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace win32 {
namespace echo {
  void
  EchoServiceImpl::OnInit() {
    // TODO: Called when service is initializing.
  }
  void
  EchoServiceImpl::OnShutdown() {
    // TODO: Called when service is shutting down.
  }
  void
  EchoServiceImpl::DoEcho(::ir::ntnaeem::hottentot::examples::win32::echo::EchoRequest &req, ::ir::ntnaeem::hottentot::examples::win32::echo::EchoResponse &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "EchoServiceImpl::DoEcho() is called." << std::endl;
    }
    out.SetMessage("Hello Kamran!");
  }
} // END OF NAMESPACE echo
} // END OF NAMESPACE win32
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir