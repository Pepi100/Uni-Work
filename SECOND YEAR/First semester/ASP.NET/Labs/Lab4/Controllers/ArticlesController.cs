using Lab_4.Models;
using Microsoft.AspNetCore.Mvc;

namespace Lab_4.Controllers
{
    public class ArticlesController : Controller
    {
        [NonAction]
        public Article[] GetArticles()
        {
            // Se instantiaza un array de articole
            Article[] articles = new Article[3];
            // Se creeaza articolele
            for (int i = 0; i < 3; i++)
            {
                Article article = new Article();
                article.Id = i;
                article.Title = "Articol " + (i + 1).ToString();
                article.Content = "Continut articol " + (i + 1).ToString();
                article.Date = DateTime.Now;
                // Se adauga articolul in array
                articles[i] = article;
            }
            return articles;
        }

         


        public IActionResult Index()
        {

            Article[] articles = GetArticles();

            ViewBag.Articles = articles;
            return View();
        }



        public IActionResult Show(int? id)
        {
            Article[] articles = GetArticles();

            ViewBag.Article = articles[(int)id];

            return View();
        }


        public IActionResult New()
        {
            return View();
        }

        [HttpPost]
        public IActionResult New(Article art)
        {   
            //adaugare in baza de date

            return View("NewMethodPost"); //redirect
        }
    }
}
