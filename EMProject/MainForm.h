#pragma once

#include "InterpreterFactory.h"
#include "Interpreter.h"
#include "RegistrationArea.h"
#include "Message.h"
#include "Matrix.h"

namespace EMProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace em::intrprt;
	using em::intrprt::Message;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form {
	public:
		MainForm(void) {
			InitializeComponent();
			shortcutTable = gcnew Dictionary<Keys, Shortcut^>();
			shortcutTable->Add(Keys::R, gcnew Shortcut(this, &MainForm::run));
			shortcutTable->Add(Keys::S, gcnew Shortcut(this, &MainForm::save));
			RegistrationArea::registerHere();
			this->ofInterpreter = InterpreterFactory::createInterpreter(InterpreterFactory::InterpreterType::OBJECT_FILE);
			this->rInterpreter = InterpreterFactory::createInterpreter(InterpreterFactory::InterpreterType::RUNTIME);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()	{
			if (components)	{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openCodeFileDialog;
	protected:

	protected:

	private: System::Windows::Forms::SplitContainer^  splitContainer;
	private: System::Windows::Forms::MenuStrip^  menu;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openGroupFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveGroupFileToolStripMenuItem;




	private: System::Windows::Forms::RichTextBox^  outputTextBox;

	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::SaveFileDialog^  saveCodeFileDialog;


	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem;



	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		delegate void Shortcut(Object^ sender);
		Interpreter^ rInterpreter;
		Interpreter^ ofInterpreter;
		Dictionary<Keys, Shortcut^>^ shortcutTable;

	private: System::Windows::Forms::ToolStripMenuItem^  openCodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadObjectToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^  openObjectFileDialog;
	private: System::Windows::Forms::RichTextBox^  inputTextBox;
	private: System::Windows::Forms::ToolStripMenuItem^  saveCodeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  saveOutputToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^  openSampleCodesToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  manualToolStripMenuItem;




	private: System::Windows::Forms::SaveFileDialog^  saveOutputFileDialog;
			 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->openCodeFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->outputTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->inputTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openGroupFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openCodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadObjectToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openSampleCodesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveGroupFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveOutputToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manualToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveCodeFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openObjectFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveOutputFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// openCodeFileDialog
			// 
			this->openCodeFileDialog->FileName = L"sample.txt";
			this->openCodeFileDialog->Filter = L"Text files (*.txt)|*.txt";
			this->openCodeFileDialog->RestoreDirectory = true;
			this->openCodeFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openCodeFileDialog_FileOk);
			// 
			// splitContainer
			// 
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->Location = System::Drawing::Point(0, 24);
			this->splitContainer->Name = L"splitContainer";
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->outputTextBox);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->inputTextBox);
			this->splitContainer->Size = System::Drawing::Size(654, 337);
			this->splitContainer->SplitterDistance = 317;
			this->splitContainer->TabIndex = 1;
			// 
			// outputTextBox
			// 
			this->outputTextBox->BackColor = System::Drawing::Color::White;
			this->outputTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->outputTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputTextBox->ForeColor = System::Drawing::Color::Black;
			this->outputTextBox->Location = System::Drawing::Point(0, 0);
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->ReadOnly = true;
			this->outputTextBox->Size = System::Drawing::Size(317, 337);
			this->outputTextBox->TabIndex = 1;
			this->outputTextBox->TabStop = false;
			this->outputTextBox->Text = L"";
			this->outputTextBox->WordWrap = false;
			this->outputTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::outputTextBox_KeyDown);
			// 
			// inputTextBox
			// 
			this->inputTextBox->AcceptsTab = true;
			this->inputTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->inputTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->inputTextBox->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputTextBox->ForeColor = System::Drawing::Color::White;
			this->inputTextBox->Location = System::Drawing::Point(0, 0);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(333, 337);
			this->inputTextBox->TabIndex = 0;
			this->inputTextBox->Text = L"#Write your instructions here";
			this->inputTextBox->WordWrap = false;
			this->inputTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::inputTextBox_KeyDown);
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->runToolStripMenuItem, this->manualToolStripMenuItem
			});
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(654, 24);
			this->menu->TabIndex = 2;
			this->menu->Text = L"menu";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openGroupFileToolStripMenuItem,
					this->saveGroupFileToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openGroupFileToolStripMenuItem
			// 
			this->openGroupFileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openCodeToolStripMenuItem,
					this->loadObjectToolStripMenuItem, this->openSampleCodesToolStripMenuItem
			});
			this->openGroupFileToolStripMenuItem->Name = L"openGroupFileToolStripMenuItem";
			this->openGroupFileToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openGroupFileToolStripMenuItem->Text = L"Open";
			// 
			// openCodeToolStripMenuItem
			// 
			this->openCodeToolStripMenuItem->Name = L"openCodeToolStripMenuItem";
			this->openCodeToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->openCodeToolStripMenuItem->Text = L"Open Code File...";
			this->openCodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openCodeToolStripMenuItem_Click);
			// 
			// loadObjectToolStripMenuItem
			// 
			this->loadObjectToolStripMenuItem->Name = L"loadObjectToolStripMenuItem";
			this->loadObjectToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->loadObjectToolStripMenuItem->Text = L"Load Object File...";
			this->loadObjectToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadObjectToolStripMenuItem_Click);
			// 
			// openSampleCodesToolStripMenuItem
			// 
			this->openSampleCodesToolStripMenuItem->Name = L"openSampleCodesToolStripMenuItem";
			this->openSampleCodesToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->openSampleCodesToolStripMenuItem->Text = L"Open Sample...";
			this->openSampleCodesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openSampleCodesToolStripMenuItem_Click);
			// 
			// saveGroupFileToolStripMenuItem
			// 
			this->saveGroupFileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->saveCodeToolStripMenuItem,
					this->saveAsToolStripMenuItem, this->saveOutputToolStripMenuItem1
			});
			this->saveGroupFileToolStripMenuItem->Name = L"saveGroupFileToolStripMenuItem";
			this->saveGroupFileToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->saveGroupFileToolStripMenuItem->Text = L"Save";
			// 
			// saveCodeToolStripMenuItem
			// 
			this->saveCodeToolStripMenuItem->Enabled = false;
			this->saveCodeToolStripMenuItem->Name = L"saveCodeToolStripMenuItem";
			this->saveCodeToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->saveCodeToolStripMenuItem->Text = L"Save Code...";
			this->saveCodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveCodeToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(148, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As...";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveAsToolStripMenuItem_Click);
			// 
			// saveOutputToolStripMenuItem1
			// 
			this->saveOutputToolStripMenuItem1->Name = L"saveOutputToolStripMenuItem1";
			this->saveOutputToolStripMenuItem1->Size = System::Drawing::Size(148, 22);
			this->saveOutputToolStripMenuItem1->Text = L"Save Output...";
			this->saveOutputToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::saveOutputToolStripMenuItem_Click);
			// 
			// runToolStripMenuItem
			// 
			this->runToolStripMenuItem->Name = L"runToolStripMenuItem";
			this->runToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->runToolStripMenuItem->Text = L"Run";
			this->runToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::runToolStripMenuItem_Click_1);
			// 
			// manualToolStripMenuItem
			// 
			this->manualToolStripMenuItem->Name = L"manualToolStripMenuItem";
			this->manualToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->manualToolStripMenuItem->Text = L"Manual";
			this->manualToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::manualToolStripMenuItem_Click);
			// 
			// saveCodeFileDialog
			// 
			this->saveCodeFileDialog->FileName = L"code";
			this->saveCodeFileDialog->Filter = L"txt files (*.txt)|*.txt";
			this->saveCodeFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::saveCodeFileDialog_FileOk);
			// 
			// openObjectFileDialog
			// 
			this->openObjectFileDialog->FileName = L"Object.txt";
			this->openObjectFileDialog->Filter = L"Text files (*.txt)|*.txt";
			this->openObjectFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openObjectFileDialog_FileOk);
			// 
			// saveOutputFileDialog
			// 
			this->saveOutputFileDialog->FileName = L"Output.txt";
			this->saveOutputFileDialog->Filter = L"txt files (*.txt)|*.txt";
			this->saveOutputFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::saveOutputFileDialog_FileOk);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 361);
			this->Controls->Add(this->splitContainer);
			this->Controls->Add(this->menu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu;
			this->Name = L"MainForm";
			this->Text = L"MiniMathLab Version 1.0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void openCodeFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			openCodeFile(this->openCodeFileDialog->OpenFile());
			this->saveCodeFileDialog->FileName = this->openCodeFileDialog->FileName;
		}
		
		private: System::Void openObjectFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			
			StreamReader^ reader = gcnew StreamReader(this->openObjectFileDialog->OpenFile());
			this->outputTextBox->Clear();
			this->outputTextBox->AppendText("Load object file \"" + this->openObjectFileDialog->FileName + "\"\n");
			startInterpret(ofInterpreter, reader, false);
			this->openObjectFileDialog->FileName = "Object.txt";
		}

		private: System::Void openCodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->openCodeFileDialog->ShowDialog();
		}

		private: System::Void loadObjectToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->openObjectFileDialog->ShowDialog();
		}
		private: System::Void openSampleCodesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->openCodeFileDialog->InitialDirectory = Path::Combine(Application::StartupPath, "Samples");
			this->openCodeFileDialog->ShowDialog();
		}

		private: System::Void saveCodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			writeFile(gcnew StreamWriter(this->saveCodeFileDialog->OpenFile()), gcnew StringReader(this->inputTextBox->Text));
		}

		private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->saveCodeFileDialog->ShowDialog();
		}
		
		private: System::Void saveOutputToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			this->saveOutputFileDialog->ShowDialog();
		}

		private: System::Void saveCodeFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			writeFile(gcnew StreamWriter(this->saveCodeFileDialog->OpenFile()), gcnew StringReader(this->inputTextBox->Text));
			this->saveCodeToolStripMenuItem->Enabled = true;
		}

		private: System::Void saveOutputFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			writeFile(gcnew StreamWriter(this->saveOutputFileDialog->OpenFile()), gcnew StringReader(this->outputTextBox->Text));
		}

		private: System::Void runToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
			this->run(this->inputTextBox);
		}

		private: void writeFile(StreamWriter^ writer, TextReader^ reader) {
			
			for (String^ line = reader->ReadLine(); line != nullptr; line = reader->ReadLine()) {
				writer->WriteLine(line);
			}
			writer->Flush();
			writer->Close();
			reader->Close();
		}

		private: System::Void inputTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			handleShortcutPress(sender, e);

		}
		private: System::Void outputTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			handleShortcutPress(sender, e);
		}

		private: void handleShortcutPress(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->Control && shortcutTable->ContainsKey(e->KeyCode)) {
				shortcutTable[e->KeyCode](sender);
				e->SuppressKeyPress = true;
			}

		}
		private: void startInterpret(Interpreter^ interpreter, TextReader^ reader, bool selectError) {
			Message^ result;
			int lineIndex = -1;
			int beenIntrprtedLineCount;

			for (String^ line = reader->ReadLine(); line != nullptr; line = reader->ReadLine()) {
				lineIndex++;
				if (System::String::IsNullOrWhiteSpace(line)) {
					continue;
				}

				result = interpreter->interpret(line, beenIntrprtedLineCount);

				if (result->msgState == Message::State::PASS) {
					handlePass(result);
					
				} else if (result->msgState == Message::State::ERROR) {
					handleError(result, lineIndex, beenIntrprtedLineCount, selectError);
					break;
				}


			}
			reader->Close();
			interpreter->finishInterpret();
		}
		private: void handlePass(Message^ msg) {

			if (!String::IsNullOrEmpty(msg)) {
				this->outputTextBox->SelectionColor = msg->msgColor;
				this->outputTextBox->AppendText(msg + "\n");
				this->outputTextBox->SelectionColor = Color::Black;
			}

			delete msg;
		}

		private: void handleError(Message^ msg, int lineIndex, int beenIntrprtedLineCount, bool selectError) {
			lineIndex ++;
			this->outputTextBox->SelectionColor = Color::Red;
			this->outputTextBox->AppendText("Error occurs at line " + (beenIntrprtedLineCount > 0 ? ((lineIndex - beenIntrprtedLineCount) + " ~ " + lineIndex) : Convert::ToString(lineIndex)) + ":\n\t");
			this->outputTextBox->AppendText(msg);
			this->outputTextBox->SelectionColor = Color::Black;
			lineIndex--;
			if (selectError) {
				array<String^>^ lines = this->inputTextBox->Lines;
				int start = this->inputTextBox->GetFirstCharIndexFromLine(lineIndex - beenIntrprtedLineCount);
				int length = this->inputTextBox->GetFirstCharIndexFromLine(lineIndex) + lines[lineIndex]->Length - start;
				this->inputTextBox->Select(start, length);
			}

			delete msg;
		}
	
		private: void run(Object^ sender) {
			TextReader^ reader = gcnew StringReader(this->inputTextBox->Text);
			this->outputTextBox->Clear();
			startInterpret(rInterpreter, reader, true);
		}

		private: void save(Object^ sender) {
			RichTextBox^ rtb = dynamic_cast<RichTextBox^>(sender);
			if (rtb->Equals(this->inputTextBox)) {
				if (this->saveCodeToolStripMenuItem->Enabled) {
					writeFile(gcnew StreamWriter(this->saveCodeFileDialog->FileName), gcnew StringReader(rtb->Text));
				} else {
					this->saveCodeFileDialog->ShowDialog();
				}
			} else if (rtb->Equals(this->outputTextBox)) {
				this->saveOutputFileDialog->ShowDialog();
			}
		}
		private: System::Void manualToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			try {
				System::Diagnostics::Process::Start(Path::Combine(Application::StartupPath, "MiniMathLab Manual.pdf"));
			} catch (Win32Exception^ e) {
				this->outputTextBox->Clear();
				this->outputTextBox->AppendText("Cannot find the manual file, please don't move the manual to other place");
			}
		}
		
		private: void openCodeFile(Stream^ stream) {
			StreamReader^ reader = gcnew StreamReader(stream);

			this->inputTextBox->Clear();
			this->outputTextBox->Clear();

			for (; !reader->EndOfStream;) {
				this->inputTextBox->AppendText(reader->ReadLine() + "\n");
			}

			reader->Close();
			this->saveCodeToolStripMenuItem->Enabled = true;
			this->outputTextBox->AppendText("Click \"Run\" or \"Ctrl + R\" to execute the instructions.");
		}







};

		
}
