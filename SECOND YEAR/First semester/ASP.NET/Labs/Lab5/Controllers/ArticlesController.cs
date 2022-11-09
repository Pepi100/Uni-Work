using Microsoft.AspNetCore.Mvc;

namespace Lab5.Controllers
{
    public class ArticlesController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
