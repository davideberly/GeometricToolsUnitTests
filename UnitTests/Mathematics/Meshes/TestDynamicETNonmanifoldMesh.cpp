#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/DynamicETNonmanifoldMesh.h>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestDynamicETNonmanifoldMesh
    {
    public:
        UnitTestDynamicETNonmanifoldMesh();

    private:
    };
}

UnitTestDynamicETNonmanifoldMesh::UnitTestDynamicETNonmanifoldMesh()
{
    UTInformation("Mathematics/Meshes/DynamicETNonmanifoldMesh");
}

#else

#include <GTL/Mathematics/Meshes/DynamicETNonmanifoldMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(DynamicETNonmanifoldMesh)
