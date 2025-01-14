//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IdTelnet1DataAvailable(AnsiString Buffer)
{

BufMemo->Text=BufMemo->Text+Buffer;
BufMemo->SelStart = BufMemo->GetTextLen();
BufMemo->Perform(EM_SCROLLCARET, 0, 0);
//Memodc->Lines->Add(Buffer);

//------------------------avtomatik Girisqon---------------------//
if(Giris!=true){

    if (int PosReturn =Buffer.Pos("login:"))
    IdTelnet1->WriteLn(UserEdit->Text);

    if (int PosReturn = Buffer.Pos("Password:"))
    IdTelnet1->WriteLn(PassMaskEdit->Text);

    if (int PosReturn = Buffer.Pos(">"))
    {
    BufMemo->Clear();
    Giris=true;
    Komanda="NOVBETI";
    }
 }

//--------------------------------------------cavablar---------------------------//
if(Komanda=="amos "+NeListBox->Items->Strings[0]+" 'lt ^utrancell;strt'")
if(int buf=Buffer.Pos("0;"))
 {

 int cnames=0;
 for (int I = 0; I < BufMemo->Lines->Count; I++)
  {
     if(int o=BufMemo->Lines->Strings[I].Pos("CELLNAMES"))
     cnames=o;

     if(int k=BufMemo->Lines->Strings[I].Pos("IUB_"))
     {
        String cell=Trim(BufMemo->Lines->Strings[I].SubString(cnames,6));
        String sectors=Trim(BufMemo->Lines->Strings[I].SubString(cnames+7,13));

        String sec=Delimiter(sectors,"/",1);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+20,1)));

        sec=Delimiter(sectors,"/",2);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+29,1)));

        sec=Delimiter(sectors,"/",3);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+38,1)));

        sec=Delimiter(sectors,"/",4);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+47,1)));

        sec=Delimiter(sectors,"/",5);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+56,1)));

        sec=Delimiter(sectors,"/",6);
        if(sec!="Not Found")
        CellsListBox->Items->Add(cell+sec+" "+Trim(BufMemo->Lines->Strings[I].SubString(cnames+65,1)));
     }

     if (int RXOTG=BufMemo->Lines->Strings[I].Pos("0;"))
     {

        //ReportMemo->Lines->Add(NeListBox->Items->Strings[0]+" Database update...");
        ProgressBar1->Visible=true;

        if(UpdateQuery->Active==true)
         UpdateQuery->Close();

         //cells_temp cedvelinin silinmesi
         UpdateQuery->SQL->Clear();
         UpdateQuery->SQL->Add("TRUNCATE TABLE cells_temp");
         UpdateQuery->ExecSQL();

        //cellerin sayi listde azdirsa update-de problem var!!!
        if(CellsListBox->Count<20){
           ReportMemo->Lines->Add(NeListBox->Items->Strings[0]+"update failed(cell list)... "+Now());
           //StopButton->Click();
           //loga fail barede qeyd
           //UpdateQuery->SQL->Clear();
           //UpdateQuery->SQL->Add("insert into logs (PROGRAM,USER,DATETIME,LOGTYPE,LOG) values('CELLS_DROP','TAHMAZ',NOW(),'FAIL UPDATE',replace('"+BufMemo->Text+"', '\'', '-'))");
           //UpdateQuery->ExecSQL();
        }

        for(int f=0;f<CellsListBox->Count;f++)
        {
         ProgressBar1->Max=CellsListBox->Count;
         ProgressBar1->Position=f;
         String status=CellsListBox->Items->Strings[f].SubString(9,1);
         if(status=="1")
         status="9";
         else if(status=="S")
         status="1";
         else if(status=="L")
         status="2";

         //yeni datanin cells_temp cedveline girilmesi
         UpdateQuery->SQL->Clear();
         UpdateQuery->SQL->Add("insert into cells_temp (cell,status) values ('"+CellsListBox->Items->Strings[f].SubString(0,7)+"',"+status+")");
         UpdateQuery->ExecSQL();

         //ReportMemo->Lines->Add("insert into cells_temp (cell,status) values ('"+CellsListBox->Items->Strings[f].SubString(0,7)+"',"+status+")");

        }
        //yeni onair edilen cellerin cells cedveline girilmesi.
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells (cell_type,status,node,site,cell) select '3G' as cell_type, 9 as status, '"+NeListBox->Items->Strings[0]+"' as node,substring(cell,1,6) as site,cell from cells_temp a where not exists(select cell from cells where cell=a.cell)");
        UpdateQuery->ExecSQL();

        //yeni dushen ve ya halt edilen lakin evvelden cedvelde halt ve ya kesinti kimi qeydiyyatinin baglanmasi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells_drop set ceasing_date_time=NOW(),duration=TIMESTAMPDIFF(MINUTE,occur_date_time,NOW()) where cell=(SELECT cells.cell FROM cells LEFT JOIN cells_temp ON cells.cell=cells_temp.cell where cells.status<>cells_temp.status and (cells_temp.status=0 or cells_temp.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"') AND ceasing_date_time is null");
        UpdateQuery->ExecSQL();

        //yeni dushen sellerin cells_drop cedveline girilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells_drop (cell_type,occur_date_time,node, cell,location,status) SELECT cells.cell_type, NOW() as occur_date_time,cells.node, cells.cell,cells.location, cells_temp.status FROM cells LEFT JOIN cells_temp ON cells.cell=cells_temp.cell where cells.status<>cells_temp.status and (cells_temp.status=0 or cells_temp.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"'");
        UpdateQuery->ExecSQL();

        //qalxan sellerin cells_drop cedvelinde update edilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells_drop set ceasing_date_time=NOW(),duration=TIMESTAMPDIFF(MINUTE,occur_date_time,NOW()) where ceasing_date_time is null and cell=ANY(SELECT cells.cell FROM cells LEFT JOIN cells_temp ON cells.cell=cells_temp.cell where cells.status<>cells_temp.status and cells_temp.status=9 and cells.node='"+NeListBox->Items->Strings[0]+"')");
        UpdateQuery->ExecSQL();

        //Dashinan cellerin rnc-lerinin update edilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells LEFT JOIN cells_temp ON cells.cell=cells_temp.cell set node='"+NeListBox->Items->Strings[0]+"' where cells.cell=cells_temp.cell and cells.node<>'"+NeListBox->Items->Strings[0]+"';");
        UpdateQuery->ExecSQL();

        //sells ve sells_temp cedvellesinin statuslarinin beraberleshdirilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells LEFT JOIN cells_temp ON cells.cell=cells_temp.cell set cells.status=cells_temp.status where cells.status<>cells_temp.status and cells.node='"+NeListBox->Items->Strings[0]+"'");
        UpdateQuery->ExecSQL();

        //kesintide olan lakin cedvelde eksini tapmayan cellerin mecburi cells_drop cedveline girilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells_drop (cell_type,occur_date_time,node, cell,location,status,note) SELECT cells.cell_type, NOW() as occur_date_time,cells.node, cells.cell,cells.location, cells.status, 'occur time is not true' as note FROM cells LEFT JOIN cells_drop ON cells.cell=cells_drop.cell where (cells.status=0 or cells.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"' and cells_drop.occur_date_time is null");
        UpdateQuery->ExecSQL();

        ProgressBar1->Visible=false;
        ProgressBar1->Position=0;

        Komanda="NOVBETI";
        strt="OK";
        //ReportMemo->Lines->Add(NeListBox->Items->Strings[0]+" Database update finished.");

     goto KOM;

     }

  }
}


