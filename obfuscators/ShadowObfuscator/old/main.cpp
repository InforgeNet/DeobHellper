#include <windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <Windowsx.h>
#include <stdio.h>
#include <algorithm>
#include <cctype>

using namespace std;

long Count(string text ,string found) ;
void Save(string filename,string Key , string Value);
string Load(string filename,string Key , string Value);
int StringToInt(string str);
string StringBetween(string FindeString,string left,string right);
string encrypt(string text);
string decrypt(string text);
string IntToString(int i);
string ReplaceAll(string text,string fnd,string rep);
void CopyToClipboard(const char *str);
string IntToHex(unsigned char dec);
string RegRead(string path);
int InterpretFuctions(short index,int var);
void CreateFuctions(short index);
int FindVar(int index,int zahl,string& ergebniss1,string& ergebniss2);
DWORD WINAPI ThreadFunctions(LPVOID obj);
string Encrypt_Au3_Func(string text,char temp_end=14);
void Split(std::string str,std::string delimiter,std::string *splited,unsigned int max);;
string Encrypt_Au3_Func2(string text,char temp_end=14,char temp_add=6);

string NextLine;
const string keywords[32]= {"if","do","case","func","next"
                            ,"while","for","select","switch","ends","endif","endfunc","until",
                            "else","redim","dim","enum","exit","wend","return","endwith","with",
                            "const","continuecase","continueloop","exitloop","then","step","in","global","local"," local"
                           };

string created_funcs[20][11][2];

class Parser
{
public:
    Parser()
    {
        count2=0;
        added=0;
        fadded=0;
        vadded=0;
        added_endfunc=0;
        srand((unsigned)time( NULL ));
        created_enc_func="";
        ResetCode();
    }
    ~Parser() {}
    void ResetCode()
    {
        char char_ran=(rand()%25+65);
        random_func_crap[0]="BinaryLen("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[1]="BinaryMid("+CreateCrapParam(rand()%5+4)+")";
        random_func_crap[2]="BinaryToString("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[3]="BitNOT("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[4]="Chr("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[5]="$";
        random_func_crap[6]="Dim "+CreateCrapParam(rand()%8+2)+"";
        random_func_crap[7]="Else";
        random_func_crap[8]="EndIf";
        random_func_crap[9]="If";
        random_func_crap[10]="endfunc";
        random_func_crap[11]="func";
        random_func_crap[12]="_StringInsert("+CreateCrapParam(rand()%5+1)+")";
        random_func_crap[13]="_TCPIpToName("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[14]="_TimeToTicks("+CreateCrapParam(rand()%5+4)+")";
        random_func_crap[15]="_VersionCompare("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[16]="_WeekNumberISO("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[17]="$()6734893";
        random_func_crap[18]="_Radian("+CreateCrapParam(rand()%5+1)+")";
        random_func_crap[19]="_GUICtrlRichEdit_GetParaBorder("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[20]="_Net_Share_SessionGetInfo("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[21]="_NowCalc("+CreateCrapParam(rand()%5+1)+")";
        random_func_crap[22]="_ArrayFindAll("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[23]= "_ColorGetRed("+CreateCrapParam(rand()%5+3)+")";
        random_func_crap[24]="_IE_VersionInfo("+CreateCrapParam(rand()%5+2)+")";
        random_func_crap[25]="while";
        random_func_crap[26]="wend";
        random_func_crap[27]="do";
        random_func_crap[28]="until";
        random_func_crap[29]="case";
        random_func_crap[30]="switch";
        random_func_crap[31]="@MIN";
        random_func_crap[32]="@HOUR";
        random_func_crap[33]="#include<array.au3>";
        random_func_crap[34]="#include<WinAPI.au3>";

        string str2;

        for (int i=0; i<35; i++)
        {
            str2="0x";
            for (int o=0; o<random_func_crap[i].length(); o++)
            {
                if(random_func_crap[i][o]>13 || random_func_crap[i][o]<0) str2+=IntToHex(random_func_crap[i][o]);
            }
            random_func_crap[i]="Execute(BinaryToString(\""+str2+"\"))\n";
        }

        for(int a=0; a<100000; a++)
            code[a]="";

        for (int i=0; i<50; i++)
            change_var_char[i]=0;

        added_endfunc2=0;
        char_variable_replace[0]='O';
        char_variable_replace[1]='0';
        mom_alphabet=0;
        char_split=rand()%9+71;
        enc_func2_par1=rand()%10+6;
        enc_func2_par2=rand()%3;
        enc_func_opt=rand()%10+4;
        added=16;
        fadded=0;
        vadded=0;
        var_last_length=0;
        created_enc_func="_";
        for (int e=rand()%10; e<20; e++)
        {
            if (rand()%2==1)
                created_enc_func+=(char)(rand()%22+66);
            else
                created_enc_func+=(char)(rand()%22+97);
        }

        created_enc_func2="__";
        for (int e=rand()%10; e<20; e++)
        {
            if (rand()%2==1)
                created_enc_func2+=(char)(rand()%22+66);
            else
                created_enc_func2+=(char)(rand()%22+97);
        }

        array_name_used="$";
        for (int e=rand()%4; e<10; e++)
        {
            if (rand()%2==1)
                array_name_used+=char_variable_replace[0];
            else
                array_name_used+=char_variable_replace[1];
        }

        for (int e=rand()%4; e<15; e++)
        {
            if (rand()%2==1)
                array_name_used+=(char)(rand()%22+66);
            else
                array_name_used+=(char)(rand()%22+97);
        }
    }
    void AddCode(string Code)
    {
        int i2=0;
        for (int i3=0; i3<Code.length(); i3++)
        {
            if (Code[i3]<33)
            {
                i2++;
            }
            else
            {
                break;
            }
        }
        code[added]=Code.substr(i2);

        added++;
    }
    string GetCode(string file_write_to)
    {
        string str1="";
        short ran=rand()%5+5;
        if (added_endfunc2==0)
        {
            added_endfunc2=1;
            AddCode("Func "+created_enc_func2+"($text)\n");
            AddCode("Local $struct_Shadow_Obfus_Variable_Not_Overwrite_Pls2 = DllStructCreate(\"byte[\"&(StringLen($text)*2+1)&\"]\")\n");
            AddCode("DllCall(\"user32.dll\", \"ptr\", \"CallWindowProcW\", \"ptr\", DllStructGetPtr($tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls2), \"str*\", $text, \"ptr\", DllStructGetPtr($struct_Shadow_Obfus_Variable_Not_Overwrite_Pls2), \"int\", 0, \"int\", 0)\n");
            AddCode("return BinaryToString(DllStructGetData($struct_Shadow_Obfus_Variable_Not_Overwrite_Pls2, 1), 1)\n");
            AddCode("EndFunc\n");
        }


        string str="",str2="",str3="";

        code[0]="Local $tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls2 = DllStructCreate(\"byte[128]\")\n";
        code[1]="Local $struct_Shadow_Obfus_Variable_Not_Overwrite_Pls = DllStructCreate(\"byte[4096]\")\n";
        code[2]="Local $tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls = DllStructCreate(\"byte[100]\")\n";
        code[3]="DllStructSetData($tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls2, 1, String(\"0x8B5424048B128B7C240831C0B001803A007417802A0"+IntToHex((int)enc_func2_par2)+"30028B0A890F4742FEC03C0"+IntToHex((int)enc_func2_par1)+"750431C0B001EBE4C3\"))\n";
        code[4]="DllStructSetData($tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls, 1, String(\"0x8B5424048B128B7C240831C0B001803A00741780020130028B0A890F4742FEC03C0"+IntToHex((int)enc_func_opt)+"750431C0B001EBE4C60700C3\"))\n";
        code[ran]="$str=0\n";
        ran=rand()%5+5;
        code[ran]="$";
        code[ran]+=(char)(rand()%20+68);
        code[ran]+="=0\n";
        ran=rand()%5+5;
        code[ran]="$";
        code[ran]+=(char)(rand()%20+68);
        code[ran]+="=0\n";
        ran=rand()%5+5;
        code[ran]="$e=0\n";
        ran=rand()%5+5;
        code[ran]="$";
        code[ran]+=(char)(rand()%9+48);
        code[ran]+="=0\n";
        code[10]="#RequireAdmin\n";

        for (short i=0; i<rand()%25+10; i++)
        {
            str1+=(char)(rand()%20+68);
        }


        code[11]="Local $"+str1+"=Random(100,9999999)\n";
        code[12]="if Not @Compiled and FileExists(\"obfuscator_file.s92\")=0 then MsgBox(16,\"Obfuscator Datei fehlt\",\"Die erstellte 'obfuscator_file.s92' fehlt, daher kann es zu Fehlern kommen, wenn das Skript ausgeführt wird. Es wird zwingend empfohlen die fehlende Datei in dasselbe Verzeichniss wie das AutoIt-Skript zu kopieren.\")\n";
        code[13]="FileInstall(\"obfuscator_file.s92\",@TempDir&\"\\\"&$"+str1+",1)\n";
        code[14]=array_name_used+"=StringSplit("+created_enc_func2+"(FileRead(@TempDir&\"\\\"&$"+str1+")),chr(\""+IntToString(char_split)+"\"),2)\n";
        code[15]="FileDelete(@TempDir&\"\\\"&$"+str1+")\n";

        for (short a=0; a<rand()%18+7; a++)
        {
            InsertCode(random_func_crap[rand()%35],rand()%16+1);
        }

        for (int a=0; a<=added; a++)
            if (code[a].length()>=3)
                code2+=code[a];


        for (int i=0; i<sadded; i++)
        {
            str2="0x";
            for (int o=0; o<strings1[i].length(); o++)
            {
                if(strings1[i][o]>13 || strings1[i][o]<0) str2+=IntToHex(strings1[i][o]);
            }
            str3+=str2;
            str3+=char_split;
        }

        str2=Encrypt_Au3_Func2(str3,enc_func2_par1,enc_func2_par2);

        FILE *f = fopen(string(file_write_to+"obfuscator_file.s92").c_str(),"w+");
        fputs(str2.c_str(),f);
        fclose(f);
        return ReplaceAll(code2,NextLine+NextLine,"");
    }
    long CountLines();
    void RemoveUnusedLines();
    void RemoveComment();
    void ObfuscateCommands(bool activate_crypt=0);
    string GetVariable(int Number,long LineNr);
    void RemoveMultilineComments();
    void RemoveAllComments();
    void RemoveIncludes();
    void AddInclude(string str);
    void IncludeFiles();
    void GetFunctions();
    void ObfuscateStrings();
    void ObfuscateStringsEx();
    void GetVariables();
    string CreateCrapParam(unsigned short params);
    void AddVariable(string variable)
    {
        char temp_char;
        bool pos_found=0;
        int temp_int=0;
        char temp_arr[50];

        std::transform(variable.begin(), variable.end(), variable.begin(), ::tolower);

        if (IsVarAvaible(variable)==-1)
        {
            if (rand()%2==0)
                temp_char=char_variable_replace[0];
            else
                temp_char=char_variable_replace[1];

            string alias="";
            for (int i=0; i<5; i++)
            {
                alias+=char_variable_replace[0];
                alias+=char_variable_replace[0];
                alias+=char_variable_replace[1];
                alias+=temp_char;
            }

            for (int i=0; i<50; i++)
            {
                if (change_var_char[i]==1)
                {
                    alias+=char_variable_replace[0];
                }
                else if (change_var_char[i]==2)
                {
                    alias+=char_variable_replace[1];
                }
            }

            int a=0;
            for (int i=0; i<50; i++)
            {
                if (change_var_char[i]==1)
                {
                    change_var_char[i]=2;
                    pos_found=1;
                    break;
                }
            }
            if (pos_found==0)
            {
                for (int i=0; i<50; i++)
                {
                    if (change_var_char[i]==2)
                    {
                        if (i!=49)
                        {
                            a=i;
                            while (a<49 && change_var_char[a]==2)
                            {
                                temp_arr[a]=change_var_char[a];
                                a++;
                            }
                            temp_int=a;
                            a=i;
                            while (a<temp_int)
                            {
                                change_var_char[a+1]=1;
                                a++;
                            }
                            change_var_char[0]=1;
                            pos_found=1;
                            break;
                        }
                    }
                }
            }


            if (pos_found==0)
                change_var_char[0]=1;

            if(change_var_char[49]==2)
            {
                if (mom_alphabet==0)
                {
                    for (int i=0; i<50; i++)
                        change_var_char[i]=0;

                    char_variable_replace[0]='I';
                    char_variable_replace[1]='l';

                    mom_alphabet++;
                }
                else if(mom_alphabet==1)
                {
                    for (int i=0; i<50; i++)
                        change_var_char[i]=0;

                    char_variable_replace[0]='E';
                    char_variable_replace[1]='3';

                    mom_alphabet++;
                }
                else
                {
                    for (int i=0; i<50; i++)
                        change_var_char[i]=0;

                    char_variable_replace[0]=(char)(rand()%23+65);
                    char_variable_replace[1]=(char)(rand()%23+65);
                }

            }
            variables[vadded][0]=variable;
            variables[vadded][1]=alias;

            vadded++;
            count++;
        }
    }
    void AddFunction(string function,string alias)
    {
        functions1[fadded][0]=function;
        functions1[fadded][1]=alias;
        fadded++;
        count++;
    }
    void AddStrings(string strings)
    {
        if(strings!="")
        {
            if (IsStringAvaible(strings)==-1)
            {
                //if (sadded<33) cout<<"index: "<<sadded<<" value: "<<strings<<endl;
                strings1[sadded]=strings;
                sadded++;
                count++;
            }
        }
    }
    int IsVarAvaible(string var);
    bool IsFuncAvaible(string func);
    void ObfuscateFunctions();
    void ObfuscateFunctionsHelper();
    void PlantErrors();
    void InsertCode(string code,unsigned int pos);
    void ObfuscateVariables();
    int IsStringAvaible(string var);
    void GetStrings();
    void ReplaceStringByArray();
public:
    string code[100001],code2,created_enc_func,created_enc_func2;
    int added,vadded,fadded,count2,var_last_length,sadded;
    string variables[30000][2];
    string functions1[30000][2];
    string strings1[30000];
    int count;
    bool ready,added_endfunc,added_endfunc2;
    string temp_code_copy[100001];
    char enc_func_opt,enc_func2_par1,enc_func2_par2,char_split;
    string random_func_crap[35];
    char change_var_char[50],char_variable_replace[2];
    short mom_alphabet;
    string var_name;
    string array_name_used;
};

