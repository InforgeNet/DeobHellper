namespace YAAID
{
    struct Options
    {
        public bool RenameVariables { get; private set; }

        public Options(bool renameVariables) : this()
        {
            RenameVariables = renameVariables;
        }
    }
}
