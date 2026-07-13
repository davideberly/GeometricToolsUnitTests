#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/MarchingCubes.h>
using namespace gtl;

namespace gtl
{
    class UnitTestMarchingCubes
    {
    public:
        UnitTestMarchingCubes();
    };
}

UnitTestMarchingCubes::UnitTestMarchingCubes()
{
    UTInformation("Mathematics/ImageProcessing/MarchingCubes [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/MarchingCubes.h>

namespace gtl
{
    template class MarchingCubes<std::uint16_t>;
    template class MarchingCubes<std::uint32_t>;
    template class MarchingCubes<std::uint64_t>;
    template class MarchingCubes<std::size_t>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(MarchingCubes)
