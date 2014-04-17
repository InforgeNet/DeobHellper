#RequireAdmin
#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseUpx=n
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****
; Author ........: Shadow992
; Modified.......: No Edit
; Version........: 1.3.8e
; Copyright by Shadow992 (www.elitepvpers.de)
#Include <GuiComboBox.au3>
#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <array.au3>
#include <file.au3>
#include <string.au3>
#Region ### START Koda GUI section ### Form=
$Form1 = GUICreate("Obfuscator by Shadow992", 569, 267, 253, 183, Default, $WS_EX_ACCEPTFILES)
GUISetBkColor(0x9DB9EB)
$Schlussel_Button = GUICtrlCreateButton("Neuen Schlüssel generieren", 416, 40, 145, 25, $WS_GROUP)
$Schlussel_Input = GUICtrlCreateInput("", 8, 40, 401, 21)
$Datei_Input = GUICtrlCreateInput("", 8, 8, 353, 21)
GUICtrlSetState($Datei_Input, $GUI_DROPACCEPTED)
$Datei_Button = GUICtrlCreateButton("Datei zum obfuscaten auswählen", 368, 8, 193, 25, $WS_GROUP)
$Label1 = GUICtrlCreateLabel("", 8, 88, 259, 113)
$Variblen_Checkbox = GUICtrlCreateCheckbox("Variablennamen obfuscaten", 288, 80, 193, 20)
GUICtrlSetFont(-1, 10, 400, 0, "MS Sans Serif")
$Funktionen_Checkbox = GUICtrlCreateCheckbox("Eigene Funktionen obfuscaten", 288, 120, 201, 20)
GUICtrlSetFont(-1, 10, 400, 0, "MS Sans Serif")
$AutoITBefehleObfuscaten_Checkbox = GUICtrlCreateCheckbox("AutoIT-Befehle obfuscaten", 288, 160, 185, 20)
GUICtrlSetFont(-1, 10, 400, 0, "MS Sans Serif")
$Hash_Combobox = GUICtrlCreateCombo("Shadowhash", 8, 208, 265, 25)
GUICtrlSetData($Hash_Combobox,"RC4|CRC32|MD5|MD5 & RC4|MD5 & CRC32|Shadowhash & RC4|CRC32 & RC4|CRC32 & Shadowhash & RC4 & MD5 ")
GUICtrlSetState($Hash_Combobox,$GUI_DISABLE)
$AutoITStarkObfuscate_Checkbox = GUICtrlCreateCheckbox("AutoIT-Befehle stark obfuscaten", 312, 184, 209, 25)
GUICtrlSetFont(-1, 10, 400, 0, "MS Sans Serif")
GUICtrlSetState($AutoITStarkObfuscate_Checkbox,$GUI_DISABLE)
$Group1 = GUICtrlCreateGroup("", 280, 144, 281, 73)
GUICtrlCreateGroup("", -99, -99, 1, 1)
$Group2 = GUICtrlCreateGroup("", 280, 104, 281, 41)
GUICtrlCreateGroup("", -99, -99, 1, 1)
$Group3 = GUICtrlCreateGroup("", 280, 64, 281, 41)
GUICtrlCreateGroup("", -99, -99, 1, 1)
$Group4 = GUICtrlCreateGroup("", 280, 216, 281, 41)
GUICtrlCreateGroup("", -99, -99, 1, 1)
$Includes_Checkbox= GUICtrlCreateCheckbox("Includes einbinden (minimiert Erroranzahl)", 288, 232, 271, 20)
$Kommentar_Checkbox=$GUI_UNCHECKED
GUICtrlSetFont(-1, 10, 400, 0, "MS Sans Serif")
$Start = GUICtrlCreateButton("Start", 8, 232, 265, 25, $WS_GROUP)
$Label2 = GUICtrlCreateLabel("© by Shadow992", 76, 64, 124, 24)
GUICtrlSetFont(-1, 12, 400, 0, "MS Sans Serif")
GUICtrlSetColor(-1, 0xFF0000)
GUISetState(@SW_SHOW)
#EndRegion ### END Koda GUI section ###
			$randT=""
			For $k=0 To Random(20,50,1)
				If Random(0,1,1)=1 Then
				$randT=$randT&chr(Random(65,90,1))
				Else
				$randT=$randT&chr(Random(97,122,1))
				EndIf
			Next
			GUICtrlSetData($Schlussel_Input,$randT)
