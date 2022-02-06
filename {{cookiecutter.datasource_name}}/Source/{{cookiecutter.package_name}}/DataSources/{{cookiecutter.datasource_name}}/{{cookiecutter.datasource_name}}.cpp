/**
 * @file {{cookiecutter.datasource_name}}.cpp
 * @brief Source file for class {{cookiecutter.datasource_name}}
 * @date {{cookiecutter.date}}
 * @author {{cookiecutter.author}}
 */

{{cookiecutter.copyright}}

{{cookiecutter.implementation_details}}

/*---------------------------------------------------------------------------*/
/*                         Standard header includes                          */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                         Project header includes                           */
/*---------------------------------------------------------------------------*/
#include "AdvancedErrorManagement.h"
#include "CLASSMETHODREGISTER.h"
#include "Directory.h"
#include "{{cookiecutter.datasource_name}}.h"
#include "MemoryMapSynchronisedInputBroker.h"
#include "TypeConversion.h"

/*---------------------------------------------------------------------------*/
/*                           Static definitions                              */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                           Method definitions                              */
/*---------------------------------------------------------------------------*/
namespace MARTe {

{{cookiecutter.datasource_name}}::{{cookiecutter.datasource_name}}() :
        DataSourceI(),
        MessageI() {
// TODO : initializers for all data source data members
}

/*lint -e{1551} -e{1579} the destructor must guarantee that the memory is freed and the file is flushed and closed.. The brokerAsyncTrigger is freed by the ReferenceT */
{{cookiecutter.datasource_name}}::~{{cookiecutter.datasource_name}}() {

// TODO: implement destructors for dynamically allocated memory and close other resources e.g. files
}

bool {{cookiecutter.datasource_name}}::AllocateMemory() {
    return true;
}

uint32 {{cookiecutter.datasource_name}}::GetNumberOfMemoryBuffers() {
	// TODO: customise according to data source memory needs
    return 1u;
}

/*lint -e{715}  [MISRA C++ Rule 0-1-11], [MISRA C++ Rule 0-1-12]. Justification: The signalAddress is independent of the bufferIdx.*/
bool {{cookiecutter.datasource_name}}::GetSignalMemoryBuffer(const uint32 signalIdx,
                                       const uint32 bufferIdx,
                                       void *&signalAddress) {

    // TODO: find memory and cast to type.
    //
    return ok;
}

/*lint -e{715}  [MISRA C++ Rule 0-1-11], [MISRA C++ Rule 0-1-12]. Justification: The brokerName only depends on the direction and on the storeOnTrigger property (which is load before).*/
const char8* {{cookiecutter.datasource_name}}::GetBrokerName(StructuredDataI &data,
                                       const SignalDirection direction) {
    const char8 *brokerName = "";

    // TODO: implement broker pattern : the example code below must be updated
    /*
    if (direction == InputSignals) {
        if (interpolate) {
            brokerName = "MemoryMapInterpolatedInputBroker";
        }
        else {
            brokerName = "MemoryMapSynchronisedInputBroker";
        }
    }
     */
    return brokerName;
}

bool {{cookiecutter.datasource_name}}::GetInputBrokers(ReferenceContainer &inputBrokers,
                                 const char8 *const functionName,
                                 void *const gamMemPtr) {
    bool ok = true;
    // TODO

    return ok;
}

/*lint -e{715}  [MISRA C++ Rule 0-1-11], [MISRA C++ Rule 0-1-12]. Justification: OutputBrokers are not supported. Function returns false irrespectively of the parameters.*/
bool {{cookiecutter.datasource_name}}::GetOutputBrokers(ReferenceContainer &outputBrokers,
                                  const char8 *const functionName,
                                  void *const gamMemPtr) {
    return false;
}

/*lint -e{613} xAxisSignalPtr cannot be NULL as otherwise SetConfiguredDatabase would have failed.*/

bool {{cookiecutter.datasource_name}}::Synchronise() {
   return ok;
}

/*lint -e{715}  [MISRA C++ Rule 0-1-11], [MISRA C++ Rule 0-1-12]. Justification: NOOP at StateChange, independently of the function parameters.*/
bool {{cookiecutter.datasource_name}}::PrepareNextState(const char8 *const currentStateName,
                                  const char8 *const nextStateName) {
    return true;
}

bool {{cookiecutter.datasource_name}}::Initialise(StructuredDataI &data) {
    bool ok = DataSourceI::Initialise(data);
    if (ok) {
	// TODO: read and parse configuration data
    }
        return ok;
}

bool {{cookiecutter.datasource_name}}::SetConfiguredDatabase(StructuredDataI &data) {
    bool ok = DataSourceI::SetConfiguredDatabase(data);
    if (ok) {
        ok = data.MoveRelative("Signals");
    }
    // TODO : process signals
    return ok;
}

CLASS_REGISTER({{cookiecutter.datasource_name}}, "1.0")
// TODO: register methods as required e.g. 
//CLASS_METHOD_REGISTER({{cookiecutter.datasource_name}}, CloseFile)

}

