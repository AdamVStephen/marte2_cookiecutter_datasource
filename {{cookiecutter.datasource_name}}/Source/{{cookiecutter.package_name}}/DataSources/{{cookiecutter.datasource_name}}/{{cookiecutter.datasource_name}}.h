/**
 * @file {{cookiecutter.datasource_name}}.h
 * @brief Header file for class {{cookiecutter.datasource_name}}
 *
 * @date {{cookiecutter.date}}
 * @author {{cookiecutter.author}}
 */

{{cookiecutter.copyright}}

{{cookiecutter.interface_details}}

// COOKIECUTTER TODO : MANAGE THE IDEMPOTENT GUARD GENERATION

#ifndef {{cookiecutter.datasource_include_guard}}
#define {{cookiecutter.datasource_include_guard}}

/*---------------------------------------------------------------------------*/
/*                        Standard header includes                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                        Project header includes                            */
/*---------------------------------------------------------------------------*/

// COOKIECUTTER TODO: minimise the following headers (DataSource, MessageI ?)
//
#include "DataSourceI.h"
#include "File.h"
#include "MemoryMapInterpolatedInputBroker.h"
#include "MessageI.h"
#include "ProcessorType.h"
#include "RegisteredMethodsMessageFilter.h"

/*---------------------------------------------------------------------------*/
/*                           Class declaration                               */
/*---------------------------------------------------------------------------*/
namespace MARTe {
/**
 * @brief A DataSourceI interface which allows to read signals from a file.
 *
 * @details TODO
 *
 * TODO: write description and outline design in prose.
 * The configuration syntax is (names are only given as an example):
 *
 * <pre>
 * +{{cookiecutter.datasource_name}}_Instance_Qualifier = {
 *     Class = {{cookiecutter.datasource_name}}
 *     TODO: fill out key = value // description
 *     +Messages = { //Optional. If set a message will be fired every time one of the events below occur
 *         Class = ReferenceContainer
 *         +MessageName = { //Optional
 *             Class = Message
 *             Destination = SomeObject
 *             Function = SomeFunction
 *             Mode = ExpectsReply
 *         }
 *     }
 * }
 * </pre>
 */
class {{cookiecutter.datasource_name}} : public DataSourceI, public MessageI {
public:CLASS_REGISTER_DECLARATION()

    /**
     * @brief Default constructor.
     * @details TODO
     */
    {{cookiecutter.datasource_name}} ();

    /**
     * @brief Destructor.
     * @details TODO
     */
    virtual ~{{cookiecutter.datasource_name}}();

    /**
     * @brief See DataSourceI::AllocateMemory.
     * @return true.
     */
    virtual bool AllocateMemory();

    /**
     * @brief See DataSourceI::GetNumberOfMemoryBuffers.
     * @return 1.
     */
    virtual uint32 GetNumberOfMemoryBuffers();

    /**
     * @brief See DataSourceI::GetSignalMemoryBuffer.
     * @pre
     *   SetConfiguredDatabase
     */
    virtual bool GetSignalMemoryBuffer(const uint32 signalIdx,
                                       const uint32 bufferIdx,
                                       void *&signalAddress);

    /**
     * @brief See DataSourceI::GetBrokerName.
     * @details Only InputSignals are supported.
     * @return MemoryMapSynchronisedInputBroker if interpolate = false, MemoryMapInterpolatedInputBroker otherwise.
     */
    virtual const char8* GetBrokerName(StructuredDataI &data,
                                       const SignalDirection direction);

    /**
     * @brief See DataSourceI::GetInputBrokers.
     * @details If interpolate == yes adds a MemoryMapInterpolatedInputBroker instance to
     *  the inputBrokers, otherwise adds a MemoryMapSynchronisedInputBroker instance to the intputBrokers.
     * @pre
     *   GetNumberOfFunctions() == 1u
     */
    virtual bool GetInputBrokers(ReferenceContainer &inputBrokers,
                                 const char8 *const functionName,
                                 void *const gamMemPtr);

    /**
     * @brief See DataSourceI::GetOutputBrokers.
     * @return false.
     */
    virtual bool GetOutputBrokers(ReferenceContainer &outputBrokers,
                                  const char8 *const functionName,
                                  void *const gamMemPtr);

    /**
     * @brief Reads into the buffer data the data from the specified file in the specified format.
     * @return true if the data can be successfully read from the file.
     */
    virtual bool Synchronise();

    /**
     * @brief See DataSourceI::PrepareNextState. NOOP.
     * @return true.
     */
    virtual bool PrepareNextState(const char8 *const currentStateName,
                                  const char8 *const nextStateName);

    /**
     * @brief Loads and verifies the configuration parameters detailed in the class description.
     * @return true if all the mandatory parameters are correctly specified and if the specified optional parameters have valid values.
     */
    virtual bool Initialise(StructuredDataI &data);

    /**
     * @brief Final verification of all the parameters and opening of the file.
     * @details This method verifies that all the parameters are valid
     * @return true if all the parameters are valid and if the data source can operate correctly.
     */
    virtual bool SetConfiguredDatabase(StructuredDataI &data);

    /**
     * @brief Close the file. Function is registered as an RPC.
     * @return ErrorManagement::NoError if the file can be successfully closed.
     */
    ErrorManagement::ErrorType CloseFile();

    /**
     * @brief Gets the configured filename.
     * @return the configured filename.
     */
    const StreamString& GetFilename() const;

    /**
     * @brief Gets the configured FileFormat.
     * @return the configured FileFormat.
     */
    const StreamString& GetFileFormat() const;

    /**
     * @brief Gets the configured CSVSeparator.
     * @return the configured CSVSeparator.
     */
    const StreamString& GetCSVSeparator() const;

    /**
     * @brief Returns true if the file is to be interpolated.
     * @return true if the file is to be interpolated.
     */
    bool IsInterpolate() const;

    /**
     * @brief Returns the XAxisSignal name.
     * @return the XAxisSignal name.
     */
    const StreamString& GetXAxisSignal() const;

    /**
     * @brief Returns the InterpolationPeriod value.
     * @return the InterpolationPeriod value
     */
    uint64 GetInterpolationPeriod() const;

private:

    /**
     * @brief TODO: as required for the DataSource implementation : member methods and data
     */
    };
}

/*---------------------------------------------------------------------------*/
/*                        Inline method definitions                          */
/*---------------------------------------------------------------------------*/

#endif /*  {{cookiecutter.datasource_include_guard}} */
