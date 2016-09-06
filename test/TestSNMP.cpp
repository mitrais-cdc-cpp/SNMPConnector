#include "TestSNMP.hpp"

/**
 * testSystemDescription
 */
void TestSNMPUtil::testSystemDescription()
{
	int statusCode = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding> vbs;

	Mitrais::SNMP::VariableBinding vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = SYSTEM_DESCRIPTION;
	vb1.setOID(oid);

	vbs.push_back(vb1);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "172.19.12.29";
	Mitrais::SNMP::Target target;

	Mitrais::SNMP::ReturnStatus status;

	target.Ip = IpAddress;
	status = snmp.set(pdu, target, Mitrais::SNMP::REQUEST);

	std::string expectedValue = "Hardware: Intel64 Family 6 Model 45 Stepping 7 AT/AT COMPATIBLE - Software: Windows Version 6.1 (Build 7601 Multiprocessor Free)";

	std::string result;
	pdu.getBindingList()[0].getValue(result);

	CPPUNIT_ASSERT(status.getErrorCode() == 0);
	CPPUNIT_ASSERT(result.compare(expectedValue) == 0);
}

/**
 * testSystemUpTime
 */
void TestSNMPUtil::testSystemUpTime()
{
	int statusCode = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding> vbs;

	Mitrais::SNMP::VariableBinding vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = SYSTEM_UP_TIME;
	vb1.setOID(oid);

	vbs.push_back(vb1);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "172.19.12.29";
	Mitrais::SNMP::Target target;

	Mitrais::SNMP::ReturnStatus status;

	target.Ip = IpAddress;
	status = snmp.set(pdu, target, Mitrais::SNMP::REQUEST);

	std::string result;
	pdu.getBindingList()[0].getValue(result);

	CPPUNIT_ASSERT(status.getErrorCode() == 0);
	CPPUNIT_ASSERT(!result.empty());
}

/**
 * testSystemName
 */
void TestSNMPUtil::testSystemName()
{
	int statusCode = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding> vbs;

	Mitrais::SNMP::VariableBinding vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = SYSTEM_NAME;
	vb1.setOID(oid);

	vbs.push_back(vb1);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "172.19.12.29";
	Mitrais::SNMP::Target target;

	Mitrais::SNMP::ReturnStatus status;

	target.Ip = IpAddress;
	status = snmp.set(pdu, target, Mitrais::SNMP::REQUEST);

	std::string expectedValue = "NemstaSNMP.mitrais.com";

	std::string result;
	pdu.getBindingList()[0].getValue(result);

	CPPUNIT_ASSERT(status.getErrorCode() == 0);
	CPPUNIT_ASSERT(result.compare(expectedValue) == 0);
}

/**
 * testMultipleVariableBinding
 */
void TestSNMPUtil::testMultipleVariableBinding()
{
	int statusCode = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding> vbs;

	Mitrais::SNMP::VariableBinding vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = SYSTEM_DESCRIPTION;
	vb1.setOID(oid);

	vbs.push_back(vb1);

	Mitrais::SNMP::VariableBinding vb2;
	Mitrais::SNMP::OID oid2;
	oid2.oid = SYSTEM_UP_TIME;
	vb2.setOID(oid2);

	vbs.push_back(vb2);

	Mitrais::SNMP::VariableBinding vb3;
	Mitrais::SNMP::OID oid3;
	oid3.oid = SYSTEM_NAME;
	vb3.setOID(oid3);

	vbs.push_back(vb3);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "172.19.12.29";
	Mitrais::SNMP::Target target;

	Mitrais::SNMP::ReturnStatus status;

	target.Ip = IpAddress;
	status = snmp.set(pdu, target, Mitrais::SNMP::REQUEST);

	std::string expectedValue = "Hardware: Intel64 Family 6 Model 45 Stepping 7 AT/AT COMPATIBLE - Software: Windows Version 6.1 (Build 7601 Multiprocessor Free)";

	std::string result;
	pdu.getBindingList()[0].getValue(result);

	CPPUNIT_ASSERT(status.getErrorCode() == 0);
	CPPUNIT_ASSERT(result.compare(expectedValue) == 0);
}
