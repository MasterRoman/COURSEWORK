#include "Controller.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    GOSTDiagram::Controller form; //WinFormsTest - ��� ������ �������
    Application::Run(% form);
}
