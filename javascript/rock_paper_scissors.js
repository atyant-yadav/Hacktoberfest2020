let playerscore=0;
let computerscore=0;
let result;
function computerPlay() {
  data = {
    1: "rock",
    2: "paper",
    3: "scissors",
  }

  key = (Math.floor(Math.random()*3)+1);
  return data[key];
}
function playRound(playerSelection, computerSelection) {
  playerSelection = playerSelection.toLowerCase();
  computerSelection = computerSelection.toLowerCase();
  if (((playerSelection=="scissors") && (computerSelection=="paper")) ||
  ((playerSelection=="paper") && (computerSelection=="rock")) ||
  ((playerSelection=="rock") && (computerSelection=="scissors"))){
      playerscore++;
      result = `You chose ${playerSelection} and Computer chose ${computerSelection}. YOU win!`;
      return result;

  } else if (((playerSelection=="scissors")&&(computerSelection=="rock")) ||
  ((playerSelection=="rock") && (computerSelection=="paper")) ||
  ((playerSelection=="paper")&&(computerSelection=="scissors"))){
    computerscore++;
    result = `You chose ${playerSelection} and Computer chose ${computerSelection}. Computer wins!`;
    return result;
  } else if (playerSelection == computerSelection) {
    result = `You and the Computer chose ${computerSelection}. Match Draw!`;
    return result;
}
}

function gameReset() {
  computerscore = 0;
  document.getElementById('computers-scorecard').innerHTML = computerscore;
  playerscore = 0;
  document.getElementById('players-scorecard').innerHTML = playerscore;
}

function game(element_id) {
  const playerSelection = element_id;
  const computerSelection = computerPlay();
  finalResult = playRound(playerSelection, computerSelection);
  document.getElementById('result-description').innerHTML=finalResult;
  document.getElementById('players-scorecard').innerHTML = Number(playerscore);
  document.getElementById('computers-scorecard').innerHTML = Number(computerscore);
}
