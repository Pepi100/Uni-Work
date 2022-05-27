window.addEventListener("load", function(){


    let btn_tema=document.getElementById("btn_tema")
    if(btn_tema){
        btn_tema.onclick=function(){
            var tema=localStorage.getItem("tema");
            if(tema)
                localStorage.removeItem("tema");
            else
                localStorage.setItem("tema","dark");

            document.body.classList.toggle("dark");
        }
    }
});