$Zahl=1
$file=""
$write=""
$salt=Random(65,90,1)
$salt2=Random(1,999,1)
dim $kommentar[1]
dim $arrays[1]
$Zahl2=0
$key=0
$file2=0
$hash=0
$read=0
_GUICtrlComboBox_SetCurSel($Hash_Combobox,3)
HotKeySet("{F6}","Ende")
#Region Hashfunctions made by Ward (http://www.autoitscript.com/forum)
Global	$_MD5Opcode = '0xC85800005356576A006A006A008D45A850E8280000006A00FF750CFF75088D45A850E8440000006A006A008D45A850FF7510E8710700005F5E5BC9C210005589E58B4D0831C0894114894110C70101234567C7410489ABCDEFC74108FEDCBA98C7410C765432105DC21000C80C0000538B5D088B4310C1E80383E03F8945F88B4510C1E0030143103943107303FF43148B4510C1E81D0143146A40582B45F88945F4394510724550FF750C8B45F88D44031850E8A00700008D43185053E84E0000008B45F48945FC8B45FC83C03F39451076138B450C0345FC5053E8300000008345FC40EBE28365F800EB048365FC008B45102B45FC508B450C0345FC508B45F88D44031850E84D0700005BC9C21000C84000005356576A40FF750C8D45C050E8330700008B45088B088B50048B70088B780C89D021F089D3F7D321FB09D801C1034DC081C178A46AD7C1C10701D189C821D089CBF7D321F309D801C7037DC481C756B7C7E8C1C70C01CF89F821C889FBF7D321D309D801C60375C881C6DB702024C1C61101FE89F021F889F3F7D321CB09D801C20355CC81C2EECEBDC1C1C21601F289D021F089D3F7D321FB09D801C1034DD081C1AF0F7CF5C1C10701D189C821D089CBF7D321F309D801C7037DD481C72AC68747C1C70C01CF89F821C889FBF7D321D309D801C60375D881C6134630A8C1C61101FE89F021F889F3F7D321CB09D801C20355DC81C2019546FDC1C21601F289D021F089D3F7D321FB09D801C1034DE081C1D8988069C1C10701D189C821D089CBF7D321F309D801C7037DE481C7AFF7448BC1C70C01CF89F821C889FBF7D321D309D801C60375E881C6B15BFFFFC1C61101FE89F021F889F3F7D321CB09D801C20355EC81C2BED75C89C1C21601F289D021F089D3F7D321FB09D801C1034DF081C12211906BC1C10701D189C821D089CBF7D321F309D801C7037DF481C7937198FDC1C70C01CF89F821C889FBF7D321D309D801C60375F881C68E4379A6C1C61101FE89F021F889F3F7D321CB09D801C20355FC81C22108B449C1C21601F289D021F889FBF7D321F309D801C1034DC481C162251EF6C1C10501D189C821F089F3F7D321D309D801C7037DD881C740B340C0C1C70901CF89F821D089D3F7D321CB09D801C60375EC81C6515A5E26C1C60E01FE89F021C889CBF7D321FB09D801C20355C081C2AAC7B6E9C1C21401F289D021F889FBF7D321F309D801C1034DD481C15D102FD6C1C10501D189C821F089F3F7D321D309D801C7037DE881C753144402C1C70901CF89F821D089D3F7D321CB09D801C60375FC81C681E6A1D8C1C60E01FE89F021C889CBF7D321FB09D801C20355D081C2C8FBD3E7C1C21401F289D021F889FBF7D321F309D801C1034DE481C1E6CDE121C1C10501D189C821F089F3F7D321D309D801C7037D'
		$_MD5Opcode &= 'F881C7D60737C3C1C70901CF89F821D089D3F7D321CB09D801C60375CC81C6870DD5F4C1C60E01FE89F021C889CBF7D321FB09D801C20355E081C2ED145A45C1C21401F289D021F889FBF7D321F309D801C1034DF481C105E9E3A9C1C10501D189C821F089F3F7D321D309D801C7037DC881C7F8A3EFFCC1C70901CF89F821D089D3F7D321CB09D801C60375DC81C6D9026F67C1C60E01FE89F021C889CBF7D321FB09D801C20355F081C28A4C2A8DC1C21401F289D031F031F801C1034DD481C14239FAFFC1C10401D189C831D031F001C7037DE081C781F67187C1C70B01CF89F831C831D001C60375EC81C622619D6DC1C61001FE89F031F831C801C20355F881C20C38E5FDC1C21701F289D031F031F801C1034DC481C144EABEA4C1C10401D189C831D031F001C7037DD081C7A9CFDE4BC1C70B01CF89F831C831D001C60375DC81C6604BBBF6C1C61001FE89F031F831C801C20355E881C270BCBFBEC1C21701F289D031F031F801C1034DF481C1C67E9B28C1C10401D189C831D031F001C7037DC081C7FA27A1EAC1C70B01CF89F831C831D001C60375CC81C68530EFD4C1C61001FE89F031F831C801C20355D881C2051D8804C1C21701F289D031F031F801C1034DE481C139D0D4D9C1C10401D189C831D031F001C7037DF081C7E599DBE6C1C70B01CF89F831C831D001C60375FC81C6F87CA21FC1C61001FE89F031F831C801C20355C881C26556ACC4C1C21701F289F8F7D009D031F001C1034DC081C1442229F4C1C10601D189F0F7D009C831D001C7037DDC81C797FF2A43C1C70A01CF89D0F7D009F831C801C60375F881C6A72394ABC1C60F01FE89C8F7D009F031F801C20355D481C239A093FCC1C21501F289F8F7D009D031F001C1034DF081C1C3595B65C1C10601D189F0F7D009C831D001C7037DCC81C792CC0C8FC1C70A01CF89D0F7D009F831C801C60375E881C67DF4EFFFC1C60F01FE89C8F7D009F031F801C20355C481C2D15D8485C1C21501F289F8F7D009D031F001C1034DE081C14F7EA86FC1C10601D189F0F7D009C831D001C7037DFC81C7E0E62CFEC1C70A01CF89D0F7D009F831C801C60375D881C6144301A3C1C60F01FE89C8F7D009F031F801C20355F481C2A111084EC1C21501F289F8F7D009D031F001C1034DD081C1827E53F7C1C10601D189F0F7D009C831D001C7037DEC81C735F23ABDC1C70A01CF89D0F7D009F831C801C60375C881C6BBD2D72AC1C60F01FE89C8F7D009F031F801C20355E481C291D386EBC1C21501F28B4508010801500401700801780C5F5E5BC9C20800C814000053E840000000800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000008F45EC8B5D0C6A088D4310508D'
		$_MD5Opcode &= '45F850E8510000008B4310C1E80383E03F8945F483F838730B6A38582B45F48945F0EB096A78582B45F48945F0FF75F0FF75ECFF750CE831F8FFFF6A088D45F850FF750CE823F8FFFF6A1053FF7508E8050000005BC9C210005589E55156578B7D088B750C8B4D10FCF3A45F5E595DC20C00'
