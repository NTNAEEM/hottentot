/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 12-01-2016 01:39:45
 * Name: service.h
 * Description:
 *   This file contains definition of service interface.
 ***************************************************************/

#ifndef ___PROXY__SERVICE_H_
#define ___PROXY__SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>





  class Service {
  public:
    virtual void (::naeem::hottentot::runtime::types::Utf8String &fileName, ::naeem::hottentot::runtime::types::ByteArray &content,  &out) = 0;
  };


#endif