
#include <QApplication>
#include "ComplexNetworkVisualizer.hpp"
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QVTKApplication.h>
#include <QList>
#include <FeatureExtractors/AreaFeatureFactory.hpp>
#include <FeatureExtractors/LabelFeatureFactory.hpp>
#include <FeatureExtractors/OrientationFeatureFactory.hpp>
int main(int argc, char *argv[]){

    QVTKApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addPositionalArgument("input","Input Complex Network File","input");
    parser.addPositionalArgument("node_type","One of the following: NodeString, int, float, double","node_type");

    parser.addHelpOption();
    parser.process(app);

    QList<FeatureFactoryAbstract*> factories;
    LabelFeatureFactory labelFactory;
    OrientationFeatureFactory orientationFactory(40);
    factories.append(&labelFactory);
    factories.append(&orientationFactory);


    ComplexNetworkVisualizer visualizer;
    visualizer.load(parser.positionalArguments().first(), factories);
    visualizer.setVisible(true);

    return app.exec();
}

