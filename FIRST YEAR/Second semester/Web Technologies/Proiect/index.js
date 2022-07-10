const express = require("express");
const fs = require("fs");
const sharp = require("sharp");
const { Client } = require("pg");
const ejs = require("ejs");
// const sass = require("sass");
const { Server } = require("http");
const formidable = require('formidable');
const crypto = require('crypto');
const session = require('express-session');
const nodemailer = require('nodemailer');
const path = require("path");
// const jpg = require("jpg");


var client = new Client({ database: "Proiect", user: "pepi100", password: "1234", host: "localhost", port: "5432" });

// var client = new Client({
//     database: "dbdpf6n3221q9m",
//     user: "eadtwgkamhelqk",
//     password: "c8f99f14b0ffc1ce496d7a30555406ecc03634b82c23c48b1222597d375b4689",
//     host: "ec2-44-205-41-76.compute-1.amazonaws.com",
//     port: 5432,
//     ssl: {
//         rejectUnauthorized: false
//     }
// });

client.connect();


app = express();

app.set("view engine", "ejs");


app.use(["/resurse", "/resurse123"], express.static(__dirname + "/resurse"))
app.use("/poze_uploadate", express.static(__dirname + "/poze_uploadate"))

app.use(session({
    secret: 'qwerty', //folosit pentru criptare
    resave: true,
    saveUninitialized: false
}));

app.use("/*", function(req, res, next) {
    res.locals.propGenerala = "Ceva care se afiseaza pe toate pag";
    var vCateg = [
        'Microfon de voce si live',
        'Microfon de studio',
        'Microfon lavaliera',
        'Microfon gaming / podcast',
        'Microfon pentru camere video'
    ];
    res.locals.categorii = vCateg;
    res.locals.utilizator = req.session.utilizator;
    res.locals.mesajLogin = req.session.mesajLogin;
    req.session.mesajLogin = null;
    next();
});


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


// app.get("/despre", function(req, res) {
//     //res.sendFile(__dirname+"/index1.html");
//     res.render("pagini/despre");
// })

foldere = ["temp", "poze_uploadate"]
for (let folder of foldere) {
    let caleFolder = path.join(__dirname, folder);
    if (!fs.existsSync(caleFolder))
        fs.mkdirSync(caleFolder);
}

const obGlobal = {
    obImagini: null,
    obErori: null,
    emailServer: "fyresound@gmail.com",
    port: 8080,
    sirAlphaNum: "",
    protocol: null,
    numeDomeniu: null,
    // clientMongo: mongodb.MongoClient,
    // bdMongo: null
};

// obGlobal.clientMongo.connect(url, function(err, bd) {
//     if (err) console.log(err);
//     else {
//         obGlobal.bdMongo = bd.db("proiect_web");
//     }
// });


async function trimiteMail(email, subiect, mesajText, mesajHtml, atasamente = []) {
    var transp = nodemailer.createTransport({
        service: "gmail",
        secure: false,
        auth: { //date login 
            user: obGlobal.emailServer,
            pass: "plmdmihwrvviikqj"
        },
        tls: {
            rejectUnauthorized: false
        }
    });
    //genereaza html
    await transp.sendMail({
        from: obGlobal.emailServer,
        to: email,
        subject: subiect, //"Te-ai inregistrat cu succes",
        text: mesajText, //"Username-ul tau este "+username
        html: mesajHtml, // `<h1>Salut!</h1><p style='color:blue'>Username-ul tau este ${username}.</p> <p><a href='http://${numeDomeniu}/cod/${username}/${token}'>Click aici pentru confirmare</a></p>`,
        attachments: atasamente
    })
    console.log("trimis mail");
}


// --------------------------------ulitizatori--------------------------------
parolaServer = "tehniciweb";


