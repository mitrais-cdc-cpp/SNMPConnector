#ifndef SNMPLIB_INC_VARIABLEBINDING_H_
#define SNMPLIB_INC_VARIABLEBINDING_H_

#include <iostream>

#include "OID.hpp"
#include "ReturnStatus.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * Variable Binding class
		 */
		template<typename T>
		class VariableBinding
		{
		public:

			/*
			 * Default constructor
			 */
			VariableBinding()
			{

			}

			/*
			 * Default destructor
			 */
			~VariableBinding()
			{

			}

			/*
			 * get OID
			 *
			 * @return OID
			 */
			OID getOID()
			{
				return oid;
			}

			/*
			 * set the OID
			 *
			 * @param OID
			 */
			void setOID(OID& oid)
			{
				this->oid = oid;
			}

			/*
			 * Get value function
			 *
			 * @param T value
			 * @return Return Status
			 */
			ReturnStatus getValue(T& t)
			{
				ReturnStatus returnStatus;

				return returnStatus;
			}

		private:

			/*
			 * Value of T
			 */
			T value;

			/*
			 * The OID
			 */
			OID oid;

			/*
			 * Set value function
			 */
			void setValue(T t)
			{
				this->value = t;
			}
		};
	}
}

#endif /* SNMPLIB_INC_VARIABLEBINDING_H_ */
