#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/CurveExtractor.h>
using namespace gtl;

namespace gtl
{
    class UnitTestCurveExtractor
    {
    public:
        UnitTestCurveExtractor();
    };
}

UnitTestCurveExtractor::UnitTestCurveExtractor()
{
    UTInformation("Mathematics/ImageProcessing/CurveExtractor [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/CurveExtractor.h>

namespace gtl
{
    template class CurveExtractor<std::int8_t, float>;
    template class CurveExtractor<std::int16_t, float>;
    template class CurveExtractor<std::int32_t, float>;
    template class CurveExtractor<std::uint8_t, float>;
    template class CurveExtractor<std::uint16_t, float>;
    template class CurveExtractor<std::uint32_t, float>;
    template class CurveExtractor<std::int8_t, double>;
    template class CurveExtractor<std::int16_t, double>;
    template class CurveExtractor<std::int32_t, double>;
    template class CurveExtractor<std::uint8_t, double>;
    template class CurveExtractor<std::uint16_t, double>;
    template class CurveExtractor<std::uint32_t, double>;
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(CurveExtractor)
