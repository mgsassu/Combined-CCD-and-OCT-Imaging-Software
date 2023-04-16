#pragma once
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>
#include <exception>
#include <process.h>
#include <list>
#include <iostream>
#include <algorithm>
//AutoLock header files
#include "AutoBusy.h"
#include "AutoLock.h"
//Picam header files
#include <pil_platform.h>
#include <picam.h>
#include <picam_advanced.h>
//AlazarTech header files
#include "ATS_GMA.h"
#include "ATS_GMA_OCT.h"
#include <chrono>
#include <vector>

namespace FalloposcopeSoftwarev10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for PrimaryGUI
	/// </summary>

#pragma region std Global Variables
	////////////////////////////////////////////////////////////////////////////////
	// Class "prototypes"
	////////////////////////////////////////////////////////////////////////////////
	//ref class PrimaryGUI;
	//class AutoBusy;
	//class AutoLock;
	
	////////////////////////////////////////////////////////////////////////////////
	// std variables cannot be part of the windows form class
	////////////////////////////////////////////////////////////////////////////////
	std::vector<pibyte> buffer_;            // - acquisition circular buffer
	CRITICAL_SECTION lock_;                 // - protects all shared state below
	CONDITION_VARIABLE imageDataAvailable_; // - signals fresh image data acquired
	std::vector<pi16u> imageData16_;        // - data from last frame (16-bit)
	std::vector<pi32u> imageData32_;        // - data from last frame (32-bit)
	piint busy_ = 0;                        // - controls the wait cursor
	HCURSOR waitCursor_ = 0;                // - the wait cursor

#pragma endregion

	public ref class PrimaryGUI : public System::Windows::Forms::Form
	{
	public:
		PrimaryGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PrimaryGUI()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::MaskedTextBox^  mtbExposureTime;

	private: System::Windows::Forms::Button^  btnTakeSingleExposure;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pbPixis;
	private: System::Windows::Forms::Button^  btnInitializeCamera;
	private: System::Windows::Forms::Label^  lblInitializationStatus;
	private: System::Windows::Forms::Button^  btnPixisContinuousAcquisition;


	private: System::Windows::Forms::Label^  lblSerialNumber;

	private: System::Windows::Forms::Label^  lblSensorName;
	private: System::Windows::Forms::Label^  lblInterface;

	private: System::Windows::Forms::Label^  lblModel;

	private: System::Windows::Forms::Button^  btnSaveCurrentImage;
	private: System::Windows::Forms::Button^  btnScreenRecording;




	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewScreenRecordingsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  viewSavedPixisImagesToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  mtbScreenRecordingName;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panelPixisImage;




	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  mtbPixisImageName;
	private: System::Windows::Forms::MaskedTextBox^  mtbRecordingName;
	private: System::Windows::Forms::MaskedTextBox^  mtbImageName;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::MaskedTextBox^  mtbRecording;
	private: System::Windows::Forms::MaskedTextBox^  mtbPixisImage;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartAScan;

	private: System::Windows::Forms::Panel^  panelBScan;
	private: System::Windows::Forms::PictureBox^  pbBScan;
	private: System::Windows::Forms::Button^  btnOCTScan;



	private: System::Windows::Forms::CheckBox^  cbInterpolation;
	private: System::Windows::Forms::Label^  lblAlazarDataPoint1;

	private: System::Windows::Forms::ToolStripMenuItem^  infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pixisDLLToolStripMenuItem;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  cbAudioDevices;
	private: System::Windows::Forms::Panel^  panelScreenRecording;
	private: System::Windows::Forms::Button^  btnFindAudioDevices;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panelPixisImagingControls;




	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->mtbExposureTime = (gcnew System::Windows::Forms::MaskedTextBox());
			this->btnTakeSingleExposure = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pbPixis = (gcnew System::Windows::Forms::PictureBox());
			this->btnInitializeCamera = (gcnew System::Windows::Forms::Button());
			this->lblInitializationStatus = (gcnew System::Windows::Forms::Label());
			this->btnPixisContinuousAcquisition = (gcnew System::Windows::Forms::Button());
			this->lblSerialNumber = (gcnew System::Windows::Forms::Label());
			this->lblSensorName = (gcnew System::Windows::Forms::Label());
			this->lblInterface = (gcnew System::Windows::Forms::Label());
			this->lblModel = (gcnew System::Windows::Forms::Label());
			this->panelPixisImage = (gcnew System::Windows::Forms::Panel());
			this->btnSaveCurrentImage = (gcnew System::Windows::Forms::Button());
			this->btnScreenRecording = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewScreenRecordingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewSavedPixisImagesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pixisDLLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mtbRecording = (gcnew System::Windows::Forms::MaskedTextBox());
			this->mtbPixisImage = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chartAScan = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panelBScan = (gcnew System::Windows::Forms::Panel());
			this->pbBScan = (gcnew System::Windows::Forms::PictureBox());
			this->btnOCTScan = (gcnew System::Windows::Forms::Button());
			this->cbInterpolation = (gcnew System::Windows::Forms::CheckBox());
			this->lblAlazarDataPoint1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cbAudioDevices = (gcnew System::Windows::Forms::ComboBox());
			this->panelScreenRecording = (gcnew System::Windows::Forms::Panel());
			this->btnFindAudioDevices = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panelPixisImagingControls = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPixis))->BeginInit();
			this->panelPixisImage->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAScan))->BeginInit();
			this->panelBScan->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBScan))->BeginInit();
			this->panelScreenRecording->SuspendLayout();
			this->panelPixisImagingControls->SuspendLayout();
			this->SuspendLayout();
			// 
			// mtbExposureTime
			// 
			this->mtbExposureTime->Location = System::Drawing::Point(115, 117);
			this->mtbExposureTime->Name = L"mtbExposureTime";
			this->mtbExposureTime->Size = System::Drawing::Size(73, 20);
			this->mtbExposureTime->TabIndex = 6;
			this->mtbExposureTime->Text = L"100";
			// 
			// btnTakeSingleExposure
			// 
			this->btnTakeSingleExposure->Enabled = false;
			this->btnTakeSingleExposure->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnTakeSingleExposure->Location = System::Drawing::Point(6, 143);
			this->btnTakeSingleExposure->Name = L"btnTakeSingleExposure";
			this->btnTakeSingleExposure->Size = System::Drawing::Size(184, 26);
			this->btnTakeSingleExposure->TabIndex = 7;
			this->btnTakeSingleExposure->Text = L"Take Single Exposure";
			this->btnTakeSingleExposure->UseVisualStyleBackColor = true;
			this->btnTakeSingleExposure->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnTakeSingleExposure_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(7, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Exposure Time (ms):";
			// 
			// pbPixis
			// 
			this->pbPixis->BackColor = System::Drawing::Color::Gray;
			this->pbPixis->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbPixis->Location = System::Drawing::Point(0, 0);
			this->pbPixis->Name = L"pbPixis";
			this->pbPixis->Size = System::Drawing::Size(400, 400);
			this->pbPixis->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbPixis->TabIndex = 9;
			this->pbPixis->TabStop = false;
			// 
			// btnInitializeCamera
			// 
			this->btnInitializeCamera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnInitializeCamera->Location = System::Drawing::Point(5, 10);
			this->btnInitializeCamera->Name = L"btnInitializeCamera";
			this->btnInitializeCamera->Size = System::Drawing::Size(185, 26);
			this->btnInitializeCamera->TabIndex = 10;
			this->btnInitializeCamera->Text = L"Initialize Camera";
			this->btnInitializeCamera->UseVisualStyleBackColor = true;
			this->btnInitializeCamera->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnInitializeCamera_Click);
			// 
			// lblInitializationStatus
			// 
			this->lblInitializationStatus->AutoSize = true;
			this->lblInitializationStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblInitializationStatus->ForeColor = System::Drawing::Color::Red;
			this->lblInitializationStatus->Location = System::Drawing::Point(2, 94);
			this->lblInitializationStatus->Name = L"lblInitializationStatus";
			this->lblInitializationStatus->Size = System::Drawing::Size(193, 20);
			this->lblInitializationStatus->TabIndex = 11;
			this->lblInitializationStatus->Text = L"Camera NOT Initialized";
			// 
			// btnPixisContinuousAcquisition
			// 
			this->btnPixisContinuousAcquisition->BackColor = System::Drawing::Color::Lime;
			this->btnPixisContinuousAcquisition->Enabled = false;
			this->btnPixisContinuousAcquisition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPixisContinuousAcquisition->Location = System::Drawing::Point(6, 230);
			this->btnPixisContinuousAcquisition->Name = L"btnPixisContinuousAcquisition";
			this->btnPixisContinuousAcquisition->Size = System::Drawing::Size(184, 54);
			this->btnPixisContinuousAcquisition->TabIndex = 12;
			this->btnPixisContinuousAcquisition->Text = L"Start Pixis Acquisition";
			this->btnPixisContinuousAcquisition->UseVisualStyleBackColor = false;
			this->btnPixisContinuousAcquisition->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnBeginContinuousAcquisition_Click);
			// 
			// lblSerialNumber
			// 
			this->lblSerialNumber->AutoSize = true;
			this->lblSerialNumber->ForeColor = System::Drawing::Color::White;
			this->lblSerialNumber->Location = System::Drawing::Point(3, 78);
			this->lblSerialNumber->Name = L"lblSerialNumber";
			this->lblSerialNumber->Size = System::Drawing::Size(76, 13);
			this->lblSerialNumber->TabIndex = 14;
			this->lblSerialNumber->Text = L"Serial Number:";
			// 
			// lblSensorName
			// 
			this->lblSensorName->AutoSize = true;
			this->lblSensorName->ForeColor = System::Drawing::Color::White;
			this->lblSensorName->Location = System::Drawing::Point(3, 65);
			this->lblSensorName->Name = L"lblSensorName";
			this->lblSensorName->Size = System::Drawing::Size(74, 13);
			this->lblSensorName->TabIndex = 15;
			this->lblSensorName->Text = L"Sensor Name:";
			// 
			// lblInterface
			// 
			this->lblInterface->AutoSize = true;
			this->lblInterface->ForeColor = System::Drawing::Color::White;
			this->lblInterface->Location = System::Drawing::Point(3, 52);
			this->lblInterface->Name = L"lblInterface";
			this->lblInterface->Size = System::Drawing::Size(52, 13);
			this->lblInterface->TabIndex = 16;
			this->lblInterface->Text = L"Interface:";
			// 
			// lblModel
			// 
			this->lblModel->AutoSize = true;
			this->lblModel->ForeColor = System::Drawing::Color::White;
			this->lblModel->Location = System::Drawing::Point(3, 39);
			this->lblModel->Name = L"lblModel";
			this->lblModel->Size = System::Drawing::Size(39, 13);
			this->lblModel->TabIndex = 17;
			this->lblModel->Text = L"Model:";
			// 
			// panelPixisImage
			// 
			this->panelPixisImage->AutoScroll = true;
			this->panelPixisImage->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelPixisImage->Controls->Add(this->pbPixis);
			this->panelPixisImage->Location = System::Drawing::Point(214, 27);
			this->panelPixisImage->Name = L"panelPixisImage";
			this->panelPixisImage->Size = System::Drawing::Size(400, 400);
			this->panelPixisImage->TabIndex = 29;
			// 
			// btnSaveCurrentImage
			// 
			this->btnSaveCurrentImage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSaveCurrentImage->Location = System::Drawing::Point(6, 198);
			this->btnSaveCurrentImage->Name = L"btnSaveCurrentImage";
			this->btnSaveCurrentImage->Size = System::Drawing::Size(184, 26);
			this->btnSaveCurrentImage->TabIndex = 30;
			this->btnSaveCurrentImage->Text = L"Save Current Image";
			this->btnSaveCurrentImage->UseVisualStyleBackColor = true;
			this->btnSaveCurrentImage->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnSaveCurrentImage_Click);
			// 
			// btnScreenRecording
			// 
			this->btnScreenRecording->BackColor = System::Drawing::Color::Lime;
			this->btnScreenRecording->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnScreenRecording->Location = System::Drawing::Point(5, 94);
			this->btnScreenRecording->Name = L"btnScreenRecording";
			this->btnScreenRecording->Size = System::Drawing::Size(185, 54);
			this->btnScreenRecording->TabIndex = 32;
			this->btnScreenRecording->Text = L"Start Screen Recording";
			this->btnScreenRecording->UseVisualStyleBackColor = false;
			this->btnScreenRecording->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnScreenRecording_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->infoToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1140, 24);
			this->menuStrip1->TabIndex = 34;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->viewScreenRecordingsToolStripMenuItem,
					this->viewSavedPixisImagesToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// viewScreenRecordingsToolStripMenuItem
			// 
			this->viewScreenRecordingsToolStripMenuItem->Name = L"viewScreenRecordingsToolStripMenuItem";
			this->viewScreenRecordingsToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->viewScreenRecordingsToolStripMenuItem->Text = L"View Screen Recordings";
			this->viewScreenRecordingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &PrimaryGUI::viewScreenRecordingsToolStripMenuItem_Click);
			// 
			// viewSavedPixisImagesToolStripMenuItem
			// 
			this->viewSavedPixisImagesToolStripMenuItem->Name = L"viewSavedPixisImagesToolStripMenuItem";
			this->viewSavedPixisImagesToolStripMenuItem->Size = System::Drawing::Size(200, 22);
			this->viewSavedPixisImagesToolStripMenuItem->Text = L"View Saved Pixis Images";
			this->viewSavedPixisImagesToolStripMenuItem->Click += gcnew System::EventHandler(this, &PrimaryGUI::viewSavedPixisImagesToolStripMenuItem_Click_1);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->pixisDLLToolStripMenuItem });
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->infoToolStripMenuItem->Text = L"Info";
			// 
			// pixisDLLToolStripMenuItem
			// 
			this->pixisDLLToolStripMenuItem->Name = L"pixisDLLToolStripMenuItem";
			this->pixisDLLToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->pixisDLLToolStripMenuItem->Text = L"Pixis DLL";
			this->pixisDLLToolStripMenuItem->Click += gcnew System::EventHandler(this, &PrimaryGUI::pixisDLLToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(6, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 36;
			this->label2->Text = L"Name:";
			// 
			// mtbRecording
			// 
			this->mtbRecording->Location = System::Drawing::Point(50, 45);
			this->mtbRecording->Name = L"mtbRecording";
			this->mtbRecording->Size = System::Drawing::Size(140, 20);
			this->mtbRecording->TabIndex = 37;
			this->mtbRecording->Text = L"Recording 1";
			// 
			// mtbPixisImage
			// 
			this->mtbPixisImage->Location = System::Drawing::Point(48, 172);
			this->mtbPixisImage->Name = L"mtbPixisImage";
			this->mtbPixisImage->Size = System::Drawing::Size(140, 20);
			this->mtbPixisImage->TabIndex = 38;
			this->mtbPixisImage->Text = L"Pixis Image 1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(7, 175);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Name:";
			// 
			// chartAScan
			// 
			this->chartAScan->BackColor = System::Drawing::Color::Gray;
			chartArea2->BackColor = System::Drawing::Color::Black;
			chartArea2->Name = L"ChartArea1";
			this->chartAScan->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chartAScan->Legends->Add(legend2);
			this->chartAScan->Location = System::Drawing::Point(620, 27);
			this->chartAScan->Name = L"chartAScan";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chartAScan->Series->Add(series2);
			this->chartAScan->Size = System::Drawing::Size(514, 206);
			this->chartAScan->TabIndex = 40;
			this->chartAScan->Text = L"chart1";
			// 
			// panelBScan
			// 
			this->panelBScan->AutoScroll = true;
			this->panelBScan->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panelBScan->Controls->Add(this->pbBScan);
			this->panelBScan->Location = System::Drawing::Point(620, 239);
			this->panelBScan->Name = L"panelBScan";
			this->panelBScan->Size = System::Drawing::Size(500, 500);
			this->panelBScan->TabIndex = 41;
			// 
			// pbBScan
			// 
			this->pbBScan->BackColor = System::Drawing::Color::Gray;
			this->pbBScan->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbBScan->Location = System::Drawing::Point(0, 0);
			this->pbBScan->Name = L"pbBScan";
			this->pbBScan->Size = System::Drawing::Size(500, 500);
			this->pbBScan->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbBScan->TabIndex = 9;
			this->pbBScan->TabStop = false;
			// 
			// btnOCTScan
			// 
			this->btnOCTScan->BackColor = System::Drawing::Color::Lime;
			this->btnOCTScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOCTScan->Location = System::Drawing::Point(430, 466);
			this->btnOCTScan->Name = L"btnOCTScan";
			this->btnOCTScan->Size = System::Drawing::Size(184, 54);
			this->btnOCTScan->TabIndex = 42;
			this->btnOCTScan->Text = L"Start OCT Scan";
			this->btnOCTScan->UseVisualStyleBackColor = false;
			this->btnOCTScan->Click += gcnew System::EventHandler(this, &PrimaryGUI::btnBeginOCTScan_Click);
			// 
			// cbInterpolation
			// 
			this->cbInterpolation->AutoSize = true;
			this->cbInterpolation->ForeColor = System::Drawing::Color::White;
			this->cbInterpolation->Location = System::Drawing::Point(228, 433);
			this->cbInterpolation->Name = L"cbInterpolation";
			this->cbInterpolation->Size = System::Drawing::Size(84, 17);
			this->cbInterpolation->TabIndex = 44;
			this->cbInterpolation->Text = L"Interpolation";
			this->cbInterpolation->UseVisualStyleBackColor = true;
			// 
			// lblAlazarDataPoint1
			// 
			this->lblAlazarDataPoint1->AutoSize = true;
			this->lblAlazarDataPoint1->ForeColor = System::Drawing::Color::White;
			this->lblAlazarDataPoint1->Location = System::Drawing::Point(534, 437);
			this->lblAlazarDataPoint1->Name = L"lblAlazarDataPoint1";
			this->lblAlazarDataPoint1->Size = System::Drawing::Size(13, 13);
			this->lblAlazarDataPoint1->TabIndex = 45;
			this->lblAlazarDataPoint1->Text = L"0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(6, 70);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 46;
			this->label6->Text = L"Audio:";
			// 
			// cbAudioDevices
			// 
			this->cbAudioDevices->FormattingEnabled = true;
			this->cbAudioDevices->Location = System::Drawing::Point(50, 67);
			this->cbAudioDevices->Name = L"cbAudioDevices";
			this->cbAudioDevices->Size = System::Drawing::Size(140, 21);
			this->cbAudioDevices->TabIndex = 47;
			// 
			// panelScreenRecording
			// 
			this->panelScreenRecording->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panelScreenRecording->Controls->Add(this->btnFindAudioDevices);
			this->panelScreenRecording->Controls->Add(this->cbAudioDevices);
			this->panelScreenRecording->Controls->Add(this->mtbRecording);
			this->panelScreenRecording->Controls->Add(this->label6);
			this->panelScreenRecording->Controls->Add(this->label2);
			this->panelScreenRecording->Controls->Add(this->btnScreenRecording);
			this->panelScreenRecording->Location = System::Drawing::Point(12, 55);
			this->panelScreenRecording->Name = L"panelScreenRecording";
			this->panelScreenRecording->Size = System::Drawing::Size(196, 157);
			this->panelScreenRecording->TabIndex = 48;
			// 
			// btnFindAudioDevices
			// 
			this->btnFindAudioDevices->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnFindAudioDevices->Location = System::Drawing::Point(5, 3);
			this->btnFindAudioDevices->Name = L"btnFindAudioDevices";
			this->btnFindAudioDevices->Size = System::Drawing::Size(185, 36);
			this->btnFindAudioDevices->TabIndex = 49;
			this->btnFindAudioDevices->Text = L"Find Audio Devices";
			this->btnFindAudioDevices->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(8, 32);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(137, 20);
			this->label7->TabIndex = 49;
			this->label7->Text = L"Screen Recording";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(12, 224);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(104, 20);
			this->label8->TabIndex = 50;
			this->label8->Text = L"CCD Imaging";
			// 
			// panelPixisImagingControls
			// 
			this->panelPixisImagingControls->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panelPixisImagingControls->Controls->Add(this->btnTakeSingleExposure);
			this->panelPixisImagingControls->Controls->Add(this->btnInitializeCamera);
			this->panelPixisImagingControls->Controls->Add(this->mtbExposureTime);
			this->panelPixisImagingControls->Controls->Add(this->label1);
			this->panelPixisImagingControls->Controls->Add(this->lblInitializationStatus);
			this->panelPixisImagingControls->Controls->Add(this->lblSerialNumber);
			this->panelPixisImagingControls->Controls->Add(this->btnPixisContinuousAcquisition);
			this->panelPixisImagingControls->Controls->Add(this->lblSensorName);
			this->panelPixisImagingControls->Controls->Add(this->btnSaveCurrentImage);
			this->panelPixisImagingControls->Controls->Add(this->lblInterface);
			this->panelPixisImagingControls->Controls->Add(this->label5);
			this->panelPixisImagingControls->Controls->Add(this->lblModel);
			this->panelPixisImagingControls->Controls->Add(this->mtbPixisImage);
			this->panelPixisImagingControls->Location = System::Drawing::Point(12, 247);
			this->panelPixisImagingControls->Name = L"panelPixisImagingControls";
			this->panelPixisImagingControls->Size = System::Drawing::Size(196, 296);
			this->panelPixisImagingControls->TabIndex = 51;
			// 
			// PrimaryGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1140, 747);
			this->Controls->Add(this->panelPixisImagingControls);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->panelScreenRecording);
			this->Controls->Add(this->lblAlazarDataPoint1);
			this->Controls->Add(this->cbInterpolation);
			this->Controls->Add(this->btnOCTScan);
			this->Controls->Add(this->panelBScan);
			this->Controls->Add(this->chartAScan);
			this->Controls->Add(this->panelPixisImage);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PrimaryGUI";
			this->Text = L"Falloposcope Software v1.0";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPixis))->EndInit();
			this->panelPixisImage->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAScan))->EndInit();
			this->panelBScan->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBScan))->EndInit();
			this->panelScreenRecording->ResumeLayout(false);
			this->panelScreenRecording->PerformLayout();
			this->panelPixisImagingControls->ResumeLayout(false);
			this->panelPixisImagingControls->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Global variables
	//Screen Recording
	Process^ screenRecorder = gcnew Process();
	bool recordingScreen = 0;

	//Pixis
	PicamHandle cameraHandleGlobal;					// - the selected camera (open)
	std::size_t calculatedBufferSize_ = 0;			// - calculated buffer size (bytes)
	HCURSOR acquiringCursor_ = 0;					// - the cursor shown when acquiring
	pibool acquiring_ = false;						// - controls the acquiring cursor
	HANDLE acquisitionInactive_;					// - event reset during acquisition
	int readoutStride_ = 0;							// - stride to next readout (bytes)
	int framesPerReadout_ = 0;						// - number of frames in a readout
	int frameStride_ = 0;							// - stride to next frame (bytes)
	int frameSize_ = 0;								// - size of frame (bytes)
	bool highResolution_ = false;					// - resolution > 16-bit
	int imageDataWidth_ = 0;						// - image data width (pixels)
	int imageDataHeight_ = 0;						// - image data height (pixels)
	UInt16* dataPtrUInt16;							// - pointer to image data in buffer (16 bit data)
	UInt32* dataPtrUInt32;							// - pointer to image data in buffer (32 bit data)
	bool newImageAvailable;							// - New bitmap to draw to UI
	bool bitmapExists = false;						// - True if a bitmap image is displayed in the picturebox
	double byteMultiplier16 = 255.0 / 65535.0;
	double byteMultiplier32 = 255.0 / 4294967295.0;
	bool continuousPixisImaging = 0;

	//AlazarTech
	#define EOL "\n"
	#define MAX_PROCESS 128
	#define numberOfGMABuffers 4
	bool acquiringOCT = 0;
	bool bScanExists = 0;