#EndRegion
While 1
	If $Zahl2=0 Then
	If (BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Or BitAND(GUICtrlRead ($Variblen_Checkbox),$GUI_CHECKED)=1)  Then

		GUICtrlSetState($Hash_Combobox,$GUI_ENABLE)
		$Zahl2=1
	Else
		GUICtrlSetState($Hash_Combobox,$GUI_DISABLE)
		$Zahl2=1
	EndIf
	EndIf
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			Exit
		Case $Schlussel_Button
			$randT=""
			For $k=0 To Random(20,50,1)
				If Random(0,1,1)=1 Then
				$randT=$randT&chr(Random(65,90,1))
				Else
				$randT=$randT&chr(Random(97,122,1))
				EndIf
			Next
			GUICtrlSetData($Schlussel_Input,$randT)
		Case $Schlussel_Input
		Case $Datei_Input
		Case $Datei_Button
			$file=FileOpenDialog("Select file to obfuscate","","(*.au3)",1)
			GUICtrlSetData($Datei_Input,$file)
			if FileExists (guictrlread ($Datei_Input)) Then
				guictrlsetdata ($Label1,"Zeilen : "&_FileCountLines (guictrlread ($Datei_Input))&@CRLF&@CRLF&"Größe : "&FileGetSize (guictrlread ($Datei_Input))&" B"&@CRLF&@CRLF&"Geschätzte Größe "&@CRLF&"nach dem Obfuscaten: "&@CRLF&Round((FileGetSize(guictrlread ($Datei_Input))*5)/1024,1)&" KB")
			EndIf
		Case $Variblen_Checkbox
			$Zahl2=0
		Case $Funktionen_Checkbox
			$Zahl2=0
		Case $AutoITBefehleObfuscaten_Checkbox
			If $Zahl=1 Then
				GUICtrlSetState($AutoITStarkObfuscate_Checkbox,$GUI_ENABLE)
				$Zahl=2
			Else
				GUICtrlSetState($AutoITStarkObfuscate_Checkbox,$GUI_DISABLE)
				GUICtrlSetState($AutoITStarkObfuscate_Checkbox,$GUI_UNCHECKED)
				$Zahl=1
			EndIf
		Case $Hash_Combobox
		Case $AutoITStarkObfuscate_Checkbox
		Case $Kommentar_Checkbox
		Case $Start
		If GUICtrlRead($Schlussel_Input)<>"" and GUICtrlRead($Schlussel_Input)<>" " Then
			If FileExists (guictrlread ($Datei_Input)) and _Filecountlines(guictrlread ($Datei_Input))<>0 and FileRead(guictrlread ($Datei_Input))<>"" Then
			$file=guictrlread ($Datei_Input)
			Obfuscate()
			Else
			MsgBox(0,"Ungültige Datei","Diese Datei ist ungültig oder nicht vorhanden")
			EndIf
		Else
		If _GUICtrlComboBox_GetCurSel($Hash_Combobox) = 3 or _GUICtrlComboBox_GetCurSel($Hash_Combobox) = 5 or _GUICtrlComboBox_GetCurSel($Hash_Combobox) = 2  Then
		If FileExists (guictrlread ($Datei_Input)) and _Filecountlines(guictrlread ($Datei_Input))<>0 and FileRead(guictrlread ($Datei_Input))<>"" Then
		$file=guictrlread ($Datei_Input)
		Obfuscate()
		Else
		MsgBox(0,"Ungültige Datei","Diese Datei ist ungültig oder nicht vorhanden")
		EndIf
		Else
		If (BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=0 And BitAND(GUICtrlRead ($Variblen_Checkbox),$GUI_CHECKED)=0)  Then
		If FileExists (guictrlread ($Datei_Input)) and _Filecountlines(guictrlread ($Datei_Input))<>0 and FileRead(guictrlread ($Datei_Input))<>"" Then

		$file=guictrlread ($Datei_Input)
		Obfuscate()
		Else
		MsgBox(0,"Ungültige Datei","Diese Datei ist ungültig oder nicht vorhanden")
		EndIf
		Else
		MsgBox(0,"Ungültige Zeichen","Bitte beachte , dass der Schlüssel ausschlieslich aus Buchstaben bestehen darf")
		EndIf
		EndIf

		EndIf
	EndSwitch
WEnd



Func ArrayObfuscate()
;~ #cs
_FileReadToArray($file2,$arrays)
$gros=UBound($arrays)-1
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
_ArrayAdd($arrays,"Func _"&Hash(Chr($salt)&"_Arrays_Definition_Fuction"&Chr($salt),$key,$hash)&Chr($salt)&"()")
_ArrayInsert($arrays,2,"_"&Hash(Chr($salt)&"_Arrays_Definition_Fuction"&Chr($salt),$key,$hash)&Chr($salt)&"()")
Else
_ArrayAdd($arrays,"Func _"&Chr($salt)&"_Arrays_Definition_Fuction"&Chr($salt)&"()")
_ArrayInsert($arrays,2,"_"&Chr($salt)&"_Arrays_Definition_Fuction"&Chr($salt)&"()")
EndIf
For $i=1 To $gros
If StringInStr($arrays[$i],"$")<>0 And StringInStr($arrays[$i],"[")<>0 And StringInStr($arrays[$i],"]")<>0 Then
$Ok=1

$RightArray=_StringBetween($arrays[$i],"'","'")
if IsArray($RightArray) Then
For $g=0 To UBound($RightArray)-1
if StringInStr($RightArray[$g],"$")<>0 And StringInStr($RightArray[$g],"[")<>0 And StringInStr($RightArray[$g],"]")<>0 Then
	$Ok=1
Else
	$Ok=0
EndIf
Next
EndIf

$RightArray=_StringBetween($arrays[$i],'"','"')
if IsArray($RightArray) Then
For $g=0 To UBound($RightArray)-1
if StringInStr($RightArray[$g],"$")<>0 And StringInStr($RightArray[$g],"[")<>0 And StringInStr($RightArray[$g],"]")<>0 Then
	$Ok=1
Else
	$Ok=0
EndIf
Next
EndIf

$arra=_StringBetween($arrays[$i],"[","]")
If IsArray($arra) and StringRegExp($arra[0],"(\d*)") and StringInStr($arra[0],"$")=0 And $Ok=1 Then

If StringRegExp($arrays[$i],"["&$arra[0]&"]") Then

If BitAND(GUICtrlRead ($Variblen_Checkbox),$GUI_CHECKED)=1 Then
$obfus=Chr($salt)&"_"&Chr($salt)&Hash($arra[0],$key,$hash)
Else
$obfus="_"&Chr($salt)&$arra[0]&Chr($salt)
EndIf

$arrays[$i]=StringReplace($arrays[$i],"["&$arra[0]&"]","["&"$"&$obfus&"]",1)

If BitAND(GUICtrlRead ($Variblen_Checkbox),$GUI_CHECKED)=1 Then
_ArrayAdd($arrays,"Global $"&$obfus)
_ArrayAdd($arrays,"Assign('"&$obfus&"', '"&$arra[0]&"')")
Else
_ArrayAdd($arrays,"Global $"&$obfus)
_ArrayAdd($arrays,"Assign('"&$obfus&"', '"&$arra[0]&"')")
EndIf
EndIf
EndIf
EndIf
$prozent=$i/UBound($arrays)*100
ProgressSet($prozent,"Arrays werden obfuscatet")
Next
_ArrayAdd($arrays,"Endfunc")
_FileWriteFromArray($file2,$arrays)
;~ #ce
endfunc





Func IncludesEinbinden()
$i=0
$includes=""
$prozent=0
$String=""
For $hiu=0 To 1
$i=0
$read=FileRead($file)
$read=StringStripWS ($read,8)

