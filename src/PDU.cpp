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
std::vector<VariableBinding<std::string> > PDU::getBindingList()
{
	return vb;
}

/*
 * set binding list function
 *
 * @param list of VariableBinding
 */
void PDU::setBindingList(std::vector<VariableBinding<std::string> > list)
{
	this->vb = vb;
}
