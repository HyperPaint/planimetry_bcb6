//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Screen;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *AppClose;
	TLabel *MenuLabel;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TImage *PaintArea;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *InfoLabel;
	TLabel *ErrorLabel;
	void __fastcall AppCloseClick(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N12Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
