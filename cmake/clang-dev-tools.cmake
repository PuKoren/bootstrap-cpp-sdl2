# http://stackoverflow.com/questions/32280717/cmake-clang-tidy-or-other-script-as-custom-target#32311771
# Additional target to perform clang-format/clang-tidy run
# Requires clang-format and clang-tidy

# Get all project files
file(GLOB_RECURSE ALL_SOURCE_FILES src/*.cpp include/*.hpp)

add_custom_target(
        clang-format
        COMMAND /usr/bin/clang-format
        -style=file
        -i
        ${ALL_SOURCE_FILES}
)

add_custom_target(
        clang-tidy
        COMMAND /usr/bin/clang-tidy
        ${ALL_SOURCE_FILES}
        --
        -std=c++11
        -I${PROJECT_SOURCE_DIR}/include
        -I${SDL2_INCLUDE_DIR}
        -I${SDL2_TTF_INCLUDE_DIR}
        -I${SDL2_IMAGE_INCLUDE_DIR}
)