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
if(Komanda=="eaw "+NeListBox->Items->Strings[0])
if(int buf=Buffer.Pos("<"))
 {
        Komanda="NOVBETI";
        eaw="OK";
        //Memodc->Clear();
     goto KOM;
}

if(Komanda=="rlstp:cell=all;")
if(int buf=Buffer.Pos("<"))
 {
   int cellfind=0;
 for (int I = 0; I < BufMemo->Lines->Count; I++)
  {
       if(int o=BufMemo->Lines->Strings[I].Pos("CELL      STATE"))
       cellfind=o;

       if(Trim(BufMemo->Lines->Strings[I].SubString(cellfind,6))!="" && Trim(BufMemo->Lines->Strings[I].SubString(cellfind,6)).Length()==6 && cellfind!=0){
                String cellstate="";

                if(Trim(BufMemo->Lines->Strings[I].SubString(cellfind+10,6))=="ACTIVE")
                cellstate="9";
                else
                cellstate="2";

       CellsListBox->Items->Add(Trim(BufMemo->Lines->Strings[I].SubString(cellfind,6))+" "+cellstate);
       }

     if (int RXOTG=BufMemo->Lines->Strings[I].Pos("<"))
     if(Trim(BufMemo->Lines->Strings[I].SubString(0,80))=="<")
     {
         ProgressBar1->Visible=true;

        if(UpdateQuery->Active==true)
         UpdateQuery->Close();

         //cells_temp cedvelinin silinmesi
         UpdateQuery->SQL->Clear();
         UpdateQuery->SQL->Add("TRUNCATE TABLE cells_temp_2g");
         UpdateQuery->ExecSQL();

        //cellerin sayi listde azdirsa update-de problem var!!!
        if(CellsListBox->Count<20){
           ReportMemo->Lines->Add(NeListBox->Items->Strings[0]+"update failed(cell list)...");
           //loga fail barede qeyd
           //UpdateQuery->SQL->Clear();
           //UpdateQuery->SQL->Add("insert into logs (PROGRAM,USER,DATETIME,LOGTYPE,LOG) values('CELLS_DROP','TAHMAZ',NOW(),'FAIL UPDATE',replace('"+BufMemo->Text+"', '\'', '-'))");
           //UpdateQuery->ExecSQL();
        }

        for(int f=0;f<CellsListBox->Count;f++)
        {
         ProgressBar1->Max=CellsListBox->Count;
         ProgressBar1->Position=f;
         String status=CellsListBox->Items->Strings[f].SubString(8,1);

        //yeni datanin cells_temp cedveline girilmesi
         UpdateQuery->SQL->Clear();
         UpdateQuery->SQL->Add("insert into cells_temp_2g (cell,status) values ('"+CellsListBox->Items->Strings[f].SubString(0,6)+"',"+status+")");
         //ReportMemo->Lines->Add("insert into cells_temp_2g (cell,status) values ('"+CellsListBox->Items->Strings[f].SubString(0,6)+"',"+status+")");
         UpdateQuery->ExecSQL();
         }

        ProgressBar1->Visible=false;
        Komanda="NOVBETI";
        rlstp="OK";

     goto KOM;

     }

  }

}


if(Komanda=="allip:alcat=kesinti;")
if(int buf=Buffer.Pos("<"))
 {
 
 for (int I = 0; I < BufMemo->Lines->Count; I++)
  {
       if(int o=BufMemo->Lines->Strings[I].Pos("CELL       SCTYPE"))
       if(Trim(BufMemo->Lines->Strings[I+1].SubString(o+20,10))=="BCCH"){
       //ReportMemo->Lines->Add(Trim(BufMemo->Lines->Strings[I+1].SubString(o+20,10)));
       CellsListBox->Items->Add(Trim(BufMemo->Lines->Strings[I+1].SubString(o,6))+" 0");
       }
       
     if (int RXOTG=BufMemo->Lines->Strings[I].Pos("<"))
     if(Trim(BufMemo->Lines->Strings[I].SubString(0,80))=="<")
     {
         ProgressBar1->Visible=true;

        for(int f=0;f<CellsListBox->Count;f++)
        {
         ProgressBar1->Max=CellsListBox->Count;
         ProgressBar1->Position=f;
         String status=CellsListBox->Items->Strings[f].SubString(8,1);

        //yeni datanin cells_temp cedveline girilmesi
         UpdateQuery->SQL->Clear();
         UpdateQuery->SQL->Add("update cells_temp_2g set status="+status+" where cell='"+Trim(CellsListBox->Items->Strings[f].SubString(0,6))+"' ");
         //ReportMemo->Lines->Add("update cells_temp_2g set status="+status+" where cell='"+Trim(CellsListBox->Items->Strings[f].SubString(0,6))+"' ");
         UpdateQuery->ExecSQL();
         }

         //ReportMemo->Lines->Add("insert into cells_temp (cell,status) values ('"+CellsListBox->Items->Strings[f].SubString(0,7)+"',"+status+")");
        ProgressBar1->Visible=false;
        Komanda="NOVBETI";
        allip="OK";

     goto KOM;

     }

  }
}

