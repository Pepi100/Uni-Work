window.onload = function() {

    var formular = document.getElementById("form_inreg");
    if (formular) {
        // console.log("ceva1");
        formular.onsubmit = function() {

            console.log("ceva2");
            if (document.getElementById("parl").value != document.getElementById("rparl").value) {
                alert("Nu ati introdus acelasi sir pentru campurile \"parola\" si \"reintroducere parola\".");
                return false;
            }

            return true;
        }
    }
}