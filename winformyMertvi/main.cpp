#include"MyForm.h"

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	winformyMertvi::MyForm form;

	Application::Run(% form);
}

