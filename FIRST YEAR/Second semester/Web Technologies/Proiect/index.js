const express = require("express");
const fs = require("fs");
const sharp = require("sharp");
const { Client } = require("pg");
const ejs = require("ejs");
const sass = require("sass");
const { Server } = require("http");
// const jpg = require("jpg");


var client = new Client({ database: "Proiect", user: "pepi100", password: "1234", host: "localhost", port: "5432" });
// var client = new Client({
//     database: "d6htj14nvp5nb5",
//     user: "raelwnowgnmmid",
//     password: "6a60d479ec4ea7c3f7468c5a4acbaa777c22e20b27e961922604f2aa6ce07e2d",
//     host: "ec2-54-165-178-178.compute-1.amazonaws.com",
//     port: 5432,
//     ssl: {
//         rejectUnauthorized: false
//     }
// });
client.connect();


app = express();

app.set("view engine", "ejs");


app.use(["/resurse", "/resurse123"], express.static(__dirname + "/resurse"))


console.log("Director proiect:", __dirname);

app.get(["/", "/index", "/home"], function(req, res) {
    //res.sendFile(__dirname+"/index1.html");
    client.query("select * from tabel", function(err, rezQuery) {
        // console.log(rezQuery);
    });
    res.render("pagini/index", { ip: req.ip, imagini: obImagini.imagini });
})


app.get(["/*.ejs", "/admin"], function(req, res) {
    //res.sendFile(__dirname+"/index1.html");
    res.status(403).render("pagini/403");
})

/*
app.get("/despre", function(req, res){
    //res.sendFile(__dirname+"/index1.html");
    res.render("pagini/despre");
})
*/

app.get("/galerie", function(req, res) {
    //res.sendFile(__dirname+"/index1.html");
    res.render("pagini/galerie_statica", { ip: req.ip, imagini: obImagini.imagini });
    res.end();
})



app.get("/produse", function(req, res) {
    client.query("select * from microfoane", function(err, rezQuery) {
        // console.log(err);
        // console.log(rezQuery);

        res.render("pagini/produse", { microfoane: rezQuery.rows });
    });
})

app.get("/produs/:id", function(req, res) {
    client.query(`select * from microfoane where id = ${req.params.id}`, function(err, rezQuery) {
        // console.log(err);
        // console.log(rezQuery);

        res.render("pagini/produs", { prod: rezQuery.rows[0] });
    });
})


app.get("/*", function(req, res) {
    res.render("pagini" + req.url, function(err, rezRender) {
        if (err) {
            if (err.message.includes("Failed to lookup view")) {
                console.log(err);
                res.status(404).render("pagini/404");
            } else {

                res.render("pagini/eroare_generala");
            }
        } else {
            console.log(rezRender);
            res.send(rezRender);
        }
    });

    //console.log("generala:",req.url);
    res.end();
})





function creeazaImagini() {
    var buf = fs.readFileSync(__dirname + "/resurse/json/galerie.json").toString("utf8");
    obImagini = JSON.parse(buf); //global
    //console.log(obImagini);

    for (let imag of obImagini.imagini) {
        let descriere = imag.descriere;
        let nume_imag, extensie;
        [nume_imag, extensie] = imag.cale_fisier.split(".") // "abc.de".split(".") ---> ["abc","de"]
        let dim_mic = 150

        imag.mic = `${obImagini.cale_galerie}/mic/${nume_imag}-${dim_mic}.webp` //nume-150.webp // "a10" b=10 "a"+b `a${b}`
            //console.log(imag.mic);

        let dim_mediu = 300
        imag.mediu = `${obImagini.cale_galerie}/mediu/${nume_imag}-${dim_mediu}.png`;
        imag.mare = `${obImagini.cale_galerie}/${imag.cale_fisier}`;
        if (!fs.existsSync(imag.mic))
            sharp(__dirname + "/" + imag.mare).resize(dim_mic).toFile(__dirname + "/" + imag.mic);

        if (!fs.existsSync(imag.mediu))
            sharp(__dirname + "/" + imag.mare).resize(dim_mediu).toFile(__dirname + "/" + imag.mediu);



    }

}
creeazaImagini();



process.on('uncaughtException', function(err) {
    console.log(err);
});


// app.listen(8080);
var s_port = process.env.PORT || 8080;
app.listen(s_port);

console.log("A pornit");