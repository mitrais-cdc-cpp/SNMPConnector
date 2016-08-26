#include "TestSNMP.hpp"

void TestSNMPUtil::testInitialFunction()
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

	// TODO get actual value from
	// pdu.getBindingList()[0].getValue();

	CPPUNIT_ASSERT(status.getErrorCode() == 0);
}
