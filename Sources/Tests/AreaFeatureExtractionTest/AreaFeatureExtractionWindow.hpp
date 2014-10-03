#ifndef AREAFEATUREEXTRACTIONWINDOW_HPP
#define AREAFEATUREEXTRACTIONWINDOW_HPP

#include <QWidget>
#include <GuiUtilities/supervisedimageviewerwidget.hpp>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <Utilities/SunDatabaseReader.hpp>

class AreaFeatureExtractionWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *m_next_button;
    QPushButton *m_previous_button;
    QVBoxLayout *m_vbox;
    QHBoxLayout *m_hbox;
    SupervisedImageViewerWidget *m_supervisedWidget;
    SunDatabaseReader reader;

public:
    explicit AreaFeatureExtractionWindow(QWidget *parent = 0);

signals:

public slots:
    void show_next();
    void show_previous();

};

#endif // AREAFEATUREEXTRACTIONWINDOW_HPP
