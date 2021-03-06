/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 11-01-2016 11:34:13
 * Name: file_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__SERVICE__ABSTRACT_FILE_SERVICE_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__SERVICE__ABSTRACT_FILE_SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/service.h>


#include "../file_service.h"
#include "file_service_request_handler.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace file {
namespace server {
namespace service {
  class AbstractFileService : public FileService, public ::naeem::hottentot::runtime::service::Service {
  public:
    inline virtual uint32_t GetServiceId() const {
      return 2482879718;
    }
  protected:
    inline virtual ::naeem::hottentot::runtime::service::RequestHandler* MakeRequestHandler() {
      return new FileServiceRequestHandler(this);
    }
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE server
} // END OF NAMESPACE file
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif