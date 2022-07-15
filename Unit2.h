//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TMathForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
private:	// User declarations
public:		// User declarations
	__fastcall TMathForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMathForm *MathForm;
//---------------------------------------------------------------------------
#endif
