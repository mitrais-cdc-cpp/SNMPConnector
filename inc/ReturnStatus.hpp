#ifndef SNMPLIB_INC_RETURNSTATUS_H_
#define SNMPLIB_INC_RETURNSTATUS_H_

#include <iostream>

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * Return Status class
		 */
		class ReturnStatus
		{
		public:

			/*
			 * Return Status default Constructor
			 */
			ReturnStatus();

			/*
			 * Return Status default destructor
			 */
			~ReturnStatus();

			/*
			 * Check the error status
			 *
			 * @return the error status
			 */
			bool isError();

			/*
			 * Get error message function
			 *
			 * @return get error message
			 */
			std::string getErrorMessage();

			/*
			 * Get error code function
			 *
			 * @return error code in integer
			 */
			int getErrorCode();
		};
	}
}

#endif /* SNMPLIB_INC_RETURNSTATUS_H_ */
