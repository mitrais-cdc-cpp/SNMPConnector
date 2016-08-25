#ifndef INC_SNMP_HPP_
#define INC_SNMP_HPP_

#include <iostream>

#include "PDU.hpp"
#include "Target.hpp"

#include "../env/snmp_pp/include/snmp_pp/snmp_pp.h"

namespace Mitrais
{
	namespace SNMP
	{
		class SNMP
		{
			public:

				/*
				 * Set function
				 * @param PDU
				 * @param Target
				 * @param mode (Request or Trap)
				 *
				 * @return ReturnStatus
				 */
				ReturnStatus set(PDU pdu, Target target, std::string mode);
		};
	}
}

#endif /* INC_SNMP_HPP_ */
