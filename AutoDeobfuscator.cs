using System;
using System.Text.RegularExpressions;

namespace DeobHellper
{
	public class AutoDeobfuscator
	{
		public static string Deobfuscate(string source, string tblSource)
		{
			string ret;
			
			ret = source;
			RenameFunctions(ref ret);
			ResolveEB2S(ref ret);
			RemoveArrayObfuscation(ref ret, tblSource);
			CompactCode(ref source);
			ResolveNumbers(ref ret);
			ResolveExecute(ref ret);
			InsertCredits(ref ret);
			
			return ret;
		}
		
		private static void CompactCode(ref string source)
		{
			// TODO aka neverdo.
		}
		
		private static void ResolveNumbers(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, "Number\\((\"|') (\\w+) (\"|')\\)", RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			foreach(Match tmp in toDo) {
				source = source.Replace(tmp.Value, tmp.Groups[2].Value);
			}
			
		}
		
		private static void ResolveExecute(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, "Execute\\((\"|') (\\w+) (\"|')\\)", RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			foreach(Match tmp in toDo) {
				source = source.Replace(tmp.Value, tmp.Groups[2].Value);
			}
		}
		
		private static void RenameFunctions(ref string source)
		{
			MatchCollection toDo;
			
			toDo = Regex.Matches(source, @"^Func (\w+)\(.*\)", RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			for(int i = 0; i < toDo.Count; i++) {
				string replace;
				
				replace = String.Format("{0}\\(",toDo[i].Groups[1].Value);
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
		
		private static void RemoveArrayObfuscation(ref string source, string tblSource)
		{
			string arrayName, decryptName, separator;
			string[] values;
			MatchCollection toFix;
			
			arrayName = getArrayName(source);
			decryptName = getBin2StrName(source, arrayName);
			separator = getSeparator(source, arrayName);
			values = tblSource.Split(new string[] { separator }, StringSplitOptions.RemoveEmptyEntries);
			
			toFix = Regex.Matches(source, String.Format("\\$(\\w+) = {0}\\(\\${1}\\[(\\d+)\\]\\)", decryptName, arrayName), RegexOptions.IgnoreCase | RegexOptions.Multiline);
			
			foreach(Match tmp in toFix)
			{
				string varName;
				int i;
				
				varName = tmp.Groups[1].Value;
				i = int.Parse(tmp.Groups[2].Value);
				
				source = source.Replace(String.Format("${0}", varName), string.Format("\"{0}\"", AutoShit.BinaryToString(values[i-1], false)));
			}
			
			
			// REMOVE THE methodcrypt() CALLS.
			
			toFix = Regex.Matches(source, String.Format("{0}\\((\"|')([\\dA-F]+)(\"|')\\)", decryptName), RegexOptions.Multiline | RegexOptions.IgnoreCase);
			
			foreach(Match tmp in toFix)
			{	
				source = source.Replace(tmp.Value, String.Format("\"{0}\"", AutoShit.BinaryToString(tmp.Groups[2].Value, false)));
			}
			
			
			RemoveArrayRests(ref source);
		}
		
		private static string getArrayName(string source)
		{
			Match match;
			
			match = Regex.Match(source, "(If NOT IsDeclared\\(\"\\w+\"\\) Then )?Global \\$(\\w+)", RegexOptions.Multiline | RegexOptions.IgnoreCase);
			if(match.Success)
				return match.Groups[2].Value;
			else
				throw new Exception("Can't find the array name");
		}
		
		private static string getBin2StrName(string source, string arrayName)
		{
			Match match;
			
			match = Regex.Match(source, String.Format("= (\\w+)\\(\\${0}\\[\\d+\\]\\)", arrayName), RegexOptions.Multiline | RegexOptions.IgnoreCase);
			if(match.Success)
				return match.Groups[1].Value;
			else
				throw new Exception("Can't find the decrypt method name");
		}
		
		private static string getSeparator(string source, string arrayName)
		{
			Match match;
			
			match = Regex.Match(source, string.Format("Global (\\$\\w+, )?\\${0} = StringSplit\\(FileRead\\(\\$\\w+\\),('|\")(.+)('|\")(,\\d+)?\\)", arrayName), RegexOptions.Multiline | RegexOptions.IgnoreCase);
			if(match.Success)
				return match.Groups[3].Value;
			else
				throw new Exception("Can't find the separator");
			
		}
		
		private static void RemoveArrayRests(ref string source)
		{
			source = Regex.Replace(source, "#OnAutoItStartRegister +\"(\\w+)\"", String.Empty, RegexOptions.Multiline | RegexOptions.IgnoreCase);
			source = Regex.Replace(source, "Global \".+", String.Empty, RegexOptions.Multiline | RegexOptions.IgnoreCase);
			source = Regex.Replace(source, "If NOT IsDeclared\\(\"\\w+\"\\) Then Global \\$\\w+", String.Empty, RegexOptions.Multiline | RegexOptions.IgnoreCase);
		}
		
		
		private static void InsertCredits(ref string source)
		{
			string credits;
			
			credits = ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n"+
					  ";                                             ;\n"+
					  ";        DEOBFUSCATED WITH DEOBHELLPER        ;\n"+
					  ";                                             ;\n"+
					  ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n"+
					  ";                                             ;\n"+
					  "; Author: V0K3 (v0k3@inventati.org)           ;\n"+
					  "; Site: http://inforge.net                    ;\n"+
					  "; Version: 0.3                                ;\n"+
					  ";                                             ;\n"+
					  ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n"+
					  ";                                             ;\n"+
					  ";                FUCK THE TOY                 ;\n"+
					  ";                                             ;\n"+
					  ";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n";
			
			source = credits + source;
		}
		
	}
}
