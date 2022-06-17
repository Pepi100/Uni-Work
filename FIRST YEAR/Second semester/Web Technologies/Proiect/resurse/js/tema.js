window.addEventListener("load", function() {
    var tema = localStorage.getItem("tema");
    if (tema)
        document.body.classList.add("light");
    else
        document.body.classList.remove("light");
    document.getElementById("btn_tema").onclick = function() {
        var tema = localStorage.getItem("tema");
        if (tema)
            localStorage.removeItem("tema");
        else
            localStorage.setItem("tema", "dark");

        document.body.classList.toggle("light");
    }
})