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
#ifndef elxMyStandardResampler_h
#define elxMyStandardResampler_h

#include "elxIncludes.h" // include first to avoid MSVS warning
#include "itkResampleImageFilter.h"

namespace elastix
{

/**
 * \class MyStandardResampler
 * \brief A resampler based on the itk::ResampleImageFilter.
 *
 * The parameters used in this class are:
 * \parameter Resampler: Select this resampler as follows:\n
 *    <tt>(Resampler "DefaultResampler")</tt>
 *
 * \ingroup Resamplers
 */

template <class TElastix>
class ITK_TEMPLATE_EXPORT MyStandardResampler
  : public ResamplerBase<TElastix>::ITKBaseType
  , public ResamplerBase<TElastix>
{
public:
  /** Standard ITK-stuff. */
  typedef MyStandardResampler                           Self;
  typedef typename ResamplerBase<TElastix>::ITKBaseType Superclass1;
  typedef ResamplerBase<TElastix>                       Superclass2;
  typedef itk::SmartPointer<Self>                       Pointer;
  typedef itk::SmartPointer<const Self>                 ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(MyStandardResampler, ResampleImageFilter);

  /** Name of this class.
   * Use this name in the parameter file to select this specific resampler. \n
   * example: <tt>(Resampler "DefaultResampler")</tt>\n
   */
  elxClassNameMacro("DefaultResampler");

  /** Typedef's inherited from the superclass. */
  using typename Superclass1::InputImageType;
  using typename Superclass1::OutputImageType;
  using typename Superclass1::InputImagePointer;
  using typename Superclass1::OutputImagePointer;
  using typename Superclass1::InputImageRegionType;
  using typename Superclass1::TransformType;
  using typename Superclass1::TransformPointerType;
  using typename Superclass1::InterpolatorType;
  using typename Superclass1::InterpolatorPointerType;
  using typename Superclass1::SizeType;
  using typename Superclass1::IndexType;
  using typename Superclass1::PixelType;
  using typename Superclass1::OutputImageRegionType;
  using typename Superclass1::SpacingType;
  using typename Superclass1::OriginPointType;

  /** Typedef's from the ResamplerBase. */
  using typename Superclass2::ElastixType;
  using typename Superclass2::ElastixPointer;
  using typename Superclass2::ConfigurationType;
  using typename Superclass2::ConfigurationPointer;
  using typename Superclass2::RegistrationType;
  using typename Superclass2::RegistrationPointer;
  typedef typename Superclass2::ITKBaseType ITKBaseType;

  /* Nothing to add. In the baseclass already everything is done what should be done. */

protected:
  /** The constructor. */
  MyStandardResampler() = default;
  /** The destructor. */
  ~MyStandardResampler() override = default;

private:
  elxOverrideGetSelfMacro;

  /** The deleted copy constructor. */
  MyStandardResampler(const Self &) = delete;
  /** The deleted assignment operator. */
  void
  operator=(const Self &) = delete;
};

} // end namespace elastix

#ifndef ITK_MANUAL_INSTANTIATION
#  include "elxMyStandardResampler.hxx"
#endif

#endif // end #ifndef elxMyStandardResampler_h
