/*=========================================================================
 *
 *  Copyright UMC Utrecht and contributors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkBSplineStackTransform_h
#define itkBSplineStackTransform_h

#include "itkStackTransform.h"
#include "itkAdvancedBSplineDeformableTransform.h"

namespace itk
{
template <unsigned int NDimension>
class ITK_TEMPLATE_EXPORT BSplineStackTransform
  : public itk::StackTransform<elx::ElastixBase::CoordRepType, NDimension, NDimension>
{
  typedef elx::ElastixBase::CoordRepType CoordRepType;

  template <unsigned VSplineOrder>
  using SubTransformType = AdvancedBSplineDeformableTransform<CoordRepType, NDimension - 1, VSplineOrder>;

public:
  typedef BSplineStackTransform                                                       Self;
  typedef itk::StackTransform<elx::ElastixBase::CoordRepType, NDimension, NDimension> Superclass;
  typedef itk::SmartPointer<BSplineStackTransform>                                    Pointer;
  itkNewMacro(Self);
  itkTypeMacro(BSplineStackTransform, Superclass);

  void
  SetSplineOrder(const unsigned newValue)
  {
    m_SplineOrder = newValue;
  }

private:
  using typename Superclass::SubTransformPointer;

  template <unsigned VSplineOrder>
  SubTransformPointer
  CreateSubTransformOfSplineOrder() const
  {
    return SubTransformType<VSplineOrder>::New().GetPointer();
  }


  SubTransformPointer
  CreateSubTransform() const override
  {
    return (m_SplineOrder == 1)
             ? CreateSubTransformOfSplineOrder<1>()
             : (m_SplineOrder == 2) ? CreateSubTransformOfSplineOrder<2>()
                                    : (m_SplineOrder == 3) ? CreateSubTransformOfSplineOrder<3>() : nullptr;
  }

  unsigned m_SplineOrder{ 3 };
};

} // namespace itk

#endif
