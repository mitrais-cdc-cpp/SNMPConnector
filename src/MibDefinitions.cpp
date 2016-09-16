/*
 * MibDefinitions.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: developer
 */

#include "../inc/MibDefinitions.hpp"

/**
 * Function to get SNMP Object name by given OID
 * @param OID
 * @return SNMP Object name
 */
std::string getSNMPNameByOID(const std::string &OID) {
  if (OID == "1.3.6.1.2.1.1.1.0") {
    return "SYSTEM_DESCRIPTION";
  } else if (OID == "1.3.6.1.2.1.1.3.0") {
    return "SYSTEM_UP_TIME";
  } else if (OID == "1.3.6.1.2.1.1.5.0") {
    return "SYSTEM_NAME";
  } else if (OID == "1.3.6.1.2.1.1.6.0") {
    return "SYSTEM_LOCATION";
  } else if (OID == "1.3.6.1.2.1.11.1.0") {
    return "RFC1213_MIB_SNMP_IN_PKTS";
  } else if (OID == "1.3.6.1.2.1.11.19.0") {
    return "RFC1213_MIB_SNMP_IN_TRAPS";
  } else if (OID == "1.3.6.1.2.1.25.2.2.0") {
    return "HOST_RESOURCES_MIB_HR_MEMORY_SIZE";
  } else if (OID == "1.3.6.1.2.1.25.3.3.1.1.3") {
    return "HOST_RESOURCES_MIB_HR_PROCESSOR_FRW_ID";
  } else if (OID == "1.3.6.1.2.1.25.3.3.1.2.3") {
    return "HOST_RESOURCES_MIB_HR_PROCESSOR_LOAD";
  } else if (OID == "1.3.6.1.2.1.25.3.5.1.1.1") {
    return "HOST_RESOURCES_MIB_HR_PRINTER_STATUS";
  } else if (OID == "1.3.6.1.2.1.25.2.3.1.2.5") {
    return "HOST_RESOURCES_MIB_HR_STORAGE_TYPE";
  } else if (OID == "1.3.6.1.2.1.25.2.3.1.3.2") {
    return "HOST_RESOURCES_MIB_HR_STORAGE_DESCR";
  } else if (OID == "1.3.6.1.2.1.25.2.3.1.6.2") {
    return "HOST_RESOURCES_MIB_HR_STORAGE_USED";
  } else if (OID == "1.3.6.1.2.1.25.2.3.1.4.4") {
    return "HOST_RESOURCES_MIB_HR_STORAGE_ALLOCATION_UNITS";
  } else if (OID == "1.3.6.1.2.1.2.2.1.6.11") {
    return "RFC1213_MIB_IF_PHYS_ADDRESS";
  } else {
    return "NOT_FOUND";
  }
}
