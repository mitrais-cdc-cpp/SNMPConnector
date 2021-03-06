cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(SNMPLibTest VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
	main.cpp	
	*.hpp
	*.cpp)

#to take control which files are used, dont go recursive through
#file(GLOB_RECURSE SOURCES src/*.cpp inc/*.h)

message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(SNMPLibTest ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SNMPLibTest PUBLIC -Wextra)


###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
#set_property(TARGET SNMPLibTest PROPERTY CXX_STANDARD 11)
#set_property(TARGET SNMPLibTest PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions("-DSTDCXX_98_HEADERS -D_SNMPv3")

###############################################################################
## dependencies ###############################################################
###############################################################################

# THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

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

#SNMP++
set(SNMP_PP_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/snmp_pp/lib)
set(SNMP_PP_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/snmp_pp/include)

find_library(
    SNMP_PP_LIBRARIES
    NAMES snmp++
    PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/snmp_pp/lib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

# SNMPLIB
set(SNMPLIB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../build)
set(SNMPLIB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../inc)

find_library(
    SNMPLIB_LIBRARIES
    NAMES SNMPLib
    PATHS ${CMAKE_CURRENT_LIST_DIR}/../build
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

# TEST FILES
#file(GLOB TEST_FILES "test_files/*")
#file(COPY ${TEST_FILES} DESTINATION .)

include_directories(${SNMPLIB_INCLUDE_DIRS} ${SNMP_PP_INCLUDE_DIRS})
link_directories(${CPPUNIT_LIBRARY} ${SNMPLIB_LIBRARY_DIRS} ${SNMP_PP_LIBRARY_DIRS})
target_link_libraries(SNMPLibTest ${SNMPLIB_LIBRARIES} ${CPPUNIT_LIBRARY} ${SNMP_PP_LIBRARIES})