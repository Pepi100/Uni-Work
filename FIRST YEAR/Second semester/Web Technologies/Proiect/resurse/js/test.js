window.addEventListener("load", function() {




    document.getElementsByClassName("sec_jucarie").onclick = function() {


    }

    document.getElementById("sortare").onclick = function() {
        //ce uitam ce valori are radio-buttonul
        console.log(11);
        var semn;
        var butoaneRadio = document.getElementsByName("gr_rad");
        if (butoaneRadio[0].checked) {
            semn = 1;
        } else {
            semn = -1;
        }
        sorteaza(semn);

    }



    function sorteaza(semn) {
        var jucarii = document.getElementsByClassName("sec_jucarie");
        var v_jucarii = Array.from(jucarii);

        v_jucarii.sort(function(a, b) {
            let val_a = parseInt(a.getElementsByClassName("varsta")[0].innerHTML)
            let val_b = parseInt(b.getElementsByClassName("varsta")[0].innerHTML)

            let pret_a = parseInt(a.getElementsByClassName("pret")[0].innerHTML)
            let pret_b = parseInt(b.getElementsByClassName("pret")[0].innerHTML)
            if (val_a - val_b == 0) {
                //daca au aceelasi pret sortam dupa pret
                return (pret_a - pret_b) * semn;
            } else {
                return (val_a - val_b) * semn;
            }
        });

        for (let art of v_jucarii) {
            art.parentElement.appendChild(art);
        }
    }


    document.getElementById("filtrare").onclick = function() {


        var articole = document.getElementsByClassName("sec_jucarie");

        //verificam care optiune este selectalta

        var culoareSel;

        var optiuni = document.getElementsByClassName("opt");

        for (let cul of optiuni) {
            if (cul.selected) {

                culoareSel = cul.value.toLowerCase();
                break;
            }
        }

        for (let art of articole) {
            art.style.display = "none";



            // let tipMic = art.getElementsByClassName("val-tip")[0].innerHTML.toLowerCase();
            // let cond2 = (valTip == "toate" || valTip == tipMic);

            // let pretArt = parseInt(art.getElementsByClassName("val-pret")[0].innerHTML);
            // //  console.log(pretArt);
            // let cond3 = (pretArt >= valPret);

            // let categorieArt = art.getElementsByClassName("val-categorie")[0].innerHTML;
            // let cond4 = (valCategorie == "toate" || valCategorie == categorieArt);

            // let cabluArt = (art.getElementsByClassName("val-cablu")[0].innerHTML) == "true";
            // let cond5 = (!inclCablu) || cabluArt;



            let cond1 = art.innerHTML.toLowerCase().includes(culoareSel) || culoareSel == "toate";

            let contitieFinala = cond1;

            if (contitieFinala) {
                art.style.display = "block";
            }
        }

        setTimeout(function() {
            document.getElementById("sel_culori").selectedIndex = 0;
            for (let art of articole) {
                art.style.display = "block";
            }
        }, 5000);


    }



});