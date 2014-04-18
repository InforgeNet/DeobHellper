using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YAAID.Deobfuscators;

namespace YAAID
{
    static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("[TEST] Reading file...");
            string code = File.ReadAllText("test.au3");
            Console.WriteLine("[TEST] Starting deobfuscator...");
            GenericDeobfuscator deobfuscator = new GenericDeobfuscator();
            Console.WriteLine("[TEST] Renaming variables...");
            code = deobfuscator.Deobfuscate(code, new Options(true));
            Console.WriteLine("[TEST] Writing file...");
            File.WriteAllText("deobf.au3", code);
            Console.WriteLine("[TEST] Done!");
            Console.ReadKey(false);
        }
    }
}
