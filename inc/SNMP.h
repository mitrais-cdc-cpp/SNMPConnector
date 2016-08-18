#ifndef INC_SNMP_H_
#define INC_SNMP_H_

#include <iostream>

#include "PDU.h"
#include "Target.h"

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

#endif /* INC_SNMP_H_ */
