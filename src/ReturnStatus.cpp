#include "../inc/ReturnStatus.hpp"

using namespace Mitrais::SNMP;

/*
 * Return Status default Constructor
 */
ReturnStatus::ReturnStatus()
{

}

/*
 * Return Status default destructor
 */
ReturnStatus::~ReturnStatus()
{

}


/*
 * Check the error status
 *
 * @return the error status
 */
bool ReturnStatus::isError()
{
	return false;
}

/*
 * Get error message function
 *
 * @return get error message
 */
std::string ReturnStatus::getErrorMessage()
{
	return "Error message";
}

/*
 * Get error code function
 *
 * @return error code in integer
 */
int ReturnStatus::getErrorCode()
{
	return 0;
}
