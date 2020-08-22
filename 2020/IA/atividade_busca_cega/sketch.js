var cols = 5;
var rows = 5;
var grid = new Array(cols);

var openSet = [];
var closedSet = [];
var start;
var end;
var w, h; //width and height

function Spot(i, j) {
  this.x = i;
  this.y = j;
  this.f = 0;
  this.g = 0;
  this.h = 0;

  this.show = function () {
    fill(255);
    stroke(0);
    rect(this.x * w, this.y * h, w - 1, h - 1);
  }
}

function setup() {
  // put setup code here
  createCanvas(400, 400);
  console.log("A*");

  // Setting up width and height
  w = width / cols;
  h = height / rows;

  // filling grid (Making a 2D array)
  for (var i = 0; i < cols; i++) {
    grid[i] = new Array(rows);
  }

  //
  for (var i = 0; i < cols; i++) {
    for (var j = 0; j < rows; j++) {
      grid[i][j] = new Spot(i, j);
    }
  }

  // 
  start = grid[0][0];
  end = grid[cols - 1][rows - 1];

  openSet.push(start)


  console.log(grid);
}

function draw() {

  if (openSet.length > 0) {
    // we can keep going
  } else {
    // no solution
  }

  // put drawing code here
  background(0);

  // 
  for (var i = 0; i < cols; i++) {
    for (var j = 0; j < rows; j++) {
      grid[i][j].show();
    }
  }
}