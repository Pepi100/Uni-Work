var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();


app.MapControllerRoute(
    name: "Produs",
    pattern: "produs/{a}/{b?}",
    defaults: new { controller = "Examples", action = "Produs" });

app.MapControllerRoute(
    name: "Concatenare",
    pattern: "concatenare/{s1}/{s2}",
    defaults: new {controller = "Examples", action = "Concatenare"});

app.MapControllerRoute(
   name: "StudentsAll",
   pattern: "students/all",
   defaults: new {controller = "Students", action="Index"}
    );
app.MapControllerRoute(
   name: "StudentsShow",
   pattern: "students/show/{id?}",
   defaults: new { controller = "Students", action = "Show" }
    );
app.MapControllerRoute(
   name: "StudentsShow",
   pattern: "students/edit/{id?}",
   defaults: new { controller = "Students", action = "Edit" }
    );

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
