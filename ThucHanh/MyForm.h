#pragma once
#include "Dulieu.h"
namespace ThucHanh {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::IO;
	using namespace System::Xml;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		double x = 1, y;
		int c = 0;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ btnVe;
	private: System::Windows::Forms::Button^ btnPause;


	public:
		Form^ obj;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm(Form^ obj1)
		{
			obj = obj1;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnHienthi;
	private: System::ComponentModel::IContainer^ components;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->btnHienthi = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btnVe = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnHienthi
			// 
			this->btnHienthi->Location = System::Drawing::Point(12, 32);
			this->btnHienthi->Name = L"btnHienthi";
			this->btnHienthi->Size = System::Drawing::Size(124, 66);
			this->btnHienthi->TabIndex = 0;
			this->btnHienthi->Text = L"Form điều khiển";
			this->btnHienthi->UseVisualStyleBackColor = true;
			this->btnHienthi->Click += gcnew System::EventHandler(this, &MyForm::btnHienthi_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(177, 32);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->MarkerSize = 10;
			series1->Name = L"Gia tri";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"Do am";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(633, 300);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// btnVe
			// 
			this->btnVe->Location = System::Drawing::Point(12, 147);
			this->btnVe->Name = L"btnVe";
			this->btnVe->Size = System::Drawing::Size(124, 66);
			this->btnVe->TabIndex = 0;
			this->btnVe->Text = L"Vẽ đồ thị";
			this->btnVe->UseVisualStyleBackColor = true;
			this->btnVe->Click += gcnew System::EventHandler(this, &MyForm::btnVe_Click);
			// 
			// btnPause
			// 
			this->btnPause->Location = System::Drawing::Point(12, 266);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(124, 66);
			this->btnPause->TabIndex = 0;
			this->btnPause->Text = L"Xóa";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &MyForm::btnPause_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 377);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->btnVe);
			this->Controls->Add(this->btnHienthi);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	Form^ frm = gcnew Dulieu(this);
	private: System::Void btnHienthi_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Form^ frm = gcnew Dulieu(this);		
		frm->Show();				
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{		
		chart1->Series["Gia tri"]->Points->AddXY(dulieu.toa_do_x - 1 , dulieu.a);
		chart1->Series["Do am"]->Points->AddXY(dulieu.toa_do_x - 1, dulieu.b);			
	}
	private: System::Void btnVe_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		timer1->Start();
	}
	private: System::Void btnPause_Click(System::Object^ sender, System::EventArgs^ e)  // btnXoa
	{				
		chart1->Series["Gia tri"]->Points->Clear();
		chart1->Series["Do am"]->Points->Clear();
	}
};
}
