using Microsoft.AspNetCore.Mvc;

namespace Lab3.Controllers
{
    public class StudentsController : Controller
    {
        public string Index()
        {
            return "Afisarea tuturor studentilor";
        }

        public string Show(int? id)
        {
            return "Afisarea studentului cu id" + id.ToString();
        }

        public string Edit(int? id)
        {
            return "Editarea studentului cu id" + id.ToString();
        }
    }
}
