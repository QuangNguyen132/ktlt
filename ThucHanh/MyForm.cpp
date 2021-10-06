#include "MyForm.h"
#include "Dulieu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace ThucHanh; // is your project name

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm()); // is your form class
}