if(Komanda=="exit;")
if(int buf=Buffer.Pos(">"))
{
        //yeni onair edilen cellerin cells cedveline girilmesi.
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells (cell_type,status,node,site,cell) select '2G' as cell_type, 9 as status, '"+NeListBox->Items->Strings[0]+"' as node,substring(cell,1,5) as site,cell from cells_temp_2g a where not exists(select cell from cells where cell=a.cell)");
        UpdateQuery->ExecSQL();

        //yeni dushen ve ya halt edilen lakin evvelden cedvelde halt ve ya kesinti kimi qeydiyyatinin baglanmasi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells_drop set ceasing_date_time=NOW(),duration=TIMESTAMPDIFF(MINUTE,occur_date_time,NOW()) where cell=(SELECT cells.cell FROM cells LEFT JOIN cells_temp_2g ON cells.cell=cells_temp_2g.cell where cells.status<>cells_temp_2g.status and (cells_temp_2g.status=0 or cells_temp_2g.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"') AND ceasing_date_time is null;");
        UpdateQuery->ExecSQL();

        //yeni dushen ve ya halt edilen sellerin cells_drop cedveline girilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells_drop (cell_type,occur_date_time,node, cell,location,status) SELECT cells.cell_type, NOW() as occur_date_time,cells.node, cells.cell,cells.location, cells_temp_2g.status FROM cells LEFT JOIN cells_temp_2g ON cells.cell=cells_temp_2g.cell where cells.status<>cells_temp_2g.status and (cells_temp_2g.status=0 or cells_temp_2g.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"'");
        UpdateQuery->ExecSQL();

        //qalxan sellerin cells_drop cedvelinde update edilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells_drop set ceasing_date_time=NOW(),duration=TIMESTAMPDIFF(MINUTE,occur_date_time,NOW()) where ceasing_date_time is null and cell=ANY(SELECT cells.cell FROM cells LEFT JOIN cells_temp_2g ON cells.cell=cells_temp_2g.cell where cells.status<>cells_temp_2g.status and cells_temp_2g.status=9 and cells.node='"+NeListBox->Items->Strings[0]+"')");
        UpdateQuery->ExecSQL();

        //sells ve sells_temp cedvellesinin statuslarinin beraberleshdirilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("update cells LEFT JOIN cells_temp_2g ON cells.cell=cells_temp_2g.cell set cells.status=cells_temp_2g.status where cells.status<>cells_temp_2g.status and cells.node='"+NeListBox->Items->Strings[0]+"'");
        UpdateQuery->ExecSQL();

        //kesintide olan lakin cedvelde eksini tapmayan cellerin mecburi cells_drop cedveline girilmesi
        UpdateQuery->SQL->Clear();
        UpdateQuery->SQL->Add("insert into cells_drop (cell_type,occur_date_time,node, cell,location,status,note) SELECT cells.cell_type, NOW() as occur_date_time,cells.node, cells.cell,cells.location, cells.status, 'occur time is not true' as note FROM cells LEFT JOIN cells_drop ON cells.cell=cells_drop.cell where (cells.status=0 or cells.status=2) and cells.node='"+NeListBox->Items->Strings[0]+"' and cells_drop.occur_date_time is null");
        UpdateQuery->ExecSQL();

        Komanda="NOVBETI";
        exit="OK";

     goto KOM;

}


KOM:;
//---------------------------------------------Komandalar------------------------------//

if(Giris==true && Komanda=="NOVBETI" && exit=="OK")
{
NeListBox->Items->Add(NeListBox->Items->Strings[0]);
NeListBox->Items->Delete(0);
rlstp="";
eaw="";
allip="";
exit="";
}

if(Giris==true && Komanda=="NOVBETI" && eaw!="OK" )
{
BufMemo->Clear();
Komanda="eaw "+NeListBox->Items->Strings[0];
IdTelnet1->WriteLn(Komanda);
goto son;
}

if(Giris==true && Komanda=="NOVBETI" && rlstp!="OK" )
{
BufMemo->Clear();
CellsListBox->Clear();
Komanda="rlstp:cell=all;";
IdTelnet1->WriteLn(Komanda);
goto son;
}

if(Giris==true && Komanda=="NOVBETI" && allip!="OK" )
{
BufMemo->Clear();
CellsListBox->Clear();
Komanda="allip:alcat=kesinti;";
IdTelnet1->WriteLn(Komanda);
goto son;
}

if(Giris==true && Komanda=="NOVBETI" && exit!="OK" )
{
BufMemo->Clear();
Komanda="exit;";
IdTelnet1->WriteLn(Komanda);
goto son;
}

son:;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTelnet1Disconnected(TObject *Sender)
{
Giris=false;
eaw="";
rlstp="";
allip="";
exit="";
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
        UpdateQuery->SQL->Add("select NE from nodes where type='BSC'");
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



