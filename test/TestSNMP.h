#ifndef SNMPLib_TEST_TESTSNMPLib_H_
#define SNMPLib_TEST_TESTSNMPLib_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../inc/SNMP.hpp"
#include "../inc/SnmpMode.hpp"
#include <string>

#define NUM_SYS_VBS	6
#define sysDescr	"1.3.6.1.2.1.1.1.0"
#define sysObjectID	"1.3.6.1.2.1.1.2.0"
#define sysUpTime	"1.3.6.1.2.1.1.3.0"
#define sysContact	"1.3.6.1.2.1.1.4.0"
#define sysName		"1.3.6.1.2.1.1.5.0"
#define sysLocation	"1.3.6.1.2.1.1.6.0"


class TestSNMPUtil: public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(TestSNMPUtil);
	CPPUNIT_TEST(testInitialFunction);
	CPPUNIT_TEST_SUITE_END();

private:
	void testInitialFunction();

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestSNMPUtil );

#endif /* SNMPLib_TEST_TESTSNMPLib_H_ */