app.post("/inreg", function(req, res) {
    var formular = new formidable.IncomingForm()
    var username;
    formular.parse(req, function(err, campuriText, campuriFisier) {
        // console.log(2);
        var parolaCriptata = crypto.scryptSync(campuriText.parola, parolaServer, 64).toString('hex');

        var eroare = "";
        if (campuriText.username == "") {
            eroare += "Username necompletat.\n";
        }
        if (!campuriText.username.match(new RegExp("^[A-Za-z0-9]+$"))) {
            eroare += "Username nu conditine doar litere si cifre.\n";
        }
        if (campuriText.parola != campuriText.rparola) {
            eroare += "Parolele nu seamana.";
        }

        console.log("1");

        if (!eroare) {
            var queryUtiliz = `select username from utilizatori where username = '${campuriText.username}'`;

            client.query(queryUtiliz, function(err, rezUtiliz) {
                if (rezUtiliz.rows.length != 0) {
                    eroare += "Username-ul a fost deja folosit."



                    var x = Math.floor(Math.random() * 100);

                    var nouUser = campuriText.username + x.toString();

                    var queryNou = `select username from utilizatori where username = '${nouUser}'`



                    let ok = 0;
                    client.query(queryNou, function(err, rezUtiliz2) {
                        if (rezUtiliz2.rows.length == 0) {
                            ok = 1;

                        }
                        while (ok != 1) {
                            x = Math.floor(Math.random() * 100);
                            nouUser = campuriText.username + x.toString();

                            client.query(queryNou, function(err, rezUtiliz2) {
                                if (rezUtiliz2.rows.length == 0)
                                    ok = 1;
                            });

                        }


                    });



                    eroare += `\n Va recomandam '${nouUser}'.`;

                    res.render("pagini/inregistrare", { err: "Eroare: " + eroare });
                } else {
                    var comandaInserare = `insert into utilizatori (username, nume, prenume, parola, email, culoare_chat) values ('${campuriText.username}', '${campuriText.nume}','${campuriText.prenume}', '${parolaCriptata}', '${campuriText.email}', '${campuriText.culoare_chat}')`;
                    client.query(comandaInserare, function(err, rezInserare) {
                        if (err) {
                            console.log(err);
                            res.render("pagini/inregistrare", { err: "Eroare: " + eroare });
                        } else {
                            res.render("pagini/inregistrare", { raspuns: "Datele au fost introduse" });
                            trimiteMail(campuriText.email, "Te-ai inregistrat", "text", `<h1>Salut!</h1><p style='color:blue'>Username-ul tau este ${campuriText.username}.</p> <p><a href='http://${obGlobal.numeDomeniu}/cod/${campuriText.username}'>Click aici pentru confirmare</a></p>`);

                        }
                    })
                }
            })

        } else {
            res.render("pagini/inregistrare", { err: "Eroare: " + eroare });
        }

    })
    formular.on("field", function(nume, val) {
        if (nume == "username")
            username = val;
    });
    formular.on("fileBegin", function(nume, fisier) {
        caleUtiliz = path.join(__dirname, "poze_uploadate", username);
        if (!fs.existsSync(caleUtiliz)) {
            fs.mkdirSync(caleUtiliz);
        }
        fisier.filepath = path.join(caleUtiliz, "imagine.png");
    });
    formular.on("file", function(nume, fisier) {

    });


});

app.post("/login", function(req, res) {
    var formular = new formidable.IncomingForm()
    formular.parse(req, function(err, campuriText, campuriFisier) {

        var parolaCriptata = crypto.scryptSync(campuriText.parola, parolaServer, 64).toString('hex');
        var querySelect = `select * from utilizatori where username= '${campuriText.username}' and parola= '${parolaCriptata}'`;
        client.query(querySelect, function(err, rezSelect) {
            if (err) {
                console.log(err);
            } else {
                if (rezSelect.rows.length == 1) {
                    // console.log("e bun");

                    req.session.utilizator = {
                        nume: rezSelect.rows[0].nume,
                        prenume: rezSelect.rows[0].prenume,
                        username: rezSelect.rows[0].username,
                        email: rezSelect.rows[0].email,
                        rol: rezSelect.rows[0].rol,
                        culoare_chat: rezSelect.rows[0].culoare_chat
                    };
                    res.redirect("/index");
                } else {
                    req.session.mesajLogin = "Login esuat";
                    res.redirect("/index");
                }
            }
        })
    })

});


