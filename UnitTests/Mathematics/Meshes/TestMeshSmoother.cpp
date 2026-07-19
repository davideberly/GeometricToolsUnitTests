#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Meshes/MeshSmoother.h>
#include <map>
#include <set>
#include <string>
using namespace gtl;

namespace gtl
{
    class UnitTestMeshSmoother
    {
    public:
        UnitTestMeshSmoother();

    private:
    };
}

UnitTestMeshSmoother::UnitTestMeshSmoother()
{
    UTInformation("Mathematics/Meshes/MeshSmoother");
}

#else

#include <GTL/Mathematics/Meshes/MeshSmoother.h>

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MeshSmoother)
