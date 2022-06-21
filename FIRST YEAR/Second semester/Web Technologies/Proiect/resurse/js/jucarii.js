window.addEventListener("load", function() {

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

    document.getElementById("sortare").onclick = function() { sorteaza(semn); }


});