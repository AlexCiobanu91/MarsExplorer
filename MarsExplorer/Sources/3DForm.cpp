#include "..\Headers\3DForm.h"
using namespace System;
using namespace System::Windows::Forms;

namespace MarsExplorer {
  System::Void My3DForm::btnReturn_Click(System::Object^  sender, System::EventArgs^  e) {
    MenuForm ^ frm = gcnew MenuForm();
    frm->Show();
    this->Hide();
  }
}
