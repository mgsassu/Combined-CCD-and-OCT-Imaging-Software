#include "PrimaryGUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FalloposcopeSoftwarev10::PrimaryGUI gui;
	Application::Run(%gui);
}