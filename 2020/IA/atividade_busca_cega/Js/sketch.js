function removeFromArray(arr, target) {
  for (var i = arr.length - 1; i >= 0; i--) {
    if (arr[i] == target) {
      arr.splice(i, 1);
    }
  }
}

var cols = 5;
var rows = 5;
var grid = new Array(cols);

var openSet = [];
var closedSet = [];
var start;
var end;
var w, h; //width and height

function Spot(i, j) {
  this.i = i;
  this.j = j;
  this.f = 0;
  this.g = 0;
  this.h = 0;
  this.neighbors = [];

  this.show = function (col) {
    fill(col);
    noStroke();
    rect(this.i * w, this.j * h, w - 1, h - 1);
  }

  this.addNeighbors = function (grid) {
    var i = this.i;
    var j = this.j;

    if (i < cols < 1)
      this.neighbors.push(grid[i + 1][j]);

    if (i > 0)
      this.neighbors.push(grid[i - 1][j]);

    if (j < rows - 1)
      this.neighbors.push(grid[i][j + 1]);

    if (j > 0)
      this.neighbors.push(grid[i][j - 1]);
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

  for (var i = 0; i < cols; i++) {
    for (var j = 0; j < rows; j++) {
      grid[i][j].addNeighbors(grid);
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

    var winner = 0;
    for (var i = 0; i < openSet.length; i++) {
      if (openSet[i].f < openSet[winner].f) {
        winner = i;
      }
    }

    //
    var current = current;
    if (current === end) {
      console.log("DONE!!!");
    }

    removeFromArray(openSet, current);
    // openSet.remove(current);
    closedSet.push(current);

    var neighbors = current.neighbors;
    for (var i = 0; i < neighbors.length; i++) {
      var neighbor = neighbors[i];

      if (!closedSet.includes(neighbor))
        neighbor.g = current.g + 1;
    }

  } else {
    // no solution
  }

  // put drawing code here
  background(0);

  // 
  for (var i = 0; i < cols; i++) {
    for (var j = 0; j < rows; j++) {
      grid[i][j].show(color(255));
    }
  }

  for (var i = 0; i < closedSet.length; i++) {
    openSet[i].show(color(255, 0, 0));
  }


  for (var i = 0; i < openSet.length; i++) {
    openSet[i].show(color(0, 255, 0));
  }

}