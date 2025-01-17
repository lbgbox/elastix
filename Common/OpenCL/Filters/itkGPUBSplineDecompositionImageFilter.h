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
#ifndef itkGPUBSplineDecompositionImageFilter_h
#define itkGPUBSplineDecompositionImageFilter_h

#include "itkBSplineDecompositionImageFilter.h"
#include "itkGPUInPlaceImageFilter.h"

namespace itk
{
/** Create a helper GPU Kernel class for GPUBSplineDecompositionImageFilter */
itkGPUKernelClassMacro(GPUBSplineDecompositionImageFilterKernel);

/** \class GPUBSplineDecompositionImageFilter
 * \brief GPU version of BSplineDecompositionImageFilter.
 *
 * \author Denis P. Shamonin and Marius Staring. Division of Image Processing,
 * Department of Radiology, Leiden, The Netherlands
 *
 * \note This work was funded by the Netherlands Organisation for
 * Scientific Research (NWO NRG-2010.02 and NWO 639.021.124).
 *
 * \ingroup GPUCommon
 */
template <typename TInputImage, typename TOutputImage>
class ITK_TEMPLATE_EXPORT GPUBSplineDecompositionImageFilter
  : public GPUImageToImageFilter<TInputImage, TOutputImage, BSplineDecompositionImageFilter<TInputImage, TOutputImage>>
{
public:
  /** Standard ITK-stuff. */
  typedef GPUBSplineDecompositionImageFilter                              Self;
  typedef BSplineDecompositionImageFilter<TInputImage, TOutputImage>      CPUSuperclass;
  typedef GPUImageToImageFilter<TInputImage, TOutputImage, CPUSuperclass> GPUSuperclass;
  typedef SmartPointer<Self>                                              Pointer;
  typedef SmartPointer<const Self>                                        ConstPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(GPUBSplineDecompositionImageFilter, GPUSuperclass);

  /** Superclass typedefs. */
  typedef typename GPUSuperclass::OutputImageRegionType OutputImageRegionType;
  typedef typename GPUSuperclass::OutputImagePixelType  OutputImagePixelType;
  typedef typename GPUSuperclass::SplinePolesVectorType SplinePolesVectorType;

  /** Some convenient typedefs. */
  typedef TInputImage                           InputImageType;
  typedef typename InputImageType::Pointer      InputImagePointer;
  typedef typename InputImageType::ConstPointer InputImageConstPointer;
  typedef typename InputImageType::RegionType   InputImageRegionType;
  typedef typename InputImageType::PixelType    InputImagePixelType;

  /** ImageDimension constants */
  itkStaticConstMacro(InputImageDimension, unsigned int, TInputImage::ImageDimension);
  itkStaticConstMacro(OutputImageDimension, unsigned int, TOutputImage::ImageDimension);

protected:
  GPUBSplineDecompositionImageFilter();
  ~GPUBSplineDecompositionImageFilter() {}
  void
  PrintSelf(std::ostream & os, Indent indent) const override;

  virtual void
  GPUGenerateData(void);

private:
  GPUBSplineDecompositionImageFilter(const Self &) = delete;
  void
  operator=(const Self &) = delete;

  std::size_t m_FilterGPUKernelHandle;
  std::size_t m_DeviceLocalMemorySize;
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#  include "itkGPUBSplineDecompositionImageFilter.hxx"
#endif

#endif /* itkGPUBSplineDecompositionImageFilter_h */