long Parser::CountLines()
{
    return added;
}

int Parser::IsStringAvaible(string var)
{
    for(int i=0; i<sadded; i++)
    {
        if(strings1[i]==var)
        {
            return i;
        }
        if(strings1[i]=="") break;
    }
    return -1;
}

int Parser::IsVarAvaible(string var)
{
    for(int i=0; i<vadded; i++)
    {
        if(variables[i][0]==var)
        {
            return i;
        }
        if(variables[i][0]=="") break;
    }
    return -1;
}

bool Parser::IsFuncAvaible(string func)
{
    bool avaible=0;
    func=ReplaceAll(func," ","");
    for(int i=0; i<fadded; i++)
    {
        if(functions1[i][0]==func) avaible=1;
        if(functions1[i][0]=="") break;
    }
    return avaible;
}

void Parser::RemoveUnusedLines()
{
    for (int a=0; a<added; a++)
    {
        for (long i=0; i<code[a].length(); i++)
        {
            if (code[a].length()>2)
            {
                if (code[a][i]==char(13) && code[a][i+1]==char(13) && code[a][i+2]==char(10))
                {
                    code[a][i]=' ';
                    code[a][i+1]=' ';
                    code[a][i+2]=' ';
                }
                if (code[a][i]==char(13) && code[a][i+1]!=char(10))
                {
                    code[a][i]=' ';
                    code[a][i+1]=' ';
                }
                if (code[a][i]==char(13) && code[a][i+1]==char(10))
                {
                    code[a][i]=' ';
                    code[a][i+1]=char(10);
                }
            }
        }
    }
}

void Parser::RemoveIncludes()
{
    int QuotationsLeft=0,ApostrophesLeft=0;
    int found=-1;
    for(int a=0; a<added; a++)
    {
        found=-1;
        for (int i=0; i<code[a].length()-1; i++)
        {
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0)QuotationsLeft++;
            if(code[a][i]=='#' &&code[a][i+1]=='i' &&code[a][i+2]=='n'&&code[a][i+3]=='c' && code[a][i+4]=='l'
                    && ApostrophesLeft==0 && QuotationsLeft==0 )
            {
                found=i;
                break;
            }
        }

        string str2;
        if (found!=-1)
        {
            if (found==0 ) str2=NextLine;
            else str2=code[a].substr(0,found);
            code[a]=ReplaceAll(code[a],code[a],str2+NextLine);
        }
    }
}

