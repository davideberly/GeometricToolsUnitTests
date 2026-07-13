#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/CurveExtractorTriangles.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCurveExtractorTriangles
    {
    public:
        UnitTestCurveExtractorTriangles();
    };
}

UnitTestCurveExtractorTriangles::UnitTestCurveExtractorTriangles()
{
    UTInformation("Mathematics/ImageProcessing/CurveExtractorTriangles [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/CurveExtractorTriangles.h>

namespace gtl
{
    template class CurveExtractorTriangles<std::int8_t, float>;
    template class CurveExtractorTriangles<std::int16_t, float>;
    template class CurveExtractorTriangles<std::int32_t, float>;
    template class CurveExtractorTriangles<std::uint8_t, float>;
    template class CurveExtractorTriangles<std::uint16_t, float>;
    template class CurveExtractorTriangles<std::uint32_t, float>;
    template class CurveExtractorTriangles<std::int8_t, double>;
    template class CurveExtractorTriangles<std::int16_t, double>;
    template class CurveExtractorTriangles<std::int32_t, double>;
    template class CurveExtractorTriangles<std::uint8_t, double>;
    template class CurveExtractorTriangles<std::uint16_t, double>;
    template class CurveExtractorTriangles<std::uint32_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CurveExtractorTriangles)
