#include "../inc/SNMP.hpp"

using namespace Mitrais::SNMP;

/*
 * Set function
 * @param PDU
 * @param Target
 *
 * @return ReturnStatus
 */
ReturnStatus SNMP::set(PDU pdu, Target target, std::string mode)
{
	ReturnStatus status;

	int statusCode;

	std::string errorMessage;

	// Initialize socket subsystem
	Snmp_pp::Snmp::socket_startup();

	if (target.Ip.IpAddress.empty())
	{
		errorMessage = "There is no IP Address in target";

		status.setError(true, errorMessage, 1);

		return status;
	}

	char* ipAddress = new char[target.Ip.IpAddress.length() + 1];
	strcpy(ipAddress, target.Ip.IpAddress.c_str());

	Snmp_pp::IpAddress ipAddr(ipAddress);

	if (!ipAddr.valid())
	{
		errorMessage = "Invalid destination: " + target.Ip.IpAddress;

		status.setError(true, errorMessage, 1);

		return status;
	}

	// bind to any port and use IPv6 if needed
	Snmp_pp::Snmp snmp(statusCode, 0, (ipAddr.get_ip_version() == Snmp_pp::Address::version_ipv6));

	if (statusCode)
	{
		errorMessage = "Failed to create SNMP Session: " + statusCode;

		status.setError(true, errorMessage, statusCode);

		return status;
	}

	Snmp_pp::CTarget targetSnmp(ipAddr);

	if (!targetSnmp.valid())
	{
		errorMessage = "Invalid target" + target.Ip.IpAddress;

		status.setError(true, errorMessage, 1);

		return status;
	}

	Snmp_pp::Pdu pduSnmp;
	Snmp_pp::Vb vb;

	int numberOfDataBinding = pdu.getBindingList().size();

	Snmp_pp::Vb vbl[numberOfDataBinding];

	for (int i = 0; i < numberOfDataBinding; i++)
	{
		const char *oidAddress = pdu.getBindingList()[i].getOID().oid.c_str();

		Snmp_pp::Oid oid(oidAddress);

		vbl[i].set_oid(oid);

		//delete [] oidAddress;
	}

	// set PDU SNMP
	pduSnmp.set_vblist(vbl, numberOfDataBinding);

	if (mode.compare("req") == 0)
	{
	    std::cout << "Send a GET-REQUEST to: " << ipAddr.get_printable() << std::endl;

	    statusCode = snmp.get(pduSnmp, targetSnmp);

	    if (statusCode)
	    {
	    	errorMessage = "Failed to issue SNMP Get: " + statusCode;

	    	// snmp.error_msg(statusCode);

			status.setError(true, errorMessage, statusCode);

			return status;
	    }
	    else
	    {
	    	std::cout << "Issued get successfully" << std::endl;

	    	int vbcount = pduSnmp.get_vb_count();
	    	if (vbcount == pdu.getBindingList().size())
	    	{
	    		pduSnmp.get_vblist(vbl, vbcount);

	    		for ( int i=0; i<vbcount ; i++ )
	    		{
	    			std::cout << vbl[i].get_printable_oid() << " : " <<
						  vbl[i].get_printable_value() << std::endl;
	    		}
	    	}
	    	else
	    	{
	    		for ( int i=0; i<vbcount ; i++ )
	    		{
	    			pduSnmp.get_vb(vb, i);
	    			std::cout << vb.get_printable_oid() << " : " <<
						  vb.get_printable_value() << std::endl;
	    		}
	    	}
	    }
	}
	else if (mode.compare("trap") == 0)
	{
	    std::cout << "Send a TRAP to: " << ipAddr.get_printable() << std::endl;

	    statusCode = snmp.trap(pduSnmp, targetSnmp);

	    if (statusCode)
	    {
	    	errorMessage = "Failed to issue SNMP Trap: " + statusCode;

	    	// snmp.error_msg(status)

	    	status.setError(true, errorMessage, statusCode);

	    	return status;

	    }
	    else
	    {
	    	std::cout << "Success" << std::endl;
	    }
	}

	delete [] ipAddress;

	Snmp_pp::Snmp::socket_cleanup();  // Shut down socket subsystem

	return status;
}
