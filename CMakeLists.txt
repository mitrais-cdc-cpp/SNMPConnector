cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPLib VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
 	src/*.cpp)
 
message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

include_directories(inc)  

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_library(SNMPLib SHARED ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SNMPLib PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
#set_property(TARGET SNMPLib PROPERTY CXX_STANDARD 11)
#set_property(TARGET SNMPLib PROPERTY CXX_STANDARD_REQUIRED ON)
#-DHAVE_NAMESPACE_STD -m64
add_definitions("-DSTDCXX_98_HEADERS -D_SNMPv3")

###############################################################################
## generate documentation #####################################################
###############################################################################

find_package(Doxygen)
add_custom_target (doc ALL
	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doxy/*.doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxy
)

###############################################################################
## dependencies ###############################################################
###############################################################################

#SNMP++
set(SNMP_PP_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib)
set(SNMP_PP_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/include)

find_library(
    SNMP_PP_LIBRARIES
    NAMES snmp++
    PATHS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

include_directories(${SNMP_PP_INCLUDE_DIRS})
link_directories(${SNMP_PP_LIBRARY_DIRS})
target_link_libraries(SNMPLib ${SNMP_PP_LIBRARIES})

####################
##  Installation  ##
####################

# Set installation destination folder for .so and .h files.
# Change the destination folder
###############################l
set(INSTALLATION_DIR "SNMPLib/lib")
set(HEADER_DIR "SNMPLib/inc")
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_LIST_DIR}/env/" CACHE PATH "default install path" FORCE )
endif()

# Set header location that will be copied
file(GLOB HEADERS inc/*)

# Install .so file
#install(TARGETS MongoDao DESTINATION ${INSTALLATION_DIR}
#	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

INSTALL( FILES "${CMAKE_CURRENT_SOURCE_DIR}/build/libSNMPLib.so"
	DESTINATION ${INSTALLATION_DIR}
	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

# Install .h files
foreach(ITEM ${HEADERS})
   IF( IS_DIRECTORY "${ITEM}" )
      LIST( APPEND DIRS_TO_DEPLOY "${ITEM}" )
   ELSE()
      LIST( APPEND FILES_TO_DEPLOY "${ITEM}" )
   ENDIF()
endforeach()

INSTALL( FILES ${FILES_TO_DEPLOY} DESTINATION ${HEADER_DIR} 
	PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ WORLD_WRITE)

INSTALL( DIRECTORY ${DIRS_TO_DEPLOY} DESTINATION ${HEADER_DIR} )