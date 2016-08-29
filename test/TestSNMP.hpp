#ifndef SNMPLib_TEST_TESTSNMPLib_H_
#define SNMPLib_TEST_TESTSNMPLib_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../inc/SNMP.hpp"

class TestSNMPUtil: public CppUnit::TestFixture
{
public:
	CPPUNIT_TEST_SUITE(TestSNMPUtil);
	CPPUNIT_TEST(testSystemDescription);
	CPPUNIT_TEST(testSystemUpTime);
	CPPUNIT_TEST(testSystemName);
	CPPUNIT_TEST_SUITE_END();

private:
	void testSystemDescription();
	void testSystemUpTime();
	void testSystemName();

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestSNMPUtil );

#endif /* SNMPLib_TEST_TESTSNMPLib_H_ */