void Parser::RemoveMultilineComments()
{
    int QuotationsLeft=0,ApostrophesLeft=0;
    int found[4];
    found[0]=-1;
    found[1]=-1;
    found[2]=0;
    found[3]=0;
    for (int a=0; a<added; a++)
    {
        for (int i=0; i<code[a].length(); i++)
        {
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0)QuotationsLeft++;
            if(code[a][i]==char(13)&&code[a][i+1]==char(10))
            {
                QuotationsLeft=0;
                ApostrophesLeft=0;
            }

            if(((code[a][i]=='#' && code[a][i+1]=='c' && code[a][i+2]=='s')||
                    (code[a][i]=='#' && code[a][i+1]=='c' && code[a][i+2]=='o'&& code[a][i+3]=='m'&& code[a][i+4]=='m'&& code[a][i+5]=='e'&& code[a][i+6]=='n'&& code[a][i+7]=='t'&& code[a][i+8]=='s'&& code[a][i+9]=='-'&& code[a][i+10]=='s'))
                    && ApostrophesLeft==0 && QuotationsLeft==0 )
            {
                found[0]=i;
                found[2]=a;
            }
            if(((code[a][i]=='#' && code[a][i+1]=='c' && code[a][i+2]=='e')||
                    (code[a][i]=='#' && code[a][i+1]=='c' && code[a][i+2]=='o'&& code[a][i+3]=='m'&& code[a][i+4]=='m'&& code[a][i+5]=='e'&& code[a][i+6]=='n'&& code[a][i+7]=='t'&& code[a][i+8]=='s'&& code[a][i+9]=='-'&& code[a][i+10]=='e'))
                    && ApostrophesLeft==0 && QuotationsLeft==0 )
            {
                found[1]=i;
                found[3]=a;
            }
            if (found[0]!=-1 && found[1]!=-1)
            {
                for (int ii=found[2]; ii<=found[3]; ii++)
                {
                    code[ii]="";
                }
                found[0]=-1;
                found[1]=-1;
            }
        }
    }
}

void Parser::PlantErrors()
{
    int line;
    string str,str2,str3,temp_str;
    for (unsigned int i=0; i<rand()%330+120; i++)
    {
        line=rand()%added+1;
        str=code[line];
        str2=code[line-1];
        str3=code[line+1];
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
        std::transform(str3.begin(), str3.end(), str3.begin(), ::tolower);
        if(str.find("switch")==string::npos && str2.find("switch")==string::npos && str3.find("switch")==string::npos &&
                str.find("select")==string::npos && str2.find("select")==string::npos && str3.find("select")==string::npos &&
                str.find("case")==string::npos && str2.find("case")==string::npos && str3.find("case")==string::npos)
        {
            if(rand()%2==0)
            {
                InsertCode(random_func_crap[rand()%35],line);
            }
            else
            {
                if (rand()%3==2)
                {
                    temp_str="0x";
                    for (int a=0;a<rand()%20+10;a++)
                    {
                        temp_str+="0";
                        temp_str+=IntToHex(rand()%12);
                    }
                    InsertCode("Execute(BinaryToString(\""+temp_str+"\"))\n",line);
                }
                else
                {
                    temp_str="0x";
                    for (int a=0;a<rand()%20+10;a++)
                    {
                        temp_str+=IntToHex(rand()%127);
                    }
                    InsertCode("Execute(BinaryToString(\""+temp_str+"\"))\n",line);
                }
            }

        }

    }
}

string Parser::CreateCrapParam(unsigned short params)
{
    string temp_crap="";
    for (unsigned short i=0; i<params; i++)
    {
        if (i!=0) temp_crap+=",";
        if(rand()%2==1)
        {
            if(rand()%2==1)
            {
                temp_crap+="'";
                for (unsigned short a=0; a<rand()%15+3; a++)
                {
                    temp_crap+=(char)(rand()%42+48);
                }
                temp_crap+="'";
            }
            else
            {
                temp_crap="\"";
                for (unsigned short a=0; a<rand()%15+3; a++)
                {
                    temp_crap+=(char)(rand()%42+48);
                }
                temp_crap+="\"";
            }
        }
        else
        {
            for (unsigned short a=0; a<rand()%15+3; a++)
            {
                temp_crap+=IntToString(rand()%420000+480);
            }
        }
    }
    return temp_crap;
}

void Parser::InsertCode(string code1,unsigned int pos)
{
    unsigned int i=pos,end=0;

    if (pos<100000)
    {
        if (code[pos]=="")
        {
            code[pos]=code1;
        }
        else
        {
            temp_code_copy[i]=code1;
            while(i<added)
            {
                temp_code_copy[i+1]=code[i];
                i++;
            }
            if (i!=added)
            {
                end=added+1;
                i=pos;
                while(i<end)
                {
                    code[i]=temp_code_copy[i];
                    i++;
                }
                added++;
            }
        }
    }

}

void Parser::RemoveComment()
{
    int QuotationsLeft=0,ApostrophesLeft=0;
    int found=-1;
    string str2;

    for(int a=0; a<added; a++)
    {
        found=-1;

        for (int i=0; i<code[a].length(); i++)
        {
            //cout<<code[a][i];
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0)QuotationsLeft++;
            if(code[a][i]==';' && ApostrophesLeft==0 && QuotationsLeft==0 )
            {
                found=i;
                break;
            }
        }


        if (found!=-1)
        {
            if (found==0 ) str2=NextLine;
            else str2=code[a].substr(0,found);
            code[a]=ReplaceAll(code[a],code[a],str2+NextLine);
        }
    }

}

void Parser::AddInclude(string str)
{
    FILE *file;
    file=fopen("Obfuscated.au3","a+");
    fputs(str.c_str(),file);
    fclose(file);
}

void Parser::IncludeFiles()
{
    char buffer[100000];
    string str,str2,str3,path;
    int QuotationsLeft=0,ApostrophesLeft=0,Misc=0;
    FILE *hFile;
    int found;
    int i=0 ;
    for(int a=0; a<added; a++)
    {
        i=0;
        while(i<code[a].length())
        {
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
            else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
            else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;

            if(code[a][i]==' ' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0 && i>0)
            {
                code[a].replace(i,1,"");
                i=i-2;
            }
            i++;
        }
        found=0;
        str=code[a];
        if (str[0]==' ') str.replace(0,1,"");
        str3=char(9);
        str=ReplaceAll(str,str3,"");
        str3=" include";
        for (int u=1; u<str3.length(); u++)
        {
            if (str3[u]==str[u] || char(int(str3[u])-32)==str[u])
            {
                found++ ;

            }
        }
        if (str[0]=='#' && found>=str3.length()-1 && (str.find(">")!=string::npos || str.find("\"")!=string::npos))
        {
            //str2=StringBetween(str,"#include<",">");
            //if (str2=="")str2=StringBetween(str,"#include\"","\"");
            str2=str.substr(8);
            str2=ReplaceAll(str2,"\"","");
            str2=ReplaceAll(str2,"<","");
            str2=ReplaceAll(str2,">","");
            str2=ReplaceAll(str2,"\n","");
            path=RegRead("\\SOFTWARE\\AutoIt v3\\AutoIt\\InstallDir")+"\\Include\\";
            if (str2[0]==' ') str2.replace(0,1,"");
            str3=path+str2;
            hFile=fopen(str3.c_str(),"r");
            //cout<< str <<"\n"<<str2<<"\n";
            //if (str2=="")cout<<"l";

            if (hFile==NULL)
            {
                path="C:\\Programme\\AutoIt3\\Include\\"+str2;
                hFile=fopen(path.c_str(),"r");
            }
            if (hFile==NULL) fclose(hFile) ;
            if (hFile!=NULL)
            {
                str3="";
                str2="";
                str="";
                code[a]="";
                do
                {
                    str=buffer;
                    str3+=str;
                    memcpy(buffer,";",1);
                    fgets(buffer,sizeof(buffer),hFile);
                }
                while (!feof(hFile));
                str=buffer;
                if (str[0]!=';') str3+=str;
                //cout<<str3;
                AddInclude(str3);
            }
            fclose(hFile);
        }

    }
}


