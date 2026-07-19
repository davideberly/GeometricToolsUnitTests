#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/VolumetricMesh.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestVolumetricMesh
    {
    public:
        UnitTestVolumetricMesh();

    private:
    };
}

UnitTestVolumetricMesh::UnitTestVolumetricMesh()
{
    UTInformation("Mathematics/Meshes/VolumetricMesh");
}

#else

#include <GTL/Mathematics/Meshes/VolumetricMesh.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(VolumetricMesh)
