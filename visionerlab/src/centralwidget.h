#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QTextEdit>
#include "inforbase.h"
#include <opencv2/opencv.hpp>
#include <QTextCodec>
#include "form.h"
#include <QMimeData>

namespace Ui {
class CentralWidget;
}

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();
    CentralWidget(int a, QWidget *parent);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);

private:
    Ui::CentralWidget *ui;
    INFOR_BASE::sImgInfor m_ImgInfor;

    QWidget *m_parentCopy;
    QTextEdit *m_textedit;
    Form *m_openimg;

    QHBoxLayout *qButtonHor;
    QVBoxLayout *qButtonVer;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    Form *openimg;
    std::vector<Form*> vfOpenImg;
private slots:
    void getMouse(int nMouseX, int nMouseY, QColor color, int nChannel);
    void getMouseDepth(int nMouseX, int nMouseY, ushort uPixel, int nChannel);
    void OpenNew(cv::Mat, INFOR_BASE::sImgInfor);
    void RGB2Gray();
    void Gray2RGB();
    void closeEventSlot();
    void closeEventSaveAsSlot();
    void ManualThresholdSlot();
    void ThresholdOtusSlot();
    void ThresholdAdaptiveSlot();
    void EqualizationSlot();
    void SobelSlot();
    void Scharr_3_3Slot();
    void Laplacian_5_5Slot();
    void Laplacian_7_7Slot();
    void Gaussian_3_3Slot();
    void Gaussian_5_5Slot();
    void Gaussian_7_7Slot();
    void Mean_3_3Slot();
    void Mean_5_5Slot();
    void Mean_7_7Slot();
    void Median_3_3Slot();
    void Median_5_5Slot();
    void Median_7_7Slot();
    void ButtonShowManageCloseGraySlot(std::vector<std::string> ,std::vector<std::string>);
    void ButtonShowManageOpenGraySlot(std::vector<std::string> ,std::vector<std::string>);
    void CloseImgWindowSlot();
    void CloseImgWindowFromFormSlot();
    void ReceiveFormSelfSlot(Form *);
    void GaussianSlot();
    void LaplaceSlot();
    void Connected_RegionSlot();
    // 定义信号，可以与子窗口进行通信
signals:
    void sendImgCenter(cv::Mat, INFOR_BASE::sImgInfor);
    void sendButtonShowManage(std::vector<std::string> ,std::vector<std::string>);
    void sendRGB2Gray();
    void sendGray2RGB();
    void sendcloseEventSlot();
    void sendcloseEventSaveAsSlot();
    void sendManualThresholdSlot();
    void sendThresholdOtusSlot();
    void sendThresholdAdaptiveSlot();
    void sendEqualizationSlot();
    void sendSobelSlot();
    void sendScharr_3_3Slot();
    void sendLaplacian_5_5Slot();
    void sendLaplacian_7_7Slot();
    void sendGaussian_3_3Slot();
    void sendGaussian_5_5Slot();
    void sendGaussian_7_7Slot();
    void sendMean_3_3Slot();
    void sendMean_5_5Slot();
    void sendMean_7_7Slot();
    void sendMedian_3_3Slot();
    void sendMedian_5_5Slot();
    void sendMedian_7_7Slot();
    void sendCloseImgWindow();
    void sendGaussianSlot();
    void sendLaplaceSlot();
    void sendConnected_RegionSlot();
};

#endif // CENTRALWIDGET_H