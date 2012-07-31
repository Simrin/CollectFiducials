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

// Qt includes
#include <QtPlugin>

// CollectFiducials Logic includes
#include <vtkSlicerCollectFiducialsLogic.h>

// CollectFiducials includes
#include "qSlicerCollectFiducialsModule.h"
#include "qSlicerCollectFiducialsModuleWidget.h"

//-----------------------------------------------------------------------------
Q_EXPORT_PLUGIN2(qSlicerCollectFiducialsModule, qSlicerCollectFiducialsModule);

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_CollectFiducials
class qSlicerCollectFiducialsModulePrivate
{
public:
  qSlicerCollectFiducialsModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerCollectFiducialsModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerCollectFiducialsModulePrivate::qSlicerCollectFiducialsModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerCollectFiducialsModule methods

//-----------------------------------------------------------------------------
qSlicerCollectFiducialsModule::qSlicerCollectFiducialsModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerCollectFiducialsModulePrivate)
{
}

//-----------------------------------------------------------------------------
QStringList qSlicerCollectFiducialsModule::categories()const
{
  // << "Developer Tools"
  return QStringList() << "" << "IGT";
}

//-----------------------------------------------------------------------------
qSlicerCollectFiducialsModule::~qSlicerCollectFiducialsModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerCollectFiducialsModule::helpText()const
{
  QString help = 
    "This template module is meant to be used with the"
    "with the ModuleWizard.py script distributed with the"
    "Slicer source code (starting with version 4)."
    "Developers can generate their own source code using the"
    "wizard and then customize it to fit their needs.";
  return help;
}

//-----------------------------------------------------------------------------
QString qSlicerCollectFiducialsModule::acknowledgementText()const
{
  return "This work was supported by NAMIC, NAC, and the Slicer Community...";
}

//-----------------------------------------------------------------------------
QStringList qSlicerCollectFiducialsModule::contributors()const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (Organization)");
  // moduleContributors << QString("Richard Roe (Organization2)");
  // ...
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerCollectFiducialsModule::icon()const
{
  return QIcon(":/Icons/CollectFiducials.png");
}

//-----------------------------------------------------------------------------
void qSlicerCollectFiducialsModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation * qSlicerCollectFiducialsModule::createWidgetRepresentation()
{
  return new qSlicerCollectFiducialsModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerCollectFiducialsModule::createLogic()
{
  return vtkSlicerCollectFiducialsLogic::New();
}
