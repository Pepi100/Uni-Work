window.addEventListener("load", function() {
    var tema = localStorage.getItem("tema");
    if (tema) {
        document.body.classList.add("light");
        document.getElementById("icon_tema").classList.replace("fa-sun", "fa-moon");
    } else {
        document.body.classList.remove("light");
        document.getElementById("icon_tema").classList.replace("fa-moon", "fa-sun");
    }

    document.getElementById("btn_tema").onclick = function() {
        var tema = localStorage.getItem("tema");
        if (tema)
            localStorage.removeItem("tema");
        else
            localStorage.setItem("tema", "dark");

        document.body.classList.toggle("light");
        if (document.getElementById("icon_tema").classList.contains("fa-sun"))
            document.getElementById("icon_tema").classList.replace("fa-sun", "fa-moon");
        else
            document.getElementById("icon_tema").classList.replace("fa-moon", "fa-sun");

        // console.log(document.getElementById("icon_tema").classList);
    }
})