While StringRegExp($read,"#include<(\w+)")=1 or StringRegExp($read,'#include"(\w+)')=1
$String=""
$read=FileRead($file)
$read=StringStripWS ($read,8)
If StringInStr($read,"#include")<>0 Then
$SplitDatei=StringSplit($file,"\")
For $a=1 To $SplitDatei[0]-1
$String=$String&$SplitDatei[$a]&"\"
Next
$read=StringStripWS ($read,8)
If StringRegExp($read,"#include<")=1 Then
$between=_StringBetween ($read,"#include<",">")
Else
$between=_StringBetween ($read,'#include"','"')
EndIf
If IsArray($between) Then
$String=$String&$between[0]
$String=StringReplace($String,">","")
$String=StringReplace($String,'"',"")
If FileExists($String) Then
$read=StringReplace($read,$between[0],FileRead($String))
Else
If FileExists(RegRead("HKEY_LOCAL_MACHINE\SOFTWARE\AutoIt v3\AutoIt","InstallDir")&"\Include\String.au3") Then
$read=StringStripWS ($read,8)
	$String=StringReplace($String,"<","")
	$file3=RegRead("HKEY_LOCAL_MACHINE\SOFTWARE\AutoIt v3\AutoIt","InstallDir")&"\Include\"&$between[0]
	if FileExists($file3)=0 Then
		$file3=RegRead("HKEY_LOCAL_MACHINE\SOFTWARE\AutoIt v3\AutoIt","InstallDir")&"\Include\"&_StringProper($between[0])
	Else
	$read=StringStripWS ($read,8)
	$between[0]=StringStripWS($between[0],8)
	if FileExists($file3) Then
	If StringInStr($includes,$between[0])=0 Then
	$includes=$includes&" "&$between[0]
	_ReplaceStringInFile($file,"#include<"&$between[0]&">",FileRead($file3),0,0)
	_ReplaceStringInFile($file,"#include <"&$between[0]&">",FileRead($file3),0,0)
	_ReplaceStringInFile($file,"#include  <"&$between[0]&">",FileRead($file3),0,0)
	_ReplaceStringInFile($file,'#include"'&$between[0]&'"',FileRead($file3),0,0)
	_ReplaceStringInFile($file,'#include "'&$between[0]&'"',FileRead($file3),0,0)
	_ReplaceStringInFile($file,'#include  "'&$between[0]&'"',FileRead($file3),0,0)
	_ReplaceStringInFile($file,'#include-once',"")
	$i=$i+1
	Else


	_ReplaceStringInFile($file,"#include<"&$between[0]&">","")
	_ReplaceStringInFile($file,"#include <"&$between[0]&">","")
	_ReplaceStringInFile($file,"#include  <"&$between[0]&">","")
	_ReplaceStringInFile($file,'#include"'&$between[0]&'"',"")
	_ReplaceStringInFile($file,'#include "'&$between[0]&'"',"")
	_ReplaceStringInFile($file,'#include  "'&$between[0]&'"',"")
	_ReplaceStringInFile($file,'#include-once',"")
	$i=$i+1
EndIf
EndIf
_ArrayDelete($between,0)
EndIf
EndIf
EndIf
EndIf
Else
$read2=$read
EndIf


$counter=StringRegExp($read,"#include<(\w+)",3)
$counter2=StringRegExp($read,'#include"(\w+)',3)
$gesamt=$i+UBound($counter)+UBound($counter2)
$prozent=($i/$gesamt)*100
ProgressSet($prozent,"Includes einbinden"&@CRLF&"Übrige Includes "&UBound($counter))

WEnd
Next
$read=FileRead($file)
_FileCreate($file)
FileClose($file)
FileWrite($file,$read)
EndFunc




Func KommentareEntfernen()
_FileReadToArray($file,$kommentar)


$grose=UBound($kommentar)-1
For $i=1 to $grose
$prozent=$i/$grose*100
ProgressSet($prozent,"Kommentare werden entfernt "&@CRLF&"momentane Zeile : "&$i&" von "&$grose)
If $grose<>$i Then
If $kommentar[$i]="" or $kommentar[$i]=" " Then
_ArrayDelete($kommentar,$i)
$grose=$grose-1
$i=$i-1
EndIf
if StringInStr(StringStripWS($kommentar[$i],8),";")= 1 Then
;~ _ReplaceStringInFile($file,$kommentar[$i],"",1,0)
_ArrayDelete($kommentar,$i)
$grose=$grose-1
$i=$i-1
Else
if StringInStr(StringStripWS($kommentar[$i],8),";~")= 1 Then
;~ _ReplaceStringInFile($file,$kommentar[$i],"",1,0)
_ArrayDelete($kommentar,$i)
$grose=$grose-1
$i=$i-1
endif
endif


;~ #cs
If StringInStr($kommentar[$i],"#cs",1)=1 Then
do
_ArrayDelete($kommentar,$i)
$grose=$grose-1
Until $i=$grose-2 or StringRegExp($kommentar[$i],"#ce")
If StringRegExp($kommentar[$i],"#ce") Then
_ArrayDelete($kommentar,$i)
$i=$i-1
$grose=$grose-1
EndIf
EndIf
;~ #ce
If StringInStr($kommentar[$i],";")<>0 Then
	$komm2=StringStripWS($kommentar[$i],8)
	$aaaa=0
	$len=StringLen($kommentar[$i])
	Do
		$aaaa+=1
		$komm3=StringRight ($komm2,$aaaa)
		If $len<=$aaaa Then ExitLoop
	Until StringInStr(StringStripWS($komm3,8),'";')=2 Or StringInStr(StringStripWS($komm3,8),");")=2 or StringInStr(StringStripWS($komm3,8),"';")=2
	If $len>$aaaa Then
	$kommentar[$i]=StringTrimRight($kommentar[$i],$aaaa)
	EndIf
EndIf

If StringInStr(StringStripWS($kommentar[$i],8),"EndFunc;",2)=1 Then
$kommentar[$i]="EndFunc"
Endif


Else
ExitLoop
EndIf
Next

_FileCreate($file)
FileClose($file)
_FileWriteFromArray($file,$kommentar,1)



EndFunc




Func Obfuscate() ;---> Funktionsanfang Obfuscate()
ProgressOn("Obfuscate","Fortschritt :")
$save=FileRead($file)
$file4=StringTrimRight($file,4)&"-Sicherheitskopie.au3"
_FileCreate($file4)
FileClose($file4)
FileWrite($file4,$save)

KommentareEntfernen()
$prozent=0
ProgressSet($prozent)
if BitAND(GUICtrlRead ($Includes_Checkbox),$GUI_CHECKED)=1 Then
IncludesEinbinden()
EndIf
$hash=_GUICtrlComboBox_GetCurSel($Hash_Combobox)
#Region FileOpen
Dim $functions[1]
If $file="" or $file=1 Then
Exit
EndIf
$schlussel=GUICtrlRead($Schlussel_Input)
#EndRegion

#Region File erstellen
$file2=StringTrimRight($file,4)
$file2=$file2&"-obfuscated.au3"
_FileCreate($file2)
FileClose($file2)
#EndRegion

if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
If StringInStr(FileRead($file),"Func Quersumme($zahl)"&@CRLF&"local $split")=0 Then
$befehl=@CRLF & _
"Func Quersumme($zahl)" &@CRLF & _
'local $split=StringSplit($zahl,"")'&@CRLF & _
"$zahl=0"&@CRLF & _
"For $i=1 To UBound($split)-1"&@CRLF & _
"$zahl=$zahl+$split[$i]"&@CRLF & _
"Next"&@CRLF & _
"return $zahl"&@CRLF & _
"EndFunc"
FileWrite($file,$befehl)
EndIf
EndIf
#Region Suchen nach Funktionen und hinzufügen zum Array $functions (wird später gebraucht)

KommentareEntfernen()
for $i=0 to _FileCountLines($file)
$prozent=($i/_FileCountLines($file))*100
ProgressSet($prozent,"Funktionen werden gesucht")
$prozent=0
$read=FileReadLine($file,$i)
$read=StringStripWS ($read,1)
If IsArray(_StringBetween($read,"func" & chr(32),"(")) Then
	$temp = _StringBetween($read,"func" & chr(32),"(")
	$temp[0]=StringStripWS($temp[0],8)
	_ArrayAdd($functions,$temp[0]&"(")
;~ 	$temp2=_StringBetween($read,"func","(")
;~ 	$temp2=StringStripWS ($temp2,8)
;~ 	StringReplace($temp2&"(",$temp2&"("," _" & Hash($temp[0],$schlussel,$hash)&"(")

If IsArray($functions) Then
If $functions[0]="" or $functions[0]=" " Then
_ArrayDelete($functions,0)
EndIf
EndIf
EndIf
#EndRegion
#Region Variablen werden mit Hash ersetzt
$befehl=$read
$read = $read&";"
	If StringRegExp($read,"(.*\x24\w+.*)") == 1 Then
		$temp = StringRegExp($read,"(\x24\w*)",3)
	if BitAND(GUICtrlRead ($Variblen_Checkbox),$GUI_CHECKED)=1 Then
		For $a = 0 to UBound($temp) -1 Step 1
			$temp[$a] = StringTrimLeft($temp[$a],1)
					$read = StringRegExpReplace($read,"\x24" & $temp[$a] & "(\W)","$_" & Hash($temp[$a],$schlussel,$hash)& "\1",$hash)
		$prozent=($a/UBound($temp))*100-1
		ProgressSet($prozent,"Variablen werden gehasht")
		Next
	EndIf
		EndIf
$read=StringTrimRight($read,1)

FileWrite($file2,$read&@CRLF)
Next
#EndRegion
#Region Funktionen im ganzen Skript , die im Array $functions sind , werden nun im ganzen Skript durch Hashes ersetzt
FileOpen($file2,1)
$read=FileRead($file2)
$read=StringStripWS ($read,2)
_filecreate($file2)
FileClose($file2)

if BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
For $hj = 0 to UBound($functions) -1 Step 1
	$prozent=int(($hj/UBound($functions))*100)
	ProgressSet($prozent,"Funktionen werden durch Hashes ersetzt")
	If $functions[0]<>"" and $functions[0]<>" " Then
;~ 		$read = StringReplace($read ,$functions[$hj],"_" & Hash($functions[$hj],$schlussel,$hash)&"(")
		$read=StringReplace($read," (","(")
		$read = StringReplace($read ,$functions[$hj],"_" & Hash($functions[$hj],$schlussel,$hash)&"(")
		$read = StringReplace($read ,"'"&StringTrimRight($functions[$hj],1)&"'","'"&"_" & Hash($functions[$hj],$schlussel,$hash)&"'")
		$read = StringReplace($read ,'"'&StringTrimRight($functions[$hj],1)&'"','"'&"_" & Hash($functions[$hj],$schlussel,$hash)&'"')

	EndIf
Next
EndIf
FileWrite($file2,$read)


#EndRegion
#Region Die restlichen AutoIT Befehle werden ersetzt
Dim $read[_FileCountLines($file2)+3]
for $i=0 to _FileCountLines($file2)
$read[$i]=FileReadLine($file2,$i)
Next
$count=_FileCountLines($file2)
$splitstring=""
$write=""
$read4=FileRead($file2)

#Region Strings werden durch Variablen ersetzt
If BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1  Then
_ArrayAdd($read,"Func _"&Chr($salt)&Hash(Chr($salt)&'_Variable1Definition2Function3',$schlussel,$hash)&"()")
Else
_ArrayAdd($read,"Func _"&Chr($salt)&"_"&Chr($salt)&'_Variable_Definition_Function'&"()")
EndIf
$count=_FileCountLines($file2)
for $i=0 to $count
$splitstring=""
$prozent=int(($i/$count)*100)
ProgressSet($prozent,"Strings werden durch Variablen ersetzt")


For $iiii=0 To 1
$temp3=StringInStr($read[$i],"'")
$temp4=StringInStr($read[$i],'"')



If $temp4 < $temp3 Or $temp3=0 Then
$betw=_StringBetween($read[$i],'"','"')
ElseIf $temp3 < $temp4 Or $temp4=0 Then
$betw=_StringBetween($read[$i],"'","'")
EndIf


;~ 	ProgressOff()
;~ MsgBox(0,"test","Read : "&$read[$i]&@CRLF&"Temp4 : "&$temp4&@CRLF&"Temp3 : "&$temp3)

if IsArray($betw) Then

if $betw[0]<>"" and StringLen($betw[0])<250 Then
$betw2=StringStripWS($betw[0],8)
$betw2=StringRegExpReplace ($betw2, "(\W)",$i&chr($salt))

$var4="$"&Chr($salt)&"_"&Hash(Chr($salt)&$betw2&'_constZeichenString1',$schlussel,3)
_ArrayAdd($read,"Global "&$var4)
If $temp4 < $temp3 Then
_ArrayAdd($read,'Assign("'&StringTrimLeft($var4,1)&'", "'&$betw[0]&'")')
Else
_ArrayAdd($read,"Assign('"&StringTrimLeft($var4,1)&"', '"&$betw[0]&"')")
EndIf



If $temp4 < $temp3 Or $temp3=0 Then
$read[$i]=StringReplace($read[$i],'"'&$betw[0]&'"'," "&$var4&" ")
;~ MsgBox(0,"test",'"'&$betw[0]&'"')
ElseIf $temp3 < $temp4 Or $temp4=0 Then
	$read[$i]=StringReplace($read[$i],"'"&$betw[0]&"'"," "&$var4&" ")
	;~ MsgBox(0,"test","'"&$betw[0]&"'")
EndIf



EndIf

EndIf
next
$count=_FileCountLines($file2)
Next
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
_ArrayInsert($read,2,"_"&Chr($salt)&Hash(Chr($salt)&'_Variable1Definition2Function3',$schlussel,$hash)&"()")
Else
_ArrayInsert($read,2,"_"&Chr($salt)&"_"&Chr($salt)&'_Variable_Definition_Function'&"()")
EndIf

_ArrayAdd($read,"EndFunc")
_FileWriteFromArray($file2,$read,1)
EndIf
#EndRegion

if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
ArrayObfuscate()
EndIf


ReDim $read[_FileCountLines($file2)+3]
for $i=0 to _FileCountLines($file2)
$read[$i]=FileReadLine($file2,$i)
Next

$prozent=$prozent+10
$cou=_FileCountLines($file2)
_ArrayDelete($read,0)
_ArrayDelete($read,0)
_filecreate($file2)
FileOpen($file2,1)
for $i=0 to $cou
$prozent=($i/$cou)*100
ProgressSet($prozent,"AutoIT-Befehle werden obfuscatet")
$read[$i]=StringStripWS ($read[$i],4)
$befehl=$read[$i]&@CRLF
$split=StringSplit($read[$i],"")
If $split[0]>=4 Then
$test=$split[1]&$split[2]&$split[3]&$split[4]
If ($split[1] <> "$") and ($split[1]&$split[2] <> "if") and ($split[1]&$split[2] <> "do") and $split[1] <> "" and $split[1] <> "#" and $split[1] <> ";" and $test<>"case" and $test<>"func" and $test<>"next" and $test<>"whil" and ($split[1]&$split[2]&$split[3]<>"for") and  $test<>"sele" and  $test<>"swit" and $test<>"ends" and $test<>"endi" and $test<>"endf" and $test<>"unti" and $test<>"else" and $test<>"redi" and $test<>"dim " and $test<>"loca" and $test<>"glob" and $test<>"exit" and $test<>"wend" and $test<>"retu" Then


If StringinStr($read[$i],",_")<>0 Or StringinStr($read[$i]," _")<>0 Or StringinStr($read[$i],"&_")<>0 Or StringLen($read[$i])>250 Then
$befehl=$read[$i]&@CRLF
Else

$var2=StringToBinary($read[$i])
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"3",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"1",'"&Stringlen("'&chr(Random(97,122,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"2",'"&Stringlen("'&chr(Random(97,122,1))&chr(Random(65,90,1))&'")&"',Random(2,4,1))
$var2=StringReplace($var2,"7",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,5,1))
$var2=StringReplace($var2,"4",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))




