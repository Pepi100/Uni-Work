window.addEventListener("load", function() {
    document.getElementById("inp-pret").onchange = function() {
        document.getElementById("infoRange").innerHTML = "(" + this.value + ")";
    }




    document.getElementById("filtrare").onclick = function() {
        var valNume = document.getElementById("inp-nume").value.toLowerCase();

        var butoaneRadio = document.getElementsByName("gr_rad");

        var valPret = document.getElementById("inp-pret").value;

        var inclCablu = document.getElementById("cablu").checked;

        var articole = document.getElementsByClassName("produs");
        for (let rad of butoaneRadio) {
            if (rad.checked) {
                var valTip = rad.value;
                break;
            }
        }

        var valCategorie = document.getElementById("inp-categorie").value;

        for (let art of articole) {
            art.style.display = "none";
            let numeArt = art.getElementsByClassName("val-nume")[0].innerHTML.toLowerCase();
            let cond1 = numeArt.startsWith(valNume);

            let tipMic = art.getElementsByClassName("val-tip")[0].innerHTML.toLowerCase();
            let cond2 = (valTip == "toate" || valTip == tipMic);

            let pretArt = parseInt(art.getElementsByClassName("val-pret")[0].innerHTML);
            //  console.log(pretArt);
            let cond3 = (pretArt >= valPret);

            let categorieArt = art.getElementsByClassName("val-categorie")[0].innerHTML;
            let cond4 = (valCategorie == "toate" || valCategorie == categorieArt);

            let cabluArt = (art.getElementsByClassName("val-cablu")[0].innerHTML) == "true";
            let cond5 = (!inclCablu) || cabluArt;

            let contitieFinala = cond1 && cond2 && cond3 && cond4 && cond5;

            if (contitieFinala) {
                art.style.display = "block";
            }
        }
    }

    document.getElementById("resetare").onclick = function() {
        var articole = document.getElementsByClassName("produs");
        for (let art of articole) {
            art.style.display = "block";
        }
        document.getElementById("inp-nume").value = "";
        document.getElementById("i_rad4").checked = true;
        document.getElementById("sel-toate").selected = true;
        document.getElementById("inp-pret").value = 0;
        document.getElementById("infoRange").innerHTML = " (0)";


    }

    function sorteaza(semn) {
        var articole = document.getElementsByClassName("produs");
        var v_articole = Array.from(articole);
        v_articole.sort(function(a, b) {
            let val_a = parseFloat(a.getElementsByClassName("val-pret")[0].innerHTML)
            let val_b = parseFloat(b.getElementsByClassName("val-pret")[0].innerHTML)

            let categ_a = a.getElementsByClassName("val-categorie")[0].innerHTML
            let categ_b = b.getElementsByClassName("val-categorie")[0].innerHTML
            if (val_a - val_b == 0) {
                //daca au aceelasi pret sortam dupa nume
                return categ_a.localeCompare(categ_b) * semn;
            } else {
                return (val_a - val_b) * semn;
            }
        });

        for (let art of v_articole) {
            art.parentElement.appendChild(art);
        }
    }

    document.getElementById("sortCrescNume").onclick = function() { sorteaza(1); }
    document.getElementById("sortDescrescNume").onclick = function() { sorteaza(-1); }


    document.getElementById("numarProd").onclick = function() {
        if (!document.getElementById("numar")) {
            let nr_prod = 0;
            var articole = document.getElementsByClassName("produs");
            for (let art of articole) {
                if (art.style.display != "none") {
                    nr_prod = nr_prod + 1;
                }
            }

            var p = document.createElement("p");
            p.id = "numar";
            p.innerHTML = "<b>Numar produse: " + nr_prod + "</b>";
            document.getElementById("filtre").appendChild(p);


            setTimeout(function() {
                let p2 = document.getElementById("numar");
                if (p) {
                    p.remove();
                }
            }, 2000);
        }


    }




})