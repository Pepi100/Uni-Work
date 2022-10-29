using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Lab3.Controllers
{
    public class ExamplesController : Controller
    {
        // GET: ExamplesController
        public string Concatenare(string s1, string s2)
        {
            return s1+s2;
        }

        public string Produs(int a, int? b)
        {
            if (b == null)
            {
                return "Introduceti ambii parametri";
            }
            return (a * b).ToString();
        }


    }
}
