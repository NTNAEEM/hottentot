/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 01-12-2015 05:07:25
 * Name: echo_service_server.cc
 * Description:
 *   This file contains definitions of sample stub.
 ******************************************************************/
 
#include <iostream>

#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/service/service_runtime.h>

#include "../request_message.h"
#include "../response_message.h"

#include "echo_service_impl.h"


int
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();
    ::naeem::hottentot::runtime::Logger::GetOut() << "Starting server ..." << std::endl;
    ::naeem::hottentot::runtime::service::ServiceRuntime::Init(argc, argv);
    ::ir::ntnaeem::hottentot::examples::echoer::EchoServiceImpl *service =
        new ::ir::ntnaeem::hottentot::examples::echoer::EchoServiceImpl;
    ::naeem::hottentot::runtime::service::ServiceRuntime::Register("0.0.0.0", 2000, service);
    ::naeem::hottentot::runtime::service::ServiceRuntime::Start();
  } catch (...) {
    std::cout << "Error." << std::endl;
    return 1;
  }
  return 0;
}
