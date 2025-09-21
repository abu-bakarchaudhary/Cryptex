#pragma once
#include "RSA.h"
#include <fstream>    // For file handling
#include <string>     // For string operations
#include "RSAEncryption.h"
#include <msclr/marshal_cppstd.h>
#include "SharedData.h"

namespace DMProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RSADecryption
	/// </summary>
	public ref class RSADecryption : public System::Windows::Forms::Form
	{
	public:
		RSADecryption(void)
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
		~RSADecryption()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RSADecryption::typeid));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 194);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 16);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Message->";
			this->label5->Click += gcnew System::EventHandler(this, &RSADecryption::label5_Click);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(93, 141);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Decrypt";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RSADecryption::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(75, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"N::";
			this->label4->Click += gcnew System::EventHandler(this, &RSADecryption::label4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(75, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 16);
			this->label2->TabIndex = 11;
			this->label2->Text = L"D::";
			this->label2->Click += gcnew System::EventHandler(this, &RSADecryption::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(93, 194);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(179, 55);
			this->textBox1->TabIndex = 17;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &RSADecryption::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(113, 54);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 18;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &RSADecryption::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(113, 97);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 19;
			// 
			// RSADecryption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RSADecryption";
			this->Text = L"RSADecryption";
			this->Load += gcnew System::EventHandler(this, &RSADecryption::RSADecryption_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void maskedTextBox2_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void maskedTextBox5_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(this->textBox2->Text) || String::IsNullOrWhiteSpace(this->textBox3->Text)) {
		MessageBox::Show("Please fill all fields!");
		return;
	}

	// Retrieve values from textboxes
	int D = Int32::Parse(this->textBox2->Text);
	int N = Int32::Parse(this->textBox3->Text);

	int p = SharedData::p;
	int q = SharedData::q;

	// Read the encrypted message from the text file
	std::ifstream inputFile("RSAEncryptedMessage.txt");  // Open the file for reading
	std::string encryptedMessage;

	if (inputFile.is_open()) {
		std::getline(inputFile, encryptedMessage);  // Read the encrypted message
		inputFile.close();  // Close the file
	}
	else {
		MessageBox::Show("Failed to open the encrypted message file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (encryptedMessage.empty()) {
		MessageBox::Show("Encrypted message is empty!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	RSA obj1;
	obj1.calculation(p, q);  // Calculate the RSA keys
	obj1.encryption(SharedData::message);  // Encrypt the original message to ensure the decryption works correctly

	if (encryptedMessage == " ") {
		MessageBox::Show("There is no encrypted message...");
		return;
	}

	// Check if the entered key is correct
	if (obj1.checkkey(D, N)) {
		obj1.decryption(D, N);  // Decrypt the message using the provided keys
		this->textBox1->Text = msclr::interop::marshal_as<System::String^>(obj1.getdecryptmessage());  // Display the decrypted message
	}
	else {
		MessageBox::Show("Please enter the correct key.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
}

private: System::Void RSADecryption_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
