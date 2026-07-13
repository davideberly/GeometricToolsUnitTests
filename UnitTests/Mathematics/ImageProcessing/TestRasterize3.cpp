#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/Rasterize3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestRasterize3
    {
    public:
        UnitTestRasterize3();
    };
}

UnitTestRasterize3::UnitTestRasterize3()
{
    UTInformation("Mathematics/ImageProcessing/Rasterize3 [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/Rasterize3.h>

namespace gtl
{
    template class Rasterize3<std::int32_t>;
    template class Rasterize3<std::int64_t>;

    using SInteger = std::int64_t;
    using VoxelType = std::int32_t;
    template void Rasterize3<SInteger>::DrawFloodFill6(SInteger, SInteger, SInteger,
        SInteger, SInteger, SInteger, VoxelType, VoxelType,
        std::function<void(SInteger, SInteger, SInteger, VoxelType)> const&,
        std::function<VoxelType(SInteger, SInteger, SInteger)> const&);
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(Rasterize3)
