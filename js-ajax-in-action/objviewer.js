objviewer.ObjectViewer = function(obj, div, isInline, addNew) {
  styling.removeChildren(div);
  this.object = obj;
  this.mainDiv = div;
  this.mainDiv.viewer = this;
  this.isInline = isInline;
  this.addNew = addNew;
  var table = document.createElement("table");
  this.tbod = document.createElement("tbody");
  table.appendChild(this.tbod);
  this.fields = [];
  this.children = [];
  for (var i in this.object) {
    this.fields[i] = new objviewer.PropertyViewer(
      this, i
    );
  }
};
