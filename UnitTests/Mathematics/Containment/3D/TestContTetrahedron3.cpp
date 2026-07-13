#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Containment/3D/ContTetrahedron3.h>
using namespace gtl;

namespace gtl
{
    class UnitTestContTetrahedron3
    {
    public:
        UnitTestContTetrahedron3();

    private:
        void Test();
    };
}

UnitTestContTetrahedron3::UnitTestContTetrahedron3()
{
    UTInformation("Mathematics/Containment/3D/ContTetrahedron3");

    Test();
}

void UnitTestContTetrahedron3::Test()
{
    Tetrahedron3<double> tetra{};
    Vector3<double> point{};
    bool contained{};

    tetra.v[0] = { 0.0, 0.0, 0.0 };
    tetra.v[1] = { 1.0, 0.0, 0.0 };
    tetra.v[2] = { 0.0, 1.0, 0.0 };
    tetra.v[3] = { 0.0, 0.0, 1.0 };

    point = { 0.2, 0.3, 0.4 };
    contained = ContTetrahedron3<double>::InContainer(point, tetra);
    UTAssert(contained, "Invalid result.");

    point = { -0.1, 0.25, 0.25 };
    contained = ContTetrahedron3<double>::InContainer(point, tetra);
    UTAssert(!contained, "Invalid result.");

    point = { 0.25, -0.1, 0.25 };
    contained = ContTetrahedron3<double>::InContainer(point, tetra);
    UTAssert(!contained, "Invalid result.");

    point = { 0.25, 0.25, -0.1 };
    contained = ContTetrahedron3<double>::InContainer(point, tetra);
    UTAssert(!contained, "Invalid result.");

    point = { 0.5, 0.5, 0.5 };
    contained = ContTetrahedron3<double>::InContainer(point, tetra);
    UTAssert(!contained, "Invalid result.");
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Containment/3D/ContTetrahedron3.h>

namespace gtl
{
    template class ContTetrahedron3<float>;
    template class ContTetrahedron3<double>;

#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class ContTetrahedron3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(ContTetrahedron3)
