const spawn = require('child_process').spawn;

let params;
let frames;
let index = -2;

let width;
let height;
let cellSize = 15;

const C_P1_DONE = '#EE6352';
const C_P1_LAST = '#F5A9A0';
const C_P2_DONE = '#08B2E3';
const C_P2_LAST = '#8EDCF2';
const C_BG = '#F4F1F8';

function setup() {
  width = document.getElementById('sketch_canvas').offsetWidth;
  height = document.getElementById('sketch_canvas').offsetHeight;

  let cn = createCanvas(width, height);
  cn.parent('sketch_canvas');
  noStroke()
  background(255)
  frameRate(24)
}

function draw() {
  background(C_BG);

  let offset;

  if (index >= 0) {
    offset = [width/2 - (cellSize * params[0])/2, height/2 - (cellSize * params[1])/2]
    if (index < frames.length - 1)
      index++
    for (let i = 0; i < params[0]; i++) {
      for (let j = 0; j < params[1]; j++) {
        fill(getFill(frames[index][i][j]));
        stroke(0);
        rect(i * cellSize + offset[0], j * cellSize + offset[1], cellSize, cellSize);
      }
    }
  }
  if (index == -2) {
    offset = [width/2 - (cellSize * 10)/2, height/2 - (cellSize * 10)/2]
    for (let i = 0; i < 10; i++) {
      for (let j = 0; j < 10; j++) {
        fill(255);
        stroke(0);
        rect(i * cellSize + offset[0], j * cellSize + offset[1], cellSize, cellSize);
      }
    }
  }
}

function windowResized() {
  width = document.getElementById('sketch_canvas').offsetWidth;
  height = document.getElementById('sketch_canvas').offsetHeight;
  resizeCanvas(width, height);
}

function getParams(data) {
  for (let i = 0; i < data.length; i++) {
    if (data[i].indexOf("Plateau") == 0) {
      let params = data[i].split(" ");
      if (params.length == 3) {
        return ([int(params[1]), int(params[2])]);
        break;
      }
    }
  }
}

function getFrames(data) {
  frames = [];

  let j = 0;
  for (let i = 0; i < data.length; i++) {
    if (data[i].indexOf("Plateau") == 0) {
      i+=2;
      frames.push([]);
      for (; data[i].indexOf("Piece") != 0; i++) {
        frames[j].push(data[i].split(" ")[1]);
      }
      j++;
    }
  }
  return (frames);
}

function getFill(c) {
  if (c == 'X')
    return (C_P1_DONE);
  else if (c == 'x')
    return (C_P1_LAST);
  else if (c == 'O')
    return (C_P2_DONE);
  else if (c == 'o')
    return (C_P2_LAST);
  else
    return (255);
}

function fillerVM(map, player1, player2) {
    return (spawn("./filler_vm", [
      "-f", "maps/" + map,
      "-p1", "./players/" + player1,
      "-p2", "./players/" + player2
    ],
    {cwd:"resources"}
    ))
};

function getInfo(result)
{
  index = 0;
  params = getParams(result);
  frames = getFrames(result);
  loadStrings("../resources/filler.trace", function (data) {
    document.getElementById("info-1").innerHTML = data[data.length - 3];
    document.getElementById("info-2").innerHTML = data[data.length - 2];
    document.getElementById("info-3").innerHTML = data[data.length - 1];
    console.log(data);
  })
}

function fillerRun(map, player1, player2, callback) {
  let trace = "";
  let filler = fillerVM(map, player1, player2);

  filler.stdout.on('data', function (data) {
    trace += data.toString();
  })
  filler.on('close', function (code) {
    console.log("End with code:" + code);
    document.getElementById("go").disabled = false;
    document.getElementById("go").value = "GO";
    callback(trace.split("\n"));
  })
}

function gameOn() {
  let fillerMap = document.getElementById("filler_map").value;
  let fillerPlayer1 = document.getElementById("filler_player1").value;
  let fillerPlayer2 = document.getElementById("filler_player2").value;

  document.getElementById("go").disabled = true;
  document.getElementById("go").value = "wait";

  if (fillerMap == "map00")
    cellSize = 15;
  else if (fillerMap == "map01")
    cellSize = 10;
  else
    cellSize = 7;

  fillerRun(fillerMap, fillerPlayer1, fillerPlayer2, getInfo);
}
