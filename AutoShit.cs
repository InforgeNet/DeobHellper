using System;
using System.Globalization;

namespace DeobHellper
{
	public class AutoShit
	{
		public static string BinaryToString(string binary, bool Zerox = true)
		{
			string ret;
			
			ret = String.Empty;
			
			if(Zerox)
				if(binary.Substring(0,2) != "0x")
				throw new Exception("Invalid hex, no 0x found.");
			
			for(int i = Zerox?2:0; i < binary.Length; i+=2) {
				ret += (char)int.Parse(binary.Substring(i,2), NumberStyles.HexNumber);
			}
			
			return ret;
		}
		
	}
}
