#ifndef SNMPLIB_INC_PDU_H_
#define SNMPLIB_INC_PDU_H_

#include <vector>

#include "VariableBinding.hpp"
#include "Binding.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * PDU class
		 */
		class PDU
		{
		public:

			/*
			 * Default constructor
			 */
			PDU();

			/*
			 * Default destructor
			 */
			~PDU();

			/*
			 * Get binding list function
			 *
			 * @return vector<VariableBinding>
			 *
			 */
			std::vector<VariableBinding<Binding>> getBindingList();

			/*
			 * set binding list function
			 *
			 * @param list of VariableBinding
			 */
			void setBindingList(std::vector<VariableBinding<Binding>> list);


		private:
			std::vector<VariableBinding<Binding>> vb;
		};
	}
}

#endif /* SNMPLIB_INC_PDU_H_ */
