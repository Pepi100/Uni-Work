window.addEventListener("load", function(){

    // bifare elemente din cosul virtual (localStorage)

    iduriProduse=localStorage.getItem("cos_virtual");// "1,5,3" 
    //hint pentru cantitate "1|20,5|10,3|2" 20 produse cu id-ul 1....
    if(iduriProduse){
        iduriProduse=iduriProduse.split(",");
    }
    else{
        iduriProduse=[];
    }
    for (let id_p of iduriProduse){
        var ch=document.querySelector(`[value='${id_p}'].select-cos`);
        if(ch){
            ch.checked=true;
        }
    }


    document.getElementById("inp-pret").onchange=function(){
        document.getElementById("infoRange").innerHTML= " ("+ this.value + ")"
    }




    document.getElementById("filtrare").onclick=function(){
        var valNume=document.getElementById("inp-nume").value.toLowerCase();

        var butoaneRadio=document.getElementsByName("gr_rad");
        for(let rad of butoaneRadio){
            if(rad.checked){
                var valCalorii=rad.value;
                break;
            }
        }
        var minCalorii,maxCalorii;
        if (valCalorii!="toate"){
            
            [minCalorii,maxCalorii]=valCalorii.split(":");
            minCalorii=parseInt(minCalorii);
            maxCalorii=parseInt(maxCalorii);
        }
        else{
            minCalorii=0;
            maxCalorii=100000000;
        }


        var valPret=document.getElementById("inp-pret").value;

        var valCategorie=document.getElementById("inp-categorie").value;


        var articole=document.getElementsByClassName("produs");
        for(let art of articole){
            art.style.display="none";
            //v= art.getElementsByClassName("val-nume"); v[0]
            let numeArt= art.getElementsByClassName("val-nume")[0].innerHTML.toLowerCase();

            let cond1= numeArt.startsWith(valNume);


            let caloriiArt=parseInt(art.getElementsByClassName("val-calorii")[0].innerHTML);
            let cond2= (minCalorii <= caloriiArt && caloriiArt<maxCalorii);

            let pretArt=parseInt(art.getElementsByClassName("val-pret")[0].innerHTML)
            let cond3=(valPret<=pretArt) ;

            let categorieArt=art.getElementsByClassName("val-categorie")[0].innerHTML
            let cond4= (valCategorie=="toate") || (categorieArt==valCategorie);


            let conditieFinala= cond1 && cond2 && cond3 && cond4;
            if(conditieFinala)
                art.style.display="block";
        }

    }

    
    document.getElementById("resetare").onclick=function(){
        var articole= document.getElementsByClassName("produs");
        for(let art of articole)
            art.style.display="block";

        document.getElementById("inp-nume").value="";
        document.getElementById("i_rad4").checked=true;
        document.getElementById("inp-pret").value=0;
        document.getElementById("infoRange").innerHTML="(0)";
        
        document.getElementById("sel-toate").selected=true;
    }

    function sorteaza(semn){
        var articole= document.getElementsByClassName("produs");
        var v_articole=Array.from(articole);
        v_articole.sort(function(a,b){
            var pret_a= parseFloat(a.getElementsByClassName("val-pret")[0].innerHTML);
            var pret_b= parseFloat(b.getElementsByClassName("val-pret")[0].innerHTML);
            if(pret_a!=pret_b)
                return semn*(pret_a - pret_b);
            else{
                
                var nume_a= a.getElementsByClassName("val-nume")[0].innerHTML;
                var nume_b= b.getElementsByClassName("val-nume")[0].innerHTML;
                return semn*nume_a.localeCompare(nume_b);
            }

        });

        for(let art of v_articole){
            art.parentElement.appendChild(art);
        }
    }

    document.getElementById("sortCrescNume").onclick=function(){
        sorteaza(1);
    }

    
    document.getElementById("sortDescrescNume").onclick=function(){
        sorteaza(-1);
    }


    window.onkeydown=function(e){
        console.log(e);
        if(e.key=="c" && e.altKey){
            var p_vechi=document.getElementById("suma")
            if(!p_vechi){
                suma=0;
                var articole= document.getElementsByClassName("produs");   
                for(let art of articole){
                    if (art.style.display != "none")
                        suma+=parseFloat(art.getElementsByClassName("val-pret")[0].innerHTML);
                }
                var pgf=document.createElement("p");
                pgf.innerHTML="<b>Suma:</b> "+suma;
                pgf.id="suma";
                var sectiune=document.getElementById("produse");
                sectiune.parentNode.insertBefore(pgf, sectiune);
                setTimeout(function(){
                    var p_vechi=document.getElementById("suma");
                    if(p_vechi)
                        p_vechi.remove();
                } , 2000)
            }
        }
    }


    var checkboxuri=document.getElementsByClassName("select-cos");
    for(let ch of checkboxuri){
        ch.onchange=function(){

            iduriProduse=localStorage.getItem("cos_virtual");// "1,5,3" 
            //hint pentru cantitate "1|20,5|10,3|2" 20 produse cu id-ul 1....
            if(iduriProduse){
                iduriProduse=iduriProduse.split(",");
            }
            else{
                iduriProduse=[];
            }

            if(this.checked){

                iduriProduse.push(this.value)// in value avem id-ul produsului

            }
            else{
                var poz=iduriProduse.indexOf(this.value);
                if(poz!=-1)
                    iduriProduse.splice(poz,1);
                
            }
            localStorage.setItem("cos_virtual", iduriProduse.join(","))
        }
    }
    
})