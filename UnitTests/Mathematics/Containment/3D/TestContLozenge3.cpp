#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContLozenge3.h>
#include <fstream>
using namespace gtl;

namespace gtl
{
    class UnitTestContLozenge3
    {
    public:
        UnitTestContLozenge3();

    private:
        void Test();
    };
}

UnitTestContLozenge3::UnitTestContLozenge3()
{
    UTInformation("Mathematics/Containment/3D/ContLozenge3");

    Test();
}

void UnitTestContLozenge3::Test()
{
    std::vector<Vector3<float>> points(128);
    std::ifstream input("Mathematics/Containment/3D/Input/points128.binary", std::ios::binary);
    UTAssert(input, "Cannot load point file.");
    input.read(reinterpret_cast<char*>(points.data()), points.size() * sizeof(Vector3<float>));
    input.close();

    Lozenge3<float> lozenge{};
    ContLozenge3<float>::GetContainer(points, lozenge);
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContLozenge3.h>

namespace gtl
{
    template class ContLozenge3<float>;
    template class ContLozenge3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContLozenge3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContLozenge3)
