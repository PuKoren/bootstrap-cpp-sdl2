# Only build tests on Debug mode
IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
  find_package(CppUnit REQUIRED)

  IF(CPPUNIT_LIBRARY)
    # Fetch all .cpp files in test folder
    file(GLOB_RECURSE TESTS_SOURCE_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
    # Remove the Main.cpp file from the project sources
    # because we already have a main for tests and can't have two
    list(REMOVE_ITEM PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/Main.cpp)

    # Compile all test files and project files into one binary
    add_executable(tests
      ${PROJECT_SOURCE_FILES}
      ${TESTS_SOURCE_FILES}
    )

    # Link everything
    target_link_libraries(tests
      ${CPPUNIT_LIBRARY}
      ${SDL2_LIBRARY}
      ${SDL2_IMAGE_LIBRARY}
      ${SDL2_TTF_LIBRARY}
    )
  ENDIF(CPPUNIT_LIBRARY)
ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)