/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: test_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>

#include "test_service_impl.h"

#include "../token.h"
#include "../credential.h"
#include "../data_wrapper.h"
#include "../string_wrapper.h"
#include "../sample_struct.h"
#include "../result.h"


namespace hotgen {
  void
  TestServiceImpl::OnInit() {
    // TODO: Called when service is initializing.
  }
  void
  TestServiceImpl::OnShutdown() {
    // TODO: Called when service is shutting down.
  }
  void
  TestServiceImpl::Auth(::hotgen::Credential &credential, ::naeem::hottentot::runtime::types::List< ::hotgen::Token> &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Auth() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test(::naeem::hottentot::runtime::types::List< ::hotgen::DataWrapper> &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test2(::naeem::hottentot::runtime::types::List< ::hotgen::StringWrapper> &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test2() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test3(::hotgen::StringWrapper &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test3() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test4(::hotgen::DataWrapper &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test4() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test5(::naeem::hottentot::runtime::types::List< ::hotgen::StringWrapper> &inputList, ::hotgen::DataWrapper &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test5() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test6(::naeem::hottentot::runtime::types::List< ::hotgen::DataWrapper> &inputs, ::hotgen::DataWrapper &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test6() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test7(::hotgen::SampleStruct &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test7() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test8(::hotgen::StringWrapper &str, ::hotgen::StringWrapper &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test8() is called." << std::endl;
    }
    // TODO
  }
  void
  TestServiceImpl::Test9(::hotgen::SampleStruct &sample, ::hotgen::Result &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "TestServiceImpl::Test9() is called." << std::endl;
    }
    // TODO
  }
} // END OF NAMESPACE hotgen