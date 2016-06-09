function fulfil() {
  console.log("fulfil called");

  var target = document.getElementById("here");
  target.style.border = "solid blue 2px";
  target.style.backgroundColor = "cyan";

  var childEl = document.createElement("div");
  childEl.className = "text-here";
  childEl.style.position = "absolute";

  childEl.innerHTML = "hmm?";
  target.appendChild(childEl);
}
