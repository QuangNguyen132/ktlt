#pragma once
#include <exception>
#include "MyForm.h"
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
	

	struct MyStruct
	{
		double a, b;		
		int toa_do_x;
	}dulieu;


	/// <summary>
	/// Summary for Dulieu
	/// </summary>
	public ref class Dulieu : public System::Windows::Forms::Form
	{				
		String^ SDatas = String::Empty; // Khai báo chuỗi để lưu dữ liệu cảm biến gửi qua Serial
		String^ SRealTime = String::Empty; // Khai báo chuỗi để lưu thời gian gửi qua Serial
		String^ all = String::Empty;
		String^ datetime = String::Empty;
		String^ ngaythang = String::Empty;
		int status = 0; // Khai báo biến để xử lý sự kiện vẽ đồ thị
		String^ datainput;
		int x = 1;
		SerialPort^ P = gcnew SerialPort();
		//System::Delegate void SetTextCallback(String text);
	public: double datas; //Khai báo biến dữ liệu cảm biến để vẽ đồ thị
	public:	double realtime; //Khai báo biến thời gian để vẽ đồ thị
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	public:
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ txtNoidung;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripMenuItem^ fileDataToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ xoaDuLieuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ chonFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ thoátToolStripMenuItem1;
	public:
		Form^ obj;
		Dulieu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Dulieu(Form^ obj1)
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
		~Dulieu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:
	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::Button^ btnRun;
	private: System::Windows::Forms::Button^ btnPause;
	private: System::Windows::Forms::Button^ btnVedothi;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::ColumnHeader^ item;
	private: System::Windows::Forms::ColumnHeader^ subitem;
	private: System::Windows::Forms::ColumnHeader^ cot3;
	private: System::Windows::Forms::ColumnHeader^ cot4;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::ComponentModel::IContainer^ components;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->btnVedothi = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->item = (gcnew System::Windows::Forms::ColumnHeader());
			this->subitem = (gcnew System::Windows::Forms::ColumnHeader());
			this->cot3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->cot4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xoaDuLieuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chonFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->thoátToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->txtNoidung = (gcnew System::Windows::Forms::TextBox());
			this->statusStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 57);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(238, 46);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(142, 44);
			this->btnConnect->TabIndex = 1;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &Dulieu::btnConnect_Click);
			// 
			// btnRun
			// 
			this->btnRun->Location = System::Drawing::Point(386, 46);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(142, 44);
			this->btnRun->TabIndex = 1;
			this->btnRun->Text = L"Run";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Dulieu::btnRun_Click);
			// 
			// btnPause
			// 
			this->btnPause->Location = System::Drawing::Point(534, 46);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(142, 44);
			this->btnPause->TabIndex = 1;
			this->btnPause->Text = L"Pause";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &Dulieu::btnPause_Click);
			// 
			// btnVedothi
			// 
			this->btnVedothi->Location = System::Drawing::Point(685, 46);
			this->btnVedothi->Name = L"btnVedothi";
			this->btnVedothi->Size = System::Drawing::Size(142, 44);
			this->btnVedothi->TabIndex = 1;
			this->btnVedothi->Text = L"Hiển thị dữ liệu file";
			this->btnVedothi->UseVisualStyleBackColor = true;
			this->btnVedothi->Click += gcnew System::EventHandler(this, &Dulieu::btnVedothi_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->item, this->subitem,
					this->cot3, this->cot4
			});
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 98);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(529, 388);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Dulieu::listView1_SelectedIndexChanged);
			// 
			// item
			// 
			this->item->Text = L"Time";
			this->item->Width = 100;
			// 
			// subitem
			// 
			this->subitem->Text = L"Data";
			this->subitem->Width = 100;
			// 
			// cot3
			// 
			this->cot3->Text = L"Do am";
			this->cot3->Width = 100;
			// 
			// cot4
			// 
			this->cot4->Text = L"All";
			this->cot4->Width = 100;
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Dulieu::serialPort1_DataReceived);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Dulieu::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Dulieu::timer2_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(567, 371);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(257, 115);
			this->textBox1->TabIndex = 3;
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 499);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(839, 26);
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(128, 20);
			this->toolStripStatusLabel1->Text = L"toolStripStatusLabel1";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(151, 20);
			this->toolStripStatusLabel2->Text = L"toolStripStatusLabel2";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripStyle = System::Windows::Forms::ToolStripGripStyle::Visible;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileDataToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(839, 30);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileDataToolStripMenuItem
			// 
			this->fileDataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->xoaDuLieuToolStripMenuItem,
					this->chonFileToolStripMenuItem, this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem, this->thoátToolStripMenuItem1
			});
			this->fileDataToolStripMenuItem->Name = L"fileDataToolStripMenuItem";
			this->fileDataToolStripMenuItem->Size = System::Drawing::Size(80, 26);
			this->fileDataToolStripMenuItem->Text = L"File data";
			this->fileDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dulieu::fileDataToolStripMenuItem_Click);
			// 
			// xoaDuLieuToolStripMenuItem
			// 
			this->xoaDuLieuToolStripMenuItem->Name = L"xoaDuLieuToolStripMenuItem";
			this->xoaDuLieuToolStripMenuItem->Size = System::Drawing::Size(305, 26);
			this->xoaDuLieuToolStripMenuItem->Text = L"Xoa du lieu";
			this->xoaDuLieuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dulieu::xoaDuLieuToolStripMenuItem_Click);
			// 
			// chonFileToolStripMenuItem
			// 
			this->chonFileToolStripMenuItem->Name = L"chonFileToolStripMenuItem";
			this->chonFileToolStripMenuItem->Size = System::Drawing::Size(305, 26);
			this->chonFileToolStripMenuItem->Text = L"Chon file";
			this->chonFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dulieu::chonFileToolStripMenuItem_Click);
			// 
			// hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem
			// 
			this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem->Name = L"hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem";
			this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem->Size = System::Drawing::Size(305, 26);
			this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem->Text = L"Hiển thị dữ liệu nhận từ Arduino";
			this->hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dulieu::hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem_Click);
			// 
			// thoátToolStripMenuItem1
			// 
			this->thoátToolStripMenuItem1->Name = L"thoátToolStripMenuItem1";
			this->thoátToolStripMenuItem1->Size = System::Drawing::Size(305, 26);
			this->thoátToolStripMenuItem1->Text = L"Thoát";
			this->thoátToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Dulieu::thoátToolStripMenuItem1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// txtNoidung
			// 
			this->txtNoidung->Location = System::Drawing::Point(567, 98);
			this->txtNoidung->Multiline = true;
			this->txtNoidung->Name = L"txtNoidung";
			this->txtNoidung->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtNoidung->Size = System::Drawing::Size(257, 267);
			this->txtNoidung->TabIndex = 6;
			// 
			// Dulieu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 525);
			this->Controls->Add(this->txtNoidung);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->btnVedothi);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->comboBox1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Dulieu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Tag = L"dulieu";
			this->Text = L"Dulieu";
			this->Load += gcnew System::EventHandler(this, &Dulieu::Dulieu_Load);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Dulieu_Load(System::Object^ sender, System::EventArgs^ e)
	{
		array<String^>^ allport = SerialPort::GetPortNames();
		comboBox1->Items->AddRange(allport);
		toolStripStatusLabel1->Text = "Disconnect!";
		textBox1->Enabled = false;
		toolStripStatusLabel2->Text = "File";
	}
	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
	{		
		datainput = serialPort1->ReadLine()->ToString();
		array<String^>^ bien;		
		try
		{
			if (datainput != String::Empty)
			{
				bien = datainput->Split('|');
				SRealTime = bien[0];
				SDatas = bien[1];
				all = datainput;
			}
		}
		catch (Exception^ ex)
		{
			serialPort1->Close();
			datainput = String::Empty;
			MessageBox::Show(L"Sai roi!");
		}		
		status = 1;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			if ((SDatas != String::Empty) && (SRealTime != String::Empty))
			{
				datas = Double::Parse(SDatas);
				dulieu.a = datas;
				realtime = Double::Parse(SRealTime);
				dulieu.b = realtime;
			}
		}
		catch (Exception^ ex)
		{
			serialPort1->Close();
			SDatas = String::Empty;
			SRealTime = String::Empty;
			MessageBox::Show(L"Bi loi roi!");			
		}		
		if (datainput != String::Empty)
		{
			Data_ListView();
			textBox1->Text += datainput + L"\n";
		}		
		x += 1;
		dulieu.toa_do_x = x;
		StreamWriter^ wr = gcnew StreamWriter(toolStripStatusLabel2->Text->Trim(), true);
		wr->WriteLine("Ngay : " + ngaythang);
		wr->WriteLine("Thoi gian: " + datetime);	
		wr->WriteLine("Gia tri: " + datas);
		wr->WriteLine("Do am: " + realtime);
		wr->WriteLine("-----------------");
		wr->Close();
	}
	private: void Data_ListView()
		{
			   if (status == 0)
			   {
				   return;
			   }
			   else
			   {
				   ListViewItem^ item = gcnew ListViewItem();				   
				   item->Text = Convert::ToString(x);
				   listView1->Items->Add(item);
				   ListViewItem::ListViewSubItem^ subitem = gcnew ListViewItem::ListViewSubItem(item, SDatas);
				   subitem->Text = SDatas;
				   item->SubItems->Add(subitem);
				   ListViewItem::ListViewSubItem^ cot3 = gcnew ListViewItem::ListViewSubItem(item, SRealTime);
				   cot3->Text = SRealTime;
				   item->SubItems->Add(cot3);
				   ListViewItem::ListViewSubItem^ cot4 = gcnew ListViewItem::ListViewSubItem(item, datetime);
				   cot4->Text = datetime;
				   item->SubItems->Add(cot4);
			   }
		   }	
	private: System::Void btnConnect_Click(System::Object^ sender, System::EventArgs^ e)
	{
		serialPort1->PortName = comboBox1->Text;
		serialPort1->Open();
		toolStripStatusLabel1->Text = "Connected!";		
		timer2->Start();
	}
	private: System::Void btnRun_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (serialPort1->IsOpen)
		{
			serialPort1->Write("1");
			timer1->Start();
			timer2->Start();			
			toolStripStatusLabel1->Text = "Dang gui du lieu";			
		}
		else
		{
			MessageBox::Show(L"Bạn không thể chạy khi chưa kết nối với thiết bị", "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnPause_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (serialPort1->IsOpen)
		{
			serialPort1->Write("0");
			timer1->Stop();
			timer2->Stop();			
			toolStripStatusLabel1->Text = "Tam dung!";			
		}
		else
		{
			this->Close();
		}
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		System::DateTime dt = System::DateTime::Now.Add(TimeSpan());
		datetime = String::Format(L"{0:hh:mm:ss}", dt);
		ngaythang = String::Format(L"{0:dd/MM/yyyy}", dt);
	}	
	private: System::Void btnVedothi_Click(System::Object^ sender, System::EventArgs^ e) // btn Hien thi du lieu
	{		
		StreamReader^ read = gcnew StreamReader(openFileDialog1->FileName);
		txtNoidung->Text = read->ReadToEnd();
		read->Close();		
	}
	private: System::Void hiệnThịDữLiệuTừArduinoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		textBox1->Enabled = true;
	}
	private: System::Void thoátToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MessageBox::Show(L"Bạn có muốn thoát?", "Thông báo", MessageBoxButtons::OK, MessageBoxIcon::Error);		
	}
	public: System::Void fileDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{		
	}	
	private: System::Void xoaDuLieuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) // chưa tìm được cách xóa dữ liệu trong file
	{
		StreamReader^ read = gcnew StreamReader(openFileDialog1->FileName);		
	}
	private: System::Void chonFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		openFileDialog1->Filter = "|*.txt"; // chon file txt
		openFileDialog1->ShowDialog();		
		toolStripStatusLabel2->Enabled = true;
		toolStripStatusLabel2->Text = openFileDialog1->FileName;		
	}
	private: System::Void thoátToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	private: System::Void hiểnThịDữLiệuNhậnTừArduinoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		textBox1->Enabled = true;
	}
};
}
