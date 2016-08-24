#include "TestSNMP.h"

void TestSNMPUtil::testInitialFunction()
{
	int status = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding<std::string> > vbs;

	Mitrais::SNMP::VariableBinding<std::string> vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = sysDescr;
	vb1.setOID(oid);

	vbs.push_back(vb1);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "127.0.0.1";
	Mitrais::SNMP::Target target;

	target.Ip = IpAddress;
	snmp.set(pdu, target, "req");

	CPPUNIT_ASSERT(status == 0);
}
