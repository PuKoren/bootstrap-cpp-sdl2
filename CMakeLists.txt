cmake_minimum_required(VERSION 2.8.11)
project({project-name})

SET(CMAKE_CXX_FLAGS "-std=c++11")

# Compile in release mode by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
      "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif()

# Warnings and errors.
# Be less pedantic in release builds for users.
set(CMAKE_CXX_FLAGS_RELEASE "-Wno-error -Wno-all -Wno-unknown-pragmas -Wno-fatal-errors -Wno-extra ${CMAKE_CXX_FLAGS_RELEASE}")

# Be more pedantic in debug mode for developers.
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Werror -Wextra -pedantic ${CMAKE_CXX_FLAGS_DEBUG}")

# Platform-specific flags.
if(WIN32)
  # Windows: disable the console by default.
  if(MSVC)
    set_target_properties({project-name} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
  elseif(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-mwindows ${CMAKE_CXX_FLAGS}")
  endif()
endif()

# Find dependencies.
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Include paths.
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

# External include paths, marked as system ones to disable their warnings.
include_directories(SYSTEM
  ${SDL2_INCLUDE_DIR}
  ${SDL2_TTF_INCLUDE_DIR}
  ${SDL2_IMAGE_INCLUDE_DIR}
)

file(GLOB_RECURSE PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable({project-name}
  ${PROJECT_SOURCE_FILES}
)

target_link_libraries({project-name}
  ${SDL2_LIBRARY}
  ${SDL2_IMAGE_LIBRARY}
  ${SDL2_TTF_LIBRARY}
)

# Include extras like linter configuration if available
include(cmake/clang-dev-tools.cmake)

# Include CMake subdir for tests
add_subdirectory (test)
