/**
 * @file {{cookiecutter.datasource_name}}Test.h
 * @brief Header file for class {{cookiecutter.datasource_name}}Test
 * @date {{cookiecutter.date}}
 * @author {{cookiecutter.author}}
 */

{{cookiecutter.copyright}}

{{cookiecutter.interface_details}}

// TODO : COOKIECUTTER GENERATE IDEMPOTENT GUARD

#ifndef {{cookiecutter.test_include_guard}}
#define {{cookiecutter.test_include_guard}}

/*---------------------------------------------------------------------------*/
/*                        Standard header includes                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                        Project header includes                            */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                           Class declaration                               */
/*---------------------------------------------------------------------------*/
/**
 * @brief Tests the {{cookiecutter.datasource_name}} public methods.
 */
class {{cookiecutter.datasource_name}}Test {
public:
    /**
     * @brief Constructor. NOOP.
     */
    {{cookiecutter.datasource_name}}Test();

    /**
     * @brief Destructor. NOOP.
     */
    virtual ~{{cookiecutter.datasource_name}}Test();

    /**
     * @brief Tests the default constructor
     * @return true after GAM instantiation.
     */
    bool TestConstructor();

    /**
     * @brief Tests the Execute() method
     * @return true if Execute succeeds.
     */
    bool TestExecute();

    /**
     * @brief Tests the Setup() method
     * @details Verify the post-conditions
     * @return true if Setup() succeeds.
     */
    bool TestSetup();


};

/*---------------------------------------------------------------------------*/
/*                        Inline method definitions                          */
/*---------------------------------------------------------------------------*/

#endif /* {{cookiecutter.test_include_guard}} */

