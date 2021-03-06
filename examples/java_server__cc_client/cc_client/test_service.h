/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: test_service.h
 * Description:
 *   This file contains definition of service interface.
 ***************************************************************/

#ifndef _HOTGEN__PROXY__TEST_SERVICE_H_
#define _HOTGEN__PROXY__TEST_SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>

#include "token.h"
#include "credential.h"
#include "data_wrapper.h"
#include "string_wrapper.h"
#include "sample_struct.h"
#include "result.h"


namespace hotgen {
  class TestService {
  public:
    virtual void Auth(::hotgen::Credential &credential, ::naeem::hottentot::runtime::types::List< ::hotgen::Token> &out) = 0;
    virtual void Test(::naeem::hottentot::runtime::types::List< ::hotgen::DataWrapper> &out) = 0;
    virtual void Test2(::naeem::hottentot::runtime::types::List< ::hotgen::StringWrapper> &out) = 0;
    virtual void Test3(::hotgen::StringWrapper &out) = 0;
    virtual void Test4(::hotgen::DataWrapper &out) = 0;
    virtual void Test5(::naeem::hottentot::runtime::types::List< ::hotgen::StringWrapper> &inputList, ::hotgen::DataWrapper &out) = 0;
    virtual void Test6(::naeem::hottentot::runtime::types::List< ::hotgen::DataWrapper> &inputs, ::hotgen::DataWrapper &out) = 0;
    virtual void Test7(::hotgen::SampleStruct &out) = 0;
    virtual void Test8(::hotgen::StringWrapper &str, ::hotgen::StringWrapper &out) = 0;
    virtual void Test9(::hotgen::SampleStruct &sample, ::hotgen::Result &out) = 0;
  };
} // END OF NAMESPACE hotgen

#endif