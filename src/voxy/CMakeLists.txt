

include_directories(include)

###############################################################################
## file globbing ##############################################################
###############################################################################

# these instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables
# `sources` and `data`
file(GLOB_RECURSE sources      src/*.cpp src/main/*.hpp)
file(GLOB_RECURSE sources_test test/*.cpp)
file(GLOB_RECURSE data resources/*)

###############################################################################
## target definitions #########################################################
###############################################################################

# add the data to the target, so it becomes visible in some IDE
add_executable(voxy ${sources} ${data})

# just for example add some compiler flags
target_compile_options(voxy PUBLIC -std=c++1y -Wall -Wfloat-conversion)

# this copies all resource files in the build directory
# we need this, because we want to work with paths relative to the executable
file(COPY ${data} DESTINATION resources)

###############################################################################
## dependencies ###############################################################
###############################################################################

if (NOT "$ENV{CGAL_DIR}" STREQUAL "")
    set(CGAL_DIR "$ENV{CGAL_DIR}" CACHE INTERNAL "Copied from environment variable")
endif()

message("CGAL_DIR = ${CGAL_DIR}")

find_package(ASSIMP 3.3.1 REQUIRED)
find_package(CGAL 4.11 REQUIRED COMPONENTS Core)


include_directories(${CGAL_INCLUDE_DIRS})
include_directories(${ASSIMP_INCLUDE_DIRS})
target_link_libraries(voxy PUBLIC
        ${ASSIMP_LIBRARIES}
        ${CGAL_LIBRARIES}
        )

###############################################################################
## testing ####################################################################
###############################################################################

# this is for our testing framework
# we don't add REQUIRED because it's just for testing
find_package(GTest)

if(GTEST_FOUND)
    add_executable(unit_tests ${sources_test} ${sources})

    # we add this define to prevent collision with the main
    # this might be better solved by not adding the source with the main to the
    # testing target
    target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

    # this allows us to use our executable as a link library
    # therefore we can inherit all compiler options and library dependencies
    set_target_properties(example PROPERTIES ENABLE_EXPORTS on)

    target_link_libraries(unit_tests PUBLIC
            ${GTEST_BOTH_LIBRARIES}
            example
            )

    target_include_directories(unit_tests PUBLIC
            ${GTEST_INCLUDE_DIRS} # doesn't do anything on Linux
            )
endif()

###############################################################################
## packaging ##################################################################
###############################################################################

# all install commands get the same destination. this allows us to use paths
# relative to the executable.
install(TARGETS voxy DESTINATION build)
# this is basically a repeat of the file copy instruction that copies the
# resources in the build directory, but here we tell cmake that we want it
# in the package
install(DIRECTORY resources DESTINATION build)

# now comes everything we need, to create a package
# there are a lot more variables you can set, and some
# you need to set for some package types, but we want to
# be minimal here
set(CPACK_PACKAGE_NAME "Voxy")
set(CPACK_PACKAGE_VERSION "1.0.0")

# we don't want to split our program up into several things
set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)