#pragma endregion

#pragma region Picam Enumerations

		enum class PicamError_ref
		{
			/*------------------------------------------------------------------------*/
			/* Success ---------------------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_None = 0,
			/*------------------------------------------------------------------------*/
			/* General Errors --------------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_UnexpectedError = 4,
			PicamError_UnexpectedNullPointer = 3,
			PicamError_InvalidPointer = 35,
			PicamError_InvalidCount = 39,
			PicamError_InvalidOperation = 42,
			PicamError_OperationCanceled = 43,
			/*------------------------------------------------------------------------*/
			/* Library Initialization Errors -----------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_LibraryNotInitialized = 1,
			PicamError_LibraryAlreadyInitialized = 5,
			/*------------------------------------------------------------------------*/
			/* General String Handling Errors ----------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_InvalidEnumeratedType = 16,
			PicamError_EnumerationValueNotDefined = 17,
			/*------------------------------------------------------------------------*/
			/* Camera/Accessory Plug 'n Play Discovery Errors ------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_NotDiscoveringCameras = 18,
			PicamError_AlreadyDiscoveringCameras = 19,
			PicamError_NotDiscoveringAccessories = 48,
			PicamError_AlreadyDiscoveringAccessories = 49,
			/*------------------------------------------------------------------------*/
			/* Camera/Accessory Access Errors ----------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_NoCamerasAvailable = 34,
			PicamError_CameraAlreadyOpened = 7,
			PicamError_InvalidCameraID = 8,
			PicamError_NoAccessoriesAvailable = 45,
			PicamError_AccessoryAlreadyOpened = 46,
			PicamError_InvalidAccessoryID = 47,
			PicamError_InvalidHandle = 9,
			PicamError_DeviceCommunicationFailed = 15,
			PicamError_DeviceDisconnected = 23,
			PicamError_DeviceOpenElsewhere = 24,
			/*------------------------------------------------------------------------*/
			/* Demo Camera Errors ----------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_InvalidDemoModel = 6,
			PicamError_InvalidDemoSerialNumber = 21,
			PicamError_DemoAlreadyConnected = 22,
			PicamError_DemoNotSupported = 40,
			/*------------------------------------------------------------------------*/
			/* Camera/Accessory Parameter Access Errors ------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_ParameterHasInvalidValueType = 11,
			PicamError_ParameterHasInvalidConstraintType = 13,
			PicamError_ParameterDoesNotExist = 12,
			PicamError_ParameterValueIsReadOnly = 10,
			PicamError_InvalidParameterValue = 2,
			PicamError_InvalidConstraintCategory = 38,
			PicamError_ParameterValueIsIrrelevant = 14,
			PicamError_ParameterIsNotOnlineable = 25,
			PicamError_ParameterIsNotReadable = 26,
			PicamError_ParameterIsNotWaitableStatus = 50,
			PicamError_InvalidWaitableStatusParameterTimeOut = 51,
			/*------------------------------------------------------------------------*/
			/* Camera Data Acquisition Errors ----------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamError_InvalidParameterValues = 28,
			PicamError_ParametersNotCommitted = 29,
			PicamError_InvalidAcquisitionBuffer = 30,
			PicamError_InvalidReadoutCount = 36,
			PicamError_InvalidReadoutTimeOut = 37,
			PicamError_InsufficientMemory = 31,
			PicamError_AcquisitionInProgress = 20,
			PicamError_AcquisitionNotInProgress = 27,
			PicamError_TimeOutOccurred = 32,
			PicamError_AcquisitionUpdatedHandlerRegistered = 33,
			PicamError_InvalidAcquisitionState = 44,
			PicamError_NondestructiveReadoutEnabled = 41,
			PicamError_ShutterOverheated = 52,
			PicamError_CenterWavelengthFaulted = 54,
			PicamError_CameraFaulted = 53
			/*------------------------------------------------------------------------*/
		};

		enum class PicamModel_ref
		{
			/*------------------------------------------------------------------------*/
			/* PI-MTE Series (1419) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PIMteSeries = 1400,
			/* PI-MTE 1024 Series ----------------------------------------------------*/
			PicamModel_PIMte1024Series = 1401,
			PicamModel_PIMte1024F = 1402,
			PicamModel_PIMte1024B = 1403,
			PicamModel_PIMte1024BR = 1405,
			PicamModel_PIMte1024BUV = 1404,
			/* PI-MTE 1024FT Series --------------------------------------------------*/
			PicamModel_PIMte1024FTSeries = 1406,
			PicamModel_PIMte1024FT = 1407,
			PicamModel_PIMte1024BFT = 1408,
			/* PI-MTE 1300 Series ----------------------------------------------------*/
			PicamModel_PIMte1300Series = 1412,
			PicamModel_PIMte1300B = 1413,
			PicamModel_PIMte1300R = 1414,
			PicamModel_PIMte1300BR = 1415,
			/* PI-MTE 2048 Series ----------------------------------------------------*/
			PicamModel_PIMte2048Series = 1416,
			PicamModel_PIMte2048B = 1417,
			PicamModel_PIMte2048BR = 1418,
			/* PI-MTE 2K Series ------------------------------------------------------*/
			PicamModel_PIMte2KSeries = 1409,
			PicamModel_PIMte2KB = 1410,
			PicamModel_PIMte2KBUV = 1411,
			/*------------------------------------------------------------------------*/
			/* PI-MTE3 Series (2005) -------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PIMte3Series = 2000,
			/* PI-MTE3 2048 Series ---------------------------------------------------*/
			PicamModel_PIMte32048Series = 2001,
			PicamModel_PIMte32048B = 2002,
			/*------------------------------------------------------------------------*/
			/* PIXIS Series (76) -----------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PixisSeries = 0,
			/* PIXIS 100 Series ------------------------------------------------------*/
			PicamModel_Pixis100Series = 1,
			PicamModel_Pixis100F = 2,
			PicamModel_Pixis100B = 6,
			PicamModel_Pixis100R = 3,
			PicamModel_Pixis100C = 4,
			PicamModel_Pixis100BR = 5,
			PicamModel_Pixis100BExcelon = 54,
			PicamModel_Pixis100BRExcelon = 55,
			PicamModel_PixisXO100B = 7,
			PicamModel_PixisXO100BR = 8,
			PicamModel_PixisXB100B = 68,
			PicamModel_PixisXB100BR = 69,
			/* PIXIS 256 Series ------------------------------------------------------*/
			PicamModel_Pixis256Series = 26,
			PicamModel_Pixis256F = 27,
			PicamModel_Pixis256B = 29,
			PicamModel_Pixis256E = 28,
			PicamModel_Pixis256BR = 30,
			PicamModel_PixisXB256BR = 31,
			/* PIXIS 400 Series ------------------------------------------------------*/
			PicamModel_Pixis400Series = 37,
			PicamModel_Pixis400F = 38,
			PicamModel_Pixis400B = 40,
			PicamModel_Pixis400R = 39,
			PicamModel_Pixis400BR = 41,
			PicamModel_Pixis400BExcelon = 56,
			PicamModel_Pixis400BRExcelon = 57,
			PicamModel_PixisXO400B = 42,
			PicamModel_PixisXB400BR = 70,
			/* PIXIS 512 Series ------------------------------------------------------*/
			PicamModel_Pixis512Series = 43,
			PicamModel_Pixis512F = 44,
			PicamModel_Pixis512B = 45,
			PicamModel_Pixis512BUV = 46,
			PicamModel_Pixis512BExcelon = 58,
			PicamModel_PixisXO512F = 49,
			PicamModel_PixisXO512B = 50,
			PicamModel_PixisXF512F = 48,
			PicamModel_PixisXF512B = 47,
			/* PIXIS 1024 Series -----------------------------------------------------*/
			PicamModel_Pixis1024Series = 9,
			PicamModel_Pixis1024F = 10,
			PicamModel_Pixis1024B = 11,
			PicamModel_Pixis1024BR = 13,
			PicamModel_Pixis1024BUV = 12,
			PicamModel_Pixis1024BExcelon = 59,
			PicamModel_Pixis1024BRExcelon = 60,
			PicamModel_PixisXO1024F = 16,
			PicamModel_PixisXO1024B = 14,
			PicamModel_PixisXO1024BR = 15,
			PicamModel_PixisXF1024F = 17,
			PicamModel_PixisXF1024B = 18,
			PicamModel_PixisXB1024BR = 71,
			/* PIXIS 1300 Series -----------------------------------------------------*/
			PicamModel_Pixis1300Series = 51,
			PicamModel_Pixis1300F = 52,
			PicamModel_Pixis1300F_2 = 75,
			PicamModel_Pixis1300B = 53,
			PicamModel_Pixis1300BR = 73,
			PicamModel_Pixis1300BExcelon = 61,
			PicamModel_Pixis1300BRExcelon = 62,
			PicamModel_PixisXO1300B = 65,
			PicamModel_PixisXF1300B = 66,
			PicamModel_PixisXB1300R = 72,
			/* PIXIS 2048 Series -----------------------------------------------------*/
			PicamModel_Pixis2048Series = 20,
			PicamModel_Pixis2048F = 21,
			PicamModel_Pixis2048B = 22,
			PicamModel_Pixis2048BR = 67,
			PicamModel_Pixis2048BExcelon = 63,
			PicamModel_Pixis2048BRExcelon = 74,
			PicamModel_PixisXO2048B = 23,
			PicamModel_PixisXF2048F = 25,
			PicamModel_PixisXF2048B = 24,
			/* PIXIS 2K Series -------------------------------------------------------*/
			PicamModel_Pixis2KSeries = 32,
			PicamModel_Pixis2KF = 33,
			PicamModel_Pixis2KB = 34,
			PicamModel_Pixis2KBUV = 36,
			PicamModel_Pixis2KBExcelon = 64,
			PicamModel_PixisXO2KB = 35,
			/*------------------------------------------------------------------------*/
			/* Quad-RO Series (104) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_QuadroSeries = 100,
			PicamModel_Quadro4096 = 101,
			PicamModel_Quadro4096_2 = 103,
			PicamModel_Quadro4320 = 102,
			/*------------------------------------------------------------------------*/
			/* ProEM Series (214) ----------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_ProEMSeries = 200,
			/* ProEM 512 Series ------------------------------------------------------*/
			PicamModel_ProEM512Series = 203,
			PicamModel_ProEM512B = 201,
			PicamModel_ProEM512BK = 205,
			PicamModel_ProEM512BExcelon = 204,
			PicamModel_ProEM512BKExcelon = 206,
			/* ProEM 1024 Series -----------------------------------------------------*/
			PicamModel_ProEM1024Series = 207,
			PicamModel_ProEM1024B = 202,
			PicamModel_ProEM1024BExcelon = 208,
			/* ProEM 1600 Series -----------------------------------------------------*/
			PicamModel_ProEM1600Series = 209,
			PicamModel_ProEM1600xx2B = 212,
			PicamModel_ProEM1600xx2BExcelon = 210,
			PicamModel_ProEM1600xx4B = 213,
			PicamModel_ProEM1600xx4BExcelon = 211,
			/*------------------------------------------------------------------------*/
			/* ProEM+ Series (614) ---------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_ProEMPlusSeries = 600,
			/* ProEM+ 512 Series -----------------------------------------------------*/
			PicamModel_ProEMPlus512Series = 603,
			PicamModel_ProEMPlus512B = 601,
			PicamModel_ProEMPlus512BK = 605,
			PicamModel_ProEMPlus512BExcelon = 604,
			PicamModel_ProEMPlus512BKExcelon = 606,
			/* ProEM+ 1024 Series ----------------------------------------------------*/
			PicamModel_ProEMPlus1024Series = 607,
			PicamModel_ProEMPlus1024B = 602,
			PicamModel_ProEMPlus1024BExcelon = 608,
			/* ProEM+ 1600 Series ----------------------------------------------------*/
			PicamModel_ProEMPlus1600Series = 609,
			PicamModel_ProEMPlus1600xx2B = 612,
			PicamModel_ProEMPlus1600xx2BExcelon = 610,
			PicamModel_ProEMPlus1600xx4B = 613,
			PicamModel_ProEMPlus1600xx4BExcelon = 611,
			/*------------------------------------------------------------------------*/
			/* ProEM-HS Series (1218) ------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_ProEMHSSeries = 1200,
			/* ProEM-HS 512 Series ---------------------------------------------------*/
			PicamModel_ProEMHS512Series = 1201,
			PicamModel_ProEMHS512B = 1202,
			PicamModel_ProEMHS512BK = 1207,
			PicamModel_ProEMHS512BExcelon = 1203,
			PicamModel_ProEMHS512BKExcelon = 1208,
			PicamModel_ProEMHS512B_2 = 1216,
			PicamModel_ProEMHS512BExcelon_2 = 1217,
			/* ProEM-HS 1024 Series --------------------------------------------------*/
			PicamModel_ProEMHS1024Series = 1204,
			PicamModel_ProEMHS1024B = 1205,
			PicamModel_ProEMHS1024BExcelon = 1206,
			PicamModel_ProEMHS1024B_2 = 1212,
			PicamModel_ProEMHS1024BExcelon_2 = 1213,
			PicamModel_ProEMHS1024B_3 = 1214,
			PicamModel_ProEMHS1024BExcelon_3 = 1215,
			/* ProEM-HS 1K-10 Series -------------------------------------------------*/
			PicamModel_ProEMHS1K10Series = 1209,
			PicamModel_ProEMHS1KB10 = 1210,
			PicamModel_ProEMHS1KB10Excelon = 1211,
			/*------------------------------------------------------------------------*/
			/* PI-MAX3 Series (303) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PIMax3Series = 300,
			PicamModel_PIMax31024I = 301,
			PicamModel_PIMax31024x256 = 302,
			/*------------------------------------------------------------------------*/
			/* PI-MAX4 Series (721) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PIMax4Series = 700,
			/* PI-MAX4 1024i Series --------------------------------------------------*/
			PicamModel_PIMax41024ISeries = 703,
			PicamModel_PIMax41024I = 701,
			PicamModel_PIMax41024IRF = 704,
			/* PI-MAX4 1024f Series --------------------------------------------------*/
			PicamModel_PIMax41024FSeries = 710,
			PicamModel_PIMax41024F = 711,
			PicamModel_PIMax41024FRF = 712,
			/* PI-MAX4 1024x256 Series -----------------------------------------------*/
			PicamModel_PIMax41024x256Series = 705,
			PicamModel_PIMax41024x256 = 702,
			PicamModel_PIMax41024x256RF = 706,
			/* PI-MAX4 2048 Series ---------------------------------------------------*/
			PicamModel_PIMax42048Series = 716,
			PicamModel_PIMax42048F = 717,
			PicamModel_PIMax42048B = 718,
			PicamModel_PIMax42048FRF = 719,
			PicamModel_PIMax42048BRF = 720,
			/* PI-MAX4 512EM Series --------------------------------------------------*/
			PicamModel_PIMax4512EMSeries = 708,
			PicamModel_PIMax4512EM = 707,
			PicamModel_PIMax4512BEM = 709,
			/* PI-MAX4 1024EM Series -------------------------------------------------*/
			PicamModel_PIMax41024EMSeries = 713,
			PicamModel_PIMax41024EM = 715,
			PicamModel_PIMax41024BEM = 714,
			/*------------------------------------------------------------------------*/
			/* PyLoN Series (439) ----------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PylonSeries = 400,
			/* PyLoN 100 Series ------------------------------------------------------*/
			PicamModel_Pylon100Series = 418,
			PicamModel_Pylon100F = 404,
			PicamModel_Pylon100B = 401,
			PicamModel_Pylon100BR = 407,
			PicamModel_Pylon100BExcelon = 425,
			PicamModel_Pylon100BRExcelon = 426,
			/* PyLoN 256 Series ------------------------------------------------------*/
			PicamModel_Pylon256Series = 419,
			PicamModel_Pylon256F = 409,
			PicamModel_Pylon256B = 410,
			PicamModel_Pylon256E = 411,
			PicamModel_Pylon256BR = 412,
			/* PyLoN 400 Series ------------------------------------------------------*/
			PicamModel_Pylon400Series = 420,
			PicamModel_Pylon400F = 405,
			PicamModel_Pylon400B = 402,
			PicamModel_Pylon400BR = 408,
			PicamModel_Pylon400BExcelon = 427,
			PicamModel_Pylon400BRExcelon = 428,
			/* PyLoN 1024 Series -----------------------------------------------------*/
			PicamModel_Pylon1024Series = 421,
			PicamModel_Pylon1024B = 417,
			PicamModel_Pylon1024BExcelon = 429,
			/* PyLoN 1300 Series -----------------------------------------------------*/
			PicamModel_Pylon1300Series = 422,
			PicamModel_Pylon1300F = 406,
			PicamModel_Pylon1300B = 403,
			PicamModel_Pylon1300R = 438,
			PicamModel_Pylon1300BR = 432,
			PicamModel_Pylon1300BExcelon = 430,
			PicamModel_Pylon1300BRExcelon = 433,
			/* PyLoN 2048 Series -----------------------------------------------------*/
			PicamModel_Pylon2048Series = 423,
			PicamModel_Pylon2048F = 415,
			PicamModel_Pylon2048B = 434,
			PicamModel_Pylon2048BR = 416,
			PicamModel_Pylon2048BExcelon = 435,
			PicamModel_Pylon2048BRExcelon = 436,
			/* PyLoN 2K Series -------------------------------------------------------*/
			PicamModel_Pylon2KSeries = 424,
			PicamModel_Pylon2KF = 413,
			PicamModel_Pylon2KB = 414,
			PicamModel_Pylon2KBUV = 437,
			PicamModel_Pylon2KBExcelon = 431,
			/*------------------------------------------------------------------------*/
			/* PyLoN-IR Series (904) -------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PylonirSeries = 900,
			/* PyLoN-IR 1024 Series --------------------------------------------------*/
			PicamModel_Pylonir1024Series = 901,
			PicamModel_Pylonir102422 = 902,
			PicamModel_Pylonir102417 = 903,
			/*------------------------------------------------------------------------*/
			/* PIoNIR Series (502) ---------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_PionirSeries = 500,
			PicamModel_Pionir640 = 501,
			/*------------------------------------------------------------------------*/
			/* NIRvana Series (802) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_NirvanaSeries = 800,
			PicamModel_Nirvana640 = 801,
			/*------------------------------------------------------------------------*/
			/* NIRvana ST Series (1302) ----------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_NirvanaSTSeries = 1300,
			PicamModel_NirvanaST640 = 1301,
			/*------------------------------------------------------------------------*/
			/* NIRvana-LN Series (1102) ----------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_NirvanaLNSeries = 1100,
			PicamModel_NirvanaLN640 = 1101,
			/*------------------------------------------------------------------------*/
			/* SOPHIA Series (1843) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_SophiaSeries = 1800,
			/* SOPHIA 2048 Series ----------------------------------------------------*/
			PicamModel_Sophia2048Series = 1801,
			PicamModel_Sophia2048B = 1802,
			PicamModel_Sophia2048BExcelon = 1803,
			PicamModel_SophiaXO2048B = 1804,
			PicamModel_SophiaXF2048B = 1805,
			PicamModel_SophiaXB2048B = 1806,
			/* SOPHIA 2048-13.5 Series -----------------------------------------------*/
			PicamModel_Sophia2048135Series = 1807,
			PicamModel_Sophia2048135 = 1808,
			PicamModel_Sophia2048B135 = 1809,
			PicamModel_Sophia2048BR135 = 1810,
			PicamModel_Sophia2048B135Excelon = 1811,
			PicamModel_Sophia2048BR135Excelon = 1812,
			PicamModel_SophiaXO2048B135 = 1813,
			PicamModel_SophiaXO2048BR135 = 1814,
			/*------------------------------------------------------------------------*/
			/* BLAZE Series (1519) ---------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_BlazeSeries = 1500,
			/* BLAZE 100 Series ------------------------------------------------------*/
			PicamModel_Blaze100Series = 1507,
			PicamModel_Blaze100B = 1501,
			PicamModel_Blaze100BR = 1505,
			PicamModel_Blaze100HR = 1503,
			PicamModel_Blaze100BRLD = 1509,
			PicamModel_Blaze100BExcelon = 1511,
			PicamModel_Blaze100BRExcelon = 1513,
			PicamModel_Blaze100HRExcelon = 1515,
			PicamModel_Blaze100BRLDExcelon = 1517,
			/* BLAZE 400 Series ------------------------------------------------------*/
			PicamModel_Blaze400Series = 1508,
			PicamModel_Blaze400B = 1502,
			PicamModel_Blaze400BR = 1506,
			PicamModel_Blaze400HR = 1504,
			PicamModel_Blaze400BRLD = 1510,
			PicamModel_Blaze400BExcelon = 1512,
			PicamModel_Blaze400BRExcelon = 1514,
			PicamModel_Blaze400HRExcelon = 1516,
			PicamModel_Blaze400BRLDExcelon = 1518,
			/*------------------------------------------------------------------------*/
			/* FERGIE Series (1612) --------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_FergieSeries = 1600,
			/* FERGIE 256 Series -----------------------------------------------------*/
			PicamModel_Fergie256Series = 1601,
			PicamModel_Fergie256B = 1602,
			PicamModel_Fergie256BR = 1607,
			PicamModel_Fergie256BExcelon = 1603,
			PicamModel_Fergie256BRExcelon = 1608,
			/* FERGIE 256FT Series ---------------------------------------------------*/
			PicamModel_Fergie256FTSeries = 1604,
			PicamModel_Fergie256FFT = 1609,
			PicamModel_Fergie256BFT = 1605,
			PicamModel_Fergie256BRFT = 1610,
			PicamModel_Fergie256BFTExcelon = 1606,
			PicamModel_Fergie256BRFTExcelon = 1611,
			/*------------------------------------------------------------------------*/
			/* FERGIE Accessory Series (1706) ----------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_FergieAccessorySeries = 1700,
			/* FERGIE Lamp Series ----------------------------------------------------*/
			PicamModel_FergieLampSeries = 1701,
			PicamModel_FergieAEL = 1702,
			PicamModel_FergieQTH = 1703,
			/* FERGIE Laser Series ---------------------------------------------------*/
			PicamModel_FergieLaserSeries = 1704,
			PicamModel_FergieLaser785 = 1705,
			/*------------------------------------------------------------------------*/
			/* KURO Series (1904) ----------------------------------------------------*/
			/*------------------------------------------------------------------------*/
			PicamModel_KuroSeries = 1900,
			PicamModel_Kuro1200B = 1901,
			PicamModel_Kuro1608B = 1902,
			PicamModel_Kuro2048B = 1903
			/*------------------------------------------------------------------------*/
		};
		/*----------------------------------------------------------------------------*/
		enum class PicamComputerInterface_ref
		{
			PicamComputerInterface_Usb2 = 1,
			PicamComputerInterface_1394A = 2,
			PicamComputerInterface_GigabitEthernet = 3,
			PicamComputerInterface_Usb3 = 4
		};

