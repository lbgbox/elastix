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
#ifndef itkAffineLogStackTransform_h
#define itkAffineLogStackTransform_h

#include "itkStackTransform.h"
#include "../AffineLogTransform/itkAffineLogTransform.h"
#include "elxElastixBase.h"

namespace itk
{
template <unsigned int NDimension>
class ITK_TEMPLATE_EXPORT AffineLogStackTransform
  : public itk::StackTransform<elx::ElastixBase::CoordRepType, NDimension, NDimension>
{
public:
  typedef AffineLogStackTransform                                                     Self;
  typedef itk::StackTransform<elx::ElastixBase::CoordRepType, NDimension, NDimension> Superclass;
  typedef itk::SmartPointer<AffineLogStackTransform>                                  Pointer;
  itkNewMacro(Self);
  itkTypeMacro(AffineLogStackTransform, Superclass);

private:
  typename Superclass::SubTransformPointer
  CreateSubTransform() const override
  {
    return AffineLogTransform<elx::ElastixBase::CoordRepType, NDimension - 1>::New().GetPointer();
  }
};

} // namespace itk

#endif
