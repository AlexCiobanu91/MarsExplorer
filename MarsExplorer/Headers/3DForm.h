#pragma once
#include "MenuForm.h"
#include "MarsExplorer.h"
namespace MarsExplorer {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  /// <summary>
  /// Summary for My3DForm
  /// </summary>
  public ref class My3DForm : public System::Windows::Forms::Form
  {
  public:
    My3DForm(void)
    {
      InitializeComponent();
      this->StartPosition = FormStartPosition::CenterScreen;
    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~My3DForm()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::Button^  btnStart;
  protected:
  private: System::Windows::Forms::Button^  btnReturn;
  private: System::Windows::Forms::GroupBox^  groupBox1;
  private: System::Windows::Forms::TextBox^  txtLeaderSpawnRate;
  private: System::Windows::Forms::Label^  label11;
  private: System::Windows::Forms::TextBox^  txtLeaderLifeSpan;
  private: System::Windows::Forms::Label^  label3;
  private: System::Windows::Forms::TextBox^  txtNoLeaders;
  private: System::Windows::Forms::Label^  label2;
  private: System::Windows::Forms::GroupBox^  groupBox2;
  private: System::Windows::Forms::TextBox^  txtModelX;
  private: System::Windows::Forms::CheckBox^  chk3D;
  private: System::Windows::Forms::CheckBox^  chk2D;
  private: System::Windows::Forms::TextBox^  txtDistanceThreshold;
  private: System::Windows::Forms::Label^  label10;
  private: System::Windows::Forms::TextBox^  txtAgentDistance;
  private: System::Windows::Forms::Label^  label9;
  private: System::Windows::Forms::Label^  label5;
  private: System::Windows::Forms::Label^  label6;
  private: System::Windows::Forms::Label^  label7;
  private: System::Windows::Forms::Label^  label8;
  private: System::Windows::Forms::TextBox^  txtModelZ;
  private: System::Windows::Forms::TextBox^  txtModelY;

  private: System::Windows::Forms::Label^  label4;
  private: System::Windows::Forms::Label^  label1;
  private: System::Windows::Forms::TextBox^  txtSwarmSize;
  private: System::Windows::Forms::TextBox^  txtInitialDelay;
  private: System::Windows::Forms::Label^  label12;
  private: System::Windows::Forms::GroupBox^  groupBox3;
  private: System::Windows::Forms::Label^  label20;
  private: System::Windows::Forms::TextBox^  txtSimulationTime;
  private: System::Windows::Forms::TextBox^  txtOutputFile;
  private: System::Windows::Forms::Label^  label13;


























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
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(My3DForm::typeid));
      this->btnStart = (gcnew System::Windows::Forms::Button());
      this->btnReturn = (gcnew System::Windows::Forms::Button());
      this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
      this->txtInitialDelay = (gcnew System::Windows::Forms::TextBox());
      this->label12 = (gcnew System::Windows::Forms::Label());
      this->txtLeaderSpawnRate = (gcnew System::Windows::Forms::TextBox());
      this->label11 = (gcnew System::Windows::Forms::Label());
      this->txtLeaderLifeSpan = (gcnew System::Windows::Forms::TextBox());
      this->label3 = (gcnew System::Windows::Forms::Label());
      this->txtNoLeaders = (gcnew System::Windows::Forms::TextBox());
      this->label2 = (gcnew System::Windows::Forms::Label());
      this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
      this->txtModelX = (gcnew System::Windows::Forms::TextBox());
      this->txtDistanceThreshold = (gcnew System::Windows::Forms::TextBox());
      this->label10 = (gcnew System::Windows::Forms::Label());
      this->txtAgentDistance = (gcnew System::Windows::Forms::TextBox());
      this->label9 = (gcnew System::Windows::Forms::Label());
      this->label5 = (gcnew System::Windows::Forms::Label());
      this->label6 = (gcnew System::Windows::Forms::Label());
      this->label7 = (gcnew System::Windows::Forms::Label());
      this->label8 = (gcnew System::Windows::Forms::Label());
      this->txtModelZ = (gcnew System::Windows::Forms::TextBox());
      this->txtModelY = (gcnew System::Windows::Forms::TextBox());
      this->label4 = (gcnew System::Windows::Forms::Label());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->txtSwarmSize = (gcnew System::Windows::Forms::TextBox());
      this->chk3D = (gcnew System::Windows::Forms::CheckBox());
      this->chk2D = (gcnew System::Windows::Forms::CheckBox());
      this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
      this->txtOutputFile = (gcnew System::Windows::Forms::TextBox());
      this->label13 = (gcnew System::Windows::Forms::Label());
      this->label20 = (gcnew System::Windows::Forms::Label());
      this->txtSimulationTime = (gcnew System::Windows::Forms::TextBox());
      this->groupBox1->SuspendLayout();
      this->groupBox2->SuspendLayout();
      this->groupBox3->SuspendLayout();
      this->SuspendLayout();
      // 
      // btnStart
      // 
      this->btnStart->BackColor = System::Drawing::Color::Transparent;
      this->btnStart->FlatStyle = System::Windows::Forms::FlatStyle::System;
      this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->btnStart->ForeColor = System::Drawing::SystemColors::WindowText;
      this->btnStart->Location = System::Drawing::Point(355, 337);
      this->btnStart->Name = L"btnStart";
      this->btnStart->Size = System::Drawing::Size(155, 45);
      this->btnStart->TabIndex = 1;
      this->btnStart->Text = L"Start";
      this->btnStart->UseVisualStyleBackColor = true;
      this->btnStart->Click += gcnew System::EventHandler(this, &My3DForm::btnStart_Click);
      // 
      // btnReturn
      // 
      this->btnReturn->BackColor = System::Drawing::Color::Transparent;
      this->btnReturn->FlatStyle = System::Windows::Forms::FlatStyle::System;
      this->btnReturn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->btnReturn->ForeColor = System::Drawing::SystemColors::WindowText;
      this->btnReturn->Location = System::Drawing::Point(550, 337);
      this->btnReturn->Name = L"btnReturn";
      this->btnReturn->Size = System::Drawing::Size(155, 45);
      this->btnReturn->TabIndex = 2;
      this->btnReturn->Text = L"Return";
      this->btnReturn->UseVisualStyleBackColor = true;
      this->btnReturn->Click += gcnew System::EventHandler(this, &My3DForm::btnReturn_Click);
      // 
      // groupBox1
      // 
      this->groupBox1->BackColor = System::Drawing::Color::Transparent;
      this->groupBox1->Controls->Add(this->txtInitialDelay);
      this->groupBox1->Controls->Add(this->label12);
      this->groupBox1->Controls->Add(this->txtLeaderSpawnRate);
      this->groupBox1->Controls->Add(this->label11);
      this->groupBox1->Controls->Add(this->txtLeaderLifeSpan);
      this->groupBox1->Controls->Add(this->label3);
      this->groupBox1->Controls->Add(this->txtNoLeaders);
      this->groupBox1->Controls->Add(this->label2);
      this->groupBox1->Location = System::Drawing::Point(355, 12);
      this->groupBox1->Name = L"groupBox1";
      this->groupBox1->Size = System::Drawing::Size(350, 319);
      this->groupBox1->TabIndex = 25;
      this->groupBox1->TabStop = false;
      this->groupBox1->Text = L"Leader properties";
      // 
      // txtInitialDelay
      // 
      this->txtInitialDelay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtInitialDelay->Location = System::Drawing::Point(199, 118);
      this->txtInitialDelay->Name = L"txtInitialDelay";
      this->txtInitialDelay->Size = System::Drawing::Size(145, 27);
      this->txtInitialDelay->TabIndex = 35;
      this->txtInitialDelay->Text = L"10";
      // 
      // label12
      // 
      this->label12->AutoSize = true;
      this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label12->Location = System::Drawing::Point(6, 121);
      this->label12->Name = L"label12";
      this->label12->Size = System::Drawing::Size(92, 20);
      this->label12->TabIndex = 34;
      this->label12->Text = L"Initial delay";
      // 
      // txtLeaderSpawnRate
      // 
      this->txtLeaderSpawnRate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtLeaderSpawnRate->Location = System::Drawing::Point(199, 85);
      this->txtLeaderSpawnRate->Name = L"txtLeaderSpawnRate";
      this->txtLeaderSpawnRate->Size = System::Drawing::Size(145, 27);
      this->txtLeaderSpawnRate->TabIndex = 33;
      this->txtLeaderSpawnRate->Text = L"10";
      // 
      // label11
      // 
      this->label11->AutoSize = true;
      this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label11->Location = System::Drawing::Point(6, 88);
      this->label11->Name = L"label11";
      this->label11->Size = System::Drawing::Size(119, 20);
      this->label11->TabIndex = 32;
      this->label11->Text = L"Spawn rate (s)";
      // 
      // txtLeaderLifeSpan
      // 
      this->txtLeaderLifeSpan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtLeaderLifeSpan->Location = System::Drawing::Point(199, 52);
      this->txtLeaderLifeSpan->Name = L"txtLeaderLifeSpan";
      this->txtLeaderLifeSpan->Size = System::Drawing::Size(145, 27);
      this->txtLeaderLifeSpan->TabIndex = 31;
      this->txtLeaderLifeSpan->Text = L"60";
      // 
      // label3
      // 
      this->label3->AutoSize = true;
      this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label3->Location = System::Drawing::Point(6, 55);
      this->label3->Name = L"label3";
      this->label3->Size = System::Drawing::Size(104, 20);
      this->label3->TabIndex = 30;
      this->label3->Text = L"Life span (s)";
      // 
      // txtNoLeaders
      // 
      this->txtNoLeaders->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtNoLeaders->Location = System::Drawing::Point(199, 19);
      this->txtNoLeaders->Name = L"txtNoLeaders";
      this->txtNoLeaders->Size = System::Drawing::Size(145, 27);
      this->txtNoLeaders->TabIndex = 29;
      this->txtNoLeaders->Text = L"3";
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label2->Location = System::Drawing::Point(6, 22);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(142, 20);
      this->label2->TabIndex = 28;
      this->label2->Text = L"Maximum number";
      // 
      // groupBox2
      // 
      this->groupBox2->BackColor = System::Drawing::Color::Transparent;
      this->groupBox2->Controls->Add(this->txtModelX);
      this->groupBox2->Controls->Add(this->txtDistanceThreshold);
      this->groupBox2->Controls->Add(this->label10);
      this->groupBox2->Controls->Add(this->txtAgentDistance);
      this->groupBox2->Controls->Add(this->label9);
      this->groupBox2->Controls->Add(this->label5);
      this->groupBox2->Controls->Add(this->label6);
      this->groupBox2->Controls->Add(this->label7);
      this->groupBox2->Controls->Add(this->label8);
      this->groupBox2->Controls->Add(this->txtModelZ);
      this->groupBox2->Controls->Add(this->txtModelY);
      this->groupBox2->Controls->Add(this->label4);
      this->groupBox2->Controls->Add(this->label1);
      this->groupBox2->Controls->Add(this->txtSwarmSize);
      this->groupBox2->Location = System::Drawing::Point(12, 12);
      this->groupBox2->Name = L"groupBox2";
      this->groupBox2->Size = System::Drawing::Size(322, 220);
      this->groupBox2->TabIndex = 26;
      this->groupBox2->TabStop = false;
      this->groupBox2->Text = L"Swarm properties";
      // 
      // txtModelX
      // 
      this->txtModelX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtModelX->Location = System::Drawing::Point(167, 117);
      this->txtModelX->Name = L"txtModelX";
      this->txtModelX->Size = System::Drawing::Size(31, 27);
      this->txtModelX->TabIndex = 45;
      this->txtModelX->Text = L"200";
      // 
      // txtDistanceThreshold
      // 
      this->txtDistanceThreshold->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtDistanceThreshold->Location = System::Drawing::Point(167, 84);
      this->txtDistanceThreshold->Name = L"txtDistanceThreshold";
      this->txtDistanceThreshold->Size = System::Drawing::Size(145, 27);
      this->txtDistanceThreshold->TabIndex = 40;
      this->txtDistanceThreshold->Text = L"10";
      // 
      // label10
      // 
      this->label10->AutoSize = true;
      this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label10->Location = System::Drawing::Point(6, 87);
      this->label10->Name = L"label10";
      this->label10->Size = System::Drawing::Size(150, 20);
      this->label10->TabIndex = 39;
      this->label10->Text = L"Distance threshold";
      // 
      // txtAgentDistance
      // 
      this->txtAgentDistance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtAgentDistance->Location = System::Drawing::Point(167, 51);
      this->txtAgentDistance->Name = L"txtAgentDistance";
      this->txtAgentDistance->Size = System::Drawing::Size(145, 27);
      this->txtAgentDistance->TabIndex = 38;
      this->txtAgentDistance->Text = L"100";
      // 
      // label9
      // 
      this->label9->AutoSize = true;
      this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label9->Location = System::Drawing::Point(6, 54);
      this->label9->Name = L"label9";
      this->label9->Size = System::Drawing::Size(120, 20);
      this->label9->TabIndex = 37;
      this->label9->Text = L"Agent distance";
      // 
      // label5
      // 
      this->label5->AutoSize = true;
      this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label5->Location = System::Drawing::Point(263, 120);
      this->label5->Name = L"label5";
      this->label5->Size = System::Drawing::Size(18, 20);
      this->label5->TabIndex = 36;
      this->label5->Text = L"Z";
      // 
      // label6
      // 
      this->label6->AutoSize = true;
      this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label6->Location = System::Drawing::Point(263, 123);
      this->label6->Name = L"label6";
      this->label6->Size = System::Drawing::Size(18, 20);
      this->label6->TabIndex = 35;
      this->label6->Text = L"Z";
      // 
      // label7
      // 
      this->label7->AutoSize = true;
      this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label7->Location = System::Drawing::Point(204, 120);
      this->label7->Name = L"label7";
      this->label7->Size = System::Drawing::Size(19, 20);
      this->label7->TabIndex = 34;
      this->label7->Text = L"Y";
      // 
      // label8
      // 
      this->label8->AutoSize = true;
      this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label8->Location = System::Drawing::Point(141, 120);
      this->label8->Name = L"label8";
      this->label8->Size = System::Drawing::Size(20, 20);
      this->label8->TabIndex = 33;
      this->label8->Text = L"X";
      // 
      // txtModelZ
      // 
      this->txtModelZ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtModelZ->Location = System::Drawing::Point(281, 117);
      this->txtModelZ->Name = L"txtModelZ";
      this->txtModelZ->Size = System::Drawing::Size(31, 27);
      this->txtModelZ->TabIndex = 32;
      this->txtModelZ->Text = L"200";
      // 
      // txtModelY
      // 
      this->txtModelY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtModelY->Location = System::Drawing::Point(226, 117);
      this->txtModelY->Name = L"txtModelY";
      this->txtModelY->Size = System::Drawing::Size(31, 27);
      this->txtModelY->TabIndex = 31;
      this->txtModelY->Text = L"200";
      // 
      // label4
      // 
      this->label4->AutoSize = true;
      this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label4->Location = System::Drawing::Point(6, 123);
      this->label4->Name = L"label4";
      this->label4->Size = System::Drawing::Size(90, 20);
      this->label4->TabIndex = 29;
      this->label4->Text = L"Model size";
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label1->Location = System::Drawing::Point(6, 23);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(97, 20);
      this->label1->TabIndex = 27;
      this->label1->Text = L"Swarm size";
      // 
      // txtSwarmSize
      // 
      this->txtSwarmSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtSwarmSize->Location = System::Drawing::Point(167, 20);
      this->txtSwarmSize->Name = L"txtSwarmSize";
      this->txtSwarmSize->Size = System::Drawing::Size(145, 27);
      this->txtSwarmSize->TabIndex = 25;
      this->txtSwarmSize->Text = L"400";
      // 
      // chk3D
      // 
      this->chk3D->AutoSize = true;
      this->chk3D->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->chk3D->Location = System::Drawing::Point(76, 99);
      this->chk3D->Name = L"chk3D";
      this->chk3D->Size = System::Drawing::Size(50, 24);
      this->chk3D->TabIndex = 44;
      this->chk3D->Text = L"3D";
      this->chk3D->UseVisualStyleBackColor = true;
      // 
      // chk2D
      // 
      this->chk2D->AutoSize = true;
      this->chk2D->Checked = true;
      this->chk2D->CheckState = System::Windows::Forms::CheckState::Checked;
      this->chk2D->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->chk2D->Location = System::Drawing::Point(10, 99);
      this->chk2D->Name = L"chk2D";
      this->chk2D->Size = System::Drawing::Size(50, 24);
      this->chk2D->TabIndex = 43;
      this->chk2D->Text = L"2D";
      this->chk2D->UseVisualStyleBackColor = true;
      // 
      // groupBox3
      // 
      this->groupBox3->BackColor = System::Drawing::Color::Transparent;
      this->groupBox3->Controls->Add(this->txtOutputFile);
      this->groupBox3->Controls->Add(this->label13);
      this->groupBox3->Controls->Add(this->label20);
      this->groupBox3->Controls->Add(this->chk3D);
      this->groupBox3->Controls->Add(this->txtSimulationTime);
      this->groupBox3->Controls->Add(this->chk2D);
      this->groupBox3->Location = System::Drawing::Point(12, 238);
      this->groupBox3->Name = L"groupBox3";
      this->groupBox3->Size = System::Drawing::Size(322, 144);
      this->groupBox3->TabIndex = 46;
      this->groupBox3->TabStop = false;
      this->groupBox3->Text = L"Simulation properties";
      // 
      // txtOutputFile
      // 
      this->txtOutputFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->txtOutputFile->Location = System::Drawing::Point(167, 56);
      this->txtOutputFile->Name = L"txtOutputFile";
      this->txtOutputFile->Size = System::Drawing::Size(145, 27);
      this->txtOutputFile->TabIndex = 46;
      this->txtOutputFile->Text = L"fis1.txt";
      // 
      // label13
      // 
      this->label13->AutoSize = true;
      this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label13->Location = System::Drawing::Point(6, 59);
      this->label13->Name = L"label13";
      this->label13->Size = System::Drawing::Size(86, 20);
      this->label13->TabIndex = 45;
      this->label13->Text = L"Output file";
      // 
      // label20
      // 
      this->label20->AutoSize = true;
      this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
      this->label20->Location = System::Drawing::Point(6, 23);
      this->label20->Name = L"label20";
      this->label20->Size = System::Drawing::Size(200, 20);
      this->label20->TabIndex = 27;
      this->label20->Text = L"Simulation time (minutes)";
      // 
      // txtSimulationTime
      // 
      this->txtSimulationTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
      this->txtSimulationTime->Location = System::Drawing::Point(226, 20);
      this->txtSimulationTime->Name = L"txtSimulationTime";
      this->txtSimulationTime->Size = System::Drawing::Size(86, 27);
      this->txtSimulationTime->TabIndex = 25;
      this->txtSimulationTime->Text = L"600";
      // 
      // My3DForm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
      this->ClientSize = System::Drawing::Size(716, 392);
      this->Controls->Add(this->groupBox3);
      this->Controls->Add(this->groupBox2);
      this->Controls->Add(this->groupBox1);
      this->Controls->Add(this->btnReturn);
      this->Controls->Add(this->btnStart);
      this->Name = L"My3DForm";
      this->Text = L"Mars Explorer - Settings";
      this->groupBox1->ResumeLayout(false);
      this->groupBox1->PerformLayout();
      this->groupBox2->ResumeLayout(false);
      this->groupBox2->PerformLayout();
      this->groupBox3->ResumeLayout(false);
      this->groupBox3->PerformLayout();
      this->ResumeLayout(false);

    }
#pragma endregion
  private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

