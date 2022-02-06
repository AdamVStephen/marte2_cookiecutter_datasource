/**
 * @file {{cookiecutter.datasource_name}}GTest.cpp
 * @brief Source file for class {{cookiecutter.datasource_name}}GTest
 * @date {{cookiecutter.date}}
 * @author {{cookiecutter.author}}
 */

{{cookiecutter.copyright}}

{{cookiecutter.implementation_details}}

#define DLL_API

/*---------------------------------------------------------------------------*/
/*                         Standard header includes                          */
/*---------------------------------------------------------------------------*/
#include "gtest/gtest.h"
/*---------------------------------------------------------------------------*/
/*                         Project header includes                           */
/*---------------------------------------------------------------------------*/

#include "{{cookiecutter.datasource_name}}.h"
#include "{{cookiecutter.datasource_name}}Test.h"

/*---------------------------------------------------------------------------*/
/*                           Static definitions                              */
/*---------------------------------------------------------------------------*/

TEST({{cookiecutter.datasource_name}}GTest,TestConstructor) {
    {{cookiecutter.datasource_name}}Test test;
    ASSERT_TRUE(test.TestConstructor());
}

/*---------------------------------------------------------------------------*/
/*                           Method definitions                              */
/*---------------------------------------------------------------------------*/

