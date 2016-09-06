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
 * @param OID
 */
void VariableBinding::setOID(OID& oid)
{
	this->oid_ = oid;
}

/**
 * Get value function
 *
 * @param T value
 * @return Return Status
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
