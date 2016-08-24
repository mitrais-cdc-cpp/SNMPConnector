#ifndef SNMPLIB_INC_PDU_H_
#define SNMPLIB_INC_PDU_H_

#include <vector>
#include <sys/socket.h>

#include "Data.hpp"
#include "VariableBinding.hpp"

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
			std::vector<VariableBinding<std::string> > getBindingList();

			/*
			 * set binding list function
			 *
			 * @param list of VariableBinding
			 */
			void setBindingList(std::vector<VariableBinding<std::string> > list);


		private:
			std::vector<VariableBinding<std::string> > vb;
		};
	}
}

#endif /* SNMPLIB_INC_PDU_H_ */
