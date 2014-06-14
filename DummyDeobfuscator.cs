using System;
using System.Text.RegularExpressions;

namespace DeobHellper
{
	
	/*
 		*  Old, not used anymore.
	
	public class DummyDeobfuscator
	{
		public static string Deobfuscate(string source, DummyOptions options)
		{
			string ret;
			
			ret = source;
			
			if(options.ResolveEB2S)
				ResolveEB2S(ref ret);
			if(options.ResolveStartRegister)
				ResolveStartRegister(ref ret);
			if(options.RenameFunctions)
				RenameFunctions(ref ret);
			if(options.ResolveExternalArrayVars)
				ResolveExternalArrayVars(ref ret, options.REVOptions);
			
			return ret;
		}
				
		private static void RenameFunctions(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, @"^Func (\w+)\(.*\)", RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			for(int i = 0; i < toDo.Count; i++) {
				string replace;
				
				replace = Regex.Escape(String.Format("{0}(",toDo[i].Groups[1].Value));
				source = Regex.Replace(source, replace, String.Format("method{0}(", i), RegexOptions.IgnoreCase);
			}
		}
		
		private static void ResolveEB2S(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, "Execute\\(BinaryToString\\((\"|')0x[\\dA-F]+(\"|')\\)\\)", RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			for(int i = 0; i < toDo.Count; i++) {
				string workingOn;
				Match lastMatch;
				
				workingOn = toDo[i].Value;
				
				while((lastMatch = Regex.Match(workingOn, "Execute\\(BinaryToString\\((\"|')(0x[\\dA-F]+)(\"|')\\)\\)", RegexOptions.IgnoreCase)).Success)
				{
					workingOn = AutoShit.BinaryToString(lastMatch.Groups[2].Value);
				}
				
				source = source.Replace(toDo[i].Value, workingOn);
			
			}
			
		}
		
		private static void ResolveStartRegister(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, "#OnAutoItStartRegister +\"(\\w+)\"");
			
			for(int i = 0; i < toDo.Count; i++) {
				string function;
				
				function = toDo[i].Groups[1].Value;
				
				source = source.Replace(toDo[i].Value, function + "()");
			}
		}
		
		private static void ResolveExternalArrayVars(ref string source, ResolveExternalArrayVars options)
		{
			string[] values;
			string attach, tblSource, separator, arrayName, fileName, cryptMethodName;
			bool saveInFile, resolveAsciiCrypt;
			MatchCollection coll;
			
			tblSource = options.TblSource;
			separator = options.Separator;
			arrayName = options.ArrayName;		
			saveInFile = options.SaveInFile;	
			fileName = options.FileName;
			resolveAsciiCrypt = options.ResolveAsciiCrypt;
			cryptMethodName = options.CryptMethodName;
			
			values = tblSource.Split(new string[] {separator}, StringSplitOptions.RemoveEmptyEntries);
			attach = String.Format("Global ${0}[{1}]\r\n\r\n", arrayName, values.Length+1);
			
			for(int i = 0; i < values.Length; i++){
				if(resolveAsciiCrypt) {
					string tmp;
					
					tmp = AutoShit.BinaryToString(values[i], false);
					attach += String.Format("${0}[{1}]=\"{2}\"\r\n", arrayName, i+1, tmp);
					
					source = source.Replace(String.Format("{0}(${1}[{2}])", cryptMethodName, arrayName, i), String.Format("${0}[{1}]", arrayName, i));
				} else {
					attach += String.Format("${0}[{1}]=\"{2}\"\r\n", arrayName, i+1, values[i]);
				}
			}
			
			attach += "\r\n";
			
			if(resolveAsciiCrypt) {
				coll = Regex.Matches(source, String.Format("{0}\\((\"|')([\\dA-F]+)(\"|')\\)", cryptMethodName), RegexOptions.Multiline | RegexOptions.IgnoreCase);
				for(int i = 0; i < coll.Count; i++)
				{
					string tmp;
					
					tmp = AutoShit.BinaryToString(coll[i].Groups[2].Value, false);
					source = source.Replace(coll[i].Value, String.Format("\"{0}\"", tmp));
				}
			}
			
			if(saveInFile) {
				System.IO.File.WriteAllText(fileName, attach);
				attach = String.Format("#include \"{0}\"\r\n", fileName);
			}
			
			source = attach + source;
		}
	}
	
	public struct DummyOptions
	{
		public bool RenameFunctions;
		public bool ResolveEB2S;
		public bool ResolveStartRegister;
		public bool ResolveExternalArrayVars;
		public ResolveExternalArrayVars REVOptions;
		
	}
	
	public struct ResolveExternalArrayVars
	{
		public string TblSource;
		public string Separator;
		public string ArrayName;
		public bool SaveInFile;
		public string FileName;
		public bool ResolveAsciiCrypt;
		public string CryptMethodName;
	}
	*/
}