void Parser::ObfuscateFunctions()
{
    int QuotationsLeft=0,ApostrophesLeft=0,Misc=0;
    bool found_func_exception=0;
    string str;
    int i=0,found=0;
    for(int a=0; a<added/2; a++)
    {
        found_func_exception=0;
        str=code[a];
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(str.find("hotkeyset")!=string::npos  || str.find("setonevent")!=string::npos || str.find("register")!=string::npos ||  str.find("execute")!=string::npos || str.find("adlib")!=string::npos || str.find("call")!=string::npos) found_func_exception=1;
        //cout<<a<<" ";
        //cout<<1;
        for(int o=0; o<fadded; o++)
        {
            i=0;
            QuotationsLeft=0;
            ApostrophesLeft=0;
            Misc=0;
            while(i<code[a].length()-2)
            {
                if(found_func_exception==0)
                {
                    if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
                    else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
                    else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
                    else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;
                }

                found=0;
                if(QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)
                {
                    for (int u=0; u<functions1[o][0].length(); u++)
                    {
                        //if(u<=functions1[o][0].length() && functions1[o][0][u]==' ') functions1[o][0].replace(u,1,"");

                        if (/*u<=functions1[o][0].length() && i<=code[a].length() &&*/ code[a].length()>i+functions1[o][0].length()+1 &&code[a].length()>i+u && (code[a][i+u]==functions1[o][0][u] ||
                                (functions1[o][0][u]>64 && functions1[o][0][u]<91 && code[a][i+u]==char(functions1[o][0][u]+32)) ||
                                (functions1[o][0][u]>96 && functions1[o][0][u]<123 && code[a][i+u]==char(functions1[o][0][u]-32))))
                        {
                            found++;
                        }
                        else
                        {
                            found=0;
                        }

                    }
                    if(found==functions1[o][0].length() && found!=0)
                    {
                        if(i>0)
                        {
                            if (code[a][i-1]==32 || code[a][i-1]==9 || code[a][i-1]==10 || code[a][i-1]==61 || code[a][i-1]==62 || code[a][i-1]==47 || code[a][i-1]==45 || code[a][i-1]==44 || code[a][i-1]==43 || code[a][i-1]==42 || code[a][i-1]==41 || code[a][i-1]==40 || code[a][i-1]==38 || code[a][i-1]==91 || code[a][i-1]==60 || code[a][i-1]==13 || code[a][i-1]==34 || code[a][i-1]==94 || code[a][i-1]=='\'')
                                code[a].replace(i,found,functions1[o][1]);
                        }
                        else
                        {
                            code[a].replace(i,found,functions1[o][1]);
                        }
                    }
                }
                i++;
                if (i>=code[a].length()) break ;
            }
            if (functions1[o][0]=="")break;
        }
        if (a>=added)break;
    }
    while (ready==0)
    {
        Sleep(100);
    }
}

DWORD WINAPI ThreadFunctions(LPVOID obj)
{
    Parser* objekt = (Parser *)obj;
    objekt->ObfuscateFunctionsHelper();
    return 0;
}

void Parser::ObfuscateFunctionsHelper()
{
    int QuotationsLeft=0,ApostrophesLeft=0,Misc=0;
    bool found_func_exception=0;
    int i=0,found=0;
    ready=0;
    string str;
    for(int a=(int)(added/2-1); a<added; a++)
    {
        found_func_exception=0;
        str=code[a];
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(str.find("hotkeyset")!=string::npos  || str.find("setonevent")!=string::npos || str.find("register")!=string::npos ||  str.find("execute")!=string::npos || str.find("adlib")!=string::npos || str.find("call")!=string::npos) found_func_exception=1;

        for(int o=0; o<fadded; o++)
        {
            i=0;
            QuotationsLeft=0;
            ApostrophesLeft=0;
            Misc=0;
            while(i<code[a].length()-2)
            {
                if(found_func_exception==0)
                {
                    if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
                    else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
                    else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
                    else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;
                }
                found=0;
                if(QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)
                {
                    for (int u=0; u<functions1[o][0].length(); u++)
                    {
                        //if(u<=functions1[o][0].length() && functions1[o][0][u]==' ') functions1[o][0].replace(u,1,"");

                        if (/*u<=functions1[o][0].length() && i<=code[a].length() &&*/ code[a].length()>i+functions1[o][0].length()+1 &&code[a].length()>i+u && (code[a][i+u]==functions1[o][0][u] ||
                                (functions1[o][0][u]>64 && functions1[o][0][u]<91 && code[a][i+u]==char(functions1[o][0][u]+32)) ||
                                (functions1[o][0][u]>96 && functions1[o][0][u]<123 && code[a][i+u]==char(functions1[o][0][u]-32))))
                        {
                            found++;
                        }
                        else
                        {
                            found=0;
                        }

                    }
                    if(found==functions1[o][0].length() && found!=0)
                    {
                        if(i>0)
                        {
                            if (code[a][i-1]==32 || code[a][i-1]==9 || code[a][i-1]==10 || code[a][i-1]==61 || code[a][i-1]==62 || code[a][i-1]==47 || code[a][i-1]==45 || code[a][i-1]==44 || code[a][i-1]==43 || code[a][i-1]==42 || code[a][i-1]==41 || code[a][i-1]==40 || code[a][i-1]==38 || code[a][i-1]==91 || code[a][i-1]==60 || code[a][i-1]==13 || code[a][i-1]==34 || code[a][i-1]==94 || code[a][i-1]=='\'')
                                code[a].replace(i,found,functions1[o][1]);
                        }
                        else
                        {
                            code[a].replace(i,found,functions1[o][1]);
                        }
                    }
                }


                i++;
                if (i>=code[a].length()) break ;
            }
            if (functions1[o][0]=="")break;
        }
        if (a>=added)break;
    }
    ready=1;
}

void Parser::ReplaceStringByArray()
{
    int i=0,found=-1,ApostrophesLeft=0,QuotationsLeft=0,pos=0,found_before;
    string temp_string="",temp_str="";
    GetStrings();
    char ran_number=0;
    for(int a=0; a<added; a++)
    {
        ApostrophesLeft=0;
        QuotationsLeft=0;
        i=0;
        //if (code[a].find("IsDeclared")==string::npos)
        {
            while(i<code[a].length())
            {
                while(i<code[a].length())
                {
                    if (code[a][i]=='"')
                    {
                        QuotationsLeft=1;
                        found=i;
                        break;
                    }
                    else if(code[a][i]=='\'')
                    {
                        ApostrophesLeft=1;
                        found=i;
                        break;
                    }
                    i++;
                }

                if(found > -1)
                {
                    if (code[a][found]=='"' && ApostrophesLeft==0  && QuotationsLeft==1)
                    {
                        temp_string="";
                        found_before=i;
                        i=found+1;
                        while(i<code[a].length() && QuotationsLeft==1)
                        {
                            if(code[a][i]=='"')
                                QuotationsLeft=0;
                            else
                                temp_string+=code[a][i];

                            i++;
                        }

                        pos=IsStringAvaible(temp_string);
                        if (pos!=-1)
                        {
                            ran_number=rand()%100;
                            code[a].replace(found_before,strings1[pos].length()+2,"BinaryToString("+array_name_used+"["+IntToString(pos+ran_number)+"-"+IntToString((int)ran_number)+"])");
                        }
                        found=-1;
                    }
                    else if (code[a][found]=='\'' && ApostrophesLeft==1 && QuotationsLeft==0)
                    {
                        temp_string="";
                        found_before=i;
                        i=found+1;
                        while(i<code[a].length() && ApostrophesLeft==1)
                        {
                            if(code[a][i]=='\'')
                                ApostrophesLeft=0;
                            else
                                temp_string+=code[a][i];

                            i++;
                        }
                        pos=IsStringAvaible(temp_string);
                        if (pos!=-1)
                        {
                            ran_number=rand()%100;
                            code[a].replace(found_before,strings1[pos].length()+2,"BinaryToString("+array_name_used+"["+IntToString(pos+ran_number)+"-"+IntToString((int)ran_number)+"])");
                        }
                        found=-1;
                    }
                }

                i++;
            }
        }

    }
}

void Parser::GetStrings()
{
    int i=0,found=-1,ApostrophesLeft=0,QuotationsLeft=0;
    string temp_string="",temp_str="";
    for(int a=0; a<added; a++)
    {
        ApostrophesLeft=0;
        QuotationsLeft=0;
        i=0;
        temp_str=code[a];
        std::transform(temp_str.begin(), temp_str.end(),temp_str.begin(), ::tolower);
        if (temp_str.find("func ")==string::npos)
        {
            while(i<code[a].length())
            {
                while(i<code[a].length())
                {
                    if (code[a][i]=='"')
                    {
                        QuotationsLeft=1;
                        found=i;
                        break;
                    }
                    else if(code[a][i]=='\'')
                    {
                        ApostrophesLeft=1;
                        found=i;
                        break;
                    }
                    i++;
                }
                if(found > -1)
                {
                    if (code[a][found]=='"' && ApostrophesLeft==0  && QuotationsLeft==1)
                    {
                        temp_string="";
                        i=found+1;
                        while(i<code[a].length() && QuotationsLeft==1)
                        {
                            if(code[a][i]=='"')
                                QuotationsLeft=0;
                            else
                                temp_string+=code[a][i];

                            i++;
                        }
                        AddStrings(temp_string);
                        found=-1;
                    }
                    else if (code[a][found]=='\'' && ApostrophesLeft==1 && QuotationsLeft==0 && found>-1)
                    {
                        temp_string="";
                        i=found+1;
                        while(i<code[a].length() && ApostrophesLeft==1)
                        {
                            if(code[a][i]=='\'')
                                ApostrophesLeft=0;
                            else
                                temp_string+=code[a][i];

                            i++;
                        }
                        AddStrings(temp_string);
                        found=-1;
                    }
                }

                i++;
            }
        }

    }
}

