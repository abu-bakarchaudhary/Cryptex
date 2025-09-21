#pragma once
#include "CaeserCipher.h"
#include "SharedData.h"
#include <msclr/marshal_cppstd.h>
#include <fstream>  // For file handling
#include <string>   // For string operations
namespace DMProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CaserDecryption
	/// </summary>
	public ref class CaserDecryption : public System::Windows::Forms::Form
	{
	public:
		CaserDecryption(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CaserDecryption()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	protected:
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CaserDecryption::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(2, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 16);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Message->";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(83, 176);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(223, 117);
			this->textBox4->TabIndex = 14;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &CaserDecryption::textBox4_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(48, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 16);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Shift (b)::";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(34, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Multiplier (a)::";
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(135, 130);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Decrypt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CaserDecryption::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(135, 47);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(90, 20);
			this->textBox3->TabIndex = 10;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &CaserDecryption::textBox3_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(135, 84);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(90, 20);
			this->textBox2->TabIndex = 9;
			// 
			// CaserDecryption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 301);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CaserDecryption";
			this->Text = L"CaserDecryption";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(this->textBox2->Text) || String::IsNullOrWhiteSpace(this->textBox3->Text)) {
		MessageBox::Show("Please fill all fields!");
		return;
	}

	// Read the encrypted message from the file
	std::ifstream inputFile("CaeserEncryptMessage.txt");  // Open the file for reading

	std::string encryptedMessage;
	if (inputFile.is_open()) {
		std::getline(inputFile, encryptedMessage);  // Read the encrypted message from the file
		inputFile.close();  // Close the file after reading
	}
	else {
		MessageBox::Show("Failed to read the encrypted message from the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (encryptedMessage.empty()) {
		MessageBox::Show("The encrypted File is empty.");
		return;
	}

	// Encrypt the message using the shared data
	CasarCipher obj1;
	obj1.encryption(SharedData::text, SharedData::a, SharedData::b);
	std::string textq = obj1.getEncryptedMessage();
	if (textq == " ") {
		MessageBox::Show("There is no Encrypt Message....");
	}

	// Read the key values from the TextBox controls
	int b = Int32::Parse(this->textBox2->Text);
	int a = Int32::Parse(this->textBox3->Text);
	if ((a % 2) == 0) {
		MessageBox::Show("Decryption failed: No modular inverse for 'a' exists.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Check if the keys are valid and decrypt the message
	if (obj1.checkkey(a, b)) {
		obj1.decryption(a, b);

		// Display the decrypted message
		this->textBox4->Text = msclr::interop::marshal_as<System::String^>(obj1.getDecryptMessage());
	}
	else {
		MessageBox::Show("Please Enter the correct key");
		return;
	}
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