$if=random(0,4,1)
If $if=0 Then
$ran=Random(10,99,1)
$test=BitXOR(8,$ran)
$var3=StringTobinary('BitXOR('&$test&','&$ran&')')
$var2=StringReplace($var2,"8",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"',Random(2,6,1))
ElseIf $if=1 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&" Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Elseif $if=2 Then
$ran5=Random(1,100000)
$var3=StringTobinary('int(Cos(Sin ('&$ran5&'))^-1)')
$var2=StringReplace($var2,"1",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"')
Elseif $if=3 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&" Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Else
$var2ran1=Random(1,9,1)
$var2ran2=Random(1,9,1)
$var2=StringReplace($var2,"8",'"&('&$var2ran1&'+'&$var2ran2&')^2-'&($var2ran2+$var2ran1)^2-8&'&"',Random(1,3,1))
EndIf
$var2=StringReplace($var2,'&""&',"&")
EndIf
if BitAND(GUICtrlRead ($AutoITBefehleObfuscaten_Checkbox),$GUI_CHECKED)=1 Then
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
If StringLen($var2)<35 Then
$var2=StringToBinary('Execute('&"'"&'BinaryToString("'&$var2&'")'&"'"&')')
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"3",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"1",'"&Stringlen("'&chr(Random(97,122,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"2",'"&Stringlen("'&chr(Random(97,122,1))&chr(Random(65,90,1))&'")&"',Random(2,4,1))
$var2=StringReplace($var2,"7",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,5,1))
$var2=StringReplace($var2,"4",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))

$if=random(0,4,1)
If $if=0 Then
$ran=Random(10,99,1)
$test=BitXOR(8,$ran)
$var3=StringTobinary('BitXOR('&$test&','&$ran&')')
$var2=StringReplace($var2,"8",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"',Random(2,6,1))
ElseIf $if=1 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&"Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Elseif $if=2 Then
$ran5=Random(1,100000)
$var3=StringTobinary('int(Cos(Sin ('&$ran5&'))^-1)')
$var2=StringReplace($var2,"1",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"')
Elseif $if=3 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&" Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Else
$var2ran1=Random(1,9,1)
$var2ran2=Random(1,9,1)
$var2=StringReplace($var2,"8",'"&('&$var2ran1&'+'&$var2ran2&')^2-'&($var2ran2+$var2ran1)^2-8&'&"',Random(1,3,1))
EndIf
$var2=StringReplace($var2,'&""&',"&")
EndIf
EndIf
EndIf
$befehl=StringReplace($read[$i],$read[$i],'Execute(BinaryToString("'&$var2&'"))'&@CRLF)


EndIf
EndIf
Else
If ($split[1]&$split[2] <> "if") and ($split[1]&$split[2] <> "do") and $test<>"case" and $split[1] <> "" and $split[1] <> "#" and $split[1] <> ";"and $test<>"func" and $test<>"next" and $test<>"whil" and ($split[1]&$split[2]&$split[3]<>"for") and  $test<>"sele" and  $test<>"swit" and $test<>"ends" and $test<>"endi" and $test<>"endf" and $test<>"unti" and $test<>"else" and $test<>"redi" and $test<>"dim " and $test<>"loca" and $test<>"glob" and $test<>"exit" and $test<>"wend" and $test<>"retu" Then
If StringRegExp($read[$i],"=")=1  Then
If StringinStr($read[$i],",_")<>0 Or StringinStr($read[$i],"&_")<>0 Or StringinStr($read[$i]," _")<>0 Or StringLen($read[$i])>1600 Then
$befehl=$read[$i]&@CRLF
Else
$StringSplit=StringSplit($read[$i],"=")
$var2=StringToBinary($StringSplit[2])
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"3",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"1",'"&Stringlen("'&chr(Random(97,122,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"2",'"&Stringlen("'&chr(Random(97,122,1))&chr(Random(65,90,1))&'")&"',Random(2,4,1))
$var2=StringReplace($var2,"7",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,5,1))
$var2=StringReplace($var2,"4",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))

$if=random(0,4,1)
If $if=0 Then
$ran=Random(10,99,1)
$test=BitXOR(8,$ran)
$var3=StringTobinary('BitXOR('&$test&','&$ran&')')
$var2=StringReplace($var2,"8",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"',Random(2,6,1))
ElseIf $if=1 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&"Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Elseif $if=2 Then
$ran5=Random(1,100000)
$var3=StringTobinary('int(Cos(Sin ('&$ran5&'))^-1)')
$var2=StringReplace($var2,"1",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"')
Elseif $if=3 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&" Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Else
$var2ran1=Random(1,9,1)
$var2ran2=Random(1,9,1)
$var2=StringReplace($var2,"8",'"&('&$var2ran1&'+'&$var2ran2&')^2-'&($var2ran2+$var2ran1)^2-8&'&"',Random(1,3,1))
EndIf
$var2=StringReplace($var2,'&""&',"&")
EndIf

if BitAND(GUICtrlRead ($AutoITBefehleObfuscaten_Checkbox),$GUI_CHECKED)=1 Then
If StringinStr($read[$i],",_")<>0 Or StringinStr($read[$i],"&_")<>0  Then
$befehl=$read[$i]&@CRLF
Else
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
If StringLen($var2)< 35 Then

$var2=StringToBinary('Execute('&"'"&'BinaryToString("'&$var2&'")'&"'"&')')
if BitAND(GUICtrlRead ($AutoITStarkObfuscate_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"3",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"1",'"&Stringlen("'&chr(Random(97,122,1))&'")&"',Random(1,3,1))
$var2=StringReplace($var2,"2",'"&Stringlen("'&chr(Random(97,122,1))&chr(Random(65,90,1))&'")&"',Random(2,4,1))
$var2=StringReplace($var2,"7",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,5,1))
$var2=StringReplace($var2,"4",'"&Stringlen("'&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&chr(Random(65,90,1))&'")&"',Random(1,3,1))
$if=random(0,4,1)
If $if=0 Then
$ran=Random(10,99,1)
$test=BitXOR(8,$ran)
$var3=StringTobinary('BitXOR('&$test&','&$ran&')')
$var2=StringReplace($var2,"8",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"',Random(2,6,1))
ElseIf $if=1 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&"Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Elseif $if=2 Then
$ran5=Random(1,100000)
$var3=StringTobinary('int(Cos(Sin ('&$ran5&'))^-1)')
$var2=StringReplace($var2,"1",""&'"'&"&Execute(Binarytostring('"&$var3&"'))&"&'"')
Elseif $if=3 Then
If ($split[1] <> "$") Then
$ran1=Random(1,10,1)
If BitAND(GUICtrlRead ($Funktionen_Checkbox),$GUI_CHECKED)=1 Then
$var2=StringReplace($var2,"4",'"&Execute("_'&Hash("Quersumme(",$schlussel,$hash)&'('&$ran1&'*9)-5")&"',Random(1,4,1))
Else
$var2=StringReplace($var2,"4",'"&Execute("'&"Quersumme"&'('&$ran1&'*9)-5")&"',Random(1,4,1))
EndIf
EndIf
Else
$var2ran1=Random(1,9,1)
$var2ran2=Random(1,9,1)
$var2=StringReplace($var2,"8",'"&('&$var2ran1&'+'&$var2ran2&')^2-'&($var2ran2+$var2ran1)^2-8&'&"',Random(1,3,1))
EndIf
$var2=StringReplace($var2,'&""&',"&")
EndIf
EndIf
EndIf
$read[$i]=$StringSplit[1]&"="&StringReplace($StringSplit[2],$StringSplit[2],'Execute(BinaryToString("'&$var2&'"))')
EndIf
EndIf
EndIf
Else
$befehl=$read[$i]&@crlf
EndIf
EndIf
$befehl=$read[$i]&@crlf
EndIf
If ($split[1] = ";") Then
$befehl=StringReplace($read[$i],$read[$i],"")
EndIf
Else
$befehl=$read[$i]&@crlf
EndIf
FileWrite($file2,$befehl)


If StringinStr($read[$i],",_")<>0 or StringinStr($read[$i],"&_")<>0 or StringinStr($read[$i]," _")<>0 Then
do
$i=$i+1
$befehl=$read[$i]&@CRLF
FileWrite($file2,$befehl)
Until (StringinStr($read[$i],",_")=0 and StringinStr($read[$i],"&_")=0 and StringinStr($read[$i]," _")=0) or $i=UBound($read)-1
EndIf

#EndRegion
Next
FileWrite($file2,$befehl)
FileClose($file2)
FileClose($file)
ProgressOff()
MsgBox(0,"Finished","Obfuscation succesed")
EndFunc ;---> Funktionsende Obfuscate()


Func Hash($var,$key="Thunder",$hash=0) ;---> Funktionsanfang Hash($var,$key,$hash)
$var=chr($salt)&"_"&chr($salt)&$var&$salt2&chr($salt)
$String=$var

If $hash=0 Then
$String=ShadowHash($var,$key)
ElseIf $hash=1 Then
$String=_RC4($var, $key)
ElseIf $hash=2 Then
$String=_CRC32($var)
ElseIf $hash=3 Then
$String=_MD5($var)
ElseIf $hash=4 Then
$String=_MD5($var)
$String=_RC4($String, $key)
ElseIf $hash=5 Then
$String=_MD5($var)
$String=_CRC32($String)
ElseIf $hash=6 Then
$String=ShadowHash($var,$key)
$String=_RC4($String, $key)
ElseIf $hash=7 Then
$String=_CRC32($var)
$String=_RC4($String, $key)
ElseIf $hash=8 Then
$String=_CRC32($var)
$String=ShadowHash($String,$key)
$String=_RC4($String, $key)
$String=_MD5($String)

EndIf

$String=Chr($salt)&$String
Return $String
EndFunc ;---> Funktionsende Hash($var,$key,$hash)

Func ShadowHash($var,$key)
	$StrSpl=StringSplit($var,"")
	$String=0
	$tes=0
	$StrSpl2=StringSplit($key,"")
For $c=1 To $StrSpl2[0]-1
	$tes=$tes+Asc($StrSpl2[$c])
Next
For $b=1 To $StrSpl[0]-1
	$StrSpl[$b]=Asc($StrSpl[$b])
	$String=BitXOr(BitXOR(($String+BitXOR(Mod($StrSpl[$b]^$b,$b^$StrSpl[$b]),(5^0.5-1)/2))*Int($b/2),$StrSpl[$b]),1+((5^0.5-1)/2))-(($StrSpl2[0]+$tes+$salt2))
next
If $StrSpl[1]="a" or $StrSpl[1]="e" or $StrSpl[1]="u" or $StrSpl[1]="i" Then $String=$String&$tes
$String=_StringToHex($String)
$String="DE"&$String&"DE"
Return $String
EndFunc

#Region Hashfunctions made by Ward (http://www.autoitscript.com/forum)
Func _RC4($Data, $Key)
	Local $Opcode = "0xC81001006A006A005356578B551031C989C84989D7F2AE484829C88945F085C00F84DC000000B90001000088C82C0188840DEFFEFFFFE2F38365F4008365FC00817DFC000100007D478B45FC31D2F775F0920345100FB6008B4DFC0FB68C0DF0FEFFFF01C80345F425FF0000008945F48B75FC8A8435F0FEFFFF8B7DF486843DF0FEFFFF888435F0FEFFFFFF45FCEBB08D9DF0FEFFFF31FF89FA39550C76638B85ECFEFFFF4025FF0000008985ECFEFFFF89D80385ECFEFFFF0FB6000385E8FEFFFF25FF0000008985E8FEFFFF89DE03B5ECFEFFFF8A0689DF03BDE8FEFFFF860788060FB60E0FB60701C181E1FF0000008A840DF0FEFFFF8B750801D6300642EB985F5E5BC9C21000"
	Local $CodeBuffer = DllStructCreate("byte[" & BinaryLen($Opcode) & "]")
	DllStructSetData($CodeBuffer, 1, $Opcode)

	Local $Buffer = DllStructCreate("byte[" & BinaryLen($Data) & "]")
	DllStructSetData($Buffer, 1, $Data)

	DllCall("user32.dll", "none", "CallWindowProc", "ptr", DllStructGetPtr($CodeBuffer), _
													"ptr", DllStructGetPtr($Buffer), _
													"int", BinaryLen($Data), _
													"str", $Key, _
													"int", 0)

	Local $Ret = DllStructGetData($Buffer, 1)
	$Buffer = 0
	$CodeBuffer = 0
	Return $Ret
EndFunc

Func _CRC32($Data, $CRC32 = -1)
	Local $Opcode = '0xC800040053BA2083B8EDB9000100008D41FF516A0859D1E8730231D0E2F85989848DFCFBFFFFE2E78B5D088B4D0C8B451085DB7416E3148A1330C20FB6D2C1E80833849500FCFFFF43E2ECF7D05BC9C21000'

	Local $CodeBuffer = DllStructCreate("byte[" & BinaryLen($Opcode) & "]")
	DllStructSetData($CodeBuffer, 1, $Opcode)

	Local $Input = DllStructCreate("byte[" & BinaryLen($Data) & "]")
	DllStructSetData($Input, 1, $Data)

	Local $Ret = DllCall("user32.dll", "uint", "CallWindowProc", "ptr", DllStructGetPtr($CodeBuffer), _
													"ptr", DllStructGetPtr($Input), _
													"int", BinaryLen($Data), _
													"uint", $CRC32, _
													"int", 0)

	$Input = 0
	$CodeBuffer = 0

Return $Ret[0]
EndFunc

Func _MD5($Data)
	Local $CodeBuffer = DllStructCreate("byte[" & BinaryLen($_MD5Opcode) & "]")
	DllStructSetData($CodeBuffer, 1, $_MD5Opcode)

	Local $Input = DllStructCreate("byte[" & BinaryLen($Data) & "]")
	DllStructSetData($Input, 1, $Data)

	Local $Digest = DllStructCreate("byte[16]")

	DllCall("user32.dll", "none", "CallWindowProc", "ptr", DllStructGetPtr($CodeBuffer), _
													"ptr", DllStructGetPtr($Input), _
													"int", BinaryLen($Data), _
													"ptr", DllStructGetPtr($Digest), _
													"int", 0)

	Local $Ret = DllStructGetData($Digest, 1)
	$Input = 0
	$Digest = 0
	$CodeBuffer = 0
	Return $Ret
EndFunc
#EndRegion

Func _StringBetweenReplace($string,$start,$end,$replacestring,$replace_times=0,$casesensitive=0)
	If $casesensitive=0 Then
		$casesensitive_between=-1
	Else
		$casesensitive_between=$casesensitive
	EndIf
	$string_found=_StringBetween($string,$start,$end,$casesensitive_between)
	If IsArray($string_found) Then
		$string_end=StringReplace($string,$string_found[0],$replacestring,$replace_times,$casesensitive)
	Else
		$string_end=-1
	EndIf
	Return $string_end
EndFunc

Func Ende()
	Exit
EndFunc
Func _StringAdd($string,$searchpattern,$add,$sre = 0)
	$string = StringSplit($string,"",2)
	If $searchpattern == "" Then
		Return _ArrayToString($string,$add)
	Else
		If $sre = 1 Then
			If $add = "" Then
				$add = "."
			EndIf
			StringRegExpReplace($string,$searchpattern,$searchpattern & $add)
		Else
			StringReplace($string,$searchpattern,$searchpattern & $add)
		EndIf
		Return $string
	Endif
	Return -1
EndFunc