void Parser::GetFunctions()
{
    string str;
    int QuotationsLeft=0,ApostrophesLeft=0,Misc=0,i=0;
    for(int a=0; a<added; a++)
    {
        i=0;
        QuotationsLeft=0;
        ApostrophesLeft=0;
        Misc=0;
        while(i<code[a].length())
        {
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
            else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
            else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;

            if(code[a][i]==' ' && code[a][i+1]==' ' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)
            {
                code[a].replace(i,1,"");
                i=i-2;
            }
            i++;
        }
        if(code[a].length()>4 && (code[a][0]=='f'||code[a][0]=='F')&&(code[a][1]=='u'||code[a][1]=='U')&&(code[a][2]=='n'||code[a][2]=='N')&&(code[a][3]=='c'||code[a][3]=='C'))
        {
            i=4;
            QuotationsLeft=0;
            ApostrophesLeft=0;
            Misc=0;
            while(i<code[a].length())
            {
                if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
                else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
                else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
                else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
                else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
                else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;

                if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)
                {
                    str=code[a].substr(5,i-5);
                    if(IsFuncAvaible(str)==0) AddFunction(str,"_"+IntToString(rand() % 24 + 65)+IntToHex(rand() % 513 + 413)+char(rand() % 26 + 97)+IntToString(count)+char(rand() % 26 + 97)+IntToHex(rand() % 513 + 113)+char(count%20+66));
                    //cout<<functions1[fadded-1][0]<<"\n"<<functions1[fadded-1][1]<<"\n\n";
                }
                i++;
            }
        }
    }
}

void Parser::GetVariables()
{
    int i=0,found=0,ApostrophesLeft=0,bracket1=0,bracket2=0,QuotationsLeft=0;
    string temp_var="",temp_str="";
    for(int a=0; a<added; a++)
    {
        ApostrophesLeft=0;
        bracket1=0;
        bracket2=0;
        QuotationsLeft=0;
        i=0;
        while(i<code[a].length())
        {
            if (code[a][i]>=33)
            {
                found=i;
                break;
            }
            i++;
        }

        if (code[a][found]=='$')
        {
            temp_var="";
            i=found+1;
            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
            {
                temp_var+=code[a][i];
                i++;
            }
            AddVariable(temp_var);
        }
        else if(code[a][found]=='a' || code[a][found]=='A')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("assign")==found)
            {
                if (found!=string::npos)
                {
                    i=found+6;
                    while (i<code[a].length() && code[a][i]!='"' && code[a][i]!='\'')
                    {
                        i++;
                    }
                    i++;
                    temp_var="";
                    while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                    {
                        temp_var+=code[a][i];
                        i++;
                    }
                    AddVariable(temp_var);
                }

            }
        }
        else if(code[a][found]=='g' || code[a][found]=='G')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("global")==found)
            {
                if (found!=string::npos)
                {
                    i=found+5;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
        else if(code[a][found]=='d' || code[a][found]=='D')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("dim")==found)
            {
                if (found!=string::npos)
                {
                    i=found+2;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
        else if(code[a][found]=='l' || code[a][found]=='L')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("local")==found)
            {
                if (found!=string::npos)
                {
                    i=found+4;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
        else if(code[a][found]=='c' || code[a][found]=='C')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("const")==found)
            {
                if (found!=string::npos)
                {
                    i=found+4;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
        else if(code[a][found]=='f' || code[a][found]=='F')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("func")==found)
            {
                if (found!=string::npos)
                {
                    i=found+3;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
        else if(code[a][found]=='s' || code[a][found]=='S')
        {
            temp_str=code[a];
            std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
            if (temp_str.find("static")==found)
            {
                if (found!=string::npos)
                {
                    i=found+5;
                    while (i<code[a].length())
                    {
                        if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
                        else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
                        else if(code[a][i]=='(' && ApostrophesLeft==0 && QuotationsLeft==0)bracket1++;
                        else if(code[a][i]==')' && QuotationsLeft==0 && ApostrophesLeft==0)bracket1--;
                        else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                        else if(code[a][i]=='[' && ApostrophesLeft==0 && QuotationsLeft==0)bracket2++;
                        else if(code[a][i]==']' && QuotationsLeft==0 && ApostrophesLeft==0)bracket2--;

                        if(QuotationsLeft==0 && ApostrophesLeft==0 && bracket2==0 && bracket1==0 && code[a][i]=='$')
                        {
                            i++;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            AddVariable(temp_var);
                        }
                        i++;
                    }

                }

            }
        }
    }
}

void Parser::ObfuscateVariables()
{
    GetVariables();
    int ApostrophesLeft=0,QuotationsLeft=0;
    int i=0,pos=-1,temp_i=0;
    string temp_var="",temp_str,str2,str,str3,str4;
    for(int a=0; a<added; a++)
    {
        i=0;
        QuotationsLeft=0;
        ApostrophesLeft=0;
        while(i<code[a].length())
        {
            if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1)QuotationsLeft--;
            else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0)ApostrophesLeft++;
            else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
            if(QuotationsLeft==0 && ApostrophesLeft==0)
            {
                if(code[a][i]=='$')
                {
                    i++;
                    temp_i=i;
                    temp_var="";
                    while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                    {
                        temp_var+=code[a][i];
                        i++;
                    }
                    std::transform(temp_var.begin(), temp_var.end(), temp_var.begin(), ::tolower);
                    pos=IsVarAvaible(temp_var);
                    if (pos!=-1)
                    {
                        while(i<code[a].length() && code[a][i]<33)
                        {
                            temp_var+=code[a][i];
                            i++;
                        }
                        if (rand()%4==0)
                        {
                            temp_str=code[a];
                            std::transform(temp_str.begin(), temp_str.end(),temp_str.begin(), ::tolower);
                            if (code[a].find("'")==string::npos && code[a][i]=='=' && code[a].find(";")==string::npos && code[a].find("[")==string::npos
                                    && temp_str.find("if")==string::npos && temp_str.find("end")==string::npos && temp_str.find("select")==string::npos &&
                                    temp_str.find("switch")==string::npos && temp_str.find("func")==string::npos && temp_str.find("while")==string::npos &&
                                    temp_str.find("until")==string::npos && temp_str.find("case")==string::npos && temp_str.find("for")==string::npos &&
                                    temp_str.find("with")==string::npos && temp_str.find("_\r")==string::npos)
                            {
                                str=ReplaceAll(ReplaceAll(code[a].substr(i+1),"\n",""),"\r","");
                                if (str.find("$")==string::npos)
                                {
                                    str= "Assign('"+variables[pos][1]+"',"+str+")";

                                    str2="0x";
                                    for (int o=0; o<str.length(); o++)
                                    {
                                        if(str[o]>13 || str[o]<0) str2+=IntToHex(str[o]);
                                    }

                                    if (rand()%3==0)
                                    {
                                        str3="Assign('"+variables[rand()%pos][1]+"',"+IntToString(rand()%10000)+")";

                                        str4="0x";
                                        for (int o=0; o<str3.length(); o++)
                                        {
                                            if(str3[o]>13 || str3[o]<0) str4+=IntToHex(str3[o]);
                                        }

                                        if (rand()%2==0)
                                        {

                                            if (rand()%3==0)
                                            {
                                                str2="Execute(BinaryToString(\""+str2+"\"))\r\nExecute(BinaryToString(\""+str4+"3B\"))";
                                            }
                                            else
                                            {
                                                str2="Execute(BinaryToString(\""+str2+"\"))\r\nExecute(BinaryToString(\""+str4+IntToHex(rand()%200)+IntToHex(rand()%200)+"\"))";
                                            }
                                        }
                                        else
                                        {
                                            if (rand()%3==0)
                                            {
                                                str2="Execute(BinaryToString(\""+str4+"3B\"))\r\nExecute(BinaryToString(\""+str2+"\"))";
                                            }
                                            else
                                            {
                                                str2="Execute(BinaryToString(\""+str4+IntToHex(rand()%200)+"\"))\r\nExecute(BinaryToString(\""+str2+"\"))";
                                            }
                                        }
                                    }
                                    else
                                        str2="Execute(BinaryToString(\""+str2+"\"))";
                                    code[a]="if IsDeclared('"+variables[pos][1]+"')=0 then $"+variables[pos][1]+"=0\r\n"+str2+"\r\n";
                                }
                                else
                                {
                                    code[a].replace(temp_i,variables[pos][0].length(),variables[pos][1]);
                                }
                            }
                            else if (code[a].find("\"")==string::npos && code[a][i]=='=' && code[a].find(";")==string::npos && code[a].find("[")==string::npos
                                     && temp_str.find("if")==string::npos && temp_str.find("end")==string::npos && temp_str.find("select")==string::npos &&
                                     temp_str.find("switch")==string::npos && temp_str.find("func")==string::npos && temp_str.find("while")==string::npos &&
                                     temp_str.find("until")==string::npos && temp_str.find("case")==string::npos && temp_str.find("for")==string::npos &&
                                     temp_str.find("with")==string::npos && temp_str.find("_\r")==string::npos)
                            {
                                str=ReplaceAll(ReplaceAll(code[a].substr(i+1),"\n",""),"\r","");
                                if (str.find("$")==string::npos)
                                {
                                    str= "Assign(\""+variables[pos][1]+"\","+str+")";

                                    str2="0x";
                                    for (int o=0; o<str.length(); o++)
                                    {
                                        if(str[o]>13 || str[o]<0) str2+=IntToHex(str[o]);
                                    }
                                    str2="Execute(BinaryToString(\""+str2+"\"))";
                                    code[a]="if IsDeclared('"+variables[pos][1]+"')=0 then $"+variables[pos][1]+"=0\r\n"+str2+"\r\n";

                                }
                                else
                                {
                                    code[a].replace(temp_i,variables[pos][0].length(),variables[pos][1]);
                                }

                            }
                            else
                            {
                                code[a].replace(temp_i,variables[pos][0].length(),variables[pos][1]);
                            }
                        }
                        else
                        {
                            code[a].replace(temp_i,variables[pos][0].length(),variables[pos][1]);
                        }

                    }
                }
                else if(code[a][i]=='a' || code[a][i]=='e' || code[a][i]=='i' ||
                        code[a][i]=='A' || code[a][i]=='E' || code[a][i]=='I')
                {
                    temp_str=code[a];
                    std::transform(temp_str.begin(), temp_str.end(), temp_str.begin(), ::tolower);
                    if (temp_str.find("assign")==i || temp_str.find("eval")==i || temp_str.find("isdeclared")==i)
                    {
                        if (i!=string::npos)
                        {
                            i+=3;
                            while (i<code[a].length() && code[a][i]!='"' && code[a][i]!='\'')
                            {
                                i++;
                            }
                            i++;
                            temp_i=i;
                            temp_var="";
                            while(i<code[a].length() && ((code[a][i]>='a' && code[a][i]<='z') || (code[a][i]>='A' && code[a][i]<='Z') || code[a][i]=='_' || (code[a][i]>='0' && code[a][i]<='9') ) )
                            {
                                temp_var+=code[a][i];
                                i++;
                            }
                            std::transform(temp_var.begin(), temp_var.end(), temp_var.begin(), ::tolower);
                            pos=IsVarAvaible(temp_var);
                            if (pos!=-1)
                            {
                                code[a].replace(temp_i,variables[pos][0].length(),variables[pos][1]);
                            }
                        }
                    }
                }
            }
            i++;
        }

    }
}

void Parser::ObfuscateStrings()
{
    int var,i,index,a=0;
    int QuotationsLeft=0,ApostrophesLeft=0;
    string str,str2,var2,str3,temp_str;
    AddCode("  \r\n");
    int added2=added;
    while(a<added2)
    {
        //cout<<added<<"\n";
        str3=ReplaceAll(code[a]," ","");
        if(str3!="" && str3[0]!='f' && str3[0]!='F' && str3[0]!='#' )
        {
            for(int e=0; e<1; e++)
            {
                i=0;
                QuotationsLeft=0;
                ApostrophesLeft=0;
                while(i<code[a].length())
                {
                    if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 )QuotationsLeft--;
                    else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 )ApostrophesLeft++;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                    if(rand()%12==1 && ((code[a][i]>64 && code[a][i]<91) || (code[a][i]>96 && code[a][i]<123) || (code[a][i]>47 && code[a][i]<58)))
                    {
                        if(ApostrophesLeft==0 && QuotationsLeft==1 && code[a][i]!='"')
                        {
                            index=rand()%20;
                            var=FindVar(index,int(code[a][i]),str,str2);
                            if (str!="-1")
                            {
                                str2=char(rand()%26+65)+IntToString(rand()%126+65)+IntToString(index)+IntToString(code[a].length())+IntToString(var%10)+IntToString(count2);
                                var2="$"+IntToString(rand()%126+65)+char(rand()%26+65)+IntToString(rand()%126215+1)+IntToString(count2);
                                AddCode("Func _"+str2+"("+var2+")\r\n");
                                for (int o=0; o<11; o++)AddCode(ReplaceAll(created_funcs[index][o][0],"x",var2)+"\r\n");
                                AddCode(ReplaceAll(str,"x",var2)+"\r\n");
                                AddCode("return "+var2+"\r\n");
                                AddCode("EndFunc\n");
                                str="\"&chr(_"+str2+"("+IntToString(var)+"))&\"";
                                code[a].replace(i,1,str);
                                QuotationsLeft=0;
                                i=code[a].length();
                                count2++;
                            }
                        }
                        else if(ApostrophesLeft==1 && QuotationsLeft==0 && code[a][i]!='\'')
                        {
                            index=rand()%20;
                            var=FindVar(index,int(code[a][i]),str,str2);
                            if (str!="-1")
                            {
                                str2=char(rand()%26+65)+IntToString(rand()%126+65)+IntToString(index)+IntToString(code[a].length())+IntToString(var%10)+IntToString(count2);
                                var2="$"+IntToString(rand()%126+65)+char(rand()%26+65)+IntToString(rand()%126215+1)+IntToString(count2);
                                AddCode("Func _"+str2+"("+var2+")\n");
                                for (int o=0; o<11; o++)AddCode(ReplaceAll(created_funcs[index][o][0],"x",var2)+"\n");
                                AddCode(ReplaceAll(str,"x",var2)+"\r\n");
                                AddCode("Return "+var2+"\r\n");
                                AddCode("EndFunc\n");
                                str="'&chr(_"+str2+"("+IntToString(var)+"))&'";
                                code[a].replace(i,1,str);
                                QuotationsLeft=0;
                                i=code[a].length();
                                count2++;
                            }
                        }
                    }
                    i++;
                    if(i>=code[a].length()) break;
                }
            }
        }
        a++;
        if(a>=added+1) break;
    }
}

