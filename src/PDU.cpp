#include "../inc/PDU.h"

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
std::vector<VariableBinding> PDU::getBindingList()
{
	std::vector<VariableBinding> list;
	return list;
}

/*
 * set binding list function
 *
 * @param list of VariableBinding
 */
void setBindingList(std::vector<VariableBinding>& list)
{

}
