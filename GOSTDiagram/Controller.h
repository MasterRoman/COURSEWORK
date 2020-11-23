#pragma once
#include "PictureView.h"

#include "DataTypes.h"

#include "FigureModel.h"
#include "RectFunctions.h"

#include "RectFunc.h"
#include "AbstractFigure.h"
#include "FigureModel.h"

FunctionType curType;
EditMode curEditMode;
TDrawMode curDrawMode;
bool isChanged;
int curX, curY;
Rect selectedRect;
bool saveToBMP;



namespace GOSTDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Controller
	/// </summary>
	public ref class Controller : public System::Windows::Forms::Form
	{
	public:
		System::String^ curPath;
		List^ head;
		List^ curElement;	
		List^ curSelectedFunc;
		List^ selectedHead;
		Controller(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->curPath = System::String::Empty;
			this->head = initList(head);
			this->selectedHead = initList(selectedHead);
			this->curElement = nullptr;
			this->curSelectedFunc = nullptr;
		}
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Controller()
		{
			if (components)
			{
				delete components;
			}
			cleanList(head);
			cleanList(selectedHead);
			delete head;
			delete selectedHead;
			delete curPath;
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ FileStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ FileNewMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ FileOpenMenuItem;
	protected:

	protected:




	private: System::Windows::Forms::ToolStripMenuItem^ EditStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ FileSaveMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ FileSaveAsMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^ FileExitMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ HelpStripMenuItem;
	private: System::Windows::Forms::ImageList^ MenuImageList;



	private: System::Windows::Forms::ToolStripMenuItem^ EditUndoMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EditCopyMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ EditInsertMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStrip^ toolStripMenu;
	private: System::Windows::Forms::ToolStripButton^ toolStripNewButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripOpenButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripSaveButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripSaveAsButton;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ toolStripUndoButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripCopyButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripPasteButton;
	private: System::Windows::Forms::ToolStrip^ toolStripFunctions;
	private: System::Windows::Forms::ToolStripButton^ toolStripPointerButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripLineButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripProcessButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripDecisionButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripDataButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripTerminatorButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripPageReferenceButton;
	private: System::Windows::Forms::ToolStripButton^ toolStripTextButton;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
	private: System::Windows::Forms::Panel^ panel;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Controller::typeid));
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->FileStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileNewMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileOpenMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->FileSaveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileSaveAsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->FileExitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditUndoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditCopyMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EditInsertMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->HelpStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->toolStripMenu = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripNewButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripOpenButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSaveButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSaveAsButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripUndoButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripCopyButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripPasteButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripFunctions = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripPointerButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLineButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripProcessButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripDecisionButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripDataButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripTerminatorButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripPageReferenceButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripTextButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip->SuspendLayout();
			this->toolStripMenu->SuspendLayout();
			this->toolStripFunctions->SuspendLayout();
			this->panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(15, 15);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->FileStripMenuItem,
					this->EditStripMenuItem, this->HelpStripMenuItem
			});
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(1082, 28);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Tag = L"";
			this->menuStrip->Text = L"menuStrip";
			// 
			// FileStripMenuItem
			// 
			this->FileStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->FileNewMenuItem,
					this->FileOpenMenuItem, this->toolStripMenuItem2, this->FileSaveMenuItem, this->FileSaveAsMenuItem, this->toolStripMenuItem3,
					this->FileExitMenuItem
			});
			this->FileStripMenuItem->Name = L"FileStripMenuItem";
			this->FileStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->FileStripMenuItem->Text = L"Файл";
			// 
			// FileNewMenuItem
			// 
			this->FileNewMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FileNewMenuItem.Image")));
			this->FileNewMenuItem->Name = L"FileNewMenuItem";
			this->FileNewMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->FileNewMenuItem->Size = System::Drawing::Size(264, 26);
			this->FileNewMenuItem->Text = L"Новый";
			this->FileNewMenuItem->Click += gcnew System::EventHandler(this, &Controller::FileNewMenuItem_Click);
			// 
			// FileOpenMenuItem
			// 
			this->FileOpenMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FileOpenMenuItem.Image")));
			this->FileOpenMenuItem->Name = L"FileOpenMenuItem";
			this->FileOpenMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->FileOpenMenuItem->Size = System::Drawing::Size(264, 26);
			this->FileOpenMenuItem->Text = L"Открыть";
			this->FileOpenMenuItem->Click += gcnew System::EventHandler(this, &Controller::FileOpenMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(261, 6);
			// 
			// FileSaveMenuItem
			// 
			this->FileSaveMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FileSaveMenuItem.Image")));
			this->FileSaveMenuItem->Name = L"FileSaveMenuItem";
			this->FileSaveMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->FileSaveMenuItem->Size = System::Drawing::Size(264, 26);
			this->FileSaveMenuItem->Text = L"Сохранить";
			this->FileSaveMenuItem->Click += gcnew System::EventHandler(this, &Controller::FileSaveMenuItem_Click);
			// 
			// FileSaveAsMenuItem
			// 
			this->FileSaveAsMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FileSaveAsMenuItem.Image")));
			this->FileSaveAsMenuItem->Name = L"FileSaveAsMenuItem";
			this->FileSaveAsMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::F12));
			this->FileSaveAsMenuItem->Size = System::Drawing::Size(264, 26);
			this->FileSaveAsMenuItem->Text = L"Сохранить как";
			this->FileSaveAsMenuItem->Click += gcnew System::EventHandler(this, &Controller::FileSaveAsMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(261, 6);
			// 
			// FileExitMenuItem
			// 
			this->FileExitMenuItem->Name = L"FileExitMenuItem";
			this->FileExitMenuItem->Size = System::Drawing::Size(264, 26);
			this->FileExitMenuItem->Text = L"Выйти";
			this->FileExitMenuItem->Click += gcnew System::EventHandler(this, &Controller::FileExitMenuItem_Click);
			// 
			// EditStripMenuItem
			// 
			this->EditStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->EditUndoMenuItem,
					this->EditCopyMenuItem, this->EditInsertMenuItem
			});
			this->EditStripMenuItem->Name = L"EditStripMenuItem";
			this->EditStripMenuItem->Size = System::Drawing::Size(137, 24);
			this->EditStripMenuItem->Text = L"Редактирование";
			// 
			// EditUndoMenuItem
			// 
			this->EditUndoMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditUndoMenuItem.Image")));
			this->EditUndoMenuItem->Name = L"EditUndoMenuItem";
			this->EditUndoMenuItem->Size = System::Drawing::Size(176, 26);
			this->EditUndoMenuItem->Text = L"Отменить";
			// 
			// EditCopyMenuItem
			// 
			this->EditCopyMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditCopyMenuItem.Image")));
			this->EditCopyMenuItem->Name = L"EditCopyMenuItem";
			this->EditCopyMenuItem->Size = System::Drawing::Size(176, 26);
			this->EditCopyMenuItem->Text = L"Копировать";
			// 
			// EditInsertMenuItem
			// 
			this->EditInsertMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditInsertMenuItem.Image")));
			this->EditInsertMenuItem->Name = L"EditInsertMenuItem";
			this->EditInsertMenuItem->Size = System::Drawing::Size(176, 26);
			this->EditInsertMenuItem->Text = L"Вставить";
			// 
			// HelpStripMenuItem
			// 
			this->HelpStripMenuItem->Name = L"HelpStripMenuItem";
			this->HelpStripMenuItem->Size = System::Drawing::Size(83, 24);
			this->HelpStripMenuItem->Text = L"Помощь";
			// 
			// MenuImageList
			// 
			this->MenuImageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"MenuImageList.ImageStream")));
			this->MenuImageList->TransparentColor = System::Drawing::Color::Transparent;
			this->MenuImageList->Images->SetKeyName(0, L"New.ico");
			this->MenuImageList->Images->SetKeyName(1, L"Open.ico");
			this->MenuImageList->Images->SetKeyName(2, L"Save.ico");
			this->MenuImageList->Images->SetKeyName(3, L"SaveAs.ico");
			this->MenuImageList->Images->SetKeyName(4, L"UndoBlue.ico");
			this->MenuImageList->Images->SetKeyName(5, L"Copy.ico");
			this->MenuImageList->Images->SetKeyName(6, L"Paste.ico");
			this->MenuImageList->Images->SetKeyName(7, L"ZoomIn.ico");
			this->MenuImageList->Images->SetKeyName(8, L"ZoomOut.ico");
			this->MenuImageList->Images->SetKeyName(9, L"CutBlue.ico");
			this->MenuImageList->Images->SetKeyName(10, L"CutRed.ico");
			this->MenuImageList->Images->SetKeyName(11, L"RedoBlue.ico");
			this->MenuImageList->Images->SetKeyName(12, L"RedoGreen.ico");
			this->MenuImageList->Images->SetKeyName(13, L"RedoRed.ico");
			this->MenuImageList->Images->SetKeyName(14, L"UndoGreen.ico");
			this->MenuImageList->Images->SetKeyName(15, L"UndoRed.ico");
			// 
			// toolStripMenu
			// 
			this->toolStripMenu->BackColor = System::Drawing::SystemColors::Control;
			this->toolStripMenu->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toolStripMenu->ImageScalingSize = System::Drawing::Size(15, 15);
			this->toolStripMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripNewButton,
					this->toolStripOpenButton, this->toolStripSaveButton, this->toolStripSaveAsButton, this->toolStripSeparator1, this->toolStripUndoButton,
					this->toolStripCopyButton, this->toolStripPasteButton
			});
			this->toolStripMenu->Location = System::Drawing::Point(0, 28);
			this->toolStripMenu->Name = L"toolStripMenu";
			this->toolStripMenu->Padding = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->toolStripMenu->Size = System::Drawing::Size(1082, 25);
			this->toolStripMenu->TabIndex = 1;
			this->toolStripMenu->Text = L"toolStripMenu";
			// 
			// toolStripNewButton
			// 
			this->toolStripNewButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripNewButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripNewButton.Image")));
			this->toolStripNewButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripNewButton->Name = L"toolStripNewButton";
			this->toolStripNewButton->Size = System::Drawing::Size(29, 22);
			this->toolStripNewButton->Click += gcnew System::EventHandler(this, &Controller::toolStripNewButton_Click);
			// 
			// toolStripOpenButton
			// 
			this->toolStripOpenButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripOpenButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripOpenButton.Image")));
			this->toolStripOpenButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripOpenButton->Name = L"toolStripOpenButton";
			this->toolStripOpenButton->Size = System::Drawing::Size(29, 22);
			this->toolStripOpenButton->Click += gcnew System::EventHandler(this, &Controller::toolStripOpenButton_Click);
			// 
			// toolStripSaveButton
			// 
			this->toolStripSaveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSaveButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSaveButton.Image")));
			this->toolStripSaveButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSaveButton->Name = L"toolStripSaveButton";
			this->toolStripSaveButton->Size = System::Drawing::Size(29, 22);
			this->toolStripSaveButton->Click += gcnew System::EventHandler(this, &Controller::toolStripSaveButton_Click);
			// 
			// toolStripSaveAsButton
			// 
			this->toolStripSaveAsButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSaveAsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSaveAsButton.Image")));
			this->toolStripSaveAsButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSaveAsButton->Name = L"toolStripSaveAsButton";
			this->toolStripSaveAsButton->Size = System::Drawing::Size(29, 22);
			this->toolStripSaveAsButton->Click += gcnew System::EventHandler(this, &Controller::toolStripSaveAsButton_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// toolStripUndoButton
			// 
			this->toolStripUndoButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripUndoButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripUndoButton.Image")));
			this->toolStripUndoButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripUndoButton->Name = L"toolStripUndoButton";
			this->toolStripUndoButton->Size = System::Drawing::Size(29, 22);
			// 
			// toolStripCopyButton
			// 
			this->toolStripCopyButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripCopyButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripCopyButton.Image")));
			this->toolStripCopyButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripCopyButton->Name = L"toolStripCopyButton";
			this->toolStripCopyButton->Size = System::Drawing::Size(29, 22);
			// 
			// toolStripPasteButton
			// 
			this->toolStripPasteButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripPasteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripPasteButton.Image")));
			this->toolStripPasteButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripPasteButton->Name = L"toolStripPasteButton";
			this->toolStripPasteButton->Size = System::Drawing::Size(29, 22);
			// 
			// toolStripFunctions
			// 
			this->toolStripFunctions->Dock = System::Windows::Forms::DockStyle::Left;
			this->toolStripFunctions->GripMargin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->toolStripFunctions->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStripFunctions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->toolStripPointerButton,
					this->toolStripSeparator2, this->toolStripLineButton, this->toolStripSeparator3, this->toolStripProcessButton, this->toolStripDecisionButton,
					this->toolStripDataButton, this->toolStripTerminatorButton, this->toolStripPageReferenceButton, this->toolStripSeparator4, this->toolStripTextButton,
					this->toolStripSeparator5
			});
			this->toolStripFunctions->Location = System::Drawing::Point(0, 53);
			this->toolStripFunctions->Name = L"toolStripFunctions";
			this->toolStripFunctions->Padding = System::Windows::Forms::Padding(0, 1, 0, 1);
			this->toolStripFunctions->Size = System::Drawing::Size(29, 500);
			this->toolStripFunctions->TabIndex = 2;
			this->toolStripFunctions->Text = L"toolStrip";
			this->toolStripFunctions->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Controller::toolStripFunctions_ItemClicked);
			// 
			// toolStripPointerButton
			// 
			this->toolStripPointerButton->CheckOnClick = true;
			this->toolStripPointerButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripPointerButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripPointerButton.Image")));
			this->toolStripPointerButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripPointerButton->Name = L"toolStripPointerButton";
			this->toolStripPointerButton->Size = System::Drawing::Size(28, 24);
			this->toolStripPointerButton->Tag = L"0";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(28, 6);
			this->toolStripSeparator2->Tag = L"notFigure";
			// 
			// toolStripLineButton
			// 
			this->toolStripLineButton->CheckOnClick = true;
			this->toolStripLineButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripLineButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripLineButton.Image")));
			this->toolStripLineButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripLineButton->Name = L"toolStripLineButton";
			this->toolStripLineButton->Size = System::Drawing::Size(28, 24);
			this->toolStripLineButton->Tag = L"1";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(28, 6);
			this->toolStripSeparator3->Tag = L"notFigure";
			// 
			// toolStripProcessButton
			// 
			this->toolStripProcessButton->CheckOnClick = true;
			this->toolStripProcessButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripProcessButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripProcessButton.Image")));
			this->toolStripProcessButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripProcessButton->Name = L"toolStripProcessButton";
			this->toolStripProcessButton->Size = System::Drawing::Size(28, 24);
			this->toolStripProcessButton->Tag = L"2";
			// 
			// toolStripDecisionButton
			// 
			this->toolStripDecisionButton->CheckOnClick = true;
			this->toolStripDecisionButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDecisionButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDecisionButton.Image")));
			this->toolStripDecisionButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDecisionButton->Name = L"toolStripDecisionButton";
			this->toolStripDecisionButton->Size = System::Drawing::Size(28, 24);
			this->toolStripDecisionButton->Tag = L"3";
			// 
			// toolStripDataButton
			// 
			this->toolStripDataButton->CheckOnClick = true;
			this->toolStripDataButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDataButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDataButton.Image")));
			this->toolStripDataButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDataButton->Name = L"toolStripDataButton";
			this->toolStripDataButton->Size = System::Drawing::Size(28, 24);
			this->toolStripDataButton->Tag = L"4";
			// 
			// toolStripTerminatorButton
			// 
			this->toolStripTerminatorButton->CheckOnClick = true;
			this->toolStripTerminatorButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripTerminatorButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripTerminatorButton.Image")));
			this->toolStripTerminatorButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripTerminatorButton->Name = L"toolStripTerminatorButton";
			this->toolStripTerminatorButton->Size = System::Drawing::Size(28, 24);
			this->toolStripTerminatorButton->Tag = L"5";
			// 
			// toolStripPageReferenceButton
			// 
			this->toolStripPageReferenceButton->CheckOnClick = true;
			this->toolStripPageReferenceButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripPageReferenceButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripPageReferenceButton.Image")));
			this->toolStripPageReferenceButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripPageReferenceButton->Name = L"toolStripPageReferenceButton";
			this->toolStripPageReferenceButton->Size = System::Drawing::Size(28, 24);
			this->toolStripPageReferenceButton->Tag = L"6";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(28, 6);
			this->toolStripSeparator4->Tag = L"notFigure";
			// 
			// toolStripTextButton
			// 
			this->toolStripTextButton->CheckOnClick = true;
			this->toolStripTextButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripTextButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripTextButton.Image")));
			this->toolStripTextButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripTextButton->Name = L"toolStripTextButton";
			this->toolStripTextButton->Size = System::Drawing::Size(28, 24);
			this->toolStripTextButton->Tag = L"7";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(28, 6);
			this->toolStripSeparator5->Tag = L"notFigure";
			// 
			// panel
			// 
			this->panel->AutoScroll = true;
			this->panel->Controls->Add(this->pictureBox);
			this->panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel->Location = System::Drawing::Point(29, 53);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(1053, 500);
			this->panel->TabIndex = 3;
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(0, 0);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(1053, 500);
			this->pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Controller::pictureBox_Paint);
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Controller::pictureBox_MouseDown);
			this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Controller::pictureBox_MouseMove);
			this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Controller::pictureBox_MouseUp);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"Все файлы|*.*|BMP|*.bmp|Специальный формат|*.rks";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->Filter = L"Все файлы|*.*|BMP|*.bmp|Специальный формат|*.rks";
			// 
			// Controller
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1082, 553);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->toolStripFunctions);
			this->Controls->Add(this->toolStripMenu);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"Controller";
			this->Text = L"Controller";
			this->Load += gcnew System::EventHandler(this, &Controller::Controller_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Controller::Controller_KeyDown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->toolStripMenu->ResumeLayout(false);
			this->toolStripMenu->PerformLayout();
			this->toolStripFunctions->ResumeLayout(false);
			this->toolStripFunctions->PerformLayout();
			this->panel->ResumeLayout(false);
			this->panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

void saveBMP(System::String^ path) {
	saveToBMP = true;
	curSelectedFunc = nullptr;

	pictureBox->Invalidate();
	
	

	Bitmap^ bmp = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	pictureBox->DrawToBitmap(bmp, pictureBox->ClientRectangle);
	bmp->Save(path, System::Drawing::Imaging::ImageFormat::Bmp);
	
	delete bmp;

	saveToBMP = false;
}

System::String^ openNFile() {
	openFileDialog->ShowDialog();
	return openFileDialog->FileName;
}

System::String^ saveNFile() {
	saveFileDialog->ShowDialog();
	return saveFileDialog->FileName;

}

bool saveNewFile() {
	System::String^ path = saveNFile();
	int pos = path->IndexOf(".");
	System::String^ ext = path->Substring(pos + 1);
		if ((path->Length != 0) && (ext!="bmp")){

			curPath = path;
			return true;
		}
		else if (path->Length != 0) {
			saveBMP(path);
			curPath = path;
			return true;
	}
		return false;

}


void actNew() {
	System::Windows::Forms::DialogResult res = MessageBox::Show("Все несохраненные данные будут удалены.Продолжить?", "Создание нового файла", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (res == System::Windows::Forms::DialogResult::Yes) {
		isChanged = false;
		curSelectedFunc = nullptr;
		cleanList(head);
		pictureBox->Invalidate();
	}
	
}

void actOpen() {
	if (isChanged) {
		System::Windows::Forms::DialogResult res = MessageBox::Show("Желаете сохранить файл?В противном случае все данные будут утеряны?", "Сохранение", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);
		if (res == System::Windows::Forms::DialogResult::Yes) {
			if (!saveNewFile())
				return;
			
		}
		else if (res == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}

	}

	System::String^ str = openNFile();
	if ((str->Length != 0) && (str->ToString() != "openFileDialog")) {
		//open file 
		curPath = str;
		isChanged = false;
		pictureBox->Invalidate();
	} 

}

void actSaveAs() {
	saveNewFile();
}

void actSave() {
	int pos = curPath->IndexOf(".");
	System::String^ ext = curPath->Substring(pos + 1);
	if ((curPath->Length != 0) && (ext!="bmp")) {
		//save to spec file
	}
	else if (curPath->Length != 0) {
		//save bmp
		saveBMP(curPath);
	}
	else
	{
		saveNewFile();
	}

}

// additional methods

void changeButtonState(FunctionType type) {
			switch (type)
			{
			case POINTER: {
				toolStripPointerButton->Checked = false;
				break;
			}
			case LINE: {
				toolStripLineButton->Checked = false;
				break;
			}
			case PROCESS: {
				toolStripProcessButton->Checked = false;
				break;
			}
			case DECISSION: {
				toolStripDecisionButton->Checked = false;
				break;
			}
			case DATA: {
				toolStripDataButton->Checked = false;
				break;
			}
			case TERMINATOR: {
				toolStripTerminatorButton->Checked = false;
				break;
			}
			case PAGEREFERENCE: {
				toolStripPageReferenceButton->Checked = false;
				break;
			}
			case TEXT: {
				toolStripTextButton->Checked = false;
				break;
			}
			}


}

void stopDrawLine() {
	curDrawMode = NOT_DRAW;
	pictureBox->Invalidate();

}


private: System::Void Controller_Load(System::Object^ sender, System::EventArgs^ e) {
	curType = POINTER;
	toolStripPointerButton->Checked = true;
	isChanged = false;
	curEditMode = NOT_EDIT;
	curDrawMode = NOT_DRAW;
	selectedRect.top = -1;
	saveToBMP = false;
	curSelectedFunc = nullptr;
	
}
private: System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	cleanScreen(e, pictureBox->Width, pictureBox->Height);
	if (!saveToBMP)
		drawFunctions(e, head, true);
	else
		drawFunctions(e, head, false);

	if ((curDrawMode == DRAW_LINE) && (curType == LINE)) {
		drawPath(e,(LineFunc^)curElement->fig, Point(curX, curY));
	}

	if ((curType == POINTER) && (curEditMode == NOT_EDIT) && (selectedRect.top != -1)) {
		drawSelectedRect(e, selectedRect);
	}
	
	if ((curSelectedFunc != nullptr) || (selectedHead->next != nullptr)) {
		if (selectedHead->next != nullptr) {
			List^ cur = selectedHead->next;
			while (cur!=nullptr)
			{
				repaintSelectedFunc(e, cur);
				cur = cur->next;

			}
		}
		else if (curSelectedFunc != nullptr)
		repaintSelectedFunc(e, curSelectedFunc);
	}



	

}

private: System::Void toolStripFunctions_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	if (curType == LINE) {
		stopDrawLine();
	}
	if (e->ClickedItem->Tag->ToString()!="notFigure")
		changeButtonState(curType);
	if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(POINTER)){
		curType = POINTER;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(LINE)) {
		curType = LINE;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(PROCESS)) {
		curType = PROCESS;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(DECISSION)) {
		curType = DECISSION;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(DATA)) {
		curType = DATA;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(TERMINATOR)) {
		curType = TERMINATOR;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(PAGEREFERENCE)) {
		curType = PAGEREFERENCE;
	}
	else if ((e->ClickedItem->Tag->ToString()) == functionTypeToString(TEXT)) {
		curType = TEXT;
	}
	else
		return;
}