void Parser::ObfuscateStringsEx()
{
    int i,a=0;
    int QuotationsLeft=0,ApostrophesLeft=0;
    string str,str2,var2,str3;
    AddCode("  \r\n");
    int added2=added;
    while(a<added2)
    {
        //cout<<added<<"\n";
        str3=ReplaceAll(code[a]," ","");
        if(str3!="" && str3[0]!='f' && str3[0]!='F' && str3[0]!='#' )
        {
            for(int e=0; e<2; e++)
            {
                i=0;
                QuotationsLeft=0;
                ApostrophesLeft=0;
                while(i+1<code[a].length())
                {
                    if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1)ApostrophesLeft--;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 )QuotationsLeft--;
                    else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 )ApostrophesLeft++;
                    else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 )QuotationsLeft++;
                    if(rand()%8==1 && ((code[a][i]>64 && code[a][i]<91) || (code[a][i]>96 && code[a][i]<123) || (code[a][i]>47 && code[a][i]<58)))
                    {
                        if(ApostrophesLeft==0 && QuotationsLeft==1 && code[a][i]!='"')
                        {
                            if (code[a][i]=='2' && code[a][i+1]=='2')
                            {
                                str="\"&hex(asc('\"'),2)&\""; //replace with dec 34
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='7')
                            {
                                str="\"&hex(asc(\"'\"),2)&\""; //replace with dec 39
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='8')
                            {
                                str="\"&hex(asc(\"(\"),2)&\""; //replace with dec 40
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='9')
                            {
                                str="\"&hex(asc(\')\'),2)&\""; //replace with dec 41
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='7' && (code[a][i+1]=='b' || code[a][i+1]=='B'))
                            {
                                str="\"&hex(asc(\'{\'),2)&\""; //replace with dec 123
                                code[a].replace(i,2,str);
                            }
                            i=code[a].length();
                        }
                        else if(ApostrophesLeft==1 && QuotationsLeft==0 && code[a][i]!='\'')
                        {
                            if (code[a][i]=='2' && code[a][i+1]=='2')
                            {
                                str="\'&hex(asc('\"'),2)&\'"; //replace with dec 34
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='7')
                            {
                                str="'&hex(asc(\"'\"),2)&\'"; //replace with dec 39
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='8')
                            {
                                str="'&hex(asc(\"(\"),2)&\'"; //replace with dec 40
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='2' && code[a][i+1]=='9')
                            {
                                str="'&hex(asc(\')\'),2)&\'"; //replace with dec 41
                                code[a].replace(i,2,str);
                            }
                            else if(code[a][i]=='7' && code[a][i+1]=='b')
                            {
                                str="'&hex(asc(\'{\'),2)&\'"; //replace with dec 123
                                code[a].replace(i,2,str);
                            }
                            i=code[a].length();
                        }
                    }
                    i++;
                    if(i>=code[a].length()) break;
                }
            }
        }
        a++;
        if(a>=added+1) break;
    }

}

