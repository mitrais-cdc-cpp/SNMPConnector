#include "../inc/VariableBinding.h"

using namespace Mitrais::SNMP;

/*
 * VariableBinding default Constructor
 */
VariableBinding::VariableBinding()
{

}

/*
 * VariableBinding default destructor
 */
VariableBinding::~VariableBinding()
{

}

/*
 * get OID
 *
 * @return OID
 */
OID VariableBinding::getOID()
{
	return oid;
}

/*
 * set the OID
 *
 * @param OID
 */
void VariableBinding::setOID(OID& oid)
{
	this->oid = oid;
}
