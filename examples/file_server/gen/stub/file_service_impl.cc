/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-12-2015 12:52:35
 * Name: file_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <naeem/hottentot/runtime/utils.h>
 #include <naeem/hottentot/runtime/logger.h>

#include "file_service_impl.h"




namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace file {
namespace server {
  void
  FileServiceImpl::UploadFile(::naeem::hottentot::runtime::types::Utf8String *fileName, ::naeem::hottentot::runtime::types::ByteArray *content) {
    ::naeem::hottentot::runtime::Logger::GetOut() << "FileServiceImpl::UploadFile() is called." << std::endl;
        return;
  }
  ::naeem::hottentot::runtime::types::Boolean*
  FileServiceImpl::FileExists(::naeem::hottentot::runtime::types::Utf8String *fileName) {
    ::naeem::hottentot::runtime::Logger::GetOut() << "FileServiceImpl::FileExists() is called." << std::endl;
    return new ::naeem::hottentot::runtime::types::Boolean(false);
  }
  ::naeem::hottentot::runtime::types::ByteArray*
  FileServiceImpl::DownloadFile(::naeem::hottentot::runtime::types::Utf8String *fileName) {
    ::naeem::hottentot::runtime::Logger::GetOut() << "FileServiceImpl::DownloadFile() is called." << std::endl;
    unsigned char *str = new unsigned char[10];
    strcpy((char *)str, "Kamran");
    ::naeem::hottentot::runtime::types::ByteArray *result = new ::naeem::hottentot::runtime::types::ByteArray;
    result->SetValue(str, strlen((char *)str) + 1);
    return result;
  }
} // END OF NAMESPACE server
} // END OF NAMESPACE file
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir