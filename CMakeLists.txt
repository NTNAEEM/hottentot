cmake_minimum_required(VERSION 2.8) 

project(hottentot)

if (UNIX)
  add_definitions(-D__UNIX__)
  add_definitions(-D__CPPXX__)
  set(BIN_INSTALL_DIR "/usr/bin/" CACHE PATH "")
  set(HEADERS_INSTALL_DIR "/usr/include")
  set(LIB_INSTALL_DIR "/usr/lib")
  if (APPLE)
    set(CMAKE_MACOSX_RPATH 1)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-writable-strings -Wno-deprecated-register -Wno-unused-function")
    add_definitions(-D__MACOS__)
    link_directories("/opt/local/lib/")
  else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-attributes -Wno-write-strings -Wno-unused-but-set-variable -Wno-sign-compare -Wno-unused-function")
    add_definitions(-D__LINUX__)
    link_directories("/usr/local/lib")
  endif()
endif()

if (WIN32)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
  add_definitions(-DUNICODE -D_UNICODE)
  add_definitions(-D__WIN32__)
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/)

if (WIN32)
  include_directories(${PROJECT_SOURCE_DIR}/generator)
endif()

set(CC_TEMPLATE_SOURCES
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/templates.h
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/templates.cc
)

set(CC_TEMPLATES
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/abstract_service_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/client.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/enums.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/interface.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_builder_cc.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_builder_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_cc.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_cc__method.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_cc__method_argument_serialization.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_cc__method_response_deserialization.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/proxy_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/request_handler_cc.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/request_handler_cc__method_if_clause.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/request_handler_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/server.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/service_impl_cc.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/service_impl_cc__method.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/service_impl_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/service_interface.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/struct_cc.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/struct_header.template
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/struct_header__getter_and_setter.template
)

set(JAVA_TEMPLATES
  ${PROJECT_SOURCE_DIR}/generator/java/templates/abstractService.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/client_main.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/enum.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/pom.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/requestHandler.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/serializableStructList.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/server_impl.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/server_main.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/service.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/serviceProxy.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/serviceProxyBuilder.template
  ${PROJECT_SOURCE_DIR}/generator/java/templates/struct.template
)

set(JAVA_TEMPLATE_SOURCES
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/abstractService.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/clientMain.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/enum.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/pom.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/requestHandler.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/serializableStructList.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/serverImpl.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/serverMain.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/service.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/serviceProxy.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/serviceProxyBuilder.h
  ${PROJECT_SOURCE_DIR}/generator/java/templates/byte_arrays/struct.h
)

set(YACC_LEX_FILES
  ${PROJECT_SOURCE_DIR}/generator/hot.y
  ${PROJECT_SOURCE_DIR}/generator/hot.l
)

set(YACC_LEX_SOURCES
  ${PROJECT_SOURCE_DIR}/generator/y.tab.cc
  ${PROJECT_SOURCE_DIR}/generator/lex.yy.cc
)

if (UNIX)
  add_custom_command(OUTPUT ${CC_TEMPLATE_SOURCES}
    COMMAND echo "Generating C++ templates ..."
    COMMAND ./cc/templates/generate_templates_header.sh ./cc/templates/
    COMMAND echo "C++ templates are generated."
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/generator
    VERBATIM
    DEPENDS ${CC_TEMPLATES}
  )
else()
  add_custom_command(OUTPUT ${CC_TEMPLATE_SOURCES}
    COMMAND echo "Generating C++ templates ..."
    COMMAND .\\cc\\templates\\generate_templates_header.bat .\\cc\\templates
    COMMAND echo "C++ templates are generated."
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}\\generator
    VERBATIM
    DEPENDS ${CC_TEMPLATES}
  )
endif()

add_custom_target(cc-templates DEPENDS ${CC_TEMPLATE_SOURCES})

if (UNIX)
  add_custom_command(OUTPUT ${JAVA_TEMPLATE_SOURCES}
    COMMAND echo "Generating Java templates ..."
    COMMAND ./java/templates/byte_array_maker.sh
    COMMAND echo "Java templates are generated."
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/generator
    VERBATIM
    DEPENDS ${JAVA_TEMPLATES}
  )
else()
  add_custom_command(OUTPUT ${JAVA_TEMPLATE_SOURCES}
    COMMAND echo "Generating Java templates ..."
    COMMAND .\\java\\templates\\byte_array_maker.bat
    COMMAND echo "Java templates are generated."
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}\\generator
    VERBATIM
    DEPENDS ${JAVA_TEMPLATES}
  )
endif()

add_custom_target(java-templates DEPENDS ${JAVA_TEMPLATE_SOURCES})

if (UNIX)
  if(APPLE)
    add_custom_command(OUTPUT ${YACC_LEX_SOURCES}
      COMMAND echo "Building sources for yacc and lex ..."
      COMMAND bison -d hot.y
      COMMAND flex hot.l
      COMMAND mv hot.tab.c y.tab.cc
      COMMAND mv lex.yy.c lex.yy.cc
      COMMAND echo "Yac and lex sources are generated."
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/generator
      VERBATIM
      DEPENDS ${YACC_LEX_FILES}
    )
  else()
    add_custom_command(OUTPUT ${YACC_LEX_SOURCES}
      COMMAND echo "Building sources for yacc and lex ..."
      COMMAND bison -d hot.y
      COMMAND flex hot.l
      COMMAND mv hot.tab.c y.tab.cc
      COMMAND mv lex.yy.c lex.yy.cc
      COMMAND echo "Yac and lex sources are generated."
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/generator
      VERBATIM
      DEPENDS ${YACC_LEX_FILES}
    )
  endif()