void CreateFuctions(short index)
{
    short ran=0;
    string str;
    for (int i=0; i<rand()%7+2; i++)
    {
        ran=rand()%5;
        str=IntToString(rand()%20+1);
        if (ran==0)
        {
            created_funcs[index][i][0]="x=BitAnd(x,"+str+")";
            created_funcs[index][i][1]="&"+str;
        }
        else if (ran==1)
        {
            created_funcs[index][i][0]="x=x+"+str;
            created_funcs[index][i][1]="+"+str;
        }
        else if (ran==2)
        {
            created_funcs[index][i][0]="x=BitXOr(x,"+str+")";
            created_funcs[index][i][1]="^"+str;
        }
        else if (ran==3)
        {
            created_funcs[index][i][0]="x=x-"+str;
            created_funcs[index][i][1]="-"+str;
        }
    }
}

int InterpretFuctions(short index,int var)
{
    int zahl=0;
    for (short i=0; i<11; i++)
    {
        if (created_funcs[index][i][1]!="")
        {
            zahl=StringToInt(created_funcs[index][i][1].substr(1));
            if (created_funcs[index][i][1][0]=='^')
            {
                var=var^zahl;
            }
            else if (created_funcs[index][i][1][0]=='+')
            {
                var=var+zahl;
            }
            else if (created_funcs[index][i][1][0]=='-')
            {
                var=var-zahl;
            }
            else if (created_funcs[index][i][1][0]=='%')
            {
                var=var%zahl;
            }
            else if (created_funcs[index][i][1][0]=='&')
            {
                var=var&zahl;
            }
        }
    }
    return var;
}


