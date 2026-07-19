#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Geometry/3D/SplitMeshByPlane.h>
using namespace gtl;

namespace gtl
{
    class UnitTestSplitMeshByPlane
    {
    public:
        UnitTestSplitMeshByPlane();

    private:
    };
}

UnitTestSplitMeshByPlane::UnitTestSplitMeshByPlane()
{
    UTInformation("Mathematics/Geometry/3D/SplitMeshByPlane [NEEDS UNIT TESTING]");
}

#else

#include <GTL/Mathematics/Geometry/3D/SplitMeshByPlane.h>

namespace gtl
{
    template class SplitMeshByPlane<float>;
    template class SplitMeshByPlane<double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(SplitMeshByPlane)
