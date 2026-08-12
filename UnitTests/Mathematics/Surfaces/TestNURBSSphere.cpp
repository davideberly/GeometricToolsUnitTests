#if defined(GTL_UNIT_TESTS)
#include <UnitTestsExceptions.h>
#include <GTL/Mathematics/Surfaces/NURBSSphere.h>
using namespace gtl;

namespace gtl
{
    class UnitTestNURBSSphere
    {
    public:
        UnitTestNURBSSphere();

        void Test();
    };
}

UnitTestNURBSSphere::UnitTestNURBSSphere()
{
    // Also tested by GTL/VisualTests/Surfaces/NURBSSphere
    UTInformation("Mathematics/Surfaces/NURBSSphere [tested by GTL/VisualTests/Surfaces/NURBSSphere]");
    Test();
}

void UnitTestNURBSSphere::Test()
{
    NURBSEighthSphereDegree4<double> sphere{};
    std::array<Vector3<double>, 6> value{};
    //sphere.Evaluate(0.1234, 0.5678, 0, value); 
    //sphere.Evaluate(0.1234, 0.5678, 1, value);
    //sphere.Evaluate(0.1234, 0.5678, 2, value);
    sphere.Evaluate(0.1234, 0.5678, 3, value.data());
    // GTE:
    // f = (0.22063321412885425, 0.83630229229091790, 0.50191579047896806)
    // fu = (1.7355059167763871, 0.27911496575564576, -1.2279644233627531)
    // fv = (-0.070104450349645492, 0.95209320203916703, -1.5555803820985650)
    // fuu = (-1.4784727469210039, -2.8660003438638051, -3.7351678517530966)
    // fuv = (-0.90896269307761823, -1.0371365141841129, -1.9652044306840073)
    // fvv = (-0.50908174682048479, -3.0397405444374930, -1.3483618367815471)
    // Mathematica:
    // f = (0.2206332141288542,  0.8363022922909178,  0.5019157904789680)
    // fu = (1.7355059167763869, 0.27911496575564665, -1.2279644233627525)
    // fv = (-0.07010445034964555, 0.9520932020391674, -1.555580382098565)
    // fuu = (-1.4784727469209995, -2.8660003438638046, -3.7351678517530993)
    // fuv = (-0.9089626930776188, -1.0371365141841131, -1.9652044306840082)
    // fvv = (-0.5090817468204849, -3.0397405444374934, -1.3483618367815424)
}

#else

#if defined(GTL_INSTANTIATE_RATIONAL)
#include <GTL/Mathematics/Arithmetic/ArbitraryPrecision.h>
#endif
#include <GTL/Mathematics/Surfaces/NURBSSphere.h>

namespace gtl
{
    template class NURBSEighthSphereDegree4<float>;
    template class NURBSHalfSphereDegree3<float>;
    template class NURBSFullSphereDegree3<float>;

    template class NURBSEighthSphereDegree4<double>;
    template class NURBSHalfSphereDegree3<double>;
    template class NURBSFullSphereDegree3<double>;
    
#if defined(GTL_INSTANTIATE_RATIONAL)
    using Rational = BSRational<UIntegerAP32>;
    template class NURBSEighthSphereDegree4<Rational>;
    template class NURBSHalfSphereDegree3<Rational>;
    template class NURBSFullSphereDegree3<Rational>;
#endif
}

#endif

#include <UnitTestsNamespaces.h>
GTL_TEST_FUNCTION(NURBSSphere)
