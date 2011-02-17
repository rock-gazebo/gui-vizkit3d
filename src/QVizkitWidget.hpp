#ifndef __VIZKIT_QVIZKITWIDGET__
#define __VIZKIT_QVIZKITWIDGET__

#include <vizkit/QOSGWidget.hpp>
#include <vizkit/VizPlugin.hpp>
#include <vizkit/CompositeViewerQOSG.hpp>
#include <vizkit/PickHandler.hpp>
#include <QtDesigner/QDesignerExportWidget>

namespace vizkit 
{

class QDESIGNER_WIDGET_EXPORT QVizkitWidget : public CompositeViewerQOSG 
{
    Q_OBJECT

public:
    QVizkitWidget( QWidget* parent = 0, Qt::WindowFlags f = 0 );
    osg::ref_ptr<osg::Group> getRootNode() const;
    void addDataHandler(VizPluginBase *viz);
    void removeDataHandler(VizPluginBase *viz);
    
    void changeCameraView(const osg::Vec3& lookAtPos);
    void changeCameraView(const osg::Vec3& lookAtPos, const osg::Vec3& eyePos);
    void setTrackedNode( vizkit::VizPluginBase* plugin );

    QSize sizeHint() const;
    
public slots:    
    QStringList* getListOfAvailablePlugins();
    QObject* createPlugin(QString pluginName);

protected:
    osg::ref_ptr<osg::Group> root;
    void createSceneGraph();
    osg::ref_ptr<PickHandler> pickHandler;

    osg::ref_ptr<ViewQOSG> view;
    
    QStringList* pluginNames;    
};

}

#endif