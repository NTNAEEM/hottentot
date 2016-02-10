/****************************************************************************
 * Generated by Hottentot CC Generator
 * Date: 10-02-2016 11:35:21
 * Name: phone_manager_service_request_handler.cc
 * Description:
 *   This file contains implementation of service's request handler class.
 ****************************************************************************/
 
#include <string.h>

#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>

#include "phone_manager_service_request_handler.h"
#include "abstract_phone_manager_service.h"
#include "phone_manager_service.h"
#include "../person.h"
#include "../phone.h"


namespace ir {
namespace ntnaeem {
namespace services {
namespace service {
  void 
  PhoneManagerServiceRequestHandler::HandleRequest(::naeem::hottentot::runtime::Request &request, ::naeem::hottentot::runtime::Response &response) {
    if (request.GetMethodId() == 133025501) {
      ::ir::ntnaeem::services::service::AbstractPhoneManagerService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::services::service::AbstractPhoneManagerService*>(service_);
      /*
       * Deserialization and making input variables
       */
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::service::HotContext hotContext;
      ::ir::ntnaeem::services::map<Person,list<Phone>> result;
      serviceObject->GetPhonebook(result, hotContext);
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
    if (request.GetMethodId() == 1769151897) {
      ::ir::ntnaeem::services::service::AbstractPhoneManagerService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::services::service::AbstractPhoneManagerService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::ir::ntnaeem::services::Person person;
      person.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      ::ir::ntnaeem::services::Phone phone;
      phone.Deserialize(request.GetArgumentData(1), request.GetArgumentLength(1));
      ::naeem::hottentot::runtime::types::Date d;
      d.Deserialize(request.GetArgumentData(2), request.GetArgumentLength(2));
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::service::HotContext hotContext;
      serviceObject->AddEntry(person, phone, d, hotContext);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = 0;
      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    if (request.GetMethodId() == 2372717956) {
      ::ir::ntnaeem::services::service::AbstractPhoneManagerService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::services::service::AbstractPhoneManagerService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::Utf8String abc;
      abc.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::service::HotContext hotContext;
      ::ir::ntnaeem::services::map<list<Person>,string> result;
      serviceObject->FFF(abc, result, hotContext);
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
} // END OF NAMESPACE services
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir