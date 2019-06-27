cmake_minimum_required (VERSION 3.0)
#module name
set(ProjectName test)

project (${ProjectName})
#module verison
set(PCK_MAJOR 1)
set(PCK_MINOR 0)
set(PCK_REVISION 0)

set (CMAKE_C_FLAGS_INIT "-mcpu Cortex-M4 -mthumb")
set (CMAKE_CXX_FLAGS_INIT "-mcpu Cortex-M4 -mthumb")
set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

#include (CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_CROSSCOMPILING 1)

set(CMAKE_ASM_COMPILER "arm-none-eabi-as")
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_LINKER "arm-none-eabi-gcc")

set(MEMORY_MAP "memory_map.ld")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --specs=nosys.specs -nostdlib -mcpu=cortex-m4 -mthumb -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --specs=nosys.specs -nostdlib -mcpu=cortex-m4 -mthumb -g")
set(CMAKE_EXE_LINKER_FLAGS " -T./${MEMORY_MAP} -Xlinker -Map=memory.map -nostdlib -lgcc")

set_property(SOURCE core.S PROPERTY LANGUAGE C)

list (APPEND project_sources
  core.S
  main.c
  )

add_executable(
  ${ProjectName} ${project_sources}
  )
