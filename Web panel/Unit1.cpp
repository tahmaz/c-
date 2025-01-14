//---------------------------------------------------------------------------

#include <vcl.h>
#include <FileCtrl.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
ListBox1->Items->Add(Edit1->Text);
ComboBox2->Items->Add(Edit1->Text);
ListBox2->Items->Add(ComboBox1->Text);
ListBox3->Items->Add(Edit2->Text);

Edit1->Text="";
Edit2->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int k=ListBox1->ItemIndex;
ListBox1->Items->Delete(k);
ListBox2->Items->Delete(k);
ListBox3->Items->Delete(k);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
		Directory="";
		if (SelectDirectory("Select Directory","", Directory))
		Edit3->Text="Selected forder: " +Directory;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
if(Edit3->Text=="")
ShowMessage("Please select folder!");
else{
MkDir(Directory+"\\images");
MkDir(Directory+"\\styles");

//Memo1->Lines->SaveToFile(in);
Image1->Picture->SaveToFile(Directory+"\\images\\button_etrafli_small.gif");
Image2->Picture->SaveToFile(Directory+"\\images\\button_etrafli_small2.gif");

Memo1->Lines->SaveToFile(Directory+"\\styles\\style.css");
Memo2->Lines->SaveToFile(Directory+"\\styles\\stylem.css");


Form1->Panel1Click(Panel1);
Form1->Panel2Click(Panel2);
Form1->Panel3Click(Panel3);
Form1->Panel4Click(Panel4);
Form1->Panel5Click(Panel5);
Form1->Panel6Click(Panel6);
Form1->Panel7Click(Panel7);
Form1->Panel8Click(Panel8);
Form1->Panel9Click(Panel9);

}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1Click(TObject *Sender)
{
TempMemo->Clear();
TempMemo->Lines->Add("<%@ page import=\"java.util.Properties\" %>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("Properties pi = System.getProperties ();");
TempMemo->Lines->Add("pi.put (\"file.encoding\", \"UTF-8\"); // To add a new one ");
TempMemo->Lines->Add("System.setProperties(pi);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("String DRIVER = \"com.mysql.jdbc.Driver\";");
TempMemo->Lines->Add("String USERNAME = \"monty\";");
TempMemo->Lines->Add("String PASSWORD = \"some_pass\";");
TempMemo->Lines->Add("String STRING =\"jdbc:mysql://so-m.azercell.com/santral\";");
TempMemo->Lines->Add("%>");
TempMemo->Lines->SaveToFile(Directory+"\\Polyprint.jsp");
TempMemo->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
if(PageControl1->TabIndex>0)
PageControl1->TabIndex=PageControl1->TabIndex-1;

if(PageControl1->TabIndex==0)
Button5->Enabled=false;
else
Button6->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
if(PageControl1->PageCount>PageControl1->TabIndex+1)
PageControl1->TabIndex=PageControl1->TabIndex+1;

if(PageControl1->PageCount==PageControl1->TabIndex+1)
Button6->Enabled=false;
else
Button5->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel9Click(TObject *Sender)
{
TempMemo->Clear();
TempMemo->Lines->Add("");
TempMemo->Lines->Add("CREATE TABLE "+PrEdit->Text.LowerCase()+" (");
TempMemo->Lines->Add("     id "+IdComboBox->Text+" NOT NULL AUTO_INCREMENT,");
for(int i=0;i<ListBox1->Items->Count;i++)
  if(ListBox3->Items->Strings[i]!="")
  TempMemo->Lines->Add("     "+ListBox1->Items->Strings[i]+" "+ListBox2->Items->Strings[i]+"("+ListBox3->Items->Strings[i]+"),");
  else
  TempMemo->Lines->Add("     "+ListBox1->Items->Strings[i]+" "+ListBox2->Items->Strings[i]+",");

TempMemo->Lines->Add("     PRIMARY KEY (id)");
TempMemo->Lines->Add(");");
TempMemo->Lines->SaveToFile(Directory+"\\"+PrEdit->Text.LowerCase()+"_table.sql");
TempMemo->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
if(ComboBox1->Text=="VARCHAR")
Edit2->Enabled=true;
else
Edit2->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
ListBox4->Items->Add(ComboBox2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
 ListBox4->Items->Delete(ListBox4->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel2Click(TObject *Sender)
{
String viewfields="id";
String searchfields="";
for(int i=0;i<ListBox4->Items->Count;i++)
viewfields=viewfields+","+ListBox4->Items->Strings[i];

for(int i=0;i<ListBox6->Items->Count;i++){
  if(searchfields=="")
  searchfields=ListBox6->Items->Strings[i]+" like \'%\"+search+\"%\'";
  else
  searchfields=searchfields+ " OR "+ListBox6->Items->Strings[i]+" like \'%\"+search+\"%\'";
}

TempMemo->Clear();
TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : index");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.util.Date,java.text.*,java.io.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>");
TempMemo->Lines->Add("        <title>"+PrEdit->Text+"</title>");
TempMemo->Lines->Add("        <% ");
TempMemo->Lines->Add("String search = request.getParameter(\"search\");");
TempMemo->Lines->Add("Connection connection = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection = DriverManager.getConnection(STRING, USERNAME, PASSWORD);");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex);");
TempMemo->Lines->Add("} %>");
TempMemo->Lines->Add("    </head>");
TempMemo->Lines->Add("           ");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("        <%");
TempMemo->Lines->Add("try{");
TempMemo->Lines->Add("	if(!connection.isClosed()){");
TempMemo->Lines->Add("Statement  st = connection.createStatement();");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("String query=\"\";");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("if(search!=null){ ");
TempMemo->Lines->Add("query=\"Select "+viewfields+" from "+PrEdit->Text+" where "+searchfields+"\";}");
TempMemo->Lines->Add("else{");
TempMemo->Lines->Add("query=\"Select "+viewfields+" from "+PrEdit->Text+" \";}");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("ResultSet rs = st.executeQuery(query); ");
TempMemo->Lines->Add("ResultSetMetaData rsmd = rs.getMetaData();");
TempMemo->Lines->Add("			int numberOfColumns = rsmd.getColumnCount();");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("<form name=\"getdata\" action=\"index.jsp\" method=\"GET\" >");
TempMemo->Lines->Add("<h2 style=\"color:red;\">"+PrEdit->Text+"</h2>");


TempMemo->Lines->Add("<form action=\"index.jsp\">");
TempMemo->Lines->Add("Search:<input type=\"text\" class=\"axtar\" name=\"search\"/>");
TempMemo->Lines->Add(" <input type=\"submit\" class=\"button1\" value=\"Search\"/>");
TempMemo->Lines->Add("<a class=\"a\" href=\"addview.jsp\">Add new job</a>");
TempMemo->Lines->Add(" ");
TempMemo->Lines->Add("</form>");

TempMemo->Lines->Add("<div style=\"overflow:auto;\">");
TempMemo->Lines->Add("<table width=\"659\" border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("    <thead>");
TempMemo->Lines->Add("        <tr>");
TempMemo->Lines->Add("            <th align=\"center\">ID</th>");

for(int i=0;i<ListBox4->Items->Count;i++)
TempMemo->Lines->Add("            <th align=\"center\">"+ListBox4->Items->Strings[i]+"</th>");
TempMemo->Lines->Add("            <th align=\"center\">Update</th>");
TempMemo->Lines->Add("            <th align=\"center\">Delete</th>");
TempMemo->Lines->Add("        </tr>");
TempMemo->Lines->Add("    </thead>");
TempMemo->Lines->Add("    <tbody>");
TempMemo->Lines->Add("        <%while(rs.next()) {%>");
TempMemo->Lines->Add("        <tr>");
TempMemo->Lines->Add("");

for(int i=0;i<=ListBox4->Items->Count;i++)
TempMemo->Lines->Add("            <td><div style=\"width:50px;\"><%=rs.getString("+IntToStr(i+1)+")%></div></td>");

TempMemo->Lines->Add("            <td><a class=\"a\" href=\"updateview.jsp?id=<%=rs.getString(1)%>\">Update_this</a></td>");
TempMemo->Lines->Add("			<td><a class=\"a\" href=\"deleteview.jsp?id=<%=rs.getString(1)%>\">Delete_this</a></td>");
TempMemo->Lines->Add("        </tr>");
TempMemo->Lines->Add("        <%}%>");
TempMemo->Lines->Add("    </tbody>");
TempMemo->Lines->Add("</table>");
TempMemo->Lines->Add("</div>");
TempMemo->Lines->Add("    </form>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		<%");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		rs.close(); ");
TempMemo->Lines->Add("		st.close(); ");
TempMemo->Lines->Add("					   ");
TempMemo->Lines->Add("		connection.close();");
TempMemo->Lines->Add("		}//end of if");
TempMemo->Lines->Add("		}  //end of try");
TempMemo->Lines->Add("		catch(Exception ex){");
TempMemo->Lines->Add("		out.println(\"Unable to connect to database. \"+ex.getMessage());");
TempMemo->Lines->Add("		}");
TempMemo->Lines->Add("		%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");
TempMemo->Lines->SaveToFile(Directory+"\\index.jsp");
TempMemo->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
 ListBox6->Items->Add(ComboBox2->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
ListBox6->Items->Delete(ListBox6->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel4Click(TObject *Sender)
{
TempMemo->Clear();
TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : Addview");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");

TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.util.Date,java.text.*,java.io.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>");
TempMemo->Lines->Add("        <title>Product view</title>");
TempMemo->Lines->Add("                 </head>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("    <a class=\"a\" href=\"index.jsp\">Back to Main</a><br/>");
TempMemo->Lines->Add("    <form method=\"GET\" action=\"add.jsp\" accept-charset=\"ISO-8859-1\">");
TempMemo->Lines->Add("                <table border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("                    <tbody>");
TempMemo->Lines->Add("                    	<th></th><th></th>");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>"+ListBox1->Items->Strings[i]+"</td>");
TempMemo->Lines->Add("                            <td><input type=\"text\" name=\""+ListBox1->Items->Strings[i]+"\" size=\"100\" /></td>");
TempMemo->Lines->Add("                        </tr>");
}
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                        	  <td></td>");
TempMemo->Lines->Add("                            <td><input class=\"button1\" type=\"submit\" value=\"Add\" /></td>");
TempMemo->Lines->Add("                        </tr>");

TempMemo->Lines->Add("                    </tbody>");
TempMemo->Lines->Add("                </table>");
TempMemo->Lines->Add("               </form>");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");
TempMemo->Lines->SaveToFile(Directory+"\\addview.jsp");
TempMemo->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3Click(TObject *Sender)
{
TempMemo->Clear();

TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : Add");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.io.*,java.lang.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
TempMemo->Lines->Add("        <title>Update site</title>");
TempMemo->Lines->Add("    </head>");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("<%");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("String "+ListBox1->Items->Strings[i]+" = request.getParameter(\""+ListBox1->Items->Strings[i]+"\").trim();");
}
TempMemo->Lines->Add("String sql=\"\";");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Connection connection = DriverManager.getConnection(STRING,USERNAME, PASSWORD);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("ResultSet rs = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Statement statement = connection.createStatement();");
TempMemo->Lines->Add("");
String fields="";
String values="";
for(int i=0;i<ListBox1->Items->Count;i++){
 if(i+1==ListBox1->Items->Count){
  fields=fields+ListBox1->Items->Strings[i];
  values=values+"'\"+"+ListBox1->Items->Strings[i]+"+\"'";
 }
 else{
  fields=fields+ListBox1->Items->Strings[i]+",";
  values=values+"'\"+"+ListBox1->Items->Strings[i]+"+\"',";
 }
}
TempMemo->Lines->Add("sql = (\"insert into "+PrEdit->Text+" ("+fields+") values("+values+")\");");
TempMemo->Lines->Add("statement.executeUpdate(sql);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection.close();");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("Insert ended successfuly<br/>");
TempMemo->Lines->Add("<table border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("                    <tbody>");
TempMemo->Lines->Add("                    	<th></th><th></th>");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>"+ListBox1->Items->Strings[i]+"</td>");
TempMemo->Lines->Add("                            <td><%="+ListBox1->Items->Strings[i]+"%></td>");
TempMemo->Lines->Add("                        </tr>");
}

TempMemo->Lines->Add("                    </tbody>");
TempMemo->Lines->Add("                </table>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex+\" \"+sql);}");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("<br/><a class=\"a\" href=\"index.jsp\">Back to Main</a>");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");

TempMemo->Lines->SaveToFile(Directory+"\\add.jsp");
TempMemo->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel6Click(TObject *Sender)
{
TempMemo->Clear();


TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.io.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("	<head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>");
TempMemo->Lines->Add("        <title>Delete view</title>");
TempMemo->Lines->Add("        <%");
TempMemo->Lines->Add("String id = request.getParameter(\"id\");");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Connection connection = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection = DriverManager.getConnection(STRING, USERNAME, PASSWORD);");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex+\" \");}");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("        <%");
TempMemo->Lines->Add("try{");
TempMemo->Lines->Add("	if(!connection.isClosed()){");
TempMemo->Lines->Add("Statement  st = connection.createStatement();");
TempMemo->Lines->Add("ResultSet rs = st.executeQuery(\"Select * from "+PrEdit->Text+" where id='\"+id+\"'\");");
TempMemo->Lines->Add("ResultSetMetaData rsmd = rs.getMetaData();");
TempMemo->Lines->Add("rs.next();");
TempMemo->Lines->Add("        %>");
TempMemo->Lines->Add("                 </head>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("    <a class=\"a\" href=\"index.jsp\">Back to Main</a><br/>");
TempMemo->Lines->Add("    <form method=\"GET\" action=\"delete.jsp\" accept-charset=\"ISO-8859-1\">");
TempMemo->Lines->Add("                <table border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("                    <tbody>");
TempMemo->Lines->Add("                    	<th></th><th></th>");
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>Id</td>");
TempMemo->Lines->Add("                            <td><input type=\"text\" name=\"id\" value=\"<%=rs.getString(1)%>\" readonly=\"readonly\" style=\"border:none;background:none;\" /></td>");
TempMemo->Lines->Add("                        </tr>");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>"+ListBox1->Items->Strings[i]+"</td>");
TempMemo->Lines->Add("                            <td><%=rs.getString("+IntToStr(i+2)+")%></td>");
TempMemo->Lines->Add("                        </tr>");
}
TempMemo->Lines->Add("");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                        	<td></td>");
TempMemo->Lines->Add("                            <td><input class=\"button1\" type=\"submit\" value=\"Delete\" /></td>");
TempMemo->Lines->Add("                        </tr>");
TempMemo->Lines->Add("                    </tbody>");
TempMemo->Lines->Add("                </table>");
TempMemo->Lines->Add("               </form>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("               <%");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		rs.close();");
TempMemo->Lines->Add("		st.close();");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		connection.close();");
TempMemo->Lines->Add("                	}//end of if");
TempMemo->Lines->Add("		}  //end of try");
TempMemo->Lines->Add("		catch(Exception ex){");
TempMemo->Lines->Add("		out.println(\"Unable to connect to database. \"+ ex+\" \"+ ex.getMessage());");
TempMemo->Lines->Add("		}");
TempMemo->Lines->Add("		%>");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");

TempMemo->Lines->SaveToFile(Directory+"\\deleteview.jsp");
TempMemo->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel5Click(TObject *Sender)
{

TempMemo->Clear();

TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : Delete");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");

TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.io.*,java.lang.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("		<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
TempMemo->Lines->Add("		<title>Update site</title>");
TempMemo->Lines->Add("	</head>");
TempMemo->Lines->Add("	<body>");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("String id = request.getParameter(\"id\").trim();");
TempMemo->Lines->Add("String sql=\"\";");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Connection connection = DriverManager.getConnection(STRING,USERNAME, PASSWORD);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("ResultSet rs = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Statement statement = connection.createStatement();");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("sql =\"delete from "+PrEdit->Text+" where id='\"+id+\"'\";");
TempMemo->Lines->Add("statement.executeUpdate(sql);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection.close();");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Delete ended successfuly<br/>");
TempMemo->Lines->Add("ID=<%=id%><br/>");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex+\" \"+sql);}");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("<br/><a class=\"a\" href=\"index.jsp\">Back to Main</a>");
TempMemo->Lines->Add("	</body>");
TempMemo->Lines->Add("</html>");

TempMemo->Lines->SaveToFile(Directory+"\\delete.jsp");
TempMemo->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel8Click(TObject *Sender)
{
TempMemo->Clear();

TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : Update view");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.util.Date,java.text.*,java.io.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<html> ");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"/>");
TempMemo->Lines->Add("        <title>Product view</title>");
TempMemo->Lines->Add("        <%");
TempMemo->Lines->Add("String id = request.getParameter(\"id\").trim();");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Connection connection = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection = DriverManager.getConnection(STRING, USERNAME, PASSWORD);");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex+\" \");}");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("        <%");
TempMemo->Lines->Add("try{");
TempMemo->Lines->Add("	if(!connection.isClosed()){");
TempMemo->Lines->Add("Statement  st = connection.createStatement();");
TempMemo->Lines->Add("ResultSet rs = st.executeQuery(\"Select * from "+PrEdit->Text+" where id='\"+id+\"'\");");
TempMemo->Lines->Add("ResultSetMetaData rsmd = rs.getMetaData();");
TempMemo->Lines->Add("rs.next();");
TempMemo->Lines->Add("        %>");
TempMemo->Lines->Add("                 </head>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("    <a class=\"a\" href=\"index.jsp\">Back to Main</a><br/>");
TempMemo->Lines->Add("    <form method=\"GET\" action=\"update.jsp\" accept-charset=\"ISO-8859-1\">");
TempMemo->Lines->Add("                <table border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("                    <tbody>");
TempMemo->Lines->Add("                    	<th></th><th></th>");

TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td id=\"id\">ID</td>");
TempMemo->Lines->Add("                            <td><input type=\"text\" name=\"id\" value=\"<%=rs.getString(1)%>\" size=\"65\" readonly=\"readonly\" style=\"border:none;background:none;\" /></td>");
TempMemo->Lines->Add("                        </tr>");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>"+ListBox1->Items->Strings[i]+"</td>");
TempMemo->Lines->Add("                            <td><input type=\"text\" name=\""+ListBox1->Items->Strings[i]+"\" value=\"<%=rs.getString("+IntToStr(i+2)+")%>\" size=\"65\" /></td>");
TempMemo->Lines->Add("                        </tr>");
}
TempMemo->Lines->Add("						<tr>");
TempMemo->Lines->Add("                        	<td></td>");
TempMemo->Lines->Add("                            <td><input class=\"button1\" type=\"submit\" value=\"Update\" /></td>");
TempMemo->Lines->Add("						</tr>");
TempMemo->Lines->Add("                    </tbody>");
TempMemo->Lines->Add("                </table>");
TempMemo->Lines->Add("               </form>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("               <%");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		rs.close();");
TempMemo->Lines->Add("		st.close();");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("		connection.close();");
TempMemo->Lines->Add("                	}//end of if");
TempMemo->Lines->Add("		}  //end of try");
TempMemo->Lines->Add("		catch(Exception ex){");
TempMemo->Lines->Add("		out.println(\"Unable to connect to database. \"+ ex+\" \"+ ex.getMessage());");
TempMemo->Lines->Add("		}");
TempMemo->Lines->Add("		%>");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");

TempMemo->Lines->SaveToFile(Directory+"\\updateview.jsp");
TempMemo->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel7Click(TObject *Sender)
{
TempMemo->Clear();

TempMemo->Lines->Add("<%-- ");
TempMemo->Lines->Add("    Document   : Update");
TempMemo->Lines->Add("    Created on : "+Date());
TempMemo->Lines->Add("    Author     : Tahmaz");
TempMemo->Lines->Add("--%>");

TempMemo->Lines->Add("<%@ page contentType=\"text/html; charset=utf-8\" language=\"java\" import=\"java.sql.*,java.io.*,java.lang.*\" errorPage=\"\" %>");
TempMemo->Lines->Add("<%@ include file=\"Polyprint.jsp\" %>");
TempMemo->Lines->Add("<link href=\"styles/stylem.css\" type=\"text/css\" rel=\"stylesheet\" />");
TempMemo->Lines->Add("<!DOCTYPE html>");
TempMemo->Lines->Add("<html>");
TempMemo->Lines->Add("    <head>");
TempMemo->Lines->Add("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
TempMemo->Lines->Add("        <title>Update site</title>");
TempMemo->Lines->Add("    </head>");
TempMemo->Lines->Add("    <body>");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("String id = request.getParameter(\"id\").trim();");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("String "+ListBox1->Items->Strings[i]+" = request.getParameter(\""+ListBox1->Items->Strings[i]+"\").trim();");
}

TempMemo->Lines->Add("String sql=\"\";");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("try {");
TempMemo->Lines->Add("Class.forName(DRIVER);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Connection connection = DriverManager.getConnection(STRING,USERNAME, PASSWORD);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("ResultSet rs = null;");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("Statement statement = connection.createStatement();");
TempMemo->Lines->Add("");

String upvalue="";
for(int i=0;i<ListBox1->Items->Count;i++){
 if(i+1==ListBox1->Items->Count){
  upvalue=upvalue+ListBox1->Items->Strings[i]+"='\"+"+ListBox1->Items->Strings[i]+"+\"'";
 }
 else{
  upvalue=upvalue+ListBox1->Items->Strings[i]+"='\"+"+ListBox1->Items->Strings[i]+"+\"',";
 }
}


TempMemo->Lines->Add("sql =\"update "+PrEdit->Text+" set "+upvalue+" where id='\"+id+\"'\";");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("statement.executeUpdate(sql);");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("connection.close();");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("Update ended successfuly<br/>");
TempMemo->Lines->Add("<table border=\"1\" id=\"box-table-a\">");
TempMemo->Lines->Add("                    <tbody>");
TempMemo->Lines->Add("                    	<th></th><th></th>");
for(int i=0;i<ListBox1->Items->Count;i++){
TempMemo->Lines->Add("                        <tr>");
TempMemo->Lines->Add("                            <td>"+ListBox1->Items->Strings[i]+"</td>");
TempMemo->Lines->Add("                            <td><%="+ListBox1->Items->Strings[i]+"%></td>");
TempMemo->Lines->Add("                        </tr>");
}

TempMemo->Lines->Add("                    </tbody>");
TempMemo->Lines->Add("                </table>");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("<%");
TempMemo->Lines->Add("}");
TempMemo->Lines->Add("catch(Exception ex){");
TempMemo->Lines->Add("	out.println(\"Problem: \"+ ex+\" \"+sql);}");
TempMemo->Lines->Add("");
TempMemo->Lines->Add("%>");
TempMemo->Lines->Add("<br/><a class=\"a\" href=\"index.jsp\">Back to Main</a>");
TempMemo->Lines->Add("    </body>");
TempMemo->Lines->Add("</html>");

TempMemo->Lines->SaveToFile(Directory+"\\update.jsp");
TempMemo->Clear();
}
//---------------------------------------------------------------------------

