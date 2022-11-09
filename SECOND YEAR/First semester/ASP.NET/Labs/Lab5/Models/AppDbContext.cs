using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.ChangeTracking;

namespace Lab5.Models
{
    public class AppDbContext : DbContext
    {
        public AppDbContext() : base()
        {
        }
        protected override void OnConfiguring
       (DbContextOptionsBuilder options)
        {
            options.UseSqlServer(
            @"Data Source=(localdb)\mssqllocaldb;Initial Catalog=ArticleDB;Integrated Security=True;MultipleActiveResultSets=True");
        }

        public DbSet<Article> Articles { get; set; }

        public DbSet<Category> Categories { get; set; } 
    }
}
