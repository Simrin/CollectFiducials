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

// IGTProbe includes
#include "vtkSlicerIGTProbeLogic.h"


// MRML includes
#include "vtkMRMLLinearTransformNode.h"
#include "vtkMRMLAnnotationHierarchyNode.h"
#include "vtkMRMLAnnotationFiducialNode.h"


// VTK includes
#include <vtkMatrix4x4.h>
#include <vtkNew.h>


// STD includes
#include <cassert>



vtkStandardNewMacro(vtkSlicerIGTProbeLogic);



vtkSlicerIGTProbeLogic::vtkSlicerIGTProbeLogic()
{
  this->ProbeTransformNode = NULL;
  this->AnnotationHierarchyNode = NULL;
}



vtkSlicerIGTProbeLogic::~vtkSlicerIGTProbeLogic()
{
  if ( this->ProbeTransformNode != NULL )
  {
    this->ProbeTransformNode->Delete();
    this->ProbeTransformNode = NULL;
  }
  
  if ( this->AnnotationHierarchyNode != NULL )
  {
    this->AnnotationHierarchyNode->Delete();
    this->AnnotationHierarchyNode = NULL;
  }
}



void vtkSlicerIGTProbeLogic::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  
  os << indent << "ProbeTransformNode: "
     << ( this->ProbeTransformNode ? this->ProbeTransformNode->GetNodeTagName() : "(none)" ) << std::endl;
}



void vtkSlicerIGTProbeLogic
::AddFiducial()
{
  if (     this->ProbeTransformNode == NULL
      // ||  this->AnnotationHierarchyNode == NULL
      )
  {
    return;
  }
  
  vtkMatrix4x4* transformToWorld = vtkMatrix4x4::New();
  this->ProbeTransformNode->GetMatrixTransformToWorld( transformToWorld );
  
  vtkMRMLAnnotationFiducialNode * fnode = vtkMRMLAnnotationFiducialNode::New();
  
  // fnode->SetName(labelText);
  // double coord[3] = {(double)xyz[0], (double)xyz[1], (double)xyz[2]};
  // fnode->AddControlPoint(coord, sel, vis); 
  
  double coord[ 3 ] = { transformToWorld->GetElement( 0, 3 ), transformToWorld->GetElement( 1, 3 ), transformToWorld->GetElement( 2, 3 ) };
  fnode->SetFiducialCoordinates( coord[ 0 ], coord[ 1 ], coord[ 2 ] );
  
  // fnode->SetControlPoint( 0, coord );
  
  this->GetMRMLScene()->AddNode( fnode );
  
  fnode->Delete();
  transformToWorld->Delete();
}



void vtkSlicerIGTProbeLogic
::SetProbeTransformNode( vtkMRMLLinearTransformNode *node )
{
  vtkSetMRMLNodeMacro( this->ProbeTransformNode, node );
  this->Modified();
}



void vtkSlicerIGTProbeLogic
::SetAnnotationHierarchyNode( vtkMRMLAnnotationHierarchyNode *node )
{
  vtkSetMRMLNodeMacro( this->AnnotationHierarchyNode, node );
  this->Modified();
}



void vtkSlicerIGTProbeLogic::SetMRMLSceneInternal(vtkMRMLScene * newScene)
{
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());
}



void vtkSlicerIGTProbeLogic::RegisterNodes()
{
  assert(this->GetMRMLScene() != 0);
}



void vtkSlicerIGTProbeLogic::UpdateFromMRMLScene()
{
  assert(this->GetMRMLScene() != 0);
}



void vtkSlicerIGTProbeLogic
::OnMRMLSceneNodeAdded(vtkMRMLNode* vtkNotUsed(node))
{
}



void vtkSlicerIGTProbeLogic
::OnMRMLSceneNodeRemoved(vtkMRMLNode* vtkNotUsed(node))
{
}
