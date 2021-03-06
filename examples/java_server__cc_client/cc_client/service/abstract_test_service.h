/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: test_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _HOTGEN__SERVICE__ABSTRACT_TEST_SERVICE_H_
#define _HOTGEN__SERVICE__ABSTRACT_TEST_SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/service.h>

#include "../token.h"
#include "../credential.h"
#include "../data_wrapper.h"
#include "../string_wrapper.h"
#include "../sample_struct.h"
#include "../result.h"
#include "../test_service.h"
#include "test_service_request_handler.h"


namespace hotgen {
namespace service {
  class AbstractTestService : public TestService, public ::naeem::hottentot::runtime::service::Service {
  public:
    inline virtual uint32_t GetServiceId() const {
      return 3840930520;
    }
  protected:
    inline virtual ::naeem::hottentot::runtime::service::RequestHandler* MakeRequestHandler() {
      return new TestServiceRequestHandler(this);
    }
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE hotgen

#endif