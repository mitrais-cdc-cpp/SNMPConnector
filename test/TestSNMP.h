#ifndef SNMPLib_TEST_TESTSNMPLib_H_
#define SNMPLib_TEST_TESTSNMPLib_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../inc/SNMP.hpp"

class TestSNMPUtil: public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(TestSNMPUtil);
	CPPUNIT_TEST(testInitialFucntion);
	CPPUNIT_TEST_SUITE_END();

private:
	void testInitialFucntion();

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestSNMPUtil );

#endif /* SNMPLib_TEST_TESTSNMPLib_H_ */
