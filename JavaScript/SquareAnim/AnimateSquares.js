var CYCLES = 2;     // !Global variable for the number of cycles

//* Loading screen
const myPreloader = document.querySelector('.preloader');
const fadeOutEffect = setInterval(() => {
    if (!myPreloader.style.opacity) {
        myPreloader.style.opacity = 1;
    }
    if (myPreloader.style.opacity > 0) {
        myPreloader.style.opacity -= 0.6;
    } else {
        clearInterval(fadeOutEffect);
    }
}, 100);

fadeOutEffect;

//! Whenever the loading screen animation finishes display body content, and hide it when there is a loading screen

document.onreadystatechange = setInterval(() => {
    if (document.readyState !== "complete") {
        document.querySelector("body").style.visibility = "hidden";
        document.querySelector(".preloader").style.visibility = "visible";
    } else {
        document.querySelector("body").style.visibility = "visible";
        document.querySelector(".preloader").style.display = "none";
    }
}, 1000);

var yellowSquare = document.getElementById("yellowSquare");
var redSquare = document.getElementById("redSquare");
var blueSquare = document.getElementById("blueSquare");
var greenSquare = document.getElementById("greenSquare");


var id = null;
var cyclesCOPY = CYCLES;
function animateSquare() {
    //! vars for MoveAndConfirm
    var pos = 0;
    var _ANS = "green yellow";

    cyclesCOPY--;  //* decrease number of cycles every cycle

    id = setInterval(MoveAndConfirm, 15);

    function MoveAndConfirm() {
        var yellowSquare = document.getElementById("yellowSquare");
        var redSquare = document.getElementById("redSquare");
        var blueSquare = document.getElementById("blueSquare");
        var greenSquare = document.getElementById("greenSquare");

        yellowSquare.style.display = "block";
        redSquare.style.display = "block";
        blueSquare.style.display = "block";
        greenSquare.style.display = "block";


        if (pos == 245) {
            clearInterval(id); //! clear timer that has been set by setInterval() once you reach the dest
            if (cyclesCOPY == 0) {
                //! when the cycles reach 0, ask the user about the right answer and then reload the page again
                switch (_answer = prompt("Which squares contain the right characters?")) {
                    case _ANS:
                        alert("You're Right!!");
                        cyclesCOPY = CYCLES;
                        document.location.reload();
                        break;

                    default:
                        alert("Hmm.. you might wanna check again!");
                        cyclesCOPY = CYCLES;
                        document.location.reload();
                        break;
                }
            }
            animateSquare(); //* rerun the function "loop"

        } else {
            //! change squares position
            yellowSquare.style.top = pos + 10 + 'px';
            yellowSquare.style.left = pos + 10 + 'px';

            redSquare.style.bottom = pos + 10 + 'px';
            redSquare.style.right = pos + 10 + 'px';

            blueSquare.style.top = pos + 10 + 'px';
            blueSquare.style.right = pos + 10 + 'px';

            greenSquare.style.bottom = pos + 10 + 'px';
            greenSquare.style.left = pos + 10 + 'px';
            pos++;
        }
    }
}

