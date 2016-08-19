#include "../inc/PDU.hpp"

using namespace Mitrais::SNMP;

/*
 * PDU default Constructor
 */
PDU::PDU()
{

}

/*
 * PDU default destructor
 */
PDU::~PDU()
{

}

/*
 * Get binding list function
 *
 * @return vector<VariableBinding>
 *
 */
std::vector<VariableBinding<Binding>> PDU::getBindingList()
{
	return vb;
}

/*
 * set binding list function
 *
 * @param list of VariableBinding
 */
void PDU::setBindingList(std::vector<VariableBinding<Binding>> list)
{
	this->vb = vb;
}
