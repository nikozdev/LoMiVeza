cmake_minimum_required(VERSION 3.24)

include(CMakeDependentOption)
include(FetchContent)

set(vProjName "LoMiVeza")
set(vProjVnum "0.0")
set(vProjDesc "Language Of My Vesania")
set(vProjPath "${CMAKE_SOURCE_DIR}/..")

project(${vProjName} VERSION ${vProjVnum} DESCRIPTION ${vProjDesc})

# lang

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# code

set(vCodePath "${vProjPath}/code")
set(vCodeFile "${vCodePath}/${vProjName}.cpp")

# head

set(vHeadPath "${vProjPath}/code")
set(vHeadFile "${vHeadPath}/${vProjName}.hpp")

# defs

set(vDefsName "d${vProjName}_")

# make

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "type of build" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)

set(vMakePath "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${vMakePath}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${vMakePath}")

##lib

set(vTlibName "t${vProjName}Lib")

add_library(${vTlibName} INTERFACE)
target_compile_definitions(${vTlibName} INTERFACE ${vDefsName}MakeTlib)

target_precompile_headers(${vTlibName} INTERFACE ${vHeadFile})

##exe

set(vTexeName "t${vProjName}Exe")
set(vTexePath "${vMakePath}")
set(vTexeFile "${vTexePath}/${vTexeName}")

option(oMakeTexe "build the project executable" TRUE)
if(oMakeTexe)

  add_executable(${vTexeName})
  target_compile_definitions(${vTexeName} PRIVATE ${vDefsName}MakeTexe)
  target_link_libraries(${vTexeName} PRIVATE ${vTlibName})

  target_sources(${vTexeName} PRIVATE ${vCodeFile})

endif(oMakeTexe)

# test

cmake_dependent_option(oMakeTest "setup and build ctest units" TRUE oMakeTexe FALSE)
if(oMakeTest)

  include(CTest)
  enable_testing()

  target_compile_definitions(${vTexeName} PRIVATE ${vDefsName}MakeTest)

  function(fTest vName vText)
    add_test(${vName} COMMAND ${vTexeFile} "test" "${vName}")
    set_tests_properties(${vName} PROPERTIES PASS_REGULAR_EXPRESSION ${vText})
  endfunction(fTest)

  fTest("Hello" "HelloWorld")

endif(oMakeTest)
