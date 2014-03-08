################################################
# CMake Library Constants
################################################
SET( MAIN_PRODUCT_OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/Product" )
SET( MAIN_INCLUDE_DIR        "${CMAKE_CURRENT_LIST_DIR}/Include" )

################################################
# Library Generation Code
################################################
CMAKE_MINIMUM_REQUIRED( VERSION 2.8.7 )
PROJECT( MathLibrary CXX )

################################################
# Library Compiler Flags
################################################
IF( WIN32 )
  
  SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /W3" )

ELSE( WIN32 )
  
  SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Werror -Wno-missing-braces" )

ENDIF( WIN32 )

################################################
# Library Dependencies
################################################
ADD_SUBDIRECTORY( Dependencies/Utility )
INCLUDE_DIRECTORIES( ${UTILITY_INCLUDE_DIRS} )
LINK_DIRECTORIES   ( ${UTILITY_LIBRARY_DIRS} )

################################################
# Library Generation Configuration
################################################
INCLUDE_DIRECTORIES( ${MAIN_INCLUDE_DIR} )
SET( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MAIN_PRODUCT_OUTPUT_DIR} )

ADD_SUBDIRECTORY( Source )
ADD_LIBRARY( MathLib ${LIB_SOURCES} )

TARGET_LINK_LIBRARIES( MathLib
  ${UTILITY_LIBRARY}
)

IF( NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_LIST_DIR )

  ################################################
  # Library Definitions for Inclusion
  ################################################
  SET( MATH_LIBRARY      "MathLib"                  CACHE STRING "Math Library Name"              )
  SET( MATH_INCLUDE_DIRS ${MAIN_INCLUDE_DIR}        CACHE STRING "Math Library Include Directory" )
  SET( MATH_LIBRARY_DIRS ${MAIN_PRODUCT_OUTPUT_DIR} CACHE STRING "Math Library Product Directory" )

ENDIF( NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_LIST_DIR )
