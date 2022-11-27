#include <string>

#include "Form_Main.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int __clrcall Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	POOProjet::MyForm monFormulaire;
	Application::Run(% monFormulaire);

	return 0;
}