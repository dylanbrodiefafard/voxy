

include_directories(include)

###############################################################################
## file globbing ##############################################################
###############################################################################

# these instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables
# `sources` and `data`
file(GLOB_RECURSE sources      src/*.cpp include/*.hpp)
file(GLOB_RECURSE sources_test test/*.cpp)
file(GLOB_RECURSE data resources/*)

###############################################################################
## target definitions #########################################################
###############################################################################

# add the data to the target, so it becomes visible in some IDE
add_library(voxy SHARED ${sources})
#add_executable(voxy ${sources} ${data})

# just for example add some compiler flags
target_compile_options(voxy PUBLIC -std=c++1y -Wall -Wfloat-conversion)

# this copies all resource files in the build directory
# we need this, because we want to work with paths relative to the executable
file(COPY ${data} DESTINATION resources)

###############################################################################
## dependencies ###############################################################
###############################################################################

# TODO: Remove this junk
SET(ENV_HINTS "CGAL_DIR;ASSIMP_ROOT_DIR;BOOST_ROOT;BOOST_INCLUDEDIR;BOOST_LIBRARYDIR")
foreach(ENV_HINT ${ENV_HINTS})
    if(NOT "$ENV{${ENV_HINT}}" STREQUAL "")
        set(${ENV_HINT} "$ENV{${ENV_HINT}}" CACHE INTERNAL "Copied from environment variable")
    endif()
endforeach()

set(Boost_USE_STATIC_LIBS        OFF)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
set(BOOST_ALL_DYN_LINK           ON)   # force dynamic linking for all libraries
find_package(Boost COMPONENTS thread system filesystem log REQUIRED)

if (WIN32 AND __COMPILER_GNU)
    # mingw-gcc fails to link boost::thread
    message("Adding BOOST_THREAD_USE_LIB")
    add_definitions(-DBOOST_THREAD_USE_LIB)
endif (WIN32 AND __COMPILER_GNU)
add_definitions(-DBOOST_LOG_DYN_LINK)

message("Found Boost.")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")
#target_link_libraries(voxy PUBLIC Boost::system Boost::filesystem Boost::log Boost::thread)

# CGAL for geometric algorithms
set(CGAL_Boost_USE_STATIC_LIBS FALSE)
find_package(CGAL COMPONENTS Core REQUIRED)

message("Found CGAL.")

message("CGAL_CXX_FLAGS_INIT: ${CGAL_CXX_FLAGS_INIT}")
#add_definitions(${CGAL_CXX_GLAFS_INIT})

message("CGAL_LIBRARIES: ${CGAL_LIBRARIES}")
#target_link_libraries(voxy PUBLIC CGAL)

# ASSIMP for 3D import/export and data structures
find_package(ASSIMP REQUIRED)

message("Found ASSIMP.")
message("ASSIMP_LIBRARIES: ${ASSIMP_LIBRARIES}")


target_link_libraries(voxy
        ASSIMP
        Boost::system Boost::filesystem Boost::log Boost::thread
        CGAL)


###############################################################################
## testing ####################################################################
###############################################################################

# this is for our testing framework
# we don't add REQUIRED because it's just for testing
#find_package(GTest)

if(TESTING)
    add_executable(unit_tests ${sources_test} ${sources})

    # we add this define to prevent collision with the main
    # this might be better solved by not adding the source with the main to the
    # testing target
    target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

    # this allows us to use our executable as a link library
    # therefore we can inherit all compiler options and library dependencies
    set_target_properties(unit_tests PROPERTIES ENABLE_EXPORTS on)

    target_link_libraries(unit_tests
            ASSIMP
            Boost::system Boost::filesystem Boost::log Boost::thread
            CGAL)
    #target_link_libraries(unit_tests PUBLIC
    #        ASSIMP
    #        CGAL
    #        Boost::system Boost::filesystem Boost::log Boost::thread)

    #target_include_directories(unit_tests PUBLIC
    #       ${GTEST_INCLUDE_DIRS} # doesn't do anything on Linux
    #       )
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