void Parser::ObfuscateCommands(bool activate_crypt)
{
    int QuotationsLeft=0,ApostrophesLeft=0,Misc=0;
    string str,str2="0x",str3,str4;
    int i=0;
    short found;
    bool KeywordsFound=0;
    for(int a=0; a<added; a++)
    {
        while (code[a][0]==' ') code[a].replace(0,1,"");
        if (!((code[a][0]=='F' || code[a][0]=='f') &&
                (code[a][1]=='I' || code[a][1]=='i') &&
                (code[a][2]=='L' || code[a][2]=='l') &&
                (code[a][3]=='E' || code[a][3]=='e') &&
                (code[a][4]=='I' || code[a][4]=='i') &&
                (code[a][5]=='N' || code[a][5]=='n')) &&
                !((code[a][0]=='F' || code[a][0]=='f')&&
                  (code[a][1]=='U' || code[a][1]=='u')&&
                  (code[a][2]=='N' || code[a][2]=='n')&&
                  (code[a][3]=='C' || code[a][3]=='c')))
        {
            i=0;
            KeywordsFound=0;

            while(i<code[a].length()-1)
            {
                if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
                else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
                else if(code[a][i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
                else if(code[a][i]=='<' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)Misc++;
                else if(code[a][i]=='>' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc>=1)Misc--;
                else if(code[a][i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;

                if(code[a][i]==' ' && code[a][i+1]==' ' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)
                {
                    code[a].replace(i,1,"");
                    i=i-2;
                }
                i++;
                if (i>=code[a].length()) break;
            }
            str=ReplaceAll(code[a],"\n\n","\n");
            str3=char(9);
            str=ReplaceAll(str,str3,"");
            //cout<<a<<" ";
            if (str[0]==' ') str.replace(0,1,"");
            for (int o=0; o<32; o++)
            {
                found=0;
                for (int u=0; u<keywords[o].length(); u++)
                {
                    if ((keywords[o][u]==str[u] || keywords[o][u]-32==str[u])  && str[u]!=' '  ) found++;
                }
                if (found==keywords[o].length())
                {
                    KeywordsFound=1;
                    break;
                }
            }
            str3=ReplaceAll(str," ","");
            if (a>0) str4=ReplaceAll(code[a-1]," ","");
            if (str[0]!='$' && str[0]!=';' && str[0]!='#' && KeywordsFound==0 && str3.find("_\n")==string::npos &&  str4.find("_\n")==string::npos)
            {

                str2="0x";
                for (int o=0; o<str.length(); o++)
                {
                    if(str[o]>13 || str[o]<0) str2+=IntToHex(str[o]);
                }
                if (str2!="0x" && str2!="0xA" )
                {
                    if (activate_crypt==1 && added_endfunc==0 && str3.find("$")==string::npos && str3.find("Execute")==string::npos)
                    {
                        str2=Encrypt_Au3_Func(str2,enc_func_opt);
                        str2=created_enc_func+"(\""+str2+"\")\r\n";
                        if (str2.length()<2000)  code[a]=str2;
                    }
                    else
                    {
                        str2="Execute(BinaryToString(\""+str2+"\"))"+"\r\n";
                        if (str2.length()<2000)  code[a]=str2;
                    }

                }
            }
            else if( str[0]!=';' && str[0]!='#' && str3.find("$")!=string::npos && str3.find("_\n")==string::npos &&  str4.find("_\n")==string::npos)
            {
                QuotationsLeft=0;
                ApostrophesLeft=0;
                i=0;
                KeywordsFound=0;
                if (str[0]==' ') str.replace(0,1,"");
                for (int o=0; o<32; o++)
                {
                    found=0;
                    for (int u=0; u<keywords[o].length(); u++)
                    {
                        if ((keywords[o][u]==str[u] || keywords[o][u]-32==str[u])  && str[u]!=' '  ) found++;
                    }
                    if (found==keywords[o].length())
                    {
                        KeywordsFound=1;
                        break;
                    }
                }
                if (KeywordsFound==0)
                {
                    while(i<str.length())
                    {
                        if(str[i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==1 && Misc==0)ApostrophesLeft--;
                        else if(str[i]=='"' && ApostrophesLeft==0 && QuotationsLeft==1 && Misc==0)QuotationsLeft--;
                        else if(str[i]=='\'' && QuotationsLeft==0 && ApostrophesLeft==0 && Misc==0)ApostrophesLeft++;
                        else if(str[i]=='"' && ApostrophesLeft==0 && QuotationsLeft==0 && Misc==0)QuotationsLeft++;
                        if(str[i]=='=' && ApostrophesLeft==0 && QuotationsLeft==0)
                        {
                            str4=str.substr(i+1);
                            str3=str.substr(0,i);
                            str=str4;
                            str2="0x";
                            for (int o=0; o<str.length(); o++)
                            {
                                if(str[o]>13 || str[o]<0) str2+=IntToHex(str[o]);
                            }
                            if (str2!="0x" && str2!="0xA" && str[0]!='[' && str[1]!='[' )
                            {
                                str2=str3+"=Execute(BinaryToString(\""+str2+"\"))"+"\n";
                                if (str2.length()<2000)code[a]=str2;
                                break;
                            }
                        }
                        i++;
                        if (i>=code[a].length()) break;
                    }
                }
            }
            if (a>=added) break;
        }
    }

    if (activate_crypt==1 && added_endfunc==0)
    {
        AddCode("Func "+created_enc_func+"($text)\n");
        AddCode("DllStructSetData($struct_Shadow_Obfus_Variable_Not_Overwrite_Pls, 1, \"\")\n");
        AddCode("DllCall(\"user32.dll\", \"ptr\", \"CallWindowProcW\", \"ptr\", DllStructGetPtr($tCodeBuffer_Shadow_Obfus_Variable_Not_Overwrite_Pls), \"str*\", $text, \"ptr\", DllStructGetPtr($struct_Shadow_Obfus_Variable_Not_Overwrite_Pls), \"int\", 0, \"int\", 0)\n");
        AddCode("Execute(StringMid(BinaryToString(BinaryToString(DllStructGetData($struct_Shadow_Obfus_Variable_Not_Overwrite_Pls, 1), 1)),1,StringLen($text)/2-1))\n");
        AddCode("EndFunc\n");
        added_endfunc=1;
    }
}

int FindVar(int index,int zahl,string& ergebniss1,string& ergebniss2)
{
    int erg=0,zahl2=zahl;
    for (int i=-100; i<100; i++)
    {
        if (InterpretFuctions(index,i)==zahl)
        {
            erg=i;
            break;
        }
    }
    if(erg==0)
    {
        zahl2=rand()%20+1;
        erg=zahl-InterpretFuctions(index,zahl2);
        ergebniss1="x=x+"+IntToString(erg);
        ergebniss2="+"+IntToString(erg);
    }
    else
    {
        ergebniss1="-1";
        ergebniss2="-1";
    }
    return zahl2;
}


int main()
{
    time_t start,end;
    double dif;
    string str3="";
    string obfuscator_file="";
    string splited[32];

    Parser test;

    cout<<"Pfad Zur Datei (Doppelte \\\\ statt Einfachen \\ Bsp. C:\\\\Dek\\\\test.au3)\nMit Enter bestaetigen:\n";
    cin>>str3;

    time (&start);
    srand(time(NULL));
    for (int i=0; i<20; i++)CreateFuctions(i);
    NextLine=char(13);
    NextLine+=char(10);
    char buffer[200000];
    string str="";
    FILE *file;

    file=fopen(str3.c_str(),"r");
    cout<<"Lese Datei"<<endl;
    if (file!=NULL)
    {
        do
        {

            fgets(buffer,sizeof(buffer),file);
            str=buffer;
            test.AddCode(str);
            memcpy(buffer,";",1);
            //cout<<str;
        }
        while (!feof(file));
        str=buffer;
        test.AddCode(str);
        //cout<<str;
        fclose(file);
    }

    Split(str3,"\\",&(*splited),32);

    for (char i=0; i<30; i++)
    {
        if(splited[i+1]!="" || splited[i+2]!="")
            obfuscator_file+=splited[i]+"\\";
        else
            break;
    }

    str=str3;
    str=ReplaceAll(str,".au3","-Obfuscated.au3");
    str=ReplaceAll(str,".txt","-Obfuscated.txt");
    cout<<"Obfuscation gestartet"<<endl;
    test.RemoveAllComments();
    test.ObfuscateVariables();
    //cin>>str;
    cout<<"Kommentare wurden erfolgreich entfernt.\n";
    //test.RemoveIncludes();
    //test.RemoveUnusedLines();
    test.GetFunctions();
    CreateThread(NULL, 0, ThreadFunctions, (LPVOID)&test, 0, NULL);
    test.ObfuscateFunctions();
    cout<<"Funktionen wurden erfolgreich obfuscatet.\n";
    test.ObfuscateCommands(1);
    cout<<"Befehle wurden erfolgreich obfuscatet.\n";
    test.ReplaceStringByArray();
    cout<<"Strings wurden durch Arrays ersetzt.\n";
    test.ObfuscateStrings();
    cout<<"Strings wurden erfolgreich obfuscatet.\n";
    test.ObfuscateStringsEx();
    test.PlantErrors();
    test.RemoveUnusedLines();
    cout<<"Unnoetige Zeilen wurden erfolgreich entfernt.\n";
    str3=test.GetCode(obfuscator_file);
    file=fopen(str.c_str(),"w+");
    if (file!=NULL)
    {
        fputs(str3.c_str(),file);
    }
    fclose(file);
    cout<<"Obfuscation wurde erfolgreich beendet.\n\n";
    time (&end);
    dif = difftime (end,start);
    cout<<"Es hat "<<dif<<" s gedauert das Skript zu obfuscaten.\n";
    cin >> str;
    //cout<<str;
    /*string temp="";
    for (short i=0; i<test.added; i++)
        if (test.functions1[i][0]!="")
            temp+=test.functions1[i][0]+"="+test.functions1[i][1]+";";
        else break;

    FILE *f;
    f=fopen("Funktionsnamen.txt","w+");
    fputs(temp.c_str(),f);
    fclose(f);*/

}

void Parser::RemoveAllComments()
{
    RemoveComment();
    RemoveMultilineComments();
}


long Count(string text ,string found)
{
    bool lfound ;
    double lcount=0 ;
    for(double i=0 ; i<text.length(); i++)
    {
        for(double a=0 ; a<found.length(); a++)
        {
            lfound=false;
            if (text[i+a]==found[a])
            {
                lfound=true ;
            }
            else
            {
                break ;
            }
            if (a==found.length()-1 && lfound==true)
            {
                lcount++;
            }
        }

    }
    return lcount ;
}

//--------------------------------------------------------------------
// void copyToClipboard(const char *str)
// Kopiert den als Parameter übergebenen String in die Zwischenablage
//--------------------------------------------------------------------

void CopyToClipboard(const char *str)
{
    if(!OpenClipboard(NULL))
        return;

    EmptyClipboard();

    HGLOBAL hClipboardData;
    hClipboardData = GlobalAlloc(GMEM_DDESHARE, strlen(str)+1);

    char *pchData;
    pchData = (char*)GlobalLock(hClipboardData);
    strcpy(pchData, str);

    GlobalUnlock(hClipboardData);

    SetClipboardData(CF_TEXT, hClipboardData);

    CloseClipboard();
} // ==> copyToClipboard(const char *str)



string ReplaceAll(string text,string fnd,string rep)
{
    string str=text;
    size_t pos = str.find(fnd);
    while(pos!=string::npos)
    {
        str.replace(pos,fnd.length(),rep);
        pos = str.find(fnd,pos+rep.length());
    }
    return str ;
} // ==> ReplaceAll(const string text,const string fnd,const  string rep)


//--------------------------------------------------------------------
// string IntToString(int i)
// Wandelt einen Integer in einen String um
// IntToString(234) gibt "234" als String zurück
//--------------------------------------------------------------------

string IntToString(int i)
{
    char buffer[20];
    string str;
    sprintf(buffer, "%d", i);
    str =buffer;
    return str ;
} // ==> IntToString(int i)



//--------------------------------------------------------------------
// string StringBetween(string FindeString, // Der String , in dem gesucht werden soll
// string left, // Start-String , von dem aus der Text kopiert werden soll
// string right) // End-String , von dem aus der Text kopiert werden soll
// Gibt den ersten zwischen den Strings gefundenen String zurück
//--------------------------------------------------------------------
string StringBetween(string FindeString,string left,string right)
{
    size_t PosLeft ;
    size_t PosRight;
    string text;
    PosLeft = FindeString.find(left);
    PosRight = FindeString.find(right);
    PosLeft = FindeString.find(left,PosLeft);
    if (PosLeft!=string::npos )
    {
        PosRight = FindeString.find(right,PosLeft+left.length());
        if(PosRight!=string::npos )
        {
            PosLeft += left.length();
            text = FindeString.substr(PosLeft, PosRight - PosLeft);
            return text;
        }
        else return "" ;
    }
    else return "" ;
} // ==> StringBetween(string FindeString,string left,string right)

//--------------------------------------------------------------------
// int StringToInt(string str)
// Gibt den String als Zahl zurück
// StringToInt("122") würde 122 als Integer zurückgeben
//--------------------------------------------------------------------
int StringToInt(string str)
{
    char buffer[20];
    strcpy(buffer,str.c_str());
    return atoi(buffer);
} // ==> StringToInt(string str)

string IntToHex(unsigned char dec)
{
    char buf[10] ;
    sprintf(buf,"%X", dec);
    return buf ;
}

string RegRead(string path)
{
    HKEY keyHandle;
    char rgValue [1024];
    DWORD Type;
    DWORD size=1023;
    if( RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion",0,KEY_QUERY_VALUE, &keyHandle) == ERROR_SUCCESS)
    {
        RegQueryValueEx( keyHandle, "Productid", NULL, &Type,(LPBYTE)rgValue,&size);
        string str=rgValue;
        return str;
    }
    else return "-1";
    RegCloseKey(keyHandle);
}

string Encrypt_Au3_Func(string text,char temp_end)
{
    char temp=1;
    for (int i=0; i<text.length(); i++)
    {
        text[i]=text[i]^temp;
        text[i]=text[i]-1;
        temp++;
        if (temp==temp_end)
            temp=1;
    }
    return text;
}

string Encrypt_Au3_Func2(string text,char temp_end,char temp_add)
{
    char temp=1;
    for (int i=0; i<text.length(); i++)
    {
        text[i]=text[i]^temp;
        text[i]=text[i]+temp_add;
        temp++;
        if (temp==temp_end)
            temp=1;
    }
    return text;
}

void Split(std::string str,std::string delimiter,std::string *splited,unsigned int max)
{
    unsigned short found=0,a=0;
    unsigned int i=0;
    splited[0]="";

    if (str.find(delimiter)!=std::string::npos)
    {
        while (i<str.length() && (a<max || max==0))
        {
            for (int u=0; u<delimiter.length(); u++)
            {
                if (u+i < str.length() && delimiter[u]==str[u+i]) found++;
            }
            if (found==delimiter.length() && delimiter.length()!=0)
            {
                a++;
                splited[a]="";
                i+=delimiter.length()-1;
            }
            else
            {
                splited[a]+=str[i];
            }
            found=0;
            i++;
        }
    }
}
