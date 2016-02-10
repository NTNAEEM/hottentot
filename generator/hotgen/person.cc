/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 10-02-2016 11:35:21
 * Name: person.cc
 * Description:
 *   This file contains implementation of Person class.
 ******************************************************************/

#include <iostream>
#include <string.h>

#include <naeem/hottentot/runtime/hot_ptr.h>

#include "person.h"


namespace ir {
namespace ntnaeem {
namespace services {
  Person::Person(const Person &other) {
    names_ = other.names_;
    sum_ = other.sum_;
    x_ = other.x_;
    str_ = other.str_;
  }
  Person::Person(Person *other) {
    names_ = other->names_;
    sum_ = other->sum_;
    x_ = other->x_;
    str_ = other->str_;
  }
  unsigned char *
  Person::Serialize(uint32_t *length_ptr) {
    uint32_t totalLength = 0;
    uint32_t length0 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr0 = 
      names_.Serialize(&length0);
    if (length0 < 128) {
      totalLength += 1 + length0;
    } else if (length0 < 256) {
      totalLength += 2 + length0;
    } else if (length0 < 256 * 256) {
      totalLength += 3 + length0;
    } else if (length0 < 256 * 256 * 256) {
      totalLength += 3 + length0;
    }
    uint32_t length1 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr1 = 
      sum_.Serialize(&length1);
    if (length1 < 128) {
      totalLength += 1 + length1;
    } else if (length1 < 256) {
      totalLength += 2 + length1;
    } else if (length1 < 256 * 256) {
      totalLength += 3 + length1;
    } else if (length1 < 256 * 256 * 256) {
      totalLength += 3 + length1;
    }
    uint32_t length2 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr2 = 
      x_.Serialize(&length2);
    totalLength += length2;
    uint32_t length3 = 0;
    ::naeem::hottentot::runtime::HotPtr<unsigned char, true> ptr3 = 
      str_.Serialize(&length3);
    if (length3 < 128) {
      totalLength += 1 + length3;
    } else if (length3 < 256) {
      totalLength += 2 + length3;
    } else if (length3 < 256 * 256) {
      totalLength += 3 + length3;
    } else if (length3 < 256 * 256 * 256) {
      totalLength += 3 + length3;
    }
    unsigned char *data = new unsigned char[totalLength];
    uint32_t c = 0;
    if (length0 < 128) {
      data[c] = length0;
      c += 1;
    } else if (length0 < 256) {
      data[c] = 0x81;
      data[c + 1] = length0;
      c += 2;
    } else if (length0 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length0 / 256;
      data[c + 2] = length0 % 256;
      c += 3;
    } else if (length0 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length0 / (256 * 256);
      data[c + 2] = (length0 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length0 % (256 * 256);
      c += 4;
    }
    unsigned char *data0 = ptr0.Get();
    for (uint32_t i = 0; i < length0; i++) {
      data[c++] = data0[i];
    }
    if (length1 < 128) {
      data[c] = length1;
      c += 1;
    } else if (length1 < 256) {
      data[c] = 0x81;
      data[c + 1] = length1;
      c += 2;
    } else if (length1 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length1 / 256;
      data[c + 2] = length1 % 256;
      c += 3;
    } else if (length1 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length1 / (256 * 256);
      data[c + 2] = (length1 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length1 % (256 * 256);
      c += 4;
    }
    unsigned char *data1 = ptr1.Get();
    for (uint32_t i = 0; i < length1; i++) {
      data[c++] = data1[i];
    }
    unsigned char *data2 = ptr2.Get();
    for (uint32_t i = 0; i < length2; i++) {
      data[c++] = data2[i];
    }
    if (length3 < 128) {
      data[c] = length3;
      c += 1;
    } else if (length3 < 256) {
      data[c] = 0x81;
      data[c + 1] = length3;
      c += 2;
    } else if (length3 < 256 * 256) {
      data[c] = 0x82;
      data[c + 1] = length3 / 256;
      data[c + 2] = length3 % 256;
      c += 3;
    } else if (length3 < 256 * 256 * 256) {
      data[c] = 0x83;
      data[c + 1] = length3 / (256 * 256);
      data[c + 2] = (length3 - data[c + 1] * (256 * 256)) / 256;
      data[c + 3] = length3 % (256 * 256);
      c += 4;
    }
    unsigned char *data3 = ptr3.Get();
    for (uint32_t i = 0; i < length3; i++) {
      data[c++] = data3[i];
    }
    if (c != totalLength) {
      std::cout << "Struct Serialization: Inconsistency in length of serialized byte array." << std::endl;
      exit(1);
    };
    if (length_ptr) {
      *length_ptr = totalLength;
    }
    return data;
  }
  void
  Person::Deserialize(unsigned char *data, uint32_t length) {
    uint32_t c = 0, elength = 0;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    names_.Deserialize(data + c, elength);
    c += elength;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    sum_.Deserialize(data + c, elength);
    c += elength;
    x_.Deserialize(data + c, 8);
    c += 8;
    if ((data[c] & 0x80) == 0) {
      elength = data[c];
      c++;
    } else {
      uint8_t ll = data[c] & 0x0f;
      c++;
      if (ll == 1) {
        elength = data[c];
        c += 1;
      } else if (ll == 2) {
        elength = data[c] * 256 + data[c + 1];
        c += 2;
      } else if (ll == 3) {
        elength = data[c] * 256 * 256 + data[c + 1] * 256 + data[c + 2];
        c += 3;
      }
    }
    str_.Deserialize(data + c, elength);
    c += elength;
    if (c != length) {
      std::cout << "Struct Deserialization: Inconsistency in length of deserialized byte array." << std::endl;
      exit(1);
    };
  }
} // END OF NAMESPACE services
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir