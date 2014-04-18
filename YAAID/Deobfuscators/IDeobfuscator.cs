namespace YAAID.Deobfuscators
{
    interface IDeobfuscator
    {
        string Deobfuscate(string code, Options options);
    }
}
