#ifndef INC_SNMP_HPP_
#define INC_SNMP_HPP_

#include <iostream>

#include "PDU.hpp"
#include "Target.hpp"
#include "MibDefinitions.hpp"
#include "SnmpMode.hpp"

#include "../env/snmp_pp/include/snmp_pp/snmp_pp.h"

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
				 * @param mode (Request or Trap)
				 *
				 * @return ReturnStatus
				 */
				ReturnStatus set(PDU& pdu, Target target, SnmpMode mode);

			private:
				/*
				 * Set error function
				 *
				 * @param message
				 * @param error code
				 */
				ReturnStatus setErrorMessage(std::string message, int errorCode);

				/*
				 * Set Variable Binding Value
				 *
				 * @param PDU
				 * @param oid
				 * @param value
				 */
				void setVariableBindingValue(PDU& pdu, std::string oid, std::string value);
		};
	}
}

#endif /* INC_SNMP_HPP_ */
