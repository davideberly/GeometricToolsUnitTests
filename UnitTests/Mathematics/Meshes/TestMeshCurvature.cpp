#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/MeshCurvature.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestMeshCurvature
    {
    public:
        UnitTestMeshCurvature();

    private:
    };
}

UnitTestMeshCurvature::UnitTestMeshCurvature()
{
    UTInformation("Mathematics/Meshes/MeshCurvature");
}

#else

#include <GTL/Mathematics/Meshes/MeshCurvature.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MeshCurvature)
