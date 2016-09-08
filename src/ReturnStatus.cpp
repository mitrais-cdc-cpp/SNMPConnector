#include "../inc/ReturnStatus.hpp"

using namespace Mitrais::SNMP;

/**
 * Return Status default Constructor
 */
ReturnStatus::ReturnStatus() : errorCode_(0), isError_(false), errorMessage_("")
{

}

/**
 * Default destructor
 */
ReturnStatus::~ReturnStatus()
{

}

/**
 * Return Status Constructor with one parameter
 *
 * @param isError
 */
ReturnStatus::ReturnStatus(bool isError): isError_(isError), errorCode_(0), errorMessage_("")
{

}

/**
 * Return Status Constructor with two parameter
 *
 * @param isError
 * @param errorMessage
 */
ReturnStatus::ReturnStatus(bool isError, std::string errorMessage)
		:isError_(isError), errorMessage_(errorMessage), errorCode_(0)
{

}

/**
 * Return Status Constructor with two parameter			 *
 *
 * @param isError
 * @param errorCode
 */
ReturnStatus::ReturnStatus(bool isError, int errorCode) :
		isError_(isError), errorCode_(errorCode),  errorMessage_("")
{

}

/**
 * Return Status Constructor with three parameter
 *
 * @param isError
 * @param errorMessage
 * @param errorCode
 */
ReturnStatus::ReturnStatus(bool isError, std::string errorMessage, int errorCode) :
		isError_(isError), errorMessage_(errorMessage), errorCode_(errorCode)
{

}

/**
 * Check the error status
 *
 * @return the error status
 */
bool ReturnStatus::isError()
{
	return isError_;
}

/**
 * Get error message function
 *
 * @return get error message
 */
std::string ReturnStatus::getErrorMessage()
{
	return errorMessage_;
}

/**
 * Get error code function
 *
 * @return error code in integer
 */
int ReturnStatus::getErrorCode()
{
	return errorCode_;
}

/**
 * Set error properties
 *
 * @param isError
 * @param errorMessage
 * @param errorCode
 */
void ReturnStatus::setError(bool isError, std::string errorMessage, int errorCode)
{
	isError_ = isError;
	errorMessage_ = errorMessage;
	errorCode_ = errorCode;
}

/**
 * Set is Error flag
 *
 * @param isError
 */
void ReturnStatus::setIsError(bool isError)
{
	isError_ = isError;
}

/**
 * Set error message
 *
 * @param errorMessage
 */
void ReturnStatus::setErrorMessage(std::string errorMessage)
{
	errorMessage_ = errorMessage;
}

/**
 * Set error code
 *
 * @param errorCode
 */
void ReturnStatus::setErrorCode(int errorCode)
{
	errorCode_ = errorCode;
}
