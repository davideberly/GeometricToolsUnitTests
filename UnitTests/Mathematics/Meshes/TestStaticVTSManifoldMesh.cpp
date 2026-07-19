#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/StaticVTSManifoldMesh.h>
#include <GTL/Mathematics/Algebra/Vector.h>
#include <GTL/Utility/Timer.h>
#include <fstream>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestStaticVTSManifoldMesh
    {
    public:
        UnitTestStaticVTSManifoldMesh();

    private:
    };
}

UnitTestStaticVTSManifoldMesh::UnitTestStaticVTSManifoldMesh()
{
    UTInformation("Mathematics/Meshes/StaticVTSManifoldMesh");
}

#else

#include <GTL/Mathematics/Meshes/StaticVTSManifoldMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(StaticVTSManifoldMesh)
