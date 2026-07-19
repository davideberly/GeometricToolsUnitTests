#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/DynamicVETNonmanifoldMesh.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestDynamicVETNonmanifoldMesh
    {
    public:
        UnitTestDynamicVETNonmanifoldMesh();

    private:
    };
}

UnitTestDynamicVETNonmanifoldMesh::UnitTestDynamicVETNonmanifoldMesh()
{
    UTInformation("Mathematics/Meshes/DynamicVETNonmanifoldMesh");
}

#else

#include <GTL/Mathematics/Meshes/DynamicVETNonmanifoldMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(DynamicVETNonmanifoldMesh)
