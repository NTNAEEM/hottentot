/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar NAEEM Co.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef _NAEEM_HOTTENTOT_GENERATOR__DS__HOT_H_
#define _NAEEM_HOTTENTOT_GENERATOR__DS__HOT_H_

#include <vector>
#include <iostream>
#include <stdint.h>

#include "module.h"


namespace naeem {
  namespace hottentot {
    namespace generator {
      namespace ds {
        class Module;
        class Hot {
        public:
          Hot() {}
          virtual ~Hot() {}
        public:
          inline virtual void AddModule(Module *module) {
            modules_.push_back(module);
          }
          inline virtual void Display() {
            std::cout << "HOT {\n";
            for (uint32_t i = 0; i < modules_.size(); i++) {
              std::cout << "   MODULE {\n";
              for (uint32_t j = 0; j < modules_[i]->structs_.size(); j++) {
                std::cout << "      STRUCT {\n";
                std::cout << "      }\n";
              }
              std::cout << "   }\n";
            }
            std::cout << "}\n";
          }
        private:
          std::vector<Module*> modules_;
        };
      }
    }
  }
}

#endif