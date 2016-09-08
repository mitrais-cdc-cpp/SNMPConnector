#include "../inc/SNMP.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>

#include <snmp_pp/snmp_pp.h>

using namespace Mitrais::SNMP;

/**
 * Default constructor
 */
SNMP::SNMP()
{

}

/**
 * Default destructor
 */
SNMP::~SNMP()
{

}

/**
 * Set function
 *
 * @param pdu
 * @param target
 * @param mode
 * @return ReturnStatus
 */
ReturnStatus SNMP::set(PDU& pdu, Target target, SnmpMode mode)
{
	ReturnStatus status;

	int statusCode = 0;

	std::string errorMessage;

	// Initialize socket subsystem
	Snmp_pp::Snmp::socket_startup();

	if (target.Ip.IpAddress.empty())
	{
		errorMessage = "There is no IP Address in target";

		return setErrorMessage(errorMessage, statusCode);
	}

	char* ipAddress = new char[target.Ip.IpAddress.length() + 1];
	strcpy(ipAddress, target.Ip.IpAddress.c_str());

	Snmp_pp::IpAddress ipAddr(ipAddress);

	if (!ipAddr.valid())
	{
		errorMessage = "Invalid destination: " + target.Ip.IpAddress;

		return setErrorMessage(errorMessage, statusCode);
	}

	// bind to any port and use IPv6 if needed
	Snmp_pp::Snmp snmp(statusCode, 0, (ipAddr.get_ip_version() == Snmp_pp::Address::version_ipv6));

	if (statusCode)
	{
		std::string message(snmp.error_msg(statusCode));

		errorMessage = "Failed to create SNMP Session: " + message;

		return setErrorMessage(errorMessage, statusCode);
	}

	Snmp_pp::CTarget targetSnmp(ipAddr);

	if (!targetSnmp.valid())
	{
		errorMessage = "Invalid target" + target.Ip.IpAddress;

		return setErrorMessage(errorMessage, statusCode);
	}

	Snmp_pp::Pdu pduSnmp;
	Snmp_pp::Vb vbSnmp;
	
	int numberOfDataBinding = pdu.getBindingList().size();

	Snmp_pp::Vb vbl[numberOfDataBinding];

	std::vector<VariableBinding> vb = pdu.getBindingList();

	for (int i = 0; i < numberOfDataBinding; i++)
	{
		char* oidAddress = new char[vb[i].getOID().oid.length() + 1];
		strcpy(oidAddress, vb[i].getOID().oid.c_str());

		Snmp_pp::Oid oid(oidAddress);

		vbl[i].set_oid(oid);
	}

	// set PDU SNMP
	pduSnmp.set_vblist(vbl, numberOfDataBinding);

	switch (mode)
	{
		case REQUEST:
		{
			std::cout << "Send a GET-REQUEST to: " << ipAddr.get_printable() << std::endl;

			statusCode = snmp.get(pduSnmp, targetSnmp);

			if (statusCode)
			{
				std::string message(snmp.error_msg(statusCode));

				errorMessage = "Failed to issue SNMP Get: " + message;

				return setErrorMessage(errorMessage, statusCode);
			}
			else
			{
				std::cout << "Issued get successfully" << std::endl;

				pduSnmp.get_vblist(vbl, numberOfDataBinding);

				//pdu = setVariableBindingValue(pduSnmp, vbl);

				std::vector<Mitrais::SNMP::VariableBinding> vbs;

				int vbcount = pduSnmp.get_vb_count();

				for ( int i = 0; i<vbcount; i++ )
				{
					Mitrais::SNMP::VariableBinding vb;
					Mitrais::SNMP::OID oid;
					oid.oid = vbl[i].get_printable_oid();
					vb.setOID(oid);
					vb.setValue(vbl[i].get_printable_value());

					std::cout << vbl[i].get_printable_oid() << " : " <<
						  vbl[i].get_printable_value() << std::endl;

					vbs.push_back(vb);
				}

				pdu.setBindingList(vbs);
			}
		}
			break;
		case TRAP:
		{
			std::cout << "Send a TRAP to: " << ipAddr.get_printable() << std::endl;

			statusCode = snmp.trap(pduSnmp, targetSnmp);

			if (statusCode)
			{
				std::string message(snmp.error_msg(statusCode));

				errorMessage = "Failed to issue SNMP Trap: " + message;

				return setErrorMessage(errorMessage, statusCode);

			}
			else
			{
				std::cout << "Success" << std::endl;
			}
		}
			break;
	}

	Snmp_pp::Snmp::socket_cleanup();  // Shut down socket subsystem

	return status;
}

/**
 * Set error function
 *
 * @param message
 * @param errorCode
 * @return
 */
ReturnStatus SNMP::setErrorMessage(std::string message, int errorCode)
{
	ReturnStatus status(true, message, errorCode);

	std::cout << message << ". Error code : " << errorCode << std::endl;

	return status;
}
