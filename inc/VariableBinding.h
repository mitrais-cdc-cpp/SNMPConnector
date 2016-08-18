#ifndef SNMPLIB_INC_VARIABLEBINDING_H_
#define SNMPLIB_INC_VARIABLEBINDING_H_

#include <iostream>

#include "OID.h"
#include "ReturnStatus.h"

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * Variable Binding class
		 */
		class VariableBinding
		{
		public:

			/*
			 * Default constructor
			 */
			VariableBinding();

			/*
			 * Default destructor
			 */
			~VariableBinding();

			/*
			 * Value of T
			 */
			// TODO: Error when complie it
			// error: data member ‘value’ cannot be a member template
			//template<typename T>
			//T value;

			/*
			 * The OID
			 */
			OID oid;

			/*
			 * get OID
			 *
			 * @return OID
			 */
			OID getOID();

			/*
			 * set the OID
			 *
			 * @param OID
			 */
			void setOID(OID& oid);

			/*
			 * Get value function
			 *
			 * @param T value
			 * @return Return Status
			 */
			template<typename T>
			ReturnStatus getValue(T& t);

		private:
			template<typename T>
			void setValue(T);
		};
	}
}

#endif /* SNMPLIB_INC_VARIABLEBINDING_H_ */