    MarsExplorer::setSwarmSize(System::Convert::ToInt32(txtSwarmSize->Text));
    MarsExplorer::setAgentDistance(System::Convert::ToSingle(txtAgentDistance->Text));
    MarsExplorer::setDistanceThreshold(System::Convert::ToSingle(txtDistanceThreshold->Text));

    MarsExplorer::setModelSize(System::Convert::ToSingle(txtModelX->Text),
      System::Convert::ToSingle(txtModelY->Text),
      System::Convert::ToSingle(txtModelZ->Text));

    MarsExplorer::setNoLeaders(System::Convert::ToInt32(txtNoLeaders->Text));
    MarsExplorer::setLeaderSpawnRate(System::Convert::ToSingle(txtLeaderSpawnRate->Text));
    MarsExplorer::setLeaderLifeTime(System::Convert::ToSingle(txtLeaderLifeSpan->Text));
    MarsExplorer::setInitialDelay(System::Convert::ToSingle(txtInitialDelay->Text));
    MarsExplorer::setSimulationTime(System::Convert::ToSingle(txtSimulationTime->Text));
    MarsExplorer::setOutputFile(txtOutputFile->Text);
    MarsExplorer::SetRepresentationType(chk3D->Checked);
    MarsExplorer::disableStart();
    MarsExplorer::Load();

  }
  private: System::Void btnReturn_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chk3D_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    if (this->chk3D->Checked) {
      this->chk2D->Checked = false;
    } 
    else
    {
      this->chk2D->Checked = true;
    }
  }
  private: System::Void chk2D_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
    if (this->chk2D->Checked) {
      this->chk3D->Checked = false;
    }
    else
    {
      this->chk3D->Checked = true;
    }
  }
};
}
