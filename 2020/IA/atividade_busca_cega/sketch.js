var cols = 5;
var rows = 5;
var grid = new Array(cols);

function Spot() {
  this.f = 0;
  this.g = 0;
  this.h = 0;
}

function setup() {
  // put setup code here
  createCanvas(400, 400);
  console.log("A*");

  // filling grid (Making a 2D array)
  for (var i = 0; i < cols; i++) {
    grid[i] = new Array(rows);
  }

  //
  for (var i = 0; i < cols; i++) {
    for (var j = 0; j < rows; j++) {
      grid[i][j] = new Spot();
    }
  }

  console.log(grid);
}

function draw() {
  // put drawing code here
  background(0);
}