KOM:;
//---------------------------------------------Komandalar------------------------------//

if(Giris==true && Komanda=="NOVBETI" && strt=="OK")
{
NeListBox->Items->Add(NeListBox->Items->Strings[0]);
NeListBox->Items->Delete(0);
strt="";
}

if(Giris==true && Komanda=="NOVBETI" && strt!="OK" )
{
BufMemo->Clear();
CellsListBox->Clear();
Komanda="amos "+NeListBox->Items->Strings[0]+" 'lt ^utrancell;strt'";
IdTelnet1->WriteLn(Komanda);
goto son;
}

son:;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Disconnected(TObject *Sender)
{
Giris=false;
strt="";
RXMFP="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StartButtonClick(TObject *Sender)
{

 if(UserEdit->Text=="" || PassMaskEdit->Text=="")
 ShowMessage("OSS user ve passwordunu daxil et!");
 else
 {

   if(NeListBox->Items->Count==0){
        if(UpdateQuery->Active==true)
        UpdateQuery->Close();

        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("select NE from nodes where type='RNC'");
        UpdateQuery->Open();

        while(!UpdateQuery->Eof){
        NeListBox->Items->Add(UpdateQuery->FieldByName("NE")->AsString);
        UpdateQuery->Next();
        }
   }
   
   if(NeListBox->Items->Count!=0){
        if(!IdTelnet1->Connected())
        {
        IdTelnet1->Connect();
        ReportMemo->Lines->Add("Update started...");
        StatusBar1->SimpleText="Updating..." ;
        //Animate1->Visible=true;
        FailTimer->Enabled=true;
        }
   }

 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopButtonClick(TObject *Sender)
{
        if(IdTelnet1->Connected()){
        IdTelnet1->Disconnect();
        FailTimer->Enabled=false;
        }
}

//---------------------------------------------------------------------------




void __fastcall TForm1::FailTimerTimer(TObject *Sender)
{
if(check==BufMemo->Text){
ReportMemo->Lines->Add(NeListBox->Items->Strings[0]+" Update failed(reset) "+Now());
StopButton->Click();
StartButton->Click();
}

check=BufMemo->Text;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Close1Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start1Click(TObject *Sender)
{
StartButton->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop1Click(TObject *Sender)
{
StopButton->Click();
}
//---------------------------------------------------------------------------

