#include <string>
#include <windows.h>

#include "Form_Main.h"
#include "Connection_DB.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int __clrcall Main(array<String^>^ args) {
	Connection_DB^ cnx = gcnew Connection_DB();
	while (cnx->isConnected()) {
		Sleep(5);
		cnx = gcnew Connection_DB();
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	POOProjet::MyForm monFormulaire;
	Application::Run(% monFormulaire);

	return 0;
}