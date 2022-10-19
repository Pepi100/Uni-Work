class Program
{
    static void Palindrom(int n) {
        int nCopy = n;
        int rev = 0;
        while (nCopy > 0)
        {
            rev = rev * 10 + nCopy % 10;
            nCopy = nCopy / 10;
        }

        if (n == rev)
            Console.WriteLine("Numarul este palindrom");
        else
            Console.WriteLine("Numarul nu este palindrom");
    }

    static bool Alterneaza(int[] v, int n )
    {
        bool alterneaza = true;

        for(int i = 0; i < n-1; i++)
        {
            if( v[i]%2 == v[i+1]%2 )
                alterneaza = false;
        }

        return alterneaza;
    }

    static void Main(string[] args){

        


      


        Console.WriteLine("Introduceti un numar pentru a verifica daca acesta este palindorm:");
        string nr = Console.ReadLine();

        Palindrom(int.Parse(nr));



        Console.WriteLine("Introduceti numarul de numere din vector:");
         nr = Console.ReadLine();
        int n = int.Parse(nr);

        Console.WriteLine("Introduceti "+nr+ " numere:");
        int[] v= new int[200];
        string a;

        for(int i = 0; i < n; i++)
        {
            a = Console.ReadLine();
            v[i] = int.Parse(a);
            
        }




        Console.WriteLine( Alterneaza(v, n));





    }

}
