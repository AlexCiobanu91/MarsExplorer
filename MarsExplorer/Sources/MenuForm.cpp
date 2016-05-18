#include "..\Headers\MenuForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  MarsExplorer::MenuForm form;
  Application::Run(%form);
}

System::Void MarsExplorer::MenuForm::btnStart_Click(System::Object ^ sender, System::EventArgs ^ e)
{
  My3DForm ^frm = gcnew My3DForm();
  frm->Show();
  this->Hide();
  return System::Void();
}
