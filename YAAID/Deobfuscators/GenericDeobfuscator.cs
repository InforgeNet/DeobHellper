using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace YAAID.Deobfuscators
{
    class GenericDeobfuscator : IDeobfuscator
    {
        private const string Var = "Var";

        public string Deobfuscate(string code, Options options)
        {
            if (options.RenameVariables)
                code = DecryptVariables(code);
            return code;
        }

        private IEnumerable<string> EnumerateVariables(string code)
        {
            List<string> variableNames = new List<string>();

            Regex regex = new Regex(@"\$(\w+)", RegexOptions.CultureInvariant);
            Match match = regex.Match(code);
            while (match.Success)
            {
                if (!variableNames.Contains(match.Groups[1].Value))
                    variableNames.Add(match.Groups[1].Value);
                match = match.NextMatch();
            }

            return variableNames;
        }

        private string DecryptVariables(string code)
        {
            IEnumerable<string> variableNames =  EnumerateVariables(code);
            int i = 0;
            foreach (string variable in variableNames)
            {
                code = code.Replace("$" + variable, Var + i);
                i++;
            }

            return code;
        }
    }
}