else()
  add_custom_command(OUTPUT ${YACC_LEX_SOURCES}
    COMMAND echo "Building sources for yacc and lex ..."
    COMMAND bison -d hot.y
    COMMAND flex hot.l
    COMMAND move hot.tab.c y.tab.cc
    COMMAND move lex.yy.c lex.yy.cc
    COMMAND echo "Yac and lex sources are generated."
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/generator
    VERBATIM
    DEPENDS ${YACC_LEX_FILES}
  )
endif()

add_custom_target(yacc-lex-sources DEPENDS ${YACC_LEX_SOURCES})

add_library(hottentot-generator-common-lib STATIC 
  ${PROJECT_SOURCE_DIR}/generator/runtime.cc
  ${PROJECT_SOURCE_DIR}/generator/fasthash.cc
  ${PROJECT_SOURCE_DIR}/generator/service.cc
  ${PROJECT_SOURCE_DIR}/generator/method.cc
  ${PROJECT_SOURCE_DIR}/generator/os.cc
)

add_library(hottentot-generator-cc-lib STATIC
  ${PROJECT_SOURCE_DIR}/generator/cc/runtime.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/cc_generator.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_abstract_service_header.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_enums.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_interface.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_service_interface.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_proxy_header.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_proxy_cc.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_proxy_builder_header.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_proxy_builder_cc.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_request_handler_header.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_request_handler_cc.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_struct_header.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_struct_cc.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_makefile.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_client.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/generate_stub.cc
  ${PROJECT_SOURCE_DIR}/generator/cc/templates/templates.cc
)

add_dependencies(hottentot-generator-cc-lib cc-templates)
add_dependencies(hottentot-generator-cc-lib hottentot-generator-common-lib)

add_library(hottentot-generator-java-lib STATIC
  ${PROJECT_SOURCE_DIR}/generator/runtime.cc
  ${PROJECT_SOURCE_DIR}/generator/java/java_generator.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_abstract_service_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_structs_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_service_interface_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_request_handler_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_service_proxy_builder_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_service_proxy_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_serializable_struct_list_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_client_main_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_server_main_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_server_impls_java.cc
  ${PROJECT_SOURCE_DIR}/generator/java/generate_enums_java.cc
)

add_dependencies(hottentot-generator-java-lib java-templates)
add_dependencies(hottentot-generator-java-lib hottentot-generator-common-lib)

add_executable(hottentot-generator
  ${PROJECT_SOURCE_DIR}/generator/lex.yy.cc
  ${PROJECT_SOURCE_DIR}/generator/y.tab.cc
)

add_dependencies(hottentot-generator yacc-lex-sources)
add_dependencies(hottentot-generator hottentot-generator-cc-lib)
add_dependencies(hottentot-generator hottentot-generator-java-lib)

if (UNIX)
  target_compile_options(hottentot-generator-common-lib PUBLIC -std=c++11 -O3)
  target_compile_options(hottentot-generator-cc-lib PUBLIC -std=c++11 -O3)
  target_compile_options(hottentot-generator-java-lib PUBLIC -std=c++11 -O3)
  target_compile_options(hottentot-generator PUBLIC -std=c++11 -O3)
endif()

set_target_properties(hottentot-generator-common-lib PROPERTIES OUTPUT_NAME hottentot-generator-common)
set_target_properties(hottentot-generator-cc-lib PROPERTIES OUTPUT_NAME hottentot-generator-cc)
set_target_properties(hottentot-generator-java-lib PROPERTIES OUTPUT_NAME hottentot-generator-java)
set_target_properties(hottentot-generator PROPERTIES RUNTIME_OUTPUT_NAME hot)

if (UNIX)
  target_link_libraries(hottentot-generator
    hottentot-generator-cc-lib
    hottentot-generator-common-lib
    hottentot-generator-java-lib
    fl
  )
else()
  target_link_libraries(hottentot-generator
    hottentot-generator-common-lib
    hottentot-generator-cc-lib
    hottentot-generator-java-lib
  )
endif()

add_library(hottentot-runtime STATIC
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/configuration.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/logger.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/protocol_v1.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/proxy.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/proxy_runtime.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/default_tcp_client.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/default_tcp_client_factory.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/service_runtime.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_tcp_server.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_tcp_server_factory.cc
  ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_request_callback.cc
)

if (UNIX)
  target_compile_options(hottentot-runtime PUBLIC -std=c++11 -O3)
  
  add_library(hottentot-runtime-debug STATIC
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/configuration.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/logger.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/protocol_v1.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/proxy.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/proxy_runtime.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/default_tcp_client.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/proxy/default_tcp_client_factory.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/service_runtime.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_tcp_server.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_tcp_server_factory.cc
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org/labcrypto/hottentot/runtime/service/default_request_callback.cc
  )
  target_compile_options(hottentot-runtime-debug PUBLIC -D_DEBUG -std=c++11 -O0 -g)
endif()

if (UNIX)
  install(DIRECTORY 
    ${PROJECT_SOURCE_DIR}/runtimes/cc/runtime/org 
    DESTINATION 
    ${HEADERS_INSTALL_DIR} 
    FILES_MATCHING 
    PATTERN "*.h"
  )

  install(TARGETS
    hottentot-runtime
    hottentot-runtime-debug
    DESTINATION
    ${LIB_INSTALL_DIR}
  )

  install(TARGETS
    hottentot-generator
    DESTINATION
    ${BIN_INSTALL_DIR}
  )
endif()
 
# add_custom_target(uninstall
#   COMMAND rm -rfv ${BIN_INSTALL_DIR}/hot
#   COMMAND rm -rfv ${LIB_INSTALL_DIR}/libhot*
#   COMMAND rm -rfv ${HEADERS_INSTALL_DIR}/org/labcrypto/hottentot
# )
# 
