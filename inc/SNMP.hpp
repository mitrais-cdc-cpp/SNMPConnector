#ifndef INC_SNMP_HPP_
#define INC_SNMP_HPP_

#include <iostream>

#include "PDU.hpp"
#include "Target.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		class SNMP
		{
			public:

				/*
				 * Default constructor
				 */
				SNMP();

				/*
				 * Default destructor
				 */
				~SNMP();

				/*
				 * Set function
				 * @param PDU
				 * @param Target
				 *
				 * @return ReturnStatus
				 */
				ReturnStatus set(PDU, Target);
		};
	}
}

#endif /* INC_SNMP_HPP_ */
