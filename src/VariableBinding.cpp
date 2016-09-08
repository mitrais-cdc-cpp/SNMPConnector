#include "../inc/VariableBinding.hpp"

using namespace Mitrais::SNMP;

/**
 * Default constructor
 */
VariableBinding::VariableBinding()
{

}

/**
 * Default destructor
 */
VariableBinding::~VariableBinding()
{

}

/**
 * get OID
 *
 * @return OID
 */
OID VariableBinding::getOID()
{
	return oid_;
}

/**
 * set the OID
 *
 * @param oid
 */
void VariableBinding::setOID(OID& oid)
{
	this->oid_ = oid;
}

/**
 * get Value functuon
 *
 * @param value
 * @return
 */
ReturnStatus VariableBinding::getValue(std::string& value)
{
	ReturnStatus status;

	value = value_;

	return status;
}

/**
 * Set value function
 */
void VariableBinding::setValue(std::string value)
{
	value_ = value;
}
