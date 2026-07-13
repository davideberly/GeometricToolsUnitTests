#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/ImageProcessing/Histogram.h>
using namespace gtl;

namespace gtl
{
    class UnitTestHistogram
    {
    public:
        UnitTestHistogram();
    };
}

UnitTestHistogram::UnitTestHistogram()
{
    UTInformation("Mathematics/ImageProcessing/Histogram [NEEDS UNIT TESTS]");
}

#else

#include <GTL/Mathematics/ImageProcessing/Histogram.h>

namespace gtl
{
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::uint8_t> const&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::uint16_t> const&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::uint32_t> const&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::uint64_t> const&, std::size_t&);

    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::int8_t> const&, std::int8_t&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::int16_t> const&, std::int16_t&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::int32_t> const&, std::int32_t&, std::size_t&);
    template void Histogram::Compute(std::vector<std::size_t>&,
        std::vector<std::int64_t> const&, std::int64_t&, std::size_t&);

    template void Histogram::Compute(std::vector<std::size_t>&, std::vector<float> const&);
    template void Histogram::Compute(std::vector<std::size_t>&, std::vector<double> const&);
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(Histogram)
