/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 14-01-2016 10:56:23
 * Name: .h
 * Description:
 *   This file contains definition of  class.
 ***************************************************************/

#ifndef ____H_
#define ____H_

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/serializable.h>



  class  : public ::naeem::hottentot::runtime::Serializable {
  public:
    () {}
    ~() {}
  public:
    inline ::naeem::hottentot::runtime::types::Utf8String GetValue() const {
      return value_;
    }
    inline void SetValue(::naeem::hottentot::runtime::types::Utf8String value) {
      value_ = value;
    }
  public:
    virtual unsigned char * Serialize(uint32_t * /* Pointer to length */);
    virtual void Deserialize(unsigned char * /* Data */, uint32_t /* Data length */);
  private:
    ::naeem::hottentot::runtime::types::Utf8String value_;
  };


#endif