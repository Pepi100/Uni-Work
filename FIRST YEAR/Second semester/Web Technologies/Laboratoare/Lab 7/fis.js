/*var raspuns=prompt("Introduce text","text default");
alert(raspuns);
var ras2=confirm("Iti place siteul?");
alert( ras2 ? "Da" : "Nu")*/


window.onload = function() {
    var p = document.getElementById("p1");
    p.title = "descriere";
    p.style.backgroundColor = "pink";
    p.style.border = "1px solid green";
    p.innerHTML = "Un paragraf si mai <b>frumos</b>"
        //alert(345)
    var b_ok = document.getElementById("btn");
    b_ok.onclick = function() {
        var inp = document.getElementById("inp");
        document.getElementById("p1").innerHTML += inp.value;
    }
    var b_filtreaza = document.getElementById("filtreaza");
    b_filtreaza.onclick = function() {
        var val_inp = document.getElementById("inp").value;
        var paragrafe = document.getElementsByClassName("a");
        for (let p of paragrafe) {
            p.style.display = "none";
            if (p.innerHTML.includes(val_inp))
                p.style.display = "block";
        }
    }
    document.getElementById("creeaza").onclick = function() {
        var p = document.createElement("p");
        p.innerHTML = "sir oarecare";
        p.className = document.getElementById("inp").value;
        document.body.appendChild(p);
    }
    document.getElementById("sterge").onclick = function() {
        document.body.lastElementChild.remove();
    }


    document.getElementById("data").onclick = function() {
        var d = document.createElement("p");
        d.innerHTML = new Date();
        document.body.appendChild(d);
    }

    var f = document.getElementsByClassName("b")
    for (let p of f) {
        p.onclick = function() {
            var d = document.createElement("p");
            d.innerHTML = p.innerHTML.split("").reverse().join("");
            document.body.appendChild(d);
        }
    }
}

//alert(123)