#include "TestSNMP.hpp"

void TestSNMPUtil::testInitialFunction()
{
	int status = 0;

	Mitrais::SNMP::SNMP snmp;

	std::vector<Mitrais::SNMP::VariableBinding<std::string> > vbs;

	Mitrais::SNMP::VariableBinding<std::string> vb1;
	Mitrais::SNMP::OID oid;
	oid.oid = HOST_RESOURCES_MIB_HR_STORAGE_ALLOCATION_UNITS;
	vb1.setOID(oid);

	Mitrais::SNMP::VariableBinding<std::string> vb2;
	Mitrais::SNMP::OID oid2;
	oid2.oid = HOST_RESOURCES_MIB_HR_STORAGE_USED;
	vb2.setOID(oid);

	Mitrais::SNMP::VariableBinding<std::string> vb3;
	Mitrais::SNMP::OID oid3;
	oid3.oid = HOST_RESOURCES_MIB_HR_STORAGE_DESCR;
	vb3.setOID(oid);

	vbs.push_back(vb1);
	vbs.push_back(vb2);
	vbs.push_back(vb3);

	Mitrais::SNMP::PDU pdu;
	pdu.setBindingList(vbs);

	Mitrais::SNMP::IpAddress IpAddress;
	IpAddress.IpAddress = "127.0.0.1";
	Mitrais::SNMP::Target target;

	target.Ip = IpAddress;
	snmp.set(pdu, target, "req");

	CPPUNIT_ASSERT(status == 0);
}