private: System::Void FileNewMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	actNew();
}
private: System::Void toolStripNewButton_Click(System::Object^ sender, System::EventArgs^ e) {
	actNew();
}
private: System::Void toolStripOpenButton_Click(System::Object^ sender, System::EventArgs^ e) {
	actOpen();
}
private: System::Void FileOpenMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	actOpen();
}
private: System::Void toolStripSaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	actSave();
}
private: System::Void FileSaveMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	actSave();
}
private: System::Void FileSaveAsMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	actSaveAs();
}
private: System::Void toolStripSaveAsButton_Click(System::Object^ sender, System::EventArgs^ e) {
	actSaveAs();
}
private: System::Void FileExitMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isChanged) {
		System::Windows::Forms::DialogResult res = MessageBox::Show("Желаете сохранить файл?В противном случае все данные будут утеряны?", "Сохранение", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);
		if (res == System::Windows::Forms::DialogResult::Yes) {
			if (!saveNewFile())
				return;

		}
		else if (res == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}

	}
	this->Close();

}


//PaintBox click events

private: System::Void pictureBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	if (curType != POINTER) {
		cleanList(selectedHead);
	}

	if ((curType == POINTER) && (curEditMode == NOT_EDIT)) {
		cleanList(selectedHead);
		selectedRect.left  = e->X;
		selectedRect.right  = e->X;
		selectedRect.top = e->Y;
		selectedRect.bottom = e->Y;
	}

	if (curDrawMode == DRAW_LINE) {
		isChanged = true;

		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			addPoints((LineFunc^)curElement->fig, Point(e->X, e->Y));
			return;
		} 
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			stopDrawLine();
			return;
		}
		
	}
	else
		curDrawMode = DRAW;

	if (curType != POINTER) {
		isChanged = true;
		if (curType != LINE) {
			
			curElement = push(head, curType,Point(e->X,e->Y));
		}
		else if (curDrawMode != DRAW_LINE)
		{
			curElement = addLine(head, Point(e->X, e->Y));
			curDrawMode = DRAW_LINE;
		}
	}

	if (curType == POINTER) {
		curSelectedFunc = hitTest(head, Point(e->X, e->Y));
	}

}
private: System::Void pictureBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	if ((curType == POINTER) && (curEditMode == NOT_EDIT) && (selectedRect.top!=-1)) {

		selectedRect.right = e->X;
		selectedRect.bottom = e->Y;
		pictureBox->Invalidate();
		return;
	}

	if ((curDrawMode == DRAW_LINE) && (curType == LINE)) {
		pictureBox->Invalidate();
		curX = e->X;
		curY = e->Y;
	}

	if ((curType == POINTER) && (curDrawMode == NOT_DRAW)) {
		if ((curSelectedFunc != nullptr) || (selectedHead->next != nullptr)) {
			// if we have selected func we will show it
			pictureBox->Invalidate();
		}
	}

	if (curType != POINTER) 
		cleanList(selectedHead);
}
private: System::Void pictureBox_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if ((curType == POINTER) && (curEditMode == NOT_EDIT)) {
		cleanList(selectedHead);
		getSelectedFuncFromRect(head, selectedHead, selectedRect);
		selectedRect.top = -1;
	}
	if (curDrawMode != DRAW_LINE) {
		curDrawMode = NOT_DRAW;
	}
	pictureBox->Invalidate();
}



private: System::Void Controller_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (curSelectedFunc != nullptr) {
		pushExistingFunc(selectedHead, curSelectedFunc->fig);
	}
	if (e->KeyCode == System::Windows::Forms::Keys::Delete) {
		List^ cur = selectedHead->next;
		while (cur!=nullptr)
		{

			deleteElement(head, cur);
			cur = cur->next;
			
		}

		cleanList(selectedHead);
		curSelectedFunc = nullptr;
		pictureBox->Invalidate();
	}
}
};



}






