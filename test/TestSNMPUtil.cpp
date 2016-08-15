#include "TestSNMPUtil.h"

using namespace Mitrais::SNMP;

void TestSNMPUtil::testInitialFucntion()
{
	SNMPUtil util;
	std::string result = util.capturePackage();

	std::string actual = "Package captured";

	int status = result.compare(actual);

	CPPUNIT_ASSERT(status == 0);
}