#pragma endregion
	
#pragma region Pixis Imaging Functions
	////////////////////////////////////////////////////////////////////////////////
	// DisplayError
	// - displays an error (with optional picam error code) in a message box
	////////////////////////////////////////////////////////////////////////////////
	void DisplayError(System::String^ message, PicamError error) {
		const pichar* errorMsg;
		Picam_GetEnumerationString(PicamEnumeratedType_Error, error, &errorMsg);
		MessageBox::Show(message + Convert::ToString(*errorMsg));
	}

	////////////////////////////////////////////////////////////////////////////////
	// DisplayPixisDLLInfo
	// - displays the current version of Picam on the UI
	////////////////////////////////////////////////////////////////////////////////
	void displayPixisDLLInfo() {
		piint major;
		piint minor;
		piint distribution;
		piint release;

		PicamError error = Picam_GetVersion(&major, &minor, &distribution, &release);
		if (error != PicamError_None) {
			DisplayError("Cannot read DLL. Not off to a good start... ", error);
		}

		MessageBox::Show(major.ToString() + "." +
			minor.ToString() + "." +
			distribution.ToString() + "." +
			release.ToString());
	}

	////////////////////////////////////////////////////////////////////////////////
	// Begins a recording of the screen for documentation of the procedure
	////////////////////////////////////////////////////////////////////////////////
	void startScreenRecording()
	{
		screenRecorder->StartInfo->FileName = System::IO::Directory::GetCurrentDirectory() + "\\ScreenRecorder.exe";
		screenRecorder->StartInfo->WindowStyle = ProcessWindowStyle::Hidden;
		screenRecorder->StartInfo->RedirectStandardInput = true;
		screenRecorder->StartInfo->UseShellExecute = false;
		screenRecorder->StartInfo->CreateNoWindow = true;
		screenRecorder->StartInfo->Arguments = mtbRecording->Text;
		screenRecorder->Start();
		btnScreenRecording->Text = "Stop Screen Recording";
		btnScreenRecording->BackColor = Color::Red;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Stops and saves the recording
	////////////////////////////////////////////////////////////////////////////////
	void stopScreenRecording()
	{
		System::IO::StreamWriter^ srInputs = screenRecorder->StandardInput;
		srInputs->WriteLine();// SendKeys::Send("{ENTER}"));
		btnScreenRecording->Text = "Start Screen Recording";
		btnScreenRecording->BackColor = Color::Green;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Delegate for acquisition update
	////////////////////////////////////////////////////////////////////////////////
	delegate PicamError AcquisitionUpdatedDelegate(PicamHandle device,
		const PicamAvailableData*     available,
		const PicamAcquisitionStatus* status);

	////////////////////////////////////////////////////////////////////////////////
	// RegisterCameraCallbacks
	// - initializes callbacks from the open camera
	////////////////////////////////////////////////////////////////////////////////
	void RegisterCameraCallbacks()
	{
		AcquisitionUpdatedDelegate^ aud = gcnew AcquisitionUpdatedDelegate(this, &PrimaryGUI::AcquisitionUpdated);
		GCHandle gch = GCHandle::Alloc(aud);
		IntPtr ip = Marshal::GetFunctionPointerForDelegate(aud);
		PicamAcquisitionUpdatedCallback pauc = static_cast<PicamAcquisitionUpdatedCallback>(ip.ToPointer());
		PicamError error = PicamAdvanced_RegisterForAcquisitionUpdated(cameraHandleGlobal, *pauc);
		if (error != PicamError_None) 
		{
			DisplayError("Failed to register for acquisition updated: ", error);
		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// GetBlackWhiteLevels
	// - returns image data corresponding to thresholds for black/white pixels
	////////////////////////////////////////////////////////////////////////////////
	void GetBlackWhiteLevels(
		const std::vector<pibyte>& imageVector,
		pi32u* black,
		pi32u* white)
	{
		// - generate an 8-bit histogram of image data intensities
		static std::vector<piint> histogram(0x100);
		histogram.assign(histogram.size(), 0);
		const piint dataPoints = static_cast<piint>(imageVector.size());
		for (piint i = 0; i < dataPoints; ++i)
		{
			++histogram[imageVector[i]];
		}

		// - find the start and end of the histogram
		pibyte b = 0, w = static_cast<pibyte>(histogram.size() - 1);
		while (!histogram[b] || !histogram[w])
		{
			if (!histogram[b])
				++b;
			if (!histogram[w])
				--w;
		}

		// - clip a small percentage of outlying values in histogram
		const piint outliers = static_cast<piint>(0.01 * dataPoints);
		piint skippedBlack = 0, skippedWhite = 0;
		while ((skippedBlack < outliers || skippedWhite < outliers) && b != w)
		{
			if (skippedBlack < outliers)
				skippedBlack += histogram[b++];
			if (skippedWhite < outliers)
				skippedWhite += histogram[w--];
		}

		// - if all data are equal set all black if zero, otherwise all white
		if (b == w)
		{
			*black = b == 0x0000 ? b : b - 1;
			*white = b == 0x0000 ? b + 1 : b;
			return;
		}

		*black = b;
		*white = w;
	}

	////////////////////////////////////////////////////////////////////////////////
	// AcquisitionUpdated
	// - called when any of the following occur during acquisition:
	//   - a new readout arrives
	//   - acquisition completes due to total readouts acquired
	//   - acquisition completes due to a stop request
	//   - acquisition completes due to an acquisition error
	//   - an acquisition error occurs
	// - called on another thread
	// - all update callbacks are serialized
	// - takes the lock
	////////////////////////////////////////////////////////////////////////////////
	PicamError PIL_CALL AcquisitionUpdated(
		PicamHandle device,
		const PicamAvailableData* available,
		const PicamAcquisitionStatus* status)
	{
		if (available && available->readout_count)
		{
			if (cbInterpolation->Checked) {
				// - copy the last available frame to the shared image buffer and notify
				AutoLock al(lock_);
				pi64s lastReadoutOffset = readoutStride_ * (available->readout_count - 1);
				pi64s lastFrameOffset = frameStride_ * (framesPerReadout_ - 1);
				const pibyte* frame = static_cast<const pibyte*>(available->initial_readout) + lastReadoutOffset + lastFrameOffset;

				//Copy data from buffer to vector. 
				std::vector<pibyte> imageVector;

				if (highResolution_)
				{
					dataPtrUInt32 = (UInt32*)frame;
					for (int y = 0; y < imageDataHeight_; y++)
					{
						for (int x = 0; x < imageDataWidth_; x++)
						{
							pibyte value = static_cast<pibyte>(*dataPtrUInt32++ * byteMultiplier32);
							imageVector.push_back(value);
						}
					}
				}
				else
				{
					dataPtrUInt16 = (UInt16*)frame;
					for (int y = 0; y < imageDataHeight_; y++)
					{
						for (int x = 0; x < imageDataWidth_; x++)
						{
							pibyte value = static_cast<pibyte>(*dataPtrUInt16++ * byteMultiplier16);
							imageVector.push_back(value);
						}
					}
				}

				// - determine linear interpolation black/white levels
				pi32u black = 0, white = 0;
				GetBlackWhiteLevels(imageVector, &black, &white);

				std::vector<pibyte> imageVectorInterpolated;

				for (int i = 0; i < imageVector.size(); i++)
				{
					pibyte data = imageVector[i];
					pibyte value = data < black ? 0 : data > white ? 255 : static_cast<pibyte>((data - black) * 255.0 / (white - black));
					imageVectorInterpolated.push_back(value);
				}

				Bitmap^ bmp = gcnew Bitmap(imageDataWidth_, imageDataHeight_, PixelFormat::Format32bppPArgb);
				BitmapData^ bmpData = bmp->LockBits(System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height), ImageLockMode::WriteOnly, bmp->PixelFormat);
				IntPtr^ imagePtr = (IntPtr)bmpData->Scan0;
				pibyte alpha = 255;

				for (int i = 0; i < imageVector.size(); i++)
				{
					//Write 3 equal values to the memory location of the first pixel
					pibyte value = imageVectorInterpolated[i];
					Marshal::WriteByte(*imagePtr, value);
					imagePtr = IntPtr::Add(*imagePtr, 1);
					Marshal::WriteByte(*imagePtr, value);
					imagePtr = IntPtr::Add(*imagePtr, 1);
					Marshal::WriteByte(*imagePtr, value);
					imagePtr = IntPtr::Add(*imagePtr, 1);
					Marshal::WriteByte(*imagePtr, alpha);
					imagePtr = IntPtr::Add(*imagePtr, 1);
				}
				bmp->UnlockBits(bmpData);

				Invoke(gcnew Action<Bitmap^>(this, &PrimaryGUI::updatePixisImage), bmp);
				WakeConditionVariable(&imageDataAvailable_);
				al.Release();
			}
			else {
				// - copy the last available frame to the shared image buffer and notify
				AutoLock al(lock_);
				pi64s lastReadoutOffset = readoutStride_ * (available->readout_count - 1);
				pi64s lastFrameOffset = frameStride_ * (framesPerReadout_ - 1);
				const pibyte* frame = static_cast<const pibyte*>(available->initial_readout) + lastReadoutOffset + lastFrameOffset;
				Bitmap^ bmp = gcnew Bitmap(imageDataWidth_, imageDataHeight_, PixelFormat::Format24bppRgb);
				BitmapData^ bmpData = bmp->LockBits(System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height), ImageLockMode::WriteOnly, bmp->PixelFormat);
				IntPtr^ imagePtr = (IntPtr)bmpData->Scan0;
				std::vector<pibyte> imageVector;
				if (highResolution_)
				{
					dataPtrUInt32 = (UInt32*)frame;
					for (int y = 0; y < imageDataHeight_; y++)
					{
						for (int x = 0; x < imageDataWidth_; x++)
						{
							//Write 3 equal values to the memory location of the first pixel
							pibyte value = static_cast<pibyte>(*dataPtrUInt32++ * byteMultiplier32);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
						}

					}
					bmp->UnlockBits(bmpData);
				}
				else
				{
					dataPtrUInt16 = (UInt16*)frame;
					for (int y = 0; y < imageDataHeight_; y++)
					{
						for (int x = 0; x < imageDataWidth_; x++)
						{
							//Write 3 equal values to the memory location of the first pixel
							pibyte value = static_cast<pibyte>(*dataPtrUInt16++ * byteMultiplier16);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
							Marshal::WriteByte(*imagePtr, value);
							imagePtr = IntPtr::Add(*imagePtr, 1);
						}

					}
					bmp->UnlockBits(bmpData);
				}
				Invoke(gcnew Action<Bitmap^>(this, &PrimaryGUI::updatePixisImage), bmp);
				WakeConditionVariable(&imageDataAvailable_);
				al.Release();
			}


			// - check for overrun after copying
			pibln overran;
			PicamError error = PicamAdvanced_HasAcquisitionBufferOverrun(device, &overran);
			if (error != PicamError_None)
			{

			}
			else if (overran)
			{

			}
		}

		// - note when acquisition has completed
		if (!status->running)
		{
			SetEvent(acquisitionInactive_);
		}

		return PicamError_None;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Initialize
	// - initialize state and camera discovery
	// - any failure quits the application
	////////////////////////////////////////////////////////////////////////////////
	pibool Initialize()
	{
		// - show wait cursor while in this function
		AutoBusy ab;

		// - initialize state
		InitializeCriticalSection(&lock_);
		acquisitionInactive_ = CreateEvent(0, true /*manual*/, true /*signaled*/, 0);
		if (!acquisitionInactive_)
		{
			MessageBox::Show("Failed to create acquisition inactive event.");
			return false;
		}
		InitializeConditionVariable(&imageDataAvailable_);

		// - initialize picam
		PicamError error = Picam_InitializeLibrary();
		if (error != PicamError_None)
		{
			DisplayError(L"Failed to initialize PICam.", error);
			return false;
		}

		//Find available camera
		const PicamCameraID *cameraIDptr;
		piint cameraIDCount;
		error = Picam_GetAvailableCameraIDs(&cameraIDptr, &cameraIDCount);
		if (error != PicamError_None)
		{
			DisplayError("Failed to get available camera ID: ", error);
			return false;
		}
		if (cameraIDCount == 0)
		{
			MessageBox::Show("No cameras available. ID count: " + cameraIDCount.ToString());
			return false;
		}

		int model = cameraIDptr->model;
		int picamInterface = cameraIDptr->computer_interface;
		lblModel->Text = Enum::GetName(PicamModel_ref::typeid, model);
		lblInterface->Text = Enum::GetName(PicamComputerInterface_ref::typeid, picamInterface);
		lblSensorName->Text = "Sensor: " + gcnew System::String(cameraIDptr->sensor_name);
		lblSerialNumber->Text = "S/N: " + gcnew System::String(cameraIDptr->serial_number);

		pibln isIDConnected;
		error = Picam_IsCameraIDConnected(cameraIDptr, &isIDConnected);
		if (error != PicamError_None)
		{
			DisplayError("Failed to connect camera ID: ", error);
			return false;
		}
		if (isIDConnected != 1)
		{
			MessageBox::Show("Camera ID not connected. Return: " + isIDConnected.ToString());
			return false;
		}

		//Create handle for available camera.
		PicamHandle cameraHandle_local;
		//Picam_OpenCamera(cameraIDptr, &cameraHandle_local);
		error = PicamAdvanced_OpenCameraDevice(cameraIDptr, &cameraHandle_local);
		if (error != PicamError_None)
		{
			DisplayError("Failed to open camera device (advanced function): ", error);
			return false;
		}

		pibln isHandleConnected;
		Picam_IsCameraConnected(cameraHandle_local, &isHandleConnected);
		if (isHandleConnected != 1)
		{
			MessageBox::Show("Camera Handle not connected. Return: " + isHandleConnected.ToString());
			return false;
		}
		cameraHandleGlobal = cameraHandle_local;

		//Initialize buffer, and callback functions for camera
		RegisterCameraCallbacks();
		InitializeCalculatedBufferSize();
		//InitializeImage();

		//Gets ROI data from the camera. Default is 1024x1024. Updates the bitmap object.
		const PicamRois *Rois_ptr;
		Picam_GetParameterRoisValue(cameraHandleGlobal, PicamParameter_Rois, &Rois_ptr);
		PicamRois Rois = *Rois_ptr;
		PicamRoi *Roi_ptr = Rois.roi_array;
		PicamRoi Roi = *Roi_ptr;
		imageDataWidth_ = Roi.width;
		imageDataHeight_ = Roi.height;
		//pixels = width * height;

		btnTakeSingleExposure->Enabled = true;
		btnPixisContinuousAcquisition->Enabled = true;
		lblInitializationStatus->Text = "Camera Initialized";
		lblInitializationStatus->ForeColor = Color::Green;

		return true;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Uninitialize
	// - clean up camera on exit
	// - handles an open and acquiring camera as well
	////////////////////////////////////////////////////////////////////////////////
	void Uninitialize()
	{
		if (cameraHandleGlobal)
		{
			// - handle an acquiring camera
			pibln running;
			PicamError error = Picam_IsAcquisitionRunning(cameraHandleGlobal, &running);
			if (error == PicamError_None && running)
			{
				error = Picam_StopAcquisition(cameraHandleGlobal);
				running =
					error != PicamError_None ||
					WaitForSingleObject(
						acquisitionInactive_,
						10000) != WAIT_OBJECT_0;
				if (running)
					DisplayError(L"Failed to stop camera.", error);
			}

			// - handle an open camera
			if (!running)
				PicamAdvanced_CloseCameraDevice(cameraHandleGlobal);
		}

		// - clean up library
		// - this is especially important for other processes using picam
		Picam_UninitializeLibrary();
	}

	////////////////////////////////////////////////////////////////////////////////
	// SetReadoutCount
	// - Sets the camera to readout either 1 image, or continuously
	////////////////////////////////////////////////////////////////////////////////
	pibool SetReadoutCount(pibool acquire)
	{
		pi64s readouts = acquire ? 1 : 0;
		PicamError error =
			Picam_SetParameterLargeIntegerValue(
				cameraHandleGlobal,
				PicamParameter_ReadoutCount,
				readouts);
		if (error != PicamError_None)
		{
			DisplayError(L"Cannot set readout count.", error);
			return false;
		}

		return true;
	}

	////////////////////////////////////////////////////////////////////////////////
	// ApplyExposureTime
	// - sets the exposure time on the selected camera
	////////////////////////////////////////////////////////////////////////////////
	pibool SetExposureTime(piflt exposure)
	{
		PicamError error = Picam_SetParameterFloatingPointValue(
				cameraHandleGlobal,
				PicamParameter_ExposureTime,
				exposure);
		if (error != PicamError_None)
		{
			DisplayError("Failed to set exposure time: ", error);
			return false;
		}

		return true;
	}

	////////////////////////////////////////////////////////////////////////////////
	// CalculateBufferSize
	// - calculates a new circular buffer size given a readout stride and rate
	////////////////////////////////////////////////////////////////////////////////
	void CalculateBufferSize(piint readoutStride, piflt onlineReadoutRate)
	{
		// - calculate a circular buffer with the following simple rules:
		//   - contain at least 3 seconds worth of readout rate
		//   - contain at least 2 readouts
		// - note this takes into account changes that affect rate online (such as
		//   exposure) by assuming worst case (fastest rate)
		pi64s readouts = static_cast<pi64s>(std::ceil(max(3.*onlineReadoutRate, 2.)));
		calculatedBufferSize_ = static_cast<std::size_t>(readoutStride * readouts);
	}

	////////////////////////////////////////////////////////////////////////////////
	// InitializeCalculatedBufferSize
	// - calculates the first buffer size for a camera just opened
	////////////////////////////////////////////////////////////////////////////////
	void InitializeCalculatedBufferSize()
	{
		// - get the current readout rate
		// - note this accounts for rate increases in online scenarios
		piflt onlineReadoutRate;
		PicamError error = Picam_GetParameterFloatingPointValue(cameraHandleGlobal, PicamParameter_OnlineReadoutRateCalculation, &onlineReadoutRate);
		if (error != PicamError_None) 
		{
			DisplayError("Failed to get online readout rate: ", error);
			return;
		}

		// - get the current readout stride
		piint readoutStride;
		error = Picam_GetParameterIntegerValue(cameraHandleGlobal, PicamParameter_ReadoutStride, &readoutStride);
		if (error != PicamError_None) 
		{
			DisplayError("Failed to get readout stride: ", error);
			return;
		}

		// - calculate the buffer size
		CalculateBufferSize(readoutStride, onlineReadoutRate);
	}

	////////////////////////////////////////////////////////////////////////////////
	// CacheFrameNavigation
	// - caches frame navigation information to extract frames from readouts
	// - takes the lock
	////////////////////////////////////////////////////////////////////////////////
	pibool CacheFrameNavigation()
	{
		// - lock before accessing shared state
		AutoLock al(lock_);

		// - cache the readout stride
		piint readoutStride;
		PicamError error = Picam_GetParameterIntegerValue(cameraHandleGlobal, PicamParameter_ReadoutStride, &readoutStride);
		if (error != PicamError_None)
		{
			DisplayError("Failed to get readout stride: ", error);
			return false;
		}
		readoutStride_ = readoutStride;

		// - cache the frame stride
		piint frameStride;
		error = Picam_GetParameterIntegerValue(cameraHandleGlobal, PicamParameter_FrameStride, &frameStride);
		if (error != PicamError_None)
		{
			DisplayError("Failed to get frame stride: ", error);
			return false;
		}
		frameStride_ = frameStride;

		// - cache the frames per readout
		piint framesPerReadout;
		error = Picam_GetParameterIntegerValue(cameraHandleGlobal, PicamParameter_FramesPerReadout, &framesPerReadout);
		if (error != PicamError_None)
		{
			DisplayError("Failed to get frames per readout: ", error);
			return false;
		}
		framesPerReadout_ = framesPerReadout;

		// - determine pixel bit depth
		piint pixelBitDepth = 0;
		error =
			Picam_GetParameterIntegerValue(
				cameraHandleGlobal,
				PicamParameter_PixelBitDepth,
				&pixelBitDepth);
		if (error != PicamError_None)
		{
			DisplayError("Failed to get pixel bit depth: ", error);
			return false;
		}
		highResolution_ = pixelBitDepth > 16;

		return true;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Start
	// - starts acquisition with the selected camera
	////////////////////////////////////////////////////////////////////////////////
	void Start()
	{
		PicamError error;

		// - determine if parameters need to be committed
		pibln committed;
		error = Picam_AreParametersCommitted(cameraHandleGlobal, &committed);
		if (error != PicamError_None)
		{
			DisplayError("Cannot determine if parameters need to be committed.", error);
			return;
		}

		// - commit parameters from the model to the device
		if (!committed)
		{
			PicamHandle model;
			error = PicamAdvanced_GetCameraModel(cameraHandleGlobal, &model);
			if (error != PicamError_None)
			{
				DisplayError("Cannot get the camera model.", error);
				return;
			}

			error = PicamAdvanced_CommitParametersToCameraDevice(model);
			if (error != PicamError_None)
			{
				DisplayError("Failed to commit the camera model parameters.", error);
				return;
			}
		}

		// - reallocate circular buffer if necessary
		if (calculatedBufferSize_ == 0)
		{
			MessageBox::Show("Cannot start with a circular buffer of no length.");
			return;
		}
		if (buffer_.size() != calculatedBufferSize_) 
		{
			buffer_.resize(calculatedBufferSize_);
		}


		// - get current circular buffer
		PicamAcquisitionBuffer buffer;
		error = PicamAdvanced_GetAcquisitionBuffer(cameraHandleGlobal, &buffer);
		if (error != PicamError_None)
		{
			DisplayError(L"Failed to get circular buffer.", error);
			return;
		}

		// - update circular buffer if neccessary
		if (&buffer_[0] != buffer.memory ||
			static_cast<pi64s>(buffer_.size()) != buffer.memory_size)
		{
			buffer.memory = &buffer_[0];
			buffer.memory_size = buffer_.size();
			error = PicamAdvanced_SetAcquisitionBuffer(cameraHandleGlobal, &buffer);
			if (error != PicamError_None)
			{
				DisplayError(L"Failed to set circular buffer.", error);
				return;
			}
		}

		// - cache information used to extract frames during acquisition
		if (!CacheFrameNavigation()) {
			return;
		}


		//// - initialize image data and display
		//if (!InitializeImage()) {
		//	return;
		//}


		// - mark acquisition active just before acquisition begins
		ResetEvent(acquisitionInactive_);

		// - start
		error = Picam_StartAcquisition(cameraHandleGlobal);
		if (error != PicamError_None)
		{
			DisplayError(L"Failed to start acquisition.", error);
			return;
		}

		// - indicate acquisition has begun
		acquiring_ = true;
		SetCursor(acquiringCursor_);
	}

	void updatePixisImage(Bitmap^ bmp) 
	{
		pbPixis->Image = bmp;
		pbPixis->Refresh();
		bitmapExists = true;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Preview
	// - runs a continuous acquisition until stop is requested
	////////////////////////////////////////////////////////////////////////////////
	void Preview()
	{
		//Sets readout count to 0, continuous exposures
		if (!SetReadoutCount(false /*acquire*/))
			return;

		//Sets exposure time from the value in the text bod
		piflt exposureTime = Convert::ToDouble(mtbExposureTime->Text);
		if (!SetExposureTime(exposureTime)) {
			return;
		}

		// - start the asynchronous acquisition
		Start();
	}

	////////////////////////////////////////////////////////////////////////////////
	// Acquire
	// - runs an acquisition for the previously specified number of readouts
	////////////////////////////////////////////////////////////////////////////////
	void Acquire()
	{
		//Sets readout count to 1, single exposure
		if (!SetReadoutCount(true /*acquire*/)) {
			return;
		}

		//Sets exposure time from the value in the text bod
		piflt exposureTime = Convert::ToDouble(mtbExposureTime->Text);
		if (!SetExposureTime(exposureTime)) {
			return;
		}

		// - start the asynchronous acquisition
		Start();
	}

	////////////////////////////////////////////////////////////////////////////////
	// Stop
	// - requests for an asynchronous acquisition to stop
	////////////////////////////////////////////////////////////////////////////////
	void Stop()
	{
		PicamError error = Picam_StopAcquisition(cameraHandleGlobal);
		if (error != PicamError_None) 
		{
			DisplayError(L"Failed to stop acquisition.", error);
		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// SaveFrame
	// - saves the last frame acquired
	// - takes the lock
	////////////////////////////////////////////////////////////////////////////////
	void SaveFrame()
	{
		if (bitmapExists == true) 
		{
			Bitmap^ bmp = gcnew Bitmap(pbPixis->Image);
			bmp->Save(System::IO::Directory::GetCurrentDirectory() + "\\Pixis Images and Video\\" + mtbPixisImage->Text + DateTime::Now.ToString("yyyyMMdd_hhmmss") + ".bmp");
		}
	}

#pragma endregion

#pragma region Pixis UI Function Calls

	private: System::Void pixisDLLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		displayPixisDLLInfo();
	}

	private: System::Void btnInitializeCamera_Click(System::Object^  sender, System::EventArgs^  e) {
		// - initialize state and picam
		if (!Initialize()) {
			return;
		}
		btnPixisContinuousAcquisition->Enabled = true;
		btnTakeSingleExposure->Enabled = true;
	}

	private: System::Void btnTakeSingleExposure_Click(System::Object^  sender, System::EventArgs^  e) {
		//Takes a single image asynchronously
		ThreadStart^ PixisSingle_threadStart = gcnew ThreadStart(this, &PrimaryGUI::Acquire);
		Thread^ PixisSingle_thread = gcnew Thread(PixisSingle_threadStart);
		PixisSingle_thread->IsBackground = true;
		PixisSingle_thread->Start();
	}

	private: System::Void btnSaveCurrentImage_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFrame();
	}

	private: System::Void btnBeginContinuousAcquisition_Click(System::Object^  sender, System::EventArgs^  e) {
		//Takes images continuously
		if (continuousPixisImaging == 0) {
			ThreadStart^ PixisContinuous_threadStart = gcnew ThreadStart(this, &PrimaryGUI::Preview);
			Thread^ PixisContinuous_thread = gcnew Thread(PixisContinuous_threadStart);
			PixisContinuous_thread->IsBackground = true;
			PixisContinuous_thread->Start();
			btnPixisContinuousAcquisition->Text = "Stop Pixis Acquisition";
			btnPixisContinuousAcquisition->BackColor = Color::Red;
			continuousPixisImaging = 1;
		}
		else if (continuousPixisImaging == 1) {
			Picam_StopAcquisition(cameraHandleGlobal);
			btnPixisContinuousAcquisition->Text = "Start Pixis Acquisition";
			btnPixisContinuousAcquisition->BackColor = Color::Green;
			continuousPixisImaging = 0;
		}

	}


	private: System::Void btnScreenRecording_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (recordingScreen == 0) {
			startScreenRecording();
			recordingScreen = 1;
		}
		else if (recordingScreen == 1) {
			stopScreenRecording();
			recordingScreen = 0;
		}
	}

	private: System::Void viewScreenRecordingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::IO::Directory::CreateDirectory(System::IO::Directory::GetCurrentDirectory() + "\\Screen Recordings\\");
		Process::Start("explorer.exe", System::IO::Directory::GetCurrentDirectory() + "\\Screen Recordings\\");
	}

	private: System::Void viewSavedPixisImagesToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e)
	{
		System::IO::Directory::CreateDirectory(System::IO::Directory::GetCurrentDirectory() + "\\Pixis Images and Video\\");
		Process::Start("explorer.exe", System::IO::Directory::GetCurrentDirectory() + "\\Pixis Images and Video\\");
	}

#pragma endregion

#pragma region SS-OCT Functions
	//////////////////////////////////////////////////////////////
	//SS-OCT Global Variables
	//////////////////////////////////////////////////////////////
	Bitmap^ bScan;
	int i = 0;
	cli::array<byte>^ bScanOldColumns = gcnew cli::array<byte>(1024 * 1023 * 4);


#define ERROR_CHECK(x)                                                         \
    do {                                                                       \
        RETURN_CODE retCode = (x);                                             \
        if (retCode != ApiSuccess) {                                           \
            MessageBox::Show("Error: " + gcnew System::String(#x) + " , " + gcnew System::String(AlazarErrorToText(retCode)));                                \
            return ApiFailed;                                                  \
        }                                                                      \
    } while (0)

#define CL_CHECK(x)                                                            \
    do {                                                                       \
        int clStatus = (x);                                                    \
        if (clStatus != CL_SUCCESS) {                                          \
            MessageBox::Show("Error: " +  gcnew System::String(#x) + " , " + Convert::ToString(clStatus));                \
            return ApiFailed;                                                  \
            break;                                                             \
        }                                                                      \
    } while (0)

	//RETURN_CODE ConfigureBoard(HANDLE boardHandle);
	//RETURN_CODE AcquireDataGMA(HANDLE boardHandle);
	//RETURN_CODE PrepareProgramAndKernel(cl_context aOpenCL, cl_device_id aDevice,
	//	std::string program, char *programName,
	//	cl_program *aProgram, cl_kernel *aKernel);
	//RETURN_CODE GetPlatform(cl_platform_id *clPlatform);
	//RETURN_CODE CreateContext(cl_platform_id clPlatform, cl_device_id clDevice,
	//	cl_context *clContext);
			 
	RETURN_CODE GetPlatform(cl_platform_id *clPlatform) {
		if (!clPlatform)
			return ApiInvalidData;

		cl_uint lNum;

		CL_CHECK(clGetPlatformIDs(0, NULL, &lNum));

		if (lNum <= 0) {
			printf(__FUNCTION__ " - No platform" EOL);
			return ApiInvalidHandle;
		}

		std::vector<cl_platform_id> lPlatforms(lNum);

		CL_CHECK(clGetPlatformIDs(lNum, &lPlatforms[0], NULL));

		for (unsigned int i = 0; i < lNum; i++) {
			char lBuffer[128];
			CL_CHECK(clGetPlatformInfo(lPlatforms[i], CL_PLATFORM_VENDOR,
				sizeof(lBuffer), lBuffer, NULL));

			if (0 == strcmp("Advanced Micro Devices, Inc.", lBuffer)) {
				(*clPlatform) = lPlatforms[i];
				return ApiSuccess;
			}
		}

		printf(__FUNCTION__ " - No supported platform found" EOL);
		return ApiInvalidHandle;
	}

	RETURN_CODE CreateContext(cl_platform_id clPlatform, cl_device_id clDevice,
		cl_context *clContext) {
		if (!clContext)
			return ApiInvalidData;

		cl_int clStatus;

		cl_context_properties lProperties[3];

		lProperties[0] = CL_CONTEXT_PLATFORM;
		lProperties[1] = (cl_context_properties)(clPlatform);
		lProperties[2] = 0;

		(*clContext) =
			clCreateContext(lProperties, 1, &clDevice, NULL, NULL, &clStatus);
		if (CL_SUCCESS != clStatus) {
			printf(__FUNCTION__ " - clCreateContext( , , , , ,  )  failed "
				"indicating %d \n",
				clStatus);
			return ApiFailed;
		}

		return ApiSuccess;
	}

	RETURN_CODE PrepareProgramAndKernel(cl_context clContext, cl_device_id clDevice,
		std::string program, char *programName,
		cl_program *clProgram,
		cl_kernel *clKernel) {

		cl_int clStatus;

		const size_t program_size = program.size();
		const char *c_program = program.c_str();
		*clProgram = clCreateProgramWithSource(clContext, 1, &c_program,
			&program_size, &clStatus);
		if (CL_SUCCESS == clStatus) {
			CL_CHECK(clBuildProgram(*clProgram, 1, &clDevice, "", NULL, NULL));

			*clKernel = clCreateKernel(*clProgram, programName, &clStatus);
			if (CL_SUCCESS == clStatus) {
				// (*aKernel) = lKernel;
				// (*aProgram) = lProgram;
			}
			else {
				CL_CHECK(clReleaseProgram(*clProgram));
			}
		}

		else {
			printf(__FUNCTION__ " - clCreateProgramWithSource( , , , ,  ) failed "
				"indicating ");
		}
		return ApiSuccess;
	}

	RETURN_CODE ConfigureBoard(HANDLE boardHandle) {

		// TODO: Select clock parameters as required to generate this sample rate.
		//
		// For example: if samplesPerSec is 100.e6 (100 MS/s), then:
		// - select clock source INTERNAL_CLOCK and sample rate SAMPLE_RATE_100MSPS
		// - select clock source FAST_EXTERNAL_CLOCK, sample rate
		// SAMPLE_RATE_USER_DEF, and connect a 100 MHz signal to the EXT CLK BNC
		// connector.

		// Typical values for each type of board using INTERNAL_CLOCK :
		// ATS9373 : SAMPLE_RATE_2000MSPS
		// ATS9360 : SAMPLE_RATE_1800MSPS
		// ATS9350 : SAMPLE_RATE_500MSPS
		// ATS9351 : SAMPLE_RATE_500MSPS
		// ATS9440 : SAMPLE_RATE_125MSPS
		// ATS9870 : SAMPLE_RATE_1000MSPS
		// ATS9462 : SAMPLE_RATE_180MSPS
		// ATS9626 : SAMPLE_RATE_250MSPS

		ERROR_CHECK(
			AlazarSetCaptureClock(boardHandle,          // HANDLE -- board handl
				INTERNAL_CLOCK,       // U32 -- clock source id
				SAMPLE_RATE_50MSPS, // U32 -- sample rate id
				CLOCK_EDGE_FALLING,    // U32 -- clock edge id
				0 // U32 -- clock decimatfidion
			));

		// TODO: Select CHA input parameters as required
		// Board specific input ranges
		// ATS9373, ATS9360, ATS9351 only support INPUT_RANGE_PM_400_MV.
		// ATS9625 and ATS9626 only support INPUT_RANGE_PM_1_V_25.
		// ATS9350, ATS9870 ATS9440 and ATS9462 support multiple input ranges.
		// Common values are INPUT_RANGE_PM_1_V and INPUT_RANGE_PM_400_MV.
		// ATS9416 supports either INPUT_RANGE_PM_1_V or INPUT_RANGE_PM_500_MV
		// See ATS-SDK guide for more information.

		ERROR_CHECK(
			AlazarInputControl(boardHandle,           // HANDLE -- board handle
				CHANNEL_A,             // U8 -- input channel
				DC_COUPLING,           // U32 -- input coupling id
				INPUT_RANGE_PM_4_V, // U32 -- input range id
				IMPEDANCE_50_OHM       // U32 -- input impedance id
			));

		// TODO: Select CHB input parameters as required
		// Board specific input ranges
		// ATS9373, ATS9360, ATS9351 only support INPUT_RANGE_PM_400_MV.
		// ATS9625 and ATS9626 only support INPUT_RANGE_PM_1_V_25.
		// ATS9350, ATS9870 ATS9440 and ATS9462 support multiple input ranges.
		// Common values are INPUT_RANGE_PM_1_V and INPUT_RANGE_PM_400_MV.
		// ATS9416 supports either INPUT_RANGE_PM_1_V or INPUT_RANGE_PM_500_MV
		// ATS9462 supports IMPEDANCE_50_OHM and IMPEDANCE_1M_OHM.
		// All other PCIE board only support IMPEDANCE_50_OHM
		// See ATS-SDK guide for more information.
		//ERROR_CHECK(
		//	AlazarInputControl(boardHandle,           // HANDLE -- board handle
		//		CHANNEL_B,             // U8 -- channel identifier
		//		DC_COUPLING,           // U32 -- input coupling id
		//		INPUT_RANGE_PM_4_V, // U32 -- input range id
		//		IMPEDANCE_50_OHM       // U32 -- input impedance id
		//	));

		// TODO: Select trigger inputs and levels as required
		// Typical values for trigger source id include TRIG_CHAN_A, TRIG_CHAN_B and
		// TRIG_EXTERNAL
		ERROR_CHECK(AlazarSetTriggerOperation(
			boardHandle,            // HANDLE -- board handle
			TRIG_ENGINE_OP_J,       // U32 -- trigger operation
			TRIG_ENGINE_J,          // U32 -- trigger engine id
			TRIG_EXTERNAL,          // U32 -- trigger source id
			TRIGGER_SLOPE_NEGATIVE, // U32 -- trigger slope id
			150,           // U32 -- trigger level from 0 (-range) to 255 (+range)
			TRIG_ENGINE_K, // U32 -- trigger engine id
			TRIG_DISABLE,  // U32 -- trigger source id for engine K
			TRIGGER_SLOPE_POSITIVE, // U32 -- trigger slope id
			128 // U32 -- trigger level from 0 (-range) to 255 (+range)
		));

		// TODO: Select external trigger parameters as required
		// Typical values :
		// external trigger range id
		// ATS9462 : ETR_5V
		// ATS9870 : ETR_5V
		// All other boards : ETR_TTL
		// See ATS-SDK guide for more information.

		ERROR_CHECK(AlazarSetExternalTrigger(
			boardHandle, // HANDLE -- board handle
			DC_COUPLING, // U32 -- external trigger coupling id
			ETR_TTL      // U32 -- external trigger range id
		));

		// TODO: Set trigger delay as required.

		ERROR_CHECK(AlazarSetTriggerDelay(boardHandle, 0));

		// TODO: Set trigger timeout as required.

		// NOTE:
		// The board will wait for a for this amount of time for a trigger event.
		// If a trigger event does not arrive, then the board will automatically
		// trigger. Set the trigger timeout value to 0 to force the board to wait
		// forever for a trigger event.
		//
		// IMPORTANT:
		// The trigger timeout value should be set to zero after appropriate
		// trigger parameters have been determined, otherwise the
		// board may trigger if the timeout interval expires before a
		// hardware trigger event arrives.

		ERROR_CHECK(AlazarSetTriggerTimeOut(
			boardHandle, // HANDLE -- board handle
			0            // U32 -- timeout_sec / 10.e-6 (0 means wait forever)
		));

		// TODO: Configure AUX I/O connector as required
		ERROR_CHECK(AlazarConfigureAuxIO(boardHandle,     // HANDLE -- board handle
			AUX_OUT_TRIGGER, // U32 -- mode
			0                // U32 -- parameter
		));

		return ApiSuccess;
	}
			 
	void updateBScan(Bitmap^ bmp)
	{
		pbBScan->Image = bmp;
		pbBScan->Refresh();
	}

	void updateAScan(cli::array<float>^ aScan)
	{
		chartAScan->Series[0]->Points->DataBindY(aScan);
		chartAScan->Refresh();
	}

	void OCTScanAsyncThreadEntry() {
		RETURN_CODE c = beginOCTScan();
	}

	void updateAlazarDataPoint1(System::String^ dataPoint) {
		lblAlazarDataPoint1->Text = dataPoint;
	}

	RETURN_CODE beginOCTScan()
	{
		// TODO: Select a Alazar Device
		U32 systemId = 1;
		U32 boardId = 1;

		// Get a handle to the ATSboard
		HANDLE boardHandle = AlazarGetBoardBySystemID(systemId, boardId);
		if (boardHandle == NULL) {
			printf("Error: Unable to open board system Id %u board Id %u\n",
				systemId, boardId);
			return ApiFailed;
		}

		// Configure the board's sample rate, input, and trigger settings
		if (ConfigureBoard(boardHandle) != ApiSuccess) {
			printf("Error: Configure board failed\n");
			return ApiFailed;
		}

		//// Make an acquisition, process data with GPU, optionally saving sample data
		//// to a file
		//printf("ADMA acquisition with GPU processing: \n");

		//if (AcquireDataGMA(boardHandle) != ApiSuccess) {
		//	printf("Error: Acquisition failed\n");
		//	return 1;
		//}

		cl_int clStatus;

		// TODO: Select a AMD FirePro GPU
		U32 deviceCount;
		cl_device_id clDevice;
		ERROR_CHECK(ATS_GMA_QueryDeviceCount(boardHandle, &deviceCount));

		ERROR_CHECK(ATS_GMA_GetComputeDevice(boardHandle, 0, &clDevice));

		// TODO: Select the number of post-trigger samples per record
		U32 postTriggerSamples = 1748;

		// Use ATS_GMA_MODE_TRADITIONAL to use pretrigger samples. Otherwise keep
		// this at 0.
		U32 preTriggerSamples = 300;

		// TODO: Specify the number of records per DMA buffer
		// In continous streaming or triggered streaming mode, this must be 1.
		U32 recordsPerBuffer = 800;

		// TODO: Specifiy the total number of buffers to capture
		U32 buffersPerAcquisition = 100; //this parameter becomes useless

		// TODO: Select which channels to capture (A, B, or both)
		// Example : CHANNEL_A or CHANNEL_B for one channel acquisition.
		// channelMask = CHANNEL_A | CHANNEL_B; for 2 channels.
		// for ATS9440 : channelMask = CHANNEL_A | CHANNE_B | CHANNEL_C | CHANNEL_D;
		// is also possible
		// ATS9416 supports up to 16 channels (CHANNEL_A to CHANNEL_P)
		// See ATS-SDK guide for supported combinations

		U32 channelMask = CHANNEL_A;

		// Calculate the number of enabled channels from the channel mask

		int channelCount = 0;
		long channelsPerBoard;
		ERROR_CHECK(AlazarGetParameter(boardHandle, CHANNEL_ALL,
			GET_CHANNELS_PER_BOARD, &channelsPerBoard));
		for (int channelIndex = 0; channelIndex < channelsPerBoard;
			channelIndex++) {
			U32 channelId = 1U << channelIndex;
			if (channelId & channelMask)
				channelCount++;
		}

		if (channelCount == 0 || channelCount > channelsPerBoard) {
			printf("Error: Invalid channel mask %08X\n", channelMask);
			return ApiFailed;
		}

		// TODO : set AutoDMA flags for acquisition
		U32 autoDMAFlags;
		autoDMAFlags = ADMA_EXTERNAL_STARTCAPTURE | ADMA_NPT;  //only post trigger samples?????

		// TODO : set OCT flags
		U32 OCTFlags = ATS_GMA_OCT_LOG_OUTPUT;

		// Calculate the number of outputs based on flags used
		const bool outputLog = (OCTFlags & ATS_GMA_OCT_LOG_OUTPUT) != 0;
		const bool outputAmplitude = (OCTFlags & ATS_GMA_OCT_AMPLITUDE_OUTPUT) != 0;
		const bool outputPhase = (OCTFlags & ATS_GMA_OCT_PHASE_OUTPUT) != 0;
		const bool outputReal = (OCTFlags & ATS_GMA_OCT_REAL_OUTPUT) != 0;
		const bool outputImag = (OCTFlags & ATS_GMA_OCT_IMAG_OUTPUT) != 0;
		U8 numberOfOutputs = (outputLog ? 1 : 0) + (outputAmplitude ? 1 : 0) +
			(outputPhase ? 1 : 0) + (outputReal ? 1 : 0) +
			(outputImag ? 1 : 0);

		if (numberOfOutputs == 0) {
			numberOfOutputs = 1;
			OCTFlags |= ATS_GMA_OCT_AMPLITUDE_OUTPUT;
		}

		// TODO : set packing mode
		const U32 pack_mode = PACK_DEFAULT;

		// TODO : specify if a user defined OpenCL context is used
		bool UserDefinedContext = false;

		// TODO : set ATS-GPU flags
		U32 atsGMAFlags = 0;

		// set unpacking on GPU
		const bool unpack = false;

		// TODO : set deinterleaving
		const bool deinterleave = false;

		if (unpack) {
			atsGMAFlags |= ATS_GMA_SETUP_FLAG_UNPACK;
		}
		if (deinterleave) {
			atsGMAFlags |= ATS_GMA_SETUP_FLAG_DEINTERLEAVE;
		}

		ERROR_CHECK(
			AlazarSetParameter(boardHandle, CHANNEL_ALL, PACK_MODE, pack_mode));

		// TODO: Select if you wish to send processed buffers to host memory
		bool readProcessedBuffer = true;

		// TODO: Select if you wish to save the data to file

		//// saveLastBuffer will only save the last buffer of an acquisition.
		//FILE *rawdataFile = NULL;
		//bool saveLastRawBuffer = true;
		//if (saveLastRawBuffer) {
		//	rawdataFile = fopen("rawdata_gpu.bin", "wb");
		//	if (rawdataFile == NULL) {
		//		printf("Error: Unable to create data file -- %u\n", GetLastError());
		//		return ApiFailed;
		//	}
		//}

		//bool saveLastProcessedBuffer = true;
		//FILE *processdataFile = NULL;
		//if (saveLastProcessedBuffer) {
		//	processdataFile = fopen("processdata_gpu.bin", "wb");
		//	if (processdataFile == NULL) {
		//		printf("Error: Unable to create data file -- %u\n", GetLastError());
		//		return ApiFailed;
		//	}
		//}

		// Get the sample size in bits, and the on-board memory size in samples per
		// channel

		U8 bitsPerSample;
		U32 maxSamplesPerChannel;
		ERROR_CHECK(AlazarGetChannelInfo(boardHandle, &maxSamplesPerChannel,
			&bitsPerSample));

		// Calculate the size of each DMA buffer in bytes
		float bytesPerSample = (float)((bitsPerSample + 7) / 8);

		bitsPerSample = (int)bytesPerSample * 8;

		if (pack_mode == PACK_8_BITS_PER_SAMPLE) {
			bytesPerSample = 1.0;
		}
		if (pack_mode == PACK_12_BITS_PER_SAMPLE) {
			bytesPerSample = 1.5;
		}

		U32 bytesPerSampleOut = sizeof(float);

		U32 samplesPerRecordPerChannel = preTriggerSamples + postTriggerSamples;

		// TODO : Determine FFT padding length
		U32 ZeroPaddingLength = 0;
		U32 FFTLength = samplesPerRecordPerChannel + ZeroPaddingLength;

		U32 binsPerBuffer =
			samplesPerRecordPerChannel * recordsPerBuffer * channelCount;

		U32 bytesPerBuffer = (U32)(bytesPerSample * binsPerBuffer);

		U32 binsPerResultBuffer =
			(FFTLength / 2) * recordsPerBuffer * channelCount * numberOfOutputs;

		// Setup the acquisition

		cl_context clContext;
		if (UserDefinedContext == true) {
			cl_platform_id clPlatform;
			GetPlatform(&clPlatform);
			CreateContext(clPlatform, clDevice, &clContext);
			atsGMAFlags |= ATS_GMA_SETUP_FLAG_USER_DEFINED_CONTEXT;
		}

		cl_command_queue clQueue;
		cl_kernel clKernel[MAX_PROCESS];
		cl_program clProgram[MAX_PROCESS];

		ERROR_CHECK(ATS_GMA_OCT_Setup(
			boardHandle, channelMask, 0, samplesPerRecordPerChannel,
			recordsPerBuffer, 0x7FFFFFFF, FFTLength,
			autoDMAFlags, atsGMAFlags, OCTFlags, &clContext, &clDevice));

		std::vector<float> window(samplesPerRecordPerChannel);

		ERROR_CHECK(ATS_GMA_OCT_GenerateWindowFunction(
			FFT_WINDOW_HANNING, &window[0], samplesPerRecordPerChannel));

		ERROR_CHECK(ATS_GMA_OCT_SetWindowFunction(
			boardHandle, samplesPerRecordPerChannel, &window[0], NULL));

		std::string data_inversion = R"(
			__kernel void data_inversion(__global const float *bufferIn,
								  __global float *bufferOut) {
				const int sampleInBuffer = get_global_id(0);
			for (int i = 0; i<20 ; i++)
				bufferOut[sampleInBuffer] = -bufferIn[sampleInBuffer];
			})";

		////////////// Prepare custom program and kernel /////////////////
		int kernelIndex = 0;
		std::string program = data_inversion;

		PrepareProgramAndKernel(clContext, clDevice, program, "data_inversion",
			&clProgram[kernelIndex], &clKernel[kernelIndex]);
		cl_mem data_inversion_out = clCreateBuffer(
			clContext, CL_MEM_WRITE_ONLY, bytesPerSampleOut * binsPerResultBuffer,
			NULL, &clStatus);
		if (clStatus != CL_SUCCESS) {
			printf(__FUNCTION__ " - clCreateBuffer( , , , ,  ) failed "
				"indicating %d \n",
				clStatus);
		}

		CL_CHECK(clSetKernelArg(clKernel[kernelIndex], 1, sizeof(void *),
			&data_inversion_out));
		/////////////////////////////////////////////////////////////////////

		// Set global work size
		size_t global_work_size = binsPerResultBuffer;

		// Create GMA Buffer Array
		cl_mem BufferArray[numberOfGMABuffers];

		// Allocate GMA Buffer Array
		for (int i = 0; i < numberOfGMABuffers; i++) {
			BufferArray[i] = ATS_GMA_OCT_AllocBuffer(boardHandle, bytesPerBuffer);
		}

		// Post buffers and set first argument of first kernel to
		// buffers in BufferArray
		for (int i = 0; i < numberOfGMABuffers; i++) {
			ERROR_CHECK(ATS_GMA_OCT_PostBuffer(boardHandle, BufferArray[i]));
		}

		auto start_time = std::chrono::system_clock::now();
		System::Diagnostics::Stopwatch^ sw = gcnew System::Diagnostics::Stopwatch();

		ATS_GMA_OCT_StartCapture(boardHandle);

		unsigned int BufferIndex;
		U32 timeout_ms = 5000;

		cl_mem ironOut_output;
		cl_mem sampleToComplex_output;
		cl_mem fft_output;
		cl_mem complexToResult_output;

		//Creates a fully black image if one doesn't exist already.
		if (!bScanExists)
		{
			Bitmap^ bmp = gcnew Bitmap(1024, 1024, PixelFormat::Format32bppPArgb);
			BitmapData^ bmpData = bmp->LockBits(System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height), ImageLockMode::WriteOnly, bmp->PixelFormat);
			IntPtr^ pixel = bmpData->Scan0;

			for (int y = 0; y < bmp->Height; y++)
			{
				for (int x = 0; x < bmp->Width; x++)
				{
					Marshal::WriteByte(*pixel, 255);
					pixel = IntPtr::Add(*pixel, 1);
					Marshal::WriteByte(*pixel, 0);
					pixel = IntPtr::Add(*pixel, 1);
					Marshal::WriteByte(*pixel, 0);
					pixel = IntPtr::Add(*pixel, 1);
					Marshal::WriteByte(*pixel, 255);
					pixel = IntPtr::Add(*pixel, 1);
				}
			}
			bScanExists = 1;
			bmp->UnlockBits(bmpData);
			bScan = bmp;

			bmpData = bmp->LockBits(System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height), ImageLockMode::ReadOnly, bmp->PixelFormat);
			Marshal::Copy(bmpData->Scan0, bScanOldColumns, 0, 1024 * 1023 * 4);
			bmp->UnlockBits(bmpData);
		}

		Invoke(gcnew Action<Bitmap^>(this, &PrimaryGUI::updateBScan), bScan);

		float *pHostBuffer;
		int itterator = 0;

		// for (unsigned int i = 0; i < buffersPerAcquisition; i++) {
		while (acquiringOCT == 1) {

			sw->Start();

			//BufferIndex = i % numberOfGMABuffers;
			BufferIndex = itterator % numberOfGMABuffers;

			ERROR_CHECK(ATS_GMA_OCT_GetBuffer(boardHandle, BufferArray[BufferIndex],
				&ironOut_output, &clQueue, timeout_ms,
				NULL));

			ERROR_CHECK(ATS_GMA_OCT_PreFFT(boardHandle, &ironOut_output,
				&sampleToComplex_output, NULL, NULL));

			ERROR_CHECK(ATS_GMA_OCT_FFT(boardHandle, &sampleToComplex_output,
				&fft_output, NULL, NULL));

			//// Custom kernel after FFT
			// CL_CHECK(clSetKernelArg(clKernel[0], 0, sizeof(void *),
			// &fft_output)); CL_CHECK(clEnqueueNDRangeKernel(clQueue, clKernel[0],
			// 1, NULL,
			//                                &global_work_size, NULL, 0, NULL,
			//                                NULL));

			ERROR_CHECK(ATS_GMA_OCT_PostFFT(boardHandle, &fft_output,
				&complexToResult_output, NULL, NULL));

			if (readProcessedBuffer == 1) {
				ATS_GMA_OCT_ReadOutputBuffer(boardHandle, &complexToResult_output,
					&pHostBuffer, NULL, NULL);
			}

			///////////////////////////////////////////////////
			//Full Speed A-Scan
			///////////////////////////////////////////////////
			cli::array<float>^ aScan = gcnew cli::array<float>(1024 * 1) { 0 };
			Marshal::Copy((IntPtr)pHostBuffer, aScan, 0, 1024);
			//for (int i = 0; i < aScan->Length; i++) {
			//	aScan[i] = *pHostBuffer++;
			//}
			Invoke(gcnew Action<cli::array<float>^>(this, &PrimaryGUI::updateAScan), aScan);

			/////////////////////////////////////////////////////
			////Slowed A-Scan
			/////////////////////////////////////////////////////
			//cli::array<float>^ aScan = gcnew cli::array<float>(1024) { 0 };
			////Display A-Scan to graph on GUI
			//if (itterator > 10) {
			//	for (int j = 0; j < recordsPerBuffer; j++) {
			//		for (int i = 0; i < aScan->Length; i++) {
			//			aScan[i] = *pHostBuffer++;
			//		}
			//		Invoke(gcnew Action<System::String^>(this, &PrimaryGUI::updateAlazarDataPoint1), Convert::ToString(j));
			//		Invoke(gcnew Action<cli::array<float>^>(this, &PrimaryGUI::updateAScan), aScan);
			//		Thread::Sleep(500);
			//	}
			//}

			//Display B-Scan on GUI
			BitmapData^ bmpData = bScan->LockBits(System::Drawing::Rectangle(0, 0, bScan->Width, bScan->Height), ImageLockMode::WriteOnly, bScan->PixelFormat);
			IntPtr^ pixel = bmpData->Scan0;

			////Move location of pixelCurrent to be one ahead of pixelNew. 
			////for (int y = 0; y < bScan->Height; y++)
			////{
			////	for (int x = 0; x < bScan->Width - 200; x++)
			////	{
			////		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 600));
			////		pixel = IntPtr::Add(*pixel, 1);
			////		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 600));
			////		pixel = IntPtr::Add(*pixel, 1);
			////		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 600));
			////		pixel = IntPtr::Add(*pixel, 1);
			////	}
			////	pixel = IntPtr::Add(*pixel, 600);
			////}
			////Write the new A-Scans to the last 200 columns of the B-Scan image.
			////for (int x = 0; x < 200; x++)
			////{
			////	pixel = bScanData->Scan0;
			////	pixel = IntPtr::Add(*pixel, 45000 + x*3);
			////	for (int y = 0; y < bScan->Height; y++)
			////	{
			////		byte value = static_cast<byte>(*pHostBuffer++);
			////		Marshal::WriteByte(*pixel, value);
			////		pixel = IntPtr::Add(*pixel, 1);
			////		Marshal::WriteByte(*pixel, value);
			////		pixel = IntPtr::Add(*pixel, 1);
			////		Marshal::WriteByte(*pixel, value);
			////		pixel = IntPtr::Add(*pixel, 15199 * 3);
			////	}
			////}

			//for (int y = 0; y < bScan->Height; y++)
			//{
			//	for (int x = 0; x < bScan->Width - 1; x++)
			//	{
			//		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 4));
			//		pixel = IntPtr::Add(*pixel, 1);
			//		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 4));
			//		pixel = IntPtr::Add(*pixel, 1);
			//		Marshal::WriteByte(*pixel, Marshal::ReadByte(*pixel + 4));
			//		pixel = IntPtr::Add(*pixel, 2);
			//	}
			//	pixel = IntPtr::Add(*pixel, 4);
			//}

			//pixel = bmpData->Scan0;
			//pixel = IntPtr::Add(*pixel, 1023 * 4);
			for (int x = 0; x < bScan->Width; x++)
			{
				byte value = static_cast<byte>(*pHostBuffer++);
				Marshal::WriteByte(*pixel, value);
				pixel = IntPtr::Add(*pixel, 1);
				Marshal::WriteByte(*pixel, value);
				pixel = IntPtr::Add(*pixel, 1);
				Marshal::WriteByte(*pixel, value);
				pixel = IntPtr::Add(*pixel, 2);
			}

			Marshal::Copy(bScanOldColumns, 0, *pixel, 1024 * 1023 * 4);
			bScan->UnlockBits(bmpData);

			bmpData = bScan->LockBits(System::Drawing::Rectangle(0, 0, bScan->Width, bScan->Height), ImageLockMode::ReadOnly, bScan->PixelFormat);
			Marshal::Copy(bmpData->Scan0, bScanOldColumns, 0, 1024 * 1023 * 4);
			bScan->UnlockBits(bmpData);
			Invoke(gcnew Action<Bitmap^>(this, &PrimaryGUI::updateBScan), bScan);

			////Unlock bits
			//bScan->UnlockBits(bScanData);
			////Write the new Bitmap to the B-Scan PictureBox
			//Invoke(gcnew Action<Bitmap^>(this, &PrimaryGUI::updateBScan), bScan);

			ERROR_CHECK(
				ATS_GMA_OCT_PostBuffer(boardHandle, BufferArray[BufferIndex]));

			//printf("buffers completed %i \r", itterator);
			itterator++;
			sw->Stop();
			Invoke(gcnew Action<System::String^>(this, &PrimaryGUI::updateAlazarDataPoint1), Convert::ToString(sw->ElapsedMilliseconds));
			sw->Reset();
		}

		auto end_time = std::chrono::system_clock::now();
		auto time_span =
			static_cast<std::chrono::duration<double>>(end_time - start_time);
		//printf("operation took : %lf \n", time_span.count());
		//printf("buffers acquired size : %u  \n", buffersPerAcquisition);
		//printf("buffer size : %u bytes \n", bytesPerBuffer);

		//if (saveLastRawBuffer) {
		//	using T = uint16_t;

		//	std::vector<T> lastRawData(binsPerBuffer);
		//	CL_CHECK(clEnqueueReadBuffer(clQueue, BufferArray[BufferIndex], CL_TRUE,
		//		0, (U32)(binsPerBuffer * bytesPerSample),
		//		&lastRawData[0], 0, NULL, NULL));
		//	size_t binsWritten =
		//		fwrite(&lastRawData[0], sizeof(uint8_t),
		//		(U32)(binsPerBuffer * bytesPerSample), rawdataFile);
		//}

		//if (saveLastProcessedBuffer) {

		//	float *pHostBuffer;
		//	ATS_GMA_OCT_ReadOutputBuffer(boardHandle, &complexToResult_output,
		//		&pHostBuffer, NULL, NULL);

		//	size_t binsWritten = fwrite(
		//		pHostBuffer, sizeof(uint8_t),
		//		(U32)binsPerResultBuffer * bytesPerSampleOut, processdataFile);
		//}

		// Release Buffer Array
		for (int i = 0; i < numberOfGMABuffers; i++) {
			ERROR_CHECK(ATS_GMA_OCT_FreeBuffer(boardHandle, BufferArray[i]));
		}

		for (int i = 0; i <= kernelIndex; i++) {
			CL_CHECK(clReleaseProgram(clProgram[i]));
			CL_CHECK(clReleaseKernel(clKernel[i]));
		}

		// User is responsible of deleting all cl_mem objects created
		CL_CHECK(clReleaseMemObject(data_inversion_out));

		ERROR_CHECK(ATS_GMA_OCT_AbortCapture(boardHandle));
	}


#pragma endregion

#pragma region SS-OCT UI Function Calls
	private: System::Void btnBeginOCTScan_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (acquiringOCT == 0) {
			//Graph initialization parameters
			chartAScan->Series[0]->Color = Color::White;
			chartAScan->ChartAreas[0]->AxisY->Minimum = -200;
			chartAScan->ChartAreas[0]->AxisY->Maximum = 200;
			//Sets up OCT scanning on another thread. This can only run functions with a VOID return type!
			ThreadStart^ OCT_threadStart = gcnew ThreadStart(this, &PrimaryGUI::OCTScanAsyncThreadEntry);
			Thread^ OCT_thread = gcnew Thread(OCT_threadStart);
			OCT_thread->IsBackground = true;
			acquiringOCT = 1;
			OCT_thread->Start();
			btnOCTScan->Text = "Stop OCT Scan";
			btnOCTScan->BackColor = Color::Red;
		}
		else if (acquiringOCT == 1) {
			acquiringOCT = 0;
			btnOCTScan->Text = "Start OCT Scan";
			btnOCTScan->BackColor = Color::Green;
		}
	}
#pragma endregion
};

}
