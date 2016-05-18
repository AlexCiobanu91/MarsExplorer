#pragma once
#include "3DForm.h"
namespace MarsExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuForm
	/// </summary>
	public ref class MenuForm : public System::Windows::Forms::Form
	{
	public:
		MenuForm(void)
		{
			InitializeComponent();
      this->StartPosition = FormStartPosition::CenterScreen;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuForm()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::Button^  btnStart;
  protected:


  private: System::Windows::Forms::Button^  btnExit;
  private: System::Windows::Forms::Button^  btnAbout;
  protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->btnStart = (gcnew System::Windows::Forms::Button());
      this->btnExit = (gcnew System::Windows::Forms::Button());
      this->btnAbout = (gcnew System::Windows::Forms::Button());
      this->SuspendLayout();
      // 
      // btnStart
      // 
      this->btnStart->BackColor = System::Drawing::Color::Transparent;
      this->btnStart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
      this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::System;
      this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->btnStart->Location = System::Drawing::Point(101, 71);
      this->btnStart->Name = L"btnStart";
      this->btnStart->Size = System::Drawing::Size(155, 45);
      this->btnStart->TabIndex = 1;
      this->btnStart->Text = L"Start";
      this->btnStart->UseVisualStyleBackColor = false;
      this->btnStart->Click += gcnew System::EventHandler(this, &MenuForm::btnStart_Click);
      // 
      // btnExit
      // 
      this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::System;
      this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->btnExit->Location = System::Drawing::Point(101, 173);
      this->btnExit->Name = L"btnExit";
      this->btnExit->Size = System::Drawing::Size(155, 45);
      this->btnExit->TabIndex = 3;
      this->btnExit->Text = L"Exit";
      this->btnExit->UseVisualStyleBackColor = true;
      this->btnExit->Click += gcnew System::EventHandler(this, &MenuForm::btnExit_Click);
      // 
      // btnAbout
      // 
      this->btnAbout->FlatStyle = System::Windows::Forms::FlatStyle::System;
      this->btnAbout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->btnAbout->Location = System::Drawing::Point(101, 122);
      this->btnAbout->Name = L"btnAbout";
      this->btnAbout->Size = System::Drawing::Size(155, 45);
      this->btnAbout->TabIndex = 4;
      this->btnAbout->Text = L"About";
      this->btnAbout->UseVisualStyleBackColor = true;
      // 
      // MenuForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
      this->ClientSize = System::Drawing::Size(338, 304);
      this->Controls->Add(this->btnAbout);
      this->Controls->Add(this->btnExit);
      this->Controls->Add(this->btnStart);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
      this->Location = System::Drawing::Point(400, 300);
      this->Name = L"MenuForm";
      this->Text = L"Mars Explorer (v 1.0)";
      this->ResumeLayout(false);

    }
#pragma endregion

  private: System::Void btn2DAttempt_Click(System::Object^  sender, System::EventArgs^  e) {
  }

  private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
    Application::Exit();
  }
  private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e);
};
}
