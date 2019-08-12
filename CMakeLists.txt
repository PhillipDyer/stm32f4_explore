cmake_minimum_required (VERSION 3.0)
#module name
set(ProjectName test)

project (${ProjectName})

add_subdirectory("cortex_core")

set(ProjectLibs "cortex_core")

#module verison
set(PCK_MAJOR 1)
set(PCK_MINOR 0)
set(PCK_REVISION 0)

set (CMAKE_C_FLAGS_INIT "-mcpu Cortex-M4 -mthumb")
set (CMAKE_CXX_FLAGS_INIT "-mcpu Cortex-M4 -mthumb")

#these added to fix the -rdynamic bug
set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set (CMAKE_SHARED_LIBAARY_LINK_CXX_FLAGS "")

#include (CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_CROSSCOMPILING 1)

set(CMAKE_ASM_COMPILER "arm-none-eabi-as")
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_LINKER "arm-none-eabi-gcc")

set(MEMORY_MAP "memory_map.ld")

set(NEWLIB_PATH "/usr/lib/arm-none-eabi/newlib/")
set(NEWLIB_LIBRARIES "-lg -lm -lc")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --specs=nosys.specs -mcpu=cortex-m4 -mthumb -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --specs=nosys.specs -mcpu=cortex-m4 -mthumb -g")
set(CMAKE_EXE_LINKER_FLAGS " -T./${MEMORY_MAP} -nostdlib ${NEWLIB_LIBRARIES}")

set_property(SOURCE core.S PROPERTY LANGUAGE C)

list (APPEND ProjectSources
#  core.S
  main.c
  interrupt_handlers.c
  )

add_executable(
  ${ProjectName} ${ProjectSources}
  )

target_link_libraries(${ProjectName} ${ProjectLibs})
