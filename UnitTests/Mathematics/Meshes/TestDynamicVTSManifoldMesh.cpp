#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/DynamicVTSManifoldMesh.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestDynamicVTSManifoldMesh
    {
    public:
        UnitTestDynamicVTSManifoldMesh();

    private:
    };
}

UnitTestDynamicVTSManifoldMesh::UnitTestDynamicVTSManifoldMesh()
{
    UTInformation("Mathematics/Meshes/DynamicVTSManifoldMesh");
}

#else

#include <GTL/Mathematics/Meshes/DynamicVTSManifoldMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(DynamicVTSManifoldMesh)
