#
# Find Assimp
#
# Try to find Assimp : Open Asset Import Library.
# This module defines the following variables:
# - ASSIMP_INCLUDE_DIRS
# - ASSIMP_LIBRARIES
# - ASSIMP_FOUND
#
# The following variables can be set as arguments for the module.
# - ASSIMP_ROOT_DIR : Root library directory of Assimp
#
set(ASSIMP_DIR_MESSAGE     "ASSIMP not found.  Set the ASSIMP_ROOT_DIR cmake variable or environment variable to the installation directory.")
# Additional modules
include(FindPackageHandleStandardArgs)

if (WIN32)
	# Find include files
	find_path(
		ASSIMP_INCLUDE_DIR
		NAMES assimp/scene.h
		PATHS
			$ENV{PROGRAMFILES}/include
			${ASSIMP_ROOT_DIR}/include
		DOC "The directory where assimp/scene.h resides")

	# Find library files
	find_library(
		ASSIMP_LIBRARY
		NAMES x64/assimp.lib
			  x86/assimp.lib
		PATHS
			$ENV{PROGRAMFILES}/lib
			${ASSIMP_ROOT_DIR}/lib)
else()
	# Find include files
	find_path(
		ASSIMP_INCLUDE_DIR
		NAMES assimp/scene.h
		PATHS
			/usr/include
			/usr/local/include
			/sw/include
			/opt/local/include
		DOC "The directory where assimp/scene.h resides")

	# Find library files
	find_library(
		ASSIMP_LIBRARY
		NAMES assimp
		PATHS
			/usr/lib64
			/usr/lib
			/usr/local/lib64
			/usr/local/lib
			/sw/lib
			/opt/local/lib
			${ASSIMP_ROOT_DIR}/lib
		DOC "The Assimp library")
endif()

message(STATUS ${ASSIMP_INCLUDE_DIR})
message(STATUS ${ASSIMP_LIBRARY})
# Handle REQUIRD argument, define *_FOUND variable
find_package_handle_standard_args(Assimp DEFAULT_MSG ASSIMP_INCLUDE_DIR ASSIMP_LIBRARY)

if ( ASSIMP_INCLUDE_DIR )
    if( ASSIMP_LIBRARY )
		set( ASSIMP_FOUND TRUE )
	endif()
endif()

if (ASSIMP_FOUND)
	set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARY})
	set(ASSIMP_INCLUDE_DIRS ${ASSIMP_INCLUDE_DIR})
else()
	if(ASSIMP_FIND_REQUIRED)
		MESSAGE(FATAL_ERROR ${ASSIMP_DIR_MESSAGE})
	else()
		if(NOT ASSIMP_FIND_QUIETLY)
			MESSAGE(STATUS ${ASSIMP_DIR_MESSAGE})
		endif()
	endif()
endif()

# Hide some variables
mark_as_advanced(ASSIMP_INCLUDE_DIR ASSIMP_LIBRARY)

