/****************************************************************************
 * Generated by Hottentot CC Generator
 * Date: 10-02-2016 11:35:21
 * Name: apache_license_manager_service_request_handler.cc
 * Description:
 *   This file contains implementation of service's request handler class.
 ****************************************************************************/
 
#include <string.h>

#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>

#include "apache_license_manager_service_request_handler.h"
#include "abstract_apache_license_manager_service.h"
#include "apache_license_manager_service.h"
#include "../license.h"


namespace org {
namespace apache {
namespace tests {
namespace service {
  void 
  ApacheLicenseManagerServiceRequestHandler::HandleRequest(::naeem::hottentot::runtime::Request &request, ::naeem::hottentot::runtime::Response &response) {
    if (request.GetMethodId() == 1658552266) {
      ::org::apache::tests::service::AbstractApacheLicenseManagerService *serviceObject = 
        dynamic_cast< ::org::apache::tests::service::AbstractApacheLicenseManagerService*>(service_);
      /*
       * Deserialization and making input variables
       */
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::service::HotContext hotContext;
      ::org::apache::tests::set<License> result;
      serviceObject->GetThem(result, hotContext);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    if (request.GetMethodId() == 2119373143) {
      ::org::apache::tests::service::AbstractApacheLicenseManagerService *serviceObject = 
        dynamic_cast< ::org::apache::tests::service::AbstractApacheLicenseManagerService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> names;
      names.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      ::org::apache::tests::set<map<list<int>,string>> s;
      s.Deserialize(request.GetArgumentData(1), request.GetArgumentLength(1));
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::service::HotContext hotContext;
      ::org::apache::tests::map<list<Person>,asdasdaasdasdsda> result;
      serviceObject->GetMap(names, s, result, hotContext);
      names.Purge();
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    char errorMessage[] = "Method not found.";
    response.SetStatusCode(1);
    response.SetData((unsigned char*)errorMessage);
    response.SetDataLength(strlen(errorMessage));
  }
} // END OF NAMESPACE service
} // END OF NAMESPACE tests
} // END OF NAMESPACE apache
} // END OF NAMESPACE org