app.get("/logout", function(req, res) {
    req.session.destroy();
    res.locals.utilizator = null;
    res.render("pagini/logout");
});



app.get("/useri", function(req, res) {
    if (req.session.utilizator && req.session.utilizator.rol == "admin") {
        client.query("select * from utilizatori", function(err, rezQuery) {
            console.log(err);
            res.render("pagini/useri", { useri: rezQuery.rows });
        });
    } else {
        res.render("pagini/eroare_generala", { text: "Nu sunteti logat." });
    }
});

app.post("/sterge_utiliz", function(req, res) {
    var formular = new formidable.IncomingForm();

    formular.parse(req, function(err, campuriText, campuriFile) {
        var queryDelete = `delete from utilizatori where id=${campuriText.id_utiliz}`;
        client.query(queryDelete, function(err, rezQuery) {
            console.log(err);
            res.redirect("/useri");
        });
    });

});




//actualizare profil

app.post("/profil", function(req, res) {
    console.log("profil");
    if (!req.session.utilizator) {
        res.render("pagini/eroare_generala", { text: "Nu sunteti logat." });
        return;
    }
    var formular = new formidable.IncomingForm();

    formular.parse(req, function(err, campuriText, campuriFile) {

        var criptareParola = crypto.scryptSync(campuriText.parola, parolaServer, 64).toString('hex');

        //TO DO query
        var queryUpdate = `update utilizatori set nume='${campuriText.nume}', prenume='${campuriText.prenume}', email='${campuriText.email}', culoare_chat='${campuriText.culoare_chat}' where parola='${criptareParola}'`;
        console.log(queryUpdate);
        client.query(queryUpdate, function(err, rez) {
            if (err) {
                console.log(err);
                res.render("pagini/eroare_generala", { text: "Eroare baza date. Incercati mai tarziu." });
                return;
            }
            console.log(rez.rowCount);
            if (rez.rowCount == 0) {
                res.render("pagini/profil", { mesaj: "Update-ul nu s-a realizat. Verificati parola introdusa." });
                return;
            } else {
                //actualizare sesiune
                req.session.utilizator.nume = campuriText.nume;
                req.session.utilizator.prenume = campuriText.prenume;
                req.session.utilizator.email = campuriText.email;
                req.session.utilizator.culoare_chat = campuriText.culoare_chat;
            }


            res.render("pagini/profil", { mesaj: "Update-ul s-a realizat cu succes." });

        });


    });
});





















app.get("/galerie", function(req, res) {
    //res.sendFile(__dirname+"/index1.html");
    res.render("pagini/galerie_statica", { ip: req.ip, imagini: obImagini.imagini });
    res.end();
});



app.get("/jucarii", function(req, res) {

    // client.query("select * from unnest(enum_range(null::subcategorie))", function(err, rezCateg) {
    client.query("select * from jucarii", function(err, rezQuery) {
        // console.log(err);
        console.log(rezQuery);

        res.render("pagini/jucarii", { jucarii: rezQuery.rows });
    });
    // });
});


app.get("/produse", function(req, res) {

    client.query("select * from unnest(enum_range(null::subcategorie))", function(err, rezCateg) {
        client.query("select * from microfoane", function(err, rezQuery) {
            // console.log(err);
            // console.log(rezQuery);

            res.render("pagini/produse", { microfoane: rezQuery.rows, optiuni: rezCateg.rows });
        });
    });
});

app.get("/produs/:id", function(req, res) {
    client.query(`select * from microfoane where id = ${req.params.id}`, function(err, rezQuery) {
        // console.log(err);
        // console.log(rezQuery);

        res.render("pagini/produs", { prod: rezQuery.rows[0] });
    });
});


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
            // console.log(rezRender);
            res.send(rezRender);
        }
    });


    res.end();
});





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

//app.listen(8080)
console.log("A pornit");