namespace CSharpConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Blob name: ");
            string blobName = Console.ReadLine();

            Console.WriteLine("Container name: ");
            string containerName = Console.ReadLine();

            Console.WriteLine("Connection string: ");
            string connectionString = Console.ReadLine();

            // since "managed library" doesn't build, I can't use it.
        }
    }
}