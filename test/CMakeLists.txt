cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPLib_Test VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
 *.h
 *.cpp)

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(SNMPLib_Test ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SNMPLib_Test PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET SNMPLib_Test PROPERTY CXX_STANDARD 11)
set_property(TARGET SNMPLib_Test PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# MongoDao
#set(SNMPLib_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}../build") # the directory containing "include" and "lib"
#set(SNMPLib_INCLUDE_DIR"${CMAKE_CURRENT_SOURCE_DIR}../inc")
#set(SNMPLib_LIB_DIR "${SNMPLib_PREFIX}")
#set(SNMPLib_LIBS
#        "${SNMPLib_LIB_DIR}/libMongoDao.a")
        
set(SNMPLib_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../build)  
set(SNMPLib_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../inc)  
find_library(  
	SNMPLib_LIBRARIES  
	NAMES SNMPLib  
	PATHS ${CMAKE_CURRENT_LIST_DIR}/../build  
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)  

# CPPUNIT
find_library(CPPUNIT_LIBRARY_DEBUG NAMES cppunit cppunit_dll cppunitd cppunitd_dll
            	PATHS  
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES debug )

find_library(CPPUNIT_LIBRARY_RELEASE NAMES cppunit cppunit_dll
            PATHS   ${PATH}/lib
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES release )

if(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)
    set(CPPUNIT_LIBRARY_RELEASE ${CPPUNIT_LIBRARY_DEBUG})
endif(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)

set( CPPUNIT_LIBRARY debug ${CPPUNIT_LIBRARY_DEBUG} optimized ${CPPUNIT_LIBRARY_RELEASE} )

include_directories(${SNMPLib_INCLUDE} )
link_directories(${SNMPLib_LIBRARY_DIRS} ${CPPUNIT_LIBRARY})
target_link_libraries(SNMPLib_Test ${SNMPLib_LIBRARIES} ${CPPUNIT_LIBRARY})