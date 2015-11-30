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

#include <iostream>
#include <fstream>

#include "cc_generator.h"
#include "type_helper.h"

#include "../ds/hot.h"
#include "../ds/service.h"
#include "../ds/method.h"
#include "../ds/module.h"
#include "../ds/argument.h"
#include "../ds/struct.h"
#include "../ds/declaration.h"

#include "../common/os.h"
#include "../common/string_helper.h"
#include "../common/datetime_helper.h"


namespace naeem {
  namespace hottentot {
    namespace generator {
      namespace cc {
        void
        CCGenerator::GenerateStructCC(::naeem::hottentot::generator::ds::Struct *structt,
                                        ::naeem::hottentot::generator::GenerationConfig &generationConfig,
                                        std::map<std::string, std::string> &templates) {
          std::string indent = generationConfig.GetIndentString();
          /*
           * Making needed variables and assigning values to them
           */
          std::string structNameCamelCaseFirstCapital = 
          ::naeem::hottentot::generator::common::StringHelper::MakeCamelCaseFirstCapital(
            structt->GetName());
          std::string structNameSnakeCase = 
            ::naeem::hottentot::generator::common::StringHelper::MakeSnakeCaseFromCamelCase(
              structNameCamelCaseFirstCapital);
          std::string structNameScreamingSnakeCase =
          ::naeem::hottentot::generator::common::StringHelper::MakeScreamingSnakeCaseFromCamelCase(structNameSnakeCase);
          std::string structCCFilePath = generationConfig.GetOutDir() + "/" + structNameSnakeCase + ".cc";
          /*
           * Making real values
           */
          std::vector<std::string> packageTokens = ::naeem::hottentot::generator::common::StringHelper::Split(
            structt->module_->GetPackage(), '.');
          std::string namespacesStart = "";
          for (uint32_t i = 0; i < packageTokens.size(); i++) {
            namespacesStart += "namespace " + 
              ::naeem::hottentot::generator::common::StringHelper::MakeLowerCase(packageTokens[i]) + " {\r\n";
          }
          std::string namespacesEnd = "";
          for (int32_t i = packageTokens.size() - 1; i >= 0; i--) {
            namespacesEnd += "} // END OF NAMESPACE " + packageTokens[i] + "\r\n";
          }
          namespacesStart = ::naeem::hottentot::generator::common::StringHelper::Trim(namespacesStart);
          namespacesEnd = ::naeem::hottentot::generator::common::StringHelper::Trim(namespacesEnd);
          std::string fields = "";
          std::string serialization = "return 0; // TODO(kamran)";
          std::string deserialization = "return; // TODO(kamran)";
          for (std::map<uint32_t, ::naeem::hottentot::generator::ds::Declaration*>::iterator it = structt->declarations_.begin();
               it != structt->declarations_.end();
               ++it) {
          }
          /*
           * Filling templates with real values
           */
          std::map<std::string, std::string> params;
          params.insert(std::pair<std::string, std::string>("GENERATION_DATE", ::naeem::hottentot::generator::common::DateTimeHelper::GetCurrentDateTime()));
          params.insert(std::pair<std::string, std::string>("FILENAME", structNameSnakeCase + ".cc"));
          params.insert(std::pair<std::string, std::string>("NAMESPACES_START", namespacesStart));
          params.insert(std::pair<std::string, std::string>("NAMESPACES_END", namespacesEnd));
          params.insert(std::pair<std::string, std::string>("NAMESPACE","::" + 
            ::naeem::hottentot::generator::common::StringHelper::Concat( 
              ::naeem::hottentot::generator::common::StringHelper::Split(
                  structt->module_->GetPackage(), '.'), "::")));
          params.insert(std::pair<std::string, std::string>("STRUCT_NAME", structNameCamelCaseFirstCapital));
          params.insert(std::pair<std::string, std::string>("SNAKE_CASE_STRUCT_NAME", structNameSnakeCase));
          params.insert(std::pair<std::string, std::string>("SERIALIZATION", serialization));
          params.insert(std::pair<std::string, std::string>("DESERIALIZATION", deserialization));
          params.insert(std::pair<std::string, std::string>("INDENT", indent));
          std::string structCCTemplate = templates["struct_cc"];
          for (std::map<std::string, std::string>::iterator it = params.begin();
               it != params.end();
               ++it) {
            structCCTemplate = 
              ::naeem::hottentot::generator::common::StringHelper::Replace(structCCTemplate, 
                                                                           "[[[" + it->first + "]]]", 
                                                                           it->second);
          }
          /*
           * Writing final results to files
           */
          std::fstream f;
          f.open(structCCFilePath.c_str(), std::fstream::out | std::fstream::binary);
          f << structCCTemplate;
          f.close();
        }
      }
    }
  }
}