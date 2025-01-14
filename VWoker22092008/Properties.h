//---------------------------------------------------------------------------

#ifndef PropertiesH
#define PropertiesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TPropertiesForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TEdit *UserEdit;
        TMaskEdit *PasswordEdit;
        TEdit *IpEdit;
        TEdit *PortEdit;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
private:	// User declarations
public:		// User declarations
        __fastcall TPropertiesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPropertiesForm *PropertiesForm;
//---------------------------------------------------------------------------
#endif
