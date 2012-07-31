/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// .NAME vtkSlicerIGTProbeLogic - slicer logic class for volumes manipulation
// .SECTION Description
// This class manages the logic associated with reading, saving,
// and changing propertied of the volumes


#ifndef __vtkSlicerIGTProbeLogic_h
#define __vtkSlicerIGTProbeLogic_h

// Slicer includes
#include "vtkSlicerModuleLogic.h"

// MRML includes
#include "vtkMRML.h"
#include "vtkMRMLNode.h"
#include "vtkMRMLScene.h"

class vtkMRMLLinearTransformNode;
class vtkMRMLAnnotationHierarchyNode;


// STD includes
#include <cstdlib>

#include "vtkSlicerIGTProbeModuleLogicExport.h"




/// \ingroup Slicer_QtModules_IGTProbe
class VTK_SLICER_IGTPROBE_MODULE_LOGIC_EXPORT vtkSlicerIGTProbeLogic :
  public vtkSlicerModuleLogic
{
public:
  
  static vtkSlicerIGTProbeLogic *New();
  vtkTypeMacro(vtkSlicerIGTProbeLogic,vtkSlicerModuleLogic);
  void PrintSelf(ostream& os, vtkIndent indent);
  
  void AddFiducial();
  

  // Reference to the probe transform.

public:
  vtkGetObjectMacro( ProbeTransformNode, vtkMRMLLinearTransformNode );
  void SetProbeTransformNode( vtkMRMLLinearTransformNode *node );
private:
  vtkMRMLLinearTransformNode *ProbeTransformNode;
  
  
  // Reference to the annotation list.

public:
  vtkGetObjectMacro( AnnotationHierarchyNode, vtkMRMLAnnotationHierarchyNode );
  void SetAnnotationHierarchyNode( vtkMRMLAnnotationHierarchyNode *node );
private:
  vtkMRMLAnnotationHierarchyNode *AnnotationHierarchyNode;
  
  
protected:
  vtkSlicerIGTProbeLogic();
  virtual ~vtkSlicerIGTProbeLogic();

  virtual void SetMRMLSceneInternal(vtkMRMLScene * newScene);
  /// Register MRML Node classes to Scene. Gets called automatically when the MRMLScene is attached to this logic class.
  virtual void RegisterNodes();
  virtual void UpdateFromMRMLScene();
  virtual void OnMRMLSceneNodeAdded(vtkMRMLNode* node);
  virtual void OnMRMLSceneNodeRemoved(vtkMRMLNode* node);
private:

  vtkSlicerIGTProbeLogic(const vtkSlicerIGTProbeLogic&); // Not implemented
  void operator=(const vtkSlicerIGTProbeLogic&);               // Not implemented
};

#endif
