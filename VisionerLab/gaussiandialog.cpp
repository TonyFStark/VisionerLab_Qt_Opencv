#include "gaussiandialog.h"
#include "ui_gaussiandialog.h"

GaussianDialog::GaussianDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GaussianDialog)
{
    m_qButtonVer = new QVBoxLayout;
    m_qSliderHor1 = new QHBoxLayout;
    m_qSliderHor2 = new QHBoxLayout;
    m_pLabel = new QLabel(this);
    m_pLabel->setText("Level");
    m_parent = parent;
    int nMin = 3;
    int nMax = 51;
    int nSingleStep = 2;
    // ΢����
    m_pSpinBox = new QSpinBox(this);
    m_pSpinBox->setMinimum(nMin);  // ��Сֵ
    m_pSpinBox->setMaximum(nMax);  // ���ֵ
    m_pSpinBox->setSingleStep(nSingleStep);  // ����


    // ������
    m_pSlider = new QSlider(this);
    m_pSlider->setOrientation(Qt::Horizontal);  // ˮƽ����
    m_pSlider->setMinimum(nMin);  // ��Сֵ
    m_pSlider->setMaximum(nMax);  // ���ֵ
    m_pSlider->setSingleStep(nSingleStep);  // ����
    //m_pSlider->setPageStep(nSingleStep);
    m_qSliderHor1->addWidget(m_pLabel);
    m_qSliderHor1->addWidget(m_pSpinBox);
    m_qSliderHor1->addWidget(m_pSlider);

    // �����źŲۣ��໥�ı䣩
    connect(m_pSpinBox, SIGNAL(valueChanged(int)), m_pSlider, SLOT(setValue(int)));
    connect(m_pSlider, SIGNAL(valueChanged(int)), m_pSpinBox, SLOT(setValue(int)));
    connect(m_pSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ManualGaussianChangeSlot(int)));
    connect(m_pSlider, SIGNAL(valueChanged(int)), this, SLOT(ManualGaussianChangeSlot(int)));
    m_pSpinBox->setValue(21);
    button = new QDialogButtonBox(parent);
    button->addButton( "OK", QDialogButtonBox::YesRole);
    button->addButton( "NO", QDialogButtonBox::NoRole);
    connect(button, SIGNAL(accepted()), parent, SLOT(OKGaussianSliderSelectImg()));
    connect(button, SIGNAL(rejected()), parent, SLOT(CancelGaussianSliderSelectImg()));

    m_qSliderHor2->addWidget(button);
    m_qButtonVer->addLayout(m_qSliderHor1);
    m_qButtonVer->addLayout(m_qSliderHor2);
    this->setLayout(m_qButtonVer);
    ui->setupUi(this);

}

GaussianDialog::~GaussianDialog()
{
    delete m_parent;
    delete m_pSpinBox;
    delete m_pSlider;
    delete m_pLabel;
    delete m_qButtonVer;
    delete m_qSliderHor1;
    delete m_qSliderHor2;
    delete button;
    delete ui;
}
void GaussianDialog::ManualGaussianChangeSlot(int nValue)
{
    connect(this, SIGNAL(sendManualGaussianChange(int )), m_parent, SLOT(ManualGaussianChangeSlot(int)));
    emit sendManualGaussianChange(nValue);
    // ���ӶϿ����ӣ�ִ�еڴ�Խ�࣬����ִ�д���Խ��
    disconnect(this, 0, m_parent, 0);
}
